/*
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef CDIGITAL_OUT_H_
#define CDIGITAL_OUT_H_

#include <ConHeader.h>

#define _DOut1_ON() HAL_GPIO_WritePin(DOut1_GPIO_Port, DOut1_Pin, GPIO_PIN_RESET)
#define _DOut2_ON() HAL_GPIO_WritePin(DOut2_GPIO_Port, DOut2_Pin, GPIO_PIN_RESET)
#define _DOut3_ON() HAL_GPIO_WritePin(DOut3_GPIO_Port, DOut3_Pin, GPIO_PIN_RESET)
#define _DOut4_ON() HAL_GPIO_WritePin(DOut4_GPIO_Port, DOut4_Pin, GPIO_PIN_RESET)
#define _DOut5_ON() HAL_GPIO_WritePin(DOut5_GPIO_Port, DOut5_Pin, GPIO_PIN_RESET)
#define _DOut6_ON() HAL_GPIO_WritePin(DOut6_GPIO_Port, DOut6_Pin, GPIO_PIN_RESET)
#define _DOut7_ON() HAL_GPIO_WritePin(DOut7_GPIO_Port, DOut7_Pin, GPIO_PIN_RESET)
#define _DOut8_ON() HAL_GPIO_WritePin(DOut8_GPIO_Port, DOut8_Pin, GPIO_PIN_RESET)

#define _DOut1_OFF() HAL_GPIO_WritePin(DOut1_GPIO_Port, DOut1_Pin, GPIO_PIN_SET)
#define _DOut2_OFF() HAL_GPIO_WritePin(DOut2_GPIO_Port, DOut2_Pin, GPIO_PIN_SET)
#define _DOut3_OFF() HAL_GPIO_WritePin(DOut3_GPIO_Port, DOut3_Pin, GPIO_PIN_SET)
#define _DOut4_OFF() HAL_GPIO_WritePin(DOut4_GPIO_Port, DOut4_Pin, GPIO_PIN_SET)
#define _DOut5_OFF() HAL_GPIO_WritePin(DOut5_GPIO_Port, DOut5_Pin, GPIO_PIN_SET)
#define _DOut6_OFF() HAL_GPIO_WritePin(DOut6_GPIO_Port, DOut6_Pin, GPIO_PIN_SET)
#define _DOut7_OFF() HAL_GPIO_WritePin(DOut7_GPIO_Port, DOut7_Pin, GPIO_PIN_SET)
#define _DOut8_OFF() HAL_GPIO_WritePin(DOut8_GPIO_Port, DOut8_Pin, GPIO_PIN_SET)

#define _DOut1_TOG() HAL_GPIO_TogglePin(DOut1_GPIO_Port, DOut1_Pin)
#define _DOut2_TOG() HAL_GPIO_TogglePin(DOut2_GPIO_Port, DOut2_Pin)
#define _DOut3_TOG() HAL_GPIO_TogglePin(DOut3_GPIO_Port, DOut3_Pin)
#define _DOut4_TOG() HAL_GPIO_TogglePin(DOut4_GPIO_Port, DOut4_Pin)
#define _DOut5_TOG() HAL_GPIO_TogglePin(DOut5_GPIO_Port, DOut5_Pin)
#define _DOut6_TOG() HAL_GPIO_TogglePin(DOut6_GPIO_Port, DOut6_Pin)
#define _DOut7_TOG() HAL_GPIO_TogglePin(DOut7_GPIO_Port, DOut7_Pin)
#define _DOut8_TOG() HAL_GPIO_TogglePin(DOut8_GPIO_Port, DOut8_Pin)

#endif /* CDIGITAL_OUT_H_ */
