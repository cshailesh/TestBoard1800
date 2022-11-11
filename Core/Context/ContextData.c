/*
 * ContextData.h
 *
 *  Created on: Feb 10, 2022
 *      Author: ADITYA
 */

#include "ContextData.h"

void ContextDataInit(CONTEXT_DATA_t *pCD)
{
	for (int i = 0; i < 8; ++i)
	{
		pCD->mAnalogOutData.mAdcVal[i] = 0;
		pCD->mDigOutData.mDigVal[i] = 0;
		pCD->mPwmData.mPWMCurVal[i] = 0;
	}
	LedDataInit(&pCD->mLedData);
}

