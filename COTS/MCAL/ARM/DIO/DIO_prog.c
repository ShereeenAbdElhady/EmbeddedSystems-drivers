/**********************************************************************************/
/*                                                                               */
/* File Name   : DIO_prog.c                                                     */
/*                                                                             */
/* Created on  : Feb 27, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V02                                                      */
/*                                                                       */
/* Description : software driver for Digital inputs / outputs           */
/*                                                                     */
/*               with a defined public and private functions for the  */
/*               For STM32F103C8 ARM Microcontroller.                */
/*                                                                  */
/* Layer       : MCAL                                              */
/******************************************************************/

#include "../STD_TYPES.h"
#include "../BIT_CALC.h"
#include "../include/DIO_interface.h"
#include "../include/DIO_private.h"

/*********************** Public Functions ******************************/

/***********************************************************************
 * Description: Function to initialize pin Direction each pin is 4 bits
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************/
void DIO_vidInitialize(void)
{
	/* Set the 32 PINs directions according to configuration file settings                     */
	DIO_u8SetPinDirection(DIO_u8_PIN0,DIO_u8_PIN0_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN1,DIO_u8_PIN1_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN2,DIO_u8_PIN2_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN3,DIO_u8_PIN3_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN4,DIO_u8_PIN4_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN5,DIO_u8_PIN5_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN6,DIO_u8_PIN6_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN7,DIO_u8_PIN7_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN8,DIO_u8_PIN8_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN9,DIO_u8_PIN9_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN10,DIO_u8_PIN10_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN11,DIO_u8_PIN11_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN12,DIO_u8_PIN12_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN13,DIO_u8_PIN13_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN14,DIO_u8_PIN14_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN15,DIO_u8_PIN15_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN16,DIO_u8_PIN16_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN17,DIO_u8_PIN17_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN18,DIO_u8_PIN18_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN19,DIO_u8_PIN19_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN20,DIO_u8_PIN20_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN21,DIO_u8_PIN21_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN22,DIO_u8_PIN22_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN23,DIO_u8_PIN23_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN24,DIO_u8_PIN24_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN25,DIO_u8_PIN25_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN26,DIO_u8_PIN26_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN27,DIO_u8_PIN27_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN28,DIO_u8_PIN28_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN0,DIO_u8_PIN29_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN30,DIO_u8_PIN30_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN31,DIO_u8_PIN31_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN32,DIO_u8_PIN32_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN33,DIO_u8_PIN33_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN34,DIO_u8_PIN34_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN35,DIO_u8_PIN35_INIT_DIR);
	DIO_u8SetPinDirection(DIO_u8_PIN36,DIO_u8_PIN36_INIT_DIR);
}

/*********************************************************************
 * Description: Function to Set pin value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PinValue: value of this pin
 *             Copy_u8PinNB : pin number
 ********************************************************************/
u8   DIO_u8SetPinValue (u8 Copy_u8PinNb, u8  Copy_u8PinValue )
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Local Variable to map PIN ID             */
	u8 Local_u8PinId;
	/* Local Variable to map PORT ID          */
	u8 Local_u8PortId;
	/* user will pass the PIN number and here we will map it to the corresponding PIN in the Micro-Controller */
	Local_u8PinId =  Copy_u8PinNb % DIO_u8_NUMBER_PINS_IN_PORT;
	/* user will pass the PIN number and here we will map it to the corresponding PORT in the Micro-Controller */
	Local_u8PortId =  Copy_u8PinNb / DIO_u8_NUMBER_PINS_IN_PORT;
	/* Check the passed value                                                                                  */
	switch (Copy_u8PinValue)
	{
	/* In case the value was HIGH then call the SetPin function                                                */
	case DIO_u8_PIN_HIGH: Local_u8Error = u8SetPin(Local_u8PortId,Local_u8PinId);
	break;
	/* In case the value was LOW then call the RstPin function                                                 */
	case DIO_u8_PIN_LOW : Local_u8Error = u8RstPin(Local_u8PortId,Local_u8PinId);
	break;
	/* Neither HIGH nor LOW return an error and this is considered as input validation checking                */
	default         :     Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	break;
	}
	/* Function Return */
	return Local_u8Error;
}


