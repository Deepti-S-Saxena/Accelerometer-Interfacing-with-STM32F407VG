/*
 * stm32f407vg.h
 */

#ifndef STM32F407_H_
#define STM32F407_H_

#include<stdint.h>

/**********************************Processor Specific Details **********************************/

/* ARM Cortex M4 Processor NVIC ISERx register Addresses */

#define NVIC_ISER0          ((volatile uint32_t*)0xE000E100 )
#define NVIC_ISER1          ((volatile uint32_t*)0xE000E104 )
#define NVIC_ISER2          ((volatile uint32_t*)0xE000E108 )
#define NVIC_ISER3          ((volatile uint32_t*)0xE000E10c )

/* ARM Cortex M4 Processor NVIC ICERx register Addresses */
#define NVIC_ICER0 			((volatile uint32_t*)0XE000E180)
#define NVIC_ICER1 			((volatile uint32_t*)0XE000E184)
#define NVIC_ICER2   		((volatile uint32_t*)0XE000E188)
#define NVIC_ICER3 			((volatile uint32_t*)0XE000E18C)

/* ARM Cortex Mx Processor Priority Register Address Calculation */
#define NVIC_PR_BASE_ADDR ((volatile uint32_t*)0xE000E400)

/* ARM Cortex Mx Processor number of priority bits implemented in Priority Register */
#define NO_PR_BITS_IMPLEMENTED  4

/* base addresses of Flash and SRAM memories */

#define FLASH_BASEADDR 		0x08000000UL
#define SRAM1_BASEADDR 		0x20000000UL
#define SRAM2_BASEADDR 		0x2001C000UL
#define ROM_BASEADDR 		0x1FFF0000UL
#define SRAM 				SRAM1_BASEADDR

/* AHBx and APBx Bus Peripheral base addresses */

#define PERIPH_BASEADDR 		0x40000000UL
#define APB1PERIPH_BASEADDR 	PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR 	0x40010000UL
#define AHB1PERIPH_BASEADDR 	0x40020000UL
#define AHB2PERIPH_BASEADDR 	0x50000000UL

/* Base addresses of peripherals which are hanging on AHB1 bus */

#define GPIOA_BASEADDR                   (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR                   (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR 					 (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR 					 (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR                   (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR                   (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR 					 (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR 					 (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR 					 (AHB1PERIPH_BASEADDR + 0x2000)
#define RCC_BASEADDR                     (AHB1PERIPH_BASEADDR + 0x3800)

/* Base addresses of peripherals which are hanging on APB1 bus */

#define USART1_BASEADDR    				(APB2PERIPH_BASEADDR + 0x1000)
#define USART2_BASEADDR 				(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR 				(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR 					(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR 					(APB1PERIPH_BASEADDR + 0x5000)
#define SPI2_BASEADDR 					(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR 					(APB1PERIPH_BASEADDR + 0x3C00)
#define TIM4_BASEADDR    				(APB1PERIPH_BASEADDR + 0x0800)
#define USART6_BASEADDR    				(APB2PERIPH_BASEADDR + 0x1400)

/* Base addresses of peripherals which are hanging on APB2 bus */

#define EXTI_BASEADDR 				(APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR         	(APB2PERIPH_BASEADDR + 0x3800)
#define SPI1_BASEADDR 				(APB2PERIPH_BASEADDR + 0x3000)

/**********************************peripheral register definition structures **********************************/

typedef struct {
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2]; /*!< AFR[0] : GPIO alternate function low register, AF[1] : GPIO alternate function high register     Address offset: 0x20-0x24 */
} GPIO_RegDef_t;

/* peripheral register definition structure for RCC */

typedef struct {
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	uint32_t RESERVED2;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	uint32_t RESERVED3[2];
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	uint32_t RESERVED4;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	uint32_t RESERVED5[2];
	volatile uint32_t BDCR; /* Address offset: 0x70 */
	volatile uint32_t CSR; /*!< *,     Address offset: 0x74 */
	uint32_t RESERVED6[2]; /*!< Reserved, 0x78-0x7C                                                  */
	volatile uint32_t SSCGR; /*!< *,     Address offset: 0x80 */
	volatile uint32_t PLLI2SCFGR; /*!< *,     Address offset: 0x84 */
	volatile uint32_t PLLSAICFGR; /*!< *,     Address offset: 0x88 */
	volatile uint32_t DCKCFGR; /*!< *,     Address offset: 0x8C */
	volatile uint32_t CKGATENR; /*!< *,     Address offset: 0x90 */
	volatile uint32_t DCKCFGR2; /*!< *,     Address offset: 0x94 */

} RCC_RegDef_t;

