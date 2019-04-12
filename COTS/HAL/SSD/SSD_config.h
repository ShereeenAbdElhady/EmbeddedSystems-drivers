/*******************************************************************************************/
/*                                                                                        */
/* File Name   : SSD_config.h                                                            */
/*                                                                                      */
/* Created on  : Feb 8, 2019                                                           */
/*                                                                                    */
/* Author      : shereen  Abd Elhady                                                 */
/*                                                                                  */
/* Version     : V01                                                               */
/*                                                                                */
/* Description : Basic Public and Private configurations for seven segment driver*/
/*               defines it's type and connected to which PINs                  */
/*               according to the user desire.                                 */
/*                                                                            */
/* Layer       : HAL                                                         */
/****************************************************************************/


          /**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef SSD_PUBLIC_CONFIG_H_
#ifdef  SSD_INTERFACE_H_
#define SSD_PUBLIC_CONFIG_H_


#endif     /* SSD_INTERFACE_H_ */
#endif     /* SSD_PUBLIC_CONFIG_H_ */



/**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef SSD_PRIVATEC_CONFIG_H_
#ifdef  SSD_PRIVATE_H_
#define SSD_PRIVATE_CONFIG_H_

/* SSD numbers' configuration        */
#define SSD_u8_NUM_OF_SSD    (u8)2


/************ Seven Segment configurations to define it's  type ***************/
/* The customer configures the SSD type whether it's gonna be common cathod or common anode */
/* Range : SSD_u8_COMMON_CATHOD               */
/*         SSD_u8_COMMON_ANODE               */
u8 SSD_Au8SSDType[SSD_u8_NUM_OF_SSD] =
{
		SSD_u8_COMMON_CATHOD,
		SSD_u8_COMMON_CATHOD
};


/************ Seven Segment configurations to define it's PINs connections ***************/
/* The customer configures the SSD PINs connection  */
/* Range : From SSD_u8_PIN0               */
/*         To SSD_u8_PIN31
/* MSB gfedcba */
/* MSB : to enbale and disable the SSD*/
u8 SSD_Au8SSDConnectPin[SSD_u8_NUM_OF_SSD][SSD_u8_NUM_OF_PINS] =
{
		{SSD_u8_PIN0 , SSD_u8_PIN1 , SSD_u8_PIN2 , SSD_u8_PIN3 , SSD_u8_PIN4 , SSD_u8_PIN5 , SSD_u8_PIN6, SSD_u8_PIN7},
		 {SSD_u8_PIN8 , SSD_u8_PIN9 , SSD_u8_PIN10 , SSD_u8_PIN11 , SSD_u8_PIN12 , SSD_u8_PIN13 , SSD_u8_PIN14 , SSD_u8_PIN15}
};


#endif    /* SSD_PRIVATE_H_ */
#endif   /* SSD_PRIVATE_CONFIG_H_ */
