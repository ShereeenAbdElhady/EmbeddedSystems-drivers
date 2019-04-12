/**********************************************************************************************/
/*                                                                                           */
/* File Name   : LED_prog.c                                                                 */
/*                                                                                         */
/* Created on  : Jan 29, 2019                                                             */
/*                                                                                       */
/* Author      : shereen Abd Elhady                                                     */
/*                                                                                     */
/* Version     : V01                                                                  */
/*                                                                                   */
/* Description : Software  LED driver contains public and private APIs' definitions */
/*                                                                                 */
/* Layer       : HAL                                                              */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "LED_interface.h"
#include "LED_private.h"


/****************************************************
 * Description: Function to initialize LED Direction
 * Outputs   : Error State
 * Inputs    : Copy_u8ledIndex:     LED array index
 *****************************************************/
u8 LED_u8init(u8 Copy_u8ledIndex)
{
	/* Local Variable indication for Error status                                      */
	u8 Local_u8Error;
	/* if the user send an index within array index the code will be implemented       */
	if (Copy_u8ledIndex < LED_u8_NUM_OF_LEDS)
	{
		/* Setting PIN direction of the LED                                           */
		DIO_u8SetPinDirection(LED_Au8ledch[Copy_u8ledIndex],LED_u8_OUTPUT);

	}
	/* If the user send an index not within array index Range                         */
	/* The code will not be implemented Then will return error not oky                */
	else
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function return                                                                */
	return Local_u8Error;
}


/****************************************************
 * Description: Function to Set LED ON
 * Outputs   : Error State
 * Inputs    : Copy_u8ledIndex:     LED array index
 *****************************************************/
u8 LED_u8LEDON(u8 Copy_u8ledIndex)
{
	/* Local Variable indication for Error status                                      */
	u8 Local_u8Error;
	/* if the user send an index within array index the code will be implemented       */
	if (Copy_u8ledIndex < LED_u8_NUM_OF_LEDS)
	{
		/* If the configured connection was FORWARD then set PIN HIGH                  */
		if (LED_Au8ledType[Copy_u8ledIndex] == LED_u8_FORWARD )
		{
			DIO_u8SetPinValue(LED_Au8ledch[Copy_u8ledIndex],LED_u8_HIGH );
		}
		/* If the configured connection was REVERSE then set PIN LOW                   */
		else
		{
			DIO_u8SetPinValue(LED_Au8ledch[Copy_u8ledIndex],LED_u8_LOW );
		}
	}
	/* If the user send an index not within array index Range                         */
	/* The code will not be implemented Then will return error not oky                */
	else
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function return                                                                */
	return Local_u8Error;
}


/****************************************************
 * Description: Function to Set LED OFF
 * Outputs   : Error State
 * Inputs    : Copy_u8ledIndex:     LED array index
 *****************************************************/
u8 LED_u8LEDOFF(u8 Copy_u8ledIndex)
{
	/* Local Variable indication for Error status                                      */
	u8 Local_u8Error;
	/* if the user send an index within array index the code will be implemented       */
	if (Copy_u8ledIndex < LED_u8_NUM_OF_LEDS)
	{
		/* If the configured connection was FORWARD then set PIN LOW                   */
		if (LED_Au8ledType[Copy_u8ledIndex] == LED_u8_FORWARD )
		{
			DIO_u8SetPinValue(LED_Au8ledch[Copy_u8ledIndex],LED_u8_LOW );
		}
		/* If the configured connection was REVERSE then set PIN HIGH                   */
		else
		{
			DIO_u8SetPinValue(LED_Au8ledch[Copy_u8ledIndex],LED_u8_HIGH );
		}
	}
	/* If the user send an index not within array index Range                           */
	/* The code will not be implemented Then will return error not oky                  */
	else
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function return                                                                  */
	return Local_u8Error;
}

