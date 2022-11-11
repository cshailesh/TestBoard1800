#ifndef CCONTEXT_H_
#define CCONTEXT_H_

#include "ContextHeader.h"

extern SPI_HandleTypeDef hspi1;

void ContextInit()
{
	gPtrCD = &gContextLedData;
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
	}
}

#endif
