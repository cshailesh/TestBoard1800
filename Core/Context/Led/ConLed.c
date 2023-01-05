/*
 * CKeyboard.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#include "ConLed.h"

void _LedStateClear(LED_DATA_t *pDat, uint8_t pLedIdx)
{
	pDat->mLedState[pLedIdx] = LED_STATE_OFF;
}

void LedStateChange(LED_DATA_t *pDat, uint8_t pLedNo, eLED_STATE pState,
		eLED_BLINK_RATE pRate)
{
	_LedStateClear(pDat, pLedNo - 1);
	if (pState == LED_STATE_BLINK)
	{
		pDat->mLedState[pLedNo - 1] = LED_STATE_BLINK;
		pDat->mLedBlinkRate[pLedNo - 1] = pRate;
	}
	else
	{
		pDat->mLedState[pLedNo - 1] = pState;
	}
}

void LedProcess(LED_DATA_t *pDat)
{
	for (int i = 0; i < LED_COUNT; ++i)
	{
		if (pDat->mLedState[i] == LED_STATE_BLINK)
		{
			if (pDat->mLedBlinkCnt[i] > pDat->mLedBlinkRate[i])
			{
				_LED_Toggle(i);
				pDat->mLedBlinkCnt[i] = 0;
			}
		}
		else if (pDat->mLedState[i] == LED_STATE_OFF)
		{
			_LED_SetOff(i);
			pDat->mLedBlinkCnt[i] = 0;
		}
		else if (pDat->mLedState[i] == LED_STATE_ON)
		{
			_LED_SetOn(i);
			pDat->mLedBlinkCnt[i] = 0;
		}
	}
}

void LedDataInit(LED_DATA_t *pDat)
{
	_LedStateClear(pDat, 0);
	_LedStateClear(pDat, 1);
	_LedStateClear(pDat, 2);
}

void TaskLed()
{

	LED_DATA_t *ptrLedData = &gContextLedData.mLedData;
	LedDataInit(ptrLedData);

	while (1)
	{
		LedProcess(ptrLedData);
	}
}
