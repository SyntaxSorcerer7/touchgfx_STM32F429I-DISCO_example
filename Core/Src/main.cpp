/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "usb_host.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <time.h>
#include "../../TouchGFX/gui/include/gui/info.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

//#define DEMO

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CRC_HandleTypeDef hcrc;

I2C_HandleTypeDef hi2c3;

RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi5;

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_rx;

osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */
osThreadId demoTaskHandle;
osPoolId mpool;
osMessageQId queue;
RTC_TimeTypeDef currentTime;
RTC_DateTypeDef currentDate;
const uint16_t structSize = sizeof(SensorRecord);
uint8_t uartDmaRxBuffer[structSize];
uint8_t buffer[4];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
extern "C" void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_CRC_Init(void);
static void MX_I2C3_Init(void);
void MX_SPI5_Init(void);
static void MX_USART1_UART_Init(void);
extern void GRAPHICS_HW_Init(void);
extern void GRAPHICS_Init(void);
extern void GRAPHICS_MainTask(void);
static void MX_RTC_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */
void DemoDataGeneratorTask(void const * argument);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */
	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_DMA_Init();
	MX_CRC_Init();
	MX_I2C3_Init();
	MX_USART1_UART_Init();
	MX_RTC_Init();
	/* USER CODE BEGIN 2 */

	HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
	HAL_Delay(100);
	HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);

	//without dma
	//__HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
	//HAL_UART_Receive_IT(&huart1, (uint8_t*)buffer, 1);

	//with dma
	HAL_UART_Receive_DMA(&huart1, uartDmaRxBuffer, structSize);

	// GardenData* gardenData = GardenData::getInstace();
//  SensorData s();

	/* USER CODE END 2 */

	/* Initialise the graphical hardware */
	GRAPHICS_HW_Init();

	/* Initialise the graphical stack engine */
	GRAPHICS_Init();

	/* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
	/* USER CODE END RTOS_MUTEX */

	/* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
	/* USER CODE END RTOS_SEMAPHORES */

	/* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
	/* USER CODE END RTOS_TIMERS */

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	osPoolDef(mpool, 15, SensorRecord);
	osMessageQDef(queue, 15, SensorRecord);

	mpool = osPoolCreate(osPool(mpool));                 // create memory pool
	queue = osMessageCreate(osMessageQ(queue), NULL);  // create msg queue
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* definition and creation of defaultTask */
	osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 4096);
	defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

	/* USER CODE BEGIN RTOS_THREADS */
#ifdef DEMO
	osThreadDef(demoTask, DemoDataGeneratorTask, osPriorityNormal, 0, 1024);
	/* Start thread 1 */
	demoTaskHandle = osThreadCreate(osThread(demoTask), NULL);
#endif
	/* USER CODE END RTOS_THREADS */

	/* Start scheduler */
	osKernelStart();

	/* We should never get here as control is now taken by the scheduler */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = { 0 };

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI
			| RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.LSIState = RCC_LSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 4;
	RCC_OscInitStruct.PLL.PLLN = 72;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 3;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
		Error_Handler();
	}
	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC
			| RCC_PERIPHCLK_RTC;
	PeriphClkInitStruct.PLLSAI.PLLSAIN = 60;
	PeriphClkInitStruct.PLLSAI.PLLSAIR = 5;
	PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_4;
	PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief CRC Initialization Function
 * @param None
 * @retval None
 */
static void MX_CRC_Init(void) {

	/* USER CODE BEGIN CRC_Init 0 */

	/* USER CODE END CRC_Init 0 */

	/* USER CODE BEGIN CRC_Init 1 */

	/* USER CODE END CRC_Init 1 */
	hcrc.Instance = CRC;
	if (HAL_CRC_Init(&hcrc) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN CRC_Init 2 */

	/* USER CODE END CRC_Init 2 */

}

/**
 * @brief I2C3 Initialization Function
 * @param None
 * @retval None
 */
static void MX_I2C3_Init(void) {

	/* USER CODE BEGIN I2C3_Init 0 */

	/* USER CODE END I2C3_Init 0 */

	/* USER CODE BEGIN I2C3_Init 1 */

	/* USER CODE END I2C3_Init 1 */
	hi2c3.Instance = I2C3;
	hi2c3.Init.ClockSpeed = 100000;
	hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c3.Init.OwnAddress1 = 0;
	hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c3.Init.OwnAddress2 = 0;
	hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&hi2c3) != HAL_OK) {
		Error_Handler();
	}
	/** Configure Analogue filter
	 */
	if (HAL_I2CEx_ConfigAnalogFilter(&hi2c3, I2C_ANALOGFILTER_ENABLE)
			!= HAL_OK) {
		Error_Handler();
	}
	/** Configure Digital filter
	 */
	if (HAL_I2CEx_ConfigDigitalFilter(&hi2c3, 0) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN I2C3_Init 2 */

	/* USER CODE END I2C3_Init 2 */

}

