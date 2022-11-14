#ifndef CONTEXT_CDEVICEDATATYPES_H_
#define CONTEXT_CDEVICEDATATYPES_H_

#include "main.h"
#include "CModBusData.h"

typedef struct
{
	uint32_t mAdcVal[8];

} ANALOG_OUT_DATA_t;

//---------------------
// DIGITAL DATA
//---------------------

typedef struct
{
	uint8_t mDOut[8];
} DIGITAL_OUT_DATA_t;

//---------------------
// PWM DATA
//---------------------

#define PWM_CHANNEL_CNT	4
#define PWM_VAL_t	uint16_t
typedef struct
{
	PWM_VAL_t mPercent[PWM_CHANNEL_CNT];
	PWM_VAL_t mTIMCompare[PWM_CHANNEL_CNT];
	uint8_t mDirty[PWM_CHANNEL_CNT];

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
} eLED_BLINK_RATE;

typedef enum
{
	LED_STATE_ON = 1, LED_STATE_OFF, LED_STATE_BLINK,
} eLED_STATE;

typedef struct
{
	eLED_STATE mLedState[LED_COUNT];
	eLED_BLINK_RATE mLedBlinkRate[LED_COUNT];
	uint32_t mLedBlinkCnt[LED_COUNT];
} LED_DATA_t;

//---------------------
// GPIO DATA
//---------------------

typedef struct
{
	ANALOG_OUT_DATA_t mAnalogOutData;
	DIGITAL_OUT_DATA_t mDigOutData;
	PWM_OUT_DATA_t mPwmData;
	LED_DATA_t mLedData;

	MODBUS_SLAVE_DATA_t mModbusSlave1;
	MODBUS_SLAVE_DATA_t mModbusSlave2;

} CONTEXT_DATA_t;

#endif /* CONTEXT_CDEVICEDATATYPES_H_ */
