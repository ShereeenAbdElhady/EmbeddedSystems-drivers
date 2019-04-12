/******************************************************************************************/
/*                                                                                       */
/* File Name   : SSD_prog.c                                                             */
/*                                                                                     */
/* Created on  : Feb 8, 2019                                                          */
/*                                                                                   */
/* Author      : shereen Abd Elhady                                                 */
/*                                                                                 */
/* Version     : V01                                                              */
/*                                                                               */
/* Description : software driver for common cathod and common anode             */
/*               seven segment  with a defined public and private functions    */
/*               to display numbers on it .                                   */
/*                                                                           */
/* Layer       : HAL                                                        */
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include "SSD_interface.h"
#include "SSD_private.h"


/* initialization of static global variable whose lifetime along the whole project and it's scope within this file
 * Flag as indication that the seven segment is ON not OFF                                                        */
static u8 SSD_u8SSDStatusON = 1;


/*******************************************************************************************
 * Description : Function responsible for displaying a number send by user
 *               on a seven segment and decide either it is gonna be displayed
 *               on common anode or common cathod according to the user configurations.
 * Input       : Copy_u8NumberValue : number to be displayed
 *               Copy_u8SSDIndex    : seven segment display index
 * Output      : Error state
 *******************************************************************************************/
u8 SSD_u8DisplayNumber(u8 Copy_u8SSDIndex,u8 Copy_u8NumberValue)
{
	/* local variable indication for error status                                                   */
	u8 Local_u8Error;
	/* local variable indicates PINs index                                                          */
	u8 Local_u8PinIndex=0;
	//static Local_u8PinVal;
	/* If the user send an index not within array index Range
	 * If the user send a number to display greater than the maximum number                         */
	/* The code will not be implemented Then will return error not OKY                              */
	if((Copy_u8NumberValue >= SSD_u8_NUMBER_MAX) && (Copy_u8SSDIndex >= SSD_u8_NUM_OF_SSD))
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* If the seven segment is ON then do the following logic                                   */
		if(SSD_u8SSDStatusON == 1)
		{
			/* If the seven segment type is common cathod then perform the following logic          */
			if(SSD_Au8SSDType[Copy_u8SSDIndex] == SSD_u8_COMMON_CATHOD)
			{
				/* for loop to set each PIN in the seven segment with the corresponding bit value
				 * in the number passed by the user                                                 */
				for ( Local_u8PinIndex = 0;  Local_u8PinIndex < SSD_u8_NUM_OF_PINS  ; Local_u8PinIndex ++)
				{
					/* SSD_Au8SSDConnectPin[Copy_u8SSDIndex][Local_u8PinIndex]: to a specific PIN in the SSD to be set
					 * SSD_Au8NumberBinaryCathod[Copy_u8NumberValue]          : the passed number value in binary representation
					 * Local_u8PinIndex                                       : accessing the passed value bit by bit in the binary representation
					 * using the GET_BIT macro to get pin value we want to set the SSD PIN with
					 */
					DIO_u8SetPinValue(SSD_Au8SSDConnectPin[Copy_u8SSDIndex][Local_u8PinIndex] , SSD_Au8NumberBinaryCathod[Copy_u8NumberValue][Local_u8PinIndex]);
					//DIO_u8SetPinValue(SSD_Au8SSDConnectPin[Copy_u8SSDIndex][Local_u8PinIndex] , BITCALC_GET_BIT(SSD_Au8NumberBinaryCathod[Copy_u8NumberValue],Local_u8PinIndex));
				}

			}
			/* If the seven segment type is common anode then perform the following logic          */
			else if(SSD_Au8SSDType[Copy_u8SSDIndex] == SSD_u8_COMMON_ANODE)
			{
				/* for loop to set each PIN in the seven segment with the corresponding bit value
				 * in the number passed by the user                                                 */
				for ( Local_u8PinIndex = 0;  Local_u8PinIndex < SSD_u8_NUM_OF_PINS; Local_u8PinIndex++)
				{
					/* SSD_Au8SSDConnectPin[Copy_u8SSDIndex][Local_u8PinIndex]: to a specific PIN in the SSD to be set
					 * SSD_Au8NumberBinaryCathod[Copy_u8NumberValue]          : the passed number value in binary representation
					 * Local_u8PinIndex                                       : accessing the passed value bit by bit in the binary representation
					 * using the GET_BIT macro to get pin value we want to set the SSD PIN with
					 */
					DIO_u8SetPinValue(SSD_Au8SSDConnectPin[Copy_u8SSDIndex][Local_u8PinIndex] , SSD_Au8NumberBinaryAnode[Copy_u8NumberValue][Local_u8PinIndex]);
					//DIO_u8SetPinValue(SSD_Au8SSDConnectPin[Copy_u8SSDIndex][Local_u8PinIndex] , BITCALC_GET_BIT(SSD_Au8NumberBinaryAnode[Copy_u8NumberValue],Local_u8PinIndex));
				}
			}
		}
	}
	/* Function Return                                                                               */
	return Local_u8Error;
}


