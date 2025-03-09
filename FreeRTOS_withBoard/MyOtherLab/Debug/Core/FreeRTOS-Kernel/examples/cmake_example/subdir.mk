################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/FreeRTOS-Kernel/examples/cmake_example/main.c 

OBJS += \
./Core/FreeRTOS-Kernel/examples/cmake_example/main.o 

C_DEPS += \
./Core/FreeRTOS-Kernel/examples/cmake_example/main.d 


# Each subdirectory must supply rules for building sources it contributes
Core/FreeRTOS-Kernel/examples/cmake_example/%.o Core/FreeRTOS-Kernel/examples/cmake_example/%.su Core/FreeRTOS-Kernel/examples/cmake_example/%.cyclo: ../Core/FreeRTOS-Kernel/examples/cmake_example/%.c Core/FreeRTOS-Kernel/examples/cmake_example/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/darkt/OneDrive - Thompson Rivers University/Documents/New 3020 Material/Labs/MyOtherLab/Core/FreeRTOS-Kernel/include" -I"C:/Users/darkt/OneDrive - Thompson Rivers University/Documents/New 3020 Material/Labs/MyOtherLab/Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4F" -I"C:/Users/darkt/OneDrive - Thompson Rivers University/Documents/New 3020 Material/Labs/MyOtherLab/Core/FreeRTOS-Kernel/portable/MemMang" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-FreeRTOS-2d-Kernel-2f-examples-2f-cmake_example

clean-Core-2f-FreeRTOS-2d-Kernel-2f-examples-2f-cmake_example:
	-$(RM) ./Core/FreeRTOS-Kernel/examples/cmake_example/main.cyclo ./Core/FreeRTOS-Kernel/examples/cmake_example/main.d ./Core/FreeRTOS-Kernel/examples/cmake_example/main.o ./Core/FreeRTOS-Kernel/examples/cmake_example/main.su

.PHONY: clean-Core-2f-FreeRTOS-2d-Kernel-2f-examples-2f-cmake_example

