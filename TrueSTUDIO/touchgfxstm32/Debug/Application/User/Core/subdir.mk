################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/Core/Src/freertos.c \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/Core/Src/stm32f4xx_hal_msp.c \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/Core/Src/stm32f4xx_hal_timebase_tim.c \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/Core/Src/stm32f4xx_it.c 

CPP_SRCS += \
C:/Users/jfrut/development/mic_prog/touchgfxstm32/Core/Src/main.cpp 

OBJS += \
./Application/User/Core/freertos.o \
./Application/User/Core/main.o \
./Application/User/Core/stm32f4xx_hal_msp.o \
./Application/User/Core/stm32f4xx_hal_timebase_tim.o \
./Application/User/Core/stm32f4xx_it.o 

C_DEPS += \
./Application/User/Core/freertos.d \
./Application/User/Core/stm32f4xx_hal_msp.d \
./Application/User/Core/stm32f4xx_hal_timebase_tim.d \
./Application/User/Core/stm32f4xx_it.d 

CPP_DEPS += \
./Application/User/Core/main.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/freertos.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/Core/Src/freertos.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/freertos.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/main.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/Core/Src/main.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_hal_msp.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/Core/Src/stm32f4xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_hal_timebase_tim.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/Core/Src/stm32f4xx_hal_timebase_tim.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/stm32f4xx_hal_timebase_tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_it.o: C:/Users/jfrut/development/mic_prog/touchgfxstm32/Core/Src/stm32f4xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -c -I../../../Drivers/BSP/STM32F429I-Discovery -I../../../Core/Inc -I../../../TouchGFX/target -I../../../USB_HOST/App -I../../../USB_HOST/Target -I../../../TouchGFX/generated/fonts/include -I../../../TouchGFX/generated/texts/include -I../../../TouchGFX/generated/images/include -I../../../TouchGFX/generated/gui_generated/include -I../../../TouchGFX/gui/include -I../../../Middlewares/ST/TouchGFX/touchgfx/framework/include -I../../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../../Drivers/BSP/Components/exc7200 -I../../../Drivers/BSP/Components/stmpe811 -I../../../Drivers/BSP/Components/ts3510 -I../../../Drivers/BSP/Components/ili9341 -I../../../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../../../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../../../Drivers/BSP/Components/ampire480272 -I../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../../Drivers/BSP/Components/Common -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/Core/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
