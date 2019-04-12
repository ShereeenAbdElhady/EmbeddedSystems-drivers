/**************************************************************************************/
/*                                                                                   */
/* File Name   : KBD_private.h                                                      */
/*                                                                                 */
/* Created on  : Feb 12, 2019                                                     */
/*                                                                               */
/* Author      : shereen Abd Elhady                                             */
/*                                                                             */
/* Version     : V01                                                          */
/* Description : private header file for MATRIX KeyPad driver                */
/*               includes private functions prototypes                      */
/*               And private MACROS used by the programmer.                */
/*                                                                        */
/* Layer       : HAL                                                     */
/************************************************************************/



#ifndef KBD_PRIVATE_H_
#define KBD_PRIVATE_H_

/* 	The Private file includes only the Private configurations from the configuration file */
#include "KBD_config.h"

/* Keypad type of connection definitions     */
#define PULL_UP_CONNECTION    (u8)1
#define PULL_DOWN_CONNECTION  (u8)0

/* Keypad activation techniques definition   */
#define KBD_u8_ACTIVE_ROW     (u8)1
#define KBD_u8_ACTIVE_COL     (u8)0

/* Keypad PINs values definitions            */
#define KBD_u8_HIGH   (u8)1
#define KBD_u8_LOW    (u8)0


#endif /* KBD_PRIVATE_H_ */
