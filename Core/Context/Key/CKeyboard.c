/*
 * CKeyboard.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#include "CKeyboard.h"

uint8_t gKeyPressed;
uint8_t gKeyLastPressed;

//extern uint32_t timeOn[];
//extern uint32_t timeStart[];
//extern uint8_t bTime[];

#define NUM_DIG_INPUT 4

static GPIO_t DiscreteInput[NUM_DIG_INPUT] =
{
// DIGITAL OUT 8 PINS
		{ .port = SWITCH1_GPIO_Port, .pin = SWITCH1_Pin },
		{ .port = SWITCH2_GPIO_Port, .pin = SWITCH2_Pin },
		{ .port = SWITCH3_GPIO_Port, .pin = SWITCH3_Pin },
		{ .port = SWITCH4_GPIO_Port, .pin = SWITCH4_Pin } };

static GPIO_t* _GetInputPtr(int pIdx)
{
	GPIO_t *pOutput = NULL;
	if (pIdx < NUM_DIG_INPUT)
	{
		pOutput = &DiscreteInput[pIdx];
	}
	return pOutput;
}

uint8_t _DigitReadInput(uint8_t pIdx)
{
	uint8_t val = 0;

	if (pIdx < NUM_DIG_INPUT)
	{
		GPIO_t *pOutput = _GetInputPtr(pIdx);
		val = HAL_GPIO_ReadPin(pOutput->port, pOutput->pin);
	}
	return val;
}

uint8_t _ReadKeyPin()
{
	uint8_t keyBits = 0;
	uint32_t tickstart = HAL_GetTick();
	uint32_t wait = KEYBOARD_DELAY;
	for (uint8_t var = 0; var < NUM_DIG_INPUT; ++var)
	{
		if (wait < HAL_MAX_DELAY)
			wait += (uint32_t) (uwTickFreq);

		keyBits = _DigitReadInput(var);
		if (!keyBits)
		{
			KEY_DEDBOUCE_DELAY()
			keyBits = _DigitReadInput(var);
			while ((!keyBits) && ((HAL_GetTick() - tickstart) < wait))
			{
			}
			keyBits |= (1 << var);
			return KEYBRD_SW1 + var;
		}
	}
	return KEYBRD_NONE;

}

uint8_t ReadKeyBoard()
{
	gKeyPressed = _ReadKeyPin();
	if (gKeyPressed != KEYBRD_NONE)
	{
		gKeyLastPressed = gKeyPressed;
	}

	return gKeyPressed;
}

uint8_t GetKeyPressed()
{
	return gKeyPressed;
}

void ResetKeyPresed()
{
	gKeyPressed = KEYBRD_NONE;
}

void KeyboardInit(void)
{
	gKeyPressed = KEYBRD_NONE;
}

