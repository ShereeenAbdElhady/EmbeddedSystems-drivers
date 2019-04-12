/******************************************************************************************/
/*                                                                                       */
/* File Name   : LMD_prog.c                                                             */
/*                                                                                     */
/* Created on  : Mar 7, 2019                                                          */
/*                                                                                   */
/* Author      : shereen Abd Elhady                                                 */
/*                                                                                 */
/* Version     : V01                                                              */
/*                                                                               */
/* Description : software driver for different types of LED matrix display      */
/*               whether it's active ROW (HIGH OR LOW)                         */
/*               active COL (HIGH OR LOW)                                     */
/*               with a defined public  functions to display images on it    */
/*                                                                          */
/* Layer       : HAL                                                       */
/**************************************************************************/

#include "../STD_TYPES.h"
#include "../BIT_CALC.h"
#include "../include/Delay.h"
#include "../include/DIO_interface.h"
#include "../include/DIO_private.h"
#include "../include/DIO_config.h"
#include "../include/LMD_interface.h"
#include "../include/LMD_private.h"



/************************************************************
 * Description:  Function to display image on the LMD
 * Outputs   :               Error State
 * Inputs    : u8* Copy_Pu8Image: pointer to array of images
 *             Copy_u8Color  :  variable to set the color
 **********************************************************/
