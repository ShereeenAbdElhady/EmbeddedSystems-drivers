/***********************************************************************************/
/*                                                                                */
/* File Name   : DIO_interface.h                                                 */
/*                                                                              */
/* Created on  : Feb 27, 2019                                                  */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V02                                                       */
/*                                                                        */
/* Description : Interface file for DIO driver includes APIs' prototypes */
/*                                                                      */
/*             And MACROS for call  for STM32F103C8 ARM microcontroller*/
/*                                                                    */
/* Layer       : MCAL                                                */
/*                                                                  */
/*******************************************************************/

/* Preprocessor Guard                                                                      */
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "DIO_config.h"

/*************** Micro-Controller PINs definitions****************/
/* 37 PINs                                                                                 */
/* A0 ->  A15 (PORTA)                                                                      */
/* B16 -> B31 (PORTB)                                                                      */
/* C13 , C14 , C15 (PORTC)                                                                 */
/* D0 -> D1 (PORTD)                                                                        */
#define DIO_u8_PIN0    (u8)0
#define DIO_u8_PIN1    (u8)1
#define DIO_u8_PIN2    (u8)2
#define DIO_u8_PIN3    (u8)3
#define DIO_u8_PIN4    (u8)4
#define DIO_u8_PIN5    (u8)5
#define DIO_u8_PIN6    (u8)6
#define DIO_u8_PIN7    (u8)7
#define DIO_u8_PIN8    (u8)8
#define DIO_u8_PIN9    (u8)9
#define DIO_u8_PIN10   (u8)10
#define DIO_u8_PIN11   (u8)11
#define DIO_u8_PIN12   (u8)12
#define DIO_u8_PIN13   (u8)13
#define DIO_u8_PIN14   (u8)14
#define DIO_u8_PIN15   (u8)15
#define DIO_u8_PIN16   (u8)16
#define DIO_u8_PIN17   (u8)17
#define DIO_u8_PIN18   (u8)18
#define DIO_u8_PIN19   (u8)19
#define DIO_u8_PIN20   (u8)20
#define DIO_u8_PIN21   (u8)21
#define DIO_u8_PIN22   (u8)22
#define DIO_u8_PIN23   (u8)23
#define DIO_u8_PIN24   (u8)24
#define DIO_u8_PIN25   (u8)25
#define DIO_u8_PIN26   (u8)26
#define DIO_u8_PIN27   (u8)27
#define DIO_u8_PIN28   (u8)28
#define DIO_u8_PIN29   (u8)29
#define DIO_u8_PIN30   (u8)30
#define DIO_u8_PIN31   (u8)31
#define DIO_u8_PIN32   (u8)45
#define DIO_u8_PIN33   (u8)46
#define DIO_u8_PIN34   (u8)47
#define DIO_u8_PIN35   (u8)48
#define DIO_u8_PIN36   (u8)49


/************** Ports definitions for mapping**************/
/* Definition for PORTA (I/P & O/P) (SINK & SOURCE) means O/P could be 0 or 1                             */
#define DIO_u8_PORT0     (u8)0
/* Definition for PORTB (I/P & O/P) (SINK & SOURCE) means O/P could be 0 or 1                             */
#define DIO_u8_PORT1     (u8)1
/* Definition for PORTC (I/P & O/P) (SINK)   means O/P could be 0 only                                    */
#define DIO_u8_PORT2     (u8)2
/* Definition for PORTD (I/P & O/P) (SINK)   means O/P could be 0 only                                    */
#define DIO_u8_PORT3     (u8)3


                 /***********************PINs Values*************************/
/* The user use these macros to set the value of any output PIN whether it's gonna have high or low value */
#define DIO_u8_PIN_HIGH   (u8)1
#define DIO_u8_PIN_LOW    (u8)0

                 /***********************PORTs Values*************************/
