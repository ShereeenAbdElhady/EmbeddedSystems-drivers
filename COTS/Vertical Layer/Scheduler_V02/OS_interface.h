/**********************************************************************************/
/*                                                                               */
/* File Name   : OS_interface.h                                                 */
/*                                                                             */
/* Created on  : May 20, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V02                                                      */
/*                                                                       */
/* Description : scheduler implementation using systick timer of        */
/*               STM32F103C8 ARM Microcontroller.                      */
/*This file includes 2 structure one contains Tasks information       */
/*The another one contains a pointer to the first structure and the  */
/*time remains for execution                                        */
/*                                                                 */
/* Layer       : vertical layer                                   */
/*****************************************************************/

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

/*Note: every task is a structure                                                                          */
/*Periodicity : Task repeated every period of time                                                         */
/*Tick Time: scheduler comes every tick time                                                               */
/*Offset Time: Task starts to run after offset time                                                        */

/*Structure describes the features of each Task                                                            */
typedef struct
{
	/*Runnable of type pointer to function points to the running function                                  */
	Callback_type Runnable;
	/*The task runs periodically each specified time by milli second                                       */
	u16 Periodicity;
	/*Priority of Task by setting the index of the array of tasks(the lower the index the  higher the priority)*/
	u8 Priority;
	/*Task will start running after a certain delay represented by the offset number in milli second       */
	u16 Offset;
}Task_type;


/*Structure includes task's information & the time remains to execute this task                            */
typedef struct
{
	/*Pointer to Task structure to access the Task's information                                           */
	Task_type *Task;
	/*Time remains to execute this task and this variable gonna be used by the scheduler to handle tasks'  */
	/*Execution (instead of the counter variable in v01) to let every task executed starting from offset   */
	/*And repeated periodically according to their periodicity                                             */
	u16 RemainTimeToExecute;
	/*status of task whether it is an active task or suppressed                                            */
	u8 TaskStatus;
}SysTasks_type;

/*Tick time at which the ISR comes and we call the scheduler (scheduler comes each tick time)             */
#define OS_u16_SCHEDULER_TICK_TIME     (u16)1000

/*Number of tasks could be handled by the scheduler                                                       */
#define OS_u8_SCHEDULER_TASKS_NUM      (u8)2

/*Definitions for the task status whether it is an active task or deleted task                            */
#define OS_u8_TASK_ACTIVE_STATUS       (u8)3
#define OS_u8_TASK_SUPPRESSED_STATUS   (u8)4

/*Flag's  values definitions                                                                             */
#define OS_u8_FLAG_TRUE                (u8)1
#define OS_u8_FLAG_FALSE               (u8)0

                               /*******APIs Prototypes ********/

/********************************************************************************************************
 * Description: Function to initialize the systick with the time after which the ISR will be implemented
 *              And to set the callback to the scheduler to be implemented.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
extern void OS_VidInitialize(void);


/********************************************************************************************************
 * Description: Function to start the OS by enabling the systick timer
 *              Take care this function must be called after the OS_VidInit function.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
extern void OS_VidStart(void);


/********************************************************************************************************
 * Description: Function to enqueue task in the scheduler queue by inserting it's address
 *              in the array of pointers to Systasks and adjusting it's position in the array according
 *              to it's priority.
 *              Also to set the time remains to execute by offset value to control the starting point
 *              of this  task.
 * Outputs   :  Error state
 * Inputs    :  const Task_type* Copy_PtrTask: pointer to task structure
 *******************************************************************************************************/
extern u8 OS_u8CreateTask(const Task_type* Copy_PtrTask);


/********************************************************************************************************
 * Description: Function to pause a task for multiple time of periodicity time
 *              This function is called inside  task code.
 * Outputs   :  Error state
 * Inputs    :  const Task_type* Copy_PtrTask: pointer to task structure
 *              u8 Copy_u8TimesOfPause: Number of times to pause a task (pause is multiple of periodicity)
 *******************************************************************************************************/
extern u8 OS_u8Pause (u8 Copy_u8TimesOfPause ,const Task_type* Copy_PtrTask);


/********************************************************************************************************
 * Description: Function to delete a task by making the runnable setting it's index in the queue
 *              with NULL and change the task state
 * Outputs   :  Error state
 * Inputs    :  const Task_type* Copy_PtrTask: pointer to task structure
 *******************************************************************************************************/
extern u8 OS_u8Delete(const Task_type* Copy_PtrTask);


/********************************************************************************************************
 * Description: scheduler function to handle the tasks' execution according to it's periodicity time
 *              and offset time.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
static void OS_VidScheduler (void);


/********************************************************************************************************
 * Description: Function to set the scheduler's flag to call the scheduler
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
static void OS_VidSetOsFlag (void);


/********************************************************************************************************
 * Description: Function to call the scheduler if the OSFlag equals to one, based on the ISR descision
 *              Here the scheduler is in thread mode, so it can be interrupted.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
extern void OS_VidStartScheduler (void);


#endif /* OS_INTERFACE_H_ */
