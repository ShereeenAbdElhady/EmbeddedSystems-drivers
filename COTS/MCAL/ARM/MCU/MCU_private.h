/**************************************************************************************/
/*                                                                                   */
/* File Name   : MCU_private.h                                                      */
/*                                                                                 */
/* Created on  : Mar 28, 2019                                                     */
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


                  /******************************* Registers Addresses *****************************/
                                         /**** SCB Base address 0xE000 E008****/

/* (AIRCR) Application interrupt and reset control register address definition (offset 0x0C) (casting to pointer of u32)          */
/* ((u32*) 0xE000ED0C) is a pointer which carries an address and * to access this address                                         */
#define MCU_u32_SCB_AIRCR  *((u32*) 0xE000ED0C)


/* To write to AIRCR register you must write 0xF5A to the VECTKEY field, otherwise the processor ignore to write                  */
#define MCU_u32_SCB_AIRCR_KEY  0x5FA




#endif /* MCU_PRIVATE_H_ */
