/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "bgfx.h"
#include "image.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE {
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}

// 0x00, soft-reset, temperature, active temp, PSR0, PSR1
const uint8_t  REGISTER_DATA[] = {0x00, 0x0e, 0x19, 0x02, 0x0f, 0x89};
const uint32_t IMAGE_DATA_SIZE = (uint32_t) 300 * (uint32_t) (400 / 8);
const uint16_t SCREEN_DIAGONAL = 417;
const uint16_t REFRESH_TIME = 19;


/* Start
 * 1. Get temp from temp sensor
 * 2. Power on Tcon (COG)
 * 3. Input temp to COG
 * 4. Send image data to COG
 * 5. Send the power settings of DC/DC and turn on DC/DC
 * 6. Make sure BUSY = high
 * 7. Send update command to COG
 * 8. Wait until BUSY = high
 * 9. Turn off DC/DC
 * End
 *
 * Max SPI clock speed is 10 MHz
 *
 * COG Power On
 * Start
 * 1. Turn on VCC
 * 2. Delay 5ms
 * 3. Reset = 1
 * 4. Delay 5ms
 * 5. Reset = 0
 * 6. Delay 10ms
 * 7. Reset = 1
 * 8. Delay 5ms
 * 9. Soft reset (SPI 0x00, 0x0E)
 * 10.Delay 5ms
 * End
 *
 * COG Initial
 * Start
 * 1. Input temperature (SPI 0xE5, 0x19)
 * 2. Active temperature (SPI 0xE0, 0x02)
 * 3. Panel settings (SPI 0x00, 0x0F 0x89)
 * End
 *
 * COG Update
 * Start
 * 1. Make sure BUSY = high
 * 2. Power on command (SPI 0x04) * 2 no data
 * 3. Wait until BUSY = high
 * 4. Display refresh (SPI 0x12) * 2 no data
 * 5. Wait until BUSY = high
 * End
 * SPI(0x04) and SPI(0x12) both do not need data. Just the index.
 *
 * COG Turn off DC/DC
 * Start
 * 1. Turn off DC/DC (SPI 0x02) no data
 * 2. Wait until BUSY = high
 * 3. Set RESET to floating
 * 4. Clear CS, SDIN/MISO, SCLK (set low)
 * 5. Cut off VCC to COG
 * 6. Set BUSY to output, set low (reconfig as output and set low)
 * 7. Delay 150 ms
 * 8. Set RESET to output low
 * End
 *
 * Global Update
 * Start
 * 1. DC low
 * 2. CS low
 * 3. Send first frame address (0x10)
 * 4. CS high
 * 5. DC high
 * 6. CS low
 * 7. Send first byte
 * 8. CS high
 * 9. CS low
 * 10.Send second byte
 * 11.CS high
 * ...
 * 12.CS low
 * 13.Send last byte
 * 14.CS high
 * 15.Repeat 1-14 with second frame (address 0x13, all bytes 0x00 for 15000 bytes)
 * End
 *
 */

/**
 * Steps:
 * A) Power on COG driver
 * B) Set env temp and PSR
 * C) Send image to EPD
 * D) Send update command
 */

/**
 * Steps:
 * A) Power on COG driver
 * B) Set env temp and PSR
 * C) Send image to EPD
 * D) Send update command
 *
 * Official steps:
 * Start
 * 1. Get temp from temp sensor
 * 2. Power on Tcon (COG)
 * 3. Input temp to COG
 * 4. Send image data to COG
 * 5. Send the power settings of DC/DC and turn on DC/DC
 * 6. Make sure BUSY = high
 * 7. Send update command to COG
 * 8. Wait until BUSY = high
 * 9. Turn off DC/DC
 * End
 *
 * Max SPI clock speed is 10 MHz
 */
int EI_update_image(uint8_t * image) {
  static const uint8_t INPUT_TEMP = 0x19;
  uint8_t ret = 0;

  if (image == NULL) {
    return -1;
  }

  // Make sure DC high, RST high, CS high
  HAL_GPIO_WritePin(EPD_DC_PORT, EPD_DC_PIN, GPIO_PIN_SET);
  HAL_GPIO_WritePin(EPD_RST_PORT, EPD_RST_PIN, GPIO_PIN_SET);
  HAL_GPIO_WritePin(SPI1_CS_PORT, SPI1_CS_PIN, GPIO_PIN_SET);

  printf("Clock start: %lu\r\n", HAL_GetTick());

  ret += COG_on();
  printf("Ret from COG on\r\n");

  ret += COG_init(INPUT_TEMP);
  printf("Ret from COG init\r\n");

  ret += COG_update(image);
  printf("Ret from COG update\r\n");

  ret += COG_off();
  printf("Ret from COG off\r\n");

  printf("Clock finish: %lu\r\n", HAL_GetTick());
  printf("CLOCKS_PER_SEC: %d\r\n", HAL_GetTickFreq());

  return ret;
}

