/***************************************************************************************/
/*                                                                                    */
/* File Name   : SWI_interface.h                                                     */
/*                                                                                  */
/* Created on  : Feb 7, 2019                                                       */
/*                                                                                */
/* Author      : shereen Abd Elhady                                              */
/*                                                                              */
/* Version     : V01                                                           */
/*                                                                            */
/* Description : interface file for SWITCH driver                            */
/*               includes APIs' prototypes and MACROS for call              */
/*                                                                         */
/* Layer       : HAL                                                      */
/*************************************************************************/


#ifndef SWI_INTERFACE_H_
#define SWI_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "SWI_config.h"

/* MACROS definitions for switch state */
#define SWI_u8_PRESSED    (u8)1
#define SWI_u8_RELEASED   (u8)0

#define SWI_u8_HIGH       (u8)1
#define SWI_u8_LOW        (u8)0

/* Mapping the SWITCH Index with an Array in the configuration file for setting SWITCH PIN number  */
#define SWI_u8_CONNECT_0  (u8)0
#define SWI_u8_CONNECT_1  (u8)1
#define SWI_u8_CONNECT_2  (u8)2
#define SWI_u8_CONNECT_3  (u8)3
#define SWI_u8_CONNECT_4  (u8)4
#define SWI_u8_CONNECT_5  (u8)5
#define SWI_u8_CONNECT_6  (u8)6
#define SWI_u8_CONNECT_7  (u8)7
#define SWI_u8_CONNECT_8  (u8)8


/******************************************************************************************
 * Description: Function to get the pressed switch state whether it is pressed or released
 *              and save this state in the passed variable to the function.
 * Outputs    : Error State
 * Inputs     : u8 *Copy_Pu8Value: pointer to variable
 *              receive the address of this variable from the caller function and begin
 *              to access this address and save the pressed key state in it.
 *              Copy_u8SwIndex   : switch index
 ******************************************************************************************/
u8 SWI_u8GetSwiState(u8* Copy_Pu8Value,u8 Copy_u8SwIndex);


#endif /* SWI_INTERFACE_H_ */
