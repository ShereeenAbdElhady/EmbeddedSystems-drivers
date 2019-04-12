/********************************************************************************************/
/*                                                                                         */
/* File Name   : KBD_config.h                                                             */
/*                                                                                       */
/* Created on  : Feb 12, 2019                                                           */
/*                                                                                     */
/* Author      : shereen  Abd Elhady                                                  */
/*                                                                                   */
/* Version     : V01                                                                */
/*                                                                                 */
/* Description : Basic Public and Private configurations for MATRIX KeyPad driver */
/*               defines it's type of activation , connections                   */
/*               The number of ROWs and COLs and connected to which PINs        */
/*               according to the user desire.                                 */
/*                                                                            */
/* Layer       : HAL                                                         */
/****************************************************************************/


            /**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef KBD_PUBLIC_CONFIG_H_
#ifdef  KBD_INTERFACE_H_
#define KBD_PUBLIC_CONFIG_H_

/* Macros definitions for keypad switch state */
#define KBD_u8_PRESSED   (u8)0
#define KBD_u8_RELEASED  (u8)1


/* The customer configures the number of columns and rows          */
/* according to his keypad type                                    */
/* Range: Keypad 4x4
 *        Keypad 3x3
 *        Keypad 4x3 and so on.......
 */
#define KBD_u8_NUMBER_OF_COLS   (u8)3
#define KBD_u8_NUMBER_OF_ROWS   (u8)3




#endif     /* KBD_INTERFACE_H_ */
#endif     /* KBD_PUBLIC_CONFIG_H_ */


           /**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef KBD_PRIVATEC_CONFIG_H_
#ifdef  KBD_PRIVATE_H_
#define KBD_PRIVATE_CONFIG_H_


/* The customer configures the keypad switches' type of connection */
/* whether it' s gonna be PULL UP or PULL DOWN connection          */
/* Range: PULL_UP_CONNECTION
 *        PULL_DOWN_CONNECTION
 */
#define KBD_u8_TYPE_OF_CONNECTION    PULL_UP_CONNECTION


/* The customer configures the keypad switches' type of activation */
/* whether it' s gonna be active row or active column              */
/* Range: KBD_u8_ACTIVE_COL
 *        KBD_u8_ACTIVE_ROW
 */
#define KBD_u8_TYPE_OF_ACTIVATION   KBD_u8_ACTIVE_COL


/* Keypad configurations to define it's PINs connections            */
/* The customer configures the KBD PINs connection                  */
/* Range : From KBD_u8_PIN0                                         */
/*         To KBD_u8_PIN31                                          */

// A11 , C14 , C15
u8 KBD_Au8KBDConnectColPins[KBD_u8_NUMBER_OF_COLS] =
{KBD_u8_PIN11 , KBD_u8_PIN33 , KBD_u8_PIN34};

// A8 , A9 , A10
u8 KBD_Au8KBDConnectRowPins[KBD_u8_NUMBER_OF_ROWS] =
{KBD_u8_PIN8 , KBD_u8_PIN9 , KBD_u8_PIN10};


#endif    /* KBD_PRIVATE_H_ */
#endif   /* KBD_PRIVATE_CONFIG_H_ */
