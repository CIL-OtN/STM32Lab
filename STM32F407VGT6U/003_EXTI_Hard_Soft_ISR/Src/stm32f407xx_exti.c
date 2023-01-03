
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "stm32f407xx_exti.h"
#include "stm32f407xx_gpio.h"


/* Interrupts and flags management functions **********************************/

/**
 * @brief
 */
void EXTI_Init(GPIO_RegDef_t* GPIOx, EXTI_InitTypeDef* EXTI_InitStruct)
{

	if((uint32_t)EXTI_InitStruct->EXTI_Trigger == GPIO_Mode_IT_FT)
	{
		// 12.3.4 Falling trigger selection register (EXTI_FTSR)

		EXTI->FTSR |= (0x01 << (EXTI_InitStruct->EXTI_Line));
		EXTI->RTSR &= ~(0x01 << (EXTI_InitStruct->EXTI_Line));

	}
	else if((uint32_t)EXTI_InitStruct->EXTI_Trigger == GPIO_Mode_IT_RT)
	{
		// 12.3.3 Rising trigger selection register (EXTI_RTSR)

		EXTI->RTSR |= (0x01 << (EXTI_InitStruct->EXTI_Line));
		EXTI->FTSR &= ~(0x01 << (EXTI_InitStruct->EXTI_Line));
	}
	else if((uint32_t)EXTI_InitStruct->EXTI_Trigger == GPIO_Mode_IT_RFT)
	{
		// 1. Configure both FTSR and RTSR
		EXTI->RTSR |= (0x01 << (EXTI_InitStruct->EXTI_Line));
		EXTI->FTSR |= (0x01 << (EXTI_InitStruct->EXTI_Line));
	}

	uint8_t temp1, temp2;

	// 2. Configure the GPIO port selection in SYSCFG_EXTICR
	temp1 = EXTI_InitStruct->EXTI_Line / 4;
	temp2 = EXTI_InitStruct->EXTI_Line % 4;

	uint8_t portcode = GPIO_BASEADDR_TO_CODE(GPIOx);

	// 7.3.14 RCC APB2 peripheral clock enable register (RCC_APB2ENR)
	SYSCFG_PCLK_EN();

	SYSCFG->EXTICR[temp1] = portcode << ( temp2 * 4 );

	// 3. Enable the EXTI interrupt delivery using IMR -> // 12.3.1 Interrupt mask register (EXTI_IMR)
	// 0: Interrupt request from line x is masked
	// 1: Interrupt request from line x is not masked
	EXTI->IMR |= (0x01 << (EXTI_InitStruct->EXTI_Line));
}

/* Initialization and Configuration functions *********************************/
/**
 * @brief
 */
void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line)
{
	// 12.3.5 Software interrupt event register (EXTI_SWIER)
	EXTI->SWIER |= (1 << EXTI_Line);
}

/**
 * @brief
 */
void EXTI_ClearITPendingBit(uint8_t EXTI_Line)
{
	// 12.3.6 Pending register (EXTI_PR)
	// Clear the exti register corresponding to the pin number
	if(EXTI->PR & ( 1 << EXTI_Line)) {

		EXTI->PR |= (1 << EXTI_Line); 	// Clear pending register
	}
}

/* GPIO_IRQ_Config ************************************************************/
/**
 * @brief In in Cortex-M4 Devices - 4.2 Nested Vectored Interrupt Controller
 * @brief In RM0090 - Table 61. Vector table for STM32F405xx/07xx and STM32F415xx/17xx
 *
 */
void EXTI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		// Interrupt Set-enable Registers on page 4-4
		if(IRQNumber <= 31)
		{
			//program ISER0 register
			*NVIC_ISER0 |= ( 1 << IRQNumber );

		}else if(IRQNumber > 31 && IRQNumber < 64 )
		{
			//program ISER1 register
			*NVIC_ISER1 |= ( 1 << (IRQNumber % 32) );	// TODO: Hier wird zum ersten Mal ein Interrupt gefordert... Why?
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ISER2 register
			*NVIC_ISER2 |= ( 1 << (IRQNumber % 64) );
		}
	}
	else
	{
		// Interrupt Clear-enable Registers on page 4-5
		if(IRQNumber <= 31)
		{
			// program in SFR -> STM32F407 -> NVIC -> ICER0
			*ICER0 |= (1 << IRQNumber);
		}
		else if(IRQNumber >= 32 && IRQNumber <= 63)
		{
			// -"- ICER1
			*ICER1 |= (1 << IRQNumber % 32);
		}
		else if(IRQNumber >= 64 && IRQNumber < 96)
		{
			// -"- ICER2
			*ICER2 |= (1 << IRQNumber% 64);
		}
	}
}

/**
 * @brief Interrupt Priority Registers on page 4-7
 */
void EXTI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
	// 1. Find out the ipr register
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section = IRQNumber % 4;									// One register has 4 Sections with 8 bits

	uint8_t shift_amount = ( 8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);

	*(NVIC_PR_BASE_ADDR + iprx ) |= (IRQPriority << shift_amount);	// Interrupt priority register
}







