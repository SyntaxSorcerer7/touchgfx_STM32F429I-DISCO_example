################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/BoardConfiguration.cpp \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/GPIO.cpp \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/HW_Init.cpp \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/STM32F4DMA.cpp \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/STM32F4HAL.cpp \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/STM32F4Instrumentation.cpp \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/STM32F4TouchController.cpp 

OBJS += \
./Middlewares/TouchGFX/target/BoardConfiguration.o \
./Middlewares/TouchGFX/target/GPIO.o \
./Middlewares/TouchGFX/target/HW_Init.o \
./Middlewares/TouchGFX/target/STM32F4DMA.o \
./Middlewares/TouchGFX/target/STM32F4HAL.o \
./Middlewares/TouchGFX/target/STM32F4Instrumentation.o \
./Middlewares/TouchGFX/target/STM32F4TouchController.o 

CPP_DEPS += \
./Middlewares/TouchGFX/target/BoardConfiguration.d \
./Middlewares/TouchGFX/target/GPIO.d \
./Middlewares/TouchGFX/target/HW_Init.d \
./Middlewares/TouchGFX/target/STM32F4DMA.d \
./Middlewares/TouchGFX/target/STM32F4HAL.d \
./Middlewares/TouchGFX/target/STM32F4Instrumentation.d \
./Middlewares/TouchGFX/target/STM32F4TouchController.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/TouchGFX/target/BoardConfiguration.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/BoardConfiguration.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Middlewares/TouchGFX/target/BoardConfiguration.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/TouchGFX/target/GPIO.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/GPIO.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Middlewares/TouchGFX/target/GPIO.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/TouchGFX/target/HW_Init.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/HW_Init.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Middlewares/TouchGFX/target/HW_Init.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/TouchGFX/target/STM32F4DMA.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/STM32F4DMA.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Middlewares/TouchGFX/target/STM32F4DMA.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/TouchGFX/target/STM32F4HAL.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/STM32F4HAL.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Middlewares/TouchGFX/target/STM32F4HAL.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/TouchGFX/target/STM32F4Instrumentation.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/STM32F4Instrumentation.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Middlewares/TouchGFX/target/STM32F4Instrumentation.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/TouchGFX/target/STM32F4TouchController.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/TouchGFX/target/STM32F4TouchController.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Middlewares/TouchGFX/target/STM32F4TouchController.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
