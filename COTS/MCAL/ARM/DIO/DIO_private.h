/*****************************************************************************************************/
/*                                                                                                  */
/* File Name   : DIO_private.h                                                                     */
/*                                                                                                */
/* Created on  : Feb 27, 2019                                                                    */
/*                                                                                              */
/* Author      : shereen Abd Elhady                                                            */
/*                                                                                            */
/* Version     : V02                                                                         */
/*                                                                                          */
/* Description : Private header file for DIO driver contains Registers address definitions */
/*               of STM32F103C8 ARM Micro-Controller.                                     */
/*               Also contains private functions' prototypes                             */
/*               And the MACROS not needed by the upper layers' components.             */
/* Layer        : MCAL                                                                 */
/*                                                                                    */
/*************************************************************************************/



#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* 	The Private file includes only the Private configurations from the configuration file */
#include "DIO_config.h"

/* Private Macro to define the maximum PIN number                                         */
#define DIO_u8_MAX_PINNB            (u8)37


/* Private Macro to define the maximum PORT number                                        */
#define DIO_u8_MAX_PORTNB           (u8)4

/* Private MACRO used in APIs to define number of PINs per PORT                           */
#define DIO_u8_NUMBER_PINS_IN_PORT  (u8)16

/* Private MACRO defines the max value of DIO modes where the max mode value  was 1111=15 */
/* I defined instead of writing the 15 mode in the if condition                           */
#define DIO_u8_MAX_MODES_VALUE      (u8)15

/*structure to define offset addresses of these registers arranged in a correct way to be */
/* able to get their offset values correctly                                              */
typedef struct
{
/* CRL Address definition (offset address0x00)                                            */
	Register_32Bit   CRL ;
/* CRH Address definition (offset address0x04)                                            */
	Register_32Bit   CRH ;
/* IDR Address definition (offset address0x08)                                            */
	Register_32Bit   IDR ;
/* ODR Address definition (offset address0x0C)                                            */
	Register_32Bit   ODR ;
/* BSRR Address definition (offset address0x10)                                           */
	Register_32Bit   BSRR;
/* BRR Address definition (offset address0x14)                                            */
	Register_32Bit   BRR ;
/* LCKR Address definition (offset address0x18)                                           */
	Register_32Bit   LCKR;
}GPIO;

/* Casting the addresses to a structure                                                   */
/**************** Group A (0x4001 0800 - 0x4001 0BFF) *****************/
#define DIO_u32_GPIOA     ((GPIO*)0x40010800)
/**************** Group B (0x4001 0C00 - 0x4001 0FFF) *****************/
#define DIO_u32_GPIOB     ((GPIO*)0x40010C00)
/**************** Group C (0x4001 1000 - 0x4001 13FF) *****************/
#define DIO_u32_GPIOC     ((GPIO*)0x40011000)
/**************** Group D (0x4001 1400 - 0x4001 17FF) *****************/
#define DIO_u32_GPIOD     ((GPIO*)0x40011400)

              /*********************** Private Functions Prototypes ***************************/


/*********************************************************************
 * Description: Private Function to Set pin value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PortNb: port number
 *             Copy_u8PinNB : pin number
 ********************************************************************/
static u8 u8SetPin(u8 Copy_u8PortNb, u8 Copy_u8PinNb);


/*********************************************************************
 * Description: Private Function to Reset pin value
 * Outputs   :              Error State
 * Inputs    : Copy_u8PortNb: port number
 *             Copy_u8PinNB : pin number
 ********************************************************************/
static u8 u8RstPin(u8 Copy_u8PortNb, u8 Copy_u8PinNb);

#endif /* DIO_PRIVATE_H_ */
