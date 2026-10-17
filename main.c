/**
 ******************************************************************************
 * @file        : main.c
 *
 * @Description :
 *
 * This project interfaces the STM32F407VG microcontroller with the LIS302DL
 * 3-axis MEMS accelerometer using the SPI communication protocol.
 *
 * The accelerometer provides X-axis, Y-axis, and Z-axis acceleration data
 * through the following output registers:
 *
 * LIS_OUT_X : 0x29
 * LIS_OUT_Y : 0x2B
 * LIS_OUT_Z : 0x2D
 *
 * The LIS302DL is configured for a full-scale measurement range of
 * +/- 2g. The raw signed acceleration data is converted into acceleration
 * values using a sensitivity of approximately 18 mg/digit.
 *
 * The calculated X-axis and Y-axis acceleration magnitudes are mapped to
 * the PWM duty cycle of Timer 4 (TIM4) to control LED brightness.
 *
 * TIM4 PWM channel mapping:
 * TIM4_CCR1 : Green LED
 * TIM4_CCR2 : Orange LED
 * TIM4_CCR3 : Red LED
 * TIM4_CCR4 : Blue LED
 *
 * As the accelerometer orientation changes, the measured acceleration
 * values change, resulting in corresponding changes in LED brightness.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f407.h"


int main(void) {

	int8_t x_raw;
	int8_t y_raw;

	int16_t x_accel;
	int16_t y_accel;

	uint16_t red_brightness;
	uint16_t green_brightness;
	uint16_t orange_brightness;
	uint16_t blue_brightness;

	/* 1. Initialize SPI1 GPIO :- PA5 -> SCK , PA6 -> MISO , PA7 -> MOSI */
	SPI1_GPIO_Init();

	TIM4_GPIO_Init();

	/* 2. Initialize LIS302DL CS :- PE3 -> CS */
//	LIS302DL_CS_Init();

	/* 3. Configure SPI1 */
	LIS302DL_SPI1_Init();

	/* 4. Enable SPI */
	SPI_PeripheralControl(SPI1, ENABLE);

	/* 5. Initialize LIS302DL */
	LIS302DL_Init();

	/*==================================================
	 * 7. Initialize TIM4 PWM
	 *
	 * CH1 -> PD12 -> GREEN
	 * CH2 -> PD13 -> ORANGE
	 * CH3 -> PD14 -> RED
	 * CH4 -> PD15 -> BLUE
	 *==================================================*/

	TIM4_PWM_Init();
	/*==================================================
	     * 8. Main loop
	     *==================================================*/

	    while(1)
	    {

	        /* Read X and Y */
	        x_raw = (int8_t)LIS302DL_ReadReg(LIS_OUT_X);
	        y_raw = (int8_t)LIS302DL_ReadReg(LIS_OUT_Y);

	        /* Convert raw value to acceleration :- Result is in mg */
	        x_accel = LIS302DL_ConvertToAcceleration(x_raw);
	        y_accel = LIS302DL_ConvertToAcceleration(y_raw);


	        /* Initially turn all LEDs OFF */
	        red_brightness    = 0;
	        green_brightness  = 0;
	        orange_brightness = 0;
	        blue_brightness   = 0;


	        /* X-axis direction */

	        if(x_accel > 0)
	        {
	            /* +X → RED */
	            red_brightness = CalculateBrightness(x_accel);
	        }
	        else if(x_accel < 0)
	        {
	            /* -X → GREEN */
	            green_brightness = CalculateBrightness(-x_accel);
	        }


	        /* Y-axis direction */

	        if(y_accel > 0)
	        {
	            /* +Y → ORANGE */
	            orange_brightness = CalculateBrightness(y_accel);
	        }
	        else if(y_accel < 0)
	        {
	            /* -Y → BLUE */
	            blue_brightness = CalculateBrightness(-y_accel);
	        }


	        /* Update PWM duty cycles */

	        TIM4_SetCompare(TIM4_CHANNEL_1, green_brightness);
	        TIM4_SetCompare(TIM4_CHANNEL_2, orange_brightness);
	        TIM4_SetCompare(TIM4_CHANNEL_3, red_brightness);
	        TIM4_SetCompare(TIM4_CHANNEL_4, blue_brightness);
	    }

}
