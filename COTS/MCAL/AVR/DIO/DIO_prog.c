/**********************************************************************************/
/*                                                                               */
/* File Name   : DIO_prog.c                                                     */
/*                                                                             */
/* Created on  : Jan 29, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V01                                                      */
/*                                                                       */
/* Description : software driver for Digital inputs / outputs           */
/*                                                                     */
/*               with a defined public and private functions.         */
/*                                                                   */
/* Layer       : MCAL                                               */
/*******************************************************************/


#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "DIO_private.h"


/*****************************************************************************
 * Description: Function to initialize PINs directions and values
 *              initialize PINs directory as output PINs & PINs values as HIGH
 *              just one operator (assignment) instead of 15 operators
 * Outputs    : void
 * Inputs     : void
 ***************************************************************************/
void DIO_vidinit(void)
{
	/* Initialize PORTB PINs directions     */
	DIO_u8_DDRB = BITCALC_CONC_8BIT(DIO_u8_PIN0_INIT_DIR,
			DIO_u8_PIN1_INIT_DIR,
			DIO_u8_PIN2_INIT_DIR,
			DIO_u8_PIN3_INIT_DIR,
			DIO_u8_PIN4_INIT_DIR,
			DIO_u8_PIN5_INIT_DIR,
			DIO_u8_PIN6_INIT_DIR,
			DIO_u8_PIN7_INIT_DIR);
	/* Initialize PORTD PINs directions     */
	DIO_u8_DDRD = BITCALC_CONC_8BIT(DIO_u8_PIN8_INIT_DIR,
			DIO_u8_PIN9_INIT_DIR,
			DIO_u8_PIN10_INIT_DIR,
			DIO_u8_PIN11_INIT_DIR,
			DIO_u8_PIN12_INIT_DIR,
			DIO_u8_PIN13_INIT_DIR,
			DIO_u8_PIN14_INIT_DIR,
			DIO_u8_PIN15_INIT_DIR);
	/* Initialize PORTA PINs directions     */
	DIO_u8_DDRA = BITCALC_CONC_8BIT(DIO_u8_PIN16_INIT_DIR,
			DIO_u8_PIN17_INIT_DIR,
			DIO_u8_PIN18_INIT_DIR,
			DIO_u8_PIN19_INIT_DIR,
			DIO_u8_PIN20_INIT_DIR,
			DIO_u8_PIN21_INIT_DIR,
			DIO_u8_PIN22_INIT_DIR,
			DIO_u8_PIN23_INIT_DIR);
	/* Initialize PORTC PINs directions     */
	DIO_u8_DDRC = BITCALC_CONC_8BIT(DIO_u8_PIN24_INIT_DIR,
			DIO_u8_PIN25_INIT_DIR,
			DIO_u8_PIN26_INIT_DIR,
			DIO_u8_PIN27_INIT_DIR,
			DIO_u8_PIN28_INIT_DIR,
			DIO_u8_PIN29_INIT_DIR,
			DIO_u8_PIN30_INIT_DIR,
			DIO_u8_PIN31_INIT_DIR);
	/* Initialize PORTB PINs values    */
	DIO_u8_PORTB = BITCALC_CONC_8BIT(DIO_u8_PIN0_INIT_VALUE,
			DIO_u8_PIN1_INIT_VALUE,
			DIO_u8_PIN2_INIT_VALUE,
			DIO_u8_PIN3_INIT_VALUE,
			DIO_u8_PIN4_INIT_VALUE,
			DIO_u8_PIN5_INIT_VALUE,
			DIO_u8_PIN6_INIT_VALUE,
			DIO_u8_PIN7_INIT_VALUE);
	/* Initialize PORTD PINs values    */
	DIO_u8_PORTD = BITCALC_CONC_8BIT(DIO_u8_PIN8_INIT_VALUE,
			DIO_u8_PIN9_INIT_VALUE,
			DIO_u8_PIN10_INIT_VALUE,
			DIO_u8_PIN11_INIT_VALUE,
			DIO_u8_PIN12_INIT_VALUE,
			DIO_u8_PIN13_INIT_VALUE,
			DIO_u8_PIN14_INIT_VALUE,
			DIO_u8_PIN15_INIT_VALUE);
	/* Initialize PORTA PINs values    */
	DIO_u8_PORTA = BITCALC_CONC_8BIT(DIO_u8_PIN16_INIT_VALUE,
			DIO_u8_PIN17_INIT_VALUE,
			DIO_u8_PIN18_INIT_VALUE,
			DIO_u8_PIN19_INIT_VALUE,
			DIO_u8_PIN20_INIT_VALUE,
			DIO_u8_PIN21_INIT_VALUE,
			DIO_u8_PIN22_INIT_VALUE,
			DIO_u8_PIN23_INIT_VALUE);
	/* Initialize PORTC PINs values    */
	DIO_u8_PORTC = BITCALC_CONC_8BIT(DIO_u8_PIN24_INIT_VALUE,
			DIO_u8_PIN25_INIT_VALUE,
			DIO_u8_PIN26_INIT_VALUE,
			DIO_u8_PIN27_INIT_VALUE,
			DIO_u8_PIN28_INIT_VALUE,
			DIO_u8_PIN29_INIT_VALUE,
			DIO_u8_PIN30_INIT_VALUE,
			DIO_u8_PIN31_INIT_VALUE);


	/* Warning Message if the user set PIN direction as INPUT
	 * And trying to set the value with High
	 * He will receive a warning message
	 * And setting this PIN to Default value which equals to low  */

/*
#if (DIO_u8_PIN1_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN1_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 1 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN1_INIT_VALUE
#define DIO_u8_PIN1_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN2_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN2_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 2 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN2_INIT_VALUE
#define DIO_u8_PIN2_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN3_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN3_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 3 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN3_INIT_VALUE
#define DIO_u8_PIN3_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN4_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN4_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 4 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN4_INIT_VALUE
#define DIO_u8_PIN4_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN5_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN5_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 5 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN5_INIT_VALUE
#define DIO_u8_PIN5_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN6_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN6_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 6 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN6_INIT_VALUE
#define DIO_u8_PIN6_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN7_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN7_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 7 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN7_INIT_VALUE
#define DIO_u8_PIN7_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN8_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN8_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 8 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN8_INIT_VALUE
#define DIO_u8_PIN8_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN9_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN9_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 9 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN9_INIT_VALUE
#define DIO_u8_PIN9_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN10_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN10_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 10 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN10_INIT_VALUE
#define DIO_u8_PIN10_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN11_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN11_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 11 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN11_INIT_VALUE
#define DIO_u8_PIN11_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN12_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN12_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 12 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN12_INIT_VALUE
#define DIO_u8_PIN12_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN13_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN13_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 13 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN6_INIT_VALUE
#define DIO_u8_PIN6_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN14_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN14_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 14 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN14_INIT_VALUE
#define DIO_u8_PIN14_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN15_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN15_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 15 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN15_INIT_VALUE
#define DIO_u8_PIN15_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN16_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN16_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 16 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN16_INIT_VALUE
#define DIO_u8_PIN16_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN17_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN17_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 17 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN17_INIT_VALUE
#define DIO_u8_PIN17_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN18_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN18_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 18 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN18_INIT_VALUE
#define DIO_u8_PIN18_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN19_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN19_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 19 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN19_INIT_VALUE
#define DIO_u8_PIN19_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN20_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN20_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 20 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN20_INIT_VALUE
#define DIO_u8_PIN20_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN21_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN21_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 21 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN21_INIT_VALUE
#define DIO_u8_PIN21_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN22_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN22_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 22 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN22_INIT_VALUE
#define DIO_u8_PIN22_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN23_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN23_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 23 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN23_INIT_VALUE
#define DIO_u8_PIN23_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN24_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN24_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 24 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN24_INIT_VALUE
#define DIO_u8_PIN24_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN25_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN25_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 25 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN25_INIT_VALUE
#define DIO_u8_PIN25_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN26_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN26_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 26 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN26_INIT_VALUE
#define DIO_u8_PIN26_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN27_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN27_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 27 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN27_INIT_VALUE
#define DIO_u8_PIN27_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN28_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN28_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 28 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN28_INIT_VALUE
#define DIO_u8_PIN28_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN29_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN29_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 29 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN29_INIT_VALUE
#define DIO_u8_PIN29_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN30_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN30_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 30 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN30_INIT_VALUE
#define DIO_u8_PIN30_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif

#if (DIO_u8_PIN31_INIT_DIR == DIO_u8_PIN_INIT_INPUT) && (DIO_u8_PIN31_INIT_VALUE == DIO_u8_PIN_INIT_HIGH)
#warning "PIN 31 is configured as input and it's value is high, corrected to default"
#undef DIO_u8_PIN31_INIT_VALUE
#define DIO_u8_PIN31_INIT_VALUE  DIO_u8_PIN_INIT_DEF
#endif
*/
}


