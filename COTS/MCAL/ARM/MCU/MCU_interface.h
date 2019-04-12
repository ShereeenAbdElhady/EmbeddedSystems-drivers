/***************************************************************************************/
/*                                                                                    */
/* File Name   : MCU_interface.h                                                     */
/*                                                                                  */
/* Created on  : Mar 28, 2019                                                      */
/*                                                                                */
/* Author      : shereen Abd Elhady                                              */
/*                                                                              */
/* Version     : V01                                                           */
/*                                                                            */
/* Description : interface file for MCU driver                               */
/*               includes APIs' prototypes and MACROS for call              */
/*                                                                         */
/* Layer       : MCAL                                                     */
/*************************************************************************/



#ifndef MCU_INTERFACE_H_
#define MCU_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "MCU_config.h"


/* The PRIGROUP field indicates the position of the binary point ( number of groups & subgroup) that splits the PRI_n fields in   */
/* the Interrupt Priority Registers into separate group priority and sub priority fields                                          */
#define MCU_u32_SCB_AIRCR_PRIORITY_16GP_0SUB (u32)0x5FA0300
#define MCU_u32_SCB_AIRCR_PRIORITY_8GP_2SUB  (u32)0x5FA0400
#define MCU_u32_SCB_AIRCR_PRIORITY_4GP_4SUB  (u32)0x5FA0500
#define MCU_u32_SCB_AIRCR_PRIORITY_2GP_8SUB  (u32)0x5FA0600
#define MCU_u32_SCB_AIRCR_PRIORITY_0GP_16SUB (u32)0x5FA0700

/****************************************************************************************************
 * Description:Function responsible for grouping and sub grouping of NVIC priority
 *             through configuring the (SCB) system control block peripheral and AIRCR Register.
 * Outputs    :Error state
 * Inputs     :Copy_u32GpSubGp_PriorityConf : number of groups and  sub groups
 ***************************************************************************************************/
u8 MCU_u8SetGroupSubgroup (u32 Copy_u32GpSubGp_PriorityConf);



#endif /* MCU_INTERFACE_H_ */
