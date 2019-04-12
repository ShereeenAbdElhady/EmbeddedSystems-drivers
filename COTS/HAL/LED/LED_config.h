/**********************************************************************************************/
/*                                                                                           */
/* File Name   : LED_config.h                                                               */
/*                                                                                         */
/* Created on  : Jan 29, 2019                                                             */
/*                                                                                       */
/* Author      : shereen Abd Elhady                                                     */
/*                                                                                     */
/* Version     : V01                                                                  */
/*                                                                                   */
/* Description : configuration file for LED driver contains the                     */
/*               LEDs connected PINs mapped with micro-controller pins             */
/*               through the DIO driver                                           */
/*                                                                               */
/* Layer       : HAL                                                            */
/*******************************************************************************/


            /**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef LED_PUBLIC_CONFIG_H_
#ifdef  LED_INTERFACE_H_
#define LED_PUBLIC_CONFIG_H_

/* Mapping the LEDs Index with an Array in the configuration file for setting LED PIN number              */
#define LED_u8_CONNECT_INDEX0  (u8)0
#define LED_u8_CONNECT_INDEX1  (u8)1
#define LED_u8_CONNECT_INDEX2  (u8)2
#define LED_u8_CONNECT_INDEX3  (u8)3
#define LED_u8_CONNECT_INDEX4  (u8)4
#define LED_u8_CONNECT_INDEX5  (u8)5
#define LED_u8_CONNECT_INDEX6  (u8)6
#define LED_u8_CONNECT_INDEX7  (u8)7
#define LED_u8_CONNECT_INDEX8  (u8)8
#define LED_u8_CONNECT_INDEX9  (u8)9
#define LED_u8_CONNECT_INDEX10 (u8)10
#define LED_u8_CONNECT_INDEX11 (u8)11
#define LED_u8_CONNECT_INDEX12 (u8)12
#define LED_u8_CONNECT_INDEX13 (u8)13
#define LED_u8_CONNECT_INDEX14 (u8)14
#define LED_u8_CONNECT_INDEX15 (u8)15
#define LED_u8_CONNECT_INDEX16 (u8)16
#define LED_u8_CONNECT_INDEX17 (u8)17
#define LED_u8_CONNECT_INDEX18 (u8)18
#define LED_u8_CONNECT_INDEX19 (u8)19
#define LED_u8_CONNECT_INDEX20 (u8)20
#define LED_u8_CONNECT_INDEX21 (u8)21
#define LED_u8_CONNECT_INDEX22 (u8)22
#define LED_u8_CONNECT_INDEX23 (u8)23
#define LED_u8_CONNECT_INDEX24 (u8)24
#define LED_u8_CONNECT_INDEX25 (u8)25
#define LED_u8_CONNECT_INDEX26 (u8)26
#define LED_u8_CONNECT_INDEX27 (u8)27
#define LED_u8_CONNECT_INDEX28 (u8)28
#define LED_u8_CONNECT_INDEX29 (u8)29
#define LED_u8_CONNECT_INDEX30 (u8)30
#define LED_u8_CONNECT_INDEX31 (u8)31


#endif     /* LED_INTERFACE_H_ */
#endif     /* LED_PUBLIC_CONFIG_H_ */



          /**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef LED_PRIVATEC_CONFIG_H_
#ifdef  LED_PRIVATE_H_
#define LED_PRIVATE_CONFIG_H_

/* LED numbers' configuration        */
#define LED_u8_NUM_OF_LEDS    8


/* The customer configures the connected LEDs with DIO PINs driver for setting LED PIN number             */
u8 LED_Au8ledch[LED_u8_NUM_OF_LEDS] =
{
		DIO_u8_PIN0,
		DIO_u8_PIN1,
		DIO_u8_PIN11,
		DIO_u8_PIN8,
		DIO_u8_PIN7,
		DIO_u8_PIN5,
		DIO_u8_PIN4,
		DIO_u8_PIN3
};

/* The customer configures the LEDs' type of connection whether it's gonna be forward or reverse connection*/
/* Range : LED_u8_REVERSE                */
/*         LED_u8_FORWARD               */
u8 LED_Au8ledType[LED_u8_NUM_OF_LEDS] =
{
		LED_u8_FORWARD,
		LED_u8_FORWARD,
		LED_u8_FORWARD,
		LED_u8_FORWARD,
		LED_u8_REVERSE,
		LED_u8_REVERSE,
		LED_u8_REVERSE,
		LED_u8_REVERSE
};

#endif    /* LED_PRIVATE_H_ */
#endif   /* LED_PRIVATE_CONFIG_H_ */



