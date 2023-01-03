
// 004_SPI_Bus
/* 126. SPI functional block diagram explanation */

/* 127. NSS settings in STM32 master and slave modes
 * When a device is in slave mode:
 * In slave mode, the NSS works as a standard "chip select" input and lets the slave communicate with the master.
 *
 * When a device is master:
 * In master mode, NSS can be used either as output or input. As an input it can prevent multi-master bus collision,
 * and as an output it can drive a slave select signal of a single slave.
 * */

/* 128. STM32 SPI hardware and software slave managements
 * Software NSS management (SSM = 1):
 * Hardware NSS management (SSM = 0):
 *
 * Points to remember
 *
 * Scenario 1:
 * 1 master and 1 slave
 * 1) You need not to use NSS pin of master and slave if you use software slave management
 * 2) If you don't want to use software slave management then you can connect NSS of master to NSS of slave
 *
 * Scenario 2:
 * 1 master and multiple slaves
 * 1) You cannot use software slave management here
 * 2) You cannot use NSS pin of the master to connect to NSS pin of any of the slaves
 * 3) Master has to use some of its GPIO pins to control the different NSS pins of the slaves
 * */

/* 129. SPI CPOL and CPHA discussion
 *
 * SPI Communication Format
 * SCLK PHASE 			(CR1: Bit 0 CPHA: Clock phase)
 * - Controls at which clock edge of the SCLK (1st or 2nd) the data should be sampled by the slave
 * - The combination of CPOL (clock polarity) and CPHA (clock phase) bits selects the data capture clock edge
 *
 * SCLK POLARITY 		(CR1: Bit1 CPOL: Clock polarity)
 * - The CPOL bit controls the idle state value of the clock when no data is being transfered
 * - If CPOL is reset, the SCLK pin has a low-level idle state. If CPOL is set,
 *   the SCLK pin has a high-level idle state
 *
 * Data frame foramt 	(CR1: Bit 11 DFF: Data frame format 8-bit shift register or 16-bit shift register)
 *
 * - During SPI communication, receive and transmit operations are performed simultaneously
 * - The serial clock (SCK) synchronize the shifting and sampling of the information on the data lines
 * - The communication format depends on the clock phase, the clock polarity and the data
 *   frame format. To be able to communicate together, the master and slaves devices must follow the same
 *   communication format.
 *
 * Different SPI Modes
 *
 * Mode	CPOL CPHA	* If CPHASE=1: Data will be sampled on the trailing edge of the clock.
 *  0	 0	  0	 	* If CPHASE=0: Data will be sampled on the leading edge of the clock.
 *  1	 0    1
 *  2 	 1    0
 *  3 	 1    1
 * */

/* 132. SPI Serial clock frequency
 *
 * Serical Clock (SCLK) for SPI1 in APB2 is 8MHz (HSI)
 *
 * Serical Clock (SCLK) for SPI2 and SPI3 in APB1 is 8MHz (HSI)
 * If you use PLL and drive APB1 bus at 42MHz, the SPI2 and SPI3 can produce SCLK of 21MHz.
 * That means SPI peripherals maximum data transfer rate will be 21 million bits per second.
 * */

/*
 * Remember that in SPI communication, slave will not initiate data transfer unless master produces the clock.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "stm32f407xx.h"
#include "stm32f407xx_gpio.h"
#include "stm32f407xx_exti.h"
#include "stm32f407xx_spi.h"



int main(void)
{
	GPIOD_PCLK_EN();
	SPI_PeriClockControl(SPI1, ENABLE);

	GPIO_InitTypeDef LED13;

	SPI_InitTypeDef spie1;

	LED13.GPIO_Pin = Pin13;
	LED13.GPIOx_Moder = GPIO_Mode_OUT;
	LED13.GPIOx_OTyper = GPIO_OType_PP;
	LED13.GPIOx_OSpeedr = GPIO_Medium_Speed;
	LED13.GPIOx_PuPdR = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &LED13);



	spie1.SPIx_CR1 = MSTR;
	spie1.SPIx_CR1 = SPI_BaudRatePrescaler_8;


	SPI_Init(SPI1, &spie1);



	while(1);
}























































































//#include "stm32f407xx.h"
//#include "stm32f407xx_gpio.h"
//#include "stm32f407xx_exti.h"
//
//uint32_t state = 0;
//
//uint32_t counter1 = 0;
//uint32_t counter2 = 5;
//
//
//int main(void)
//{
//	GPIOD_PCLK_EN();
//	GPIOA_PCLK_EN();
//
//	GPIO_InitTypeDef MLeftForwardPA1;
//	//GPIO_InitTypeDef MLeftBackwardPA0;
//
//	EXTI_InitTypeDef BtnD10;
//	EXTI_InitTypeDef BtnD11;
//
//	printf("--- Program start ---\n");
//
//	MLeftForwardPA1.GPIO_Pin = Pin1;
//	MLeftForwardPA1.GPIOx_Moder = GPIO_Mode_OUT;
//	MLeftForwardPA1.GPIOx_OTyper = GPIO_OType_PP;
//	MLeftForwardPA1.GPIOx_OSpeedr = GPIO_Medium_Speed;
//	MLeftForwardPA1.GPIOx_PuPdR = GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIOA, &MLeftForwardPA1);
//
//
//	//GPIO_SetBit(GPIOA, Pin1);
//
//	BtnD10.EXTI_Line = EXTI_Line10;
//	BtnD10.EXTI_Trigger = GPIO_Mode_IT_FT;
//	EXTI_Init(GPIOD, &BtnD10);
//
//	BtnD11.EXTI_Line = EXTI_Line11;
//	BtnD11.EXTI_Trigger = GPIO_Mode_IT_FT;
//	EXTI_Init(GPIOD, &BtnD11);
//
//	// IRQ configurations
//	EXTI_IRQInterruptConfig(IRQ_NO_EXTI15_10, ENABLE);
//	EXTI_IRQPriorityConfig(IRQ_NO_EXTI15_10, NVIC_IRQ_PRIO1);
//
//
//
//
//	while(1)
//	{
//		if(counter1 != counter2)
//		{
//			GPIO_SetBit(GPIOA, Pin1);
//
//			EXTI_GenerateSWInterrupt(EXTI_Line10);
//		}
//		else
//		{
//			GPIO_ResetBit(GPIOA, Pin1);
//		}
//
//	}
//}
//
//void EXTI15_10_IRQHandler(void)
//{
//	if(EXTI->PR & ( 1 << EXTI_Line10))		// Is selected trigger request occurred?
//	{
//		EXTI->PR |= (1 << EXTI_Line10); 	// Clear pending register
//		counter1++;
//	}
//
//
//
//	// for wheel control
//	//printf("%d \n", counter1++);
//	//
//	//if(counter1 == counter2)
//	//{
//	//	printf("Runde \n");
//	//	GPIO_ResetBit(GPIOA, Pin0);
//	//	debounce();
//	//	GPIO_SetBit(GPIOA, Pin1);
//	//
//	//	counter2 += 17;
//	//}
//}