u8 LMD_u8Display (u32 *Copy_Pu8Image , u8 Copy_u8Color)
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error;
	/* Local variable indication for loop index   */
	u8 Local_u8LoopIndex;
	if( (Copy_Pu8Image == NULL) && ((Copy_u8Color != LMD_u8_COLOR_RED)||(Copy_u8Color != LMD_u8_COLOR_GREEN)) )
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		switch(Copy_u8Color)
		{
		/* case of RED LMD */
		case LMD_u8_COLOR_RED:
			/* if it is active HIGH and active ROW then do the following logic */
			if((LMD_u8_ACTIVE_TYPE == LMD_u8_ACTIVE_HIGH) && (LMD_u8_TYPE == LMD_u8_ACTIVE_ROW))
			{
				for(Local_u8LoopIndex=0 ; Local_u8LoopIndex < LMD_u8_NUMBER_LEDS; Local_u8LoopIndex++)
				{
					/* set the ROW with HIGH values as it is active HIGH            */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectRowPins[Local_u8LoopIndex], DIO_u8_PIN_HIGH );
					/* set the COL by negative values to draw the image             */
					DIO_u8SetPortValue(LMD_u8_RED_PORT, ~Copy_Pu8Image[Local_u8LoopIndex]);
					delay_milliSecond(6);
					/* set the ROW with LOW value to activate the second ROW        */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectRowPins[Local_u8LoopIndex], DIO_u8_PIN_LOW );
				}
			}
			/* if it is active HIGH and active COL then do the following logic */
			else if((LMD_u8_ACTIVE_TYPE == LMD_u8_ACTIVE_HIGH) && (LMD_u8_TYPE == LMD_u8_ACTIVE_COL))
			{
				for(Local_u8LoopIndex=0 ; Local_u8LoopIndex < LMD_u8_NUMBER_LEDS; Local_u8LoopIndex++)
				{
					/* set the COL with HIGH value as it is active HIGH        */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectColPins[Local_u8LoopIndex], DIO_u8_PIN_HIGH );
					/* set the ROW by negative values to draw the image             */
					DIO_u8SetPortValue(LMD_u8_RED_PORT, ~Copy_Pu8Image[Local_u8LoopIndex]);
					delay_milliSecond(4);
					/* set the COL with LOW value to activate the second column        */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectColPins[Local_u8LoopIndex], DIO_u8_PIN_LOW );
				}
			}
			/* if it is active LOW and active ROW then do the following logic */
			else if((LMD_u8_ACTIVE_TYPE == LMD_u8_ACTIVE_LOW) && (LMD_u8_TYPE == LMD_u8_ACTIVE_ROW))
			{
				for(Local_u8LoopIndex=0 ; Local_u8LoopIndex < LMD_u8_NUMBER_LEDS; Local_u8LoopIndex++)
				{
					/* set the ROW with LOW values as it is active LOW            */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectRowPins[Local_u8LoopIndex], DIO_u8_PIN_LOW );
					/* set the COLS by positive values to draw the image           */
					DIO_u8SetPortValue(LMD_u8_RED_PORT, Copy_Pu8Image[Local_u8LoopIndex]);
					delay_milliSecond(4);
					/* set the ROW with HIGH value to activate the second ROW        */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectRowPins[Local_u8LoopIndex], DIO_u8_PIN_HIGH );
				}
			}
			/* if it is active LOW and active COL then do the following logic */
			else if((LMD_u8_ACTIVE_TYPE == LMD_u8_ACTIVE_LOW) && (LMD_u8_TYPE == LMD_u8_ACTIVE_COL))
			{
				for(Local_u8LoopIndex=0 ; Local_u8LoopIndex < LMD_u8_NUMBER_LEDS; Local_u8LoopIndex++)
				{
					/* set the COL with LOW values as it is active LOW            */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectColPins[Local_u8LoopIndex], DIO_u8_PIN_LOW );
					/* set the ROWS by positive values to draw the image           */
					DIO_u8SetPortValue(LMD_u8_RED_PORT, Copy_Pu8Image[Local_u8LoopIndex]);
					delay_milliSecond(4);
					/* set the COL with HIGH values to activate the second COL      */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectColPins[Local_u8LoopIndex], DIO_u8_PIN_LOW );
				}
			}
			break;
			/* case of GREEN LMD */
		case LMD_u8_COLOR_GREEN:
			/* if it is active HIGH and active ROW then do the following logic */
			if((LMD_u8_ACTIVE_TYPE == LMD_u8_ACTIVE_HIGH) && (LMD_u8_TYPE == LMD_u8_ACTIVE_ROW))
			{
				for(Local_u8LoopIndex=0 ; Local_u8LoopIndex < LMD_u8_NUMBER_LEDS; Local_u8LoopIndex++)
				{
					/* set the ROW with HIGH values as it is active HIGH            */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectRowPins[Local_u8LoopIndex], DIO_u8_PIN_HIGH );
					/* set the COL by negative values to draw the image             */
					DIO_u8SetPortValue(LMD_u8_RED_PORT, ~Copy_Pu8Image[Local_u8LoopIndex]);
					delay_milliSecond(5);
					/* set the ROW with LOW value to activate the second ROW        */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectRowPins[Local_u8LoopIndex], DIO_u8_PIN_LOW );
				}
			}
			/* if it is active HIGH and active COL then do the following logic */
			else if((LMD_u8_ACTIVE_TYPE == LMD_u8_ACTIVE_HIGH) && (LMD_u8_TYPE == LMD_u8_ACTIVE_COL))
			{
				for(Local_u8LoopIndex=0 ; Local_u8LoopIndex < LMD_u8_NUMBER_LEDS; Local_u8LoopIndex++)
				{
					/* set the COL with HIGH value as it is active HIGH        */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectColPins[Local_u8LoopIndex], DIO_u8_PIN_HIGH );
					/* set the ROW by negative values to draw the image             */
					DIO_u8SetPortValue(LMD_u8_RED_PORT, ~Copy_Pu8Image[Local_u8LoopIndex]);
					delay_milliSecond(4);
					/* set the COL with LOW value to activate the second column        */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectColPins[Local_u8LoopIndex], DIO_u8_PIN_LOW );
				}
			}
			/* if it is active LOW and active ROW then do the following logic */
			else if((LMD_u8_ACTIVE_TYPE == LMD_u8_ACTIVE_LOW) && (LMD_u8_TYPE == LMD_u8_ACTIVE_ROW))
			{
				for(Local_u8LoopIndex=0 ; Local_u8LoopIndex < LMD_u8_NUMBER_LEDS; Local_u8LoopIndex++)
				{
					/* set the ROW with LOW values as it is active LOW            */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectRowPins[Local_u8LoopIndex], DIO_u8_PIN_LOW );
					/* set the COLS by positive values to draw the image           */
					DIO_u8SetPortValue(LMD_u8_RED_PORT, Copy_Pu8Image[Local_u8LoopIndex]);
					delay_milliSecond(4);
					/* set the ROW with HIGH value to activate the second ROW        */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectRowPins[Local_u8LoopIndex], DIO_u8_PIN_HIGH );

				}
			}
			/* if it is active LOW and active COL then do the following logic */
			else if((LMD_u8_ACTIVE_TYPE == LMD_u8_ACTIVE_LOW) && (LMD_u8_TYPE == LMD_u8_ACTIVE_COL))
			{
				for(Local_u8LoopIndex=0 ; Local_u8LoopIndex < LMD_u8_NUMBER_LEDS; Local_u8LoopIndex++)
				{
					/* set the COL with LOW values as it is active LOW            */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectColPins[Local_u8LoopIndex], DIO_u8_PIN_LOW );
					/* set the ROWS by positive values to draw the image           */
					DIO_u8SetPortValue(LMD_u8_RED_PORT, Copy_Pu8Image[Local_u8LoopIndex]);
					delay_milliSecond(4);
					/* set the COL with HIGH values to activate the second COL      */
					DIO_u8SetPinValue(LMD_Au8LMDDConnectColPins[Local_u8LoopIndex], DIO_u8_PIN_LOW );
				}
			}
			break;
		}
	}
	/* Function Return */
	return Local_u8Error;
}
