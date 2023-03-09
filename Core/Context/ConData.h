

#ifndef CONTEXT_CONDATA_H_
#define CONTEXT_CONDATA_H_

#include <ConHeader.h>

extern CONTEXT_DATA_t gContextLedData;
extern CONTEXT_DATA_t *gPtrCD;

extern DIGITAL_OUT_DATA_t *gPtrDigitalOutData;
extern PWM_OUT_DATA_t *gPtrPwmOutData;
extern LED_DATA_t *gPtrLedData;


void ContextDataInit(CONTEXT_DATA_t *pCD);

#endif /* CONTEXT_CONDATA_H_ */
