/*
 * CKeyboard.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef CKEYBOARD_H_
#define CKEYBOARD_H_

#include "ContextHeader.h"

#define KEYBRD_NONE		5
#define KEYBRD_SW1		11
#define KEYBRD_SW2		12
#define KEYBRD_SW3		13
#define KEYBRD_SW4		14

#define SW_KEY1_PIN  SWITCH1_Pin
#define SW_KEY1_PORT SWITCH1_GPIO_Port

#define SW_KEY2_PIN  SWITCH2_Pin
#define SW_KEY2_PORT SWITCH2_GPIO_Port

#define SW_KEY3_PIN  SWITCH3_Pin
#define SW_KEY3_PORT SWITCH3_GPIO_Port

#define SW_KEY4_PIN  SWITCH4_Pin
#define SW_KEY4_PORT SWITCH4_GPIO_Port

#define KEY_DEDBOUCE_DELAY() HAL_Delay(10);

#define KEYB_IS_KEY1_PRESSED() (HAL_GPIO_ReadPin(SW_KEY1_PORT, SW_KEY1_PIN) == GPIO_PIN_RESET)
#define KEYB_IS_KEY2_PRESSED() (HAL_GPIO_ReadPin(SW_KEY2_PORT, SW_KEY2_PIN) == GPIO_PIN_RESET)
#define KEYB_IS_KEY3_PRESSED() (HAL_GPIO_ReadPin(SW_KEY3_PORT, SW_KEY3_PIN) == GPIO_PIN_RESET)
#define KEYB_IS_KEY4_PRESSED() (HAL_GPIO_ReadPin(SW_KEY4_PORT, SW_KEY4_PIN) == GPIO_PIN_RESET)

#define KEYBOARD_DELAY 10

uint8_t ReadKeyPin();
uint8_t ReadKeyBoard();
uint8_t GetKeyPressed();
void ResetKeyPresed();
void KeyboardInit(void);

#endif /* CKEYBOARD_H_ */
