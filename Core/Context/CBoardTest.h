/*
 * CBoardTest.h
 *
 *  Created on: Jan 5, 2023
 *      Author: Aditya
 */

#ifndef CONTEXT_CBOARDTEST_H_
#define CONTEXT_CBOARDTEST_H_

#include "ConHeader.h"

void TestLed1()
{
	uint32_t i;

	_LED_SetAllOff();

	while (1)
	{
		for (i = 0; i < LED_COUNT; ++i)
		{
			gContextLedData.mLedData.mLedState[i] = LED_STATE_ON;
		}

		LedProcess(&gContextLedData.mLedData);

		HAL_Delay(500);
		for (i = 0; i < LED_COUNT; ++i)
		{
			gContextLedData.mLedData.mLedState[i] = LED_STATE_OFF;
		}
		LedProcess(&gContextLedData.mLedData);
		HAL_Delay(500);
	}
}

void TestSwitches()
{

}

void TestModbus()
{

}

void TestTimer()
{

}

void TestDigitalOut()
{

}

void TestDigitalInput()
{

}

void TestPwm()
{

}

void TestFlash()
{

}

#endif /* CONTEXT_CBOARDTEST_H_ */
