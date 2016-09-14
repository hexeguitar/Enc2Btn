################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include hardware/subdir.mk
-include encoder/subdir.mk
-include buttonOUT/subdir.mk
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
Enc2Btn.lss \

FLASH_IMAGE += \
Enc2Btn.hex \

EEPROM_IMAGE += \
Enc2Btn.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Enc2Btn.elf secondary-outputs

# Tool invocations
Enc2Btn.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Enc2Btn.map -mmcu=attiny25 -o "Enc2Btn.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Enc2Btn.lss: Enc2Btn.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Enc2Btn.elf  >"Enc2Btn.lss"
	@echo 'Finished building: $@'
	@echo ' '

Enc2Btn.hex: Enc2Btn.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Enc2Btn.elf  "Enc2Btn.hex"
	@echo 'Finished building: $@'
	@echo ' '

Enc2Btn.eep: Enc2Btn.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Enc2Btn.elf  "Enc2Btn.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Enc2Btn.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=attiny25 Enc2Btn.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Enc2Btn.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
