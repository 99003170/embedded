/*
 * led.c
 *
 *  Created on: Dec 29, 2020
 *      Author: 99003172
 */
#include "stm32f4XX_GPIO_driver.h"
void delay(void)
{
	for(uint32_t i=0;i<500000;i++);
}
int main()
{
	GPIO_HANDLE_T GpioLed;
	GpioLed.pGPIOx = GPIOD;
	GpioLed.PIN_CONFIG.GPIO_Pin_Number = GPIO_PIN_NUMBER_13;
	GpioLed.PIN_CONFIG.GPIO_PinMode = GPIO_PIN_MODE_OUT;
	GpioLed.PIN_CONFIG.GPIO_Pin_Speed = GPIO_PIN_SPEED_FAST;
	GpioLed.PIN_CONFIG.GPIO_Pin_OP_Type = GPIO_OP_TYPE_PP;
	GpioLed.PIN_CONFIG.GPIO_Pin_PuPd_Control = GPIO_PIN_PU;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);
	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NUMBER_13);
		delay();
	}

}
