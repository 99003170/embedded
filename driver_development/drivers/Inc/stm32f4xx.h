/*
 * stm32f4xx.h
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003172
 */
#include <stdint.h>
#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_
#define __vo volatile

/* other definitions*/
#define ENABLE 			1
#define DISABLE 		0
#define GPIO_PIN_SET 	ENABLE
#define GPIO_PIN_RESET 	DISABLE

/* Defining macros for the various memory */
#define FLASH_ADDR 		0x80000000U
#define SRAM1_ADDR 	    0x20000000U
#define SRAM2_ADDR		0x2001C000U
#define ROM_ADDR		0X1FFF0000U
#define SRAM_ADDR		SRAM1_ADDR

/* Defining macros for bus system */
#define AHB1_ADDR		0x40020000U
#define AHB2_ADDR		0x50000000U
#define APB1_ADDR		0x40000000U
#define APB2_ADDR		0x40010000U
#define PERI_ADDR		APB1_ADDR

/* Defining macros for peripherals hanging on AHB1 Bus */
#define GPIOA_ADDR		(AHB1_ADDR + 0x0000U)
#define GPIOB_ADDR		(AHB1_ADDR + 0x0400U)
#define GPIOC_ADDR		(AHB1_ADDR + 0x0800U)
#define GPIOD_ADDR		(AHB1_ADDR + 0x0C00U)
#define GPIOE_ADDR		(AHB1_ADDR + 0x1000U)
#define GPIOF_ADDR		(AHB1_ADDR + 0x1400U)
#define GPIOG_ADDR		(AHB1_ADDR + 0x1800U)
#define GPIOH_ADDR		(AHB1_ADDR + 0x1C00U)
#define GPIOI_ADDR		(AHB1_ADDR + 0x2000U)
#define RCC_ADDR		(AHB1_ADDR + 0x3800U)

/*Defining the macros for peripherals which are hanging on to APB1 bus*/

#define SPI2_I2S2_ADDR		(APB1_ADDR	+ 0X3800U)
#define SPI3_I2S3_ADDR		(APB1_ADDR	+ 0X3C00U)

#define USART2_ADDR			(APB1_ADDR	+ 0X4400U)
#define USART3_ADDR			(APB1_ADDR	+ 0X4800U)

#define UART4_ADDR			(APB1_ADDR	+ 0X4C00U)
#define UART5_ADDR			(APB1_ADDR	+ 0X5000U)

#define I2C1_ADDR			(APB1_ADDR	+ 0X5400U)
#define I2C2_ADDR			(APB1_ADDR	+ 0X5800U)
#define I2C3_ADDR			(APB1_ADDR	+ 0X5C00U)

#define CAN1_ADDR			(APB1_ADDR	+ 0X6400U)
#define CAN2_ADDR			(APB1_ADDR	+ 0X6800U)

/*Defining the macros for peripherals which are hanging on to APB2 bus*/

#define USART1_ADDR			(APB2_ADDR	+ 0X1000U)
#define USART6_ADDR			(APB2_ADDR	+ 0X1400U)
#define SPI1_ADDR			(APB2_ADDR	+ 0X3000U)

#define RCC ((RCC_GPIO_Reg_def_t*)RCC_ADDR)
/* GPIO Peripheral Registers */
typedef struct
{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t LCKR;
	uint32_t AFR[2];		//AFRL[0](Low Register) & AFRH[1](High Register)
}GPIO_Reg_def_t;

/* RCC Registers*/
typedef struct
{
	__vo uint32_t RCC_CR;
	__vo uint32_t RCC_PLLCFGR;
	__vo uint32_t RCC_CFGR;
	__vo uint32_t RCC_CIR;
	__vo uint32_t RCC_AHB1RSTR;
	__vo uint32_t RCC_AHB2RSTR;
	__vo uint32_t RCC_AHB3RSTR;
	uint32_t RESERVED0;
	__vo uint32_t RCC_APB1RSTR;
	__vo uint32_t RCC_APB2RSTR;
	uint32_t RESERVED1[2];
	__vo uint32_t RCC_AHB1ENR;
	__vo uint32_t RCC_AHB2ENR;
	uint32_t RESERVED2[2];
	__vo uint32_t RCC_AHB3ENR;
	__vo uint32_t RCC_APB1ENR;
	__vo uint32_t RCC_APB2ENR;
	__vo uint32_t RCC_AHB1LPENR;
	__vo uint32_t RCC_AHB2LPENR;
	__vo uint32_t RCC_AHB3LPENR;
	__vo uint32_t RCC_APB1LPENR;
	__vo uint32_t RCC_APB2LPENR;
	__vo uint32_t RCC_BDCR;
	__vo uint32_t RCC_CSR;
	__vo uint32_t RCC_SSCGR;
	__vo uint32_t RCC_PLLI2SCFGR;
	__vo uint32_t RCC_PLLSAICFGR;
	__vo uint32_t RCC_DCKCFGR;
} RCC_GPIO_Reg_def_t;


