#include "ConMain.h"

void ContextInit()
{
	gPtrCD = &gContextLedData;
	gPtrPwmOutData = &gContextLedData.mPwmData;
	gPtrDigitalOutData = &gContextLedData.mDigOutData;
	gPtrLedData = &gContextLedData.mLedData;

	PwmDataInit(gPtrPwmOutData);
	LedDataInit(gPtrLedData);
	DigitOutInit(gPtrDigitalOutData);
	KeyboardInit();

//	HAL_Delay(200);

	L4FLASH_Init();
	InitUID();
	InitAddress();
	InitRNG(GetUIDStr());

    eMBDisable();
    ( void ) eMBInit( MB_RTU, AddressGet(), 0, 19200, MB_PAR_NONE );
    eMBEnable();

	//initialize failsafe timer
	UpdateFailsafeTimer();

	//FlashDataInit(gPtrLedData);

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

//	int lcnt = 1;

	PwmSetPercent(gPtrPwmOutData, 1, 10);
	PwmSetPercent(gPtrPwmOutData, 2, 20);
	PwmSetPercent(gPtrPwmOutData, 3, 30);
	PwmSetPercent(gPtrPwmOutData, 4, 40);
	ledSec = HAL_GetTick();

	LedStateChange(gPtrLedData, 1, LED_STATE_ON, 0);
	LedStateChange(gPtrLedData, 2, LED_STATE_OFF, 0);
	LedStateChange(gPtrLedData, 3, LED_STATE_BLINK, 200);

	LedStateChange(gPtrLedData, 1, LED_STATE_BLINK, 400);
	LedStateChange(gPtrLedData, 2, LED_STATE_BLINK, 400);
	LedStateChange(gPtrLedData, 3, LED_STATE_BLINK, 400);

	uint8_t uartData[4];

	uartData[0] = 'A';
	uartData[1] = 'A';
	uartData[2] = 'A';
	uartData[3] = 'A';

	uint32_t serTicks;

	serTicks = HAL_GetTick();
	while (1)
	{
		eMBPoll();

		//-----SET DIRTY------------------------------

		keypress = ReadKeyBoard();
		if (keypress != KEYBRD_NONE)
		{
			HAL_Delay(100);
			ProcessKeyboardPress(gPtrCD, keypress);
			keypress = KEYBRD_NONE;
		}

		if (HAL_GetTick() - serTicks > 500)
		{
			//	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
			HAL_GPIO_WritePin(USART1_DE_GPIO_Port, USART1_DE_Pin, GPIO_PIN_SET);
			HAL_UART_Transmit(&huart1, uartData, 4, 1000);
			HAL_GPIO_WritePin(USART1_DE_GPIO_Port, USART1_DE_Pin,GPIO_PIN_RESET);
			serTicks = HAL_GetTick();
		}
		//----------ALL THE PROCESSING ------------------------------------

		PwmProcess(gPtrPwmOutData);
		LedProcess(gPtrLedData);
		DigitalOutProcess(gPtrDigitalOutData);

		//ModBusSlave1Process(gPrtModSlaveData1);
		//ModBusSlave2Process(gPtrModSlaveData2);

	}
}
