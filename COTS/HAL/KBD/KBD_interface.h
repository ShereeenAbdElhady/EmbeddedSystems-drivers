/***************************************************************************************/
/*                                                                                    */
/* File Name   : KBD_interface.h                                                     */
/*                                                                                  */
/* Created on  : Feb 12, 2019                                                      */
/*                                                                                */
/* Author      : shereen Abd Elhady                                              */
/*                                                                              */
/* Version     : V01                                                           */
/*                                                                            */
/* Description : interface file for MATRIX KeyPad driver                     */
/*               includes APIs' prototypes and MACROS for call              */
/*                                                                         */
/* Layer       : HAL                                                      */
/*************************************************************************/


#ifndef KBD_INTERFACE_H_
#define KBD_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "KBD_config.h"

/* Mapping the Keypad PIN numbers with DIO driver PIN numbers */
#define KBD_u8_PIN0   DIO_u8_PIN0
#define KBD_u8_PIN1   DIO_u8_PIN1
#define KBD_u8_PIN2   DIO_u8_PIN2
#define KBD_u8_PIN3   DIO_u8_PIN3
#define KBD_u8_PIN4   DIO_u8_PIN4
#define KBD_u8_PIN5   DIO_u8_PIN5
#define KBD_u8_PIN6   DIO_u8_PIN6
#define KBD_u8_PIN7   DIO_u8_PIN7
#define KBD_u8_PIN8   DIO_u8_PIN8
#define KBD_u8_PIN9   DIO_u8_PIN9
#define KBD_u8_PIN10  DIO_u8_PIN10
#define KBD_u8_PIN11  DIO_u8_PIN11
#define KBD_u8_PIN12  DIO_u8_PIN12
#define KBD_u8_PIN13  DIO_u8_PIN13
#define KBD_u8_PIN14  DIO_u8_PIN14
#define KBD_u8_PIN15  DIO_u8_PIN15
#define KBD_u8_PIN16  DIO_u8_PIN16
#define KBD_u8_PIN17  DIO_u8_PIN17
#define KBD_u8_PIN18  DIO_u8_PIN18
#define KBD_u8_PIN19  DIO_u8_PIN19
#define KBD_u8_PIN20  DIO_u8_PIN20
#define KBD_u8_PIN21  DIO_u8_PIN21
#define KBD_u8_PIN22  DIO_u8_PIN22
#define KBD_u8_PIN23  DIO_u8_PIN23
#define KBD_u8_PIN24  DIO_u8_PIN24
#define KBD_u8_PIN25  DIO_u8_PIN25
#define KBD_u8_PIN26  DIO_u8_PIN26
#define KBD_u8_PIN27  DIO_u8_PIN27
#define KBD_u8_PIN28  DIO_u8_PIN28
#define KBD_u8_PIN29  DIO_u8_PIN29
#define KBD_u8_PIN30  DIO_u8_PIN30
#define KBD_u8_PIN31  DIO_u8_PIN31
#define KBD_u8_PIN32  DIO_u8_PIN32
#define KBD_u8_PIN33  DIO_u8_PIN33
#define KBD_u8_PIN34  DIO_u8_PIN34
#define KBD_u8_PIN35  DIO_u8_PIN35
#define KBD_u8_PIN36  DIO_u8_PIN36


                        /************* APIs Prototypes ***************/
/******************************************************************************************
 * Description: Function to get the pressed key state whether it is pressed or released
 *              and save this state in the passed 2D array to the function.
 * Outputs    : Error State
 * Inputs     : u8 (*Copy_Pu8Arr)[KBD_u8_NUMBER_OF_COLS]: pointer to 2D array of integers
 *              receive the address of this array from the caller function and begin
 *              to access these addresses and save the pressed key state in it.
 *
 ******************************************************************************************/
u8 KBD_u8GetPressedKeyState(u8 (*Copy_Pu8Arr)[KBD_u8_NUMBER_OF_COLS]);

#endif /* KBD_INTERFACE_H_ */