/*********************************************************************
 * Description: Function to Set pin Direction each pin is 4 bits
 * Outputs   :                   Error State
 * Inputs    : Copy_u8PinNB:     Pin Number
 *             Copy_u8Mode : direction of the pin
 *********************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNb, u8 Copy_u8Direction)
{
	/* Local Variable indication for Error status                                                             */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Local Variable to map PIN ID                                                                           */
	u8 Local_u8PinId;
	/* Local Variable to map PORT ID                                                                          */
	u8 Local_u8PortId;
	/* user will pass the PIN number and here we will map it to the corresponding PIN in the Micro-Controller */
	Local_u8PinId =  Copy_u8PinNb % DIO_u8_NUMBER_PINS_IN_PORT;
	/* user will pass the PIN number and here we will map it to the corresponding PORT in the Micro-Controller*/
	Local_u8PortId =  Copy_u8PinNb / DIO_u8_NUMBER_PINS_IN_PORT;

	/*************** solving the wrong mode problem ****************************/
	/* If the passed mode was wrong then return an error and exit from the function                           */
	if(Copy_u8Direction > DIO_u8_MAX_MODES_VALUE)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}

	/******************* solving the pull down resistor problem *****************/
	/* if the Mode was internal Pull up resistance then set the ODR pin register with one                     */
	if (Copy_u8Direction == DIO_u8_PIN_INPUT_PULL_UP )
	{
		switch (Local_u8PortId)
		{
		/****** PORTA******/
		/*set the ODR pin register with one                                                                   */
		case DIO_u8_PORT0: BITCALC_SET_BIT(DIO_u32_GPIOA->ODR.FourByteAccess,  Local_u8PinId);
		break;
		/****** PORTB******/
		/*set the ODR pin register with one                                                                   */
		case DIO_u8_PORT1: BITCALC_SET_BIT(DIO_u32_GPIOB->ODR.FourByteAccess,  Local_u8PinId);
		break;
		/****** PORTC******/
		/*set the ODR pin register with one                                                                   */
		case DIO_u8_PORT2: BITCALC_SET_BIT(DIO_u32_GPIOC->ODR.FourByteAccess,  Local_u8PinId);
		break;
		/****** PORTD******/
		/*set the ODR pin register with one                                                                   */
		case DIO_u8_PORT3: BITCALC_SET_BIT(DIO_u32_GPIOD->ODR.FourByteAccess,  Local_u8PinId);
		break;
		}
	}
	/* if the Mode was internal Pull DOWN resistance then clear the ODR pin register with zero                */
	else if (Copy_u8Direction == DIO_u8_PIN_INPUT_PULL_DOWN)
	{
		switch (Local_u8PortId)
		{
		/****** PORTA******/
		/*clear the ODR pin register with zero                                                                */
		case DIO_u8_PORT0: BITCALC_CLEAR_BIT(DIO_u32_GPIOA->ODR.FourByteAccess,  Local_u8PinId);
		break;
		/****** PORTB******/
		/*clear the ODR pin register with zero                                                                */
		case DIO_u8_PORT1: BITCALC_CLEAR_BIT(DIO_u32_GPIOB->ODR.FourByteAccess,  Local_u8PinId);
		break;
		/****** PORTC******/
		/*clear the ODR pin register with zero                                                                */
		case DIO_u8_PORT2: BITCALC_CLEAR_BIT(DIO_u32_GPIOC->ODR.FourByteAccess,  Local_u8PinId);
		break;
		/****** PORTD******/
		/*clear the ODR pin register with zero                                                                */
		case DIO_u8_PORT3: BITCALC_CLEAR_BIT(DIO_u32_GPIOD->ODR.FourByteAccess,  Local_u8PinId);
		break;
		}
		/* return the mode to pull up as this macro contains the value for pull up & pull down            */
		Copy_u8Direction = DIO_u8_PIN_INPUT_PULL_UP;
	}

	/* if the PIN is in range from 0 to 7 and the mode was right                                          */
	if( (Copy_u8PinNb <= 7) && (Local_u8Error = STD_TYPES_u8_ERROR_OK) )
	{
		switch (Local_u8PortId)
		{
		/****** PORTA******/
		/* assign the required PIN(nibble) with the sent value to modify the direction                     */
		/* of Control register Low.                                                                        */
		case DIO_u8_PORT0: BITCALC_ASSIGN_NIBBLE(DIO_u32_GPIOA->CRL.FourByteAccess,Local_u8PinId, Copy_u8Direction);
		break;
		/****** PORTB******/
		/* assign the required PIN(nibble) with the sent value to modify the direction                     */
		/* of Control register Low.                                                                        */
		case DIO_u8_PORT1: BITCALC_ASSIGN_NIBBLE(DIO_u32_GPIOB->CRL.FourByteAccess,Local_u8PinId, Copy_u8Direction);
		break;
		/****** PORTC******/
		/* assign the required PIN(nibble) with the sent value to modify the direction                     */
		/* of Control register Low.                                                                        */
		case DIO_u8_PORT2: BITCALC_ASSIGN_NIBBLE(DIO_u32_GPIOC->CRL.FourByteAccess,Local_u8PinId, Copy_u8Direction);
		break;
		/****** PORTD******/
		/* assign the required PIN(nibble) with the sent value to modify the direction                     */
		/* of Control register Low.                                                                        */
		case DIO_u8_PORT3: BITCALC_ASSIGN_NIBBLE(DIO_u32_GPIOD->CRL.FourByteAccess,Local_u8PinId, Copy_u8Direction);
		break;
		/* In case of wrong port number return an error and this is considered as input validation checking*/
		default          : Local_u8Error = STD_TYPES_u8_ERROR_NOK;
		break;
		}
	}
	/* if the PIN is in range from 8 to 15 and the mode was right                                         */
	else if ( (Copy_u8PinNb > 7) && (Local_u8Error = STD_TYPES_u8_ERROR_OK) )
	{
		/* subtract 8 from the passed bit to set it's index to 0,1,2.. to fit the CRH register            */
		Local_u8PinId -=  8;
		switch (Local_u8PortId)
		{
		/****** PORTA******/
		/* assign the required PIN(nibble) with the sent value to modify the direction                     */
		/* of Control register High.                                                                       */
		case DIO_u8_PORT0: BITCALC_ASSIGN_NIBBLE(DIO_u32_GPIOA->CRH.FourByteAccess,Local_u8PinId, Copy_u8Direction);
		break;
		/****** PORTB******/
		/* assign the required PIN(nibble) with the sent value to modify the direction                     */
		/* of Control register High.                                                                       */
		case DIO_u8_PORT1: BITCALC_ASSIGN_NIBBLE(DIO_u32_GPIOB->CRH.FourByteAccess,Local_u8PinId, Copy_u8Direction);
		break;
		/****** PORTC******/
		/* assign the required PIN(nibble) with the sent value to modify the direction                     */
		/* of Control register High.                                                                       */
		case DIO_u8_PORT2: BITCALC_ASSIGN_NIBBLE(DIO_u32_GPIOC->CRH.FourByteAccess,Local_u8PinId, Copy_u8Direction);
		break;
		/****** PORTD******/
		/* assign the required PIN(nibble) with the sent value to modify the direction                     */
		/* of Control register High.                                                                       */
		case DIO_u8_PORT3: BITCALC_ASSIGN_NIBBLE(DIO_u32_GPIOD->CRH.FourByteAccess,Local_u8PinId, Copy_u8Direction);
		break;
		/* In case of wrong port number return an error and this is considered as input validation checking*/
		default          : Local_u8Error = STD_TYPES_u8_ERROR_NOK;
		break;

		}
	}
	/* Function Return */
	return Local_u8Error;
}

