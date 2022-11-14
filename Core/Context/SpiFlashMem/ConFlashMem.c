/*

 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#include "ConFlashMem.h"

void FlashProcess(LED_DATA_t *pDat)
{
}

void FlashDataInit(LED_DATA_t *pDat)
{
	W25qxx_Init();
}

void TaskFlash()
{

//	LED_DATA_t *ptrLedData = &gContextLedData.mLedData;
//	LedDataInit(ptrLedData);
//
//	while (1)
//	{
//		LedProcess(ptrLedData);
//	}
}
