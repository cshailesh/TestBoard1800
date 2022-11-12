/*
 * ContextData.h
 *
 *  Created on: Feb 10, 2022
 *      Author: ADITYA
 */

#include "ContextData.h"

void ContextDataInit(CONTEXT_DATA_t *pCD)
{
	PwmDataInit(gPwmOutData);
	LedDataInit(gLedData);
	DigitOutInit(gDigitalOutData);

}