/********************************************************************
 * Description:  Function to get pin value
 * Outputs   :               Error State
 * Inputs    : u8* Copy_Pu8Value: pointer to address of the value
 *             Copy_u8PinNB  :  pin number
 ********************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8PinNb, u8* Copy_Pu8Value)
{
	/* Local Variable indication for Error status                                                             */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Local Variable to map PIN ID                                                                           */
	u8 Local_u8PinId;
	/* Local Variable to map PORT ID                                                                          */
	u8 Local_u8PortId;
	/* user will pass the PIN number and here we will map it to the corresponding PIN in the Micro-Controller */
	Local_u8PinId =  Copy_u8PinNb % DIO_u8_NUMBER_PINS_IN_PORT;
	/* user will pass the PIN number and here we will map it to the corresponding PORT in the Micro-Controller*/
	Local_u8PortId =  Copy_u8PinNb / DIO_u8_NUMBER_PINS_IN_PORT;

	switch (Local_u8PortId)
	{
	/****** PORTA******/
	/* *pu8Value to enter this address and store the PIN value in it */
	case DIO_u8_PORT0: *Copy_Pu8Value = BITCALC_GET_BIT(DIO_u32_GPIOA->IDR.FourByteAccess,Local_u8PinId);
	break;
	/****** PORTB******/
	/* *pu8Valueto enter this address and store the PIN value in it */
	case DIO_u8_PORT1: *Copy_Pu8Value = BITCALC_GET_BIT(DIO_u32_GPIOB->IDR.FourByteAccess,Local_u8PinId);
	break;
	/****** PORTC******/
	/* *pu8Value to enter this address and store the PIN value in it */
	case DIO_u8_PORT2: *Copy_Pu8Value = BITCALC_GET_BIT(DIO_u32_GPIOC->IDR.FourByteAccess,Local_u8PinId);
	break;
	/****** PORTD******/
	/* *pu8Value to enter this address and store the PIN value in it */
	case DIO_u8_PORT3: *Copy_Pu8Value = BITCALC_GET_BIT(DIO_u32_GPIOD->IDR.FourByteAccess,Local_u8PinId);
	break;
	/* In case of wrong port number return an error and this is considered as input validation checking*/
	default          :  Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return                                                                                    */
	return Local_u8Error;
}

