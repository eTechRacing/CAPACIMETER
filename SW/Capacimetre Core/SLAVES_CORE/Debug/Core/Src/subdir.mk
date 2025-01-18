################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/I2C.c \
../Core/Src/I2C_for_MCP23008.c \
../Core/Src/MCP3302.c \
../Core/Src/analog.c \
../Core/Src/can_comunication_cellmeter.c \
../Core/Src/charge.c \
../Core/Src/discharge.c \
../Core/Src/main.c \
../Core/Src/standby.c \
../Core/Src/state_manager.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/I2C.o \
./Core/Src/I2C_for_MCP23008.o \
./Core/Src/MCP3302.o \
./Core/Src/analog.o \
./Core/Src/can_comunication_cellmeter.o \
./Core/Src/charge.o \
./Core/Src/discharge.o \
./Core/Src/main.o \
./Core/Src/standby.o \
./Core/Src/state_manager.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/I2C.d \
./Core/Src/I2C_for_MCP23008.d \
./Core/Src/MCP3302.d \
./Core/Src/analog.d \
./Core/Src/can_comunication_cellmeter.d \
./Core/Src/charge.d \
./Core/Src/discharge.d \
./Core/Src/main.d \
./Core/Src/standby.d \
./Core/Src/state_manager.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/I2C.cyclo ./Core/Src/I2C.d ./Core/Src/I2C.o ./Core/Src/I2C.su ./Core/Src/I2C_for_MCP23008.cyclo ./Core/Src/I2C_for_MCP23008.d ./Core/Src/I2C_for_MCP23008.o ./Core/Src/I2C_for_MCP23008.su ./Core/Src/MCP3302.cyclo ./Core/Src/MCP3302.d ./Core/Src/MCP3302.o ./Core/Src/MCP3302.su ./Core/Src/analog.cyclo ./Core/Src/analog.d ./Core/Src/analog.o ./Core/Src/analog.su ./Core/Src/can_comunication_cellmeter.cyclo ./Core/Src/can_comunication_cellmeter.d ./Core/Src/can_comunication_cellmeter.o ./Core/Src/can_comunication_cellmeter.su ./Core/Src/charge.cyclo ./Core/Src/charge.d ./Core/Src/charge.o ./Core/Src/charge.su ./Core/Src/discharge.cyclo ./Core/Src/discharge.d ./Core/Src/discharge.o ./Core/Src/discharge.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/standby.cyclo ./Core/Src/standby.d ./Core/Src/standby.o ./Core/Src/standby.su ./Core/Src/state_manager.cyclo ./Core/Src/state_manager.d ./Core/Src/state_manager.o ./Core/Src/state_manager.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

