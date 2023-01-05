/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32g0xx_hal.h"
#include "stm32g0xx_ll_crc.h"
#include "stm32g0xx_ll_bus.h"
#include "stm32g0xx_ll_cortex.h"
#include "stm32g0xx_ll_rcc.h"
#include "stm32g0xx_ll_system.h"
#include "stm32g0xx_ll_utils.h"
#include "stm32g0xx_ll_pwr.h"
#include "stm32g0xx_ll_gpio.h"
#include "stm32g0xx_ll_dma.h"

#include "stm32g0xx_ll_exti.h"

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
#define FRAM_CS_Pin GPIO_PIN_1
#define FRAM_CS_GPIO_Port GPIOA
#define FRAM_HOLD_Pin GPIO_PIN_2
#define FRAM_HOLD_GPIO_Port GPIOA
#define FRAM_CLK_Pin GPIO_PIN_5
#define FRAM_CLK_GPIO_Port GPIOA
#define FRAM_SO_Pin GPIO_PIN_6
#define FRAM_SO_GPIO_Port GPIOA
#define FRAM_SI_Pin GPIO_PIN_7
#define FRAM_SI_GPIO_Port GPIOA
#define SWITCH1_Pin GPIO_PIN_11
#define SWITCH1_GPIO_Port GPIOB
#define SWITCH2_Pin GPIO_PIN_12
#define SWITCH2_GPIO_Port GPIOB
#define SWITCH3_Pin GPIO_PIN_13
#define SWITCH3_GPIO_Port GPIOB
#define SWITCH4_Pin GPIO_PIN_14
#define SWITCH4_GPIO_Port GPIOB
#define DOut8_Pin GPIO_PIN_8
#define DOut8_GPIO_Port GPIOD
#define DOut7_Pin GPIO_PIN_9
#define DOut7_GPIO_Port GPIOD
#define DOut6_Pin GPIO_PIN_10
#define DOut6_GPIO_Port GPIOA
#define DOut5_Pin GPIO_PIN_11
#define DOut5_GPIO_Port GPIOA
#define DOut4_Pin GPIO_PIN_15
#define DOut4_GPIO_Port GPIOA
#define DOut3_Pin GPIO_PIN_8
#define DOut3_GPIO_Port GPIOC
#define DOut2_Pin GPIO_PIN_9
#define DOut2_GPIO_Port GPIOC
#define DOut1_Pin GPIO_PIN_0
#define DOut1_GPIO_Port GPIOD
#define USART3_DE_Pin GPIO_PIN_2
#define USART3_DE_GPIO_Port GPIOD
#define LED1_Pin GPIO_PIN_3
#define LED1_GPIO_Port GPIOD
#define LED2_Pin GPIO_PIN_4
#define LED2_GPIO_Port GPIOD
#define LED3_Pin GPIO_PIN_5
#define LED3_GPIO_Port GPIOD
#define USART1_DE_Pin GPIO_PIN_3
#define USART1_DE_GPIO_Port GPIOB
#define RS485_1_TX_Pin GPIO_PIN_6
#define RS485_1_TX_GPIO_Port GPIOB
#define RS485_1_RX_Pin GPIO_PIN_7
#define RS485_1_RX_GPIO_Port GPIOB
#define RS485_2_RX_Pin GPIO_PIN_9
#define RS485_2_RX_GPIO_Port GPIOB
#define RS485_2_TX_Pin GPIO_PIN_10
#define RS485_2_TX_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
