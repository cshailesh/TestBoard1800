/*
 * CDeviceData.h
 *
 *  Created on: Nov 10, 2022
 *      Author: Aditya
 */

#ifndef CONTEXT_CDEVICEDATA_H_
#define CONTEXT_CDEVICEDATA_H_

#include "main.h"

typedef struct
{
	uint32_t mAdcVal[8];

} ANALOG_OUT_DATA_t;

typedef struct
{
	uint32_t mDigVal[8];
} DIGITAL_OUT_DATA_t;

//---------------------
// PWM DATA
//---------------------
#define PWM_CHANNEL_CNT	4
#define PWM_VAL_t	uint16_t
typedef struct
{
	PWM_VAL_t mPWMCurVal[8];
} PWM_OUT_DATA_t;

//---------------------
// LEDS DATA
//---------------------

#define LED_COUNT	3

typedef enum
{
	LED_BLINK_SPEED_NONE = 50000,
	LED_BLINK_SPEED_SLOW = 1000,
	LED_BLINK_SPEED_MED = 500,
	LED_BLINK_SPEED_FAST = 100
} LED_BLINK_RATE;

typedef enum
{
	LED_STATE_ON = 1, LED_STATE_OFF, LED_STATE_BLINK,
} LED_STATE;

typedef struct
{
	LED_STATE mLedState[LED_COUNT];
	LED_BLINK_RATE mLedBlinkRate[LED_COUNT];
	uint32_t mLedBlinkCnt[LED_COUNT]; /// USED IN SYSTICKS

} LED_DATA_t;

typedef struct
{
	ANALOG_OUT_DATA_t mAnalogOutData;
	DIGITAL_OUT_DATA_t mDigOutData;
	PWM_OUT_DATA_t mPwmData;
	LED_DATA_t mLedData;

} CONTEXT_DATA_t;

#endif /* CONTEXT_CDEVICEDATA_H_ */
