
#ifndef STM32F407XX_H_
#define STM32F407XX_H_

#include <stdint.h>

#define		__IO	volatile

// RM0090: Table 1. STM32F4xx register boundary addresses
#define 	APB1PERIPH_BASE		0x40000000U			// Bus: APB1 base
#define 	APB2PERIPH_BASE		0x40010000U			// Bus: APB2 base
#define 	AHB1PERIPH_BASE		0x40020000U			// Bus: AHB1 base
#define 	AHB2PERIPH_BASE		0x50000000U			// Bus: AHB2 base

#define		RCC_BASE			0x40023800U			// Bus: AHB1
#define		CRC_BASE			0x40023000U			// Bus: AHB1
#define 	EXTI_BASE			0x40013C00U			// Bus: APB2
#define 	SYSCFG_BASE			0x40013800U			// Bus: APB2

// RM0090: Table 1. STM32F4xx register boundary addresses
#define		GPIOA_BASE			0x40020000U			// Bus: AHB1
#define		GPIOB_BASE			0x40020400U			// -"-
#define		GPIOC_BASE			0x40020800U			// -"-
#define		GPIOD_BASE			0x40020C00U			// -"-
#define		GPIOE_BASE			0x40021000U			// -"-
#define		GPIOF_BASE			0x40021400U			// -"-
#define		GPIOG_BASE			0x40021800U			// -"-
#define		GPIOH_BASE			0x40021C00U			// -"-
#define		GPIOI_BASE			0x40022000U			// -"-
#define		GPIOJ_BASE			0x40022400U			// -"-
#define		GPIOK_BASE			0x40022800U			// -"-

#define 	RCC					((RCC_TypeDef_t *) RCC_BASE )	// 7.3 RCC registers

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

typedef struct					// 7.3 RCC registers
{								// Address offset
	__IO uint32_t CR;          	// 0x00		7.3.1 RCC clock control register (RCC_CR)
	__IO uint32_t PLLCFGR;      // 0x04		7.3.2 RCC PLL configuration register (RCC_PLLCFGR)
	__IO uint32_t CFGR;         // 0x08		7.3.3 RCC clock configuration register (RCC_CFGR)
	__IO uint32_t CIR;          // 0x0C		7.3.4 RCC clock interrupt register (RCC_CIR)
	__IO uint32_t AHB1RSTR;     // 0x10		7.3.5 RCC AHB1 peripheral reset register (RCC_AHB1RSTR)
	__IO uint32_t AHB2RSTR;     // 0x14		7.3.6 RCC AHB2 peripheral reset register (RCC_AHB2RSTR)
	__IO uint32_t AHB3RSTR;     // 0x18		7.3.7 RCC AHB3 peripheral reset register (RCC_AHB3RSTR)
		 uint32_t RESERVED0;    // 0x1C
    __IO uint32_t APB1RSTR;     // 0x20		7.3.8 RCC APB1 peripheral reset register (RCC_APB1RSTR)
    __IO uint32_t APB2RSTR;     // 0x24		7.3.9 RCC APB2 peripheral reset register (RCC_APB2RSTR)
         uint32_t RESERVED1[2]; // 0x28-0x2C
    __IO uint32_t AHB1ENR;      // 0x30		7.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    __IO uint32_t AHB2ENR;     	// 0x34		7.3.11 RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    __IO uint32_t AHB3ENR;      // 0x38		7.3.12 RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)
         uint32_t RESERVED2;    // 0x3C
    __IO uint32_t APB1ENR;      // 0x40		7.3.13 RCC APB1 peripheral clock enable register (RCC_APB1ENR)
    __IO uint32_t APB2ENR;      // 0x44		7.3.14 RCC APB2 peripheral clock enable register (RCC_APB2ENR)
         uint32_t RESERVED3[2]; // 0x48-0x4C
    __IO uint32_t AHB1LPENR;    // 0x50		7.3.15 RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)
    __IO uint32_t AHB2LPENR;    // 0x54		7.3.16 RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)
    __IO uint32_t AHB3LPENR;    // 0x58		7.3.17 RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR)
         uint32_t RESERVED4;    // 0x5C
    __IO uint32_t APB1LPENR;    // 0x60		7.3.18 RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)
    __IO uint32_t APB2LPENR;    // 0x64		7.3.19 RCC APB2 peripheral clock enabled in low power mode register (RCC_APB2LPENR)
         uint32_t RESERVED5[2]; // 0x68-0x6C
    __IO uint32_t BDCR;         // 0x70		7.3.20 RCC Backup domain control register (RCC_BDCR)
    __IO uint32_t CSR;          // 0x74		7.3.21 RCC clock control & status register (RCC_CSR)
         uint32_t RESERVED6[2]; // 0x78-0x7C
    __IO uint32_t SSCGR;        // 0x80		7.3.22 RCC spread spectrum clock generation register (RCC_SSCGR)
  	__IO uint32_t PLLI2SCFGR;   // 0x84		7.3.23 RCC PLLI2S configuration register (RCC_PLLI2SCFGR)

} RCC_TypeDef_t;

