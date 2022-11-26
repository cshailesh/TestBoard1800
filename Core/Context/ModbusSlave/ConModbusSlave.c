/*
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#include "ConModbusSlave.h"

void ModBusSlave1Init(MODBUS_DATA_t *pDat)
{
}

void ModBusSlave2Init(MODBUS_DATA_t *pDat)
{
}

void ModBusSlave1Process(MODBUS_DATA_t *pDat)
{
}
;
void ModBusSlave2Process(MODBUS_DATA_t *pDat)
{
}
;

// Start Developments

void modbusInit(MODBUS_DATA_t *pMb_t, UART_HandleTypeDef *huart,
		GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, eMB_BAUD_RATE br,
		uint8_t hardwave_control, eMODBUS_TYPE pModbusType)
{
	pMb_t->mHuart = huart;
	pMb_t->mModbusType = pModbusType;
	if (!hardwave_control)
	{
		pMb_t->mGPIOx = GPIOx;
		pMb_t->mGPIO_Pin = GPIO_Pin;
	}
	pMb_t->mHardwaveFlow = hardwave_control;
	pMb_t->mMB_registers.mMBpointer = pMb_t->mModbusBuffer;
	pMb_t->mMB_registers.mMB_index = 0;
	pMb_t->mMB_registers.mMB_byte_count = 1;
	pMb_t->mFrame_start_timer = 0xff;
	pMb_t->mMB_status = MB_STATUS_CLEAR;
	baudRateSet(pMb_t, br);
	Modbus_ReceiveInterrupt(pMb_t);
}


void modbusSLAVE_RXHandler(MODBUS_DATA_t *pMb)
{
	/*If the broadcast is incoming, the read functions will not work.*/
	if (pMb->mMB_status & MB_BROADCASTS)
	{
		switch (pMb->mModbusBuffer[RXBF_FUCT_INDEX])
		{

		case MODBUS_FUNC_WRITE_SINGLE_COIL:
			//modbusWriteSingleCoil(pMb);
			break;
		case MODBUS_FUNC_WRITE_MULTIPLE_COILS:
			//modbusWriteMultipleCoil(pMb);
			break;
		case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
			//modbusWriteSingleHoldingRegister(pMb);
			break;
		case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
			//modbusWriteMultipleHoldingRegister(pMb);
			break;
		default:
			sendExceptionCode(pMb, MB_FUNCTION_ERROR);
			return;
		}
	}

	switch (pMb->mModbusBuffer[RXBF_FUCT_INDEX])
	{
	case MODBUS_FUNC_READ_COIL_STATUS:
		//modbusReadCoilStatus(pMb);
		break;
	case MODBUS_FUNC_READ_INPUT_STATUS:
		//modbusDiscrateStatus(pMb);
		break;
	case MODBUS_FUNC_READ_HOLDING_REGISTERS:
		modbusReadHoldingRegisters(pMb);
		break;
	case MODBUS_FUNC_READ_INPUT_REGISTERS:
		ModbusReadInputRegisters(pMb);
		break;
	case MODBUS_FUNC_WRITE_SINGLE_COIL:
		modbusWriteSingleCoil(pMb);
		break;
	case MODBUS_FUNC_WRITE_MULTIPLE_COILS:
		modbusWriteMultipleCoil(pMb);
		break;
	case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
		modbusWriteSingleHoldingRegister(pMb);
		break;
	case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
		modbusWriteMultipleHoldingRegister(pMb);
		break;
	default:
		sendExceptionCode(pMb, MB_FUNCTION_ERROR);
	}
}