/**
 * COG Power On
 * Start
 * 1. Turn on VCC
 * 2. Delay 5ms
 * 3. Reset = 1
 * 4. Delay 5ms
 * 5. Reset = 0
 * 6. Delay 10ms
 * 7. Reset = 1
 * 8. Delay 5ms
 * 9. Soft reset (SPI 0x00, 0x0E)
 * 10.Delay 5ms
 * End
 */
int COG_on(void) {
  HAL_GPIO_WritePin(EPD_PWR_PORT, EPD_PWR_PIN, GPIO_PIN_SET);
  HAL_Delay(5);
  HAL_GPIO_WritePin(EPD_RST_PORT, EPD_RST_PIN, GPIO_PIN_SET);
  HAL_Delay(5);
  HAL_GPIO_WritePin(EPD_RST_PORT, EPD_RST_PIN, GPIO_PIN_RESET);
  HAL_Delay(10);
  HAL_GPIO_WritePin(EPD_RST_PORT, EPD_RST_PIN, GPIO_PIN_SET);
  HAL_Delay(5);

  // Send soft reset command
  COG_send_index_data(0x00, &REGISTER_DATA[1], sizeof(REGISTER_DATA[1]));

  HAL_Delay(5);
  HAL_GPIO_WritePin(EPD_RST_PORT, EPD_RST_PIN, GPIO_PIN_SET);

  return 0;
}

/**
 * COG Initial
 * Start
 * 1. Input temperature (SPI 0xE5, 0x19)
 * 2. Active temperature (SPI 0xE0, 0x02)
 * 3. Panel settings (SPI 0x00, 0x0F 0x89)
 * End
 */
int COG_init(uint8_t input_temp) {
  // Send input temperature
  COG_send_index_data(0xE5, &input_temp, sizeof(input_temp));

  // Send active temperature
  COG_send_index_data(0xE0, &REGISTER_DATA[3], sizeof(REGISTER_DATA[3]));

  // Send PSR
  COG_send_index_data(0x00, &REGISTER_DATA[4], sizeof(REGISTER_DATA[4] * 2));

  return 0;
}

/**
 * Global Update
 * Start
 * 1. DC low
 * 2. CS low
 * 3. Send first frame address (0x10)
 * 4. CS high
 * 5. DC high
 * 6. CS low
 * 7. Send first byte
 * 8. CS high
 * 9. CS low
 * 10.Send second byte
 * 11.CS high
 * ...
 * 12.CS low
 * 13.Send last byte
 * 14.CS high
 * 15.Repeat 1-14 with second frame (address 0x13, all bytes 0x00 for 15000 bytes)
 * End
 */
int COG_update(uint8_t * data) {
  int ret = 0;

  ret = COG_send_index_data(0x10, data, 15000);
  ret = COG_send_index_data(0x13, image_map, 15000);

  while(HAL_GPIO_ReadPin(EPD_BUSY_PORT, EPD_BUSY_PIN) == GPIO_PIN_RESET) {
    HAL_Delay(2);
  }

  // Send power on command
  COG_send_index_data(0x04, NULL, 0);

  while(HAL_GPIO_ReadPin(EPD_BUSY_PORT, EPD_BUSY_PIN) == GPIO_PIN_RESET){
    HAL_Delay(2);
  }

  COG_send_index_data(0x12, NULL, 0);

  while(HAL_GPIO_ReadPin(EPD_BUSY_PORT, EPD_BUSY_PIN) == GPIO_PIN_RESET){
    HAL_Delay(2);
  }

  return ret;
}

/**
 * COG Turn off DC/DC
 * Start
 * 1. Turn off DC/DC (SPI 0x02) no data
 * 2. Wait until BUSY = high
 * 3. Set RESET to floating
 * 4. Clear CS, SDIN/MISO, SCLK (set low)
 * 5. Cut off VCC to COG
 * 6. Set BUSY to output, set low (reconfig as output and set low)
 * 7. Delay 150 ms
 * 8. Set RESET to output low
 * End
 */
