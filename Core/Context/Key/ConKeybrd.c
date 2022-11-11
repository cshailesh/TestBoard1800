/*
 * ConKeybrd.h
 *
 *  Created on: Feb 10, 2022
 *      Author: ADITYA
 */
#include "ConKeybrd.h"

uint8_t gKeyboardLastProcessedKey;
void ProcessKeyboardPress(CONTEXT_DATA_t *pCD, uint8_t pKey)
{
	if (pKey == KEYBRD_SW1)
	{
//			if (pCD->mIsOn == 1)
//			{
//				OPDLightsOff(pCD, 0);
//			}
//			else
//			{
//				pCD->mIsOn = 1;
//			}
		gKeyboardLastProcessedKey = KEYBRD_SW1;
	}
	else if (pKey == KEYBRD_SW2)
	{
//			pCD->mCurUser = 0;
//			OPDLightsSetHalf(pCD, 0);
//			pCD->mIsOn = 1;
		gKeyboardLastProcessedKey = KEYBRD_SW2;
	}
	else if (pKey == KEYBRD_SW3)
	{
//			OPDLightIncDec(0, 1, 0, pCD, 0);
//			pCD->mIsOn = 1;
		gKeyboardLastProcessedKey = KEYBRD_SW3;
	}

	else if (pKey == KEYBRD_SW4)
	{
//			OPDLightIncDec(0, 0, 1, pCD, 0);
//			pCD->mIsOn = 1;
		gKeyboardLastProcessedKey = KEYBRD_SW4;
	}

	if (gKeyboardLastProcessedKey > KEYBRD_NONE)
	{
//			FRAM_WriteConData(pCD);
//			Buzzer_Do_Beep();
	}
}


