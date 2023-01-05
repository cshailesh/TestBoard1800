/*
 *  Created on: Feb 10, 2022
 *      Author: LINK4
 */
#include "ConDigitalOut.h"

void DigitalOutSetPin(DIGITAL_OUT_DATA_t *pDat, uint8_t pPinNo, uint8_t pHiLow)
{
	pDat->mDOut[pPinNo - 1] = pHiLow;
}

void DigitOutAllOff(DIGITAL_OUT_DATA_t *pDat)
{
	for (uint8_t i = 0; i < 8; ++i)
	{
		DigitalOutSetPin(pDat, i + 1, 0);
	}
}

void DigitOutAllOn(DIGITAL_OUT_DATA_t *pDat)
{
	for (uint8_t i = 0; i < 8; ++i)
	{
		DigitalOutSetPin(pDat, i + 1, 1);
	}
}


void DigitOutInit(DIGITAL_OUT_DATA_t *pDat)
{
	for (uint8_t i = 0; i < 8; ++i)
	{
		DigitalOutSetPin(pDat, i + 1, 0);
	}
	DigitalOutProcess(pDat);
}

void DigitalOutProcess(DIGITAL_OUT_DATA_t *pDat)
{
	uint8_t val = 0;

	for (uint8_t i = 0; i < 8; ++i)
	{
		val = pDat->mDOut[i];
		_DigitalOutSetPin(val,i);
	}
}

