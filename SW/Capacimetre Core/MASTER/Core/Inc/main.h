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
#include "stm32h7xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define NTC2_Pin GPIO_PIN_4
#define NTC2_GPIO_Port GPIOC
#define NTC1_Pin GPIO_PIN_5
#define NTC1_GPIO_Port GPIOC
#define IMON_Pin GPIO_PIN_0
#define IMON_GPIO_Port GPIOB
#define FAN1_RPM_Pin GPIO_PIN_10
#define FAN1_RPM_GPIO_Port GPIOB
#define FAN1_PWM_Pin GPIO_PIN_11
#define FAN1_PWM_GPIO_Port GPIOB
#define FAN2_PWM_Pin GPIO_PIN_14
#define FAN2_PWM_GPIO_Port GPIOB
#define FUSE_FLTB_Pin GPIO_PIN_8
#define FUSE_FLTB_GPIO_Port GPIOD
#define FUSE_EN_Pin GPIO_PIN_9
#define FUSE_EN_GPIO_Port GPIOD
#define DCDC_S_EN_Pin GPIO_PIN_7
#define DCDC_S_EN_GPIO_Port GPIOC
#define DCDC_M_PG_Pin GPIO_PIN_9
#define DCDC_M_PG_GPIO_Port GPIOC
#define DCDC_M_EN_Pin GPIO_PIN_8
#define DCDC_M_EN_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_4
#define LED1_GPIO_Port GPIOD
#define LED2_Pin GPIO_PIN_5
#define LED2_GPIO_Port GPIOD
#define LED3_Pin GPIO_PIN_6
#define LED3_GPIO_Port GPIOD
#define LED4_Pin GPIO_PIN_7
#define LED4_GPIO_Port GPIOD
#define BUZZ_Pin GPIO_PIN_7
#define BUZZ_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
