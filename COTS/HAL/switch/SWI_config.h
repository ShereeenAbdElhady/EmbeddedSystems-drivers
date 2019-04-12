/********************************************************************************************/
/*                                                                                         */
/* File Name   : SWI_config.h                                                             */
/*                                                                                       */
/* Created on  : Feb 7, 2019                                                           */
/*                                                                                     */
/* Author      : shereen  Abd Elhady                                                  */
/*                                                                                   */
/* Version     : V01                                                                */
/*                                                                                 */
/* Description : Basic Public and Private configurations for SWITCH driver        */
/*               defines it's type of connections                                */
/*               and connected to which PINs                                    */
/*               according to the user desire.                                 */
/*                                                                            */
/* Layer       : HAL                                                         */
/****************************************************************************/


           /**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef SWI_PUBLIC_CONFIG_H_
#ifdef  SWI_INTERFACE_H_
#define SWI_PUBLIC_CONFIG_H_




#endif     /* SWI_INTERFACE_H_ */
#endif     /* SWI_PUBLIC_CONFIG_H_ */


        /**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef SWI_PRIVATEC_CONFIG_H_
#ifdef  SWI_PRIVATE_H_
#define SWI_PRIVATE_CONFIG_H_


/* switches numbers' configuration                      */
#define SWI_u8_NUM_OF_SWI     (u8)2

u8 SWI_Au8SwiType[SWI_u8_NUM_OF_SWI] =
{
		PULL_DOWN_CONNECTION,
		PULL_DOWN_CONNECTION
};

/* The customer configures the connected SWITCHES with DIO PINs driver for setting SWITCH PIN number             */
u8 SWI_Au8SwiCh[SWI_u8_NUM_OF_SWI] =
{
		DIO_u8_PIN10,
		DIO_u8_PIN11
};

#endif    /* SWI_PRIVATE_H_ */
#endif   /* SWI_PRIVATE_CONFIG_H_ */

