/*
 * spi_stm32f407.h
 */

#ifndef SPI_STM32F407_H_
#define SPI_STM32F407_H_

#include "stm32f407.h"

/* SPI application states */
#define SPI_READY       0
#define SPI_BUSY_IN_TX  1
#define SPI_BUSY_IN_RX  2

/* SPI configuration structure */
typedef struct
{
    uint8_t SPI_DeviceMode;
    uint8_t SPI_BusConfig;
    uint8_t SPI_SclkSpeed;
    uint8_t SPI_DFF;
    uint8_t SPI_CPOL;
    uint8_t SPI_CPHA;
    uint8_t SPI_SSM;

} SPI_Config_t;

/* SPI handle structure */
typedef struct
{
    SPI_RegDef_t *pSPIx;
    SPI_Config_t SPIConfig;
    uint8_t TxState;
    uint8_t RxState;

} SPI_Handle_t;

/* SPI device mode */
#define SPI_DEVICE_MODE_MASTER       1
#define SPI_DEVICE_MODE_SLAVE        0

/* SPI bus configuration */
#define SPI_BUS_CONFIG_FD            1
#define SPI_BUS_CONFIG_HD            2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY 3

/* SPI clock speed */
#define SPI_SCLK_SPEED_DIV2          0
#define SPI_SCLK_SPEED_DIV4          1
#define SPI_SCLK_SPEED_DIV8          2
#define SPI_SCLK_SPEED_DIV16         3
#define SPI_SCLK_SPEED_DIV32         4
#define SPI_SCLK_SPEED_DIV64         5
#define SPI_SCLK_SPEED_DIV128        6
#define SPI_SCLK_SPEED_DIV256        7

/* SPI data frame format */
#define SPI_DFF_8BITS                0
#define SPI_DFF_16BITS               1

/* SPI clock polarity */
#define SPI_CPOL_LOW                 0
#define SPI_CPOL_HIGH                1

/* SPI clock phase */
#define SPI_CPHA_LOW                 0
#define SPI_CPHA_HIGH                1

/* SPI software slave management */
#define SPI_SSM_DI                   0
#define SPI_SSM_EN                   1

/* SPI peripheral clock control */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/* SPI initialization and de-initialization */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/* SPI peripheral control */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/* SPI flags */
#define SPI_TXE_FLAG       (1 << SPI_SR_TXE)
#define SPI_RXNE_FLAG      (1 << SPI_SR_RXNE)
#define SPI_BUSY_FLAG      (1 << SPI_SR_BSY)

#endif /* SPI_STM32F407_H_ */