int COG_off(void) {
  COG_send_index_data(0x02, NULL, 0);

  while (HAL_GPIO_ReadPin(EPD_BUSY_PORT, EPD_BUSY_PIN) == GPIO_PIN_RESET) {
    HAL_Delay(2);
  }

  HAL_GPIO_WritePin(EPD_RST_PORT, EPD_RST_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(SPI1_CS_PORT, SPI1_CS_PIN, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(EPD_PWR_PORT, EPD_PWR_PIN, GPIO_PIN_RESET);

  return 0;
}

int COG_send_index_data(uint8_t index, uint8_t * data, uint32_t len) {
  unsigned int i = 0;

  // DC low, CS low
  HAL_GPIO_WritePin(EPD_DC_PORT, EPD_DC_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(SPI1_CS_PORT, SPI1_CS_PIN, GPIO_PIN_RESET);

  // Send reg address
  HAL_SPI_Transmit(&hspi1, &index, sizeof(index), HAL_MAX_DELAY);

  // CS high, DC high
  HAL_GPIO_WritePin(SPI1_CS_PORT, SPI1_CS_PIN, GPIO_PIN_SET);
  HAL_GPIO_WritePin(EPD_DC_PORT, EPD_DC_PIN, GPIO_PIN_SET);

  // CS low
  HAL_GPIO_WritePin(SPI1_CS_PORT, SPI1_CS_PIN, GPIO_PIN_RESET);

  if (data != NULL) {
    for (i = 0; i < len; i++) {
      // CS low
      HAL_GPIO_WritePin(SPI1_CS_PORT, SPI1_CS_PIN, GPIO_PIN_RESET);

      // Send image byte
      HAL_SPI_Transmit(&hspi1, &data[i], sizeof(data[i]), HAL_MAX_DELAY);

      // CS high
      HAL_GPIO_WritePin(SPI1_CS_PORT, SPI1_CS_PIN, GPIO_PIN_SET);
    }
  } else {
    for (i = 0; i < len; i++) {
      // CS low
      HAL_GPIO_WritePin(SPI1_CS_PORT, SPI1_CS_PIN, GPIO_PIN_RESET);

      // Send zero byte
      HAL_SPI_Transmit(&hspi1, 0x00, sizeof(uint8_t), HAL_MAX_DELAY);

      // CS high
      HAL_GPIO_WritePin(SPI1_CS_PORT, SPI1_CS_PIN, GPIO_PIN_SET);
    }
  }

  return 0;
}


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
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  bgfx_properties my_props = {
     .px_width = 400,
     .px_height = 300,
     .map = image_map
  };
  bgfx_setup(&my_props);
  bgfx_set_font(&BGFX_ATARI_16);

  static const uint8_t INPUT_TEMP = 0x19;
  uint8_t ret = 0;

  // Make sure DC high, RST high, CS high
  HAL_GPIO_WritePin(EPD_DC_PORT, EPD_DC_PIN, GPIO_PIN_SET);
  HAL_GPIO_WritePin(EPD_RST_PORT, EPD_RST_PIN, GPIO_PIN_SET);
  HAL_GPIO_WritePin(SPI1_CS_PORT, SPI1_CS_PIN, GPIO_PIN_SET);

  printf("Clock start: %lu\r\n", HAL_GetTick());

  ret += COG_on();
  printf("Ret from COG on\r\n");

  ret += COG_init(INPUT_TEMP);
  printf("Ret from COG init\r\n");


  bgfx_draw_string("14:05:37Z", 20, 5);
  bgfx_draw_string("08:05:37L", 20, 30);
  bgfx_draw_string("37 hours", 250, 5);
  bgfx_draw_string_modified_padding("4Q FJ", 2, 1, 20, 70);
  bgfx_draw_string_modified_padding("12345", 2, 1, 200, 70);
  bgfx_draw_string_modified_padding("67890", 2, 1, 200, 140);
  bgfx_draw_box(2,398,2,298);
  int rv = COG_update(my_props.map);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  ret += COG_off();
  printf("Ret from COG off\r\n");
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_5;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(EPD_PWR_GPIO_Port, EPD_PWR_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, EPD_DC_Pin|EPD_RST_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : EPD_PWR_Pin */
  GPIO_InitStruct.Pin = EPD_PWR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(EPD_PWR_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : EPD_BUSY_Pin */
  GPIO_InitStruct.Pin = EPD_BUSY_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(EPD_BUSY_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : EPD_DC_Pin EPD_RST_Pin LD2_Pin */
  GPIO_InitStruct.Pin = EPD_DC_Pin|EPD_RST_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI1_CS_Pin */
  GPIO_InitStruct.Pin = SPI1_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SPI1_CS_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
