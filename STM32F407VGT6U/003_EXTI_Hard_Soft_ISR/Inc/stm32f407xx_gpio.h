
#ifndef STM32F407XX_GPIO_H_
#define STM32F407XX_GPIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "stm32f407xx.h"


/**
  * @brief 8.4.1 GPIO port mode register (GPIOx_MODER)
  */
typedef enum
{
  GPIO_Mode_IN   	= 0x00, 		// 00: Input (reset state)
  GPIO_Mode_OUT  	= 0x01, 		// 01: General purpose output mode
  GPIO_Mode_AF   	= 0x02, 		// 10: Alternate function mode
  GPIO_Mode_AN   	= 0x03,  		// 11: Analog mode
  	  	  	  	  	  	  	  		// For Event and Interrupt!!!
//  GPIO_Mode_IT_FT 	= 0x04,			// Interrupt Falling edge detection
//  GPIO_Mode_IT_RT 	= 0x05,			// Interrupt Rising edge detection
//  GPIO_Mode_IT_RFT 	= 0x06			// Interrupt Rising Falling edge detection
} GPIOx_MODER_Typedef;

/**
 * @brief 8.4.2 GPIO port output type register (GPIOx_OTYPER)
 */
typedef enum
{
  GPIO_OType_PP = 0x00,				// 0: Output push-pull (reset state)
  GPIO_OType_OD = 0x01				// 1: Output open-drain
} GPIOx_OTYPER_TypeDef;

/**
  * @brief 8.4.3 GPIO port output speed register (GPIOx_OSPEEDR)
  */
typedef enum
{
  GPIO_Low_Speed     	= 0x00, 	// 00: Low speed
  GPIO_Medium_Speed  	= 0x01, 	// 01: Medium speed
  GPIO_High_Speed    	= 0x02, 	// 10: High speed
  GPIO_Very_High_Speed	= 0x03  	// 11: Very high speed
} GPIOx_OSPEEDR_TypeDef;

/**
  * @brief 8.4.4 GPIO port pull-up/pull-down register (GPIOx_PUPDR)
  */
typedef enum
{
  GPIO_PuPd_NOPULL = 0x00,			// 00: No pull-up, pull-down
  GPIO_PuPd_UP     = 0x01,			// 01: Pull-up
  GPIO_PuPd_DOWN   = 0x02			// 10: Pull-down
} GPIOx_PUPDR_TypeDef;

/**
  * @brief GPIO Init structure definition
  */
typedef struct
{
  uint32_t GPIO_Pin;


  GPIOx_MODER_Typedef GPIOx_Moder;


  GPIOx_OTYPER_TypeDef GPIOx_OTyper;


  GPIOx_OSPEEDR_TypeDef GPIOx_OSpeedr;


  GPIOx_PUPDR_TypeDef GPIOx_PuPdR;

} GPIO_InitTypeDef;


#define 	Pin0	0
#define 	Pin1	1
#define 	Pin2	2
#define 	Pin3	3
#define 	Pin4	4
#define 	Pin5	5
#define 	Pin6	6
#define 	Pin7	7
#define 	Pin8	8
#define 	Pin9	9
#define 	Pin10	10
#define 	Pin11	11
#define 	Pin12	12
#define 	Pin13	13
#define 	Pin14	14
#define 	Pin15	15


void wait();
void debounce();

/* Initialization and Configuration functions *********************************/
void GPIO_Init(GPIO_RegDef_t* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);

/* GPIO Read and Write functions **********************************************/
void GPIO_ResetBit(GPIO_RegDef_t* GPIOx, uint8_t GPIO_Pin);
void GPIO_SetBit(GPIO_RegDef_t* GPIOx, uint8_t GPIO_Pin);
void GPIO_ToggleBit(GPIO_RegDef_t* GPIOx, uint16_t GPIO_Pin);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t GPIO_Pin);


#endif /* STM32F407XX_GPIO_H_ */



