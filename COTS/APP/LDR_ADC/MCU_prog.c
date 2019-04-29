/**********************************************************************************/
/*                                                                               */
/* File Name   : MCU_prog.c                                                     */
/*                                                                             */
/* Created on  : Mar 24, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V01                                                      */
/*                                                                       */
/* Description : software driver for MCU which handles the overalls     */
/*                                                                     */
/*               of MC with a defined public and private functions.   */
/*                                                                   */
/* Layer       : MCAL                                               */
/*******************************************************************/

#include "STD_TYPES.h"
#include "MCU_interface.h"
#include "MCU_private.h"

/****************************************************************************************************
 * Description:Enable status register I-bit (global interrupt enable )
 * Outputs    :None
 * Inputs     :None
 ***************************************************************************************************/
void MCU_VidEnableGlobalINTP(void)
{
	/* Enable interrupts by setting I-bit          */
	MCU_u8_SREG  |= (MCU_u8_GIE_ENABLE<<MCU_u8_SREG_I_BIT);
}


/****************************************************************************************************
 * Description:Disable status register I-bit (global interrupt enable )
 * Outputs    :None
 * Inputs     :None
 ***************************************************************************************************/
void MCU_VidDisableGlobalINTP(void)
{
	/* Disable interrupts by clearing I-bit        */
	MCU_u8_SREG &= (~(MCU_u8_GIE_ENABLE<<MCU_u8_SREG_I_BIT));
}

