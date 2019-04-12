/**********************************************************************************/
/*                                                                               */
/* File Name   : MCU_prog.c                                                     */
/*                                                                             */
/* Created on  : Mar 28, 2019                                                 */
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

#include "../STD_TYPES.h"
#include "../include/MCU_interface.h"
#include "../include/MCU_private.h"


/****************************************************************************************************
 * Description:Function responsible for grouping and sub grouping of NVIC priority
 *             through configuring the (SCB) system control block peripheral and AIRCR Register.
 * Outputs    :Error state
 * Inputs     :Copy_u32GpSubGp_PriorityConf : number of groups and  sub groups
 ***************************************************************************************************/
u8 MCU_u8SetGroupSubgroup (u32 Copy_u32GpSubGp_PriorityConf)
{
	/* Local Variable indication for Error status                                                                     */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                                                                                     */
	if ((Copy_u32GpSubGp_PriorityConf < MCU_u32_SCB_AIRCR_PRIORITY_16GP_0SUB) && (Copy_u32GpSubGp_PriorityConf > MCU_u32_SCB_AIRCR_PRIORITY_0GP_16SUB))
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		MCU_u32_SCB_AIRCR = Copy_u32GpSubGp_PriorityConf;
	}
	/* Function Return                                                                                               */
	return Local_u8Error;
}