/*******************************************************************************************
 * Description : Function responsible for displaying a specific segment send by user
 *               on a seven segment and decide either it is gonna be displayed
 *               on common anode or common cathod according to the user configurations.
 * Input       : Copy_u8SegmentValue : segment to be displayed
 *               Copy_u8SSDIndex    : seven segment display index
 * Output      : Error state
 *******************************************************************************************/
u8 SSD_u8DisplaySegment(u8 Copy_u8SSDIndex, u8 Copy_u8SegmentValue)
{
	/* local variable indication for error status                                                   */
	u8 Local_u8Error;
	/* local variable indicates PINs index                                                          */
	u8 Local_u8PinIndex=0;
	if( (Copy_u8SSDIndex >= SSD_u8_NUM_OF_SSD) &&
			( (Copy_u8SegmentValue != SSD_u8_A_SEG) ||
					(Copy_u8SegmentValue != SSD_u8_B_SEG) ||
					(Copy_u8SegmentValue != SSD_u8_C_SEG) ||
					(Copy_u8SegmentValue != SSD_u8_D_SEG) ||
					(Copy_u8SegmentValue != SSD_u8_E_SEG) ||
					(Copy_u8SegmentValue != SSD_u8_F_SEG) ||
					(Copy_u8SegmentValue != SSD_u8_G_SEG)
			)
	)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		for(Local_u8PinIndex=0; Local_u8PinIndex< SSD_u8_NUM_OF_SEGMENTS; Local_u8PinIndex++)
		{
			DIO_u8SetPinValue(SSD_Au8SSDConnectPin[Copy_u8SSDIndex][Local_u8PinIndex], SSD_Au8SegmentsArray[Copy_u8SegmentValue][Local_u8PinIndex]);
		}
	}
	return Local_u8Error;
}


/*******************************************************************************************
 * Description : Function responsible for Turning ON the seven segment
 *               either it is was a common anode or a common cathod seven segment
 *               according to the user configurations.
 * Input       : Copy_u8SSDIndex    : seven segment display index
 * Output      : Error state
 *******************************************************************************************/
u8 SSD_u8SetSSDOn(u8 Copy_u8SSDIndex)
{
	/* local variable indication for error status                                                    */
	u8 Local_u8Error;
	/* If the user send an index not within array index Range
	 * The code will not be implemented Then will return error not OKY                               */
	if(Copy_u8SSDIndex >= SSD_u8_NUM_OF_SSD)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* if the SSD is common cathod then set the common PIN with zero value                           */
		if(SSD_Au8SSDType[Copy_u8SSDIndex]== SSD_u8_COMMON_CATHOD)
		{
			DIO_u8SetPinValue(SSD_Au8SSDConnectPin[ Copy_u8SSDIndex][SSD_u8_MSB] , SSD_u8_COMMON_GND_VALUE);
		}
		/* if the SSD is common anode then set the common PIN with one value                             */
		else if(SSD_Au8SSDType[Copy_u8SSDIndex]== SSD_u8_COMMON_ANODE)
		{
			DIO_u8SetPinValue(SSD_Au8SSDConnectPin[ Copy_u8SSDIndex][SSD_u8_MSB] , SSD_u8_COMMON_VCC_VALUE);
		}
		/* set the flag that indicates that the SSD is ON by one to set the SSD to the ON mode                                          */
		SSD_u8SSDStatusON = 1;
	}
	/* Function Return                                                                               */
	return Local_u8Error;
}


