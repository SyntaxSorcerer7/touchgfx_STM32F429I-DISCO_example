################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/USB_Host_Library/subdir.mk
-include Middlewares/TouchGFX/target/subdir.mk
-include Middlewares/TouchGFX/subdir.mk
-include Middlewares/FreeRTOS/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/Components/subdir.mk
-include Application/User/USB_HOST/Target/subdir.mk
-include Application/User/USB_HOST/App/subdir.mk
-include Application/User/TouchGFX/gui/screen1_screen/subdir.mk
-include Application/User/TouchGFX/gui/model/subdir.mk
-include Application/User/TouchGFX/gui/common/subdir.mk
-include Application/User/TouchGFX/generated/texts/subdir.mk
-include Application/User/TouchGFX/generated/images/__designer/subdir.mk
-include Application/User/TouchGFX/generated/images/subdir.mk
-include Application/User/TouchGFX/generated/gui_generated/screen1_screen/subdir.mk
-include Application/User/TouchGFX/generated/gui_generated/common/subdir.mk
-include Application/User/TouchGFX/generated/fonts/subdir.mk
-include Application/User/Core/subdir.mk
-include Application/TrueSTUDIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
touchgfxstm32.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
touchgfxstm32.list \


# All Target
all: touchgfxstm32.elf secondary-outputs

# Tool invocations
touchgfxstm32.elf: $(OBJS) $(USER_OBJS) ../STM32F429ZI_FLASH.ld
	arm-none-eabi-g++ -o "touchgfxstm32.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"../STM32F429ZI_FLASH.ld" --specs=nosys.specs -Wl,-Map="touchgfxstm32.map" -Wl,--gc-sections -static -L../../../Middlewares/ST/TouchGFX/touchgfx/lib/core/cortex_m4f/gcc --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

touchgfxstm32.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "touchgfxstm32.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	arm-none-eabi-objcopy.exe -O ihex "touchgfxstm32.elf" "touchgfxstm32.hex"
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
