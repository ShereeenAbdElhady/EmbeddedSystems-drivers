/**********************************************************************************************/
/*                                                                                           */
/* File Name   : LED_interface.h                                                            */
/*                                                                                         */
/* Created on  : Jan 29, 2019                                                             */
/*                                                                                       */
/* Author      : shereen Abd Elhady                                                     */
/*                                                                                     */
/* Version     : V01                                                                  */
/*                                                                                   */
/* Description : interface file for LED driver includes APIs' prototypes            */
/*                                                                                 */
/* Layer       : HAL                                                              */
/*********************************************************************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "LED_config.h"


    /*********************************** Preprocessor MACROS ************************************/
/* LED types' definition             */
#define LED_u8_FORWARD  (u8)1
#define LED_u8_REVERSE  (u8)0

/* The user use these macros to set the value of any connected LED whether it's gonna have high or low value */
#define LED_u8_HIGH   (u8)1
#define LED_u8_LOW    (u8)0

/* The user use these macros to map the connected LED PINs with DIO driver for setting LED PIN direction   */
#define LED_u8_OUTPUT   DIO_u8_PIN_OUTPUT
#define LED_u8_INPUT    DIO_u8_PIN_INPUT



       /*********************************** LED Driver APIs Prototypes ************************************/

/****************************************************
 * Description: Function to Set LED ON
 * Outputs   : Error State
 * Inputs    : Copy_u8ledIndex:     LED array index
 *****************************************************/
u8 LED_u8LEDON(u8 Copy_u8ledIndex)  ;

/****************************************************
 * Description: Function to Set LED OFF
 * Outputs   : Error State
 * Inputs    : Copy_u8ledIndex:     LED array index
 *****************************************************/
u8 LED_u8LEDOFF(u8 Copy_u8ledIndex) ;

/****************************************************
 * Description: Function to initialize LED Direction
 * Outputs   : Error State
 * Inputs    : Copy_u8ledIndex:     LED array index
 *****************************************************/
u8 LED_u8init(u8 Copy_u8ledIndex)   ;

#endif /* LED_INTERFACE_H_ */
