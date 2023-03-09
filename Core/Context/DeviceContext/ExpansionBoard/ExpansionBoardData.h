#ifndef EXPANSION_BOARD_DATA_H_
#define EXPANSION_BOARD_DATA_H_

#include "main.h"

#define EXPANSION_BOARDS_MAX_INPUT  8
#define EXPANSION_BOARDS_MAX_OUTPUT 8
#define EXPANSION_BOARDS_MAX		8

typedef struct Ex_Board_Input_Data
{
	uint8_t mType;
	uint16_t mIntData;
	float mFloatData;
	uint8_t mName[16];
} Ex_Board_Input_Data_t;

typedef struct Ex_Board_Output_Data
{
	uint8_t mType;
	uint16_t mIntData;
	float mFloatData;
	uint8_t mName[16];
} Ex_Board_Output_Data_t;

typedef struct Ex_Board
{
	uint8_t mBoardID[8];
	uint8_t mBoardName[16];
	uint8_t mAutoAddressUID[8];
	uint8_t mModbusAddress;

	uint8_t mOutputCount;
	uint8_t mInputCount;

	Ex_Board_Input_Data_t mInputs[EXPANSION_BOARDS_MAX_INPUT];
	Ex_Board_Output_Data_t mOutputs[EXPANSION_BOARDS_MAX_OUTPUT];

	USART_TypeDef *mUartHandle;

	uint8_t mIsActive;
} Ex_Board_t;

typedef struct Ex_Expansion_Board_Data
{
	Ex_Board_t mExpansions[EXPANSION_BOARDS_MAX];

} Ex_Expansion_Board_Data_t;

#endif
