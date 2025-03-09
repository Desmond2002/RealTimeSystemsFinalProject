/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "queue.h"
#include <stdlib.h> /*allows for random*/
/* USER CODE END Includes */

static TaskHandle_t xTaskHandle1 = NULL; // Handle for prvStartDefaultTask
static TaskHandle_t xTaskHandle2 = NULL; // Handle for prvStartTask02
static int buttonPressCount = 0;


/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* Priorities at which the tasks are created. */
#define mainONE_LEDTASK_PRIORITY		( tskIDLE_PRIORITY + 1 )
#define	mainOTHER_LED_TASK_PRIORITY		( tskIDLE_PRIORITY + 2 )

/* The rate at which data is sent to the queue.  The times are converted from
milliseconds to ticks using the pdMS_TO_TICKS() macro. */
#define mainTASK_SEND_FREQUENCY_MS			pdMS_TO_TICKS( 200UL )
#define mainTIMER_SEND_FREQUENCY_MS			pdMS_TO_TICKS( 2000UL )

/* The number of items the queue can hold at once. */
#define mainQUEUE_LENGTH					( 2 )

/* The values sent to the queue receive task from the queue send task and the
queue send software timer respectively. */
#define mainVALUE_SENT_FROM_TASK			( 100UL )
#define mainVALUE_SENT_FROM_TIMER			( 200UL )
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
static void prvStartDefaultTask(void  * argument);
static void prvStartTask02(void  * argument);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* The queue used by both tasks. */
static QueueHandle_t xQueue = NULL;
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */


/* A software timer that is started from the tick hook. */
//static TimerHandle_t xTimer = NULL;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
//	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
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
  /* USER CODE BEGIN 2 */
  const TickType_t xTimerPeriod = mainTIMER_SEND_FREQUENCY_MS;

    	/* Create the queue. */
    	xQueue = xQueueCreate( mainQUEUE_LENGTH, sizeof( uint32_t ) );
      /* USER CODE BEGIN 1 */
    	if( xQueue != NULL )
    	{
    		xTaskCreate( prvStartDefaultTask, "One LED", configMINIMAL_STACK_SIZE, NULL, mainONE_LEDTASK_PRIORITY, &xTaskHandle1 );
    		xTaskCreate( prvStartTask02, "Other LED", configMINIMAL_STACK_SIZE, NULL, mainOTHER_LED_TASK_PRIORITY, &xTaskHandle2 );

    	    vTaskStartScheduler();
    	}


  	else
  	{
  		//throw led if queue can't be created.. debug led
  		HAL_GPIO_TogglePin( GPIOD, GPIO_PIN_12 );

  	}
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|orange_led_Pin|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PD12 orange_led_Pin PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|orange_led_Pin|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}
/* USER CODE END 4 */
/* USER CODE BEGIN 4 */
/* USER CODE BEGIN 4 */
/* USER CODE END 4 */
/* USER CODE END 4 */
/* USER CODE END 4 */
/* USER CODE END 4 */


/* USER CODE BEGIN 4 */
static void prvStartDefaultTask(void *argument);
static void prvStartTask02(void *argument);
static uint8_t AreAllLEDsOn(void);
static void WinEffect(void);

// Global Task Handles

/* Task 1: Handles Normal Blinking */
static void prvStartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  for (;;)
  {
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
    vTaskDelay(pdMS_TO_TICKS(100)); // Normal blink rate
  }
  /* USER CODE END 5 */
  vTaskDelete(NULL);
}

/* Task 2: Handles LED Sequence When Button is Pressed */

static void prvStartTask02(void *argument)
{
  for (;;)
  {
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)) // Button Pressed
    {
        vTaskSuspend(xTaskHandle1); // Suspend Task 1 (Normal Blinking)

        buttonPressCount++; // Increment button press count

        // Step 1: Turn all LEDs OFF
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);

        // Step 2: Set Each LED Based on Random OR Force ON if 3rd Press
        GPIO_PinState ledState;

        if (buttonPressCount == 3) // Force all LEDs ON on 3rd button press
        {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
            vTaskDelay(pdMS_TO_TICKS(500));
        }
        else
        {
        	for (int i = 0; i < 5; i++) // Loop 5 times
        	        {
        	            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12); // Toggle LED (ON if OFF, OFF if ON)
        	            vTaskDelay(pdMS_TO_TICKS(10)); // Wait 500ms
        	        }
        	        ledState = (rand() % 2) ? GPIO_PIN_SET : GPIO_PIN_RESET;
        	        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, ledState);
        	        vTaskDelay(pdMS_TO_TICKS(50));

        	        // Orange LED (GPIO_PIN_13)
        	        for (int i = 0; i < 5; i++) // Loop 5 times
        	                {
        	                    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13); // Toggle LED (ON if OFF, OFF if ON)
        	                    vTaskDelay(pdMS_TO_TICKS(10)); // Wait 10ms
        	                }
        	        ledState = (rand() % 2) ? GPIO_PIN_SET : GPIO_PIN_RESET;
        	        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, ledState);
        	        vTaskDelay(pdMS_TO_TICKS(50));

        	        // Red LED (GPIO_PIN_14)
        	        for (int i = 0; i < 5; i++) // Loop 5 times
        	                {
        	                    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14); // Toggle LED (ON if OFF, OFF if ON)
        	                    vTaskDelay(pdMS_TO_TICKS(10)); // Wait 10ms
        	                }
        	        ledState = (rand() % 2) ? GPIO_PIN_SET : GPIO_PIN_RESET;
        	        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, ledState);
        	        vTaskDelay(pdMS_TO_TICKS(50));

        	        // Blue LED (GPIO_PIN_15)
        	        for (int i = 0; i < 5; i++) // Loop 5 times
        	                {
        	                    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15); // Toggle LED (ON if OFF, OFF if ON)
        	                    vTaskDelay(pdMS_TO_TICKS(10)); // Wait 10ms
        	                }
        	        ledState = (rand() % 2) ? GPIO_PIN_SET : GPIO_PIN_RESET;
        	        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, ledState);
        	        vTaskDelay(pdMS_TO_TICKS(50));
        }

        // Step 3: Check if all LEDs are ON (Trigger Win Effect)
        if (AreAllLEDsOn())
        {
            WinEffect(); // Trigger Win Effect if all LEDs are ON
            buttonPressCount = 0; // Reset count after win condition
        }

        // Step 4: Display outcome for 5 seconds
        vTaskDelay(pdMS_TO_TICKS(500));
        //resets lights to off so that all lights are in the same state before switching states
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
        vTaskResume(xTaskHandle1); // Resume Task 1 (Normal Blinking)
    }
    vTaskDelay(pdMS_TO_TICKS(5)); // Small delay to prevent CPU overload
  }
}



static uint8_t AreAllLEDsOn(void)
{
    return (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_12) == GPIO_PIN_SET &&
            HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13) == GPIO_PIN_SET &&
            HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_14) == GPIO_PIN_SET &&
            HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_15) == GPIO_PIN_SET);
}

static void WinEffect(void)
{
    for (int i = 0; i < 80; i++) // Flash LEDs 10 times
    {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
        vTaskDelay(pdMS_TO_TICKS(10)); // Fast flashing
    }
}




/* USER CODE END 4 */
/* USER CODE END 4 */
/* USER CODE END 4 */
/* USER CODE END 4 */
/* USER CODE END 4 */
/* USER CODE END 4 */
/* USER CODE END 4 */
/* USER CODE END 4 */
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