void bitStatusTransmit(MODBUS_DATA_t *pMb)
{
	uint8_t Byte_count, index;
	//coilBitAddressSet(pMb);
	Byte_count = pMb->mReceived_quantity / 8;
	if (pMb->mReceived_quantity % 8)
		Byte_count++;
	pMb->mModbusBuffer[2] = Byte_count;
	index = 3;
	pMb->mModbusBuffer[index] = 0;
	uint8_t *pBuffer = (uint8_t*) pMb->mPhisical_address;
	while (pMb->mReceived_quantity)
	{
		if (pBuffer[pMb->mMB_valid_address] & pMb->mBit_mask)
		{
			pMb->mModbusBuffer[index] |= pMb->mBit_wr_mask;
		}
		if (!(pMb->mBit_wr_mask <<= 1))
		{
			pMb->mBit_wr_mask = 1;
			index++;
			pMb->mModbusBuffer[index] = 0;
		}
		if (!(pMb->mBit_mask <<= 1))
		{
			pMb->mBit_mask = 1;
			(pMb->mMB_valid_address)++;
		}
		pMb->mReceived_quantity--;
	}
	sendResponse(pMb, Byte_count + 3);
}

void MB_Set_HoldingChangeControl_flag(MODBUS_DATA_t *pMb)
{
	pMb->mHolding_Register_Change_Control_Flag = 1;
}

void ModbusReadInputRegisters(MODBUS_DATA_t *m_t)
{
	//inputQuantityAndAddressSet(m_t);
	ModbusReadRegisters(m_t);
}

void ModbusReadRegisters(MODBUS_DATA_t *m_t)
{
	uint8_t TX_buffer_index = 3; /* Cevap ba�lang�� indexi */
	uint8_t *pBuffer = (uint8_t*) m_t->mPhisical_address;
	uint8_t Word_count;
	uint8_t Exception = 0; //  quantityAndAddressControl(m_t);
	uint16_t Holding_index = m_t->mMB_valid_address * 2;
	if (Exception)
	{
		sendExceptionCode(m_t, Exception);
		return;
	}
	Word_count = m_t->mReceived_quantity;
	m_t->mModbusBuffer[2] = Word_count * 2; /* ModbusBuffer[2] = Byte say�s� */
	while (Word_count--)
	{
#ifdef BIG_ENDIAN
		/* Big Endian ise ------------------------------------------------------------*/
		m_t->mModbusBuffer[TX_buffer_index] = pBuffer[Holding_index];
		TX_buffer_index++;
		Holding_index++;
		m_t->mModbusBuffer[TX_buffer_index] = pBuffer[Holding_index];
		TX_buffer_index++;
		Holding_index++;
#else
		/* Little Endian ise ------------------------------------------------------------*/

		m_t->ModbusBuffer[TX_buffer_index + 1] = pBuffer[Holding_index];
		Holding_index++;
		m_t->ModbusBuffer[TX_buffer_index] = pBuffer[Holding_index];
		TX_buffer_index += 2;
		Holding_index++;
#if !defined BIG_ENDIAN && !defined LITTLE_ENDIAN
#error "sys_config.h dosyas�nda LITTEL_ENDIAN veya BIG_ENDIAN se�imi yap�lmad� "
#endif
#endif /* BIG_ENDIAN */
	}
	sendResponse(m_t, TX_buffer_index);
}
void modbusReadHoldingRegisters(MODBUS_DATA_t *m_t)
{
	//holdingQuantityAndAddressSet(m_t);
	ModbusReadRegisters(m_t);
}

