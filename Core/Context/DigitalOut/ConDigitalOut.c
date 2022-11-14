/*
 *  Created on: Feb 10, 2022
 *      Author: LINK4
 */
#include "ConDigitalOut.h"


void _DigitOutProcessPin(uint8_t pNo, uint8_t pVal)
{
	switch (pNo)
	{
	case 0:
		if (pVal > 0)
			_DOut1_ON();
		else
			_DOut1_OFF();
		break;
	case 1:
		if (pVal > 0)
			_DOut2_ON();
		else
			_DOut2_OFF();
		break;
	case 2:
		if (pVal > 0)
			_DOut3_ON();
		else
			_DOut3_OFF();
		break;
	case 3:
		if (pVal > 0)
			_DOut4_ON();
		else
			_DOut4_OFF();
		break;
	case 4:
		if (pVal > 0)
			_DOut5_ON();
		else
			_DOut5_OFF();
		break;
	case 5:
		if (pVal > 0)
			_DOut6_ON();
		else
			_DOut6_OFF();
		break;
	case 6:
		if (pVal > 0)
			_DOut7_ON();
		else
			_DOut7_OFF();
		break;
	case 7:
		if (pVal > 0)
			_DOut8_ON();
		else
			_DOut8_OFF();
		break;
	default:
		break;
	}
}

void DigitalOutSetPin(DIGITAL_OUT_DATA_t *pDat, uint8_t pPinNo, uint8_t pHiLow)
{
	pDat->mDOut[pPinNo - 1] = pHiLow;
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
		_DigitOutProcessPin(i, val);
	}
}

