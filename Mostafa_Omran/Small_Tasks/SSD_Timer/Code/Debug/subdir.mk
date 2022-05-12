################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_proram.c \
../GIE_proram.c \
../Main.c \
../SSD_proram.c \
../TIMER_program.c 

OBJS += \
./DIO_proram.o \
./GIE_proram.o \
./Main.o \
./SSD_proram.o \
./TIMER_program.o 

C_DEPS += \
./DIO_proram.d \
./GIE_proram.d \
./Main.d \
./SSD_proram.d \
./TIMER_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


