
/* timer4_stm32f407.h */

#ifndef TIMER4_STM32F407_H_
#define TIMER4_STM32F407_H_

#include "stm32f407.h"

/* TIM4 configuration structure */
typedef struct
{
    uint16_t Prescaler;
    uint32_t AutoReload;
    uint8_t  CounterMode;
    uint8_t  AutoReloadPreload;

} TIM4_Config_t;


/* TIM4 handle structure */
typedef struct
{
    TIM_RegDef_t *pTIM4;
    TIM4_Config_t TIM4Config;

} TIM4_Handle_t;

/* Counter mode */
#define TIM4_COUNTER_UP       0
#define TIM4_COUNTER_DOWN     1


/* Auto reload preload */
#define TIM4_ARPE_DISABLE     0
#define TIM4_ARPE_ENABLE      1


/* PWM modes */
#define TIM4_PWM_MODE1        6
#define TIM4_PWM_MODE2        7

/* TIM4 channels */
#define TIM4_CHANNEL_1        1
#define TIM4_CHANNEL_2        2
#define TIM4_CHANNEL_3        3
#define TIM4_CHANNEL_4        4

/* TIM4 peripheral clock control */
void TIM4_PeriClockControl(uint8_t EnorDi);

/* TIM4 initialization */
void TIM4_Init(TIM4_Handle_t *pTIM4Handle);

/* TIM4 de-initialization */
void TIM4_DeInit(void);

/* TIM4 peripheral control */
void TIM4_PeripheralControl(uint8_t EnorDi);

/* TIM4 counter control */
void TIM4_Start(void);
void TIM4_Stop(void);

/* TIM4 PWM configuration */
void TIM4_PWMConfig(uint8_t Channel, uint8_t PWMMode);

/* TIM4 PWM duty cycle */
void TIM4_SetCompare(uint8_t Channel, uint32_t Value);

/* TIM4 counter */
void TIM4_SetCounter(uint32_t Value);
uint32_t TIM4_GetCounter(void);

/* TIM4 interrupt flag */
#define TIM4_UPDATE_FLAG      (1 << TIM_SR_UIF)


#endif /* TIMER4_STM32F407_H_ */
