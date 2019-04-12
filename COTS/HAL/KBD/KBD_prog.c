/******************************************************************************************/
/*                                                                                       */
/* File Name   : KBD_prog.c                                                             */
/*                                                                                     */
/* Created on  : Feb 12, 2019                                                         */
/*                                                                                   */
/* Author      : shereen Abd Elhady                                                 */
/*                                                                                 */
/* Version     : V01                                                              */
/*                                                                               */
/* Description : software driver for MATRIX KeyPad with configurable            */
/*               Number of ROWs and COLs                                       */
/*               with a defined public and private functions                  */
/* Layer       : HAL                                                         */
/****************************************************************************/

#include "../STD_TYPES.h"
#include "../BIT_CALC.h"
#include "../include/DIO_interface.h"
#include "../include/DIO_private.h"
#include "../include/KBD_interface.h"
#include "../include/KBD_private.h"

/******************************************************************************************
 * Description: Function to get the pressed key state whether it is pressed or released
 *              and save this state in the passed 2D array to the function.
 * Outputs    : Error State
 * Inputs     : u8 (*Copy_Pu8Arr)[KBD_u8_NUMBER_OF_COLS]: pointer to 2D array of integers
 *              receive the address of this array from the caller function and begin
 *              to access these addresses and save the pressed key state in it.
 *
 ******************************************************************************************/
