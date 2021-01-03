/*
 * stm32f4xx_GPIO_driver.c
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003172
 */
#include "stm32f4XX_GPIO_driver.h"

void GPIO_PeriClockControl(GPIO_Reg_def_t *pGPIOx,uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PE_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PE_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PE_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PE_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PE_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PE_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PE_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PE_CLOCK_ENABLE();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PE_CLOCK_ENABLE();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PE_CLOCK_RESET();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PE_CLOCK_RESET();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PE_CLOCK_RESET();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PE_CLOCK_RESET();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PE_CLOCK_RESET();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PE_CLOCK_RESET();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PE_CLOCK_RESET();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PE_CLOCK_RESET();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PE_CLOCK_RESET();
		}
	}
}

void GPIO_Init(GPIO_HANDLE_T *pGPIOHandle)
{
	//1. configuring the mode
	uint32_t temp=0;
		if(pGPIOHandle->PIN_CONFIG.GPIO_PinMode <= GPIO_PIN_MODE_ANALOG )//non interrupt modes
		{
			temp = pGPIOHandle->PIN_CONFIG.GPIO_PinMode<<(2*pGPIOHandle->PIN_CONFIG.GPIO_Pin_Number);
			pGPIOHandle->pGPIOx->MODER |= temp;
		}
		else
		{
				 //interrupt mode FT, RT ,FTRT
		}
	//2. configuring the speed
	uint32_t temp1=0;
	temp1 = pGPIOHandle->PIN_CONFIG.GPIO_Pin_Speed<<(2*pGPIOHandle->PIN_CONFIG.GPIO_Pin_Number);
	pGPIOHandle->pGPIOx->OSPEEDR |= temp1;

	//3. configuring the pu pd control
	uint32_t temp2=0;
	temp2 = pGPIOHandle->PIN_CONFIG.GPIO_Pin_PuPd_Control<<(2*pGPIOHandle->PIN_CONFIG.GPIO_Pin_Number);
	pGPIOHandle->pGPIOx->PUPDR |= temp2;

	//4. configuring the output type
	uint32_t temp3=0;
	temp3 = pGPIOHandle->PIN_CONFIG.GPIO_Pin_OP_Type<<(pGPIOHandle->PIN_CONFIG.GPIO_Pin_Number);
	pGPIOHandle->pGPIOx->OTYPER |= temp3;

	uint32_t tempA = pGPIOHandle->PIN_CONFIG.GPIO_Pin_Number /8;
	uint32_t tempB = pGPIOHandle->PIN_CONFIG.GPIO_Pin_Number %8;
	pGPIOHandle->pGPIOx->AFR[tempA] |= pGPIOHandle->PIN_CONFIG.GPIO_Pin_Alt_Fun_Mode << (4*tempB);
	if(tempA == 0)
	{
		if(tempB == 0);
	}
}

void GPIO_DeInit(GPIO_Reg_def_t *pGIOx)
{
	/*
	if(EnorDi == ENABLE)
		{
			if(pGPIOx == GPIOA)
			{
				GPIOA_PE_CLOCK_ENABLE();
			}
			else if(pGPIOx == GPIOB)
			{
				GPIOB_PE_CLOCK_ENABLE();
			}
			else if(pGPIOx == GPIOC)
			{
				GPIOC_PE_CLOCK_ENABLE();
			}
			else if(pGPIOx == GPIOD)
			{
				GPIOD_PE_CLOCK_ENABLE();
			}
			else if(pGPIOx == GPIOE)
			{
				GPIOE_PE_CLOCK_ENABLE();
			}
			else if(pGPIOx == GPIOF)
			{
				GPIOF_PE_CLOCK_ENABLE();
			}
			else if(pGPIOx == GPIOG)
			{
				GPIOG_PE_CLOCK_ENABLE();
			}
			else if(pGPIOx == GPIOH)
			{
				GPIOH_PE_CLOCK_ENABLE();
			}
			else if(pGPIOx == GPIOI)
			{
				GPIOI_PE_CLOCK_ENABLE();
			}
		}
		else
		{
			if(pGPIOx == GPIOA)
					{
						GPIOA_PE_CLOCK_ENABLE();
					}
					else if(pGPIOx == GPIOB)
					{
						GPIOB_PE_CLOCK_ENABLE();
					}
					else if(pGPIOx == GPIOC)
					{
						GPIOC_PE_CLOCK_ENABLE();
					}
					else if(pGPIOx == GPIOD)
					{
						GPIOD_PE_CLOCK_ENABLE();
					}
					else if(pGPIOx == GPIOE)
					{
						GPIOE_PE_CLOCK_ENABLE();
					}
					else if(pGPIOx == GPIOF)
					{
						GPIOF_PE_CLOCK_ENABLE();
					}
					else if(pGPIOx == GPIOG)
					{
						GPIOG_PE_CLOCK_ENABLE();
					}
					else if(pGPIOx == GPIOH)
					{
						GPIOH_PE_CLOCK_ENABLE();
					}
					else if(pGPIOx == GPIOI)
					{
						GPIOI_PE_CLOCK_ENABLE();
					}// To be done
		}
		*/
}

uint8_t GPIO_ReadFromInputPin(GPIO_Reg_def_t *pGPIOx,uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) * (0x00000001));
	return value;
}

uint16_t GPIO_ReadFromInputPort(GPIO_Reg_def_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}

void GPIO_WriteToOutputPin(GPIO_Reg_def_t *pGPIOx,uint8_t PinNumber,uint8_t value)
{
	if(value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

void GPIO_WriteToOutputPort(GPIO_Reg_def_t *pGPIOx,uint8_t value)
{
	pGPIOx->ODR = value;
}

void GPIO_ToggleOutputPin(GPIO_Reg_def_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1<<PinNumber);
}
