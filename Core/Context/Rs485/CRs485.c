/*
 * CRs485.h
 *
 *  Created on: 28-May-2023
 *      Author: admin
 */

#ifndef CONTEXT_RS485_CRS485_H_
#define CONTEXT_RS485_CRS485_H_
#include "ConHeader.h"

uint8_t gUartData[4];

void SendTestData()
{

	gUartData[0] = 'A';
	gUartData[1] = 'A';
	gUartData[2] = 'A';
	gUartData[3] = 'A';

	HAL_GPIO_WritePin(USART1_DE_GPIO_Port, USART1_DE_Pin, GPIO_PIN_SET);
	HAL_UART_Transmit(&huart1, gUartData, 4, 1000);
	HAL_GPIO_WritePin(USART1_DE_GPIO_Port, USART1_DE_Pin, GPIO_PIN_RESET);
}

#endif /* CONTEXT_RS485_CRS485_H_ */
