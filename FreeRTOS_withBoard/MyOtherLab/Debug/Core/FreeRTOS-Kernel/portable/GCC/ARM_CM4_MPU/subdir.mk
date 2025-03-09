################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/mpu_wrappers_v2_asm.c \
../Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/port.c 

OBJS += \
./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/mpu_wrappers_v2_asm.o \
./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/port.o 

C_DEPS += \
./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/mpu_wrappers_v2_asm.d \
./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/port.d 


# Each subdirectory must supply rules for building sources it contributes
Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/%.o Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/%.su Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/%.cyclo: ../Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/%.c Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/darkt/OneDrive - Thompson Rivers University/Documents/New 3020 Material/Labs/MyOtherLab/Core/FreeRTOS-Kernel/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-FreeRTOS-2d-Kernel-2f-portable-2f-GCC-2f-ARM_CM4_MPU

clean-Core-2f-FreeRTOS-2d-Kernel-2f-portable-2f-GCC-2f-ARM_CM4_MPU:
	-$(RM) ./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/mpu_wrappers_v2_asm.cyclo ./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/mpu_wrappers_v2_asm.d ./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/mpu_wrappers_v2_asm.o ./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/mpu_wrappers_v2_asm.su ./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/port.cyclo ./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/port.d ./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/port.o ./Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4_MPU/port.su

.PHONY: clean-Core-2f-FreeRTOS-2d-Kernel-2f-portable-2f-GCC-2f-ARM_CM4_MPU

