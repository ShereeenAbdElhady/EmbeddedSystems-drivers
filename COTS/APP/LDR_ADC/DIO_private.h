/*****************************************************************************************************/
/*                                                                                                  */
/* File Name   : DIO_private.h                                                                     */
/*                                                                                                */
/* Created on  : Jan 31, 2019                                                                    */
/*                                                                                              */
/* Author      : shereen Abd Elhady                                                            */
/*                                                                                            */
/* Version     : V01                                                                         */
/*                                                                                          */
/* Description : Private header file for DIO driver contains Registers address definitions */
/*               of AVR Atmega32 Micro-Controller.                                        */
/*               Also contains private functions' prototypes                             */
/*               And the MACROS not needed by the upper layers' components.             */
/* Layer        : MCAL                                                                 */
/*                                                                                    */
/*************************************************************************************/


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* 	The Private file includes only the Private configurations from the configuration file */
#include "DIO_config.h"

/* no casting because it's used in MACRO definition and no need for casting there */
#define DIO_u8_PIN_INIT_INPUT      0
#define DIO_u8_PIN_INIT_OUTPUT     1

#define DIO_u8_PIN_INIT_HIGH       1
#define DIO_u8_PIN_INIT_LOW        0
#define DIO_u8_PIN_INIT_DEF        0

/* Private Macro to define the maximum PIN number    */
#define DIO_u8_MAX_PINNB (u8)32


/* Private Macro to define the maximum PORT number */
#define DIO_u8_MAX_PORTNB (u8)4

/* Private MACRO used in APIs to define number of PINs per PORT */
#define DIO_u8_NUMBER_PINS_IN_PORT  (u8)8


             /******************************* Group A ******************************************/
/* DDRA Address definition */
#define DIO_u8_DDRA ((Register*) 0x3A)->ByteAccess

/* PORTA Address definition */
#define DIO_u8_PORTA ((Register*) 0x3B)->ByteAccess

/* PINA Address definition */
#define DIO_u8_PINA ((Register*) 0x39)->ByteAccess

/* PINs Addresses definition */
#define DIO_u8_PA0 ((Register*) 0x3B)->BitAccess.Bit0
#define DIO_u8_PA1 ((Register*) 0x3B)->BitAccess.Bit1
#define DIO_u8_PA2 ((Register*) 0x3B)->BitAccess.Bit2
#define DIO_u8_PA3 ((Register*) 0x3B)->BitAccess.Bit3
#define DIO_u8_PA4 ((Register*) 0x3B)->BitAccess.Bit4
#define DIO_u8_PA5 ((Register*) 0x3B)->BitAccess.Bit5
#define DIO_u8_PA6 ((Register*) 0x3B)->BitAccess.Bit6
#define DIO_u8_PA7 ((Register*) 0x3B)->BitAccess.Bit7

            /******************************* Group B ******************************************/
/* DDRB Address definition */
#define DIO_u8_DDRB ((Register*) 0x37)->ByteAccess

/* PORTB Address definition */
#define DIO_u8_PORTB ((Register*) 0x38)->ByteAccess

/* PINB Address definition */
#define DIO_u8_PINB ((Register*) 0x36)->ByteAccess

/* PINs Addresses definition */
#define DIO_u8_PB0 ((Register*) 0x38)->BitAccess.Bit0
#define DIO_u8_PB1 ((Register*) 0x38)->BitAccess.Bit1
#define DIO_u8_PB2 ((Register*) 0x38)->BitAccess.Bit2
#define DIO_u8_PB3 ((Register*) 0x38)->BitAccess.Bit3
#define DIO_u8_PB4 ((Register*) 0x38)->BitAccess.Bit4
#define DIO_u8_PB5 ((Register*) 0x38)->BitAccess.Bit5
#define DIO_u8_PB6 ((Register*) 0x38)->BitAccess.Bit6
#define DIO_u8_PB7 ((Register*) 0x38)->BitAccess.Bit7

            /******************************* Group C ******************************************/
/* DDRC Address definition */
#define DIO_u8_DDRC ((Register*) 0x34)->ByteAccess

/* PORTC Address definition */
#define DIO_u8_PORTC ((Register*) 0x35)->ByteAccess

/* PINC Address definition */
#define DIO_u8_PINC ((Register*) 0x33)->ByteAccess

/* PINs Addresses definition */
#define DIO_u8_PC0 ((Register*) 0x35)->BitAccess.Bit0
#define DIO_u8_PC1 ((Register*) 0x35)->BitAccess.Bit1
#define DIO_u8_PC2 ((Register*) 0x35)->BitAccess.Bit2
#define DIO_u8_PC3 ((Register*) 0x35)->BitAccess.Bit3
#define DIO_u8_PC4 ((Register*) 0x35)->BitAccess.Bit4
#define DIO_u8_PC5 ((Register*) 0x35)->BitAccess.Bit5
#define DIO_u8_PC6 ((Register*) 0x35)->BitAccess.Bit6
#define DIO_u8_PC7 ((Register*) 0x35)->BitAccess.Bit7

            /******************************* Group D ******************************************/
/* DDRD Address definition */
#define DIO_u8_DDRD ((Register*) 0x31)->ByteAccess

/* PORTD Address definition */
#define DIO_u8_PORTD ((Register*) 0x32)->ByteAccess

/* PIND Address definition */
#define DIO_u8_PIND ((Register*) 0x30)->ByteAccess

/* PINs Addresses definition */
#define DIO_u8_PD0 ((Register*) 0x32)->BitAccess.Bit0
#define DIO_u8_PD1 ((Register*) 0x32)->BitAccess.Bit1
#define DIO_u8_PD2 ((Register*) 0x32)->BitAccess.Bit2
#define DIO_u8_PD3 ((Register*) 0x32)->BitAccess.Bit3
#define DIO_u8_PD4 ((Register*) 0x32)->BitAccess.Bit4
#define DIO_u8_PD5 ((Register*) 0x32)->BitAccess.Bit5
#define DIO_u8_PD6 ((Register*) 0x32)->BitAccess.Bit6
#define DIO_u8_PD7 ((Register*) 0x32)->BitAccess.Bit7

#endif /* DIO_PRIVATE_H_ */
