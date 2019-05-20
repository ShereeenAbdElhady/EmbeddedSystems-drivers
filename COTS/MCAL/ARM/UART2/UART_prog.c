/******************************************************************************************/
/*                                                                                       */
/* File Name   : UART_prog.c                                                            */
/*                                                                                     */
/* Created on  : May 13, 2019                                                         */
/*                                                                                   */
/* Author      : shereen Abd Elhady                                                 */
/*                                                                                 */
/* Version     : V01                                                              */
/*                                                                               */
/* Description : software driver for universal asynchronous receiver transmitter*/
/*               for  STM32F103C8 ARM Microcontroller with defined public      */
/*               & private APIs supports Asych & Synch functions              */
/*                                                                           */
/* Layer       : MCAL                                                       */
/***************************************************************************/

#include "../STD_TYPES.h"
#include "../BIT_CALC.h"
#include "../include/UART_interface.h"
#include "../include/UART_private.h"
#include "../include/UART_config.h"

/* pointer to function, pointer will carry the address of the function wanted to be implemented by the ISR                     */
/* Initialize the pointer with Null in the beginning to avoid this pointer from garbage value and implementation of wrong code */
/* Global & Static to be seen within this file only                                                                            */
static void (*PVidFunCallback) (void) = NULL ;

/*global variable for loop index used in asynchronous transmission*/
static u8 Global_u8LoopIndexAsynch = 0;

/****** Driver Constraint*****/
/*pointer to character to be used in asynchronous transmission      */
/*we will save the address of the passed string to this function    */
/*in this pointer to avoid the dangling pointer as the sent string  */
/*gonna be locally defined in transmitAsynch function and we want   */
/*to use it in the ISR. at this point we will found that we refer   */
/*to a dangling pointer so we defined this ptr to avoid this mistake*/
/*And this is considered to be a constraint in this driver          */
static const u8 *Ptr_TXDataAsynch;
static u8 *Ptr_RXDataAsynch;
static u8 Global_RxDataLength;


/*******************************************************************************
 * Description: function to initialize the UART2 peripheral by disabling the interrupts
 *              & clearing flags , adjust baud rate, configure frame format
 *              like start bits number, word size, parity check type
 *              finally enable TX & RX and UART peripheral.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
extern void UART_VidInit (void)
{
	/*clear transmission complete TXE flag                     */
	UART_u32_SR &= (~(1 << UART_SR_TXE_PIN ));
	/*Disable TXE interrupt                                    */
	UART_VidDisableTXEInterrupt ();

	/*clear read data register not empty flag RXNE            */
	UART_u32_SR &= (~(1 << UART_SR_RXNE_PIN));
	/*Disable (read data register not empty interrupt) RXNE   */
	UART_VidDisableRXNEInterrupt ();


	/*Baud rate settings                                       */
	//UART_u32_BRR = (UART_u32_CPU_FREQUENCY_HZ / UART_u32_BAUD_RATE);
	UART_u32_BRR = 0x0341;
	/*stop bits settings                                       */
#if UART_u8_STOP_BITS == UART_u8_1_STOP_BIT
	UART_u32_CR2 &=(~(1 << UART_CR2_STOP_PIN1));
	UART_u32_CR2 &=(~(1 << UART_CR2_STOP_PIN0));
#elif UART_u8_STOP_BITS == UART_u8_0_5_STOP_BIT
	UART_u32_CR2 &=(~(1 << UART_CR2_STOP_PIN1));
	UART_u32_CR2 |= (1 << UART_CR2_STOP_PIN0);
#elif UART_u8_STOP_BITS == UART_u8_2_STOP_BIT
	UART_u32_CR2 |= (1 << UART_CR2_STOP_PIN1);
	UART_u32_CR2 &=(~(1 << UART_CR2_STOP_PIN0));
#elif UART_u8_STOP_BITS == UART_u8_1_5_STOP_BIT
	UART_u32_CR2 |= (1 << UART_CR2_STOP_PIN1);
	UART_u32_CR2 |= (1 << UART_CR2_STOP_PIN0);
#endif

	/*word size settings                                       */
#if UART_u8_DATA_WORD_LENGTH == UART_u8_8BITS_DATA
	UART_u32_CR1 &= (~(1 << UART_CR1_M_PIN));
