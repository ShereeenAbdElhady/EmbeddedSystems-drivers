/**********************************************************************************/
/*                                                                               */
/* File Name   : DC_MOTOR_prog.c                                                */
/*                                                                             */
/* Created on  : Mar 19, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V01                                                      */
/*                                                                       */
/* Description : software driver for DC motor to control it's direction */
/*                of rotation and it's states                          */
/*               with a defined public and private functions for the  */
/*               For STM32F103C8 ARM Microcontroller.                */
/*                                                                  */
/* Layer       : HAL                                               */
/******************************************************************/

#include "../STD_TYPES.h"
#include "../BIT_CALC.h"
#include "../include/Delay.h"
#include "../include/DIO_interface.h"
#include "../include/DIO_private.h"
#include "../include/RCC_interface.h"
#include "../include/RCC_private.h"
#include "../include/DCMOTOR_interface.h"
#include "../include/DCMOTOR_private.h"



/* Array of flags used as an indication for the ON motors                 */
static u8 Local_Au8MotorsONFlag[DCMOTOR_u8_NO_MOTORS]        ;
/* Array includes the initial directions of the motors                    */
static u8 Local_Au8MotorsSetDirection[DCMOTOR_u8_NO_MOTORS]  ;


/**********************************************************************************
 * Description: Function to initialize motor's direction of rotation and it's state
 *              Also initialize the motor's state whether it is ON or OFF.
 * Outputs    : None
 * Inputs     : None
 **********************************************************************************/
void DCMOTOR_vidInitialize(void)
{
	/* index to loop through the number of motors */
	u8 Local_u8LoopIndex;
	/* For loop to loop through a number of motors                            */
	for (Local_u8LoopIndex=0 ; Local_u8LoopIndex<DCMOTOR_u8_NO_MOTORS  ; Local_u8LoopIndex++)
	{
		if(DCMOTOR_Au8MotorInitState[Local_u8LoopIndex] == DCMOTOR_u8_STATE_ON)
		{
			if(DCMOTOR_Au8MotorInitDirection[DCMOTOR_u8_NO_MOTORS] == DCMOTOR_u8_CLOCKWISE)
			{
				//DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Local_u8LoopIndex][0], DCMOTOR_Au8MotorActiveType[Local_u8LoopIndex]);
				//DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Local_u8LoopIndex][1], !DCMOTOR_Au8MotorActiveType[Local_u8LoopIndex]);
				Local_Au8MotorsSetDirection[Local_u8LoopIndex] = DCMOTOR_u8_CLOCKWISE;
				Local_Au8MotorsONFlag[Local_u8LoopIndex] = 1  ;
			}
			else if(DCMOTOR_Au8MotorInitDirection[DCMOTOR_u8_NO_MOTORS] == DCMOTOR_u8_ANTICLOCKWISE)
			{
				//DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Local_u8LoopIndex][0], !DCMOTOR_Au8MotorActiveType[Local_u8LoopIndex]);
				//DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Local_u8LoopIndex][1], DCMOTOR_Au8MotorActiveType[Local_u8LoopIndex]);
				Local_Au8MotorsSetDirection[Local_u8LoopIndex] = DCMOTOR_u8_ANTICLOCKWISE;
				Local_Au8MotorsONFlag[Local_u8LoopIndex] = 1  ;
			}
		}
		else if (DCMOTOR_Au8MotorInitState[Local_u8LoopIndex] == DCMOTOR_u8_STATE_OFF)
		{
			if(DCMOTOR_Au8MotorInitDirection[DCMOTOR_u8_NO_MOTORS] == DCMOTOR_u8_CLOCKWISE)
			{
				DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Local_u8LoopIndex][0], !DCMOTOR_Au8MotorActiveType[Local_u8LoopIndex]);
				DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Local_u8LoopIndex][1], !DCMOTOR_Au8MotorActiveType[Local_u8LoopIndex]);
				Local_Au8MotorsSetDirection[Local_u8LoopIndex] = DCMOTOR_u8_CLOCKWISE;
				Local_Au8MotorsONFlag[Local_u8LoopIndex] = 0  ;
			}
			else if(DCMOTOR_Au8MotorInitDirection[DCMOTOR_u8_NO_MOTORS] == DCMOTOR_u8_ANTICLOCKWISE)
			{
				DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Local_u8LoopIndex][0], !DCMOTOR_Au8MotorActiveType[Local_u8LoopIndex]);
				DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Local_u8LoopIndex][1], !DCMOTOR_Au8MotorActiveType[Local_u8LoopIndex]);
				Local_Au8MotorsSetDirection[Local_u8LoopIndex] = DCMOTOR_u8_ANTICLOCKWISE;
				Local_Au8MotorsONFlag[Local_u8LoopIndex] = 0  ;
			}
		}
	}
}


/***********************************************************************************
 * Description: Function to set motor's state to ON state
 * Outputs    : Error state
 * Inputs     : u8 Copy_u8MotorIndex : index of the motor
 ***********************************************************************************/
