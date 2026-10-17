/*
 * Accelerometer.c
 */

#include "Accelerometer.h"

void LIS302DL_CS_Init(void) {
	GPIO_Handle_t GPIOE_CS;

	/* Enable GPIOE clock PE3 */
	GPIOE_PCLK_EN();

	GPIOE_CS.pGPIOx = GPIOE;

	GPIOE_CS.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
	GPIOE_CS.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIOE_CS.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GPIOE_CS.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIOE_CS.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOE_CS.GPIO_PinConfig.GPIO_PinAltFunMode = 0;

	GPIO_Init(&GPIOE_CS);

	/* LIS302DL initially deselected */
	GPIOE->ODR |= (1 << 3);
}

void SPI1_GPIO_Init(void) {
	GPIO_Handle_t GPIOA_SPI;

	/* Enable GPIOA clock */
	GPIOA_PCLK_EN();

	/* PA5 - SPI1_SCK */
	GPIOA_SPI.pGPIOx = GPIOA;

	GPIOA_SPI.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinAltFunMode = 5;

	GPIO_Init(&GPIOA_SPI);

	/* PA6 - SPI1_MISO */
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinAltFunMode = 5;

	GPIO_Init(&GPIOA_SPI);

	/* PA7 - SPI1_MOSI */
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOA_SPI.GPIO_PinConfig.GPIO_PinAltFunMode = 5;

	GPIO_Init(&GPIOA_SPI);
}

void LIS302DL_SPI1_Init(void)
{
	SPI_Handle_t SPI1Handle;
	SPI1Handle.pSPIx = SPI1;
	SPI1Handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI1Handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI1Handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV8;
	SPI1Handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI1Handle.SPIConfig.SPI_CPOL = SPI_CPOL_HIGH;
	SPI1Handle.SPIConfig.SPI_CPHA = SPI_CPHA_HIGH;
	SPI1Handle.SPIConfig.SPI_SSM = SPI_SSM_EN;
	SPI_Init(&SPI1Handle);
}

void TIM4_GPIO_Init(void)
{
    GPIO_Handle_t GPIOD_TIM4;

    /* Enable GPIOD clock */
    GPIOD_PCLK_EN();

    GPIOD_TIM4.pGPIOx = GPIOD;

    /* Common configuration */
    GPIOD_TIM4.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    GPIOD_TIM4.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    GPIOD_TIM4.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIOD_TIM4.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIOD_TIM4.GPIO_PinConfig.GPIO_PinAltFunMode = 2;   // AF2 = TIM4


    /* PD12 -> TIM4_CH1 */
    GPIOD_TIM4.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GPIO_Init(&GPIOD_TIM4);


    /* PD13 -> TIM4_CH2 */
    GPIOD_TIM4.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GPIO_Init(&GPIOD_TIM4);


    /* PD14 -> TIM4_CH3 */
    GPIOD_TIM4.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    GPIO_Init(&GPIOD_TIM4);


    /* PD15 -> TIM4_CH4 */
    GPIOD_TIM4.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
    GPIO_Init(&GPIOD_TIM4);
}
void TIM4_PWM_Init(void)
{
    TIM4_Handle_t TIM4Handle;

    /* 1. Configure TIM4 basic parameters */
    TIM4Handle.pTIM4 = TIM4;

    /*
     * Assuming TIM4 input clock = 16 MHz, PSC = 15
     * Timer counter frequency:
          16 MHz / (15 + 1) = 1 MHz
       Therefore:
          1 timer count = 1 us
     */

    TIM4Handle.TIM4Config.Prescaler = 15;

    /*
     * ARR = 999
        PWM frequency:
     *
     * 1 MHz / (999 + 1)
     * = 1 kHz
     */

    TIM4Handle.TIM4Config.AutoReload = 999;

    /* Up-counting */
    TIM4Handle.TIM4Config.CounterMode = TIM4_COUNTER_UP;

    /* Enable ARR preload */
    TIM4Handle.TIM4Config.AutoReloadPreload = TIM4_ARPE_ENABLE;


    /* 2. Initialize TIM4 peripheral */
    TIM4_Init(&TIM4Handle);


    /* 3. Configure all four PWM channels */
    TIM4_PWMConfig(TIM4_CHANNEL_1, TIM4_PWM_MODE1);
    TIM4_PWMConfig(TIM4_CHANNEL_2, TIM4_PWM_MODE1);
    TIM4_PWMConfig(TIM4_CHANNEL_3, TIM4_PWM_MODE1);
    TIM4_PWMConfig(TIM4_CHANNEL_4, TIM4_PWM_MODE1);


    /* 4. Initial brightness */

    /* Initially all LEDs OFF */

    TIM4_SetCompare(TIM4_CHANNEL_1, 0);
    TIM4_SetCompare(TIM4_CHANNEL_2, 0);
    TIM4_SetCompare(TIM4_CHANNEL_3, 0);
    TIM4_SetCompare(TIM4_CHANNEL_4, 0);


    /* 5. Start TIM4 */
    TIM4_Start();
}
uint8_t SPI_TransmitReceive(SPI_RegDef_t *pSPIx, uint8_t data)
{
    uint8_t received_data;

    /* Wait until transmit buffer is empty */
    while (!(pSPIx->SR & (1 << SPI_SR_TXE)))
    {
    }
    /* Send data */
    pSPIx->DR = data;

    /* Wait until receive buffer has data */
    while (!(pSPIx->SR & (1 << SPI_SR_RXNE)))
    {
    }
    /* Read received data */
    received_data = (uint8_t)pSPIx->DR;

    return received_data;
}

uint8_t LIS302DL_ReadReg(uint8_t RegAddress)
{
    uint8_t command;
    uint8_t data;

    command = 0x80 | RegAddress;

    CS_LOW();

    /* Send READ command + register address */
    SPI_TransmitReceive(SPI1, command);

    /* Generate 8 clocks and receive register data */
    data = SPI_TransmitReceive(SPI1, 0x00);

    CS_HIGH();

    return data;
}

void LIS302DL_WriteReg(uint8_t RegAddress, uint8_t Data)
{
    uint8_t command;

    command = RegAddress;

    CS_LOW();

    /* Send WRITE command + register address */
    SPI_TransmitReceive(SPI1, command);

    /* Send data */
    SPI_TransmitReceive(SPI1, Data);

    CS_HIGH();
}

int16_t LIS302DL_ConvertToAcceleration(int8_t raw)
{
    return ((int16_t)raw * 18);
}

uint16_t CalculateBrightness(int16_t acceleration_mg)
{
    uint32_t brightness;

    if(acceleration_mg < 0)
    {
        acceleration_mg = -acceleration_mg;
    }

    if(acceleration_mg > 2286)
    {
        acceleration_mg = 2286;
    }

    brightness = ((uint32_t)acceleration_mg * 999) / 2286;

    return (uint16_t)brightness;
}

void LIS302DL_Init(void)
{
    /* Configure CS pin */
    LIS302DL_CS_Init();

    /* Configure 4-wire SPI mode */
    LIS302DL_WriteReg(0x21, 0x00);

    /* Configure:
       100 Hz
       Active
       ±2.3g
       X + Y + Z enabled
    */
    LIS302DL_WriteReg(0x20, 0x47);
}