/**************************************************
 * Description: Function to Set port value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PortValue: value of the port
 *             Copy_u8PortNB   : port number
 ************************************************/
u8 DIO_u8SetPortValue(u8 Copy_u8PortNb, u32 Copy_u8PortValue)
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	switch (Copy_u8PortNb)
	{
	/****** PORTA******/
	case DIO_u8_PORT0:
		/* assign the  required PORT with the sent value to modify it's value */
		BITCALC_ASSIGN_PORT(DIO_u32_GPIOA->ODR.FourByteAccess,Copy_u8PortValue);
		break;

		/****** PORTB******/
	case DIO_u8_PORT1:
		/* assign the  required PORT with the sent value to modify it's value */
		BITCALC_ASSIGN_PORT(DIO_u32_GPIOB->ODR.FourByteAccess,Copy_u8PortValue);
		break;

		/****** PORTC******/
	case DIO_u8_PORT2:
		/* assign the  required PORT with the sent value to modify it's value */
		BITCALC_ASSIGN_PORT(DIO_u32_GPIOC->ODR.FourByteAccess,Copy_u8PortValue);
		break;

		/****** PORTD******/
	case DIO_u8_PORT3:
		/* assign the  required PORT with the sent value to modify it's value */
		BITCALC_ASSIGN_PORT(DIO_u32_GPIOD->ODR.FourByteAccess,Copy_u8PortValue);
		break;
		/* In case of wrong port number return an error and this is considered as input validation checking*/
	default          :  Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return */
	return Local_u8Error;
}

/******************************************************************
 * Description: Function to get port value
 * Outputs    :              Error State
 * Inputs     : u8* Copy_Pu8Value: pointer to address of the value
 *              Copy_u8PortNB    : port number
 ****************************************************************/
u8 DIO_u8GetPortValue(u8 Copy_u8PortNb, u8* Copy_Pu8Value)
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	switch (Copy_u8PortNb)
	{
	/****** PORTA******/
	/* *pu8Value to enter this address and store the PIN value in it */
	case DIO_u8_PORT0: *Copy_Pu8Value = BITCALC_GET_PORT(DIO_u32_GPIOA->IDR.FourByteAccess);
	break;
	/****** PORTB******/
	/* *pu8Valueto enter this address and store the PIN value in it */
	case DIO_u8_PORT1: *Copy_Pu8Value = BITCALC_GET_PORT(DIO_u32_GPIOB->IDR.FourByteAccess);
	break;
	/****** PORTC******/
	/* *pu8Value to enter this address and store the PIN value in it */
	case DIO_u8_PORT2: *Copy_Pu8Value = BITCALC_GET_PORT(DIO_u32_GPIOC->IDR.FourByteAccess);
	break;
	/****** PORTD******/
	/* *pu8Value to enter this address and store the PIN value in it */
	case DIO_u8_PORT3: *Copy_Pu8Value = BITCALC_GET_PORT(DIO_u32_GPIOD->IDR.FourByteAccess);
	break;
	/* In case of wrong port number return an error and this is considered as input validation checking*/
	default          :  Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return                                                                                    */
	return Local_u8Error;

}

