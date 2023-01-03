
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
  GPIO_Mode_IN   	= 0x00, /*!< GPIO Input Mode */
  GPIO_Mode_OUT  	= 0x01, /*!< GPIO Output Mode */
  GPIO_Mode_AF   	= 0x02, /*!< GPIO Alternate function Mode */
  GPIO_Mode_AN   	= 0x03,  /*!< GPIO Analog Mode */
//	Interrupt modes
  GPIO_Mode_IT_FT 	= 0x04,
  GPIO_Mode_IT_RT 	= 0x05,
  GPIO_Mode_IT_RFT 	= 0x06
} GPIOx_MODER_Typedef;


/**
  * @brief
  * 12.3.3 Rising trigger selection register (EXTI_RTSR)
  * - Rising trigger event configuration bit of line x
  * 12.3.4 Falling trigger selection register (EXTI_FTSR)
  * - Falling trigger event configuration bit of line x
  */


/**
 * @brief 8.4.2 GPIO port output type register (GPIOx_OTYPER)
 */
typedef enum
{
  GPIO_OType_PP = 0x00,	/*!< 0: Output push-pull (reset state) */
  GPIO_OType_OD = 0x01	/*!< 1: Output open-drain */
} GPIOx_OTYPER_TypeDef;


/**
  * @brief 8.4.3 GPIO port output speed register (GPIOx_OSPEEDR)
  */
typedef enum
{
  GPIO_Low_Speed     	= 0x00, /*!< Low speed    */
  GPIO_Medium_Speed  	= 0x01, /*!< Medium speed */
  GPIO_High_Speed    	= 0x02, /*!< Fast speed   */
  GPIO_Very_High_Speed	= 0x03  /*!< High speed   */
} GPIOx_OSPEEDR_TypeDef;


/**
  * @brief 8.4.4 GPIO port pull-up/pull-down register (GPIOx_PUPDR)
  */
typedef enum
{
  GPIO_PuPd_NOPULL = 0x00,
  GPIO_PuPd_UP     = 0x01,
  GPIO_PuPd_DOWN   = 0x02
} GPIOx_PUPDR_TypeDef;


/**
  * @brief GPIO Init structure definition
  */
typedef struct
{
  uint32_t GPIO_Pin;              		/*!< Specifies the GPIO pins to be configured.
                                       	  This parameter can be any value of @ref GPIO_pins_define */

  GPIOx_MODER_Typedef GPIOx_Moder;     	/*!< Specifies the operating mode for the selected pins.
                                       	  This parameter can be a value of @ref GPIOMode_TypeDef */

  GPIOx_OTYPER_TypeDef GPIOx_OTyper;   	/*!< Specifies the operating output type for the selected pins.
                                          This parameter can be a value of @ref GPIOOType_TypeDef */

  GPIOx_OSPEEDR_TypeDef GPIOx_OSpeedr; 	/*!< Specifies the speed for the selected pins.
                                       	  This parameter can be a value of @ref GPIOSpeed_TypeDef */

  GPIOx_PUPDR_TypeDef GPIOx_PuPdR;     	/*!< Specifies the operating Pull-up/Pull down for the selected pins.
                                      	  This parameter can be a value of @ref GPIOPuPd_TypeDef */
} GPIO_InitTypeDef;


void wait();
void debounce();

/* Initialization and Configuration functions *********************************/
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);

/* GPIO Read and Write functions **********************************************/
void GPIO_ResetBit(GPIO_TypeDef* GPIOx, uint8_t GPIO_Pin);
void GPIO_SetBit(GPIO_TypeDef* GPIOx, uint8_t GPIO_Pin);
void GPIO_ToggleBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint8_t GPIO_ReadFromInputPin(GPIO_TypeDef *pGPIOx, uint8_t GPIO_Pin);

#endif /* STM32F407XX_GPIO_H_ */



