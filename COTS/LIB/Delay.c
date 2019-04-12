/*
 * File Name:Delay.c
 * Description: Delay functions' definitions in milli second and micro second
 *  Created on: Jan 25, 2019
 *  Author: shereen
 */
#include"STD_TYPES.h"
#include "DIO_private.h"
extern void delay_milliSecond(u32 value)
{

	 /* to calculate T1 (function context switching while jumping to the function) */
	  //DIO_u8_PD1 = 0X00;

	/* will now calculate the T3 (calculations(Arithmetic) time on PD3 --> approx 92 micro */
	//DIO_u8_PD3 = 0x01;
	 //u32 i;
	 u32 no_counts;
	 /* value = (value*1000m) - T1-T2-T3 */
	no_counts= ((value*1000)-250)/4.75;                                  /* no of counts = value/loop time */
	//DIO_u8_PD3 = 0x00;

	/* we will calculate the loop time for one iteration on PD4 --> approx 5.0 micro per iteration*/
	//DIO_u8_PD4 = 0x01;
	//no_counts = ((value*1000)-19)/10.7;
	for(;no_counts>0;no_counts--)
	{
		asm("NOP");
		asm("NOP");
	    asm("NOP");
		asm("NOP");
	}
	//DIO_u8_PD4 = 0x00;

	/* will now calculate the time for context switch OUT on PD2 --> approx 2.275 = 3 micro */
	/*to calculate T2 (time of context switching while returning from the function) */
	 // DIO_u8_PD2 = 0x01;
}

/*
extern void delay_microSecond(u32 value)
{

	 /* to calculate T1 (function context switching while jumping to the function) */
	  //PD1 = 0X00;

	/* will now calculate the T3 (calculations(Arithmetic) time on PD3 --> approx 28 micro */
	//PD3 = 0x01;
	//u32 no_counts;
     /* value = (value usec) - T1-T2-T3 */
	//no_counts= (value - 99)/5;                                     /* no of counts = value/loop time */
	//PD3 = 0x00;

	/* we will calculate the loop time for one iteration on PD4 --> approx 2.6 micro per iteration*/
	  //PD4 = 0x01;
	//for(;no_counts>0;no_counts--)
	//{
		//asm("NOP");
	//}
	//PD4 = 0x00;

	/* will now calculate the time for context switch OUT on PD2 --> approx 1.40 micro */
	/*to calculate T2 (time of context switching while returning from the function) */
	  //PD2 = 0x01;
//}

