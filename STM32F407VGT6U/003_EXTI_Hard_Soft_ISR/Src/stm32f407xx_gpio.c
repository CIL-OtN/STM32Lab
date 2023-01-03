
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "stm32f407xx_gpio.h"


/**
 * @brief Let the MC doing stuff
 */
void wait()
{
	for(uint32_t i = 0; i < 100000; i++);
}

/**
 * @brief Debounce before doing something
 */
void debounce()
{
	for(uint32_t i = 0; i < 500000/2; i++);
}

/**
 * @brief Initialize GPIO Mode, OType, OSpeed, PuPd
 */
void GPIO_Init(GPIO_RegDef_t* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
	// 8.4.1 GPIO port mode register (GPIOx_MODER)
	GPIOx->MODER &= ~(0x03 << (GPIO_InitStruct->GPIO_Pin * 2));
	GPIOx->MODER |= (((uint32_t)GPIO_InitStruct->GPIOx_Moder) << (GPIO_InitStruct->GPIO_Pin * 2));

	// 8.4.2 GPIO port output type register (GPIOx_OTYPER)
	GPIOx->OTYPER &= ~(0x01 << (GPIO_InitStruct->GPIO_Pin));
	GPIOx->OTYPER |= (((uint32_t)GPIO_InitStruct->GPIOx_OTyper) << (GPIO_InitStruct->GPIO_Pin));

	// 8.4.3 GPIO port output speed register (GPIOx_OSPEEDR)
	GPIOx->OSPEEDR &= ~(0x03 << (GPIO_InitStruct->GPIO_Pin * 2));
	GPIOx->OSPEEDR |= (((uint32_t)GPIO_InitStruct->GPIOx_OSpeedr) << (GPIO_InitStruct->GPIO_Pin * 2));

	// 8.4.4 GPIO port pull-up/pull-down register (GPIOx_PUPDR)
	GPIOx->PUPDR &= ~(0x03 << (GPIO_InitStruct->GPIO_Pin * 2));
	GPIOx->PUPDR |= (((uint32_t)GPIO_InitStruct->GPIOx_PuPdR) << (GPIO_InitStruct->GPIO_Pin * 2));

	if((uint32_t)GPIO_InitStruct->GPIOx_Moder == GPIO_Mode_AF)
	{
		// 8.4.9 GPIO alternate function low register (GPIOx_AFRL)
		// 8.4.10 GPIO alternate function high register (GPIOx_AFRH)

		// datasheet_STM32F407xx -> Table 9. Alternate function mapping
		uint8_t temp1, temp2;

		temp1 = GPIO_InitStruct->GPIO_Pin / 8;
		temp2 = GPIO_InitStruct->GPIO_Pin % 8;

		GPIOx->AFR[temp1] &= ~(0xf << (4 * temp2));
		GPIOx->AFR[temp1] |= GPIO_Mode_AF << (4 * temp2);
	}
}

/**
 * @brief Toggle GPIO_Pin
 */
void GPIO_ToggleBit(GPIO_RegDef_t* GPIOx, uint16_t GPIO_Pin)
{
	GPIOx->ODR ^= (0x01 << GPIO_Pin);
	wait();
}

/**
 * @brief Set port output data
 * 8.4.6 GPIO port output data register (GPIOx_ODR)
 */
void GPIO_SetBit(GPIO_RegDef_t* GPIOx, uint8_t GPIO_Pin)
{
	GPIOx->ODR |= (0x01 << GPIO_Pin);
}

/**
 * @brief Reset port output data
 */
void GPIO_ResetBit(GPIO_RegDef_t* GPIOx, uint8_t GPIO_Pin)
{
	GPIOx->ODR &= ~(0x01 << GPIO_Pin);
}

/**
 * @brief Read from given input pin
 * 8.4.5 GPIO port input data register (GPIOx_IDR)
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t* pGPIOx, uint8_t GPIO_Pin)
{
	uint8_t value;
	value = (uint8_t ) ( (pGPIOx->IDR >> GPIO_Pin) & 0x00000001 );

	return value;
}






















