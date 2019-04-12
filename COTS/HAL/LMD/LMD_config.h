/****************************************************************************************/
/*                                                                                     */
/* File Name   : LMD_config.h                                                         */
/*                                                                                   */
/* Created on  : Mar 7, 2019                                                        */
/*                                                                                 */
/* Author      : shereen  Abd Elhady                                              */
/*                                                                               */
/* Version     : V01                                                            */
/*                                                                             */
/* Description : Basic configurations for LED matrix display driver           */
/*               defines it's type and connected to which PORTS              */
/*               according to the user desire.                              */
/*                                                                         */
/* Layer       : HAL                                                      */
/*************************************************************************/

            /**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef LMD_PUBLIC_CONFIG_H_
#ifdef  LMD_INTERFACE_H_
#define LMD_PUBLIC_CONFIG_H_


/* Colors definitions                          */
#define LMD_u8_COLOR_RED       (u8)1
#define LMD_u8_COLOR_GREEN     (u8)0

/* The customer configures the numbers of rows & the number of columns                           */
#define LMD_u8_NUMBER_LEDS      (u8)8

#endif     /* LMD_INTERFACE_H_ */
#endif     /* LMD_PUBLIC_CONFIG_H_ */


           /**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef LMD_PRIVATEC_CONFIG_H_
#ifdef  LMD_PRIVATE_H_
#define LMD_PRIVATE_CONFIG_H_


/* The customer configures the activation technique whether it's gonna be active row or active column */
/* Range : LMD_u8_ACTIVE_ROW               */
/*         LMD_u8_ACTIVE_COL               */
#define LMD_u8_TYPE          LMD_u8_ACTIVE_ROW

/* The customer configures the activation types whether it's gonna be active high or active low     */
/* Range : LMD_u8_ACTIVE_HIGH               */
/*         LMD_u8_ACTIVE_LOW                */
#define LMD_u8_ACTIVE_TYPE   LMD_u8_ACTIVE_HIGH

/* The customer configures PORTB as an activation PORT  according to his desire                  */
#define LMD_u8_ACTIVE_PORT   DIO_u8_PORT1
/* The customer configures PORTC as a Green PORT  according to his desire                        */
#define LMD_u8_GREEN_PORT    DIO_u8_PORT3
/* The customer configures PORTA as a red PORT  according to his desire                          */
#define LMD_u8_RED_PORT      DIO_u8_PORT0

/* LMD configurations to define it's PINs connections               */
/* The customer configures the LMD PINs connection                  */
/* Range : From DIO_u8_PIN0                                         */
/*         To DIO_u8_PIN36                                          */


// B8 ,B9 , B10 , B11 , B12 , B14 , B15 , C13
u8 LMD_Au8LMDDConnectRowPins[LMD_u8_NUMBER_LEDS] =
{ DIO_u8_PIN24 ,DIO_u8_PIN25 , DIO_u8_PIN26 , DIO_u8_PIN27 , DIO_u8_PIN28  , DIO_u8_PIN30 , DIO_u8_PIN31 , DIO_u8_PIN32 };



u8 LMD_Au8LMDDConnectColPins[LMD_u8_NUMBER_LEDS] =
{ DIO_u8_PIN7 ,DIO_u8_PIN6 , DIO_u8_PIN5 , DIO_u8_PIN4 , DIO_u8_PIN3  , DIO_u8_PIN2 , DIO_u8_PIN1 , DIO_u8_PIN0 };



#endif    /* LMD_PRIVATE_H_ */
#endif   /* LMD_PRIVATE_CONFIG_H_ */
