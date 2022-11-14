/*
 * ConLed.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef CONLED_H_
#define CONLED_H_

#include <ConHeader.h>

void LedStateChange(LED_DATA_t *pDat, uint8_t pLedNo, eLED_STATE pState,
		eLED_BLINK_RATE pRate);

void LedDataInit(LED_DATA_t *pDat);
void LedProcess(LED_DATA_t *pDat);

#endif /* CONLED_H */