u8 KBD_u8GetPressedKeyState(u8 (*Copy_Pu8Arr)[KBD_u8_NUMBER_OF_COLS])
{
	/* Local Variable indication for Error status     */
	u8 Local_u8Error;
	/* Local variable indication for loop index       */
	u8 Local_u8LoopRowIndex;
	/* Local variable indication for loop index       */
	u8 Local_u8LoopColIndex;
	/* Local Variable contains PIN value              */
	u8 Local_u8PinValue;

	/* If it is a wild pointer then return an error                                   */
	if(Copy_Pu8Arr == NULL)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* Switch the cases of the keypad connection type                                         */
		switch( KBD_u8_TYPE_OF_CONNECTION )
		{
		/* In case of keypad switches were connected in pull up connection                        */
		case PULL_UP_CONNECTION:
			/********* PULL UP and active COL Mechanism*******/
			/* first set the ROWs direction as an INPUT and their values are HIGH                 */
			/* second set the COLs direction as an OUTPUT and their values are HIGH               */
			/* third activate each COL with LOW value                                             */
			/* Fourth scan the ROW value if it is LOW then the key is PRESSED else it is RELEASED */
			/* Fifth return the COL to HIGH value again to activate the second COL                */

			/* if the activation type was active column then do the following logic               */
			if(KBD_u8_TYPE_OF_ACTIVATION ==  KBD_u8_ACTIVE_COL)
			{
				/* For loop to go through the rows and check for their values                     */
				/* either it is high or low to know the switch state                              */
				for(Local_u8LoopRowIndex=0 ; Local_u8LoopRowIndex <KBD_u8_NUMBER_OF_ROWS ; Local_u8LoopRowIndex++)
				{
					/* For loop to go through the columns and set their values with low value     */
					/* in case of pull up connection                                              */
					for(Local_u8LoopColIndex=0; Local_u8LoopColIndex < KBD_u8_NUMBER_OF_COLS ; Local_u8LoopColIndex++)
					{
						/* Set the column with low value in case of pull up connection           */
						DIO_u8SetPinValue(KBD_Au8KBDConnectColPins[Local_u8LoopColIndex], KBD_u8_LOW);
						/* Get the row PIN value                                                 */
						DIO_u8GetPinValue(KBD_Au8KBDConnectRowPins[Local_u8LoopRowIndex], &Local_u8PinValue);
						if(Local_u8PinValue == KBD_u8_LOW)
						{
							/* Write in the passed 2D array the state of the key is pressed       */
							Copy_Pu8Arr[Local_u8LoopRowIndex][Local_u8LoopColIndex] = KBD_u8_PRESSED;
						}
						else
						{
							/* Write in the passed 2D array the state of the key is released      */
							Copy_Pu8Arr[Local_u8LoopRowIndex][Local_u8LoopColIndex] = KBD_u8_RELEASED;
						}
						/* Return the column with HIGH value again to activate the next column     */
						DIO_u8SetPinValue(KBD_Au8KBDConnectColPins[Local_u8LoopColIndex], KBD_u8_HIGH);
					}
				}
			}
			/********* PULL UP and active ROW Mechanism*******/
			/* first set the COLs direction as an INPUT and their values are HIGH                 */
			/* second set the ROWs direction as an OUTPUT and their values are HIGH               */
			/* third activate each ROW with LOW value                                             */
			/* Fourth scan the COL value if it is LOW then the key is PRESSED else it is RELEASED */
			/* Fifth return the ROW to HIGH value again to activate the second ROW                */

			/* if the activation type was active ROW then do the following logic                  */
			else if(KBD_u8_TYPE_OF_ACTIVATION ==  KBD_u8_ACTIVE_ROW)
			{
				/* For loop to go through the COLs and check for their values                     */
				/* either it is high or low to know the switch state                              */
				for(Local_u8LoopColIndex=0 ; Local_u8LoopColIndex <KBD_u8_NUMBER_OF_COLS ; Local_u8LoopColIndex++)
				{
					/* For loop to go through the ROWs and set their values with LOW value        */
					/* in case of pull UP connection                                              */
					for(Local_u8LoopRowIndex=0; Local_u8LoopRowIndex < KBD_u8_NUMBER_OF_ROWS ; Local_u8LoopRowIndex++)
					{
						/* Set the ROW with LOW value in case of pull UP connection                */
						DIO_u8SetPinValue(KBD_Au8KBDConnectRowPins[Local_u8LoopRowIndex], KBD_u8_LOW);
						/* Get the COL PIN value                                                   */
						DIO_u8GetPinValue(KBD_Au8KBDConnectColPins[Local_u8LoopColIndex], &Local_u8PinValue);
						if(Local_u8PinValue == KBD_u8_LOW)
						{
							/* Write in the passed 2D array the state of the key is pressed       */
							Copy_Pu8Arr[Local_u8LoopRowIndex][Local_u8LoopColIndex] = KBD_u8_PRESSED;
						}
						else
						{
							/* Write in the passed 2D array the state of the key is released      */
							Copy_Pu8Arr[Local_u8LoopRowIndex][Local_u8LoopColIndex] = KBD_u8_RELEASED;
						}
						/* Return the ROW with HIGH value again to activate the next ROW           */
						DIO_u8SetPinValue(KBD_Au8KBDConnectRowPins[Local_u8LoopRowIndex], KBD_u8_HIGH);
					}
				}
			}
			break;

			/* In case of keypad switches were connected in pull DOWN connection                   */
		case PULL_DOWN_CONNECTION:
			/********* PULL DOWN and active COL Mechanism*******/
			/* first set the ROWs direction as an INPUT and their values are LOW                  */
			/* second set the COLs direction as an OUTPUT and their values are LOW                */
			/* third activate each COL with HIGH value                                            */
			/* Fourth scan the ROW value if it is HIGH then the key is PRESSED else it is RELEASED*/
			/* Fifth return the COL to LOW value again to activate the second COL                 */

			/* if the activation type was active column then do the following logic               */
			if(KBD_u8_TYPE_OF_ACTIVATION ==  KBD_u8_ACTIVE_COL)
			{
				/* For loop to go through the rows and check for their values                     */
				/* either it is high or low to know the switch state                              */
				for(Local_u8LoopRowIndex=0 ; Local_u8LoopRowIndex <KBD_u8_NUMBER_OF_ROWS ; Local_u8LoopRowIndex++)
				{
					/* For loop to go through the columns and set their values with HIGH value    */
					/* in case of pull down connection                                            */
					for(Local_u8LoopColIndex=0; Local_u8LoopColIndex < KBD_u8_NUMBER_OF_COLS ; Local_u8LoopColIndex++)
					{
						/* Set the column with HIGH value in case of pull down connection         */
						DIO_u8SetPinValue(KBD_Au8KBDConnectColPins[Local_u8LoopColIndex], KBD_u8_HIGH);
						/* Get the row PIN value                                                  */
						DIO_u8GetPinValue(KBD_Au8KBDConnectRowPins[Local_u8LoopRowIndex], &Local_u8PinValue);
						if(Local_u8PinValue == KBD_u8_HIGH)
						{
							/* Write in the passed 2D array the state of the key is pressed       */
							Copy_Pu8Arr[Local_u8LoopRowIndex][Local_u8LoopColIndex] = KBD_u8_PRESSED;
						}
						else
						{
							/* Write in the passed 2D array the state of the key is released      */
							Copy_Pu8Arr[Local_u8LoopRowIndex][Local_u8LoopColIndex] = KBD_u8_RELEASED;
						}
						/* Return the column with LOW value again to activate the next column      */
						DIO_u8SetPinValue(KBD_Au8KBDConnectColPins[Local_u8LoopColIndex], KBD_u8_LOW);
					}
				}
			}
			/********* PULL DOWN and active ROW Mechanism*******/
			/* first set the COLs direction as an INPUT and their values are LOW                  */
			/* second set the ROWs direction as an OUTPUT and their values are LOW                */
			/* third activate each ROW with HIGH value                                            */
			/* Fourth scan the COL value if it is HIGH then the key is PRESSED else it is RELEASED*/
			/* Fifth return the ROW to LOW value again to activate the second ROW                 */

			/* if the activation type was active ROW then do the following logic                  */
			else if(KBD_u8_TYPE_OF_ACTIVATION ==  KBD_u8_ACTIVE_ROW)
			{
				/* For loop to go through the COLs and check for their values                     */
				/* either it is high or low to know the switch state                              */
				for(Local_u8LoopColIndex=0 ; Local_u8LoopColIndex <KBD_u8_NUMBER_OF_COLS ; Local_u8LoopColIndex++)
				{
					/* For loop to go through the ROWs and set their values with HIGH value       */
					/* in case of pull down connection                                            */
					for(Local_u8LoopRowIndex=0; Local_u8LoopRowIndex < KBD_u8_NUMBER_OF_ROWS ; Local_u8LoopRowIndex++)
					{
						/* Set the ROW with HIGH value in case of pull down connection             */
						DIO_u8SetPinValue(KBD_Au8KBDConnectRowPins[Local_u8LoopRowIndex], KBD_u8_HIGH);
						/* Get the COL PIN value                                                   */
						DIO_u8GetPinValue(KBD_Au8KBDConnectColPins[Local_u8LoopColIndex], &Local_u8PinValue);
						if(Local_u8PinValue == KBD_u8_HIGH)
						{
							/* Write in the passed 2D array the state of the key is pressed       */
							Copy_Pu8Arr[Local_u8LoopRowIndex][Local_u8LoopColIndex] = KBD_u8_PRESSED;
						}
						else
						{
							/* Write in the passed 2D array the state of the key is released      */
							Copy_Pu8Arr[Local_u8LoopRowIndex][Local_u8LoopColIndex] = KBD_u8_RELEASED;
						}
						/* Return the ROW with LOW value again to activate the next ROW           */
						DIO_u8SetPinValue(KBD_Au8KBDConnectRowPins[Local_u8LoopRowIndex], KBD_u8_LOW);
					}
				}
			}
			break;
		}
	}
	/* Function Return */
	return Local_u8Error;
}


