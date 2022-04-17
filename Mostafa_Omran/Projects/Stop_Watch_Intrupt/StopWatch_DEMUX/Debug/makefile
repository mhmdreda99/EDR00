################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
StopWatch_DEMUX.lss \

FLASH_IMAGE += \
StopWatch_DEMUX.hex \

EEPROM_IMAGE += \
StopWatch_DEMUX.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: StopWatch_DEMUX.elf secondary-outputs

# Tool invocations
StopWatch_DEMUX.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,StopWatch_DEMUX.map -mmcu=atmega32 -o "StopWatch_DEMUX.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

StopWatch_DEMUX.lss: StopWatch_DEMUX.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S StopWatch_DEMUX.elf  >"StopWatch_DEMUX.lss"
	@echo 'Finished building: $@'
	@echo ' '

StopWatch_DEMUX.hex: StopWatch_DEMUX.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex StopWatch_DEMUX.elf  "StopWatch_DEMUX.hex"
	@echo 'Finished building: $@'
	@echo ' '

StopWatch_DEMUX.eep: StopWatch_DEMUX.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex StopWatch_DEMUX.elf  "StopWatch_DEMUX.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: StopWatch_DEMUX.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 StopWatch_DEMUX.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) StopWatch_DEMUX.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
