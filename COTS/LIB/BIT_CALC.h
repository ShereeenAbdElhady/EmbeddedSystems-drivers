/**********************************************************************************/
/* File Name   : BIT_CALC.h                                                      */
/*                                                                              */
/* Created on  : Dec 1, 2018                                                   */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V01                                                       */
/*                                                                        */
/* Description : Commonly used MACROS which performs different operations*/
/*               on any BIT in any register.                            */
/*                                                                     */
/**********************************************************************/


/*This is preprocessor (Header file) guard  */
#ifndef BIT_CALC_H_
#define BIT_CALC_H_

/******************************************************************/
/* This macro sets a certain bit in any variable                 */
/* input : VAR: variable to be changed                          */
/*         BIT_NO: number of the bit to be set                 */
/**************************************************************/
#define BITCALC_SET_BIT(VAR,BIT_NO) ((VAR)|=(1<<(BIT_NO)))                               //4 cycles  improve to 2 cycles


/**************************************************************/
/*This macro clears a certain bit in any variable            */
/* input : VAR: variable to be changed                      */
/*         BIT_NO: number of the bit to be cleared         */
/**********************************************************/
#define BITCALC_CLEAR_BIT(VAR,BIT_NO) ((VAR)&=(~(1<<(BIT_NO))))                          //5 cycles improve to 3 cycles


/************************************************************/
/*This macro toggles a certain bit in any variable         */
/* input : VAR: variable to be changed                    */
/*         BIT_NO: number of the bit to be toggle        */
/********************************************************/
#define BITCALC_TOGGLE_BIT(VAR,BIT_NO) ((VAR)^=(1<<(BIT_NO)))                            //4 cycles improve to 2 cycles


/*********************************************************/
/*This macro assign a certain bit in any variable       */
/* input : VAR: variable to be changed                 */
/*         BIT_NO: number of the bit to be assign     */
/*        VAL: value of bit to assign the macro with */
/****************************************************/
/*if VAL == 1 assign the bit with 1 value otherwise assign it with 0 value */
#define VAL 1
#define BITCALC_ASSIGN_BIT(VAR,BIT_NO,VAL) VAR=((VAR)&(~(1<<(BIT_NO))))|(VAL<<(BIT_NO))  //7 cycles improve to 2 cycles


/********************************************************/
/*This macro to get a certain bit in any variable      */
/* input : VAR: variable value                        */
/*         BIT_NO: number of the bit to get          */
/****************************************************/
//#define BITCALC_GET_BIT(VAR,BIT_NO) ((VAR)&(1<<BIT_NO))!=0 ? (printf("%d",1)):(printf("%d",0))
#define BITCALC_GET_BIT(VAR,BIT_NO) ((VAR)>>(BIT_NO))&(0X01)

/*******************************************************/
/*This macro to set the high nibble in any variable   */
/* input : VAR: variable value                       */
/****************************************************/
#define BITCALC_SET_HIGH_NIBBLE(VAR) ((VAR)|=(0xF0))


/******************************************************/
/*This macro to set the low nibble in any variable   */
/* input : VAR: variable value                      */
/***************************************************/
#define BITCALC_SET_LOW_NIBBLE(VAR) ((VAR)|=(0x0F))


/*********************************************************/
/*This macro to clear the high nibble in any variable   */
/* input : VAR: variable value                         */
/******************************************************/
#define BITCALC_CLEAR_HIGH_NIBBLE(VAR) ((VAR)&=(0x0F))


/*********************************************************/
/*This macro to clear the low nibble in any variable    */
/* input : VAR: variable value                         */
/******************************************************/
#define BITCALC_CLEAR_LOW_NIBBLE(VAR) ((VAR)&=(0xF0))


/*********************************************************/
/*This macro to toggle the high nibble in any variable  */
/* input : VAR: variable value                         */
/******************************************************/
#define BITCALC_TOGGLE_HIGH_NIBBLE(VAR) ((VAR)^=(0xF0))


/*********************************************************/
/*This macro to toggle the low nibble in any variable   */
/* input : VAR: variable value                         */
/******************************************************/
#define BITCALC_TOGGLE_LOW_NIBBLE(VAR) ((VAR)^=(0x0F))


/*********************************************************/
/*This macro Rotate right(circular right shift) the variable value with specific number of shifts*/
/* input : VAR: variable value                         */
/*          No_SHIFTS: number of shifts               */
/******************************************************/
#define BITCALC_ROR(VAR,NO_SHIFTS) ( VAR= ((VAR)>>(NO_SHIFTS)) | ((VAR)<<(8-(NO_SHIFTS))) )


/**********************************************************/
/*This macro Rotate left(circular left shift) the variable value with specific number of shifts*/
/* input : VAR: variable value                          */
/*          No_SHIFTS: number of shifts                */
/******************************************************/
#define BITCALC_ROL(VAR,NO_SHIFTS) ( VAR= ((VAR)<<(NO_SHIFTS)) | ((VAR)>>(8-(NO_SHIFTS))) )


/*********************************************************/
/*This macro assign any variable with any value         */
/* input : VAR: variable to be changed                 */
/*        VAL: value  to assign the macro with        */
/*****************************************************/
#define BITCALC_ASSIGN_PORT(VAR,VAL) VAR = (((VAR)&(0x00))|(VAL))


/******************************************************/
/*This macro to get value of any variable            */
/* input : VAR: variable value                      */
/****************************************************/
#define BITCALC_GET_PORT(VAR) ((VAR)&(0xFF))!=0X00 ? (printf("%d",VAR)):(printf("%d",0X00))


/********************************************************/
/*This macros to concatenate 8 bits together           */
/*we use these two MACROS to let the object like MACRO*/
/*expands first then the function like MACRO         */
/* input :b0 -> b7: bits values                     */
/***************************************************/
#define BITCALC_CONC_8BIT(b0,b1,b2,b3,b4,b5,b6,b7) BITCALC_CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)
#define BITCALC_CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7) 0b##b7##b6##b5##b4##b3##b2##b1##b0



#endif /* BIT_CALC_H_ */