/*********************** Private Functions ******************************/
/*********************************************************************
 * Description: Private Function to Set pin value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PortNb: port number
 *             Copy_u8PinNB : pin number
 ********************************************************************/
static u8 u8SetPin(u8 Copy_u8PortNb, u8 Copy_u8PinNb)
{
	/* Local Variable indication for Error status                                                         */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	switch (Copy_u8PortNb)
	{
	/* We gonna access the BSRR Register instead of the ODR Register                                      */
	/* to lower the number of cycles ODR |= (Copy_u8PinValue<<Local_u8PinId)                              */
	/****** PORTA******/
	/* set this BIT by one in the bit set reset register (BSRR)                                           */
	/* And it will be recorded in the output data register by default (ODR)                               */
	case DIO_u8_PORT0:  DIO_u32_GPIOA->BSRR.FourByteAccess = (1<<Copy_u8PinNb); break;
	/****** PORTB******/
	/* set this BIT by one in the bit set reset register (BSRR)                                           */
	/* And it will be recorded in the output data register by default (ODR)                               */
	case DIO_u8_PORT1:  DIO_u32_GPIOB->BSRR.FourByteAccess = (1<<Copy_u8PinNb); break;
	/****** PORTC******/
	/* set this BIT by one in the bit set reset register (BSRR)                                           */
	/* And it will be recorded in the output data register by default (ODR)                               */
	case DIO_u8_PORT2:  DIO_u32_GPIOC->BSRR.FourByteAccess = (1<<Copy_u8PinNb); break;
	/****** PORTD******/
	/* set this BIT by one in the bit set reset register (BSRR)                                           */
	/* And it will be recorded in the output data register by default (ODR)                               */
	case DIO_u8_PORT3:  DIO_u32_GPIOD->BSRR.FourByteAccess = (1<<Copy_u8PinNb); break;
	/* In case of wrong port number return an error and this is considered as input validation checking   */
	default          :  Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return                                                                                    */
	return Local_u8Error;
}


/*********************************************************************
 * Description: Private Function to Reset pin value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PortNb: port number
 *             Copy_u8PinNB : pin number
 ********************************************************************/
static u8 u8RstPin(u8 Copy_u8PortNb, u8 Copy_u8PinNb)
{
	/* Local Variable indication for Error status                                                         */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	switch (Copy_u8PortNb)
	{
	/* We gonna access the BRR Register instead of the ODR Register                                       */
	/* to lower the number of cycles ODR |= (Copy_u8PinValue<<Local_u8PinId)                              */
	/****** PORTA******/
	/* set this BIT by one in the bit  reset register (BRR)                                           */
	/* And it will be recorded in the output data register by default (ODR)                               */
	case DIO_u8_PORT0:  DIO_u32_GPIOA->BRR.FourByteAccess = (1<<Copy_u8PinNb); break;
	/****** PORTB******/
	/* set this BIT by one in the bit set reset register (BSRR)                                           */
	/* And it will be recorded in the output data register by default (ODR)                               */
	case DIO_u8_PORT1:  DIO_u32_GPIOB->BRR.FourByteAccess = (1<<Copy_u8PinNb); break;
	/****** PORTC******/
	/* set this BIT by one in the bit set reset register (BSRR)                                           */
	/* And it will be recorded in the output data register by default (ODR)                               */
	case DIO_u8_PORT2:  DIO_u32_GPIOC->BRR.FourByteAccess = (1<<Copy_u8PinNb); break;
	/****** PORTD******/
	/* set this BIT by one in the bit set reset register (BSRR)                                           */
	/* And it will be recorded in the output data register by default (ODR)                               */
	case DIO_u8_PORT3:  DIO_u32_GPIOD->BRR.FourByteAccess = (1<<Copy_u8PinNb); break;
	/* In case of wrong port number return an error and this is considered as input validation checking   */
	default          :  Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return                                                                                    */
	return Local_u8Error;
}
