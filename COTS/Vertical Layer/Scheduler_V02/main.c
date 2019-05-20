/**********************************************************************************/
/*                                                                               */
/* File Name   : main.c                                                         */
/*                                                                             */
/* Created on  : May 20, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V02                                                      */
/*                                                                       */
/* Description : test scheduler to implement two tasks                  */
/*                                                                     */
/* Layer       : APP layer                                            */
/*********************************************************************/
#include "../STD_TYPES.h"
#include "../BIT_CALC.h"
#include "../include/RCC_interface.h"
#include "../include/DIO_interface.h"
#include "../include/SysTick_interface.h"
#include "../include/OS_interface.h"
#include "../include/Application1.h"
#include "../include/Application2.h"

int main (void)
{
	/* enbale the HSI clock with no prescalar                 */
	RCC_vidinit();
	/* enable PORTC clock                                      */
	RCC_u8EnablePeripheralClock(RCC_u8_GPIOC,RCC_u8_ENABLE_CLK);
	/* set direction of PIN C14 as output                      */
	DIO_u8SetPinDirection( DIO_u8_PIN33  , DIO_u8_PIN_OUTPUT_10MHZ_PUSH_PULL);
	/* set direction of PIN C15 as output                      */
	DIO_u8SetPinDirection( DIO_u8_PIN34  , DIO_u8_PIN_OUTPUT_10MHZ_PUSH_PULL);
	/*systick prescaler and interrupt enable                   */
	SysTick_VidInit();
	/*task settings and create a task                          */
	APP1_VidInitialize();
	APP2_VidInitialize();
	/*initialize systick time and set callback to the scheduler*/
	OS_VidInitialize();
	/*enable systick timer                                     */
	OS_VidStart();
	while (1)
	{

	}
	return 0;
}
