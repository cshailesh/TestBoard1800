/*
 * CModbusMaster.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef CONMODBUS_SLAVE_H_
#define CONMODBUS_SLAVE_H_

#include <ConHeader.h>

void ModBusSlave1Init(MODBUS_DATA_t *pDat);
void ModBusSlave2Init(MODBUS_DATA_t *pDat);

void ModBusSlave1Process(MODBUS_DATA_t *pDat);
void ModBusSlave2Process(MODBUS_DATA_t *pDat);

void modbusInit(MODBUS_DATA_t *pMb, UART_HandleTypeDef *huart,
		GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, eMB_BAUD_RATE br,
		uint8_t hardwave_control, eMODBUS_TYPE pModbusType);
void sendExceptionCode(MODBUS_DATA_t *pMb, uint8_t ExceptionCode);
void sendResponse(MODBUS_DATA_t *pMb, uint8_t RXTX_byte_number);
void ReadExceptionCode();

uint8_t uartTXHandler(MODBUS_DATA_t *pMb);
uint8_t uartRXHandler(MODBUS_DATA_t *pMb);
void Modbus_ReceiveInterrupt(MODBUS_DATA_t *pMb);
void modbusSLAVE_RXHandler(MODBUS_DATA_t *pMb);

void MB_Set_HoldingChangeControl_flag(MODBUS_DATA_t *pMb);
void bitStatusTransmit(MODBUS_DATA_t *pMb);

void modbusReadHoldingRegisters(MODBUS_DATA_t *m_t);
void ModbusReadRegisters(MODBUS_DATA_t *m_t);
void ModbusReadInputRegisters(MODBUS_DATA_t *m_t);

void OnRegChange(MODBUS_DATA_t *m_t);


#endif /* CLED_H */
