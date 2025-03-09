################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/FreeRTOS-Kernel/portable/MemMang/heap_1.c 

OBJS += \
./Core/FreeRTOS-Kernel/portable/MemMang/heap_1.o 

C_DEPS += \
./Core/FreeRTOS-Kernel/portable/MemMang/heap_1.d 


# Each subdirectory must supply rules for building sources it contributes
Core/FreeRTOS-Kernel/portable/MemMang/%.o Core/FreeRTOS-Kernel/portable/MemMang/%.su Core/FreeRTOS-Kernel/portable/MemMang/%.cyclo: ../Core/FreeRTOS-Kernel/portable/MemMang/%.c Core/FreeRTOS-Kernel/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/T00672738.MYTRU.001/Downloads/FreeRTOS_withBoard_v2/FreeRTOS_withBoard/MyOtherLab/Core/FreeRTOS-Kernel/include" -I"C:/Users/T00672738.MYTRU.001/Downloads/FreeRTOS_withBoard_v2/FreeRTOS_withBoard/MyOtherLab/Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4F" -I"C:/Users/T00672738.MYTRU.001/Downloads/FreeRTOS_withBoard_v2/FreeRTOS_withBoard/MyOtherLab/Core/FreeRTOS-Kernel/portable/MemMang" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-FreeRTOS-2d-Kernel-2f-portable-2f-MemMang

clean-Core-2f-FreeRTOS-2d-Kernel-2f-portable-2f-MemMang:
	-$(RM) ./Core/FreeRTOS-Kernel/portable/MemMang/heap_1.cyclo ./Core/FreeRTOS-Kernel/portable/MemMang/heap_1.d ./Core/FreeRTOS-Kernel/portable/MemMang/heap_1.o ./Core/FreeRTOS-Kernel/portable/MemMang/heap_1.su

.PHONY: clean-Core-2f-FreeRTOS-2d-Kernel-2f-portable-2f-MemMang

