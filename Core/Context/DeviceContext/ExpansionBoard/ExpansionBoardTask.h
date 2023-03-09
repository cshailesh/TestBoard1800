/*
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef EXPANSION_BOARD_TASK_H_
#define EXPANSION_BOARD_TASK_H_

#include "ExpansionBoardPort.h"
#include "ExpansionBoardData.h"

Ex_Board_t gBoard;
Ex_Board_t *gpBoard;

void Ex_Board_Init()
{
	gpBoard = &gBoard;
	gpBoard->mUartHandle = EX_BOARD_UART_HANDLE;
}

void Task_Ex_Board();

#endif /* CONTEXT_CONKEYBRD_H_ */
