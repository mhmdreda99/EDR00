################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_proram.c \
../DIO_proram.c \
../EXTI_proram.c \
../GIE_proram.c \
../KPD_program.c \
../Main.c \
../TIMER_program.c 

OBJS += \
./CLCD_proram.o \
./DIO_proram.o \
./EXTI_proram.o \
./GIE_proram.o \
./KPD_program.o \
./Main.o \
./TIMER_program.o 

C_DEPS += \
./CLCD_proram.d \
./DIO_proram.d \
./EXTI_proram.d \
./GIE_proram.d \
./KPD_program.d \
./Main.d \
./TIMER_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


