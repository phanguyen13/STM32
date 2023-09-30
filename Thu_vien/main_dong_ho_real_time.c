/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include <stdbool.h> 
#include <stdio.h>
#include "led7seg.h"
#include "EOS.h"
#include "keypad.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
int x=0;
int hours=0;
int minutes =0;
int seconds=0;
char read_key[3];
int doi_key = 0;
int count;
static int val_key;

bool unit_seconds_adjust;
bool dozen_seconds_adjust;
bool unit_minutes_adjust;
bool dozen_minutes_adjust;
bool unit_hours_adjust;
bool dozen_hours_adjust;

int mode;

int unit_seconds;
int dozen_seconds;
int unit_minutes;
int dozen_minutes;
int unit_hours;
int dozen_hours;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
void print_time(void){
	x++;
	if(x==100){
	seconds++;
	x=0;
	}
	if(seconds==60){
	minutes++;
	seconds=0;
	}
	if(minutes==60){
	hours++;
	minutes=0;
	}
	if(hours==24){
	hours=0;
	minutes=0;
	seconds=0;
	}
	seconds=dozen_seconds+unit_seconds;
	minutes=dozen_minutes+ unit_minutes;
	hours=dozen_hours+unit_hours;
	scanLED_time(1,hours,minutes,seconds);
}

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
	
	
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  //HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  //SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
	EOS_init(10);
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		HAL_PWR_EnterSLEEPMode(
		PWR_MAINREGULATOR_ON,
		PWR_SLEEPENTRY_WFI);

  }
  /* USER CODE END 3 */
}

void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  //HAL_IncTick();

	read_key[count]=Keypad_Scan();
	if(read_key[count]!=0){
		count++;
  }
  if (count == 2)
  {
    if (read_key[0] == read_key[1]){val_key=read_key[1];}
    count = 0;
  }
	if(val_key=='0'){	scanLED_time(1,00,00,00);	hours=0; minutes =0; seconds=0; }


	  if (val_key == '1')
    {
      dozen_hours_adjust = true;
    }
    if (dozen_hours_adjust)
    {
      if (val_key !=0&&val_key!='#')
      {
				minutes = minutes;
				dozen_hours=(val_key-48)*10;
				hours = dozen_hours+unit_hours;
				seconds = seconds;
				print_time();
      }
      if(val_key == '#'){
			dozen_hours_adjust=false;
			}
    }
  if (val_key == '2')
    {
      unit_hours_adjust = true;
    }
    if (unit_hours_adjust)
    {
      if (val_key !=0&&val_key!='#')
      {
				minutes = minutes;
				unit_hours=val_key-48;
				hours = unit_hours + dozen_hours;
				seconds = seconds;
				print_time();
      }
      if(val_key == '#'){
			unit_hours_adjust=false;
			}
    }	
	 
	
	  if (val_key == '3')
    {
      dozen_minutes_adjust = true;
    }
    if (dozen_minutes_adjust)
    {
      if (val_key !=0&&val_key!='#')
      {
				hours = hours;
				dozen_minutes=(val_key-48)*10;
				minutes = dozen_minutes+unit_minutes;
				seconds = seconds;
				print_time();
      }
      if(val_key == '#'){
			dozen_minutes_adjust=false;
			}
    }
  if (val_key == '4')
    {
      unit_minutes_adjust = true;
    }
    if (unit_minutes_adjust)
    {
      if (val_key !=0&&val_key!='#')
      {
				hours = hours;
				unit_minutes=val_key-48;
				minutes = unit_minutes + dozen_minutes;
				seconds = seconds;
				print_time();
      }
      if(val_key == '#'){
			unit_minutes_adjust=false;
			}
    }
		
		 if (val_key == '5')
    {
      dozen_seconds_adjust = true;
    }
    if (dozen_seconds_adjust)
    {
      if (val_key !=0&&val_key!='#')
      {
				hours = hours;
				dozen_seconds=(val_key-48)*10;
				seconds = dozen_seconds+unit_seconds;
				minutes = minutes;
				print_time();
      }
      if(val_key == '#'){
			dozen_seconds_adjust=false;
			}
    }
  if (val_key == '6')
    {
      unit_seconds_adjust = true;
    }
    if (unit_seconds_adjust)
    {
      if (val_key !=0&&val_key!='#')
      {
				hours = hours;
				unit_seconds=val_key-48;
				seconds = unit_seconds + dozen_seconds;
				minutes = minutes;
				print_time();
      }
      if(val_key == '#'){
			unit_seconds_adjust=false;
			}
    }
		
		print_time();
	
	
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB3
                           PB4 PB5 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PA8 PA9 PA10 PA11 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */



/* USER CODE END 4 */

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

