/*
 * CModbus.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef CONTEXT_MODBUSSLAVE_CMODBUSDATA_H_
#define CONTEXT_MODBUSSLAVE_CMODBUSDATA_H_

#include "ContextHeader.h"

#define MODBUS_RX_DATA_BUFF_SIZE 256
#define MODBUS_TX_DATA_BUFF_SIZE 256

typedef struct
{
	uint8_t RXBuff[MODBUS_RX_DATA_BUFF_SIZE];
	uint8_t TXBuff[MODBUS_RX_DATA_BUFF_SIZE];

} MODBUS_SLAVE_DATA_t;

#endif /* CONTEXT_MODBUSSLAVE_CMODBUSDATA_H_ */
