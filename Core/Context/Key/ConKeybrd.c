/*
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */
#include "ConKeybrd.h"

uint8_t gKeyboardLastProcessedKey;
void ProcessKeyboardPress(CONTEXT_DATA_t *pCD, uint8_t pKey)
{
	if (pKey == KEYBRD_SW1)
	{
		LedStateChange(&pCD->mLedData, 3, LED_STATE_BLINK,LED_BLINK_SPEED_SLOW);
		gKeyboardLastProcessedKey = KEYBRD_SW1;
	}
	else if (pKey == KEYBRD_SW2)
	{
		LedStateChange(&pCD->mLedData, 3, LED_STATE_BLINK,LED_BLINK_SPEED_MED);
		gKeyboardLastProcessedKey = KEYBRD_SW2;
	}
	else if (pKey == KEYBRD_SW3)
	{
		LedStateChange(&pCD->mLedData, 3, LED_STATE_BLINK,LED_BLINK_SPEED_FAST);
		gKeyboardLastProcessedKey = KEYBRD_SW3;
	}

	else if (pKey == KEYBRD_SW4)
	{
		gKeyboardLastProcessedKey = KEYBRD_SW4;
	}

	if (gKeyboardLastProcessedKey > KEYBRD_NONE)
	{
//			FRAM_WriteConData(pCD);
//			Buzzer_Do_Beep();
	}
}

