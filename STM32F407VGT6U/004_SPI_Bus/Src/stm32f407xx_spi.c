
// 004_SPI_Bus

#include "stm32f407xx_spi.h"

/* Peripheral Clock Setup */ //
void SPI_PeriClockControl(SPI_RegDef_t* pSPIx, uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if(pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if(pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}
	} else
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_DI();
		}
		else if(pSPIx == SPI2)
		{
			SPI2_PCLK_DI();
		}
		else if(pSPIx == SPI3)
		{
			SPI3_PCLK_DI();
		}
	}
}


/* Init and De-init */
void SPI_Init(SPI_RegDef_t* pSPIx, SPI_InitTypeDef* SPI_InitStruct)
{
	// Funktioniert so nicht in einen register es sei den mit temp |= und dann jedes mal auf 0 setzen...?

	if(SPI_InitStruct->SPIx_CR1 == MSTR) {
		pSPIx->SPI_CR1 |= SPI_InitStruct->SPIx_CR1 << 1;
	}
	else
	{
		// else slave
	}

	pSPIx->SPI_CR1 |= SPI_InitStruct->SPIx_CR1 << 3;

}


#define SPI_DEVICE_MODE_MASTER			1	// CR1: Bit 2 MSTR: Master selection
#define SPI_DEVICE_MODE_SLAVE			0  	// CR1: SSM


// Bit 14 BIDIOE: Output enable in bidirectional mode	SIMPLEX MODE
// Bit 15 BIDIMODE: Bidirectional data mode enable		FULL Duplex / Halfduplex
#define SPI_BUS_Config_FD				1
#define SPI_BUS_Config_HD				2
#define SPI_BUS_Config_Simplex_RXOnly	3

// Bits 5:3 BR[2:0]: Baud rate control
#define SPI_CLK_SPEED_DIV2				0	// 000: fpclk / 2
#define SPI_CLK_SPEED_DIV4				1	// 001: fpclk / 4
#define SPI_CLK_SPEED_DIV8				2	// 010: fpclk / 8
#define SPI_CLK_SPEED_DIV16				3	// 011: fpclk / 16
#define SPI_CLK_SPEED_DIV32				4	// 100: fpclk / 32
#define SPI_CLK_SPEED_DIV64				5	// 101: fpclk / 64
#define SPI_CLK_SPEED_DIV128			6	// 110: fpclk / 128
#define SPI_CLK_SPEED_DIV256			7	// 111: fpclk / 256

// Bit 11 DFF: Data frame format
#define SPI_DFF_8Bits					0
#define SPI_DFF16Bits					1

// Bit1 CPOL: Clock polarity
#define SPI_CPOL_HIGH					1
#define SPI_CPOL_LOW					0

// Bit 0 CPHA: Clock phase
#define SPI_CPHA_HIGH					1
#define SPI_CPHA_LOW					0

// // Bit 9 SSM: Software slave management
#define SPI_SSM_EN						1
#define SPI_SSM_DI						0


// Bit 9 SSM: Software slave management

/* Data Send and Receive */
// Blocking based APIs is not interrupt based
void SPI_SendData(SPI_RegDef_t* pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{

}

void SPI_ReceiveData(SPI_RegDef_t* pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{

}
/* IRQ Configuration and ISR handling */

void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnOrDi)
{

}

void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{

}

void SPI_ClearITPendingBit(SPI_RegDef_t* pSPIx);
