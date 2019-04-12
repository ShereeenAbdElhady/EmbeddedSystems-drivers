/**********************************************************************************************/
/*                                                                                           */
/* File Name   : DCMOTOR_config.h                                                           */
/*                                                                                         */
/* Created on  : Mar 19, 2019                                                             */
/*                                                                                       */
/* Author      : shereen Abd Elhady                                                     */
/*                                                                                     */
/* Version     : V02                                                                  */
/*                                                                                   */
/* Description : configuration file for DC motor driver contains                    */
/*               the initial conditions for the DC Motor like direction,           */
/*               Activation type and the motor initial state                      */
/*               which initiates the DC Motor according to the customer desire   */
/*               For STM32F103C8 ARM Microcontroller.                           */
/*                                                                             */
/* Layer       : HAL                                                          */
/*****************************************************************************/


/**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef DCMOTOR_PUBLIC_CONFIG_H_
#ifdef  DCMOTOR_PRIVATE_H_
#define DCMOTOR_PUBLIC_CONFIG_H_



#endif     /* DC_MOTOR_INTERFACE_H_ */
#endif     /* DC_MOTOR_PUBLIC_CONFIG_H_ */

/**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef DCMOTOR_PRIVATE_CONFIG_H_
#ifdef  DCMOTOR_PRIVATE_H_
#define DCMOTOR_PRIVATE_CONFIG_H_

/* the Customer will configure the number of motors according to his desire          */
#define DCMOTOR_u8_NO_MOTORS     (u8)1

/* The Customer will configure the motor's PINs' connections according to his desire */
/* Range : DCMOTOR_u8_PIN0     DCMOTOR_u8_PIN18
           DCMOTOR_u8_PIN1     DCMOTOR_u8_PIN19
           DCMOTOR_u8_PIN2     DCMOTOR_u8_PIN20
           DCMOTOR_u8_PIN3     DCMOTOR_u8_PIN21
           DCMOTOR_u8_PIN4     DCMOTOR_u8_PIN22
           DCMOTOR_u8_PIN5     DCMOTOR_u8_PIN23
           DCMOTOR_u8_PIN6     DCMOTOR_u8_PIN24
           DCMOTOR_u8_PIN7     DCMOTOR_u8_PIN25
           DCMOTOR_u8_PIN8     DCMOTOR_u8_PIN26
           DCMOTOR_u8_PIN9     DCMOTOR_u8_PIN27
           DCMOTOR_u8_PIN10    DCMOTOR_u8_PIN28
           DCMOTOR_u8_PIN11    DCMOTOR_u8_PIN29
           DCMOTOR_u8_PIN12    DCMOTOR_u8_PIN30
           DCMOTOR_u8_PIN13    DCMOTOR_u8_PIN31
           DCMOTOR_u8_PIN14    DCMOTOR_u8_PIN32
           DCMOTOR_u8_PIN15    DCMOTOR_u8_PIN33
           DCMOTOR_u8_PIN16    DCMOTOR_u8_PIN34
           DCMOTOR_u8_PIN17    DCMOTOR_u8_PIN35
                               DCMOTOR_u8_PIN36                                       */
/* The clockwise direction will put high on first pin 				                  */
/* and low on the second pin in case of active high                                   */
u8 DCMOTOR_Au8MotorPins[DCMOTOR_u8_NO_MOTORS][DCMOTOR_u8_NO_PINS] = {DCMOTOR_u8_PIN0 , DCMOTOR_u8_PIN1};

/* The customer will configure activation type according to his desire                */
/* Range : DCMOTOR_u8_ACTIVE_HIGH                                                     */
/*         DCMOTOR_u8_ACTIVE_LOW                                                      */
/*                                                                                    */
u8 DCMOTOR_Au8MotorActiveType[DCMOTOR_u8_NO_MOTORS]    = {DCMOTOR_u8_ACTIVE_HIGH};


/* The customer will configure rotation direction according to his desire             */
/* Range : DCMOTOR_u8_CLOCKWISE                                                       */
/*         DCMOTOR_u8_ANTICLOCKWISE                                                   */
/*                                                                                    */
u8 DCMOTOR_Au8MotorInitDirection[DCMOTOR_u8_NO_MOTORS] = {DCMOTOR_u8_CLOCKWISE};


/* The customer will configure the motor initial state according to his desire        */
/* Range : DCMOTOR_u8_STATE_ON                                                        */
/*         DCMOTOR_u8_STATE_OFF                                                       */
/*                                                                                    */
u8 DCMOTOR_Au8MotorInitState[DCMOTOR_u8_NO_MOTORS]     = { DCMOTOR_u8_STATE_OFF};



#endif    /* DC_MOTOR_PRIVATE_H_ */
#endif   /* DC_MOTOR_PRIVATE_CONFIG_H_ */
