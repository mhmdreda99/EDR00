################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/EXTINT/subdir.mk
-include MCAL/DIO/subdir.mk
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
E02_EXTINT_TOGGLE_LED.lss \

FLASH_IMAGE += \
E02_EXTINT_TOGGLE_LED.hex \

EEPROM_IMAGE += \
E02_EXTINT_TOGGLE_LED.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: E02_EXTINT_TOGGLE_LED.elf secondary-outputs

# Tool invocations
E02_EXTINT_TOGGLE_LED.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,E02_EXTINT_TOGGLE_LED.map -mmcu=atmega32 -o "E02_EXTINT_TOGGLE_LED.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

E02_EXTINT_TOGGLE_LED.lss: E02_EXTINT_TOGGLE_LED.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S E02_EXTINT_TOGGLE_LED.elf  >"E02_EXTINT_TOGGLE_LED.lss"
	@echo 'Finished building: $@'
	@echo ' '

E02_EXTINT_TOGGLE_LED.hex: E02_EXTINT_TOGGLE_LED.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex E02_EXTINT_TOGGLE_LED.elf  "E02_EXTINT_TOGGLE_LED.hex"
	@echo 'Finished building: $@'
	@echo ' '

E02_EXTINT_TOGGLE_LED.eep: E02_EXTINT_TOGGLE_LED.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex E02_EXTINT_TOGGLE_LED.elf  "E02_EXTINT_TOGGLE_LED.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: E02_EXTINT_TOGGLE_LED.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 E02_EXTINT_TOGGLE_LED.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) E02_EXTINT_TOGGLE_LED.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
