
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "stm32f407xx.h"
#include "stm32f407xx_gpio.h"


int main(void)
{
	GPIOD_PCLK_EN();						// 7.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
	GPIOA_PCLK_EN();

	GPIO_InitTypeDef LED12;
	GPIO_InitTypeDef LED13;
	GPIO_InitTypeDef LED14;
	GPIO_InitTypeDef LED15;

	LED12.GPIO_Pin = Pin12;
	LED12.GPIOx_Moder = GPIO_Mode_OUT;
	LED12.GPIOx_OTyper = GPIO_OType_PP;
	LED12.GPIOx_OSpeedr = GPIO_Medium_Speed;
	LED12.GPIOx_PuPdR = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &LED12);

	LED13.GPIO_Pin = Pin13;
	LED13.GPIOx_Moder = GPIO_Mode_OUT;
	LED13.GPIOx_OTyper = GPIO_OType_PP;
	LED13.GPIOx_OSpeedr = GPIO_Medium_Speed;
	LED13.GPIOx_PuPdR = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &LED13);

	LED14.GPIO_Pin = Pin14;
	LED14.GPIOx_Moder = GPIO_Mode_OUT;
	LED14.GPIOx_OTyper = GPIO_OType_PP;
	LED14.GPIOx_OSpeedr = GPIO_Medium_Speed;
	LED14.GPIOx_PuPdR = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &LED14);

	LED15.GPIO_Pin = Pin15;
	LED15.GPIOx_Moder = GPIO_Mode_OUT;
	LED15.GPIOx_OTyper = GPIO_OType_PP;
	LED15.GPIOx_OSpeedr = GPIO_Medium_Speed;
	LED15.GPIOx_PuPdR = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &LED15);

	GPIO_InitTypeDef BtnA0;
	BtnA0.GPIO_Pin = Pin0;
	BtnA0.GPIOx_Moder = GPIO_Mode_IN;
	BtnA0.GPIOx_OSpeedr = GPIO_Medium_Speed;
	BtnA0.GPIOx_PuPdR = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &BtnA0);


	while(1)
	{

// Programm 1: Toggle LED with Button on board
		// Toggle LED GPIOA pin0
		if(GPIO_ReadFromInputPin(GPIOA, Pin0) == 1)
		{
			debounce();
			GPIO_ToggleBits(GPIOD, Pin12);
			GPIO_ToggleBits(GPIOD, Pin13);

		}

// Programm 2:
//		GPIO_ToggleBits(GPIOD, Pin12);
//		GPIO_ToggleBits(GPIOD, Pin13);
//		GPIO_ToggleBits(GPIOD, Pin14);
//		GPIO_ToggleBits(GPIOD, Pin15);

// Programm 3:
//		GPIO_SetBit(GPIOD, Pin12);
//		wait();
//		GPIO_SetBit(GPIOD, Pin13);
//		wait();
//		GPIO_SetBit(GPIOD, Pin14);
//		wait();
//		GPIO_SetBit(GPIOD, Pin15);
//		wait();
//
//		GPIO_ResetBit(GPIOD, Pin12);
//		wait();
//		GPIO_ResetBit(GPIOD, Pin13);
//		wait();
//		GPIO_ResetBit(GPIOD, Pin14);
//		wait();
//		GPIO_ResetBit(GPIOD, Pin15);
//		wait();
	}
}


