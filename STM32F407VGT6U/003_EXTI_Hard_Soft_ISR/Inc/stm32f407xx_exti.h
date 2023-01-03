
#ifndef STM32F407XX_EXTI_H_
#define STM32F407XX_EXTI_H_


#include "stm32f407xx.h"

typedef enum
{
  EXTI_Mode_Interrupt = 0x01,
  EXTI_Mode_Event 	  = 0x02
} EXTIx_Mode_TypeDef;

typedef enum
{
	GPIO_Mode_IT_FT  = 0x01,
	GPIO_Mode_IT_RT  = 0x02,
	GPIO_Mode_IT_RFT = 0x03
}EXTIx_Trigger_TypeDef;

typedef struct
{
  uint32_t EXTI_Line;


  EXTIx_Mode_TypeDef EXTI_Mode;


  EXTIx_Trigger_TypeDef EXTI_Trigger;


} EXTI_InitTypeDef;

#define 	EXTI_Line0		0
#define 	EXTI_Line1		1
#define 	EXTI_Line2		2
#define 	EXTI_Line3		3
#define 	EXTI_Line4		4
#define 	EXTI_Line5		5
#define 	EXTI_Line6		6
#define 	EXTI_Line7		7
#define 	EXTI_Line8		8
#define 	EXTI_Line9		9
#define 	EXTI_Line10		10
#define 	EXTI_Line11		11
#define 	EXTI_Line12		12
#define 	EXTI_Line13		13
#define 	EXTI_Line14		14
#define 	EXTI_Line15		15


/* Interrupts and flags management functions **********************************/
void EXTI_Init(GPIO_RegDef_t* GPIOx, EXTI_InitTypeDef* EXTI_InitStruct);


/* Initialization and Configuration functions *********************************/
void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line);


void EXTI_ClearITPendingBit(uint8_t EXTI_Line);


/* GPIO_IRQ_Config ************************************************************/
void EXTI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnOrDi);
void EXTI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);

#endif /* STM32F407XX_EXTI_H_ */
