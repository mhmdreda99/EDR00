################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/External_Interrupt/Debug/subdir.mk
-include MCAL/External_Interrupt/subdir.mk
-include MCAL/DIO/Debug/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include MCAL/.metadata/.plugins/org.eclipse.cdt.managedbuilder.core/subdir.mk
-include MCAL/.metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include MCAL/.metadata/.metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include HAL/StopWatch/subdir.mk
-include HAL/SevenSegment_Driver/.metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include HAL/SevenSegment_Driver/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Keypad/subdir.mk
-include HAL/.metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
LED_Toggle.lss \

FLASH_IMAGE += \
LED_Toggle.hex \

EEPROM_IMAGE += \
LED_Toggle.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: LED_Toggle.elf secondary-outputs

# Tool invocations
LED_Toggle.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LED_Toggle.map -mmcu=atmega32 -o "LED_Toggle.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LED_Toggle.lss: LED_Toggle.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LED_Toggle.elf  >"LED_Toggle.lss"
	@echo 'Finished building: $@'
	@echo ' '

LED_Toggle.hex: LED_Toggle.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LED_Toggle.elf  "LED_Toggle.hex"
	@echo 'Finished building: $@'
	@echo ' '

LED_Toggle.eep: LED_Toggle.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LED_Toggle.elf  "LED_Toggle.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LED_Toggle.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LED_Toggle.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LED_Toggle.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