/**
 * @brief RTC Initialization Function
 * @param None
 * @retval None
 */
static void MX_RTC_Init(void) {

	/* USER CODE BEGIN RTC_Init 0 */

	/* USER CODE END RTC_Init 0 */

	RTC_TimeTypeDef sTime = { 0 };
	RTC_DateTypeDef sDate = { 0 };

	/* USER CODE BEGIN RTC_Init 1 */

	/* USER CODE END RTC_Init 1 */
	/** Initialize RTC Only
	 */
	hrtc.Instance = RTC;
	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
	hrtc.Init.AsynchPrediv = 127;
	hrtc.Init.SynchPrediv = 255;
	hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
	if (HAL_RTC_Init(&hrtc) != HAL_OK) {
		Error_Handler();
	}

	/* USER CODE BEGIN Check_RTC_BKUP */

	/* USER CODE END Check_RTC_BKUP */

	/** Initialize RTC and set the Time and Date
	 */
	sTime.Hours = 0x18;
	sTime.Minutes = 0x0;
	sTime.Seconds = 0x0;
	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK) {
		Error_Handler();
	}
	sDate.WeekDay = RTC_WEEKDAY_TUESDAY;
	sDate.Month = RTC_MONTH_MAY;
	sDate.Date = 0x28;
	sDate.Year = 0x0;

	if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN RTC_Init 2 */

	/* USER CODE END RTC_Init 2 */

}

/**
 * @brief SPI5 Initialization Function
 * @param None
 * @retval None
 */
void MX_SPI5_Init(void) {

	/* USER CODE BEGIN SPI5_Init 0 */

	/* USER CODE END SPI5_Init 0 */

	/* USER CODE BEGIN SPI5_Init 1 */

	/* USER CODE END SPI5_Init 1 */
	/* SPI5 parameter configuration*/
	hspi5.Instance = SPI5;
	hspi5.Init.Mode = SPI_MODE_MASTER;
	hspi5.Init.Direction = SPI_DIRECTION_1LINE;
	hspi5.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi5.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi5.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi5.Init.NSS = SPI_NSS_SOFT;
	hspi5.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
	hspi5.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi5.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi5.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi5.Init.CRCPolynomial = 10;
	if (HAL_SPI_Init(&hspi5) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN SPI5_Init 2 */

	/* USER CODE END SPI5_Init 2 */

}

/**
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART1_UART_Init(void) {

	/* USER CODE BEGIN USART1_Init 0 */

	/* USER CODE END USART1_Init 0 */

	/* USER CODE BEGIN USART1_Init 1 */

	/* USER CODE END USART1_Init 1 */
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN USART1_Init 2 */

	/* USER CODE END USART1_Init 2 */

}

/** 
 * Enable DMA controller clock
 */
