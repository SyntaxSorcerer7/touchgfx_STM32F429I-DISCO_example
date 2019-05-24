################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/USB_HOST/Target/usbh_conf.c \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/USB_HOST/Target/usbh_platform.c 

OBJS += \
./Application/User/USB_HOST/Target/usbh_conf.o \
./Application/User/USB_HOST/Target/usbh_platform.o 

C_DEPS += \
./Application/User/USB_HOST/Target/usbh_conf.d \
./Application/User/USB_HOST/Target/usbh_platform.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/USB_HOST/Target/usbh_conf.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/USB_HOST/Target/usbh_conf.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/USB_HOST/Target/usbh_conf.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/USB_HOST/Target/usbh_platform.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/USB_HOST/Target/usbh_platform.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/USB_HOST/Target/usbh_platform.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

