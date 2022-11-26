

#ifndef CONTEXT_CONDATA_H_
#define CONTEXT_CONDATA_H_

#include <ConHeader.h>

CONTEXT_DATA_t gContextLedData;
CONTEXT_DATA_t *gPtrCD;

DIGITAL_OUT_DATA_t *gPtrDigitalOutData;
PWM_OUT_DATA_t *gPtrPwmOutData;
LED_DATA_t *gPtrLedData;

MODBUS_DATA_t* gPrtModSlaveData1;
MODBUS_DATA_t* gPtrModSlaveData2;


void ContextDataInit(CONTEXT_DATA_t *pCD);

#endif /* CONTEXT_CONDATA_H_ */
