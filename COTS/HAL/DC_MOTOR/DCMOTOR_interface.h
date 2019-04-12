/***********************************************************************************/
/*                                                                                */
/* File Name   : DCMOTOR_interface.h                                             */
/*                                                                              */
/* Created on  : Mar 19, 2019                                                  */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V01                                                       */
/*                                                                        */
/* Description : Interface file for DC MOTOR includes APIs' prototypes   */
/*                                                                      */
/*             And MACROS for call  for STM32F103C8 ARM microcontroller*/
/*                                                                    */
/* Layer       : HAL                                                 */
/*                                                                  */
/*******************************************************************/


#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "DCMOTOR_config.h"


/* Motor's PINs definitions                                                 */

#define DCMOTOR_u8_PIN0   DIO_u8_PIN0
#define DCMOTOR_u8_PIN1   DIO_u8_PIN1
#define DCMOTOR_u8_PIN2   DIO_u8_PIN2
#define DCMOTOR_u8_PIN3   DIO_u8_PIN3
#define DCMOTOR_u8_PIN4   DIO_u8_PIN4
#define DCMOTOR_u8_PIN5   DIO_u8_PIN5
#define DCMOTOR_u8_PIN6   DIO_u8_PIN6
#define DCMOTOR_u8_PIN7   DIO_u8_PIN7
#define DCMOTOR_u8_PIN8   DIO_u8_PIN8
#define DCMOTOR_u8_PIN9   DIO_u8_PIN9
#define DCMOTOR_u8_PIN10  DIO_u8_PIN10
#define DCMOTOR_u8_PIN11  DIO_u8_PIN11
#define DCMOTOR_u8_PIN12  DIO_u8_PIN12
#define DCMOTOR_u8_PIN13  DIO_u8_PIN13
#define DCMOTOR_u8_PIN14  DIO_u8_PIN14
#define DCMOTOR_u8_PIN15  DIO_u8_PIN15
#define DCMOTOR_u8_PIN16  DIO_u8_PIN16
#define DCMOTOR_u8_PIN17  DIO_u8_PIN17
#define DCMOTOR_u8_PIN18  DIO_u8_PIN18
#define DCMOTOR_u8_PIN19  DIO_u8_PIN19
#define DCMOTOR_u8_PIN20  DIO_u8_PIN20
#define DCMOTOR_u8_PIN21  DIO_u8_PIN21
#define DCMOTOR_u8_PIN22  DIO_u8_PIN22
#define DCMOTOR_u8_PIN23  DIO_u8_PIN23
#define DCMOTOR_u8_PIN24  DIO_u8_PIN24
#define DCMOTOR_u8_PIN25  DIO_u8_PIN25
#define DCMOTOR_u8_PIN26  DIO_u8_PIN26
#define DCMOTOR_u8_PIN27  DIO_u8_PIN27
#define DCMOTOR_u8_PIN28  DIO_u8_PIN28
#define DCMOTOR_u8_PIN29  DIO_u8_PIN29
#define DCMOTOR_u8_PIN30  DIO_u8_PIN30
#define DCMOTOR_u8_PIN31  DIO_u8_PIN31
#define DCMOTOR_u8_PIN32  DIO_u8_PIN32
#define DCMOTOR_u8_PIN33  DIO_u8_PIN33
#define DCMOTOR_u8_PIN34  DIO_u8_PIN34
#define DCMOTOR_u8_PIN35  DIO_u8_PIN35
#define DCMOTOR_u8_PIN36  DIO_u8_PIN36


/*********************************** APIs Prototypes ************************************/

/**********************************************************************************
 * Description: Function to initialize motor's direction of rotation
 *              Also initialize the motor's state whether it is ON or OFF.
 * Outputs    : None
 * Inputs     : None
 **********************************************************************************/
void DCMOTOR_vidInitialize(void);


/***********************************************************************************
 * Description: Function to set motor's state to ON state
 * Outputs    : Error state
 * Inputs     : u8 Copy_u8MotorIndex : index of the motor
 ***********************************************************************************/
u8 DCMOTOR_u8MotorON(u8 Copy_u8MotorIndex);


/************************************************************************************
 * Description: Function to set motor's state to OFF state
 * Outputs    : Error state
 * Inputs     : u8 Copy_u8MotorIndex : index of the motor
 *************************************************************************************/
u8 DCMOTOR_u8MotorOFF(u8 Copy_u8MotorIndex);


/**************************************************************************************
 * Description: Function to set motor's direction of rotation to clockwise direction
 * Outputs    : Error state
 * Inputs     : u8 Copy_u8MotorIndex : index of the motor
 **************************************************************************************/
u8 DCMOTOR_u8MotorRotateClockWise(u8 Copy_u8MotorIndex);


/****************************************************************************************
 * Description: Function to set motor's direction of rotation to Anti-clockwise direction
 * Outputs    : Error state
 * Inputs     : u8 Copy_u8MotorIndex : index of the motor
 ****************************************************************************************/
u8 DCMOTOR_u8MotorRotateAntiClockWise(u8 Copy_u8MotorIndex);

#endif /* DC_MOTOR_INTERFACE_H_ */