#elif UART_u8_DATA_WORD_LENGTH == UART_u8_9BITS_DATA
	UART_u32_CR1 |= (1 << UART_CR1_M_PIN);
#endif

	/*Parity select settings and adjusting parity type        */
#if UART_u8_PARITY_CONTROL == UART_u8_PARITY_ENABLE
	UART_u32_CR1 |= (1 << UART_CR1_PCE_PIN);
	if (UART_u8_PARITY_SELECTION == UART_u8_ODD_PARITY)
	{
		UART_u32_CR1 |= (1 << UART_CR1_PS_PIN);
	}
	else if (UART_u8_PARITY_SELECTION == UART_u8_EVEN_PARITY)
	{
		UART_u32_CR1 &= (~(1 << UART_CR1_PS_PIN));
	}
#elif UART_u8_PARITY_CONTROL == UART_u8_PARITY_DISABLE
	UART_u32_CR1 &= (~(1 << UART_CR1_PCE_PIN));
#endif

	/*transmitter, receiver and UART enable                   */
	UART_u32_CR1 |= (1 << UART_CR1_u8_TE_PIN) | (1 << UART_CR1_u8_RE_PIN);
	UART_u32_CR1 |= (1 << UART_CR1_UE_PIN);
	return ;
}


/**************************************************************************************
 * Description: synchronous function to transmit a string using polling
 *              which block the processor.
 * Outputs   : Error state
 * Inputs    : const u8*Copy_Pu8ArrayData : pointer to constant array of characters
 *************************************************************************************/
extern u8 UART_u8TransmitStringSynch (const u8*Copy_Pu8ArrayData)
{
	/*Local variable for loop index                                                */
	u8 Local_u8LoopIndexSynch = 0;
	/* Local Variable indication for Error status                                  */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	/*local counter to avoid being stuck in a loop during polling                  */
	u16 Local_u16PollingCounter = 0;

	/*Disable TXE interrupt                                                         */
	UART_VidDisableTXEInterrupt ();
	while (Copy_Pu8ArrayData[Local_u8LoopIndexSynch] != '\0')
	{
		UART_u32_DR = Copy_Pu8ArrayData[Local_u8LoopIndexSynch] ;
		/*wait until the TXE flag is set to one                  */
		/*with respect to time constraints which prevents us from being stuck      */
		while (((((UART_u32_SR) >> (UART_SR_TXE_PIN))&(0x01)) == 0) && (Local_u16PollingCounter < UART_u8_TIMEOUT_POLLING))
		{
			Local_u16PollingCounter ++;
		}
		/*if the time passed without setting the flag return error                */
		if (((((UART_u32_SR) >> (UART_SR_TXE_PIN))&(0x01)) == 0) && (Local_u16PollingCounter >= UART_u8_TIMEOUT_POLLING))
		{
			Local_u8Error = STD_TYPES_u8_ERROR_NOK;
		}
		/*after TXE flag = 1 which indicate the transmission of the first character*/
		/*increment this index to transmit the next character                     */
		Local_u8LoopIndexSynch ++;
		/* It's already cleared after accessing the DR reg clear transmission complete TXE flag */
		//UART_u32_SR &= (~(1 << UART_SR_TXE_PIN));
	}
	/* Function Return                                                            */
	return Local_u8Error;
}


/**************************************************************************************
 * Description: Asynchronous function to transmit a string using interrupts
 *              without blocking the processor.
 *              firstly will transmit the first character using this function
 *              then the ISR will transmit the rest of characters. after finishing the
 *              characters the ISR  will  call the callback function.
 * Outputs   : None
 * Inputs    : const u8*Copy_Pu8ArrayData : pointer to constant array of characters
 *             void (*Copy_PVidFunCallback) (void) : pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR
 *************************************************************************************/
