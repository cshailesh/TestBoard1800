/*
 *  Created on: Feb 10, 2022
 *      Author: LINK4
 */
#include "ConDigitalOut.h"

void DigitalOutSetPin(DIGITAL_OUT_DATA_t *pDat, uint8_t pPinNo, uint8_t pHiLow)
{
	pDat->mDOut[pPinNo - 1] = pHiLow;
}

void DigitOutProcessPin(uint8_t pNo, uint8_t pVal)
{
	switch (pNo)
	{
	case 0:
		if (pVal > 0)
			DOut1_ON();
		else
			DOut1_OFF();
		break;
	case 1:
		if (pVal > 0)
			DOut2_ON();
		else
			DOut2_OFF();
		break;
	case 2:
		if (pVal > 0)
			DOut3_ON();
		else
			DOut3_OFF();
		break;
	case 3:
		if (pVal > 0)
			DOut4_ON();
		else
			DOut4_OFF();
		break;
	case 4:
		if (pVal > 0)
			DOut5_ON();
		else
			DOut5_OFF();
		break;
	case 5:
		if (pVal > 0)
			DOut6_ON();
		else
			DOut6_OFF();
		break;
	case 6:
		if (pVal > 0)
			DOut7_ON();
		else
			DOut7_OFF();
		break;
	case 7:
		if (pVal > 0)
			DOut8_ON();
		else
			DOut8_OFF();
		break;
	default:
		break;
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
		DigitOutProcessPin(i, val);
	}
}

