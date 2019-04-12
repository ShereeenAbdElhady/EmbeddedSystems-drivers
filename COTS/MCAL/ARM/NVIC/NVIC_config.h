/***********************************************************************************/
/*                                                                                */
/* File Name   : NVIC_config.h                                                   */
/*                                                                              */
/* Created on  : Mar 28, 2019                                                  */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V01                                                       */
/*                                                                        */
/* Description : configuration file for NVIC driver includes             */
/*               Basic private and public configurations                */
/*               for STM32F103C8 ARM microcontroller                   */
/*                                                                    */
/* Layer       : MCAL                                                */
/********************************************************************/



/**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef NVIC_PUBLIC_CONFIG_H_
#ifdef  NVIC_INTERFACE_H_
#define NVIC_PUBLIC_CONFIG_H_



#endif     /* NVIC_INTERFACE_H_ */
#endif     /* NVIC_PUBLIC_CONFIG_H_ */




/**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef NVIC_PRIVATEC_CONFIG_H_
#ifdef  NVIC_PRIVATE_H_
#define NVIC_PRIVATE_CONFIG_H_


#endif    /* NVIC_PRIVATE_H_ */
#endif   /* NVIC_PRIVATE_CONFIG_H_ */