/*********************************************************************
 * Description: Function to Set pin internal resistance
 * Outputs   :              Error State
 * Inputs    : Copy_u8InternalResistance: internal resistance state
 *             Copy_u8PinNB             : pin number
 *********************************************************************/
u8 DIO_u8SetPinInternalResistance(u8 Copy_u8PinNb, u8 Copy_u8InternalResistance)
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error;
	/* Local Variable to map PIN ID             */
	u8 Local_u8PinId;
	/* Local Variable to map PORT ID          */
	u8 Local_u8PortId;
	/* if any condition of these ones is true then it will return me an error  */
	if( (Copy_u8PinNb >= DIO_u8_MAX_PINNB) && ((Copy_u8InternalResistance != DIO_u8_INTERNAL_PULL_UP )|| (Copy_u8InternalResistance != DIO_u8_INTERNAL_FLOATING)) )
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* user will pass the PIN number and here we will map it to the corresponding PIN in the Micro-Controller */
		Local_u8PinId  =  Copy_u8PinNb % DIO_u8_NUMBER_PINS_IN_PORT;
		/* user will pass the PIN number and here we will map it to the corresponding PORT in the Micro-Controller */
		Local_u8PortId =  Copy_u8PinNb / DIO_u8_NUMBER_PINS_IN_PORT;
		switch (Local_u8PortId)
		{
		case 0:
			/* if the internal resistance is configured as internal pull up resistance */
			if( Copy_u8InternalResistance == DIO_u8_INTERNAL_PULL_UP)
			{
				/* assign the  required bit with ONE to modify it's value */
				BITCALC_ASSIGN_BIT(DIO_u8_PORTB,Local_u8PinId,DIO_u8_PIN_HIGH);
			}
			else if ( Copy_u8InternalResistance == DIO_u8_INTERNAL_FLOATING)
			{
				/* assign the  required bit with ZERO to modify it's value */
				BITCALC_ASSIGN_BIT(DIO_u8_PORTB,Local_u8PinId,DIO_u8_PIN_LOW);
			}
			break;

		case 1:
			/* if the internal resistance is configured as internal pull up resistance */
			if( Copy_u8InternalResistance == DIO_u8_INTERNAL_PULL_UP)
			{
				/* assign the  required bit with ONE to modify it's value */
				BITCALC_ASSIGN_BIT(DIO_u8_PORTD,Local_u8PinId,DIO_u8_PIN_HIGH);
			}
			else if ( Copy_u8InternalResistance == DIO_u8_INTERNAL_FLOATING)
			{
				/* assign the  required bit with ZERO to modify it's value */
				BITCALC_ASSIGN_BIT(DIO_u8_PORTD,Local_u8PinId,DIO_u8_PIN_LOW);
			}
			break;

		case 2:
			/* if the internal resistance is configured as internal pull up resistance */
			if( Copy_u8InternalResistance == DIO_u8_INTERNAL_PULL_UP)
			{
				/* assign the  required bit with ONE to modify it's value */
				BITCALC_ASSIGN_BIT(DIO_u8_PORTA,Local_u8PinId,DIO_u8_PIN_HIGH);
			}
			else if ( Copy_u8InternalResistance == DIO_u8_INTERNAL_FLOATING)
			{
				/* assign the  required bit with ZERO to modify it's value */
				BITCALC_ASSIGN_BIT(DIO_u8_PORTA,Local_u8PinId,DIO_u8_PIN_LOW);
			}
			break;

		case 3:
			/* if the internal resistance is configured as internal pull up resistance */
			if( Copy_u8InternalResistance == DIO_u8_INTERNAL_PULL_UP)
			{
				/* assign the  required bit with ONE to modify it's value */
				BITCALC_ASSIGN_BIT(DIO_u8_PORTC,Local_u8PinId,DIO_u8_PIN_HIGH);
			}
			else if ( Copy_u8InternalResistance == DIO_u8_INTERNAL_FLOATING)
			{
				/* assign the  required bit with ZERO to modify it's value */
				BITCALC_ASSIGN_BIT(DIO_u8_PORTC,Local_u8PinId,DIO_u8_PIN_LOW);
			}
			break;
		}
	}
	/* Function Return */
	return Local_u8Error;
}


