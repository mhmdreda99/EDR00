################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../CLCD_proram.c \
../DIO_proram.c \
../GIE_proram.c \
../Main.c 

OBJS += \
./ADC_program.o \
./CLCD_proram.o \
./DIO_proram.o \
./GIE_proram.o \
./Main.o 

C_DEPS += \
./ADC_program.d \
./CLCD_proram.d \
./DIO_proram.d \
./GIE_proram.d \
./Main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


