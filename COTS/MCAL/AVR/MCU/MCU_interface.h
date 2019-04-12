/***************************************************************************************/
/*                                                                                    */
/* File Name   : MCU_interface.h                                                     */
/*                                                                                  */
/* Created on  : Mar 25, 2019                                                      */
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

/****************************************************************************************************
 * Description:Enable status register I-bit (global interrupt enable )
 * Outputs    :None
 * Inputs     :None
 ***************************************************************************************************/
void MCU_VidEnableGlobalINTP(void);


/****************************************************************************************************
 * Description:Disable status register I-bit (global interrupt enable )
 * Outputs    :None
 * Inputs     :None
 ***************************************************************************************************/
void MCU_VidDisableGlobalINTP(void);



#endif /* MCU_INTERFACE_H_ */
