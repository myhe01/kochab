################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/image_data/4.37/image_437_480x176_BW.c \
../Core/Src/image_data/4.37/image_437_480x176_BWR.c 

C_DEPS += \
./Core/Src/image_data/4.37/image_437_480x176_BW.d \
./Core/Src/image_data/4.37/image_437_480x176_BWR.d 

OBJS += \
./Core/Src/image_data/4.37/image_437_480x176_BW.o \
./Core/Src/image_data/4.37/image_437_480x176_BWR.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/image_data/4.37/%.o Core/Src/image_data/4.37/%.su Core/Src/image_data/4.37/%.cyclo: ../Core/Src/image_data/4.37/%.c Core/Src/image_data/4.37/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L010xB -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-image_data-2f-4-2e-37

clean-Core-2f-Src-2f-image_data-2f-4-2e-37:
	-$(RM) ./Core/Src/image_data/4.37/image_437_480x176_BW.cyclo ./Core/Src/image_data/4.37/image_437_480x176_BW.d ./Core/Src/image_data/4.37/image_437_480x176_BW.o ./Core/Src/image_data/4.37/image_437_480x176_BW.su ./Core/Src/image_data/4.37/image_437_480x176_BWR.cyclo ./Core/Src/image_data/4.37/image_437_480x176_BWR.d ./Core/Src/image_data/4.37/image_437_480x176_BWR.o ./Core/Src/image_data/4.37/image_437_480x176_BWR.su

.PHONY: clean-Core-2f-Src-2f-image_data-2f-4-2e-37

