#ifndef CCONTEXT_H_
#define CCONTEXT_H_

#include "ContextHeader.h"

void ContextInit()
{
	gPtrCD = &gContextLedData;
	gPwmOutData = &gContextLedData.mPwmData;
	gDigitalOutData = &gContextLedData.mDigOutData;
	gLedData = &gContextLedData.mLedData;

	gModSlaveData1 = &gContextLedData.mModbusSlave1;
	gModSlaveData2 = &gContextLedData.mModbusSlave2;

	ContextDataInit(gPtrCD);

	HAL_Delay(200);
}

void ContextMain()
{
	uint8_t keypress = 0;

	while (1)
	{
		keypress = ReadKeyBoard();
		if (keypress != KEYBRD_NONE)
		{
			HAL_Delay(100);
			ProcessKeyboardPress(gPtrCD, keypress);
			keypress = KEYBRD_NONE;
		}

		//
		// USART MODBUS PARSE HERE // SET DIRTY

		PwmProcess(gPwmOutData);
		LedProcess(gLedData);
		DigitalOutProcess(gDigitalOutData);

		ModBusSlave1Process(gModSlaveData1);
		ModBusSlave2Process(gModSlaveData2);


	}
}

#endif