/* GPIO Clock Enable */
#define GPIOA_PE_CLOCK_ENABLE()		RCC->RCC_AHB1ENR |= 1<<0
#define GPIOB_PE_CLOCK_ENABLE()		RCC->RCC_AHB1ENR |= 1<<1
#define GPIOC_PE_CLOCK_ENABLE()		RCC->RCC_AHB1ENR |= 1<<2
#define GPIOD_PE_CLOCK_ENABLE()		RCC->RCC_AHB1ENR |= 1<<3
#define GPIOE_PE_CLOCK_ENABLE()		RCC->RCC_AHB1ENR |= 1<<4
#define GPIOF_PE_CLOCK_ENABLE()		RCC->RCC_AHB1ENR |= 1<<5
#define GPIOG_PE_CLOCK_ENABLE()		RCC->RCC_AHB1ENR |= 1<<6
#define GPIOH_PE_CLOCK_ENABLE()		RCC->RCC_AHB1ENR |= 1<<7
#define GPIOI_PE_CLOCK_ENABLE()		RCC->RCC_AHB1ENR |= 1<<8

/* GPIO Clock Disable
#define GPIOA_PE_CLOCK_DISABLE()	RCC->RCC_AHB1ENR &= ~(1<<0)
#define GPIOB_PE_CLOCK_DISABLE()	RCC->RCC_AHB1ENR &= ~(1<<0)
#define GPIOC_PE_CLOCK_DISABLE()	RCC->RCC_AHB1ENR &= ~(1<<0)
#define GPIOD_PE_CLOCK_DISABLE()	RCC->RCC_AHB1ENR &= ~(1<<0)
#define GPIOE_PE_CLOCK_DISABLE()	RCC->RCC_AHB1ENR &= ~(1<<0)
#define GPIOF_PE_CLOCK_DISABLE()	RCC->RCC_AHB1ENR &= ~(1<<0)
#define GPIOG_PE_CLOCK_DISABLE()	RCC->RCC_AHB1ENR &= ~(1<<0)
#define GPIOH_PE_CLOCK_DISABLE()	RCC->RCC_AHB1ENR &= ~(1<<0)
#define GPIOI_PE_CLOCK_DISABLE()	RCC->RCC_AHB1ENR &= ~(1<<0)*/

/* GPIO Clock Reset */
#define GPIOA_PE_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1<<0);RCC->RCC_AHB1RSTR &= ~(1<<0);}while(DISABLE)
#define GPIOB_PE_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1<<1);RCC->RCC_AHB1RSTR &= ~(1<<1);}while(DISABLE)
#define GPIOC_PE_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1<<2);RCC->RCC_AHB1RSTR &= ~(1<<2);}while(DISABLE)
#define GPIOD_PE_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1<<3);RCC->RCC_AHB1RSTR &= ~(1<<3);}while(DISABLE)
#define GPIOE_PE_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1<<4);RCC->RCC_AHB1RSTR &= ~(1<<4);}while(DISABLE)
#define GPIOF_PE_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1<<5);RCC->RCC_AHB1RSTR &= ~(1<<5);}while(DISABLE)
#define GPIOG_PE_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1<<6);RCC->RCC_AHB1RSTR &= ~(1<<6);}while(DISABLE)
#define GPIOH_PE_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1<<7);RCC->RCC_AHB1RSTR &= ~(1<<7);}while(DISABLE)
#define GPIOI_PE_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1<<8);RCC->RCC_AHB1RSTR &= ~(1<<8);}while(DISABLE)

/* GPIO Peripheral */
#define GPIOA ((GPIO_Reg_def_t*)GPIOA_ADDR)
#define GPIOB ((GPIO_Reg_def_t*)GPIOB_ADDR)
#define GPIOC ((GPIO_Reg_def_t*)GPIOC_ADDR)
#define GPIOD ((GPIO_Reg_def_t*)GPIOD_ADDR)
#define GPIOE ((GPIO_Reg_def_t*)GPIOE_ADDR)
#define GPIOF ((GPIO_Reg_def_t*)GPIOF_ADDR)
#define GPIOG ((GPIO_Reg_def_t*)GPIOG_ADDR)
#define GPIOH ((GPIO_Reg_def_t*)GPIOH_ADDR)
#define GPIOI ((GPIO_Reg_def_t*)GPIOI_ADDR)

#endif /* INC_STM32F4XX_H_ */
