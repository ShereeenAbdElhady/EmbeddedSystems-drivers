/*****************************************************************************************************/
/*                                                                                                  */
/* File Name   : DCMOTOR_private.h                                                                 */
/*                                                                                                */
/* Created on  : Mar 19, 2019                                                                    */
/*                                                                                              */
/* Author      : shereen Abd Elhady                                                            */
/*                                                                                            */
/* Version     : V01                                                                         */
/*                                                                                          */
/* Description : Private header file for DC Motor driver                                   */
/*               of STM32F103C8 ARM Micro-Controller.                                     */
/*               Also contains private functions' prototypes                             */
/*               And the MACROS not needed by the upper layers' components.             */
/* Layer        : HAL                                                                  */
/*                                                                                    */
/*************************************************************************************/

#ifndef DCMOTOR_PRIVATE_H_
#define DCMOTOR_PRIVATE_H_



/* definition to number of motor pins                   */
#define DCMOTOR_u8_NO_PINS        (u8)2

/* Activation type definitions                          */
#define DCMOTOR_u8_ACTIVE_HIGH    (u8)1
#define DCMOTOR_u8_ACTIVE_LOW     (u8)0

/* Direction of rotation definitions                    */
#define DCMOTOR_u8_CLOCKWISE      (u8)7
#define DCMOTOR_u8_ANTICLOCKWISE  (u8)8

/* Motor state definitions                              */
#define DCMOTOR_u8_STATE_ON       (u8)12
#define DCMOTOR_u8_STATE_OFF      (u8)13

/* 	The Private file includes only the Private configurations from the configuration file */
#include "DCMOTOR_config.h"

#endif /* DC_MOTOR_PRIVATE_H_ */
