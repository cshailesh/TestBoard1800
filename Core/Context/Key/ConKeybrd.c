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

		DigitalOutSetPin(&pCD->mDigOutData, 1, 0);
		DigitalOutSetPin(&pCD->mDigOutData, 2, 1);
		DigitalOutSetPin(&pCD->mDigOutData, 3, 0);
		DigitalOutSetPin(&pCD->mDigOutData, 4, 1);
		DigitalOutSetPin(&pCD->mDigOutData, 5, 0);
		DigitalOutSetPin(&pCD->mDigOutData, 6, 1);
		DigitalOutSetPin(&pCD->mDigOutData, 7, 0);
		DigitalOutSetPin(&pCD->mDigOutData, 8, 1);

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

		DigitOutAllOff(&pCD->mDigOutData);

		gKeyboardLastProcessedKey = KEYBRD_SW3;
	}

	else if (pKey == KEYBRD_SW4)
	{
		LedStateChange(&pCD->mLedData, 1, LED_STATE_OFF,LED_BLINK_SPEED_FAST);
		LedStateChange(&pCD->mLedData, 2, LED_STATE_OFF,LED_BLINK_SPEED_FAST);
		LedStateChange(&pCD->mLedData, 3, LED_STATE_OFF,LED_BLINK_SPEED_FAST);

		DigitOutAllOn(&pCD->mDigOutData);

		gKeyboardLastProcessedKey = KEYBRD_SW4;

	}

	if (gKeyboardLastProcessedKey > KEYBRD_NONE)
	{
//			FRAM_WriteConData(pCD);
//			Buzzer_Do_Beep();
	}
}

