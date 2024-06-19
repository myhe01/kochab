/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
int EI_update_image(uint8_t * image);
int COG_init(uint8_t input_temp);
int COG_on(void);
int COG_update(uint8_t * data);
int COG_off(void);
int COG_send_index_data(uint8_t index, uint8_t * data, uint32_t len);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOH
#define EPD_PWR_Pin GPIO_PIN_2
#define EPD_PWR_GPIO_Port GPIOC
#define EPD_BUSY_Pin GPIO_PIN_0
#define EPD_BUSY_GPIO_Port GPIOA
#define EPD_DC_Pin GPIO_PIN_1
#define EPD_DC_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define EPD_RST_Pin GPIO_PIN_4
#define EPD_RST_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SPI1_CS_Pin GPIO_PIN_6
#define SPI1_CS_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define IMAGE_WIDTH (int)400
#define IMAGE_HEIGHT (int)300
#define BYTES_PER_ROW (int)(IMAGE_WIDTH / (sizeof(uint8_t) * 8))

#define LETTER_WIDTH (int)8
#define LETTER_HEIGHT (int)12

#define EPD_PWR_PIN		GPIO_PIN_2
#define EPD_PWR_PORT	GPIOC
#define EPD_BUSY_PIN	GPIO_PIN_0
#define EPD_BUSY_PORT	GPIOA
#define EPD_DC_PIN    	GPIO_PIN_1
#define EPD_DC_PORT		GPIOA
#define EPD_RST_PIN   	GPIO_PIN_4
#define EPD_RST_PORT	GPIOA
#define SPI1_CS_PIN		GPIO_PIN_6
#define SPI1_CS_PORT	GPIOB
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
