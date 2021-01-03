################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/stm32f4xx_GPIO_driver.c 

OBJS += \
./drivers/Src/stm32f4xx_GPIO_driver.o 

C_DEPS += \
./drivers/Src/stm32f4xx_GPIO_driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/stm32f4xx_GPIO_driver.o: ../drivers/Src/stm32f4xx_GPIO_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I"C:/Users/99003172/STM32CubeIDE/workspace_1.5.0/driv_dev/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/stm32f4xx_GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