/****************************************************
 * Description: Function to Set pin Direction
 * Outputs   :                   Error State
 * Inputs    : Copy_u8PinNB:     Pin Number
 *             Copy_u8Direction: direction of the pin
 *****************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNb, u8 Copy_u8Direction)
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error;
	/* Local Variable to map PIN ID             */
	u8 Local_u8PinId;
	/* Local Variable to map PORT ID          */
	u8 Local_u8PortId;
	/* if any condition of these ones is true then it will return me an error  */
	if( (Copy_u8PinNb >= DIO_u8_MAX_PINNB) || ((Copy_u8Direction !=DIO_u8_PIN_OUTPUT) && (Copy_u8Direction !=DIO_u8_PIN_INPUT)) )
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* user will pass the PIN number and here we will map it to the corresponding PIN in the Micro-Controller */
		Local_u8PinId  =  Copy_u8PinNb % DIO_u8_NUMBER_PINS_IN_PORT;
		/* user will pass the PIN number and here we will map it to the corresponding PORT in the Micro-Controller */
		Local_u8PortId =  Copy_u8PinNb / DIO_u8_NUMBER_PINS_IN_PORT;

		switch (Local_u8PortId)
		{
		case 0:
			/* assign the  required bit with the sent value to modify the direction */
			BITCALC_ASSIGN_BIT(DIO_u8_DDRB,Local_u8PinId,Copy_u8Direction);
			break;

		case 1:
			/* assign the  required bit with the sent value to modify the direction */
			BITCALC_ASSIGN_BIT(DIO_u8_DDRD,Local_u8PinId,Copy_u8Direction);
			break;

		case 2:
			/* assign the  required bit with the sent value to modify the direction */
			BITCALC_ASSIGN_BIT(DIO_u8_DDRA,Local_u8PinId,Copy_u8Direction);
			break;

		case 3:
			/* assign the  required bit with the sent value to modify the direction */
			BITCALC_ASSIGN_BIT(DIO_u8_DDRC,Local_u8PinId,Copy_u8Direction);
			break;
		}
	}
	/* Function Return */
	return Local_u8Error;
}


