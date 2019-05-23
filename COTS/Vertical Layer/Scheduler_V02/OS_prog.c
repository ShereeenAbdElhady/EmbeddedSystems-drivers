/**********************************************************************************/
/*                                                                               */
/* File Name   : OS_prog.c                                                      */
/*                                                                             */
/* Created on  : May 20, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V02                                                      */
/*                                                                       */
/* Description : scheduler implementation using systick timer of        */
/* STM32F103C8 ARM Microcontroller to handle tasks according to their  */
/* Priority, periodicity, offset.                                     */
/*                                                                   */
/* Layer       : vertical layer                                     */
/*******************************************************************/

#include "../STD_TYPES.h"
#include "../include/SysTick_interface.h"
#include "../include/OS_interface.h"

/*Note: every task is a structure                                                                       */
/*Periodicity : Task repeated every period of time                                                      */
/*Tick Time: scheduler comes every tick time                                                            */
/*Offset Time: Task starts to run after offset time                                                     */

/* Queue of tasks in which we will register each task in the scheduler queue                            */
/* creating array of Systasks(structures)                                                               */
static SysTasks_type OS_ArrayPtrSysTasks[OS_u8_SCHEDULER_TASKS_NUM] ;

/*Modification in this version : we gonna set the flag only in the ISR instead of executing the whole  */
/*Scheduler in the ISR to decrease the ISR time(handler mode time), and we gonna call the scheduler    */
/*In a separate function based on the flag value ( means that the scheduler will be in thread mode)    */
/*The reason why we want to decrease the ISR time is we want to serve any upcoming interrupt           */
/*We don't want to let any upcoming interrupt to wait in the pending state for a long time             */
/*static global variable responsible for calling the scheduler                                         */
static u8 OSFlag = 0;

/********************************************************************************************************
 * Description: Function to initialize the systick with the time after which the ISR will be implemented
 *              And to set the callback to the scheduler to be implemented.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
extern void OS_VidInitialize(void)
{
	/*Time to generate an interrupt through systick timer (Tick time)                                  */
	SysTick_VidSetTickTimeMilliSecond(OS_u16_SCHEDULER_TICK_TIME);
	/*Set the callback with the address of the function Needed to be implemented by the ISR            */
	SysTick_VidSetCallback(& OS_VidSetOsFlag);
	return ;
}


/********************************************************************************************************
 * Description: Function to start the OS by enabling the systick timer
 *              Take care this function must be called after the OS_VidInit function.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
extern void OS_VidStart(void)
{
	/*Enable systick timer                                                                           */
	SysTick_VidEnable ();
	return ;
}


/********************************************************************************************************
 * Description: Function to enqueue task in the scheduler queue by inserting it's address
 *              in the array of pointers to Systasks and adjusting it's position in the array according
 *              to it's priority.
 *              Also to set the time remains to execute by offset value to control the starting point
 *              of this  task.
 * Outputs   :  Error state
 * Inputs    :  const Task_type* Copy_PtrTask: pointer to task structure
 *******************************************************************************************************/
extern u8 OS_u8CreateTask(const Task_type* Copy_PtrTask)
{
	/* Local Variable indication for Error status                                                      */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/*Priority of task must be less than the maximum number of tasks in the queue                      */
	if ( (Copy_PtrTask != NULL) && ((Copy_PtrTask->Priority) < (OS_u8_SCHEDULER_TASKS_NUM)) )
	{
		/*storing the address of the new task in the array of pointers to tasks in it's index(priority)*/
		OS_ArrayPtrSysTasks[Copy_PtrTask->Priority].Task =  Copy_PtrTask;
		/*We decrease the CPU load using offset method                                                 */
		OS_ArrayPtrSysTasks[Copy_PtrTask->Priority].RemainTimeToExecute = ((Copy_PtrTask->Offset) / (OS_u16_SCHEDULER_TICK_TIME));
		/*Change Task status to Active indication for the creation of this task                        */
		OS_ArrayPtrSysTasks[Copy_PtrTask->Priority].TaskStatus = OS_u8_TASK_ACTIVE_STATUS ;
	}
	else
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return                                                                                 */
	return Local_u8Error;
}


/********************************************************************************************************
 * Description: Function to pause a task for multiple time of periodicity time
 *              This function is called inside  task code.
 * Outputs   :  Error state
 * Inputs    :  const Task_type* Copy_PtrTask: pointer to task structure
 *              u8 Copy_u8TimesOfPause: Number of times to pause a task (pause is multiple of periodicity)
 *******************************************************************************************************/
