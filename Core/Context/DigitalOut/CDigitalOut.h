/*
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef CDIGITAL_OUT_H_
#define CDIGITAL_OUT_H_

#include "ContextHeader.h"

#define DOut1_ON() HAL_GPIO_WritePin(DOut1_GPIO_Port, DOut1_Pin, GPIO_PIN_RESET)
#define DOut2_ON() HAL_GPIO_WritePin(DOut2_GPIO_Port, DOut2_Pin, GPIO_PIN_RESET)
#define DOut3_ON() HAL_GPIO_WritePin(DOut3_GPIO_Port, DOut3_Pin, GPIO_PIN_RESET)
#define DOut4_ON() HAL_GPIO_WritePin(DOut4_GPIO_Port, DOut4_Pin, GPIO_PIN_RESET)
#define DOut5_ON() HAL_GPIO_WritePin(DOut5_GPIO_Port, DOut5_Pin, GPIO_PIN_RESET)
#define DOut6_ON() HAL_GPIO_WritePin(DOut6_GPIO_Port, DOut6_Pin, GPIO_PIN_RESET)
#define DOut7_ON() HAL_GPIO_WritePin(DOut7_GPIO_Port, DOut7_Pin, GPIO_PIN_RESET)
#define DOut8_ON() HAL_GPIO_WritePin(DOut8_GPIO_Port, DOut8_Pin, GPIO_PIN_RESET)

#define DOut1_OFF() HAL_GPIO_WritePin(DOut1_GPIO_Port, DOut1_Pin, GPIO_PIN_SET)
#define DOut2_OFF() HAL_GPIO_WritePin(DOut2_GPIO_Port, DOut2_Pin, GPIO_PIN_SET)
#define DOut3_OFF() HAL_GPIO_WritePin(DOut3_GPIO_Port, DOut3_Pin, GPIO_PIN_SET)
#define DOut4_OFF() HAL_GPIO_WritePin(DOut4_GPIO_Port, DOut4_Pin, GPIO_PIN_SET)
#define DOut5_OFF() HAL_GPIO_WritePin(DOut5_GPIO_Port, DOut5_Pin, GPIO_PIN_SET)
#define DOut6_OFF() HAL_GPIO_WritePin(DOut6_GPIO_Port, DOut6_Pin, GPIO_PIN_SET)
#define DOut7_OFF() HAL_GPIO_WritePin(DOut7_GPIO_Port, DOut7_Pin, GPIO_PIN_SET)
#define DOut8_OFF() HAL_GPIO_WritePin(DOut8_GPIO_Port, DOut8_Pin, GPIO_PIN_SET)

#define DOut1_TOG() HAL_GPIO_TogglePin(DOut1_GPIO_Port, DOut1_Pin)
#define DOut2_TOG() HAL_GPIO_TogglePin(DOut2_GPIO_Port, DOut2_Pin)
#define DOut3_TOG() HAL_GPIO_TogglePin(DOut3_GPIO_Port, DOut3_Pin)
#define DOut4_TOG() HAL_GPIO_TogglePin(DOut4_GPIO_Port, DOut4_Pin)
#define DOut5_TOG() HAL_GPIO_TogglePin(DOut5_GPIO_Port, DOut5_Pin)
#define DOut6_TOG() HAL_GPIO_TogglePin(DOut6_GPIO_Port, DOut6_Pin)
#define DOut7_TOG() HAL_GPIO_TogglePin(DOut7_GPIO_Port, DOut7_Pin)
#define DOut8_TOG() HAL_GPIO_TogglePin(DOut8_GPIO_Port, DOut8_Pin)

#endif /* CDIGITAL_OUT_H_ */
