/*
 * CKeyboard.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#include "ConLed.h"

void LedStateClear(LED_DATA_t *pDat, uint8_t pLedIdx)
{
	pDat->mLedState[pLedIdx] = LED_STATE_OFF;
	pDat->mLedBlinkRate[pLedIdx] = LED_BLINK_SPEED_NONE;
	pDat->mLedBlinkCnt[pLedIdx] = 0;
}

void LedStateChange(LED_DATA_t *pDat, uint8_t pLedNo, eLED_STATE pState,
		eLED_BLINK_RATE pRate)
{
	LedStateClear(pDat, pLedNo - 1);
	if (pState != LED_STATE_BLINK)
	{
		pDat->mLedState[pLedNo - 1] = LED_STATE_BLINK;
		pDat->mLedBlinkRate[pLedNo - 1] = pRate;
	}
	else
	{
		pDat->mLedState[pLedNo] = pState;
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
				if (i == 0)
				{
					LED1_TOG();
					pDat->mLedBlinkCnt[i] = 0;
				}
				if (i == 1)
				{
					LED2_TOG();
					pDat->mLedBlinkCnt[i] = 0;
				}
				if (i == 2)
				{
					LED3_TOG();
					pDat->mLedBlinkCnt[i] = 0;
				}
			}
		}
		else if (pDat->mLedState[i] == LED_STATE_OFF)
		{
			if (i == 0)
			{
				LED1_OFF();
				pDat->mLedBlinkCnt[i] = 0;
			}
			if (i == 1)
			{
				LED2_OFF();
				pDat->mLedBlinkCnt[i] = 0;
			}
			if (i == 2)
			{
				LED3_OFF();
				pDat->mLedBlinkCnt[i] = 0;
			}
		}
		else if (pDat->mLedState[i] == LED_STATE_ON)
		{
			if (i == 0)
			{
				LED1_ON();
				pDat->mLedBlinkCnt[i] = 0;
			}
			if (i == 1)
			{
				LED2_ON();
				pDat->mLedBlinkCnt[i] = 0;
			}
			if (i == 2)
			{
				LED3_ON();
				pDat->mLedBlinkCnt[i] = 0;
			}
		}

	}
}

void LedDataInit(LED_DATA_t *pDat)
{
	LedStateClear(pDat, 0);
	LedStateClear(pDat, 1);
	LedStateClear(pDat, 2);
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