static void MX_DMA_Init(void) {
	/* DMA controller clock enable */
	__HAL_RCC_DMA2_CLK_ENABLE()
	;

	/* DMA interrupt init */
	/* DMA2_Stream2_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA2_Stream2_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA2_Stream2_IRQn);

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE()
	;
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	__HAL_RCC_GPIOH_CLK_ENABLE()
	;
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;
	__HAL_RCC_GPIOG_CLK_ENABLE()
	;
	__HAL_RCC_GPIOE_CLK_ENABLE()
	;
	__HAL_RCC_GPIOD_CLK_ENABLE()
	;

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, NCS_MEMS_SPI_Pin | CSX_Pin | OTG_FS_PSO_Pin,
			GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(ACP_RST_GPIO_Port, ACP_RST_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOD, RDX_Pin | WRX_DCX_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOG, LD3_Pin | LD4_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : NCS_MEMS_SPI_Pin CSX_Pin OTG_FS_PSO_Pin */
	GPIO_InitStruct.Pin = NCS_MEMS_SPI_Pin | CSX_Pin | OTG_FS_PSO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pins : B1_Pin MEMS_INT1_Pin MEMS_INT2_Pin TP_INT1_Pin */
	GPIO_InitStruct.Pin = B1_Pin | MEMS_INT1_Pin | MEMS_INT2_Pin | TP_INT1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin : ACP_RST_Pin */
	GPIO_InitStruct.Pin = ACP_RST_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(ACP_RST_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : OTG_FS_OC_Pin */
	GPIO_InitStruct.Pin = OTG_FS_OC_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(OTG_FS_OC_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : BOOT1_Pin */
	GPIO_InitStruct.Pin = BOOT1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(BOOT1_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : TE_Pin */
	GPIO_InitStruct.Pin = TE_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(TE_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : RDX_Pin WRX_DCX_Pin */
	GPIO_InitStruct.Pin = RDX_Pin | WRX_DCX_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	/*Configure GPIO pins : LD3_Pin LD4_Pin */
	GPIO_InitStruct.Pin = LD3_Pin | LD4_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

time_t getTimestamp() {
	struct tm currTime;
	time_t timestamp;
	HAL_RTC_GetTime(&hrtc, &currentTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &currentDate, RTC_FORMAT_BIN);

	currTime.tm_year = currentDate.Year + 100;  // In fact: 2000 + 18 - 1900
	currTime.tm_mday = currentDate.Date;
	currTime.tm_mon = currentDate.Month - 1;

	currTime.tm_hour = currentTime.Hours;
	currTime.tm_min = currentTime.Minutes;
	currTime.tm_sec = currentTime.Seconds;
	timestamp = mktime(&currTime);
	return timestamp;
}

//without dma
/*
 void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
 {
 HAL_GPIO_TogglePin(LD4_GPIO_Port, LD4_Pin);
 } */

//with dma
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	HAL_GPIO_TogglePin(LD4_GPIO_Port, LD4_Pin);
	SensorRecord * rec = reinterpret_cast<SensorRecord*>(uartDmaRxBuffer);
	SensorRecord *message;
	message = (SensorRecord*) osPoolAlloc(mpool);
	message->sensorId = rec->sensorId;
	message->value = rec->value;
	message->timestamp = rec->timestamp;
	osMessagePut(queue, (uint32_t) message, 1);
	HAL_UART_Receive_DMA(&huart1, uartDmaRxBuffer, structSize);
}

void DemoDataGeneratorTask(void const * argument) {
	int i = 0;
	for (;;) {
		i++;
		i = i % 36;
		HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
		SensorRecord *message;
		message = (SensorRecord*) osPoolAlloc(mpool);
		message->sensorId = 0;
		message->value = (float)i;
		message->timestamp = getTimestamp();
		;
		osMessagePut(queue, (uint32_t) message, osWaitForever);
		SensorRecord *message2;
		message2 = (SensorRecord*) osPoolAlloc(mpool);
		message2->sensorId = 1;
		message2->value = (float)i;
		message2->timestamp = getTimestamp();
		;
		osMessagePut(queue, (uint32_t) message2, osWaitForever);
		SensorRecord *message3;
		message3 = (SensorRecord*) osPoolAlloc(mpool);
		message3->sensorId = 2;
		message3->value = (float)i;
		message3->timestamp = getTimestamp();
		;
		osMessagePut(queue, (uint32_t) message3, osWaitForever);
		osDelay(1000);
	}
}

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument) {
	/* init code for USB_HOST */
	MX_USB_HOST_Init();

	/* Graphic application */
	GRAPHICS_MainTask();

	/* USER CODE BEGIN 5 */
	/* Infinite loop */
	for (;;) {
		osDelay(1);
	}
	/* USER CODE END 5 */
}

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM6 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	/* USER CODE BEGIN Callback 0 */

	/* USER CODE END Callback 0 */
	if (htim->Instance == TIM6) {
		HAL_IncTick();
	}
	/* USER CODE BEGIN Callback 1 */

	/* USER CODE END Callback 1 */
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
	 tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
