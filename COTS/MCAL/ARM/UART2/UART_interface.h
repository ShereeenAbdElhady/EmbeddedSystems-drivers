/***********************************************************************************/
/*                                                                                */
/* File Name   : UART_interface.h                                                */
/*                                                                              */
/* Created on  : May 13, 2019                                                  */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V01                                                       */
/*                                                                        */
/* Description : Interface file for UART driver includes APIs' prototypes*/
/*              And MACROS for call  for STM32F103C8 ARM microcontroller*/
/*                                                                     */
/* Layer       : MCAL                                                 */
/*********************************************************************/




                        /***************** APIs Prototypes *****************/

/*******************************************************************************
 * Description: function to initialize the UART2 peripheral by disabling the interrupts
 *              & clearing flags , adjust baud rate, configure frame format
 *              like start bits number, word size, parity check type
 *              finally enable TX & RX and UART peripheral.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
extern void UART_VidInit (void);

/**************************************************************************************
 * Description: synchronous function to transmit a string using polling
 *              which block the processor.
 * Outputs   : Error state
 * Inputs    : const u8*Copy_Pu8ArrayData : pointer to constant array of characters
 *************************************************************************************/
extern u8 UART_u8TransmitStringSynch (const u8*Copy_Pu8ArrayData);


/**************************************************************************************
 * Description: Asynchronous function to transmit a string using interrupts
 *              without blocking the processor.
 *              firstly will transmit the first character using this function
 *              then the ISR will transmit the rest of characters. after finishing the
 *              ISR will return to this function and call the callback function.
 * Outputs   : None
 * Inputs    : const u8*Copy_Pu8ArrayData : pointer to constant array of characters
 *             void (*Copy_PVidFunCallback) (void) : pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR
 *************************************************************************************/
extern void UART_VidTransmitStringAsynch (const u8*Copy_Pu8ArrayData , void (*Copy_PVidFunCallback) (void));


/**************************************************************************************
 * Description: synchronous function to receive a string using polling
 *              which block the processor.
 * Outputs   : Error state
 * Inputs    : const u8*Copy_Pu8ArrayData : pointer to constant array of characters
 *             u8 Copy_u8DataLength       : length of data
 *************************************************************************************/
extern u8 UART_u8RecieveStringSynch (u8*Copy_Pu8ArrayData , u8 Copy_u8DataLength );


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
void UART_VidRecieveStringAsynch(u8*Copy_Pu8ArrayData , u8 Copy_u8DataLength , void (*Copy_PVidFunCallback) (void));


/****************************************************************************************************
 * Description:Function to Set the pointer to callback function with the address of the function
 *              Needed to be implemented by the ISR.
 * Outputs   : Error State
 * Inputs    : void (*Copy_PVidFunCallback) (void): pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR.
 ***************************************************************************************************/
extern u8 UART_u8SetCallback (void (*Copy_PVidFunCallback) (void));


/**************************************************************************************
 * Description: UART2 ISR which responsible for the transmission & reception of the rest
 *              of characters and after finishing sending & receiving  them
 *              will call the callback function.
 *
 * Outputs   : None
 * Inputs    : None
 *************************************************************************************/
void USART2_IRQHandler(void);