/*-- WRITE MULTIPLE REGISTER ALT FONKS�YONU ----------------------------------*/
void writeMultipleRegister(MODBUS_DATA_t *pMb, uint8_t Wr_word_count,
		uint8_t Wr_data_index)
{
	uint8_t *pBuffer = (uint8_t*) pMb->mPhisical_address;
	uint16_t Holding_index = pMb->mMB_valid_address * 2;
	while (Wr_word_count--)
	{
#ifdef BIG_ENDIAN
		/* Big Endian ise ------------------------------------------------------------*/
		pBuffer[Holding_index] = pMb->mModbusBuffer[Wr_data_index];
		Wr_data_index++;
		Holding_index++;
		pBuffer[Holding_index] = pMb->mModbusBuffer[Wr_data_index];
		Wr_data_index++;
		Holding_index++;
#else
		/* Little Endian ise ------------------------------------------------------------*/
		int16_t temp = 0;
		((uint8_t*) &temp)[0] = pMb->mModbusBuffer[Wr_data_index + 1];
		((uint8_t*) &temp)[1] = pMb->mModbusBuffer[Wr_data_index];
		pMb->mlimit_counter = (uint8_t) (Holding_index / 2);

		if (temp <= Holding_Limit[pMb->mlimit_counter].up_limit
				&& temp >= Holding_Limit[pMb->mlimit_counter].down_limit)
		{
			pBuffer[Holding_index + 1] = pMb->mModbusBuffer[Wr_data_index];
			Wr_data_index++;
			pBuffer[Holding_index] = pMb->mModbusBuffer[Wr_data_index];
			Holding_index += 2;
			Wr_data_index++;
			pMb->mHolding_Register_Change_Flag = 1;
			MB_Set_HoldingChangeControl_flag(pMb);

		}
		else
		{
			Wr_data_index += 2;
			Holding_index += 2;
		}
#endif
	}
}

void modbusWriteMultipleHoldingRegister(MODBUS_DATA_t *pMb)
{
	holdingQuantityAndAddressSet(pMb);
	uint8_t Exception;
	Exception = quantityAndAddressControl(pMb);
	if (Exception)
	{
		sendExceptionCode(pMb, Exception);
		return;
	}
	writeMultipleRegister(pMb, pMb->mReceived_quantity, 7);
	sendResponse(pMb, 6); /* RX bufferdeki 6 byte geri yollan�yor */
}

void modbusWriteSingleHoldingRegister(MODBUS_DATA_t *pMb)
{
	holdingQuantityAndAddressSet(pMb);
	uint8_t Exception;
	Exception = singleAddressControl(pMb, 0xffff);
	if (Exception)
	{
		sendExceptionCode(pMb, Exception);
		return;
	}
	writeMultipleRegister(pMb, 1, 4); /*Modbus Buffer[4] deki 1 word datat� holdinge yaz*/
	sendResponse(pMb, 6); /* RX bufferdeki 6 byte geri yollan�yor */
}

/*-- WRITE MULTI COILS FONKS�YONU (FONKSIYON KODU 0x0F) ----------------------*/
void modbusWriteMultipleCoil(MODBUS_DATA_t *pMb)
{
	coilsQuantityAndAddressSet(pMb);
	uint8_t Exception = quantityAndAddressControl(pMb);
	if (Exception)
	{
		sendExceptionCode(pMb, Exception);
		return;
	}
	coilBitAddressSet(pMb);
	writeMultiCoils(pMb, pMb->mReceived_quantity, 7,
			pMb->mModbusBuffer[RXBF_BYTECOUNT_INDEX]);
	sendResponse(pMb, 6);
}
void writeMultiCoils(MODBUS_DATA_t *pMb, uint16_t Bit_count,
		uint8_t RX_buffer_index, uint8_t Byte_count)
{
//	uint8_t *pBuffer = (uint8_t*) (pMb->mPhisical_address);
//	while (Bit_count)
//	{
//		if (pMb->mModbusBuffer[RX_buffer_index] & pMb->mBit_wr_mask)
//		{
//			pBuffer[pMb->mMB_valid_address] |= pMb->mBit_mask;
//		}
//		else
//		{
//			pBuffer[pMb->mMB_valid_address] &= ~(pMb->mBit_mask);
//		}
//		if (!(pMb->mBit_mask <<= 1))
//		{
//			pMb->mBit_mask = 1;
//			(pMb->mMB_valid_address)++;
//		}
//		if (!(pMb->mBit_wr_mask <<= 1))
//		{
//			pMb->mBit_wr_mask = 1;
//			RX_buffer_index++;
//			if (--Byte_count == 0)
//				return;
//		}
//		Bit_count--;
//	}
}

