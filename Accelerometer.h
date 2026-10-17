/*
 * Accelerometer.h
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#include "stm32f407.h"

/* LIS302DL Chip Select */
#define LIS302DL_CS_PORT    GPIOE
#define LIS302DL_CS_PIN     3


/* ============================================================
   LIS302DL REGISTER DEFINITIONS
   ============================================================ */

#define LIS_WHO_AM_I    0x0F

#define LIS_CTRL_REG1   0x20
#define LIS_CTRL_REG2   0x21
#define LIS_CTRL_REG3   0x22

#define LIS_STATUS_REG  0x27

#define LIS_OUT_X       0x29
#define LIS_OUT_Y       0x2B
#define LIS_OUT_Z       0x2D

/* CS control macros */
#define CS_LOW()   (LIS302DL_CS_PORT->ODR &= ~(1 << LIS302DL_CS_PIN))
#define CS_HIGH()  (LIS302DL_CS_PORT->ODR |=  (1 << LIS302DL_CS_PIN))

/* Intilization of Accelerometer, SPI_GPIO, SPI_Init, Timer4_GPIO, Timer4_PWM */
void LIS302DL_CS_Init(void);
void LIS302DL_Init(void);

void SPI1_GPIO_Init(void);
void LIS302DL_SPI1_Init(void);

void TIM4_GPIO_Init(void);
void TIM4_PWM_Init(void);

uint8_t SPI_TransmitReceive(SPI_RegDef_t *pSPIx, uint8_t data);

/* Accelerometer Calculations */
int16_t LIS302DL_ConvertToAcceleration(int8_t raw);
uint16_t CalculateBrightness(int16_t acceleration_mg);

uint8_t LIS302DL_ReadReg(uint8_t RegAddress);
void LIS302DL_WriteReg(uint8_t RegAddress, uint8_t Data);

#endif /* ACCELEROMETER_H_ */
