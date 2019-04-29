/**************************************************************************************/
/*                                                                                   */
/* File Name   : MCU_private.h                                                      */
/*                                                                                 */
/* Created on  : Mar 25, 2019                                                     */
/*                                                                               */
/* Author      : shereen Abd Elhady                                             */
/*                                                                             */
/* Version     : V01                                                          */
/* Description : private header file for MCU driver                          */
/*               includes private functions prototypes.                     */
/*                                                                         */
/* Layer       : MCAL                                                     */
/*************************************************************************/


#ifndef MCU_PRIVATE_H_
#define MCU_PRIVATE_H_

/* 	The Private file includes only the Private configurations from the configuration file */
#include "MCU_config.h"


/* SREG (Status Register ) Address definition                   */
#define MCU_u8_SREG    ((Register*) 0x5F)->ByteAccess


/* SREG (Status Register ) Bits definitions                     */
#define MCU_u8_SREG_I_BIT  (u8)7


/* Global interrupt enable and disable definitions          */
#define MCU_u8_GIE_ENABLE  (u8)1
#define MCU_u8_GIE_DISABLE (u8)0
#endif /* MCU_PRIVATE_H_ */
