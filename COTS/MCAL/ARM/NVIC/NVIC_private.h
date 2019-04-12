/*****************************************************************************************************/
/*                                                                                                  */
/* File Name   : NVIC_private.h                                                                    */
/*                                                                                                */
/* Created on  : Mar 28, 2019                                                                    */
/*                                                                                              */
/* Author      : shereen Abd Elhady                                                            */
/*                                                                                            */
/* Version     : V01                                                                         */
/*                                                                                          */
/* Description : Private header file for NVIC driver contains Registers address definitions*/
/*               of STM32F103C8 ARM Micro-Controller.                                     */
/*               Also contains private functions' prototypes                             */
/*               And the MACROS not needed by the upper layers' components.             */
/* Layer        : MCAL                                                                 */
/*                                                                                    */
/*************************************************************************************/


#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/* 	The Private file includes only the Private configurations from the configuration file */
#include "NVIC_config.h"

                    /******************************* Registers Addresses *****************************/
                                   /********* NVIC Base address (0xE000E100)**********/

/* (ISER) interrupt set enable address definition (offset address of ISER0 ->0x000, ISER1 -> 0x004 , ISER2 -> 0x008) (casting to pointer of u32)          */
#define NVIC_u32_ISER ((u32*) 0xE000E100)

/* (ICER) interrupt clear enable register address definition (offset address of ICER0 ->0x080, ICER1 -> 0x084 , ICER2 -> 0x088)(casting to pointer of u32)*/
#define NVIC_u32_ICER ((u32*) 0xE000E180)

/* (ISPR) interrupt set pending register address definition (offset address of ISPR0 ->0x100, ISPR1 -> 0x104 , ISPR2 -> 0x108) (casting to pointer of u32) */
#define NVIC_u32_ISPR ((u32*) 0xE000E200)

/* (ICPR) interrupt clear pending register address definition (offset address of ICPR0 ->0x180, ICPR1 -> 0x184 , ICPR2 -> 0x188) (casting to pointer of u32)*/
#define NVIC_u32_ICPR ((u32*) 0xE000E280)

/* (IPR) interrupt priority register address definition (offset address of IPR ->0x300) (casting to pointer of u8)                                          */
/* As the IPR register is 32 bits and divided into 4 bytes, each byte is responsible for specific interrupt                                                 */
/* so we cast this pointer to (u8) to be able to access each byte                                                                                           */
#define NVIC_u32_IPR ((u32*) 0xE000E400)


/* Definition for the maximum number of external interrupts in STM32F103C8 ARM Microcontroller                       */
#define NVIC_u8_MAX_NUM_EXT_INT            (u8)60

/* Definition for the number of bits per register each bit is equivalent to an interrupt                             */
#define NVIC_u8_NUM_BITS_PER_REG           (u8)32

/* The IPR register is 32 bits and divided into 4 offsets, each offset is equivalent to an interrupt                 */
#define NVIC_u8_NUM_INT_PER_IPR_REG        (u8)4

/* The IPR register is 32 bits and divided into 4 offsets, each offset is equivalent to an interrupt priority        */
/* Each offset consists of 8 bits                                                                                    */
#define NVIC_u8_NUM_BITS_PER_OFFSET        (u8)8


/* The IPR register is 32 bits and divided into 4 offsets, each offset is equivalent to an interrupt priority        */
/* We have to shift 4 bits in this offset in order to be able to set the priority as they should be written in MSBs  */
#define NVIC_u8_NUM_IPR_OFFSET_SHIFT_BITS  (u8)4


#endif /* NVIC_PRIVATE_H_ */
