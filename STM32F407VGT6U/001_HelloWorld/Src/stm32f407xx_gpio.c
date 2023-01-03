
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "stm32f407xx_gpio.h"



/*********************************************************************
 * @fn 				- GPIO_PeriClockControl
 *
 * @brief			- This function enable or disable peripheral clock for given GPIO port
 *
 * @param[in]		- Base address of the GPIO peripheral
 * @param[in]		- ENABLE or DISABLE marcros
 *
 * @return			- none
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIO, uint8_t EnOrDi)
{



}








void testHelloGpio()
{

	printf("Test hello from stm32f407xx_gpio.c \n");
}
