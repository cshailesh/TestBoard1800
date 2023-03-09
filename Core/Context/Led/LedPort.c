/*
 * CKeyboard.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#include <LedPort.h>

static GPIO_t LEDs[LED_NUM] =
{ [LED1] =
{ .port = LED1_GPIO_Port, .pin = LED1_Pin },		// LED_TX (PC10)
		[LED2] =
		{ .port = LED2_GPIO_Port, .pin = LED2_Pin },		// LED_RX (PB09)
		[LED3] =
		{ .port = LED3_GPIO_Port, .pin = LED3_Pin },	// LED_HEARTBEAT (PB10)
		};

void LED_Init(void)
{

}

void _LED_SetOn(uint8_t pLed)
{
	HAL_GPIO_WritePin(LEDs[pLed].port, LEDs[pLed].pin, GPIO_PIN_RESET);
}

void _LED_SetAllOn()
{
	for (int i = 0; i < LED_NUM; i++)
	{
		_LED_SetOn(i);
	}
}

void _LED_SetOff(uint8_t pLed)
{
	HAL_GPIO_WritePin(LEDs[pLed].port, LEDs[pLed].pin, GPIO_PIN_SET);
}

void _LED_SetAllOff()
{
	for (int i = 0; i < LED_NUM; i++)
	{
		_LED_SetOff(i);
	}
}

void _LED_Toggle(uint8_t pLed)
{
//	if (_LED_GetState(pLed))
//		_LED_SetOff(pLed);
//	else
//		_LED_SetOn(pLed);
	HAL_GPIO_TogglePin(LEDs[pLed].port, LEDs[pLed].pin);

}

_Bool _LED_GetState(uint8_t pled)
{
	_Bool bLEDLevel = HAL_GPIO_ReadPin(LEDs[pled].port, LEDs[pled].pin);

	return bLEDLevel;
}

