
#include "DigitalOutputPort.h"

//extern uint32_t timeOn[];
//extern uint32_t timeStart[];
//extern uint8_t bTime[];

static GPIO_t DiscreteOutput[NUM_DISC_OUTPUTS] =
{
// DIGITAL OUT 8 PINS
		{ .port = DOut1_GPIO_Port, .pin = DOut1_Pin },
		{ .port = DOut2_GPIO_Port, .pin = DOut2_Pin },
		{ .port = DOut3_GPIO_Port, .pin = DOut3_Pin },
		{ .port = DOut4_GPIO_Port, .pin = DOut4_Pin },

		{ .port = DOut5_GPIO_Port, .pin = DOut5_Pin },
		{ .port = DOut6_GPIO_Port, .pin = DOut6_Pin },
		{ .port = DOut7_GPIO_Port, .pin = DOut7_Pin },
		{ .port = DOut8_GPIO_Port, .pin = DOut8_Pin }
};

static GPIO_t* _GetOutputPtr(int pIdx)
{
	GPIO_t *pOutput = NULL;
	if (pIdx < NUM_DISC_OUTPUTS)
	{
		pOutput = &DiscreteOutput[pIdx];
	}
	return pOutput;
}

void _DigitalOutSetPin(uint8_t pVal, uint8_t pIdx)
{
	GPIO_PinState bitaction;
	if (pIdx < NUM_DISC_OUTPUTS)
	{
		bitaction = (pVal == 0) ? GPIO_PIN_RESET : GPIO_PIN_SET;

		GPIO_t *pOutput = _GetOutputPtr(pIdx);
		if (pOutput != NULL)
		{
			HAL_GPIO_WritePin(pOutput->port, pOutput->pin, bitaction);
		}
	}
}

void _DigitalOutSetAllOff()
{
	for (uint8_t i = 0; i < NUM_DISC_OUTPUTS; i++)
	{
		_DigitalOutSetPin(0, i);
	}
}

void _DigitalOutSetAllOn()
{
	for (uint8_t i = 0; i < NUM_DISC_OUTPUTS; i++)
	{
		_DigitalOutSetPin(1, i);
	}
}

//------------------------mulitple--------------------------------------
uint8_t _DigitOutRead(uint8_t pIdx)
{
	uint8_t val = 0;

	if (pIdx < NUM_DISC_OUTPUTS)
	{
		GPIO_t *pOutput = _GetOutputPtr(pIdx);
		val = HAL_GPIO_ReadPin(pOutput->port, pOutput->pin);
	}
	return val;
}