extern u8 OS_u8Pause (u8 Copy_u8TimesOfPause ,const Task_type* Copy_PtrTask)
{
	/* Local Variable indication for Error status                                                      */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/*Priority of task must be less than the maximum number of tasks in the queue                      */
	if ( (Copy_PtrTask != NULL) && ((Copy_PtrTask->Priority) < (OS_u8_SCHEDULER_TASKS_NUM)) )
	{
		/*if the task is already registered in the queue                                              */
		if ((OS_ArrayPtrSysTasks[Copy_PtrTask->Priority].Task)!= (NULL))
		{
			/*Here we doubled remain time to execute time, to pause the task multiple of periodicity  */
			OS_ArrayPtrSysTasks[Copy_PtrTask->Priority].RemainTimeToExecute = ( (Copy_u8TimesOfPause) * ((Copy_PtrTask->Periodicity) / (OS_u16_SCHEDULER_TICK_TIME)) );
		}
	}
	else
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return                                                                                 */
	return Local_u8Error;
}


/********************************************************************************************************
 * Description: Function to delete a task by making the runnable setting it's index in the queue
 *              with NULL and change the task state
 * Outputs   :  Error state
 * Inputs    :  const Task_type* Copy_PtrTask: pointer to task structure
 *******************************************************************************************************/
extern u8 OS_u8Delete(const Task_type* Copy_PtrTask)
{
	/* Local Variable indication for Error status                                                      */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/*Priority of task must be less than the maximum number of tasks in the queue                      */
	if ( (Copy_PtrTask != NULL) && ((Copy_PtrTask->Priority) < (OS_u8_SCHEDULER_TASKS_NUM)) )
	{
		/*if the task is already registered in the queue                                              */
		if (OS_ArrayPtrSysTasks[Copy_PtrTask->Priority].Task != NULL)
		{
			/*Delete this Task by making it's place in the queue equal to NULL                       */
			OS_ArrayPtrSysTasks[Copy_PtrTask->Priority].Task = NULL;
			/*Change Task status to suppressed indication for the removal of this task               */
			OS_ArrayPtrSysTasks[Copy_PtrTask->Priority].TaskStatus = OS_u8_TASK_SUPPRESSED_STATUS ;
		}
	}
	else
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return                                                                                 */
	return Local_u8Error;
}


/********************************************************************************************************
 * Description: Function to call the scheduler if the OSFlag equals to one, based on the ISR descision
 *              Here the scheduler is in thread mode, so it can be interrupted.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
extern void OS_VidStartScheduler (void)
{
	while (1)
	{
		/*If OSFlag is true then call the scheduler, based on the Timer callback decision             */
		if (OS_u8_FLAG_TRUE == OSFlag)
		{
			/* Call the scheduler                                                                     */
			OS_VidScheduler ();
			/*Set flag with zero as an indication that the scheduler has just finished it's job       */
			OSFlag = OS_u8_FLAG_FALSE;
		}
	}
	return ;
}


/********************************************************************************************************
 * Description: scheduler function to handle the tasks' execution according to it's periodicity time
 *              and offset time.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
static void OS_VidScheduler (void)
{
	/*local variable represents task index used by for loop to loop through the tasks                   */
	u8 Local_u8TaskIndex=0;
	/*The scheduler will go through each task and check for it's remain time to execute                 */
	/*If it is equal to zero it will be executed, if it is more than zero the scheduler will            */
	/*decrement the remain time till it recheas zero                                                    */
	for( Local_u8TaskIndex=0 ; Local_u8TaskIndex < OS_u8_SCHEDULER_TASKS_NUM ; Local_u8TaskIndex++)
	{
		/*if the task is already registered in the queue and it's status is active state                */
		if ( (OS_ArrayPtrSysTasks[Local_u8TaskIndex].Task != NULL) && (OS_ArrayPtrSysTasks[Local_u8TaskIndex].TaskStatus == OS_u8_TASK_ACTIVE_STATUS) )
		{
			/*call the runnable task if it meets it's periodicity and offset time                        */
			if (OS_ArrayPtrSysTasks[Local_u8TaskIndex].RemainTimeToExecute == 0)
			{
				/*set the remain time with the periodicity of task                                       */
				OS_ArrayPtrSysTasks[Local_u8TaskIndex].RemainTimeToExecute = ((OS_ArrayPtrSysTasks[Local_u8TaskIndex].Task->Periodicity) / (OS_u16_SCHEDULER_TICK_TIME));
				/* Call the Runnable Task                                                                */
				OS_ArrayPtrSysTasks[Local_u8TaskIndex].Task->Runnable();
			}
			/*decrement the remain time we decrement it by tick till it reaches zero                         */
			/*kda kol remain b tickya f ana 3wza agy l scheduler da 3dd mn l ticks l7d ma awsl ll period time*/
			OS_ArrayPtrSysTasks[Local_u8TaskIndex].RemainTimeToExecute --;
		}
	}
	return ;
}


/********************************************************************************************************
 * Description: Function to set the scheduler's flag to call the scheduler
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
static void OS_VidSetOsFlag (void)
{
	/*If flag equal false, this means that the scheduler has been executed (! false = true)             */
	if(!OSFlag)
	{
		OSFlag = OS_u8_FLAG_TRUE;
	}
	/* else
	 * {   this means that the (CPU load > 100 %)
	 * as the timer's ISR comes & still the scheduler not finshed it's work yet
	 * tick time > execution time
	 * }*/
}