void modbusWriteSingleCoil(MODBUS_DATA_t *pMb)
{
//	coilsQuantityAndAddressSet(pMb);
//#ifdef BIG_ENDIAN
//	/* Big Endian ise ------------------------------------------------------------*/
//	((int8_t*) &pMb->mReceived_quantity)[0] =
//			pMb->mModbusBuffer[RXBF_SCVAL_INDEX]; /* Coil value MSB byte */
//	((int8_t*) &pMb->mReceived_quantity)[1] = pMb->mModbusBuffer[RXBF_SCVAL_INDEX
//			+ 1]; /* Coil value LSB byte */
//#else
//	/* Little Endian ise ------------------------------------------------------------*/
//
//	((int8_t*) &pMb->mReceived_quantity)[1] =
//			pMb->mModbusBuffer[RXBF_SCVAL_INDEX]; /* Coil value MSB byte */
//	((int8_t*) &pMb->mReceived_quantity)[0] = pMb->mModbusBuffer[RXBF_SCVAL_INDEX
//			+ 1]; /* Coil value LSB byte */
//#if !defined BIG_ENDIAN && !defined LITTLE_ENDIAN
//#error "sys_config.h dosyas�nda LITTEL_ENDIAN veya BIG_ENDIAN se�imi yap�lmad� "
//#endif
//#endif /* BIG_ENDIAN */
//	if (!(pMb->mReceived_quantity == 0xFF00 || pMb->mReceived_quantity == 0x0000))
//	{
//		sendExceptionCode(pMb, MB_QUANTITY_ERROR);
//		return;
//	}
//	if (pMb->mMB_valid_address >= pMb->mMax_quantity)
//	{
//		sendExceptionCode(pMb, MB_ADDRES_ERROR);
//		return;
//	}
//	coilBitAddressSet(pMb);
//	writeMultiCoils(pMb, 1, 4, 1);
//	sendResponse(pMb, 6);
}

//void ModbusWrite_Reg(MODBUS_DATA_t *pMb, WriteReg_TypeDef reg_type,
//		uint8_t slave_addr, uint16_t reg_addr, int16_t value)
//{
////	pMb->mmasterReqDataAddres = reg_addr;
////
////	pMb->mMasterDeviceAddres = slave_addr;
////	pMb->mModbusBuffer[0] = slave_addr;                   // Device Adres
////	pMb->mModbusBuffer[1] = (uint8_t) reg_type;             // Register Type
////	pMb->mModbusBuffer[2] = reg_addr >> 8;                  // MSB Register Adr
////	pMb->mModbusBuffer[3] = (uint8_t) reg_addr;            // LSB Register Adr
////	pMb->mModbusBuffer[4] = (value >> 8) & 0xFF;             // MSB Byte Count
////	pMb->mModbusBuffer[5] = value & 0xFF;     //gerekesiz       // LSB Byte Count
////
////	sendResponse(pMb, 6);
//
//}

#define MODBUS_REG_DOUT1		11
#define MODBUS_REG_DOUT2		12
#define MODBUS_REG_DOUT3		13
#define MODBUS_REG_DOUT4		14
#define MODBUS_REG_DOUT5		15
#define MODBUS_REG_DOUT6		16
#define MODBUS_REG_DOUT7		17
#define MODBUS_REG_DOUT8		18

#define MODBUS_REG_PWM			21
#define MODBUS_REG_PWM			22
#define MODBUS_REG_PWM			23
#define MODBUS_REG_PWM			24

#define MODBUS_REG_LED_STATUS1	31
#define MODBUS_REG_LED_STATUS1	32
#define MODBUS_REG_LED_STATUS1	33



void OnRegChange(MODBUS_DATA_t *m_t)
{

}
