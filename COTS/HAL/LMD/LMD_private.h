/**************************************************************************************/
/*                                                                                   */
/* File Name   : LMD_private.h                                                      */
/*                                                                                 */
/* Created on  :  Mar 7, 2019                                                    */
/*                                                                               */
/* Author      : shereen Abd Elhady                                             */
/*                                                                             */
/* Version     : V01                                                          */
/* Description : private header file for LED matrix display driver           */
/*                                                                          */
/* Layer       : HAL                                                       */
/**************************************************************************/

#ifndef LMD_PRIVATE_H_
#define LMD_PRIVATE_H_

/* 	The Private file includes only the Private configurations from the configuration file */
#include "LMD_config.h"

/* Active High Array                                      */
u32 LMD_Au8ActiveHigh[LMD_u8_NUMBER_LEDS] ={0x00000001,
		                                    0x00000002,
		                                    0x00000004,
		                                    0x00000008,
		                                    0x00000010,
		                                    0x00000020,
		                                    0x00000040,
		                                    0x00000080
};

/* Active Low Array                                         */
u8 LMD_Au8ActiveLow[LMD_u8_NUMBER_LEDS] = {0b11111110,
		                                   0b11111101,
		                                   0b11111011,
		                                   0b11110111,
		                                   0b11101111,
		                                   0b11011111,
		                                   0b10111111,
		                                   0b01111111
};

#endif /* LMD_PRIVATE_H_ */
