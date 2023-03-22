################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC_prog.c \
../Src/DIO_prog.c \
../Src/ELC_Heater.c \
../Src/ELC_main.c \
../Src/EXTI_program.c \
../Src/LCD_prg.c \
../Src/NVIC_prog.c \
../Src/PB_prog.c \
../Src/RCC_program.c \
../Src/SSD_prog.c \
../Src/STK_program.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ADC_prog.o \
./Src/DIO_prog.o \
./Src/ELC_Heater.o \
./Src/ELC_main.o \
./Src/EXTI_program.o \
./Src/LCD_prg.o \
./Src/NVIC_prog.o \
./Src/PB_prog.o \
./Src/RCC_program.o \
./Src/SSD_prog.o \
./Src/STK_program.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ADC_prog.d \
./Src/DIO_prog.d \
./Src/ELC_Heater.d \
./Src/ELC_main.d \
./Src/EXTI_program.d \
./Src/LCD_prg.d \
./Src/NVIC_prog.d \
./Src/PB_prog.d \
./Src/RCC_program.d \
./Src/SSD_prog.d \
./Src/STK_program.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ADC_prog.d ./Src/ADC_prog.o ./Src/ADC_prog.su ./Src/DIO_prog.d ./Src/DIO_prog.o ./Src/DIO_prog.su ./Src/ELC_Heater.d ./Src/ELC_Heater.o ./Src/ELC_Heater.su ./Src/ELC_main.d ./Src/ELC_main.o ./Src/ELC_main.su ./Src/EXTI_program.d ./Src/EXTI_program.o ./Src/EXTI_program.su ./Src/LCD_prg.d ./Src/LCD_prg.o ./Src/LCD_prg.su ./Src/NVIC_prog.d ./Src/NVIC_prog.o ./Src/NVIC_prog.su ./Src/PB_prog.d ./Src/PB_prog.o ./Src/PB_prog.su ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/SSD_prog.d ./Src/SSD_prog.o ./Src/SSD_prog.su ./Src/STK_program.d ./Src/STK_program.o ./Src/STK_program.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