/**************************************************
 * Description: Function to Set pin value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PinValue: value of this pin
 *             Copy_u8PinNB : pin number
 ************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8PinNb, u8 Copy_u8PinValue)
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error;
	/* Local Variable to map PIN ID             */
	u8 Local_u8PinId;
	/* Local Variable to map PORT ID          */
	u8 Local_u8PortId;
	/* if any condition of these ones is true then it will return me an error  */
	if( (Copy_u8PinNb >= DIO_u8_MAX_PINNB) )
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* user will pass the PIN number and here we will map it to the corresponding PIN in the Micro-Controller */
		Local_u8PinId  =  Copy_u8PinNb % DIO_u8_NUMBER_PINS_IN_PORT;
		/* user will pass the PIN number and here we will map it to the corresponding PORT in the Micro-Controller */
		Local_u8PortId =  Copy_u8PinNb / DIO_u8_NUMBER_PINS_IN_PORT;
		switch (Local_u8PortId)
		{
		case 0:
			/* assign the  required bit with the sent value to modify it's value */
			BITCALC_ASSIGN_BIT(DIO_u8_PORTB,Local_u8PinId,Copy_u8PinValue);
			break;

		case 1:
			/* assign the  required bit with the sent value to modify it's value */
			BITCALC_ASSIGN_BIT(DIO_u8_PORTD,Local_u8PinId,Copy_u8PinValue);
			break;

		case 2:
			/* assign the  required bit with the sent value to modify it's value */
			BITCALC_ASSIGN_BIT(DIO_u8_PORTA,Local_u8PinId,Copy_u8PinValue);
			break;

		case 3:
			/* assign the  required bit with the sent value to modify it's value */
			BITCALC_ASSIGN_BIT(DIO_u8_PORTC,Local_u8PinId,Copy_u8PinValue);
			break;
		}
	}
	/* Function Return */
	return Local_u8Error;
}



