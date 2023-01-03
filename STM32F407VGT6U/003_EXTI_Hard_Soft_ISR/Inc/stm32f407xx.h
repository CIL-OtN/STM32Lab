
#ifndef STM32F407XX_H_
#define STM32F407XX_H_

#include <stdint.h>

#define		__vo	volatile


//************************************** START: Processor Specific Detail **************************************

/**
 * @brief In in Cortex-M4 Devices - Interrupt Set-enable Registers on page 4-4
 * @brief Table 4-2 NVIC register summary
 */
#define NVIC_ISER0				( (__vo uint32_t*) 0xE000E100 )
#define NVIC_ISER1				( (__vo uint32_t*) 0xE000E104 )
#define NVIC_ISER2				( (__vo uint32_t*) 0xE000E108 )

/**
 * @brief In in Cortex-M4 Devices - Interrupt Clear-enable Registers on page 4-5
 */
#define ICER0				( (__vo uint32_t*) 0XE000E180 )
#define ICER1				( (__vo uint32_t*) 0XE000E184 )
#define ICER2				( (__vo uint32_t*) 0XE000E188 )


/*
 * @brief In in Cortex-M4 Devices -> Table 4-2 NVIC register summary
 * */
#define NVIC_PR_BASE_ADDR  		((__vo uint32_t*) 0xE000E400)

#define NO_PR_BITS_IMPLEMENTED	4


/*
 * base Addresses of Flash and SRAM memories
 *
 * Table 5. Flash module organization (STM32F40x and STM32F41x)	-> Full memory map of the MCU is 0xFFFF_FFFF
 * */
#define FLASH_BASEADDR			0x08000000U		// unsigned integer Main memory = Flash memory
#define SRAM1_BASEADDR			0x20000000U		// Main internal SRAM1 (112 KB)
#define SRAM2_BASEADDR			0x20001C00U		// Auxiliary internal SRAM2 (16 KB)
#define ROM_BASEADDR			0x1FFF0000U		// System memory = ROM
#define SRAM 					SRAM1_BASEADDR


// RM0090: Table 1. STM32F4xx register boundary addresses
#define 	APB1PERIPH_BASE		0x40000000U			// Bus: APB1 base
#define 	APB2PERIPH_BASE		0x40010000U			// Bus: APB2 base
#define 	AHB1PERIPH_BASE		0x40020000U			// Bus: AHB1 base
#define 	AHB2PERIPH_BASE		0x50000000U			// Bus: AHB2 base

#define		RCC_BASE			0x40023800U			// Bus: AHB1
#define		CRC_BASE			0x40023000U			// Bus: AHB1
#define 	EXTI_BASE			0x40013C00U			// Bus: APB2 0x3C00
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


#define 	RCC					((RCC_RegDef_t*) 	RCC_BASE )		// 7.3 RCC registers
#define 	SYSCFG				((SYSCFG_RegDef_t*) SYSCFG_BASE) 	// 9.2 SYSCFG registers for STM32F405xx/07xx
#define 	EXTI				((EXTI_RegDef_t*) 	EXTI_BASE) 		// 12.3 EXTI registers


#define		GPIOA				((GPIO_RegDef_t*) GPIOA_BASE)
#define		GPIOB				((GPIO_RegDef_t*) GPIOB_BASE)
#define		GPIOC				((GPIO_RegDef_t*) GPIOC_BASE)
#define		GPIOD				((GPIO_RegDef_t*) GPIOD_BASE)
#define		GPIOE				((GPIO_RegDef_t*) GPIOE_BASE)
#define		GPIOF				((GPIO_RegDef_t*) GPIOF_BASE)
#define		GPIOG				((GPIO_RegDef_t*) GPIOG_BASE)
#define		GPIOH				((GPIO_RegDef_t*) GPIOH_BASE)
#define		GPIOI				((GPIO_RegDef_t*) GPIOI_BASE)
#define		GPIOJ				((GPIO_RegDef_t*) GPIOJ_BASE)
#define		GPIOK				((GPIO_RegDef_t*) GPIOK_BASE)


