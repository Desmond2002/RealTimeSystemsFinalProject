################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/FreeRTOS-Kernel/croutine.c \
../Core/FreeRTOS-Kernel/event_groups.c \
../Core/FreeRTOS-Kernel/list.c \
../Core/FreeRTOS-Kernel/queue.c \
../Core/FreeRTOS-Kernel/stream_buffer.c \
../Core/FreeRTOS-Kernel/tasks.c \
../Core/FreeRTOS-Kernel/timers.c 

OBJS += \
./Core/FreeRTOS-Kernel/croutine.o \
./Core/FreeRTOS-Kernel/event_groups.o \
./Core/FreeRTOS-Kernel/list.o \
./Core/FreeRTOS-Kernel/queue.o \
./Core/FreeRTOS-Kernel/stream_buffer.o \
./Core/FreeRTOS-Kernel/tasks.o \
./Core/FreeRTOS-Kernel/timers.o 

C_DEPS += \
./Core/FreeRTOS-Kernel/croutine.d \
./Core/FreeRTOS-Kernel/event_groups.d \
./Core/FreeRTOS-Kernel/list.d \
./Core/FreeRTOS-Kernel/queue.d \
./Core/FreeRTOS-Kernel/stream_buffer.d \
./Core/FreeRTOS-Kernel/tasks.d \
./Core/FreeRTOS-Kernel/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Core/FreeRTOS-Kernel/%.o Core/FreeRTOS-Kernel/%.su Core/FreeRTOS-Kernel/%.cyclo: ../Core/FreeRTOS-Kernel/%.c Core/FreeRTOS-Kernel/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/T00672738.MYTRU.001/Downloads/FreeRTOS_withBoard_v2/FreeRTOS_withBoard/MyOtherLab/Core/FreeRTOS-Kernel/include" -I"C:/Users/T00672738.MYTRU.001/Downloads/FreeRTOS_withBoard_v2/FreeRTOS_withBoard/MyOtherLab/Core/FreeRTOS-Kernel/portable/GCC/ARM_CM4F" -I"C:/Users/T00672738.MYTRU.001/Downloads/FreeRTOS_withBoard_v2/FreeRTOS_withBoard/MyOtherLab/Core/FreeRTOS-Kernel/portable/MemMang" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-FreeRTOS-2d-Kernel

clean-Core-2f-FreeRTOS-2d-Kernel:
	-$(RM) ./Core/FreeRTOS-Kernel/croutine.cyclo ./Core/FreeRTOS-Kernel/croutine.d ./Core/FreeRTOS-Kernel/croutine.o ./Core/FreeRTOS-Kernel/croutine.su ./Core/FreeRTOS-Kernel/event_groups.cyclo ./Core/FreeRTOS-Kernel/event_groups.d ./Core/FreeRTOS-Kernel/event_groups.o ./Core/FreeRTOS-Kernel/event_groups.su ./Core/FreeRTOS-Kernel/list.cyclo ./Core/FreeRTOS-Kernel/list.d ./Core/FreeRTOS-Kernel/list.o ./Core/FreeRTOS-Kernel/list.su ./Core/FreeRTOS-Kernel/queue.cyclo ./Core/FreeRTOS-Kernel/queue.d ./Core/FreeRTOS-Kernel/queue.o ./Core/FreeRTOS-Kernel/queue.su ./Core/FreeRTOS-Kernel/stream_buffer.cyclo ./Core/FreeRTOS-Kernel/stream_buffer.d ./Core/FreeRTOS-Kernel/stream_buffer.o ./Core/FreeRTOS-Kernel/stream_buffer.su ./Core/FreeRTOS-Kernel/tasks.cyclo ./Core/FreeRTOS-Kernel/tasks.d ./Core/FreeRTOS-Kernel/tasks.o ./Core/FreeRTOS-Kernel/tasks.su ./Core/FreeRTOS-Kernel/timers.cyclo ./Core/FreeRTOS-Kernel/timers.d ./Core/FreeRTOS-Kernel/timers.o ./Core/FreeRTOS-Kernel/timers.su

.PHONY: clean-Core-2f-FreeRTOS-2d-Kernel

