/******************************************************************************************/
/*                                                                                       */
/* File Name   : SWI_prog.c                                                             */
/*                                                                                     */
/* Created on  : Feb 7, 2019                                                          */
/*                                                                                   */
/* Author      : shereen Abd Elhady                                                 */
/*                                                                                 */
/* Version     : V01                                                              */
/*                                                                               */
/* Description : software driver for any SWITCH supports PULL UP and PULL DOWN  */
/*               Connections  with a defined public and private functions.     */
/*                                                                            */
/* Layer       : HAL                                                         */
/****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "SWI_interface.h"
#include "SWI_private.h"


/******************************************************************************************
 * Description: Function to get the pressed switch state whether it is pressed or released
 *              and save this state in the passed variable to the function.
 * Outputs    : Error State
 * Inputs     : u8 *Copy_Pu8Value: pointer to variable
 *              receive the address of this variable from the caller function and begin
 *              to access this address and save the pressed key state in it.
 *              Copy_u8SwIndex   : switch index
 ******************************************************************************************/
u8 SWI_u8GetSwiState(u8* Copy_Pu8Value,u8 Copy_u8SwIndex)
{
	/* Local Variable indication for Error status     */
	u8 Local_u8Error;
	/* Local Variable contains PIN value             */
	u8 Local_u8PinValue;
	if((Copy_u8SwIndex < SWI_u8_NUM_OF_SWI) && (Copy_Pu8Value != NULL))
	{
		if (SWI_Au8SwiType[Copy_u8SwIndex] == PULL_DOWN_CONNECTION)
		{
			/* Reading the DIO by sending it the switch index(mapped to PIN number in the array)
			 * and sending the address of variable to store the value in it
			 */
			DIO_u8GetPinValue(SWI_Au8SwiCh[Copy_u8SwIndex], &Local_u8PinValue);
			if(Local_u8PinValue == SWI_u8_HIGH)
			{
				* Copy_Pu8Value = SWI_u8_PRESSED;
			}
			else
			{
				* Copy_Pu8Value = SWI_u8_RELEASED;
			}
		}
		else if (SWI_Au8SwiType[Copy_u8SwIndex] == PULL_UP_CONNECTION)
		{
			/* Reading the DIO by sending it the switch index(mapped to PIN number in the array)
			 * and sending the address of variable to store the value in it
			 */
			DIO_u8GetPinValue(SWI_Au8SwiCh[Copy_u8SwIndex], &Local_u8PinValue);
			if(Local_u8PinValue == SWI_u8_HIGH)
			{
				* Copy_Pu8Value = SWI_u8_RELEASED;
			}
			else
			{
				* Copy_Pu8Value = SWI_u8_PRESSED;
			}
		}
	}
	else
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function return */
	return Local_u8Error;
}
