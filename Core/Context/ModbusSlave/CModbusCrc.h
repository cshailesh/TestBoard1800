/*
 * CModbusCrc.h
 *
 *  Created on: Nov 19, 2022
 *      Author: Aditya
 */

#ifndef CONTEXT_MODBUSSLAVE_CMODBUSCRC_H_
#define CONTEXT_MODBUSSLAVE_CMODBUSCRC_H_

#include "ConHeader.h"
uint8_t CRC16Calculate(MODBUS_DATA_t *pMb_t, uint8_t Byte_number);

#endif /* CONTEXT_MODBUSSLAVE_CMODBUSCRC_H_ */
