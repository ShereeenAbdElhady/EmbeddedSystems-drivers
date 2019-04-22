/**********************************************************************************************/
/*                                                                                           */
/* File Name   : SysTick_config.h                                                           */
/*                                                                                         */
/* Created on  : Apr 22, 2019                                                             */
/*                                                                                       */
/* Author      : shereen Abd Elhady                                                     */
/*                                                                                     */
/* Version     : V01                                                                  */
/*                                                                                   */
/* Description : configuration file for systick timer driver contains               */
/*               the initial conditions which initiates the systick timer interrupt*/
/*               driver according to the customer desire                          */
/*                                                                               */
/* Layer       : MCAL                                                           */
/*******************************************************************************/

#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_

/*The configurator will configure the system clock frequency according to his desire  */
#define CPU_CLK_FREQ          (f64)8000000.0

/*structure to configure the initial state of systick prescaler and interruopt state   */
SysTickConfigurations_type SysTickInitialConfig =
{
		SYSTICK_u8_CLKSOURCE_AHB_DIVIDED_8,
		SYSTICK_u8_TICKINT_ENABLE
};


#endif /* SYSTICK_CONFIG_H_ */