extern void UART_VidTransmitStringAsynch (const u8*Copy_Pu8ArrayData , void (*Copy_PVidFunCallback) (void))
{
	Global_u8LoopIndexAsynch = 0;
	/*save the address in a static pointer to avoid dangling pointer (constraint)      */
	Ptr_TXDataAsynch = Copy_Pu8ArrayData;
	/*callback function calling and send to it the address of the function to implement*/
	UART_u8SetCallback (Copy_PVidFunCallback);
	/*clear transmission complete TXEflag                                              */
	UART_u32_SR &= (~(1 << UART_SR_TXE_PIN ));
	/*enable TXE interrupt                                                              */
	UART_VidEnableTXEInterrupt ();
	if(Ptr_TXDataAsynch[Global_u8LoopIndexAsynch] != '\0')
	{
		UART_u32_DR = Ptr_TXDataAsynch[Global_u8LoopIndexAsynch];
	}
	return ;
}


/**************************************************************************************
 * Description: synchronous function to receive a string using polling
 *              which block the processor.
 * Outputs   : Error state
 * Inputs    : const u8*Copy_Pu8ArrayData : pointer to constant array of characters
 *             u8 Copy_u8DataLength       : length of data
 *************************************************************************************/
extern u8 UART_u8RecieveStringSynch (u8*Copy_Pu8ArrayData , u8 Copy_u8DataLength)
{
	/*Local variable for loop index                                                */
	u8 Local_u8LoopIndexSynch = 0;
	/* Local Variable indication for Error status                                  */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	/*local counter to avoid being stuck in a loop during polling                  */
	u16 Local_u16PollingCounter = 0;

	/*Disable (read data register not empty interrupt) RXNE   */
	UART_VidDisableRXNEInterrupt ();
	while (Local_u8LoopIndexSynch < Copy_u8DataLength)
	{
		/*wait until the read data register not empty flag is set to one           */
		/*with respect to time constraints which prevents us from being stuck      */
		while (((((UART_u32_SR) >> (UART_SR_RXNE_PIN))&(0x01)) == 0) && (Local_u16PollingCounter < UART_u8_TIMEOUT_POLLING))
		{
			Local_u16PollingCounter ++;
		}
		/*if the time passed without setting the flag return error                */
		if (((((UART_u32_SR) >> (UART_SR_RXNE_PIN))&(0x01)) == 0) && (Local_u16PollingCounter >= UART_u8_TIMEOUT_POLLING))
		{
			Local_u8Error = STD_TYPES_u8_ERROR_NOK;
		}
		else
		{
			/*read data from the buffer                                              */
			Copy_Pu8ArrayData[Local_u8LoopIndexSynch] = UART_u32_DR;
			/*after RXNE flag = 1 which indicate the reception of the first character*/
			/*increment this index to receive the next character                     */
			Local_u8LoopIndexSynch ++;
			/*clear read data register not empty flag RXNE            */
			UART_u32_SR &= (~(1 << UART_SR_RXNE_PIN));
		}
	}
	/* Function Return                                                            */
	return Local_u8Error;
}


/**************************************************************************************
 * Description: Asynchronous function to receive a string using interrupts
 *              without blocking the processor.
 *              firstly will receive the first character using this function
 *              then the ISR will receive the rest of characters. after finishing the
 *              characters the ISR  will  call the callback function.
 * Outputs   : None
 * Inputs    : u8*Copy_Pu8ArrayData : pointer to array of characters to store the string in it
 *             void (*Copy_PVidFunCallback) (void) : pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR
 *             u8 Copy_u8DataLength: length of data
 *************************************************************************************/
void UART_VidRecieveStringAsynch(u8*Copy_Pu8ArrayData , u8 Copy_u8DataLength , void (*Copy_PVidFunCallback) (void))
{
	Global_u8LoopIndexAsynch = 0;
	/*save the address in a static pointer to avoid dangling pointer (constraint)      */
	Ptr_RXDataAsynch = Copy_Pu8ArrayData ;
	/*save the data length to be used by the ISR                                       */
	Global_RxDataLength = Copy_u8DataLength;
	/*callback function calling and send to it the address of the function to implement*/
	UART_u8SetCallback (Copy_PVidFunCallback);

	/*clear read data register not empty flag RXNE                                     */
	UART_u32_SR &= (~(1 << UART_SR_RXNE_PIN));
	/*enable (read data register not empty interrupt) RXNE                             */
	UART_VidEnableRXNEInterrupt ();

//	if(Global_u8LoopIndexAsynch < Global_RxDataLength)
	//{
		//Ptr_RXDataAsynch[Global_u8LoopIndexAsynch] = UART_u32_DR;
	//}
	//return ;
}


