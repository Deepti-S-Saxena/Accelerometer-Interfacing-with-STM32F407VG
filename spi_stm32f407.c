/*
 * spi_stm32f407.c
 */
#include "spi_stm32f407.h"

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi) {
	if (EnorDi == ENABLE) {
		if (pSPIx == SPI1) {
			SPI1_PCLK_EN();
		}
	} else {
		if (pSPIx == SPI1) {
			SPI1_PCLK_DI();
		}
	}
}

void SPI_Init(SPI_Handle_t *pSPIHandle) {
	uint32_t tempreg = 0;

	/* 1. Enable SPI peripheral clock */
	SPI_PeriClockControl(pSPIHandle->pSPIx, ENABLE);

	/* 2. Configure SPI device mode */
	if (pSPIHandle->SPIConfig.SPI_DeviceMode == SPI_DEVICE_MODE_MASTER) {
		tempreg |= (1 << SPI_CR1_MSTR);
	} else {
		tempreg &= ~(1 << SPI_CR1_MSTR);
	}

	/* 3. Configure SPI bus configuration */
	if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD) {
		/* Full duplex
		 * BIDIMODE = 0
		 */
		tempreg &= ~(1 << SPI_CR1_BIDIMODE);
	}

	else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD) {
		/* Half duplex
		 * BIDIMODE = 1
		 */
		tempreg |= (1 << SPI_CR1_BIDIMODE);
	}

	else if (pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY) {
		/* Simplex receive
		 * BIDIMODE = 0
		 * RXONLY  = 1
		 */
		tempreg &= ~(1 << SPI_CR1_BIDIMODE);
		tempreg |= (1 << SPI_CR1_RXONLY);
	}

	/* 4. Configure SPI clock speed */
	tempreg |= (pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR);

	/* 5. Configure CPOL */
	if (pSPIHandle->SPIConfig.SPI_CPOL == SPI_CPOL_HIGH) {
		tempreg |= (1 << SPI_CR1_CPOL);
	} else {
		tempreg &= ~(1 << SPI_CR1_CPOL);
	}

	/* 6. Configure CPHA */
	if (pSPIHandle->SPIConfig.SPI_CPHA == SPI_CPHA_HIGH) {
		tempreg |= (1 << SPI_CR1_CPHA);
	} else {
		tempreg &= ~(1 << SPI_CR1_CPHA);
	}

	/* 7. Configure data frame format */
	if (pSPIHandle->SPIConfig.SPI_DFF == SPI_DFF_16BITS) {
		tempreg |= (1 << SPI_CR1_DFF);
	} else {
		/* 8-bit data */
		tempreg &= ~(1 << SPI_CR1_DFF);
	}

	/* 8. Configure software slave management */
	if (pSPIHandle->SPIConfig.SPI_SSM == SPI_SSM_EN) {
		/* SSM = 1 */
		tempreg |= (1 << SPI_CR1_SSM);

		/* SSI = 1
		 * Keep internal NSS high
		 */
		tempreg |= (1 << SPI_CR1_SSI);
	} else {
		/* Hardware slave management */
		tempreg &= ~(1 << SPI_CR1_SSM);
	}

	/* 9. Write final configuration into CR1 */
	pSPIHandle->pSPIx->CR1 |= tempreg;
}

void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
        pSPIx->CR1 |= (1 << SPI_CR1_SPE);
    }
    else
    {
        pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
    }
}
