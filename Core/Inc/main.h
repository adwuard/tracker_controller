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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define USER_LED_Pin GPIO_PIN_13
#define USER_LED_GPIO_Port GPIOC
#define BTN_UP_Pin GPIO_PIN_3
#define BTN_UP_GPIO_Port GPIOA
#define BTN_DOWN_Pin GPIO_PIN_4
#define BTN_DOWN_GPIO_Port GPIOA
#define BTN_LEFT_Pin GPIO_PIN_5
#define BTN_LEFT_GPIO_Port GPIOA
#define BTN_RIGHT_Pin GPIO_PIN_6
#define BTN_RIGHT_GPIO_Port GPIOA
#define BTN_A_Pin GPIO_PIN_7
#define BTN_A_GPIO_Port GPIOA
#define BTN_B_Pin GPIO_PIN_0
#define BTN_B_GPIO_Port GPIOB
#define BTN_SHIFT_Pin GPIO_PIN_1
#define BTN_SHIFT_GPIO_Port GPIOB
#define BTN_PLAY_Pin GPIO_PIN_2
#define BTN_PLAY_GPIO_Port GPIOB
#define USER_OUT_GPIO_2_Pin GPIO_PIN_13
#define USER_OUT_GPIO_2_GPIO_Port GPIOB
#define USER_OUT_GPIO_1_Pin GPIO_PIN_14
#define USER_OUT_GPIO_1_GPIO_Port GPIOB
#define USER_IN_GPIO_2_Pin GPIO_PIN_15
#define USER_IN_GPIO_2_GPIO_Port GPIOB
#define USER_IN_GPIO_1_Pin GPIO_PIN_8
#define USER_IN_GPIO_1_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
