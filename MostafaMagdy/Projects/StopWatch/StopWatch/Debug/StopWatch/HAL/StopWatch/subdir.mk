################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../StopWatch/HAL/StopWatch/StopWatch.c 

OBJS += \
./StopWatch/HAL/StopWatch/StopWatch.o 

C_DEPS += \
./StopWatch/HAL/StopWatch/StopWatch.d 


# Each subdirectory must supply rules for building sources it contributes
StopWatch/HAL/StopWatch/%.o: ../StopWatch/HAL/StopWatch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