/* The user use these macros to set the value of any output PORT whether it's gonna have high or low value */
/* Each Register is 32 BITs which means 8 Digits Hexadecimal                                               */
#define DIO_u32_PORT_HIGH   (u32)0xFFFFFFFF
#define DIO_u32_PORT_LOW    (u32)0X00000000


               /***************I/Ps and O/Ps PINs Modes Definitions**********/
/*15 Modes (3 Modes for I/P and 12 Modes for O/P)                                                         */

/****** I/P PINs Modes ******/
/* Pull Up and Pull Down have the the same Mode value and we could'nt define 2 different Macros          */
/*the same value so we give the Pull Up the actual mode value and gives the Pull Down a reserved value   */
#define DIO_u8_PIN_INPUT_ANALOG                 0b0000
#define DIO_u8_PIN_INPUT_FLOATING               0b0100
#define DIO_u8_PIN_INPUT_PULL_UP                0b1000
#define DIO_u8_PIN_INPUT_PULL_DOWN              0b1100

/****** O/P PINs Modes with 10MHZ Freq ******/
#define DIO_u8_PIN_OUTPUT_10MHZ_PUSH_PULL       0b0001
#define DIO_u8_PIN_OUTPUT_10MHZ_OPEN_DRAIN      0b0101
#define DIO_u8_PIN_OUTPUT_10MHZ_AF_PUSH_PULL    0b1001
#define DIO_u8_PIN_OUTPUT_10MHZ_AF_OPEN_DRAIN   0b1101

/****** O/P PINs Modes with 2MHZ Freq ******/
#define DIO_u8_PIN_OUTPUT_2MHZ_PUSH_PULL        0b0010
#define DIO_u8_PIN_OUTPUT_2MHZ_OPEN_DRAIN       0b0110
#define DIO_u8_PIN_OUTPUT_2MHZ_AF_PUSH_PULL     0b1010
#define DIO_u8_PIN_OUTPUT_2MHZ_AF_OPEN_DRAIN    0b1110

/****** O/P PINs Modes with 50MHZ Freq ******/
#define DIO_u8_PIN_OUTPUT_50MHZ_PUSH_PULL        0b0011
#define DIO_u8_PIN_OUTPUT_50MHZ_OPEN_DRAIN       0b0111
#define DIO_u8_PIN_OUTPUT_50MHZ_AF_PUSH_PULL     0b1011
#define DIO_u8_PIN_OUTPUT_50MHZ_AF_OPEN_DRAIN    0b1111


/*********************************** APIs Prototypes ************************************/

/***********************************************************************
 * Description: Function to initialize pin Direction each pin is 4 bits
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************/
void DIO_vidInitialize(void);


/*********************************************************************
 * Description: Function to Set pin Direction each pin is 4 bits
 * Outputs   :                   Error State
 * Inputs    : Copy_u8PinNB:     Pin Number
 *             Copy_u8Mode : direction of the pin
 *********************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNb, u8 Copy_u8Direction);


/*********************************************************************
 * Description: Function to Set pin value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PinValue: value of this pin
 *             Copy_u8PinNB : pin number
 ********************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8PinNb, u8 Copy_u8PinValue);


/********************************************************************
 * Description:  Function to get pin value
 * Outputs   :               Error State
 * Inputs    : u8* Copy_Pu8Value: pointer to address of the value
 *             Copy_u8PinNB  :  pin number
 ********************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8PinNb, u8* Copy_Pu8Value);


/**************************************************
 * Description: Function to Set port value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PortValue: value of the port
 *             Copy_u8PortNB   : port number
 ************************************************/
u8 DIO_u8SetPortValue(u8 Copy_u8PortNb, u32 Copy_u8PortValue);

/******************************************************************
 * Description: Function to get port value
 * Outputs    :              Error State
 * Inputs     : u8* Copy_Pu8Value: pointer to address of the value
 *              Copy_u8PortNB    : port number
 ****************************************************************/
u8 DIO_u8GetPortValue(u8 Copy_u8PortNb, u8* Copy_Pu8Value);

#endif /* DIO_INTERFACE_H_ */