u8 DCMOTOR_u8MotorON(u8 Copy_u8MotorIndex)
{
	/* Local Variable indication for Error status                      */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                                      */
	if (Copy_u8MotorIndex >= DCMOTOR_u8_NO_MOTORS)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* set the array of flags with  one as an indication for ON state*/
		Local_Au8MotorsONFlag[Copy_u8MotorIndex] = 1  ;
		/*if the Direction array is setted with clockwise direction      */
		if (Local_Au8MotorsSetDirection[Copy_u8MotorIndex] ==  DCMOTOR_u8_CLOCKWISE)
		{
			/* call the RotateClockWise function                         */
			Local_u8Error = DCMOTOR_u8MotorRotateClockWise(Copy_u8MotorIndex);
		}
		/*if the Direction array is setted with anti clockwise direction*/
		else if (Local_Au8MotorsSetDirection[Copy_u8MotorIndex] ==  DCMOTOR_u8_ANTICLOCKWISE)
		{
			/* call the RotateAntiClockWise function                    */
			Local_u8Error = DCMOTOR_u8MotorRotateAntiClockWise(Copy_u8MotorIndex);
		}
	}
	/* Function Return */
	return Local_u8Error;
}


/************************************************************************************
 * Description: Function to set motor's state to OFF state
 * Outputs    : Error state
 * Inputs     : u8 Copy_u8MotorIndex : index of the motor
 *************************************************************************************/
u8 DCMOTOR_u8MotorOFF(u8 Copy_u8MotorIndex)
{
	/* Local Variable indication for Error status                      */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                                      */
	if (Copy_u8MotorIndex >= DCMOTOR_u8_NO_MOTORS)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* set the two pins with zero to switch off the motor          */
		Local_u8Error = DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Copy_u8MotorIndex][0], !DCMOTOR_Au8MotorActiveType[Copy_u8MotorIndex]);
		Local_u8Error = DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Copy_u8MotorIndex][1], !DCMOTOR_Au8MotorActiveType[Copy_u8MotorIndex]);
		/* set the array of flags with zero as an indication for OFF state*/
		Local_Au8MotorsONFlag[Copy_u8MotorIndex] = 0  ;
	}
	/* Function Return */
	return Local_u8Error;
}


/**************************************************************************************
 * Description: Function to set motor's direction of rotation to clockwise direction
 * Outputs    : Error state
 * Inputs     : u8 Copy_u8MotorIndex : index of the motor
 **************************************************************************************/
u8 DCMOTOR_u8MotorRotateClockWise(u8 Copy_u8MotorIndex)
{
	/* Local Variable indication for Error status                 */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                                 */
	if (Copy_u8MotorIndex >= DCMOTOR_u8_NO_MOTORS)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* If the motor state is on                               */
		if (Local_Au8MotorsONFlag[Copy_u8MotorIndex] == 1)
		{
			/* if it is rotate in the anti clockwise direction     */
			if (Local_Au8MotorsSetDirection[Copy_u8MotorIndex] ==  DCMOTOR_u8_ANTICLOCKWISE)
			{
				/* set the motor off  for 500 ms                   */
				Local_u8Error = DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Copy_u8MotorIndex][0], !DCMOTOR_Au8MotorActiveType[Copy_u8MotorIndex]);
				Local_u8Error = DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Copy_u8MotorIndex][1], !DCMOTOR_Au8MotorActiveType[Copy_u8MotorIndex]);
				delay_milliSecond(500);
			}
			/* Rotate it in the clockwise direction                */
			Local_u8Error = DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Copy_u8MotorIndex][0], DCMOTOR_Au8MotorActiveType[Copy_u8MotorIndex]);
			Local_u8Error = DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Copy_u8MotorIndex][1], !DCMOTOR_Au8MotorActiveType[Copy_u8MotorIndex]);
			/* set the array direction with clockwise direction    */
			Local_Au8MotorsSetDirection[Copy_u8MotorIndex] = DCMOTOR_u8_CLOCKWISE;
		}
	}
	/* Function Return */
	return Local_u8Error;
}


/****************************************************************************************
 * Description: Function to set motor's direction of rotation to Anti-clockwise direction
 * Outputs    : Error state
 * Inputs     : u8 Copy_u8MotorIndex : index of the motor
 ****************************************************************************************/
u8 DCMOTOR_u8MotorRotateAntiClockWise(u8 Copy_u8MotorIndex)
{
	/* Local Variable indication for Error status                 */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                                 */
	if (Copy_u8MotorIndex >= DCMOTOR_u8_NO_MOTORS)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* If the motor state is on                               */
		if (Local_Au8MotorsONFlag[Copy_u8MotorIndex] == 1)
		{
			/* if it is rotates in the clockwise direction         */
			if (Local_Au8MotorsSetDirection[Copy_u8MotorIndex] ==  DCMOTOR_u8_CLOCKWISE)
			{
				/* set the motor off  for 500 ms                   */
				Local_u8Error = DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Copy_u8MotorIndex][0], !DCMOTOR_Au8MotorActiveType[Copy_u8MotorIndex]);
				Local_u8Error = DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Copy_u8MotorIndex][1], !DCMOTOR_Au8MotorActiveType[Copy_u8MotorIndex]);
				delay_milliSecond(500);
			}
			/* Rotate it in the Anti clockwise direction            */
			Local_u8Error = DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Copy_u8MotorIndex][0], !DCMOTOR_Au8MotorActiveType[Copy_u8MotorIndex]);
			Local_u8Error = DIO_u8SetPinValue (DCMOTOR_Au8MotorPins[Copy_u8MotorIndex][1], DCMOTOR_Au8MotorActiveType[Copy_u8MotorIndex]);
			/* set the array direction with anti clockwise direction*/
			Local_Au8MotorsSetDirection[Copy_u8MotorIndex] = DCMOTOR_u8_ANTICLOCKWISE;
		}
	}
	/* Function Return */
	return Local_u8Error;
}