/************************************************************
 * Description:  Function to get pin value
 * Outputs   :               Error State
 * Inputs    : u8* Copy_Pu8Value: pointer to address of the value
 *             Copy_u8PinNB  :  pin number
 **********************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8PinNB, u8* Copy_Pu8Value)
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error;
	/* Local Variable to map PIN ID             */
	u8 Local_u8PinId;
	/* Local Variable to map PORT ID          */
	u8 Local_u8PortId;
	/* if any condition of these conditions is not true we will return an error  */
	if( (Copy_u8PinNB < DIO_u8_MAX_PINNB) && (Copy_Pu8Value != NULL) )
	{
		/* user will pass the PIN number and here we will map it to the corresponding PIN in the Micro-Controller */
		Local_u8PinId  =  Copy_u8PinNB % DIO_u8_NUMBER_PINS_IN_PORT;
		/* user will pass the PIN number and here we will map it to the corresponding PORT in the Micro-Controller */
		Local_u8PortId =  Copy_u8PinNB / DIO_u8_NUMBER_PINS_IN_PORT;
		switch (Local_u8PortId)
		{
		case 0:
			/* *p88Value to enter this address and store the PIN value in it */
			*Copy_Pu8Value = BITCALC_GET_BIT(DIO_u8_PINB,Local_u8PinId);
			break;

		case 1:
			/* *p88Value to enter this address and store the PIN value in it */
			*Copy_Pu8Value = BITCALC_GET_BIT(DIO_u8_PIND,Local_u8PinId);
			break;

		case 2:
			/* *p88Value to enter this address and store the PIN value in it */
			*Copy_Pu8Value = BITCALC_GET_BIT(DIO_u8_PINA,Local_u8PinId);
			break;

		case 3:
			/* *p88Value to enter this address and store the PIN value in it */
			*Copy_Pu8Value = BITCALC_GET_BIT(DIO_u8_PINC,Local_u8PinId);
			break;
		}
	}
	else
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return */
	return Local_u8Error;
}


/**************************************************
 * Description: Function to Set port Direction
 * Outputs   :              Error State
 * Inputs    : Copy_u8Direction: direction of the port
 *             Copy_u8PortNB: port number
 ************************************************/
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNB ,u8 Copy_u8Direction)
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error;
	/* if any condition of these ones is true then it will return me an error  */
	if( (Copy_u8PortNB >= DIO_u8_MAX_PORTNB) || ((Copy_u8Direction !=DIO_u8_PORT_OUTPUT) && (Copy_u8Direction !=DIO_u8_PORT_INPUT) && (Copy_u8Direction !=DIO_u8_PORT_LEAST_NIBBLE_OUTPUT) && (Copy_u8Direction !=DIO_u8_PORT_MOST_NIBBLE_OUTPUT)) )
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		switch (Copy_u8PortNB)
		{
		case 0:
			/* assign the  required PORT with the sent value to modify the direction */
			BITCALC_ASSIGN_PORT(DIO_u8_DDRB,Copy_u8Direction);
			break;

		case 1:
			/* assign the  required PORT with the sent value to modify the direction */
			BITCALC_ASSIGN_PORT(DIO_u8_DDRD,Copy_u8Direction);
			break;

		case 2:
			/* assign the  required PORT with the sent value to modify the direction */
			BITCALC_ASSIGN_PORT(DIO_u8_DDRA,Copy_u8Direction);
			break;

		case 3:
			/* assign the  required PORT with the sent value to modify the direction */
			BITCALC_ASSIGN_PORT(DIO_u8_DDRC,Copy_u8Direction);
			break;
		}
	}
	/* Function Return */
	return Local_u8Error;
}


