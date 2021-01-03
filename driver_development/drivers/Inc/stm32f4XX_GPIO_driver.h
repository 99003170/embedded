/*
 * stm32f4XX_GPIO_driver.h
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003172
 */
#include "stm32f4xx.h"
#ifndef INC_STM32F4XX_GPIO_DRIVER_H_
#define INC_STM32F4XX_GPIO_DRIVER_H_

/* GPIO Pin Configuration*/
typedef struct
{
	uint8_t GPIO_Pin_Number;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_Pin_Speed;
	uint8_t GPIO_Pin_PuPd_Control;
	uint8_t GPIO_Pin_OP_Type;
	uint8_t GPIO_Pin_Alt_Fun_Mode;
}GPIO_PIN_CONFIG_T;

/* GPIO Handle Structure */
typedef struct
{
	GPIO_Reg_def_t *pGPIOx;
	GPIO_PIN_CONFIG_T PIN_CONFIG;
}GPIO_HANDLE_T;

/* GPIO pin numbering */
#define GPIO_PIN_NUMBER_0			0
#define GPIO_PIN_NUMBER_1			1
#define GPIO_PIN_NUMBER_2			2
#define GPIO_PIN_NUMBER_3			3
#define GPIO_PIN_NUMBER_4			4
#define GPIO_PIN_NUMBER_5			5
#define GPIO_PIN_NUMBER_6			6
#define GPIO_PIN_NUMBER_7			7
#define GPIO_PIN_NUMBER_8			8
#define GPIO_PIN_NUMBER_9			9
#define GPIO_PIN_NUMBER_10			10
#define GPIO_PIN_NUMBER_11			11
#define GPIO_PIN_NUMBER_12			12
#define GPIO_PIN_NUMBER_13			13
#define GPIO_PIN_NUMBER_14			14
#define GPIO_PIN_NUMBER_15			15

/* GPIO Operating Modes */
#define GPIO_PIN_MODE_IN			0
#define GPIO_PIN_MODE_OUT			1
#define GPIO_PIN_MODE_ALT			2
#define GPIO_PIN_MODE_ANALOG		3
#define GPIO_PIN_MODE_RT			4
#define GPIO_PIN_MODE_FT			5
#define GPIO_PIN_MODE_RFT			6

/* GPIO pin possible output speeds*/
#define GPIO_PIN_SPEED_LOW			0
#define GPIO_PIN_SPEED_MEDIUM		1
#define GPIO_PIN_SPEED_FAST			2
#define GPIO_PIN_SPEED_HIGH			3

/* GPIO*/
#define GPIO_PIN_PUPD_CONTROL_0		0
#define GPIO_PIN_PUPD_CONTROL_1		1
#define GPIO_PIN_PUPD_CONTROL_2		2
#define GPIO_PIN_PUPD_CONTROL_3		3

/* GPIO Pin Output Types */
#define GPIO_OP_TYPE_PP				0
#define GPIO_OP_TYPE_OD				1

/* GPIO pin pull up and pull down configuration */
#define GPIO_NO_PUPD				0
#define GPIO_PIN_PU					1
#define GPIO_PIN_PD					2

void GPIO_PeriClockControl(GPIO_Reg_def_t *pGPIOx,uint8_t EnorDi);

void GPIO_Init(GPIO_HANDLE_T *pGPIOHandle);
void GPIO_DeInit(GPIO_Reg_def_t *pGIOx);

uint8_t GPIO_ReadFromInputPin(GPIO_Reg_def_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_Reg_def_t *pGPIOx);


void GPIO_WriteToOutputPin(GPIO_Reg_def_t *pGPIOx,uint8_t PinNumber,uint8_t value);
void GPIO_WriteToOutputPort(GPIO_Reg_def_t *pGPIOx,uint8_t value);
void GPIO_ToggleOutputPin(GPIO_Reg_def_t *pGPIOx,uint8_t PinNumber);

#endif /* INC_STM32F4XX_GPIO_DRIVER_H_ */