/**************************************************************************************
 * Description: UART2 ISR which responsible for the transmission & reception of the rest
 *              of characters and after finishing sending & receiving  them
 *              will call the callback function.
 *
 * Outputs   : None
 * Inputs    : None
 *************************************************************************************/
void USART2_IRQHandler(void)
{
	/*we will check on the TX & RX flags using if not if else if to be sure that we TX & RX in the same time in the ISR*/
	if ((BITCALC_GET_BIT(UART_u32_SR,UART_SR_TXE_PIN)) == 1)
	{
		/*increment this index to transmit the next character                            */
		Global_u8LoopIndexAsynch ++;
		/*clear transmission complete TXE flag                                            */
		UART_u32_SR &= (~(1 << UART_SR_TXE_PIN));
		if(Ptr_TXDataAsynch[Global_u8LoopIndexAsynch] != '\0')
		{
			UART_u32_DR = Ptr_TXDataAsynch[Global_u8LoopIndexAsynch];
		}
		else
		{
			Global_u8LoopIndexAsynch = 0;
			UART_VidDisableTXEInterrupt ();
			/* ISR of transmission complete Function calling                              */
			PVidFunCallback();
		}
	}

	/*check on the RX flag                                                                */
	if ((BITCALC_GET_BIT(UART_u32_SR,UART_SR_RXNE_PIN)) == 1)
	{
		/*clear read data register not empty flag RXNE                                     */
		UART_u32_SR &= (~(1 << UART_SR_RXNE_PIN));
		if (Global_u8LoopIndexAsynch < Global_RxDataLength)
		{
			Ptr_RXDataAsynch[Global_u8LoopIndexAsynch] = UART_u32_DR;
			/*increment this index to receive the next character                              */
			Global_u8LoopIndexAsynch ++;
		}
		else
		{
			Global_u8LoopIndexAsynch = 0;
			/*clear read data register not empty flag RXNE                                     */
			UART_u32_SR &= (~(1 << UART_SR_RXNE_PIN));
			UART_VidDisableRXNEInterrupt ();
			/* ISR of transmission complete Function calling                              */
			PVidFunCallback();
		}
	}
	return ;
}


/****************************************************************************************************
 * Description:Function to Set the pointer to callback function with the address of the function
 *              Needed to be implemented by the ISR.
 * Outputs   : Error State
 * Inputs    : void (*Copy_PVidFunCallback) (void): pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR.
 ***************************************************************************************************/
extern u8 UART_u8SetCallback (void (*Copy_PVidFunCallback) (void))
{
	/* Local Variable indication for Error status                                            */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                                                            */
	if (Copy_PVidFunCallback == NULL)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* Set the pointer with address of the function needed to be implemented by the ISR  */
		PVidFunCallback = Copy_PVidFunCallback;
	}
	/* Function Return                                                                       */
	return Local_u8Error;
}


/*******************************************************************************
 * Description: private function to disable the transmission complete interrupt.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
static void UART_VidDisableTXEInterrupt (void)
{
	/*Disable TC interrupt                                    */
	UART_u32_CR1 &= (~(1 << UART_CR1_u8_TXEIE_PIN));
	return ;
}

/*******************************************************************************
 * Description: private function to enable the transmission complete interrupt.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
static void UART_VidEnableTXEInterrupt (void)
{
	/*enable TC interrupt                                    */
	UART_u32_CR1 |= (1 << UART_CR1_u8_TXEIE_PIN);
	return ;
}


/*******************************************************************************
 * Description: private function to disable the read data register
 *              not empty interrupt.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
static void UART_VidDisableRXNEInterrupt (void)
{
	/*Disable (read data register not empty interrupt) RXNE   */
	UART_u32_CR1 &= (~(1 << UART_CR1_u8_RXNEIE_PIN));
	return ;
}


/*******************************************************************************
 * Description: private function to enable the read data register
 *              not empty interrupt.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
static void UART_VidEnableRXNEInterrupt (void)
{
	/*enable (read data register not empty interrupt) RXNE   */
	UART_u32_CR1 |= (1 << UART_CR1_u8_RXNEIE_PIN);
	return ;
}
