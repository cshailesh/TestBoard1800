/*
 * CModbusMaster.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef CONMODBUS_SLAVE_H_
#define CONMODBUS_SLAVE_H_

#include <ConHeader.h>

void ModBusSlave1Init(MODBUS_SLAVE_DATA_t *pDat);
void ModBusSlave2Init(MODBUS_SLAVE_DATA_t *pDat);

void ModBusSlave1Process(MODBUS_SLAVE_DATA_t *pDat);
void ModBusSlave2Process(MODBUS_SLAVE_DATA_t *pDat);
#endif /* CLED_H */
