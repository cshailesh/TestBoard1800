/*
 * CPWM.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#include "CPwm.h"

uint16_t _PwnCalcPuse(uint8_t pPer)
{
	uint16_t res;
	res = (PWM_VAL_MAX * pPer) / 100;
	return res;
}


uint8_t _PwmValIsInLimit(uint8_t pVal)
{
	if (pVal >= PWM_VAL_MIN && pVal <= PWM_VAL_MAX)
		return 1;
	else
		return 0;
}

// dont use externally -> PwmSetPercent()
void _PwmSetChannel(uint8_t pChNo, uint16_t pPwmVal)
{
	switch (pChNo)
	{
	case 1:
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, pPwmVal);
		break;
	case 2:
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, pPwmVal);
		break;
	case 3:
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pPwmVal);
		break;
	case 4:
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, pPwmVal);
		break;
	default:
		break;
	}
}

void PwmSetPercent(PWM_OUT_DATA_t *pData, uint8_t pChNo, uint8_t pPercent)
{

	if (pPercent > 100)
	{
		pPercent = 99;
	}

	uint16_t val = _PwnCalcPuse(pPercent);  // percent to pulse convert
	pData->mPercent[pChNo - 1] = pPercent; // record for set to pwm data struct
	pData->mTIMCompare[pChNo - 1] = val; // record for set to pwm data struct
	pData->mDirty[pChNo - 1] = 1; // indicate for main loop to update pwm changes
}


void PwmDataInit(PWM_OUT_DATA_t *pDat)
{
	for (int i = 0; i < PWM_CHANNEL_CNT; ++i)
	{
		pDat->mPercent[i] = 0;
		pDat->mTIMCompare[i] = 10;
		pDat->mDirty[i] = 1;
	}

	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_Base_Start(&htim3);

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);

}

void PwmProcess(PWM_OUT_DATA_t *pDat)
{
	for (int i = 0; i < PWM_CHANNEL_CNT; ++i)
	{
		if (pDat->mDirty[i])
		{
			_PwmSetChannel(i + 1, pDat->mTIMCompare[i]); /// hardware Channel Pulse Set here
		}
	}
}

//void TaskPwm()
//{
//
//	while (1)
//	{
//		//PwmCheck()
//	}
//}
