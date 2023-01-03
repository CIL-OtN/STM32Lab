
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "stm32f407xx.h"
#include "stm32f407xx_gpio.h"
#include "stm32f407xx_exti.h"

uint32_t state = 0;


int main(void)
{
	GPIOD_PCLK_EN();

	GPIO_InitTypeDef LED13;
	GPIO_InitTypeDef LED14;

	EXTI_InitTypeDef BtnD10;
	EXTI_InitTypeDef BtnD11;

	printf("--- Program start ---\n");

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


	BtnD10.EXTI_Line = EXTI_Line10;
	BtnD10.EXTI_Trigger = GPIO_Mode_IT_FT;
	EXTI_Init(GPIOD, &BtnD10);

	BtnD11.EXTI_Line = EXTI_Line11;
	BtnD11.EXTI_Trigger = GPIO_Mode_IT_FT;
	EXTI_Init(GPIOD, &BtnD11);

	// IRQ configurations
	EXTI_IRQInterruptConfig(IRQ_NO_EXTI15_10, ENABLE);
	EXTI_IRQPriorityConfig(IRQ_NO_EXTI15_10, NVIC_IRQ_PRIO1);


	for(int i = 0; i < 3; i++)
		EXTI_GenerateSWInterrupt(EXTI_Line10);

	for(int i = 0; i < 3; i++)
		EXTI_GenerateSWInterrupt(EXTI_Line11);


	while(1);
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & ( 1 << EXTI_Line10))		// Is selected trigger request occurred?
	{
		// printf("Im 1. IF-Fall \n");
		GPIO_ToggleBit(GPIOD, Pin13);

		EXTI->PR |= (1 << EXTI_Line10); 	// Clear pending register
	}

	if(EXTI->PR & ( 1 << EXTI_Line11))		// Is selected trigger request occurred?
	{
		// printf("Im 2. IF-Fall \n");
		GPIO_ToggleBit(GPIOD, Pin14);
		EXTI->PR |= (1 << EXTI_Line11); 	// Clear pending register
	}

	// for wheel control
	//printf("%d \n", counter1++);
	//
	//if(counter1 == counter2)
	//{
	//	printf("Runde \n");
	//	GPIO_ResetBit(GPIOA, Pin0);
	//	debounce();
	//	GPIO_SetBit(GPIOA, Pin1);
	//
	//	counter2 += 17;
	//}
}

//	switch(state)
//	{
//		case 0:
//			GPIO_ToggleBit(GPIOD, Pin12);
//
//			state = 1;
//			break;
//
//		case 1:
//			GPIO_ToggleBit(GPIOD, Pin13);
//
//			state = 2;
//			break;
//
//		case 2:
//			GPIO_ToggleBit(GPIOD, Pin14);
//
//			state = 3;
//			break;
//
//		case 3:
//			GPIO_ToggleBit(GPIOD, Pin15);
//
//			state = 4;
//			break;
//
//		case 4:
//			wait();
//			GPIO_ToggleBit(GPIOD, Pin12);
//			GPIO_ToggleBit(GPIOD, Pin13);
//			GPIO_ToggleBit(GPIOD, Pin14);
//			GPIO_ToggleBit(GPIOD, Pin15);
//			state = 0;
//			break;
//	}