/**************************************************
 * Description: Function to Set port value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PortValue: value of the port
 *             Copy_u8PortNB   : port number
 ************************************************/
u8 DIO_u8SetPortValue(u8 Copy_u8PortNB, u8 Copy_u8PortValue)
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error;
	/* if any condition of these ones is true then it will return me an error  */
	if( (Copy_u8PortNB >= DIO_u8_MAX_PORTNB) )
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		switch (Copy_u8PortNB)
		{
		case 0:
			/* assign the  required PORT with the sent value to modify it's value */
			BITCALC_ASSIGN_PORT(DIO_u8_PORTB,Copy_u8PortValue);
			break;

		case 1:
			/* assign the  required PORT with the sent value to modify it's value */
			BITCALC_ASSIGN_PORT(DIO_u8_PORTD,Copy_u8PortValue);
			break;

		case 2:
			/* assign the  required PORT with the sent value to modify it's value */
			BITCALC_ASSIGN_PORT(DIO_u8_PORTA,Copy_u8PortValue);
			break;

		case 3:
			/* assign the  required PORT with the sent value to modify it's value */
			BITCALC_ASSIGN_PORT(DIO_u8_PORTC,Copy_u8PortValue);
			break;
		}
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
u8 DIO_u8GetPortValue(u8 Copy_u8PortNB, u8* Copy_Pu8Value)
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error;
	/* if any condition of these conditions is not true we will return an error  */
	if( (Copy_u8PortNB <= DIO_u8_MAX_PORTNB) && (Copy_Pu8Value != NULL) )
	{
		switch (Copy_u8PortNB)
		{
		case 0:
			/* *p88Value to enter this address and store the PIN value in it */
			*Copy_Pu8Value = BITCALC_GET_PORT(DIO_u8_PINB);
			break;

		case 1:
			/* *p88Value to enter this address and store the PIN value in it */
			*Copy_Pu8Value = BITCALC_GET_PORT(DIO_u8_PIND);
			break;

		case 2:
			/* *p88Value to enter this address and store the PIN value in it */
			*Copy_Pu8Value = BITCALC_GET_PORT(DIO_u8_PINA);
			break;

		case 3:
			/* *p88Value to enter this address and store the PIN value in it */
			*Copy_Pu8Value = BITCALC_GET_PORT(DIO_u8_PINC);
			break;
		}
	}
	else
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return */
	return Local_u8Error;
}




