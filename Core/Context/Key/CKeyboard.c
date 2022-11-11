/*
 * CKeyboard.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#include "CKeyboard.h"

uint8_t gKeyPressed;
uint8_t gKeyLastPressed;

uint8_t ReadKeyPin()
{

	uint32_t tickstart = HAL_GetTick();
	uint32_t wait = KEYBOARD_DELAY;

	/* Add a freq to guarantee minimum wait */

	if (wait < HAL_MAX_DELAY)
		wait += (uint32_t) (uwTickFreq);

	if (KEYB_IS_KEY1_PRESSED())
	{
		KEY_DEDBOUCE_DELAY();
		while (KEYB_IS_KEY1_PRESSED() && ((HAL_GetTick() - tickstart) < wait))
		{
		}

		return KEYBRD_SW1;
	}

	if (KEYB_IS_KEY2_PRESSED())
	{
		KEY_DEDBOUCE_DELAY();
		while (KEYB_IS_KEY2_PRESSED() && ((HAL_GetTick() - tickstart) < wait))
		{
		}

		return KEYBRD_SW2;
	}

	if (KEYB_IS_KEY3_PRESSED())
	{
		KEY_DEDBOUCE_DELAY();
		while (KEYB_IS_KEY3_PRESSED() && ((HAL_GetTick() - tickstart) < wait))
		{
		}

		return KEYBRD_SW3;
	}

	if (KEYB_IS_KEY4_PRESSED())
	{
		KEY_DEDBOUCE_DELAY();
		while (KEYB_IS_KEY4_PRESSED() && ((HAL_GetTick() - tickstart) < wait))
		{
		}

		return KEYBRD_SW4;
	}

	return KEYBRD_NONE;

}

uint8_t ReadKeyBoard()
{
	gKeyPressed = ReadKeyPin();
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

