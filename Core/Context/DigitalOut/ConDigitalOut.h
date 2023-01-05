/*
 *  Created on: Feb 10, 2022
 *      Author: LINK4
 */

#ifndef CONTEXT_DIGITAL_OUT_H_
#define CONTEXT_DIGITAL_OUT_H_


#include <ConHeader.h>

//void _DigitOutProcessPin(uint8_t pNo, uint8_t pVal);

void DigitOutInit(DIGITAL_OUT_DATA_t *pDat);
void DigitalOutSetPin(DIGITAL_OUT_DATA_t *pDat, uint8_t pPinNo, uint8_t pHiLow);
void DigitalOutProcess(DIGITAL_OUT_DATA_t *pDat);
void DigitOutAllOn(DIGITAL_OUT_DATA_t *pDat);
void DigitOutAllOff(DIGITAL_OUT_DATA_t *pDat);

#endif /* CONTEXT_DIGITAL_OUT_H_ */
