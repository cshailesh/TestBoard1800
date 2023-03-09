/*
 * CKeyboard.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef CLED_H_
#define CLED_H_

#include <ConHeader.h>

#define LED_NUM	3

#define LED1 0
#define LED2 1
#define LED3 2

void _LED_SetOn(uint8_t pLed);
void _LED_SetOff(uint8_t pLed);
void _LED_Toggle(uint8_t pLed);
void _LED_SetAllOn();
void _LED_SetAllOff();
_Bool _LED_GetState(uint8_t pled);

//#define _LED1_ON() HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET)
//#define _LED2_ON() HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET)
//#define _LED3_ON() HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET)
//
//#define _LED1_OFF() HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET)
//#define _LED2_OFF() HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET)
//#define _LED3_OFF() HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET)
//
//#define _LED1_TOG() 	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin)
//#define _LED2_TOG() 	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin)
//#define _LED3_TOG() 	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin)

#endif /* CLED_H */
