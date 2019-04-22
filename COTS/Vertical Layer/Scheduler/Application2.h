/**********************************************************************************/
/*                                                                               */
/* File Name   : Application2.h                                                 */
/*                                                                             */
/* Created on  : Apr 22, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V01                                                      */
/*                                                                       */
/* Description : second task to be implemented by the scheduler          */
/*                                                                     */
/* Layer       : APP layer                                            */
/*********************************************************************/

#ifndef APPLICATION2_H_
#define APPLICATION2_H_


/********************************************************************************************************
 * Description: Function to initialize the second task tick, Priority and offset number
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
void APP2_VidInitialize(void);


/********************************************************************************************************
 * Description: second Task implementation is to toggle LED
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
void APP2_VidFunc(void);


#endif /* APPLICATION2_H_ */
