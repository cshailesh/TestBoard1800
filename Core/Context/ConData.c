
#include <ConData.h>

void ContextDataInit(CONTEXT_DATA_t *pCD)
{
	PwmDataInit(gPtrPwmOutData);
	LedDataInit(gPtrLedData);
	DigitOutInit(gPtrDigitalOutData);
	KeyboardInit();

}

