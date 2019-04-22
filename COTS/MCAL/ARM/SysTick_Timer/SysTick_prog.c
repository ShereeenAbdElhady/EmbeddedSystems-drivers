/**********************************************************************************/
/*                                                                               */
/* File Name   : SysTick_prog.c                                                 */
/*                                                                             */
/* Created on  : Apr 22, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V01                                                      */
/*                                                                       */
/* Description : software driver for systick timer                      */
/*                                                                     */
/*               with a defined public and private functions.         */
/*                                                                   */
/* Layer       : MCAL                                               */
/*******************************************************************/


#include "../STD_TYPES.h"
#include "../include/SysTick_interface.h"
#include "../include/SysTick_config.h"

/* pointer to function will carry the address of the function wanted to be implemented by the ISR                             */
/* Initialize the pointer with Null in the beginning to avoid this pointer from garbage value and implementation of wrong code*/
/* Global & Static to be seen within this file only                                                                           */
static Callback_type SysTick_CallbackPtrFunc = NULL;

/**************************************************************************************************
 * Description: Function to configure the systick timer clock prescaler whether it's gonna be
 *              AHB or AHB/8 processor clock, also to enable the systick exception request.
 * Outputs   :  None
 * Inputs    :  None
 **************************************************************************************************/
extern void SysTick_VidInit(void)
{
	/*configure the systick timer clk with AHB/8                             */
	SYSTICK_u32_CTRL = SysTickInitialConfig.Clock_Prescaler;
	/*enable the systick timer exception                                     */
	SYSTICK_u32_CTRL = SysTickInitialConfig.Interrupt_State;
	return;
}


/**************************************************************************************************
 * Description: Function to enable the systick timer to load the reload value from the load register
 *              and then counts down.
 * Outputs   :  None
 * Inputs    :  None
 **************************************************************************************************/
extern void SysTick_VidEnable (void)
{
	/*Enable the systick timer                                                         */
	SYSTICK_u32_CTRL |= (1 << SYSTICK_u8_CTRL_ENABLE);
	return;
}


/**************************************************************************************************
 * Description: Function to enable the systick timer
 * Outputs   :  None
 * Inputs    :  None
 **************************************************************************************************/
extern void SysTick_VidDisable (void)
{
	/*Disable the systick timer                                                         */
	SYSTICK_u32_CTRL &= (~(1 << SYSTICK_u8_CTRL_ENABLE));
	return;
}


/**************************************************************************************************
 * Description: Function to calculate the reload value in case of the desired time was in milli seconds
 *              and  load the reload value to the load register.
 *              and then counts down.
 * Outputs   :  None
 * Inputs    :  Copy_u16TimeMilliSec : desired time milli second
 **************************************************************************************************/
void SysTick_VidSetTickTimeMilliSecond(u16 Copy_u16TimeMilliSec)
{
	/*Local variable to hold the tick time of the Systick timer                                      */
	f64 Local_f64SysTickTime = 0;
	/*local variable to hold the number of counts to be put in the LOAD reg to reach the desired time*/
	u32 Local_u32ReloadValue =0;
	/*if the clock source has a prescaler one                                                        */
	if(SysTickInitialConfig.Clock_Prescaler == SYSTICK_u8_CLKSOURCE_AHB)
	{
		/*tick time of systick = 1/frequency                                                         */
		Local_f64SysTickTime = (1.0 / CPU_CLK_FREQ);
	}
	/*if the clock source has a prescaler eight                                                      */
	else
	{
		/*tick time of systick = 1/(frequency/8)                                                     */
		Local_f64SysTickTime = (1.0 / (CPU_CLK_FREQ/8));
	}
	/*Calculating reload value                                                                       */
	Local_u32ReloadValue = ((Copy_u16TimeMilliSec/Local_f64SysTickTime) * 0.001);
	/*set the LOAD REG with the reload value                                                         */
	SYSTICK_u32_LOAD = Local_u32ReloadValue;
	return;
}



/**************************************************************************************************
 * Description: Function to calculate the reload value in case of the desired time was in micro seconds
 *              and  load the reload value to the load register.
 *              and then counts down.
 * Outputs   :  None
 * Inputs    :  Copy_u16TimeMicroSec : desired time micro second
 **************************************************************************************************/
void SysTick_VidSetTickTimeMicroSecond(u16 Copy_u16TimeMicroSec)
{
	/*Local variable to hold the tick time of the Systick timer                                      */
	f64 Local_f64SysTickTime = 0;
	/*local variable to hold the number of counts to be put in the LOAD reg to reach the desired time*/
	u32 Local_u32ReloadValue =0;
	/*if the clock source has a prescaler one                                                        */
	if(SysTickInitialConfig.Clock_Prescaler == SYSTICK_u8_CLKSOURCE_AHB)
	{
		/*tick time of systick = 1/frequency                                                         */
		Local_f64SysTickTime = (1.0 / CPU_CLK_FREQ);
	}
	/*if the clock source has a prescaler eight                                                      */
	else
	{
		/*tick time of systick = 1/(frequency/8)                                                     */
		Local_f64SysTickTime = (1.0 / (CPU_CLK_FREQ/8));
	}
	/*Calculating reload value                                                                       */
	Local_u32ReloadValue = ((Copy_u16TimeMicroSec/Local_f64SysTickTime) * 0.000001);
	/*set the LOAD REG with the reload value                                                         */
	SYSTICK_u32_LOAD = Local_u32ReloadValue;
	return;
}


/****************************************************************************************************
 * Description:Function to Set the pointer to callback function with the address of the function
 *              Needed to be implemented by the ISR.
 * Outputs   : None
 * Inputs    : Copy_PVidFunCallback: pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR.
 ***************************************************************************************************/
extern void SysTick_VidSetCallback(Callback_type Copy_PVidFunCallback)
{
	if(Copy_PVidFunCallback != NULL)
	{
		/* Set the pointer with address of the function needed to be implemented by the ISR  */
		SysTick_CallbackPtrFunc = Copy_PVidFunCallback;
	}
	return;
}


/****************************************************************************************************
 * Description:SysTick timer Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :None
 * Inputs     :None
 ***************************************************************************************************/
void SysTick_Handler (void)
{
	/* Pointer validation                                   */
	if (SysTick_CallbackPtrFunc != NULL)
	{
		/* ISR of SysTick Function calling                  */
		SysTick_CallbackPtrFunc();
	}
	return;
}