typedef struct						// 7.3 RCC registers
{									// Address offset
	__vo uint32_t CR;          		// 0x00		7.3.1 RCC clock control register (RCC_CR)
	__vo uint32_t PLLCFGR;      	// 0x04		7.3.2 RCC PLL configuration register (RCC_PLLCFGR)
	__vo uint32_t CFGR;         	// 0x08		7.3.3 RCC clock configuration register (RCC_CFGR)
	__vo uint32_t CIR;          	// 0x0C		7.3.4 RCC clock interrupt register (RCC_CIR)
	__vo uint32_t AHB1RSTR;     	// 0x10		7.3.5 RCC AHB1 peripheral reset register (RCC_AHB1RSTR)
	__vo uint32_t AHB2RSTR;     	// 0x14		7.3.6 RCC AHB2 peripheral reset register (RCC_AHB2RSTR)
	__vo uint32_t AHB3RSTR;     	// 0x18		7.3.7 RCC AHB3 peripheral reset register (RCC_AHB3RSTR)
		 uint32_t RESERVED0;    	// 0x1C
    __vo uint32_t APB1RSTR;     	// 0x20		7.3.8 RCC APB1 peripheral reset register (RCC_APB1RSTR)
    __vo uint32_t APB2RSTR;     	// 0x24		7.3.9 RCC APB2 peripheral reset register (RCC_APB2RSTR)
         uint32_t RESERVED1[2]; 	// 0x28-0x2C
    __vo uint32_t AHB1ENR;      	// 0x30		7.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    __vo uint32_t AHB2ENR;     		// 0x34		7.3.11 RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    __vo uint32_t AHB3ENR;      	// 0x38		7.3.12 RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)
         uint32_t RESERVED2;    	// 0x3C
    __vo uint32_t APB1ENR;      	// 0x40		7.3.13 RCC APB1 peripheral clock enable register (RCC_APB1ENR)
    __vo uint32_t APB2ENR;      	// 0x44		7.3.14 RCC APB2 peripheral clock enable register (RCC_APB2ENR)
         uint32_t RESERVED3[2]; 	// 0x48-0x4C
    __vo uint32_t AHB1LPENR;    	// 0x50		7.3.15 RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)
    __vo uint32_t AHB2LPENR;    	// 0x54		7.3.16 RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)
    __vo uint32_t AHB3LPENR;    	// 0x58		7.3.17 RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR)
         uint32_t RESERVED4;    	// 0x5C
    __vo uint32_t APB1LPENR;    	// 0x60		7.3.18 RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)
    __vo uint32_t APB2LPENR;    	// 0x64		7.3.19 RCC APB2 peripheral clock enabled in low power mode register (RCC_APB2LPENR)
         uint32_t RESERVED5[2]; 	// 0x68-0x6C
    __vo uint32_t BDCR;         	// 0x70		7.3.20 RCC Backup domain control register (RCC_BDCR)
    __vo uint32_t CSR;          	// 0x74		7.3.21 RCC clock control & status register (RCC_CSR)
         uint32_t RESERVED6[2]; 	// 0x78-0x7C
    __vo uint32_t SSCGR;        	// 0x80		7.3.22 RCC spread spectrum clock generation register (RCC_SSCGR)
  	__vo uint32_t PLLI2SCFGR;   	// 0x84		7.3.23 RCC PLLI2S configuration register (RCC_PLLI2SCFGR)
} RCC_RegDef_t;


typedef struct						// 8.4 GPIO registers
{									// Address offset
	__vo	uint32_t MODER;			// 0x00		8.4.1 GPIO port mode register (GPIOx_MODER)
	__vo	uint32_t OTYPER;		// 0x04 	8.4.2 GPIO port output type register (GPIOx_OTYPER)
	__vo	uint32_t OSPEEDR;		// 0x08		8.4.3 GPIO port output speed register (GPIOx_OSPEEDR)
	__vo  	uint32_t PUPDR;			// 0x0C		8.4.4 GPIO port pull-up/pull-down register (GPIOx_PUPDR)
	__vo  	uint32_t IDR;			// 0x10		8.4.5 GPIO port input data register (GPIOx_IDR)
	__vo  	uint32_t ODR;			// 0x14		8.4.6 GPIO port output data register (GPIOx_ODR)
	__vo	uint32_t BSRR;			// 0x18		8.4.7 GPIO port bit set/reset register (GPIOx_BSRR)
	__vo	uint32_t LCKR;			// 0x1C		8.4.8 GPIO port configuration lock register (GPIOx_LCKR)
	__vo	uint32_t AFR[2];		// 0x20		8.4.9 GPIO alternate function low register (GPIOx_AFRL)
} GPIO_RegDef_t;


