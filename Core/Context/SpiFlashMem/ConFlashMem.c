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
	W25qxx_EraseBlock(25);
	W25qxx_ReadBytes(255, 265, 1024);
	W25qxx_WritePage(255, 3, 0, 4);

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
