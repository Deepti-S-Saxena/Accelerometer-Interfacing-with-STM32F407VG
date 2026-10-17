/* timer4_stm32f407.c */

#include "timer4_stm32f407.h"

void TIM4_PeriClockControl(uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
    	TIM4_PCLK_EN();
    }
    else
    {
    	TIM4_PCLK_DI();
    }
}

void TIM4_Init(TIM4_Handle_t *pTIM4Handle)
{
    /* Enable TIM4 peripheral clock */
    TIM4_PeriClockControl(ENABLE);

    /* Configure prescaler */
    pTIM4Handle->pTIM4->PSC = pTIM4Handle->TIM4Config.Prescaler;

    /* Configure auto reload */
    pTIM4Handle->pTIM4->ARR = pTIM4Handle->TIM4Config.AutoReload;

    /* Counter direction */
    if (pTIM4Handle->TIM4Config.CounterMode == TIM4_COUNTER_DOWN)
    {
        pTIM4Handle->pTIM4->CR1 |= (1 << TIM_CR1_DIR);
    }
    else
    {
        pTIM4Handle->pTIM4->CR1 &= ~(1 << TIM_CR1_DIR);
    }

    /* Auto-reload preload */
    if (pTIM4Handle->TIM4Config.AutoReloadPreload == TIM4_ARPE_ENABLE)
    {
        pTIM4Handle->pTIM4->CR1 |= (1 << TIM_CR1_ARPE);
    }
    else
    {
        pTIM4Handle->pTIM4->CR1 &= ~(1 << TIM_CR1_ARPE);
    }
}

void TIM4_Start(void)
{
    TIM4->CR1 |= (1 << TIM_CR1_CEN);
}

void TIM4_Stop(void)
{
    TIM4->CR1 &= ~(1 << TIM_CR1_CEN);
}

void TIM4_PWMConfig(uint8_t Channel, uint8_t PWMMode)
{
    switch (Channel)
    {
        case TIM4_CHANNEL_1:

            /* Clear OC1M bits */
            TIM4->CCMR1 &= ~(7 << TIM_CCMR1_OC1M);

            /* Set PWM mode */
            TIM4->CCMR1 |= (PWMMode << TIM_CCMR1_OC1M);

            /* Enable preload for CCR1 */
            TIM4->CCMR1 |= (1 << TIM_CCMR1_OC1PE);

            /* Enable CH1 output */
            TIM4->CCER |= (1 << TIM_CCER_CC1E);

            break;


        case TIM4_CHANNEL_2:

            /* Clear OC2M bits */
            TIM4->CCMR1 &= ~(7 << TIM_CCMR1_OC2M);

            /* Set PWM mode */
            TIM4->CCMR1 |= (PWMMode << TIM_CCMR1_OC2M);

            /* Enable preload for CCR2 */
            TIM4->CCMR1 |= (1 << TIM_CCMR1_OC2PE);

            /* Enable CH2 output */
            TIM4->CCER |= (1 << TIM_CCER_CC2E);

            break;


        case TIM4_CHANNEL_3:

            /* Clear OC3M bits */
            TIM4->CCMR2 &= ~(7 << TIM_CCMR2_OC3M);

            /* Set PWM mode */
            TIM4->CCMR2 |= (PWMMode << TIM_CCMR2_OC3M);

            /* Enable preload for CCR3 */
            TIM4->CCMR2 |= (1 << TIM_CCMR2_OC3PE);

            /* Enable CH3 output */
            TIM4->CCER |= (1 << TIM_CCER_CC3E);

            break;


        case TIM4_CHANNEL_4:

            /* Clear OC4M bits */
            TIM4->CCMR2 &= ~(7 << TIM_CCMR2_OC4M);

            /* Set PWM mode */
            TIM4->CCMR2 |= (PWMMode << TIM_CCMR2_OC4M);

            /* Enable preload for CCR4 */
            TIM4->CCMR2 |= (1 << TIM_CCMR2_OC4PE);

            /* Enable CH4 output */
            TIM4->CCER |= (1 << TIM_CCER_CC4E);

            break;


        default:
            break;
    }
}

void TIM4_SetCompare(uint8_t Channel, uint32_t Value)
{
    switch (Channel)
    {
        case TIM4_CHANNEL_1:
            TIM4->CCR1 = Value;
            break;

        case TIM4_CHANNEL_2:
            TIM4->CCR2 = Value;
            break;

        case TIM4_CHANNEL_3:
            TIM4->CCR3 = Value;
            break;

        case TIM4_CHANNEL_4:
            TIM4->CCR4 = Value;
            break;

        default:
            break;
    }
}
