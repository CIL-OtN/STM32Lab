
// 004_SPI_Bus

#ifndef STM32F407XX_SPI_H_
#define STM32F407XX_SPI_H_

#include "stm32f407xx.h"

typedef enum						// 28.5.1 SPI control register 1 (SPI_CR1) (not used in I2S mode)
{
	CPHA 		= 0x00,		// Bit 0 CPHA: Clock phase
	CPOL 		= 0x01, 	// Bit1 CPOL: Clock polarity
	MSTR 		= 0x02, 	// Bit 2 MSTR: Master selection
	BR 			= 0x03, 	// Bits 5:3 BR[2:0]: Baud rate control
	SPE 		= 0x06, 	// Bit 6 SPE: SPI enable
	LSBFIRST 	= 0x07,		// Bit 7 LSBFIRST: Frame format
	SSI 		= 0x08, 	// Bit 8 SSI: Internal slave select
	SSM 		= 0x09, 	// Bit 9 SSM: Software slave management
	RXONLY 		= 0x0A,		// Bit 10 RXONLY: Receive only
	DFF 		= 0x0B, 	// Bit 11 DFF: Data frame format
	CRCNEXT 	= 0x0C, 	// Bit 12 CRCNEXT: CRC transfer next
	CRCEN 		= 0x0D, 	// Bit 13 CRCEN: Hardware CRC calculation enable
	BIDIOE 		= 0x0E, 	// Bit 14 BIDIOE: Output enable in bidirectional mode
	BIDIMODE 	= 0x0F 		// Bit 15 BIDIMODE: Bidirectional data mode enable

} SPIx_CR1_Typedef;

// 28.5.1 SPI control register 1 (SPI_CR1) (not used in I2S mode)
// Bits 5:3 BR[2:0]: Baud rate control
#define SPI_BaudRatePrescaler_2         ((uint16_t)0x0000)
#define SPI_BaudRatePrescaler_4         ((uint16_t)0x0008)
#define SPI_BaudRatePrescaler_8         ((uint16_t)0x0010)
#define SPI_BaudRatePrescaler_16        ((uint16_t)0x0018)
#define SPI_BaudRatePrescaler_32        ((uint16_t)0x0020)
#define SPI_BaudRatePrescaler_64        ((uint16_t)0x0028)
#define SPI_BaudRatePrescaler_128       ((uint16_t)0x0030)
#define SPI_BaudRatePrescaler_256       ((uint16_t)0x0038)


typedef enum 						// 28.5.2 SPI control register 2 (SPI_CR2)
{
	RXDMAEN		= 0x00, 	// Bit 0 RXDMAEN: Rx buffer DMA enable
	TXDMAEN		= 0x01, 	// Bit 1 TXDMAEN: Tx buffer DMA enable
	SSOE 		= 0x02, 	// Bit 2 SSOE: SS output enable
 	 								// Bit 3 Reserved. Forced to 0 by hardware.
	FRF 		= 0x04, 	// Bit 4 FRF: Frame format
	ERRIE 		= 0x05, 	// Bit 5 ERRIE: Error interrupt enable
	RXNEIE		= 0x06, 	// Bit 6 RXNEIE: RX buffer not empty interrupt enable
	TXEIE		= 0x07 	// Bit 7 TXEIE: Tx buffer empty interrupt enable
									// Bits 15:8 Reserved, must be kept at reset value.
} SPIx_CR2_TypeDef;


typedef enum 						// 28.5.3 SPI status register (SPI_SR)
{
	RXNE 		= 0x00, 	// Bit 0 RXNE: Receive buffer not empty
	TXE			= 0x01, 	// Bit 1 TXE: Transmit buffer empty
	CHSIDE		= 0x02, 	// Bit 2 CHSIDE: Channel side
	UDR			= 0x03, 	// Bit 3 UDR: Underrun flag
	CRCERR		= 0x04, 	// Bit 4 CRCERR: CRC error flag
	MODF		= 0x05, 	// Bit 5 MODF: Mode fault
	OVR			= 0x06, 	// Bit 6 OVR: Overrun flag
	BSY			= 0x07, 	// Bit 7 BSY: Busy flag
	FRE			= 0x08 	// Bit 8 FRE: Frame format error
									// Bits 15:9 Reserved. Forced to 0 by hardware.
} SPIx_SR_TypeDef;

typedef enum 						// 28.5.4 SPI data register (SPI_DR)
{
	DR0			= 0x00,
	DR1			= 0x01,
	DR2			= 0x02,
	DR3			= 0x03,
	DR4			= 0x04,
	DR5			= 0x05,
	DR6			= 0x06,
	DR7			= 0x07,
	DR8			= 0x08,
	DR9			= 0x09,
	DR10		= 0x10,
	DR11		= 0x11,
	DR12		= 0x12,
	DR13		= 0x13,
	DR14		= 0x14,
	DR15		= 0x15,
	// same in CRC RXCRC snd TXCRC ...
} SPIx_DR_TypeDef;


