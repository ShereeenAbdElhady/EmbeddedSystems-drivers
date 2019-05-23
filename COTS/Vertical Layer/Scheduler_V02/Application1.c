/**********************************************************************************/
/*                                                                               */
/* File Name   : Application1.c                                                 */
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
#include "../include/Application1.h"

/*create an object (task) of a Task type structure                            */
const Task_type Task1 = {
		APP1_VidFunc,
		//1 sec
		1000,
		//priority
		0,
		//offset
		0
};

/********************************************************************************************************
 * Description: Function to initialize the first task tick, Priority and offset number
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
void APP1_VidInitialize(void)
{
	//Task1.Runnable = APP1_VidFunc;
	//Task1.Periodicity   = 1000;
	//Task1.Priority = 0;
	//Task1.Offset = 1000;
	/*passing the address of task1(structure) to array of pointers to structures*/
	OS_u8CreateTask(&Task1);
	//OS_u8Delete(&Task1);
}


/********************************************************************************************************
 * Description: First Task implementation is to toggle LED
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
void APP1_VidFunc(void)
{
	static u8 flag=0;
	if (flag == 0)
	{
		DIO_u8SetPinValue (DIO_u8_PIN34, DIO_u8_PIN_HIGH);
		flag = 1;
	}
	else
	{
		DIO_u8SetPinValue (DIO_u8_PIN34, DIO_u8_PIN_LOW);
		flag = 0;
	}
}
