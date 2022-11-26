#include "ConMain.h"

void ContextInit()
{
	gPtrCD = &gContextLedData;
	gPtrPwmOutData = &gContextLedData.mPwmData;
	gPtrDigitalOutData = &gContextLedData.mDigOutData;
	gPtrLedData = &gContextLedData.mLedData;

	gPrtModSlaveData1 = &gContextLedData.mModbusSlave1;
	gPtrModSlaveData2 = &gContextLedData.mModbusSlave2;

	ContextDataInit(gPtrCD);

	HAL_Delay(200);
}

void ContextSystick(CONTEXT_DATA_t *pDat)
{
	for (int i = 0; i < LED_COUNT; ++i)
	{
		if (pDat->mLedData.mLedState[i] == LED_STATE_BLINK)
		{
			pDat->mLedData.mLedBlinkCnt[i] += 1;
		}
	}
}

void ContextMain()
{
	uint8_t keypress = 0;

	uint32_t ledSec;

	int lcnt = 1;

	PwmSetPercent(gPtrPwmOutData, 1, 10);
	PwmSetPercent(gPtrPwmOutData, 2, 30);
	PwmSetPercent(gPtrPwmOutData, 3, 50);
	PwmSetPercent(gPtrPwmOutData, 4, 80);
	ledSec = HAL_GetTick();

	while (1)
	{

		//-----SET DIRTY------------------------------

		keypress = ReadKeyBoard();
		if (keypress != KEYBRD_NONE)
		{
			HAL_Delay(100);
			ProcessKeyboardPress(gPtrCD, keypress);
			keypress = KEYBRD_NONE;
		}

		if (HAL_GetTick() - ledSec > 1000)
		{

			LedStateChange(gPtrLedData, lcnt, LED_STATE_ON, 0);
			lcnt++;
			if (lcnt > LED_COUNT - 1)
			{
				lcnt = 1;
				asm("NOP");
			}
			ledSec = HAL_GetTick();
		}

		//----------ALL THE PROCESSING ------------------------------------

		PwmProcess(gPtrPwmOutData);
		LedProcess(gPtrLedData);
		DigitalOutProcess(gPtrDigitalOutData);

		ModBusSlave1Process(gPrtModSlaveData1);
		ModBusSlave2Process(gPtrModSlaveData2);
	}
}