//typedef enum 						// 28.5.5 SPI CRC polynomial register (SPI_CRCPR) (not used in I2S mode)
//{
////	CRC[15] 	= 0x00 	// Bits 15:0 CRCPOLY[15:0]: CRC polynomial register
//
//} SPIx_CRCPR_TypeDef;


//typedef enum 						// 28.5.6 SPI RX CRC register (SPI_RXCRCR) (not used in I2S mode)
//{
////	RXCRC[15] 	= 0x00		// Bits 15:0 RXCRC[15:0]: Rx CRC register
//
//} SPIx_RXCRCR_TypeDef;


//typedef enum 						// 28.5.7 SPI TX CRC register (SPI_TXCRCR) (not used in I2S mode)
//{
////	TXCRC[15] 	= 0x00		// Bits 15:0 TXCRC[15:0]: Tx CRC register
//
//} SPIx_TXCRCR_TypeDef;


typedef enum 						// 28.5.8 SPI_I2S configuration register (SPI_I2SCFGR)
{
	CHLEN		= 0x00, 	// Bit 0 CHLEN: Channel length (number of bits per audio channel)
//	DATLEN[2]	= 0x01, 	// Bits 2:1 DATLEN: Data length to be transferred
	CKPOL		= 0x03, 	// Bit 3 CKPOL: Steady state clock polarity
//	I2SSTD[2]	= 0x04, 	// Bits 5:4 I2SSTD: I2S standard selection
									// Bit 6 Reserved: forced at 0 by hardware
	PCMSYNC		= 0x07, 	// Bit 7 PCMSYNC: PCM frame synchronization
//	I2SCFG[2]	= 0x08, 	// Bits 9:8 I2SCFG: I2S configuration mode
	I2SE		= 0x0A, 	// Bit 10 I2SE: I2S Enable
	I2SMOD		= 0x0B 	// Bit 11 I2SMOD: I2S mode selection
									// Bits 15:12 Reserved, must be kept at reset value.
} SPIx_I2SCFGR_TypeDef;


typedef enum 						// 28.5.9 SPI_I2S prescaler register (SPI_I2SPR)
{
//	 I2SDIV[8]	= 0x00, 	// Bits 7:0 I2SDIV: I2S Linear prescaler
	 ODD		= 0x08, 	// Bit 8 ODD: Odd factor for the prescaler
	 MCKOE		= 0x09		// Bit 9 MCKOE: Master clock output enable
									// Bits 15:10 Reserved, must be kept at reset value.
} SPIx_I2SPR_TypeDef;


typedef struct
{
	// SPI_RegDef_t *pSPIx;

	//uint32_t SPI_Pin;

	SPIx_CR1_Typedef SPIx_CR1;

	SPIx_CR2_TypeDef SPIx_CR2;

	SPIx_SR_TypeDef SPIx_SR;

//  SPIx_DR_TypeDef SPIx_DR;
//
//  SPIx_CRCPR_TypeDef SPIx_CRCPR;
//
//  SPIx_RXCRCR_TypeDef SPI_RXCRCR;
//
//  SPIx_TXCRCR_TypeDef SPI_TXCRCR;

	SPIx_I2SCFGR_TypeDef SPI_I2SCFGR;

	SPIx_I2SPR_TypeDef SPI_I2SPR;

} SPI_InitTypeDef;


// example from video
//typedef struct
//{
//	uint8_t SPI_DeviceMode;
//	uint8_t SPI_BusConfig;
//	uint8_t SPI_SclkSpeed;
//	uint8_t SPI_DFF;
//	uint8_t SPI_CPOL;
//	uint8_t SPI_CPHA;
//	uint8_t SPI_SSM;
//
//} SPI_Config_t;



/* Peripheral Clock Setup */
void SPI_PeriClockControl(SPI_RegDef_t* pSPIx, uint8_t EnOrDi);


/* Init and De-init */
void SPI_Init(SPI_RegDef_t* pSPIx, SPI_InitTypeDef* SPI_InitStruct);

/* Data Send and Receive */
// Blocking based APIs is not interrupt based

void SPI_SendData(SPI_RegDef_t* pSPIx, uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t* pSPIx, uint8_t *pRxBuffer, uint32_t Len);

/* IRQ Configuration and ISR handling */

void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnOrDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);

void SPI_ClearITPendingBit(SPI_RegDef_t* pSPIx); // -> Im Video: (SPI_Handle_t *pHandle); TODO


// SPI APIs

// SPI Initialization / peripheral clock control

// SPI_Tx

// SPI_Rx

// SPI Interrupt config. & handling

// Other SPI management APIs


#endif /* STM32F407XX_SPI_H_ */