//u8 DIO_u8init(void)
//{
//u8 Local_u8Error = STD_TYPES_u8_ERROR_OK ;
/* initialize PINs directory as output PINs */
//DIO_u8_DDRA = ( (DIO_u8_PIN0_INIT_DIR) | (DIO_u8_PIN1_INIT_DIR<<1) | (DIO_u8_PIN2_INIT_DIR<<2) | (DIO_u8_PIN3_INIT_DIR<<3) | (DIO_u8_PIN4_INIT_DIR<<4) | (DIO_u8_PIN5_INIT_DIR<<5) | (DIO_u8_PIN6_INIT_DIR<<6) | (DIO_u8_PIN7_INIT_DIR<<7) );
//DIO_u8_DDRB = ( (DIO_u8_PIN8_INIT_DIR) | (DIO_u8_PIN9_INIT_DIR<<1) | (DIO_u8_PIN10_INIT_DIR<<2) | (DIO_u8_PIN11_INIT_DIR<<3) | (DIO_u8_PIN12_INIT_DIR<<4) | (DIO_u8_PIN13_INIT_DIR<<5) | (DIO_u8_PIN14_INIT_DIR<<6) | (DIO_u8_PIN15_INIT_DIR<<7) );
//DIO_u8_DDRC = ( (DIO_u8_PIN16_INIT_DIR) | (DIO_u8_PIN17_INIT_DIR<<1) | (DIO_u8_PIN18_INIT_DIR<<2) | (DIO_u8_PIN19_INIT_DIR<<3) | (DIO_u8_PIN20_INIT_DIR<<4) | (DIO_u8_PIN21_INIT_DIR<<5) | (DIO_u8_PIN22_INIT_DIR<<6) | (DIO_u8_PIN23_INIT_DIR<<7) );
//DIO_u8_DDRD = ( (DIO_u8_PIN24_INIT_DIR) | (DIO_u8_PIN25_INIT_DIR<<1) | (DIO_u8_PIN26_INIT_DIR<<2) | (DIO_u8_PIN27_INIT_DIR<<3) | (DIO_u8_PIN28_INIT_DIR<<4) | (DIO_u8_PIN29_INIT_DIR<<5) | (DIO_u8_PIN30_INIT_DIR<<6) | (DIO_u8_PIN31_INIT_DIR<<7) );
//
/*initialize PINs value as high value */
//DIO_u8_PORTA = ( (DIO_u8_PIN0_INIT_VALUE) | (DIO_u8_PIN1_INIT_VALUE<<1) | (DIO_u8_PIN2_INIT_VALUE<<2) | (DIO_u8_PIN3_INIT_VALUE<<3) | (DIO_u8_PIN4_INIT_VALUE<<4) | (DIO_u8_PIN5_INIT_VALUE<<5) | (DIO_u8_PIN6_INIT_VALUE<<6) | (DIO_u8_PIN7_INIT_VALUE<<7) );
//DIO_u8_PORTB = ( (DIO_u8_PIN8_INIT_VALUE) | (DIO_u8_PIN9_INIT_VALUE<<1) | (DIO_u8_PIN10_INIT_VALUE<<2) | (DIO_u8_PIN11_INIT_VALUE<<3) | (DIO_u8_PIN12_INIT_VALUE<<4) | (DIO_u8_PIN13_INIT_VALUE<<5) | (DIO_u8_PIN14_INIT_VALUE<<6) | (DIO_u8_PIN15_INIT_VALUE<<7) );
//DIO_u8_PORTC = ( (DIO_u8_PIN16_INIT_VALUE) | (DIO_u8_PIN17_INIT_VALUE<<1) | (DIO_u8_PIN18_INIT_VALUE<<2) | (DIO_u8_PIN19_INIT_VALUE<<3) | (DIO_u8_PIN20_INIT_VALUE<<4) | (DIO_u8_PIN21_INIT_VALUE<<5) | (DIO_u8_PIN22_INIT_VALUE<<6) | (DIO_u8_PIN23_INIT_VALUE<<7) );
//DIO_u8_PORTD = ( (DIO_u8_PIN24_INIT_VALUE) | (DIO_u8_PIN25_INIT_VALUE<<1) | (DIO_u8_PIN26_INIT_VALUE<<2) | (DIO_u8_PIN27_INIT_VALUE<<3) | (DIO_u8_PIN28_INIT_VALUE<<4) | (DIO_u8_PIN29_INIT_VALUE<<5) | (DIO_u8_PIN30_INIT_VALUE<<6) | (DIO_u8_PIN31_INIT_VALUE<<7) );
//return Local_u8Error;
//}



//u8 DIO_u8SetPinValue(u8 Copy_u8PinNb, u8 Copy_u8PinValue)
//{
//u8 Local_u8OperationStatus = STD_u8_OK;
//if(u8 Copy_u8PinNb < DIO_u8_MAX_PINNB )
//{
//switch (Copy_u8PinValue)
//{
//case DIO_U8_PIN_HIGH:
//                 if( (Copy_u8PinNb >= DIO_u8_PIN0) && (Copy_u8PinNb < DIO_u8_PIN8))
//			 {
//          	 SET_BIT(DIO_u8_PORTA, Copy_u8PinNb);
//		 }
//       else if ((Copy_u8PinNb >= DIO_u8_PIN8) && (Copy_u8PinNb < DIO_u8_PIN16))
//     {
//  	 SET_BIT(DIO_u8_PORTA, Copy_u8PinNb-8);
// }
//  case DIO_U8_PIN_LOW:
//default: Local_u8OperationStatus = STD_u8_ERROR;
//}

//}
//}
