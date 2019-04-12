/*****************************************************************************************************/
/*                                                                                                  */
/* File Name   : RCC_private.h                                                                     */
/*                                                                                                */
/* Created on  : Mar 5, 2019                                                                     */
/*                                                                                              */
/* Author      : shereen Abd Elhady                                                            */
/*                                                                                            */
/* Version     : V02                                                                         */
/*                                                                                          */
/* Description : Private header file for RCC driver contains Registers address definitions */
/*               of STM32F103C8 ARM Micro-Controller.                                     */
/*               Also contains private functions' prototypes                             */
/*               And the MACROS not needed by the upper layers' components.             */
/* Layer        : MCAL                                                                 */
/*                                                                                    */
/*************************************************************************************/


#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/* The Private file includes only the Private configurations from the configuration file */
#include "RCC_config.h"

/*structure to define offset addresses of these registers arranged in a correct way to be */
/* able to get their offset values correctly                                              */
typedef struct
{
	/* CR Address definition (offset address0x00)                                         */
	Register_32Bit CR;
	/* CFGR Address definition (offset address0x04)                                       */
	Register_32Bit CFGR;
	/* CIR Address definition (offset address0x08)                                        */
	Register_32Bit CIR;
	/* APB2RSTR Address definition (offset address0x0C)                                   */
	Register_32Bit APB2RSTR;
	/* APB1RSTR Address definition (offset address0x010)                                  */
	Register_32Bit APB1RSTR;
	/* AHBENR Address definition (offset address0x14)                                     */
	Register_32Bit AHBENR;
	/* APB2ENR Address definition (offset address0x18)                                    */
	Register_32Bit APB2ENR;
	/* APB1ENR Address definition (offset address0x1C)                                    */
	Register_32Bit APB1ENR;
	/* BDCR Address definition (offset address0x20)                                       */
	Register_32Bit BDCR;
	/* CSR Address definition (offset address0x24)                                        */
	Register_32Bit CSR;
}RCC_Type;

/* RCC Base Address definition                                                             */
#define RCC  ((RCC_Type*)0x40021000)

                            /**** RCC_CR Register PINs settings' definitions ****/
/* Enable and Disable values definitions                                                    */
#define RCC_u8_ENABLE         1
#define RCC_u8_DISABLE        0

/* Clock PINs definitions                                                                   */
#define RCC_u8_HSION_PIN      0
#define RCC_u8_HSIRDY_PIN     1
#define RCC_u8_HSEON_PIN      16
#define RCC_u8_HSERDY_PIN     17
#define RCC_u8_PLLON_PIN      24
#define RCC_u8_PLLRDY_PIN     25
#define RCC_u8_PLLSRC_PIN     16
#define RCC_u8_PLLMUL_PIN18   18
#define RCC_u8_PLLMUL_PIN19   19
#define RCC_u8_PLLMUL_PIN20   20
#define RCC_u8_PLLMUL_PIN21   21
#define RCC_u8_APB1PRE_PIN8   8
#define RCC_u8_APB1PRE_PIN9   9
#define RCC_u8_APB1PRE_PIN10  10
#define RCC_u8_APB2PRE_PIN11  11
#define RCC_u8_APB2PRE_PIN12  12
#define RCC_u8_APB2PRE_PIN13  13

/* System clock and AHB  nibble number                                                       */
#define RCC_u8_SYSCLK_NIBLLE_NUM         0
#define RCC_u8_AHB_PRESCALER_NIBLLE_NUM  1


/* External high speed clock bypass modes definitions                                        */
/* Can be written only if the HSE oscillator is disabled                                     */
#define RCC_u8_BYPASSED                 (u8)1
#define RCC_u8_NOT_BYPASSED             (u8)0

/* CLK Security system enable modes definitions                                              */
#define RCC_u8_CLK_DETECTOR_ON          (u8)1
#define RCC_u8_CLK_DETECTOR_OFF         (u8)0

                           /**** RCC_CFGR Register PINs settings' definitions ****/

/* System clock switch modes definitions to select SYSCLK source                              */
#define RCC_u8_HSI_SYSCLK             0b00
#define RCC_u8_HSE_SYSCLK             0b01
#define RCC_u8_PLL_SYSCLK             0b10

/* AHB prescaler modes definitions values to control AHB clock division factor                */
#define RCC_u8_SYSCLK_DIVIDE_NO       0b0000
#define RCC_u8_SYSCLK_DIVIDE_2        0b1000
#define RCC_u8_SYSCLK_DIVIDE_4        0b1001
#define RCC_u8_SYSCLK_DIVIDE_8        0b1010
#define RCC_u8_SYSCLK_DIVIDE_16       0b1011
#define RCC_u8_SYSCLK_DIVIDE_64       0b1100
#define RCC_u8_SYSCLK_DIVIDE_128      0b1101
#define RCC_u8_SYSCLK_DIVIDE_256      0b1110
#define RCC_u8_SYSCLK_DIVIDE_512      0b1111

/* APB1 & APB2 prescaler modes definitions values to control APB1 & APB2 clock division factor */
#define RCC_u8_HCLK_DIVIDE_NO         0b000
#define RCC_u8_HCLK_DIVIDE_2          0b100
#define RCC_u8_HCLK_DIVIDE_4          0b101
#define RCC_u8_HCLK_DIVIDE_8          0b110
#define RCC_u8_HCLK_DIVIDE_16         0b111

/* PLL entry clock source modes definitions                                                     */
#define RCC_u8_PLL_INPUT_CLK_HSI      0
#define RCC_u8_PLL_INPUT_CLK_HSE      1

/* PLL multiplication factor modes definitions                                                  */
#define RCC_u8_PLL_MUL_INPUTCLK_X2    0b0000
#define RCC_u8_PLL_MUL_INPUTCLK_X3    0b0001
#define RCC_u8_PLL_MUL_INPUTCLK_X4    0b0010
#define RCC_u8_PLL_MUL_INPUTCLK_X5    0b0011
#define RCC_u8_PLL_MUL_INPUTCLK_X6    0b0100
#define RCC_u8_PLL_MUL_INPUTCLK_X7    0b0101
#define RCC_u8_PLL_MUL_INPUTCLK_X8    0b0110
#define RCC_u8_PLL_MUL_INPUTCLK_X9    0b0111
#define RCC_u8_PLL_MUL_INPUTCLK_X10   0b1000
#define RCC_u8_PLL_MUL_INPUTCLK_X11   0b1001
#define RCC_u8_PLL_MUL_INPUTCLK_X12   0b1010
#define RCC_u8_PLL_MUL_INPUTCLK_X13   0b1011
#define RCC_u8_PLL_MUL_INPUTCLK_X14   0b1100
#define RCC_u8_PLL_MUL_INPUTCLK_X15   0b1110
#define RCC_u8_PLL_MUL_INPUTCLK_X16   0b1111

#endif /* RCC_PRIVATE_H_ */
