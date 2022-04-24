################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/SSD/subdir.mk
-include HAL/LED/subdir.mk
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
STOPWATCH.lss \

FLASH_IMAGE += \
STOPWATCH.hex \

EEPROM_IMAGE += \
STOPWATCH.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: STOPWATCH.elf secondary-outputs

# Tool invocations
STOPWATCH.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,STOPWATCH.map -mmcu=atmega32 -o "STOPWATCH.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

STOPWATCH.lss: STOPWATCH.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S STOPWATCH.elf  >"STOPWATCH.lss"
	@echo 'Finished building: $@'
	@echo ' '

STOPWATCH.hex: STOPWATCH.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex STOPWATCH.elf  "STOPWATCH.hex"
	@echo 'Finished building: $@'
	@echo ' '

STOPWATCH.eep: STOPWATCH.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex STOPWATCH.elf  "STOPWATCH.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: STOPWATCH.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 STOPWATCH.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) STOPWATCH.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
