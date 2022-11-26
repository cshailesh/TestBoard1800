///*
// * CModbusMaster.h
// *
// *  Created on: 20 SEPT 2022
// *  Author: LINK4
// */
//
//#ifndef CMODBUS_MASTER_H_
//#define CMODBUS_MASTER_H_
//
//#include <ConHeader.h>
//
//void ModbusWrite_Reg(ModbusBase_t *m_t,WriteReg_TypeDef reg_type,uint8_t slave_addr,uint16_t reg_addr,int16_t value);
//
//__weak void ModbusMaster_RXCallback(ModbusBase_t *m_t,uint8_t deviceAdress,ReadReg_TypeDef regType,int16_t *data_p,uint8_t size);
//
//void Modbu_Master_Read_Reg(ModbusBase_t *m_t,ReadReg_TypeDef reg_type,uint8_t slave_addr,uint16_t reg_addr,uint16_t size);
//
//void Master_Read_Input(ModbusBase_t *m_t);
//void Master_Read_Holding_Input(ModbusBase_t *m_t);
//void Master_Read_Coil_Discrete(ModbusBase_t *m_t);
//void modbusMASTER_RXHandler(ModbusBase_t *m_t);
//
//void writeMultiCoils(ModbusBase_t *m_t,uint16_t Bit_count,uint8_t RX_buffer_index,uint8_t Byte_count);
//void writeMultipleRegister(ModbusBase_t *m_t,uint8_t Wr_word_count,uint8_t Wr_data_index);
//
//void modbusWriteSingleHoldingRegister(ModbusBase_t *m_t);
//void modbusWriteMultipleHoldingRegister(ModbusBase_t *m_t);
//
//void modbusReadCoilStatus(ModbusBase_t *m_t);
//
//void modbusDiscrateStatus(ModbusBase_t *m_t);
//void setLimitValsTablePointer(ModbusBase_t *m_t,const MB_range_td *MB_limit_val_table);
//
//void coilsQuantityAndAddressSet(ModbusBase_t *m_t);
//
//uint8_t quantityAndAddressControl(ModbusBase_t *m_t);
//
//void coilBitAddressSet(ModbusBase_t *m_t);
//
//void modbusWriteMultipleCoil(ModbusBase_t *m_t);
//
//void modbusWriteSingleCoil(ModbusBase_t *m_t);
//
//
//void holdingQuantityAndAddressSet(ModbusBase_t *m_t);
//
//uint8_t singleAddressControl(ModbusBase_t *m_t,uint16_t Max_value);
//
//void discratesQuantityAndAddressSet(ModbusBase_t *m_t);
//
//void modbusReadHoldingRegisters(ModbusBase_t *m_t);
//
//void modbusReadRegisters(ModbusBase_t *m_t);
//
//void inputQuantityAndAddressSet(ModbusBase_t *m_t);
//
//void modbusReadInputRegisters(ModbusBase_t *m_t);
//
//#endif /* CLED_H */