// 7.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
#define 	GPIOA_PCLK_EN()		( RCC->AHB1ENR |= (1 << 0) )		// Bit 0 GPIOAEN: IO port A clock enable -> 1: IO port A clock enabled
#define 	GPIOB_PCLK_EN()		( RCC->AHB1ENR |= (1 << 1) )		// -"-
#define 	GPIOC_PCLK_EN()		( RCC->AHB1ENR |= (1 << 2) )		// -"-
#define 	GPIOD_PCLK_EN()		( RCC->AHB1ENR |= (1 << 3) )		// -"-
#define 	GPIOE_PCLK_EN()		( RCC->AHB1ENR |= (1 << 4) )		// -"-
#define 	GPIOF_PCLK_EN()		( RCC->AHB1ENR |= (1 << 5) )		// -"-
#define 	GPIOG_PCLK_EN()		( RCC->AHB1ENR |= (1 << 6) )		// -"-
#define 	GPIOH_PCLK_EN()		( RCC->AHB1ENR |= (1 << 7) )		// -"-
#define 	GPIOI_PCLK_EN()		( RCC->AHB1ENR |= (1 << 8) )		// -"-

// 7.3.5 RCC AHB1 peripheral reset register (RCC_AHB1RSTR)
#define 	GPIOA_PCLK_DI()		( RCC->AHB1RSTR &= ~(1 << 0) )
#define 	GPIOB_PCLK_DI()		( RCC->AHB1RSTR &= ~(1 << 1) )
#define	 	GPIOC_PCLK_DI()		( RCC->AHB1RSTR &= ~(1 << 2) )
#define 	GPIOD_PCLK_DI()		( RCC->AHB1RSTR &= ~(1 << 3) )
#define 	GPIOE_PCLK_DI()		( RCC->AHB1RSTR &= ~(1 << 4) )
#define 	GPIOF_PCLK_DI()		( RCC->AHB1RSTR &= ~(1 << 5) )
#define 	GPIOG_PCLK_DI()		( RCC->AHB1RSTR &= ~(1 << 6) )
#define 	GPIOH_PCLK_DI()		( RCC->AHB1RSTR &= ~(1 << 7) )
#define 	GPIOI_PCLK_DI()		( RCC->AHB1RSTR &= ~(1 << 8) )

typedef struct					// 8.4 GPIO registers
{								// Address offset
	__IO	uint32_t MODER;		// 0x00		8.4.1 GPIO port mode register (GPIOx_MODER)
	__IO	uint32_t OTYPER;	// 0x04 	8.4.2 GPIO port output type register (GPIOx_OTYPER)
	__IO	uint32_t OSPEEDR;	// 0x08		8.4.3 GPIO port output speed register (GPIOx_OSPEEDR)
	__IO  	uint32_t PUPDR;		// 0x0C		8.4.4 GPIO port pull-up/pull-down register (GPIOx_PUPDR)
	__IO  	uint32_t IDR;		// 0x10		8.4.5 GPIO port input data register (GPIOx_IDR)
	__IO  	uint32_t ODR;		// 0x14		8.4.6 GPIO port output data register (GPIOx_ODR)
	__IO	uint32_t BSRR;		// 0x18		8.4.7 GPIO port bit set/reset register (GPIOx_BSRR)
	__IO	uint32_t LCKR;		// 0x1C		8.4.8 GPIO port configuration lock register (GPIOx_LCKR)
	__IO	uint32_t AFR[2];	// 0x20		8.4.9 GPIO alternate function low register (GPIOx_AFRL)
} GPIO_RegDef_t;

#define		GPIOA	((GPIO_RegDef_t*) GPIOA_BASE)
#define		GPIOB	((GPIO_RegDef_t*) GPIOB_BASE)
#define		GPIOC	((GPIO_RegDef_t*) GPIOC_BASE)
#define		GPIOD	((GPIO_RegDef_t*) GPIOD_BASE)
#define		GPIOE	((GPIO_RegDef_t*) GPIOE_BASE)
#define		GPIOF	((GPIO_RegDef_t*) GPIOF_BASE)
#define		GPIOG	((GPIO_RegDef_t*) GPIOG_BASE)
#define		GPIOH	((GPIO_RegDef_t*) GPIOH_BASE)
#define		GPIOI	((GPIO_RegDef_t*) GPIOI_BASE)
#define		GPIOJ	((GPIO_RegDef_t*) GPIOJ_BASE)
#define		GPIOK	((GPIO_RegDef_t*) GPIOK_BASE)

// 8.4.1 GPIO port mode register (GPIOx_MODER)
#define 	InputMode 		0
#define 	OutputMode		1
#define		AltFuncMode		2
#define		AnalogMode		3






// Some generic macros -> level it for all drivers
#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET

#endif /* STM32F407XX_H_ */




























/* Test connection to main:

void testHelloMainH()
{
	printf("Test hello from stm32f407xx.h \n");
}

*/