/* peripheral register definition structure for USART */

typedef struct {
	volatile uint32_t SR; /*!< *,     Address offset: 0x00 */
	volatile uint32_t DR; /*!< *,     Address offset: 0x04 */
	volatile uint32_t BRR; /*!< *,     Address offset: 0x08 */
	volatile uint32_t CR1; /*!< *,     Address offset: 0x0C */
	volatile uint32_t CR2; /*!< *,     Address offset: 0x10 */
	volatile uint32_t CR3; /*!< *,     Address offset: 0x14 */
} USART_RegDef_t;

/* peripheral register definition structure for EXTI */
typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

} EXTI_RegDef_t;

/* peripheral register definition structure for SYSCFG */
typedef struct {
	volatile uint32_t MEMRMP; /* Address offset: 0x00 */
	volatile uint32_t PMC; /* Address offset: 0x04 */
	volatile uint32_t EXTICR[4]; /* Address offset: 0x08-0x14 */
	uint32_t RESERVED1[2]; /* Reserved, 0x18-0x1C */
	volatile uint32_t CMPCR; /* Address offset: 0x20 */
	uint32_t RESERVED2[2]; /* Reserved, 0x24-0x28 */
	volatile uint32_t CFGR; /* Address offset: 0x2C */
} SYSCFG_RegDef_t;

/* peripheral register definition structure for SPI */
typedef struct {
	volatile uint32_t CR1; /*!< TODO,     Address offset: 0x00 */
	volatile uint32_t CR2; /*!< TODO,     Address offset: 0x04 */
	volatile uint32_t SR; /*!< TODO,     Address offset: 0x08 */
	volatile uint32_t DR; /*!< TODO,     Address offset: 0x0C */
	volatile uint32_t CRCPR; /*!< TODO,     Address offset: 0x10 */
	volatile uint32_t RXCRCR; /*!< TODO,     Address offset: 0x14 */
	volatile uint32_t TXCRCR; /*!< TODO,     Address offset: 0x18 */
	volatile uint32_t I2SCFGR; /*!< TODO,     Address offset: 0x1C */
	volatile uint32_t I2SPR; /*!< TODO,     Address offset: 0x20 */
} SPI_RegDef_t;

typedef struct {
	volatile uint32_t CR1;        // 0x00 - Control register 1
	volatile uint32_t CR2;        // 0x04 - Control register 2
	volatile uint32_t SMCR;       // 0x08 - Slave mode control register
	volatile uint32_t DIER;       // 0x0C - DMA/Interrupt enable register
	volatile uint32_t SR;         // 0x10 - Status register
	volatile uint32_t EGR;        // 0x14 - Event generation register
	volatile uint32_t CCMR1;      // 0x18 - Capture/Compare mode register 1
	volatile uint32_t CCMR2;      // 0x1C - Capture/Compare mode register 2
	volatile uint32_t CCER;       // 0x20 - Capture/Compare enable register
	volatile uint32_t CNT;        // 0x24 - Counter
	volatile uint32_t PSC;        // 0x28 - Prescaler
	volatile uint32_t ARR;        // 0x2C - Auto-reload register
	volatile uint32_t RCR;        // 0x30 - Repetition counter
	volatile uint32_t CCR1;       // 0x34 - Capture/Compare register 1
	volatile uint32_t CCR2;       // 0x38 - Capture/Compare register 2
	volatile uint32_t CCR3;       // 0x3C - Capture/Compare register 3
	volatile uint32_t CCR4;       // 0x40 - Capture/Compare register 4
	volatile uint32_t BDTR;       // 0x44 - Break and dead-time register
	volatile uint32_t DCR;        // 0x48 - DMA control register
	volatile uint32_t DMAR;       // 0x4C - DMA address for full transfer
	volatile uint32_t OR;         // 0x50 - Option register

} TIM_RegDef_t;

