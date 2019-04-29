/***********************************************************************************/
/*                                                                                */
/* File Name   : DIO_interface.h                                                 */
/*                                                                              */
/* Created on  : Jan 29, 2019                                                  */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V01                                                       */
/*                                                                        */
/* Description : Interface file for DIO driver includes APIs' prototypes */
/*                                                                      */
/*               And MACROS for call                                   */
/*                                                                    */
/* Layer       : MCAL                                                */
/*                                                                  */
/*******************************************************************/

/* Preprocessor Guard                */
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/* 	The interface file includes only the Public configurations from the configuration file */
#include "DIO_config.h"

/* Micro-Controller PINs definitions */
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

/* Ports definitions for mapping            */
#define DIO_u8_PORT0     (u8)0
#define DIO_u8_PORT1     (u8)1
#define DIO_u8_PORT2     (u8)2
#define DIO_u8_PORT3     (u8)3

/* The user use these macros to set the direction of any PIN whether it's gonna be output or input PIN   */
#define DIO_u8_PIN_OUTPUT (u8)1
#define DIO_u8_PIN_INPUT  (u8)0


/* The user use these macros to set the value of any output PIN whether it's gonna have high or low value */
#define DIO_u8_PIN_HIGH   (u8)1
#define DIO_u8_PIN_LOW    (u8)0

/* The user use these macros to set the value of any output PORT whether it's gonna have high or low value */
#define DIO_u8_PORT_HIGH   0xFF
#define DIO_u8_PORT_LOW    0X00

/* The user use these macros to set the direction of any PORT whether it's gonna be output or input PORT   */
#define DIO_u8_PORT_OUTPUT 0xFF
#define DIO_u8_PORT_INPUT  0x00
#define DIO_u8_PORT_LEAST_NIBBLE_OUTPUT  0x0F
#define DIO_u8_PORT_MOST_NIBBLE_OUTPUT   0xF0

/* Internal resistance configuration definition                                       */
/* as any PIN we could activate it's internal pull up resistance or leave it floating */
#define DIO_u8_INTERNAL_PULL_UP     (u8)1
#define DIO_u8_INTERNAL_FLOATING    (u8)0


/*********************************** APIs Prototypes ************************************/

/*******************************************************************
 * Description: Function to Set pin Direction
 * Outputs   :                   Error State
 * Inputs    : Copy_u8PinNB:     Pin Number
 *             Copy_u8Direction: direction of the pin
 ******************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNb, u8 Copy_u8Direction);


/*******************************************************************
 * Description: Function to Set pin value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PortValue: value of this pin
 *             Copy_u8PinNB : pin number
********************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8PinNb, u8 Copy_u8PinValue);


/*******************************************************************
 * Description:  Function to get pin value
 * Outputs   :               Error State
 * Inputs    : u8* Copy_Pu8Value: pointer to address of the value
 *             Copy_u8PinNB  :  pin number
********* **********************************************************/
u8 DIO_u8GetPinValue(u8 u8PinNb, u8* Pu8Value);


/*****************************************************************
 * Description: Function to Set port Direction
 * Outputs   :              Error State
 * Inputs    : Copy_u8Direction: direction of the port
 *             Copy_u8PortNB: port number
*****************************************************************/
u8 DIO_u8SetPortDirection(u8 u8PortNb ,u8 u8Direction);


/*****************************************************************
 * Description: Function to Set port value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PortValue: value of the port
 *             Copy_u8PortNB   : port number
 ******************************************************************/
u8 DIO_u8SetPortValue(u8 u8PortNb, u8 u8PortValue);


/******************************************************************
 * Description: Function to get port value
 * Outputs    :              Error State
 * Inputs     : u8* Copy_Pu8Value: pointer to address of the value
 *              Copy_u8PortNB    : port number
 ****************************************************************/
u8 DIO_u8GetPortValue(u8 u8PortNb, u8* Pu8Value);


/******************************************************************
 * Description: Function to initialize PINs directions and values
 * Outputs    : void
 * Inputs     : void
 ****************************************************************/
void DIO_vidinit(void);


#endif /* DIO_INTERFACE_H_ */
