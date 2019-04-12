/**********************************************************************************/
/*                                                                               */
/* File Name   : NVIC_prog.c                                                    */
/*                                                                             */
/* Created on  : Mar 28, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V01                                                      */
/*                                                                       */
/* Description : software driver for nested vector interrupt controller */
/*                                                                     */
/*               with a defined public and private functions for the  */
/*               For STM32F103C8 ARM Microcontroller.                */
/*                                                                  */
/* Layer       : MCAL                                              */
/******************************************************************/


#include "../STD_TYPES.h"
#include "../BIT_CALC.h"
#include "../include/MCU_interface.h"
#include "../include/MCU_private.h"
#include "../include/NVIC_interface.h"
#include "../include/NVIC_private.h"


/***********************************************************************************************************
 * Description: Function to Set or clear External interrupt enable through NVIC_ISER & NVIC_ICER Registers.
 * Outputs   :                   Error State
 * Inputs    : u8 Copy_u8InterruptNumber:  Interrupt Number
 *             Copy_u8InterruptStatus   : Interrupt status whether it is enabled or disabled.
 **********************************************************************************************************/
u8 NVIC_u8SetClearInterruptEnable (u8 Copy_u8InterruptNumber , u8 Copy_u8InterruptStatus)
{
	/* Local Variable indication for Error status                                                                    */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Local Variable to map a register number to know this interrupt lies in which register                         */
	u8 Local_u8RegNb = Copy_u8InterruptNumber / NVIC_u8_NUM_BITS_PER_REG ;
	/* Local Variable to map a bit number to know this interrupt corresponds to which bit in the register            */
	u8 Local_u8BitNb = Copy_u8InterruptNumber % NVIC_u8_NUM_BITS_PER_REG;
	/* Check the interrupt enable status                                                                             */
	switch(Copy_u8InterruptStatus)
	{
	/* in case of enable set the corresponding bit in the ISER register with one                                     */
	case NVIC_u8_INTERRUPT_ENABLE:  NVIC_u32_ISER[Local_u8RegNb] = 1<< Local_u8BitNb;
	break;
	/* in case of disable set the corresponding bit in the ICER register with one                                    */
	case NVIC_u8_INTERRUPT_DISABLE: NVIC_u32_ICER[Local_u8RegNb] = 1<< Local_u8BitNb;
	break;
	/* Neither enable nor disable return an error and this is considered as input validation checking                */
	default: Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	break;
	}
	/* Function Return                                                                                               */
	return Local_u8Error;
}




/*****************************************************************************************************************
 * Description: Function to Set or clear External interrupt pending flag through NVIC_ISPR & NVIC_ICPR Registers.
 * Outputs   :                   Error State
 * Inputs    : u8 Copy_u8InterruptNumber:  Interrupt Number
 *             Copy_u8PendingStatus   : Interrupt pending status whether it is pending or not.
 ****************************************************************************************************************/
u8 NVIC_u8SetClearInterruptPending (u8 Copy_u8InterruptNumber , u8 Copy_u8PendingStatus)
{
	/* Local Variable indication for Error status                                                                    */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Local Variable to map a register number to know this interrupt lies in which register                         */
	u8 Local_u8RegNb = Copy_u8InterruptNumber / NVIC_u8_NUM_BITS_PER_REG ;
	/* Local Variable to map a bit number to know this interrupt corresponds to which bit in the register            */
	u8 Local_u8BitNb = Copy_u8InterruptNumber % NVIC_u8_NUM_BITS_PER_REG;
	/* Check the interrupt pending status                                                                            */
	switch(Copy_u8PendingStatus)
	{
	/* in case of pending set the corresponding bit in the ISPR register with one                                    */
	case NVIC_u8_INTERRUPT_PENDING:     NVIC_u32_ISPR[Local_u8RegNb] = 1<< Local_u8BitNb;
	break;
	/* in case of not pending set the corresponding bit in the ICPR register with one                                */
	case NVIC_u8_INTERRUPT_NOT_PENDING: NVIC_u32_ICPR[Local_u8RegNb] = 1<< Local_u8BitNb;
	break;
	/* Neither pending nor not pending return an error and this is considered as input validation checking           */
	default: Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	break;
	}
	/* Function Return                                                                                               */
	return Local_u8Error;
}



/**************************************************************************************************
 * Description: Function to Select the External interrupt priority through NVIC_IPR Registers.
 * Outputs   :                   Error State
 * Inputs    : u8 Copy_u8InterruptNumber:   Interrupt Number
 *             Copy_u8InterruptPriority   : Interrupt Priority.
 **************************************************************************************************/
u8 NVIC_u8SetInterruptPriority (u8 Copy_u8InterruptNumber , u8 Copy_u8InterruptPriority)
{
	/* Local Variable indication for Error status                                                                     */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Local Variable to map the IPR register number to know this interrupt lies in which register                    */
	u8 Local_u8IPR_RegNb = Copy_u8InterruptNumber / NVIC_u8_NUM_INT_PER_IPR_REG ;
	/* Local Variable to map the IPR Offset number to know this interrupt corresponds to which offset in this register*/
	u8 Local_u8OffsetNb = Copy_u8InterruptNumber % NVIC_u8_NUM_INT_PER_IPR_REG;
	/* Input arguments validation                                                                                     */
	if (Copy_u8InterruptNumber >= NVIC_u8_MAX_NUM_EXT_INT)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Set the priority value in the corresponding IPR register and the corresponding Offset (most 4 bits)            */
	/* number of offset * 8 as each offset is 8 bits and we shift by offset                                           */
	else
	{
		//NVIC_u32_IPR[Local_u8IPR_RegNb] = ((Copy_u8InterruptPriority << Local_u8OffsetNb * NVIC_u8_NUM_BITS_PER_OFFSET)<< NVIC_u8_NUM_IPR_OFFSET_SHIFT_BITS);
		NVIC_u32_IPR[Local_u8IPR_RegNb] = ((Copy_u8InterruptPriority) << ((Local_u8OffsetNb * NVIC_u8_NUM_BITS_PER_OFFSET)+ NVIC_u8_NUM_IPR_OFFSET_SHIFT_BITS));
	}
	/* Function Return                                                                                                */
	return Local_u8Error;
}