/* peripheral definitions ( Peripheral base addresses typecasted to xxx_RegDef_t) */

#define GPIOA   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD   ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE   ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF   ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG   ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH   ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI   ((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define USART1    ((USART_RegDef_t*)USART1_BASEADDR)
#define USART2    ((USART_RegDef_t*)USART2_BASEADDR)
#define USART3    ((USART_RegDef_t*)USART3_BASEADDR)
#define UART4     ((USART_RegDef_t*)UART4_BASEADDR)
#define UART5     ((USART_RegDef_t*)UART5_BASEADDR)
#define USART6    ((USART_RegDef_t*)USART6_BASEADDR)

#define RCC ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI ((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1   ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2   ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3   ((SPI_RegDef_t*)SPI3_BASEADDR)
#define TIM4    ((TIM_RegDef_t*)TIM4_BASEADDR)

/* Clock Enable Macros for GPIOx peripherals */

#define GPIOA_PCLK_EN()     	(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 8))

/* Clock Disable Macros for GPIOx peripherals */

#define GPIOA_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 0) )
#define GPIOB_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 1) )
#define GPIOC_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 2) )
#define GPIOD_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 3) )
#define GPIOE_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 4) )
#define GPIOF_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 5) )
#define GPIOG_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 6) )
#define GPIOH_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 7) )
#define GPIOI_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 8) )

/* Clock Enable Macros for USARTx peripherals */
#define USART1_PCCK_EN() (RCC->APB2ENR |= (1 << 4))
#define USART2_PCCK_EN() (RCC->APB1ENR |= (1 << 17))
#define USART3_PCCK_EN() (RCC->APB1ENR |= (1 << 18))
#define UART4_PCCK_EN()  (RCC->APB1ENR |= (1 << 19))
#define UART5_PCCK_EN()  (RCC->APB1ENR |= (1 << 20))
#define USART6_PCCK_EN() (RCC->APB1ENR |= (1 << 5))

/* * Clock Disable Macros for USARTx peripherals * */
#define USART1_PCLK_DI() ( RCC->APB2ENR &= ~(1 << 4) )
#define USART2_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 17) )
#define USART3_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 18) )
#define UART4_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 19) )
#define UART5_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 20) )
#define USART6_PCLK_DI() ( RCC->APB2ENR &= ~(1 << 5) )

/* Clock Enable Macros for SYSCFG peripheral */
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))

/* Clock Disable Macros for SYSCFG peripheral */
#define SYSCFG_PCLK_DI() (RCC->APB2ENR &= ~(1 << 14))

/* Clock Enable Macros for SPIx peripheral */
#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN() (RCC->APB2ENR |= (1 << 13))

/* Clock Disable Macros for SPIx peripherals */
#define SPI1_PCLK_DI()      (RCC->APB2ENR &= ~(1 << 12))

/* Clock Enable Macros for TIMx peripherals */
#define TIM4_PCLK_EN()      (RCC->APB1ENR |= (1 << 2))

/* Clock Disable Macros for TIMx peripherals */
#define TIM4_PCLK_DI()      (RCC->APB1ENR &= ~(1 << 2))


/******************************************************************************************
 * Bit position definitions of TIM4 peripheral
 ******************************************************************************************/

/* Bit position definitions TIM4_CR1 */
#define TIM_CR1_CEN          0
#define TIM_CR1_UDIS         1
#define TIM_CR1_URS          2
#define TIM_CR1_OPM          3
#define TIM_CR1_DIR          4
#define TIM_CR1_CMS          5
#define TIM_CR1_ARPE         7
#define TIM_CR1_CKD          8


/* Bit position definitions TIM4_CR2 */
#define TIM_CR2_CCPC         0
#define TIM_CR2_CCUS         2
#define TIM_CR2_CCDS         3
#define TIM_CR2_MMS          4
#define TIM_CR2_TI1S         7


/* Bit position definitions TIM4_SMCR */
#define TIM_SMCR_SMS         0
#define TIM_SMCR_TS          4
#define TIM_SMCR_MSM         7


