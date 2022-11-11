/*
 * CPWM.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#include "CPwm.h"

uint16_t PwmGetChannelVal(uint8_t pChNo)
{
	return 10;
}

uint8_t PwmValIsInLimit(uint8_t pVal)
{
	if (pVal >= PWM_VAL_MIN && pVal <= PWM_VAL_MAX)
		return 1;
	else
		return 0;
}

void SetPwmChannel(uint8_t pChNo, uint16_t pPwmVal)
{
	switch (pChNo)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}
}

void PwmCheck(PWM_OUT_DATA_t *pDat)
{
	for (int var = 0; var < PWM_CHANNEL_CNT; ++var)
	{

	}
}

void PwmDataInit(PWM_OUT_DATA_t *pDat)
{
	for (int i = 0; i < PWM_CHANNEL_CNT; ++i)
	{
		pDat->mPWMCurVal[i] = 0;
	}
}

void TaskPwm()
{

	while(1)
	{
		//PwmCheck()
	}
}
