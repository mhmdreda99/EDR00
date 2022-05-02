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
-include APP/StopWatch/subdir.mk
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
StopWatchINT.lss \

FLASH_IMAGE += \
StopWatchINT.hex \

EEPROM_IMAGE += \
StopWatchINT.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: StopWatchINT.elf secondary-outputs

# Tool invocations
StopWatchINT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,StopWatchINT.map -mmcu=atmega32 -o "StopWatchINT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

StopWatchINT.lss: StopWatchINT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S StopWatchINT.elf  >"StopWatchINT.lss"
	@echo 'Finished building: $@'
	@echo ' '

StopWatchINT.hex: StopWatchINT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex StopWatchINT.elf  "StopWatchINT.hex"
	@echo 'Finished building: $@'
	@echo ' '

StopWatchINT.eep: StopWatchINT.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex StopWatchINT.elf  "StopWatchINT.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: StopWatchINT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 StopWatchINT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) StopWatchINT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
