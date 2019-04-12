/**************************************************************************************/
/*                                                                                   */
/* File Name   : SSD_private.h                                                      */
/*                                                                                 */
/* Created on  : Feb 8, 2019                                                      */
/*                                                                               */
/* Author      : shereen Abd Elhady                                             */
/*                                                                             */
/* Version     : V01                                                          */
/* Description : private header file for seven segment driver                */
/*               includes private functions prototypes.                     */
/*                                                                         */
/* Layer       : HAL                                                      */
/*************************************************************************/

#ifndef SSD_PRIVATE_H_
#define SSD_PRIVATE_H_

/* Seven Segment number of PINs                                        */
#define SSD_u8_NUM_OF_PINS         (u8)8

/* 	The Private file includes only the Private configurations from the configuration file */
#include "SSD_config.h"




/* Seven Segment number of segments                                   */
#define SSD_u8_NUM_OF_SEGMENTS     (u8)7

/* Seven Segment COMMON PIN value                                     */
#define SSD_u8_COMMON_GND_VALUE    (u8)0
#define SSD_u8_COMMON_VCC_VALUE    (u8)1

/* array of integers contains numbers' values in binary representation for common cathod 7 segment */
/* MSB gfedcba
 * MSB : to enbale and disable the SSD*/
u8 SSD_Au8NumberBinaryCathod[10][SSD_u8_NUM_OF_PINS] =
{
		{1,1,1,1,1,1,0,0},
		{0,1,1,0,0,0,0,0},
		{1,1,0,1,1,0,1,0},
		{1,1,1,1,0,0,1,0},
		{0,1,1,0,0,1,1,0},
		{1,0,1,1,0,1,1,0},
		{1,0,1,1,1,1,1,0},
		{1,1,1,0,0,0,1,0},
		{1,1,1,1,1,1,1,0},
		{1,1,1,1,0,1,1,0}
};
//u8 SSD_Au8NumberBinaryCathod[10] = {0b11111100, 0b01100000 , 0b11011010 , 0b11110010 , 0b01100110 , 0b10110110 ,0b10111110 , 0b11100010 , 0b11111110 , 0b11110110};

/* array of integers contains numbers' values in binary representation for common anode 7 segment */
u8 SSD_Au8NumberBinaryAnode[10][SSD_u8_NUM_OF_PINS] =
{
		{~1,~1,~1,~1,~1,~1,~0,~0},
		{~0,~1,~1,~0,~0,~0,~0,~0},
		{~1,~1,~0,~1,~1,~0,~1,~0},
		{~1,~1,~1,~1,~0,~0,~1,~0},
		{~0,~1,~1,~0,~0,~1,~1,~0},
		{~1,~0,~1,~1,~0,~1,~1,~0},
		{~1,~0,~1,~1,~1,~1,~1,~0},
		{~1,~1,~1,~0,~0,~0,~1,~0},
		{~1,~1,~1,~1,~1,~1,~1,~0},
		{~1,~1,~1,~1,~0,~1,~1,~0}
};

/* array of integers contains the alphabetical segments values in binary representation from A to G segments    */
u8 SSD_Au8SegmentsArray[SSD_u8_NUM_OF_SEGMENTS][SSD_u8_NUM_OF_PINS] =
{
		{1,0,0,0,0,0,0,0},
		{0,1,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0},
		{0,0,0,1,0,0,0,0},
		{0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,1,0}
};
#endif /* SSD_PRIVATE_H_ */



