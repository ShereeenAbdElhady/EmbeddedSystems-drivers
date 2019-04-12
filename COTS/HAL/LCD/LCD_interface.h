/***************************************************************************************/
/*                                                                                    */
/* File Name   : LCD_interface.h                                                     */
/*                                                                                  */
/* Created on  : Mar 6, 2019                                                       */
/*                                                                                */
/* Author      : shereen Abd Elhady                                              */
/*                                                                              */
/* Version     : V01                                                           */
/*                                                                            */
/* Description : interface file for liquid crystal display                   */
/*               includes APIs' prototypes and MACROS for call              */
/*                                                                         */
/* Layer       : HAL                                                      */
/*************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "LCD_config.h"


/* ROWs and COLUMNs Macros definitions                                           */
#define LCD_u8_ROW0    (u8)0
#define LCD_u8_ROW1    (u8)1

#define LCD_u8_COL0    (u8)0
#define LCD_u8_COL1    (u8)1
#define LCD_u8_COL2    (u8)2
#define LCD_u8_COL3    (u8)3
#define LCD_u8_COL4    (u8)4
#define LCD_u8_COL5    (u8)5
#define LCD_u8_COL6    (u8)6
#define LCD_u8_COL7    (u8)7
#define LCD_u8_COL8    (u8)8
#define LCD_u8_COL9    (u8)9
#define LCD_u8_COL10   (u8)10
#define LCD_u8_COL11   (u8)11
#define LCD_u8_COL12   (u8)12
#define LCD_u8_COL13   (u8)13
#define LCD_u8_COL14   (u8)14
#define LCD_u8_COL15   (u8)15


/* the user choose the CGRAM index he wants to display according to his desire */
/* Whether he gonna display the first pattern, the second one or whatever......*/
/* Special patterns CGRAM index definitions                                    */
#define LCD_u8_SPECIAL_PATTERN_INDEX0  (u8)0
#define LCD_u8_SPECIAL_PATTERN_INDEX1  (u8)1
#define LCD_u8_SPECIAL_PATTERN_INDEX2  (u8)2
#define LCD_u8_SPECIAL_PATTERN_INDEX3  (u8)3
#define LCD_u8_SPECIAL_PATTERN_INDEX4  (u8)4
#define LCD_u8_SPECIAL_PATTERN_INDEX5  (u8)5
#define LCD_u8_SPECIAL_PATTERN_INDEX6  (u8)6
#define LCD_u8_SPECIAL_PATTERN_INDEX7  (u8)7


/*********************************** APIs Prototypes ************************************/

/**********************************************************************************************
 * Description: Function to initialize the LCD in 4BIT / 8BIT Data mode
 * Outputs   : None
 * Inputs    : None
 **********************************************************************************************/
void LCD_VidInitialize (void);


/***********************************************************************
 * Description: Function to write a string on the LCD
 * Outputs   : Error state
 * Inputs    : u8 *Copy_Pu8Data : pointer to the sent string
 *             u8 Copy_u8XPos   : X axis position
 *             u8 Copy_u8YPos   : Y axis position
 ***********************************************************************/
u8 LCD_u8WriteString(u8 *Copy_Pu8Data, u8 Copy_u8XPos , u8 Copy_u8YPos);

/**********************************************************************************************
 * Description: Function to clear the LCD in 4BIT / 8BIT Data mode
 * Outputs   : None
 * Inputs    : None
 **********************************************************************************************/
void LCD_VidClearScreen(void);


/***********************************************************************************************
 * Description: Function to write a special characters on the LCD at any position
 * Outputs   : Error state
 * Inputs    : u8 *Copy_Pu8Array     : pointer to the sent array which contains the patterns
 *             u8 Copy_u8PatternIndex: the index of pattern to be displayed
 *             u8 Copy_u8XPos        : X axis position (columns)
 *             u8 Copy_u8YPos        : Y axis position (rows)
 **********************************************************************************************/
u8 LCD_u8WriteSpecialCharacter(u8 *Copy_Pu8Array,u8 Copy_u8PatternIndex,u8 Copy_u8XPos , u8 Copy_u8YPos);

#endif /* LCD_INTERFACE_H_ */
