/*
 * ContextData.h
 *
 *  Created on: Feb 10, 2022
 *      Author: ADITYA
 */

#ifndef CONTEXT_CONTEXTDATA_H_
#define CONTEXT_CONTEXTDATA_H_

#include "ContextHeader.h"

CONTEXT_DATA_t gContextLedData;
CONTEXT_DATA_t *gPtrCD;

DIGITAL_OUT_DATA_t *gDigitalOutData;
PWM_OUT_DATA_t *gPwmOutData;
LED_DATA_t *gLedData;

MODBUS_SLAVE_DATA_t* gModSlaveData1;
MODBUS_SLAVE_DATA_t* gModSlaveData2;


void ContextDataInit(CONTEXT_DATA_t *pCD);

#endif /* CONTEXT_CONTEXTDATA_H_ */
