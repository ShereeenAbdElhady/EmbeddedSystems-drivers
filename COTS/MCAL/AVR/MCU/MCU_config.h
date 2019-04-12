/*******************************************************************************************/
/*                                                                                        */
/* File Name   : MCU_config.h                                                            */
/*                                                                                      */
/* Created on  : Mar 24, 2019                                                          */
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


#endif     /* MCU_INTERFACE_H_ */
#endif     /* MCU_PUBLIC_CONFIG_H_ */



/**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef MCU_PRIVATEC_CONFIG_H_
#ifdef  MCU_PRIVATE_H_
#define MCU_PRIVATE_CONFIG_H_


#endif    /* MCU_PRIVATE_H_ */
#endif   /* MCU_PRIVATE_CONFIG_H_ */
