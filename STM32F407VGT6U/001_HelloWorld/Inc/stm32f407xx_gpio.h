
#ifndef STM32F407XX_GPIO_H_
#define STM32F407XX_GPIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "stm32f407xx.h"



/*
 * Peripheral Clock setup
 * */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIO, uint8_t EnOrDi);

#endif /* STM32F407XX_GPIO_H_ */



/* Test connection to main:
 *
 * void testHelloGpio();
 *
 * */
