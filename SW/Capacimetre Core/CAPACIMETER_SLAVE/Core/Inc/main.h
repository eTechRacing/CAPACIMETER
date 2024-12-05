/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

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
#define K22_Pin GPIO_PIN_3
#define K22_GPIO_Port GPIOE
#define K21_Pin GPIO_PIN_4
#define K21_GPIO_Port GPIOE
#define CH2_INT_Pin GPIO_PIN_13
#define CH2_INT_GPIO_Port GPIOC
#define Csense2_Pin GPIO_PIN_1
#define Csense2_GPIO_Port GPIOC
#define NTC1_Pin GPIO_PIN_2
#define NTC1_GPIO_Port GPIOC
#define NTC2_Pin GPIO_PIN_3
#define NTC2_GPIO_Port GPIOC
#define CELL2_LED1_Pin GPIO_PIN_1
#define CELL2_LED1_GPIO_Port GPIOA
#define CELL2_LED2_Pin GPIO_PIN_2
#define CELL2_LED2_GPIO_Port GPIOA
#define CSense1_Pin GPIO_PIN_5
#define CSense1_GPIO_Port GPIOC
#define U_LED1_Pin GPIO_PIN_7
#define U_LED1_GPIO_Port GPIOE
#define U_LED2_Pin GPIO_PIN_8
#define U_LED2_GPIO_Port GPIOE
#define U_LED3_Pin GPIO_PIN_9
#define U_LED3_GPIO_Port GPIOE
#define U_LED4_Pin GPIO_PIN_10
#define U_LED4_GPIO_Port GPIOE
#define K11_Pin GPIO_PIN_12
#define K11_GPIO_Port GPIOD
#define K12_Pin GPIO_PIN_13
#define K12_GPIO_Port GPIOD
#define ID1_Pin GPIO_PIN_6
#define ID1_GPIO_Port GPIOC
#define ID2_Pin GPIO_PIN_7
#define ID2_GPIO_Port GPIOC
#define ID3_Pin GPIO_PIN_8
#define ID3_GPIO_Port GPIOC
#define ID4_Pin GPIO_PIN_9
#define ID4_GPIO_Port GPIOC
#define CS_3V3_Pin GPIO_PIN_15
#define CS_3V3_GPIO_Port GPIOA
#define CH1_INT_Pin GPIO_PIN_0
#define CH1_INT_GPIO_Port GPIOD
#define CELL1_LED2_Pin GPIO_PIN_3
#define CELL1_LED2_GPIO_Port GPIOD
#define CELL1_LED1_Pin GPIO_PIN_4
#define CELL1_LED1_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
