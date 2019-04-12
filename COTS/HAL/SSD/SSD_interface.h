/***************************************************************************************/
/*                                                                                    */
/* File Name   : SSD_interface.h                                                     */
/*                                                                                  */
/* Created on  : Feb 8, 2019                                                       */
/*                                                                                */
/* Author      : shereen Abd Elhady                                              */
/*                                                                              */
/* Version     : V01                                                           */
/*                                                                            */
/* Description : interface file for seven segment driver                     */
/*               includes APIs' prototypes and MACROS for call              */
/*                                                                         */
/* Layer       : HAL                                                      */
/*************************************************************************/


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "SSD_config.h"

/* Seven Segment type definitions                                                                 */
#define SSD_u8_COMMON_CATHOD   (u8)0
#define SSD_u8_COMMON_ANODE    (u8)1

/* Mapping Seven Segment PINs direction with DIO driver PINs directions for setting the directory */
#define SSD_u8_PIN_DIR_OUTPUT	DIO_u8_PIN_OUTPUT

/* Mapping the seven segments PIN numbers with DIO driver PIN numbers */
#define SSD_u8_PIN0   DIO_u8_PIN0
#define SSD_u8_PIN1   DIO_u8_PIN1
#define SSD_u8_PIN2   DIO_u8_PIN2
#define SSD_u8_PIN3   DIO_u8_PIN3
#define SSD_u8_PIN4   DIO_u8_PIN4
#define SSD_u8_PIN5   DIO_u8_PIN5
#define SSD_u8_PIN6   DIO_u8_PIN6
#define SSD_u8_PIN7   DIO_u8_PIN7
#define SSD_u8_PIN8   DIO_u8_PIN8
#define SSD_u8_PIN9   DIO_u8_PIN9
#define SSD_u8_PIN10  DIO_u8_PIN10
#define SSD_u8_PIN11  DIO_u8_PIN11
#define SSD_u8_PIN12  DIO_u8_PIN12
#define SSD_u8_PIN13  DIO_u8_PIN13
#define SSD_u8_PIN14  DIO_u8_PIN14
#define SSD_u8_PIN15  DIO_u8_PIN15
#define SSD_u8_PIN16  DIO_u8_PIN16
#define SSD_u8_PIN17  DIO_u8_PIN17
#define SSD_u8_PIN18  DIO_u8_PIN18
#define SSD_u8_PIN19  DIO_u8_PIN19
#define SSD_u8_PIN20  DIO_u8_PIN20
#define SSD_u8_PIN21  DIO_u8_PIN21
#define SSD_u8_PIN22  DIO_u8_PIN22
#define SSD_u8_PIN23  DIO_u8_PIN23
#define SSD_u8_PIN24  DIO_u8_PIN24
#define SSD_u8_PIN25  DIO_u8_PIN25
#define SSD_u8_PIN26  DIO_u8_PIN26
#define SSD_u8_PIN27  DIO_u8_PIN27
#define SSD_u8_PIN28  DIO_u8_PIN28
#define SSD_u8_PIN29  DIO_u8_PIN29
#define SSD_u8_PIN30  DIO_u8_PIN30
#define SSD_u8_PIN31  DIO_u8_PIN31

/* Seven segment most significant pin number                          */
#define SSD_u8_MSB   (u8)7

/* Numbers' values definitions */
#define SSD_u8_NUMBER_ZERO   (u8)0
#define SSD_u8_NUMBER_ONE    (u8)1
#define SSD_u8_NUMBER_TWO    (u8)2
#define SSD_u8_NUMBER_THREE  (u8)3
#define SSD_u8_NUMBER_FOUR   (u8)4
#define SSD_u8_NUMBER_FIVE   (u8)5
#define SSD_u8_NUMBER_SIX    (u8)6
#define SSD_u8_NUMBER_SEVEN  (u8)7
#define SSD_u8_NUMBER_EIGHT  (u8)8
#define SSD_u8_NUMBER_NINE   (u8)9
#define SSD_u8_NUMBER_MAX    (u8)10


/* Seven Segments index definitions */
#define SSD_u8_INDEX_ZERO   (u8)0
#define SSD_u8_INDEX_ONE    (u8)1
#define SSD_u8_INDEX_TWO    (u8)2
#define SSD_u8_INDEX_THREE  (u8)3
#define SSD_u8_INDEX_FOUR   (u8)4

/* Segments' definition             */
#define SSD_u8_A_SEG   (u8)0
#define SSD_u8_B_SEG   (u8)1
#define SSD_u8_C_SEG   (u8)2
#define SSD_u8_D_SEG   (u8)3
#define SSD_u8_E_SEG   (u8)4
#define SSD_u8_F_SEG   (u8)5
#define SSD_u8_G_SEG   (u8)6


        /********************************APIs prototypes **********************************/

/*******************************************************************************************
 * Description : Function responsible for displaying a number send by user
 *               on a seven segment and decide either it is gonna be displayed
 *               on common anode or common cathod according to the user configurations.
 * Input       : Copy_u8NumberValue : number to be displayed
 *               Copy_u8SSDIndex    : seven segment display index
 * Output      : Error state
 *******************************************************************************************/
u8 SSD_u8DisplayNumber(u8 Copy_u8SSDIndex,u8 Copy_u8NumberValue);


/*******************************************************************************************
 * Description : Function responsible for displaying a specific segment send by user
 *               on a seven segment and decide either it is gonna be displayed
 *               on common anode or common cathod according to the user configurations.
 * Input       : Copy_u8SegmentValue : segment to be displayed
 *               Copy_u8SSDIndex    : seven segment display index
 * Output      : Error state
 *******************************************************************************************/
u8 SSD_u8DisplaySegment(u8 Copy_u8SSDIndex, u8 Copy_u8SegmentValue);


/*******************************************************************************************
 * Description : Function responsible for Turning ON the seven segment
 *               either it is was a common anode or a common cathod seven segment
 *               according to the user configurations.
 * Input       : Copy_u8SSDIndex    : seven segment display index
 * Output      : Error state
 *******************************************************************************************/
u8 SSD_u8SetSSDOn(u8 Copy_u8SSDIndex);


/*******************************************************************************************
 * Description : Function responsible for Turning OFF the seven segment
 *               either it is was a common anode or a common cathod seven segment
 *               according to the user configurations.
 * Input       : Copy_u8SSDIndex    : seven segment display index
 * Output      : Error state
 *******************************************************************************************/
u8 SSD_u8SetSSDOff(u8 Copy_u8SSDIndex);


/*******************************************************************************************
 * Description : Function responsible for initializing the seven segment
 *               either it is was a common anode or a common cathod seven segment
 *               according to the user configurations.
 * Input       : void
 * Output      : void
 *******************************************************************************************/
void SSD_u8InitSSD(void);


#endif /* SSD_INTERFACE_H_ */

