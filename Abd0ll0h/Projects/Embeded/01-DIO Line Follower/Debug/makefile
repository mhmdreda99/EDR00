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
DIO_Line_Follower.lss \

FLASH_IMAGE += \
DIO_Line_Follower.hex \

EEPROM_IMAGE += \
DIO_Line_Follower.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: DIO_Line_Follower.elf secondary-outputs

# Tool invocations
DIO_Line_Follower.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DIO_Line_Follower.map -mmcu=atmega16 -o "DIO_Line_Follower.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DIO_Line_Follower.lss: DIO_Line_Follower.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DIO_Line_Follower.elf  >"DIO_Line_Follower.lss"
	@echo 'Finished building: $@'
	@echo ' '

DIO_Line_Follower.hex: DIO_Line_Follower.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DIO_Line_Follower.elf  "DIO_Line_Follower.hex"
	@echo 'Finished building: $@'
	@echo ' '

DIO_Line_Follower.eep: DIO_Line_Follower.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex DIO_Line_Follower.elf  "DIO_Line_Follower.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DIO_Line_Follower.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 DIO_Line_Follower.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DIO_Line_Follower.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
