/*
 * CModbus.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef CONTEXT_MODBUSSLAVE_CMODBUSDATA_H_
#define CONTEXT_MODBUSSLAVE_CMODBUSDATA_H_

#include <ConHeader.h>

#define MAX_MB_BUFFER_SIZE 256
#define MB_REGISTER_COUNT 100

typedef enum  // International Rules
{
	NO_ERROR_e,
	Illegal_Function_e = 1,
	Illegal_Data_Address_e,
	Illegal_Data_Value_e,
	Slave_Device_Failure_e,
	Acknowledge_e,
	Slave_Device_Busy_e,
	Negative_Acknowledge_e,
	Memory_Parity_Error_e,
	Gateway_Path_Unavailable_e = 10,
	Gateway_Target_Device_Failed_to_Respond_e = 11
} eModbus_ERROR_CODES;

typedef enum
{
	MB_STATUS_CLEAR = 0x0,
	MB_RX_RUN = 0x01,
	MB_RX_FRAME_END = 0x02,
	MB_TX_RUN = 0x04,
	MB_BROADCASTS = 0x40,
	MB_WR_ENABLE = 0x80
} eMB_STATUS;

typedef enum
{
	MB_FUNCTION_ERROR = 0x01,
	MB_ADDRES_ERROR,
	MB_QUANTITY_ERROR,
	MB_FUNCTION_RUN_ERROR
} eMB_EXCEPTIONS;

typedef enum
{
	Modbus_Slave, Modbus_Master,
} eMODBUS_TYPE;

typedef struct
{
	uint8_t *mMBpointer;
	uint8_t mMB_index;
	uint8_t mMB_byte_count;
} MODBUS_BUFF_t;

typedef struct
{
	uint16_t mHoldingRegBase;
	uint16_t mInputRegBase;

	uint16_t mHoldingRegCnt;
	uint16_t mInputRegCnt;

	uint16_t mHolding[MB_REGISTER_COUNT];
	uint16_t mInput[MB_REGISTER_COUNT];

} MODBUS_REG_t;

typedef struct
{
	eMODBUS_TYPE mModbusType;
	uint8_t mHardwaveFlow;
	uint8_t mRX_Data;
	uint8_t mModbusBuffer[MAX_MB_BUFFER_SIZE]; //[MAX_VAR_NUMBER*2 + 8];   /*Al�nan/G�nderilen frame in kaydedildi�i buffer*/

	MODBUS_BUFF_t mMB_registers;

	eMB_STATUS mMB_status;

	uint8_t mFrame_start_timer;
	uint32_t mPhisical_address;
	uint16_t mMax_quantity;
	uint16_t mReceived_quantity;
	uint8_t mTime1_5, mTime3_5, mCRCLo, mCRCHi;

	//const MB_range_td *mPtrLimit_vals_table;
	MODBUS_REG_t mRegisters;

	uint8_t mBit_mask, mBit_wr_mask;
	uint16_t mMB_valid_address;
	uint8_t mLimit_counter;
	uint8_t mMasterDeviceAddres;
	uint8_t mMasterReqDataAddres;
	uint8_t mHolding_Register_Change_Flag;
	uint8_t mHolding_Register_Change_Control_Flag;

	UART_HandleTypeDef *mHuart;
	GPIO_TypeDef *mGPIOx;
	uint16_t mGPIO_Pin;
} MODBUS_DATA_t;

typedef enum
{
	Read_Coil_e = 0x01,
	Read_Discrete_e = 0x02,
	Read_Holding_e = 0x03,
	Read_Input_e = 0x04,
	Write_Coil_e = 0x05,
	Write_Holding_e = 0x06,
	Write_Multi_Holding_e = 0x06,
} eMB_Operations;

#define MbTypecastAddress uint32_t /* 32 bit adreslemeli i�lemci i�in */
/*Minimum bytes required for Modbus RX data to be valid
 1 Byte device address
 + 1 byte function code
 + 2 Byte CRC
 ------------------------------------------------------------------------------*/
#define MIN_RX_BYTE_NUMBER 4
/*----------------------------------------------------------------------------*/
#define MOD_LITTLE_ENDIAN  1234
/*--------------------------MASTER DEFINATIONS------------------------------*/

#define MASTER_READ_DEVICE_ADRESS_INDEX       0x0
#define MASTER_READ_FUNC_INDEX                0x1
#define MASTER_RX_DATA_COUNT_INDEX            0x2
#define MASTER_READ_COIL_DATA_ADRES_0         0x3
#define MASTER_READ_DISCRETE_DATA_ADRES_0     0x3
#define MASTER_READ_INPUT_DATA_ADRES_0        0x3
#define MASTER_READ_HOLDING_DATA_ADRES_0      0x3

#define MASTER_CRC_HARICI_H_I_SABIT_BYTE_SAYISI     0x3  // Holding ve �nput Register icin
#define MASTER_CRC_HARICI_C_D_BYTE_SAYISI     0x4  // Coil ve Discrete Register icin

#define HARDWARE_FLOW_CONTROL_ON  1
#define HARDWARE_FLOW_CONTROL_OFF 0

/*-- MODBUS BIT ACCESS FUNCTION CODES ----------------------------------------*/
#define MODBUS_FUNC_READ_COIL_STATUS			0x01
#define MODBUS_FUNC_READ_INPUT_STATUS			0x02
#define MODBUS_FUNC_WRITE_SINGLE_COIL			0x05
#define MODBUS_FUNC_WRITE_MULTIPLE_COILS		0x0F
/*-- MODBUS 16 BITS ACCESS FUNCTION CODES ------------------------------------*/
#define MODBUS_FUNC_READ_HOLDING_REGISTERS		0x03
#define MODBUS_FUNC_READ_INPUT_REGISTERS		0x04
#define MODBUS_FUNC_WRITE_SINGLE_REGISTER		0x06
#define MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS	0x10

#define RXBF_DADDR_INDEX 0
#define RXBF_FUCT_INDEX  1
#define RXBF_ADDR_INDEX  2
#define RXBF_QUAN_INDEX  4
#define RXBF_SCVAL_INDEX  4
#define RXBF_BYTECOUNT_INDEX  6

//
//typedef struct
//{
//	uint8_t Sorgu_Adresi;
//	uint16_t Sorgu_Reg_Adresi;
//	ReadReg_TypeDef Sorgu_Tipi;
//	int16_t Sorgu_Data;
//	uint8_t Hata_Durumu;
//	uint8_t Hata_Sayaci;
//} Modbus_Master_Sorgu_Pkt;

#endif /* CONTEXT_MODBUSSLAVE_CMODBUSDATA_H_ */
