/*******************************************************************************************/
/*                                                                                        */
/* File Name   : MCU_config.h                                                            */
/*                                                                                      */
/* Created on  : Mar 28, 2019                                                          */
/*                                                                                    */
/* Author      : shereen  Abd Elhady                                                 */
/*                                                                                  */
/* Version     : V01                                                               */
/*                                                                                */
/* Description : Basic Public and Private configurations for MCU driver          */
/*               defines it's type and connected to which PINs                  */
/*               according to the user desire.                                 */
/*                                                                            */
/* Layer       : MCAL                                                        */
/****************************************************************************/


          /**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef MCU_PUBLIC_CONFIG_H_
#ifdef  MCU_INTERFACE_H_
#define MUC_PUBLIC_CONFIG_H_

/* The customer chooses the number of groups and subgroups according to his desire                            */
/* Range: MCU_u32_SCB_AIRCR_PRIORITY_16GP_0SUB                                                                */
/*        MCU_u32_SCB_AIRCR_PRIORITY_8GP_2SUB                                                                 */
/*        MCU_u32_SCB_AIRCR_PRIORITY_4GP_4SUB                                                                 */
/*        MCU_u32_SCB_AIRCR_PRIORITY_2GP_8SUB                                                                 */
/*        MCU_u32_SCB_AIRCR_PRIORITY_0GP_16SUB                                                                */
#define MCU_u32_SCB_PRIORITY_CONF  MCU_u32_SCB_AIRCR_PRIORITY_4GP_4SUB

#endif     /* MCU_INTERFACE_H_ */
#endif     /* MCU_PUBLIC_CONFIG_H_ */



/**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef MCU_PRIVATEC_CONFIG_H_
#ifdef  MCU_PRIVATE_H_
#define MCU_PRIVATE_CONFIG_H_



#endif    /* MCU_PRIVATE_H_ */
#endif   /* MCU_PRIVATE_CONFIG_H_ */
