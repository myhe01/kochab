################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BW.c \
../Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BWR.c 

C_DEPS += \
./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BW.d \
./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BWR.d 

OBJS += \
./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BW.o \
./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BWR.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/globalupdate_src/image_data/4.20/%.o Core/Src/globalupdate_src/image_data/4.20/%.su Core/Src/globalupdate_src/image_data/4.20/%.cyclo: ../Core/Src/globalupdate_src/image_data/4.20/%.c Core/Src/globalupdate_src/image_data/4.20/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L010xB -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-globalupdate_src-2f-image_data-2f-4-2e-20

clean-Core-2f-Src-2f-globalupdate_src-2f-image_data-2f-4-2e-20:
	-$(RM) ./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BW.cyclo ./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BW.d ./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BW.o ./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BW.su ./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BWR.cyclo ./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BWR.d ./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BWR.o ./Core/Src/globalupdate_src/image_data/4.20/image_420_400x300_BWR.su

.PHONY: clean-Core-2f-Src-2f-globalupdate_src-2f-image_data-2f-4-2e-20

