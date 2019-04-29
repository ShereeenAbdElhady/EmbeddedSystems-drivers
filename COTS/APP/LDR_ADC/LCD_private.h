/**************************************************************************************/
/*                                                                                   */
/* File Name   : LCD_private.h                                                      */
/*                                                                                 */
/* Created on  : Mar 6, 2019                                                      */
/*                                                                               */
/* Author      : shereen Abd Elhady                                             */
/*                                                                             */
/* Version     : V01                                                          */
/* Description : private header file for liquid crystal display driver       */
/*               includes private functions prototypes                      */
/*               And private MACROS used by the programmer.                */
/*                                                                        */
/* Layer       : HAL                                                     */
/************************************************************************/


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

/* 	The Private file includes only the Private configurations from the configuration file */
#include "LCD_config.h"

/* LCD 8 Bits definitions                                          */
#define LCD_u8_BIT0              (u8)0
#define LCD_u8_BIT1              (u8)1
#define LCD_u8_BIT2              (u8)2
#define LCD_u8_BIT3              (u8)3
#define LCD_u8_BIT4              (u8)4
#define LCD_u8_BIT5              (u8)5
#define LCD_u8_BIT6              (u8)6
#define LCD_u8_BIT7              (u8)7


#define LCD_u8_PIN_HIGH          (u8)1
#define LCD_u8_PIN_LOW           (u8)0

/* Addresses values definitions                                    */
#define LCD_u8_LINE2_START_ADDRESS              0x40
#define LCD_u8_LINE1_START_ADDRESS_COMMAND      0x80
#define LCD_u8_LINE1_END_ADDRESS_COMMAND        0x90
#define LCD_u8_LINE2_START_ADDRESS_COMMAND      0xC0
#define LCD_u8_LINE2_END_ADDRESS_COMMAND        0xD0
#define LCD_u8_SET_CGRAM_ADRESS_IN_AC_COMMAND   0x40

/* number of locations (rows & columns) per pattern in the  CGRAM   */
#define LCD_u8_CGRAM_NUM_LOCATIONS_PER_PATTERN  0x08


/* Macros definitions for interfacing data length                   */
#define LCD_u8_8BIT_DATA_MODE  (u8)1
#define LCD_u8_4BIT_DATA_MODE  (u8)0


/* Function Set Register modes in case of 8 bits data               */
#define LCD_u8_8BIT_2LINES_5X7_FONT           0b00111000
#define LCD_u8_8BIT_2LINES_5X10_FONT          0b00111100
#define LCD_u8_8BIT_1LINE_5X7_FONT            0b00110000
#define LCD_u8_8BIT_1LINE_5X10_FONT           0b00110100

/* Display ON / OFF control  Register modes in case of  8 bits data */
#define LCD_u8_8BIT_ENBALE_CURSORON_BLINKON    0b00001111
#define LCD_u8_8BIT_ENBALE_CURSORON_BLINKOFF   0b00001110
#define LCD_u8_8BIT_ENBALE_CURSOROFF_BLINKOFF  0b00001100
#define LCD_u8_8BIT_DISABLE                    0b00001000

/* Display Clear                                                   */
#define LCD_u8_DISPLAY_CLEAR                   0b00000001

/* Function Set Register modes in case of 4 bits data              */
//#define LCD_u8_4BIT_FUNCTION_SET_REG_NIBBLE    0b0010
#define LCD_u8_4BIT_2LINES_5X7_FONT            0b00101000
#define LCD_u8_4BIT_2LINES_5X10_FONT           0b00101100
#define LCD_u8_4BIT_1LINE_5X7_FONT             0b00100000
#define LCD_u8_4BIT_1LINE_5X10_FONT            0b00100100

/* Display ON / OFF control  Register modes in case of  4 bits data*/
//#define LCD_u8_4BIT_DISPLAY_CONTROL_REG_NIBBLE  0b0000
#define LCD_u8_4BIT_ENBALE_CURSORON_BLINKON     0b00001111
#define LCD_u8_4BIT_ENBALE_CURSORON_BLINKOFF    0b00001110
#define LCD_u8_4BIT_ENBALE_CURSOROFF_BLINKOFF   0b00001100
#define LCD_u8_4BIT_DISABLE                     0b00001000

/* Display Clear in case of 4 bits  data                           */
//#define LCD_u8_4BIT_DISPLAY_CLEAR_REG_NIBBLE    0b0000
//#define LCD_u8_4BIT_DISPLAY_CLEAR               0b00000001


                  /******************* Private Functions APIs *************************/

/******************************************************************************
 * Description: Function to write a command on the LCD
 * Outputs   : None
 * Inputs    : u8 Copy_u8Command : argument to receive an 8 bit command
 ******************************************************************************/
static void LCD_VidWriteCommand(u8 Copy_u8Command);


/*******************************************************************************
 * Description: Function to write a character on the LCD
 * Outputs   : None
 * Inputs    : u8 Copy_uData : argument to receive an 8 bit data
 ********************************************************************************/
void LCD_VidWriteChar(u8 Copy_u8Data);


/*********************************************************************************
 * Description: Function to write a command / data on the LCD bit by bit
 *              which handles the 8 bit data mode and 4 bit data mode
 * Outputs   : None
 * Inputs    : u8 Copy_uDataCommand : argument to receive an 8 bit data/ command
 *********************************************************************************/
static void LCD_VidWrite(u8 Copy_u8DataCommand);

#endif /* LCD_PRIVATE_H_ */
