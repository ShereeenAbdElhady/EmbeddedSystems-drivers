/**********************************************************************************/
/*                                                                               */
/* File Name   : Application2.c                                                 */
/*                                                                             */
/* Created on  : May 20, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V02                                                      */
/*                                                                       */
/* Description : first task to be implemented by the scheduler          */
/*                                                                     */
/* Layer       : APP layer                                            */
/*********************************************************************/

#include "../STD_TYPES.h"
#include "../include/DIO_interface.h"
#include "../include/OS_interface.h"
#include "../include/Application2.h"

/*create an object (task) of a Task type structure                            */
const Task_type Task2 = {
		APP2_VidFunc,
		// 2 sec
		1000,
		//priority
		1,
		//offset 1 sec
		0
};

/********************************************************************************************************
 * Description: Function to initialize the second task tick, Priority and offset number
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
void APP2_VidInitialize(void)
{
	//Task2.Runnable = APP2_VidFunc;
	//Task2.Periodicity = 2000;
	//Task2.Priority = 1;
	//Task2.Offset = 1000;
	/*passing the address of task2(structure) to array of structures*/
	OS_u8CreateTask(&Task2);
}


/********************************************************************************************************
 * Description: second Task implementation is to toggle LED
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
void APP2_VidFunc(void)
{
	static u8 flag=0;
	if (flag == 0)
	{
		DIO_u8SetPinValue (DIO_u8_PIN33, DIO_u8_PIN_HIGH);
		flag = 1;
	}
	else
	{
		DIO_u8SetPinValue (DIO_u8_PIN33, DIO_u8_PIN_LOW);
		flag = 0;
	}
	OS_u8Pause (5 ,&Task2);
}