typedef struct 						// 9.2 SYSCFG registers
{									// Address offset
	__vo	uint32_t MEMRMP;		// 0x00		9.2.1 SYSCFG memory remap register (SYSCFG_MEMRMP)
	__vo	uint32_t PMC;			// 0x04		9.2.2 SYSCFG peripheral mode configuration register (SYSCFG_PMC)
	__vo	uint32_t EXTICR[4];		// 0x08-14	9.2.3 SYSCFG external interrupt configuration register 1-4 (SYSCFG_EXTICR1-4)
			uint32_t RESERVED[2];	// 0x20		9.2.7 Compensation cell control register (SYSCFG_CMPCR)
	__vo	uint32_t CMPCR;			//
			uint32_t RESERVERD[2];	//
	__vo	uint32_t CFGR;			//
} SYSCFG_RegDef_t;

typedef struct 						// 12.3 EXTI registers
{									// Address offset
	__vo	uint32_t IMR;			// 0x00		12.3.1 Interrupt mask register (EXTI_IMR)
	__vo	uint32_t EMR;			// 0x04		12.3.2 Event mask register (EXTI_EMR)
	__vo	uint32_t RTSR;			// 0x08		12.3.3 Rising trigger selection register (EXTI_RTSR)
	__vo	uint32_t FTSR;			// 0x0C 	12.3.4 Falling trigger selection register (EXTI_FTSR)
	__vo	uint32_t SWIER;			// 0x10		12.3.5 Software interrupt event register (EXTI_SWIER)
	__vo	uint32_t PR;			// 0x14		12.3.6 Pending register (EXTI_PR)

} EXTI_RegDef_t;


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

// 7.3.14 RCC APB2 peripheral clock enable register (RCC_APB2ENR)
#define 	SYSCFG_PCLK_EN()	( RCC->APB2ENR |= (1 << 14) )


/*
 * Returns port code for given GPIOx base address
 * with C-Conditionals Operators
 * */
#define GPIO_BASEADDR_TO_CODE(x)	   ((x == GPIOA) ? 0 :\
										(x == GPIOB) ? 1 :\
										(x == GPIOC) ? 2 :\
										(x == GPIOD) ? 3 :\
										(x == GPIOE) ? 4 :\
										(x == GPIOF) ? 5 :\
										(x == GPIOG) ? 6 :\
										(x == GPIOH) ? 7 :\
										(x == GPIOI) ? 8 : 0)


#define IRQ_NO_EXTI0		6
#define IRQ_NO_EXTI1		7
#define IRQ_NO_EXTI2		8
#define IRQ_NO_EXTI3		9
#define IRQ_NO_EXTI4		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10	40

#define NVIC_IRQ_PRIO0		0
#define NVIC_IRQ_PRIO1		1
#define NVIC_IRQ_PRIO2		2
#define NVIC_IRQ_PRIO3		3
#define NVIC_IRQ_PRIO4		4
#define NVIC_IRQ_PRIO5		5
#define NVIC_IRQ_PRIO6		6
#define NVIC_IRQ_PRIO7		7
#define NVIC_IRQ_PRIO8		8
#define NVIC_IRQ_PRIO9		9
#define NVIC_IRQ_PRIO10		10
#define NVIC_IRQ_PRIO11		11
#define NVIC_IRQ_PRIO12		12
#define NVIC_IRQ_PRIO13		13
#define NVIC_IRQ_PRIO14		14
#define NVIC_IRQ_PRIO15		15

// Some generic macros -> level it for all drivers

#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET

#endif /* STM32F407XX_H_ */