/*******************************************************************************************
 * Description : Function responsible for Turning OFF the seven segment
 *               either it is was a common anode or a common cathod seven segment
 *               according to the user configurations.
 * Input       : Copy_u8SSDIndex    : seven segment display index
 * Output      : Error state
 *******************************************************************************************/
u8 SSD_u8SetSSDOff(u8 Copy_u8SSDIndex)
{
	/* local variable indication for error status                                                    */
	u8 Local_u8Error;
	/* If the user send an index not within array index Range
	 * The code will not be implemented Then will return error not OKY                               */
	if(Copy_u8SSDIndex >= SSD_u8_NUM_OF_SSD)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* if the SSD is common cathod then set the common PIN with one value                           */
		if(SSD_Au8SSDType[Copy_u8SSDIndex]== SSD_u8_COMMON_CATHOD)
		{
			DIO_u8SetPinValue(SSD_Au8SSDConnectPin[ Copy_u8SSDIndex][SSD_u8_MSB] , SSD_u8_COMMON_VCC_VALUE);
		}
		/* if the SSD is common anode then set the common PIN with one value                             */
		else if(SSD_Au8SSDType[Copy_u8SSDIndex]== SSD_u8_COMMON_ANODE)
		{
			DIO_u8SetPinValue(SSD_Au8SSDConnectPin[ Copy_u8SSDIndex][SSD_u8_MSB] , SSD_u8_COMMON_GND_VALUE);
		}
		/* set the flag that indicates that the SSD is ON by zero to set the SSD to the OFF mode         */
		SSD_u8SSDStatusON = 0;
	}
	/* Function Return                                                                               */
	return Local_u8Error;
}


/*******************************************************************************************
 * Description : Function responsible for initializing the seven segment
 *               either it is was a common anode or a common cathod seven segment
 *               according to the user configurations.
 * Input       : void
 * Output      : void
 *******************************************************************************************/
void SSD_u8InitSSD(void)
{
	/* local variable indication for seven segment numbers */
	u8 Local_u8SSDIndex;
	/* local variable indicates PINs index                                                          */
	u8 Local_u8PinIndex;
	/* for loop to loop on the connected seven segments */
	for (Local_u8SSDIndex= 0 ; Local_u8SSDIndex < SSD_u8_NUM_OF_SSD  ;  Local_u8SSDIndex++)
	{
		/* If the seven segment type is common cathod then perform the following logic          */
		if(SSD_Au8SSDType[Local_u8SSDIndex] == SSD_u8_COMMON_CATHOD)
		{
			/* for loop to set each PIN direction in the seven segment                          */
			for ( Local_u8PinIndex = 0;  Local_u8PinIndex < SSD_u8_NUM_OF_PINS; Local_u8PinIndex++)
			{
				/* SSD_Au8SSDConnectPin[Local_u8SSDIndex][Local_u8PinIndex]: to a specific PIN in the SSD
				 * to set it's direction as an OUTPUT PIN
				 */
				DIO_u8SetPinDirection(SSD_Au8SSDConnectPin[Local_u8SSDIndex][Local_u8PinIndex] , SSD_u8_PIN_DIR_OUTPUT  );
				//DIO_u8SetPinValue( SSD_Au8SSDConnectPin[Local_u8SSDIndex][Local_u8PinIndex] , BITCALC_GET_BIT(SSD_Au8SSDInitVal[Local_u8SSDIndex],Local_u8PinIndex) ) ;
			}

		}
		else if(SSD_Au8SSDType[Local_u8SSDIndex] == SSD_u8_COMMON_ANODE)
		{
			/* for loop to set each PIN direction in the seven segment                          */
			for ( Local_u8PinIndex = 0;  Local_u8PinIndex < SSD_u8_NUM_OF_PINS; Local_u8PinIndex++)
			{
				/* SSD_Au8SSDConnectPin[Local_u8SSDIndex][Local_u8PinIndex]: to a specific PIN in the SSD
				 * to set it's direction as an OUTPUT PIN
				 */
				DIO_u8SetPinDirection(SSD_Au8SSDConnectPin[Local_u8SSDIndex][Local_u8PinIndex] , SSD_u8_PIN_DIR_OUTPUT  );
			}
		}

	}
}