/* Bit position definitions TIM4_DIER */
#define TIM_DIER_UIE         0
#define TIM_DIER_CC1IE       1
#define TIM_DIER_CC2IE       2
#define TIM_DIER_CC3IE       3
#define TIM_DIER_CC4IE       4
#define TIM_DIER_TIE         6
#define TIM_DIER_UDE         8
#define TIM_DIER_CC1DE       9
#define TIM_DIER_CC2DE       10
#define TIM_DIER_CC3DE       11
#define TIM_DIER_CC4DE       12
#define TIM_DIER_TDE         14


/* Bit position definitions TIM4_SR */
#define TIM_SR_UIF           0
#define TIM_SR_CC1IF         1
#define TIM_SR_CC2IF         2
#define TIM_SR_CC3IF         3
#define TIM_SR_CC4IF         4
#define TIM_SR_TIF           6
#define TIM_SR_CC1OF         9
#define TIM_SR_CC2OF         10
#define TIM_SR_CC3OF         11
#define TIM_SR_CC4OF         12


/* Bit position definitions TIM4_EGR */
#define TIM_EGR_UG           0
#define TIM_EGR_CC1G         1
#define TIM_EGR_CC2G         2
#define TIM_EGR_CC3G         3
#define TIM_EGR_CC4G         4
#define TIM_EGR_TG           6


/* Bit position definitions TIM4_CCMR1 */
#define TIM_CCMR1_CC1S       0
#define TIM_CCMR1_OC1FE      2
#define TIM_CCMR1_OC1PE      3
#define TIM_CCMR1_OC1M       4
#define TIM_CCMR1_OC1CE      7

#define TIM_CCMR1_CC2S       8
#define TIM_CCMR1_OC2FE      10
#define TIM_CCMR1_OC2PE      11
#define TIM_CCMR1_OC2M       12
#define TIM_CCMR1_OC2CE      15


/* Bit position definitions TIM4_CCMR2 */
#define TIM_CCMR2_CC3S       0
#define TIM_CCMR2_OC3FE      2
#define TIM_CCMR2_OC3PE      3
#define TIM_CCMR2_OC3M       4
#define TIM_CCMR2_OC3CE      7

#define TIM_CCMR2_CC4S       8
#define TIM_CCMR2_OC4FE      10
#define TIM_CCMR2_OC4PE      11
#define TIM_CCMR2_OC4M       12
#define TIM_CCMR2_OC4CE      15


/* Bit position definitions TIM4_CCER */
#define TIM_CCER_CC1E        0
#define TIM_CCER_CC1P        1
#define TIM_CCER_CC1NE       2
#define TIM_CCER_CC1NP       3

#define TIM_CCER_CC2E        4
#define TIM_CCER_CC2P        5
#define TIM_CCER_CC2NE       6
#define TIM_CCER_CC2NP       7

#define TIM_CCER_CC3E        8
#define TIM_CCER_CC3P        9
#define TIM_CCER_CC3NE       10
#define TIM_CCER_CC3NP       11

#define TIM_CCER_CC4E        12
#define TIM_CCER_CC4P        13

/******************************************************************************************
 *Bit position definitions of SPI peripheral
 ******************************************************************************************/
/* Bit position definitions SPI_CR1 */
#define SPI_CR1_CPHA     0
#define SPI_CR1_CPOL       1
#define SPI_CR1_MSTR     2
#define SPI_CR1_BR   3
#define SPI_CR1_SPE     6
#define SPI_CR1_LSBFIRST   7
#define SPI_CR1_SSI     8
#define SPI_CR1_SSM       9
#define SPI_CR1_RXONLY       10
#define SPI_CR1_DFF     11
#define SPI_CR1_CRCNEXT   12
#define SPI_CR1_CRCEN   13
#define SPI_CR1_BIDIOE     14
#define SPI_CR1_BIDIMODE       15

/* Bit position definitions SPI_CR2 */
#define SPI_CR2_RXDMAEN 0
#define SPI_CR2_TXDMAEN 1
#define SPI_CR2_SSOE 2
#define SPI_CR2_FRF 4
#define SPI_CR2_ERRIE 5
#define SPI_CR2_RXNEIE 6
#define SPI_CR2_TXEIE 7


