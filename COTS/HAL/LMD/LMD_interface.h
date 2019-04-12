/***************************************************************************************/
/*                                                                                    */
/* File Name   : LMD_interface.h                                                     */
/*                                                                                  */
/* Created on  : Mar 7, 2019                                                       */
/*                                                                                */
/* Author      : shereen Abd Elhady                                              */
/*                                                                              */
/* Version     : V01                                                           */
/*                                                                            */
/* Description : interface file for LED matrix display driver                */
/*               includes APIs' prototypes and MACROS for call              */
/*                                                                         */
/* Layer       : HAL                                                      */
/*************************************************************************/

#ifndef LMD_INTERFACE_H_
#define LMD_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "LMD_config.h"

/* LMD activation techniques definition        */
#define LMD_u8_ACTIVE_ROW       (u8)1
#define LMD_u8_ACTIVE_COL       (u8)0

/* LMD activation types definitions            */
#define LMD_u8_ACTIVE_HIGH      (u8)1
#define LMD_u8_ACTIVE_LOW       (u8)0


/************************************************************
 * Description:  Function to display image on the LMD
 * Outputs   :               Error State
 * Inputs    : u8* Copy_Pu8Image: pointer to array of images
 *             Copy_u8Color  :  variable to set the color
 **********************************************************/
u8 LMD_u8Display(u32 * Copy_Pu8Image, u8 Copy_u8Color);

#endif /* LMD_INTERFACE_H_ */