/* Bit position definitions SPI_SR */
#define SPI_SR_RXNE 0
#define SPI_SR_TXE 1
#define SPI_SR_CHSIDE 2
#define SPI_SR_UDR 3
#define SPI_SR_CRCERR 4
#define SPI_SR_MODF 5
#define SPI_SR_OVR 6
#define SPI_SR_BSY 7
#define SPI_SR_FRE 8

/******************************************************************************************
 *Bit position definitions of USART peripheral
 ******************************************************************************************/

/* Bit position definitions USART_CR1 */
#define USART_CR1_SBK 0
#define USART_CR1_RWU 1
#define USART_CR1_RE   2
#define USART_CR1_TE 3
#define USART_CR1_IDLEIE 4
#define USART_CR1_RXNEIE   5
#define USART_CR1_TCIE 6
#define USART_CR1_TXEIE 7
#define USART_CR1_PEIE 8
#define USART_CR1_PS 9
#define USART_CR1_PCE 10
#define USART_CR1_WAKE   11
#define USART_CR1_M 12
#define USART_CR1_UE 13
#define USART_CR1_OVER8   15



/* Bit position definitions USART_CR2 */
#define USART_CR2_ADD   0
#define USART_CR2_LBDL   5
#define USART_CR2_LBDIE   6
#define USART_CR2_LBCL   8
#define USART_CR2_CPHA   9
#define USART_CR2_CPOL   10
#define USART_CR2_STOP   12
#define USART_CR2_LINEN   14


/* Bit position definitions USART_CR3 */
#define USART_CR3_EIE   0
#define USART_CR3_IREN   1
#define USART_CR3_IRLP   2
#define USART_CR3_HDSEL   3
#define USART_CR3_NACK   4
#define USART_CR3_SCEN   5
#define USART_CR3_DMAR   6
#define USART_CR3_DMAT   7
#define USART_CR3_RTSE   8
#define USART_CR3_CTSE   9
#define USART_CR3_CTSIE   10
#define USART_CR3_ONEBIT   11

/* Bit position definitions USART_SR */

#define USART_SR_PE         0
#define USART_SR_FE         1
#define USART_SR_NE         2
#define USART_SR_ORE       3
#define USART_SR_IDLE       4
#define USART_SR_RXNE         5
#define USART_SR_TC         6
#define USART_SR_TXE         7
#define USART_SR_LBD         8
#define USART_SR_CTS         9

/* some generic macros */

#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET    SET
#define GPIO_PIN_RESET  RESET
#define FLAG_RESET      RESET
#define FLAG_SET 		SET

#define IRQ_NO_EXTI0 6
#define IRQ_NO_EXTI1 7
#define IRQ_NO_EXTI2 8
#define IRQ_NO_EXTI3 9
#define IRQ_NO_EXTI4 10
#define IRQ_NO_EXTI9_5 23
#define IRQ_NO_EXTI15_10 40
#define IRQ_NO_SPI1 35
#define IRQ_NO_SPI2         36
#define IRQ_NO_SPI3         51
#define IRQ_NO_SPI4
#define IRQ_NO_I2C1_EV     31
#define IRQ_NO_I2C1_ER     32
#define IRQ_NO_USART1    37
#define IRQ_NO_USART2    38
#define IRQ_NO_USART3    39
#define IRQ_NO_UART4    52
#define IRQ_NO_UART5    53
#define IRQ_NO_USART6    71
#define IRQ_NO_TIM2    28
#define IRQ_NO_TIM3    29
#define IRQ_NO_TIM4    30
#define IRQ_NO_TIM5    50
#define IRQ_NO_TIM6_DAC 54
#define IRQ_NO_TIM7    55

/* macros for all the possible priority levels */
#define NVIC_IRQ_PRI0    0
#define NVIC_IRQ_PRI15    15

#include "gpio_stm32f407.h"
#include "spi_stm32f407.h"
#include "timer4_stm32f407.h"
#include "Accelerometer.h"
#endif /* STM32F407_H_ */
