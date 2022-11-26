//#include <Modbus_Master_RTU.h>
//
///*------------------------- MODBUS CRC16 -----------------------------*/
//const uint8_t Crc_high_table[] =
//{ 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01,
//		0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01,
//		0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00,
//		0xC1, 0x81, 0x40 };
//const uint8_t Crc_low_table[] =
//{ 0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7, 0x05,
//		0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E, 0x0A,
//		0xCA, 0xCB, 0x0B, 0xC9, 0x09, 0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B,
//		0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14,
//		0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3, 0x11,
//		0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32, 0x36,
//		0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D, 0xFF,
//		0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28,
//		0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D,
//		0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26, 0x22,
//		0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1, 0x63,
//		0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4, 0x6C,
//		0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69,
//		0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE,
//		0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5, 0x77,
//		0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0, 0x50,
//		0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97, 0x55,
//		0x95, 0x94, 0x54, 0x9C, 0x5C, 0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A,
//		0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B,
//		0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C, 0x44,
//		0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83, 0x41,
//		0x81, 0x80, 0x40 };
//
//#define HOLDING_REGISTER_COUNT 25
//#define INPUT_REGISTER_COUNT 10
//
//uint16_t Holding_register[HOLDING_REGISTER_SIZE] =
//{ 0 };
//uint32_t Discrate_reg;
//coilRegs_t Coils;
//uint16_t Input_Reg[5];
//int16_t ReadBuffer[HOLDING_REGISTER_SIZE] =
//{ 0 };
//// Callback te pratik olmasi icin yazildi
//
//const MB_Holding_Limit Holding_Limit[30] =
//{
//		{ 0, 32000 }, // Calısma Durumu :
//		{ 0, 32000 },   // AnaMotorFreq
//		{ 0, 32000 },   // Motor1 Freq
//		{ 0, 32000 },   // Motor2 Freq
//		{ 0, 32000 },   // Motor3 Freq
//
//		{ 0, 32000 },   // Motor3 Freq
//		{ 0, 32000 },   // Motor3 Freq
//		{ 0, 32000 },   // Motor3 Freq
//		{ 0, 32000 },   // Motor3 Freq
//
//		{ 0, 32000 },
//		{ 0, 32000 },
//		{ 0, 32000 },
//		{ 0, 32000 },
//		{ 0, 32000 },
//		{ 0, 32000 },
//		{ 0, 32000 },
//		{ 0, 32000 },
//		{ 0, 32000 },
//		{ 0, 32000 },
//		{ 0, 32000 },
//		{ 0, 32000 },
//		{ 0, 32000 },
//
//};
///*
// *
// * Holding_register adress are registred MODBUS VALUE TABLE
// *
// */
//const MB_range_td MB_limit_value_table[] =
//		{
//		/* Cihaza �zel coil,discrate, input ve holding register modbus bilgileri */
//		{ 0, /*Modbus start adresi */
//		(MbTypecastAddress) &(Coils.Coil_Reg), /*Coil fiziksel start adresi */
//		(MbTypecastAddress) &Discrate_reg, /*Discrates fiziksel start adresi */
//		(MbTypecastAddress) &Input_Reg[0], /*Inputs fiziksel start adresi */
//		(MbTypecastAddress) &Holding_register[0], //Var[CSL].Value,      /*Holdings fiziksel start adresi */
//				0, /*Maksimum Coil say�s� */
//				0, /*Maksimum Discrates input say�s� */
//				0, /*Maksimum Inputs register say�s� */
//				HOLDING_REGISTER_SIZE }, /*Maksimum Holding register say�s� */
//		///////////////////////////////////////////////////////////////////////////////////
//				{ 20, /*Modbus start adresi */
//				0, /*Coil fiziksel start adresi */
//				0, /*Discrates fiziksel start adresi */
//				0, /*Inputs fiziksel start adresi */
//				(MbTypecastAddress) &GenericIO.bits, //Var[CSL].Value,      /*Holdings fiziksel start adresi */
//						0, /*Maksimum Coil say�s� */
//						0, /*Maksimum Discrates input say�s� */
//						0, /*Maksimum Inputs register say�s� */
//						1 }, /*Maksimum Holding register say�s� */
//				///////////////////////////////////////////////////////////////////////////////////
//				///////////////////////////////////////////////////////////////////////////////////
//				{ 200, /*Modbus start adresi */
//				0, /*Coil fiziksel start adresi */
//				0, /*Discrates fiziksel start adresi */
//				0, /*Inputs fiziksel start adresi */
//				(MbTypecastAddress) &MultipleDiscrete, //Var[CSL].Value,      /*Holdings fiziksel start adresi */
//						0, /*Maksimum Coil say�s� */
//						0, /*Maksimum Discrates input say�s� */
//						0, /*Maksimum Inputs register say�s� */
//						1 }, /*Maksimum Holding register say�s� */
//				///////////////////////////////////////////////////////////////////////////////////
//				{ 250, /*Modbus start adresi */
//				0, /*Coil fiziksel start adresi */
//				0, /*Discrates fiziksel start adresi */
//				0, /*Inputs fiziksel start adresi */
//				(MbTypecastAddress) &FailSafe, //Var[CSL].Value,      /*Holdings fiziksel start adresi */
//						0, /*Maksimum Coil say�s� */
//						0, /*Maksimum Discrates input say�s� */
//						0, /*Maksimum Inputs register say�s� */
//						1 }, /*Maksimum Holding register say�s� */
//				///////////////////////////////////////////////////////////////////////////////////
//				{ 300, /*Modbus start adresi */
//				0, /*Coil fiziksel start adresi */
//				0, /*Discrates fiziksel start adresi */
//				0, /*Inputs fiziksel start adresi */
//				(MbTypecastAddress) &temperatureVal, //Var[CSL].Value,      /*Holdings fiziksel start adresi */
//						0, /*Maksimum Coil say�s� */
//						0, /*Maksimum Discrates input say�s� */
//						0, /*Maksimum Inputs register say�s� */
//						1 }, /*Maksimum Holding register say�s� */
//				///////////////////////////////////////////////////////////////////////////////////
//				{ /*Tablo Sonu*/
//				0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
//						0xffff, } };
//
//void modbusInit(ModbusBase_t *pMb_t, UART_HandleTypeDef *huart,
//		GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, BR_define_td br,
//		uint8_t hardwave_control, ModbusType modbusType)
//{
//	pMb_t->huart = huart;
//	pMb_t->modbusType = modbusType;
//	if (!hardwave_control)
//	{
//		pMb_t->GPIOx = GPIOx;
//		pMb_t->GPIO_Pin = GPIO_Pin;
//	}
//	pMb_t->HardwaveFlow = hardwave_control;
//	pMb_t->MB_registers.MBpointer = pMb_t->ModbusBuffer;
//	pMb_t->MB_registers.MB_index = 0;
//	pMb_t->MB_registers.MB_byte_count = 1;
//	pMb_t->Frame_start_timer = 0xff;
//	pMb_t->Modbus_status = MB_STATUS_CLEAR;
//	baudRateSet(pMb_t, br);
//	Modbus_ReceiveInterrupt(pMb_t);
//}
//void Modbus_ReceiveInterrupt(ModbusBase_t *m_t)
//{
//	HAL_UART_Receive_IT(m_t->huart, &(m_t->RX_Data), 1);
//}
//void modbusFrameWait(ModbusBase_t *m_t)
//{
//	if (m_t->Frame_start_timer <= m_t->Time3_5)
//	{
//		m_t->Frame_start_timer++;
//		return;
//	}
//	if (m_t->Modbus_status & MB_TX_RUN)
//	{
//		//newFrameWait();
//		m_t->Modbus_status &= ~MB_TX_RUN;
//	}
//	if (m_t->Modbus_status & MB_RX_RUN)
//	{
//		m_t->Modbus_status |= MB_RX_FRAME_END;
//		m_t->Modbus_status &= ~MB_RX_RUN;
//	}
//}
///*
// uint8_t uartTXHandler(void)
// {
// if (m_t->MB_registers.MB_index <= m_t->MB_registers.MB_byte_count)
// {
// HAL_UART_Transmit_IT(&MODBUS_UART,&m_t->ModbusBuffer[m_t->MB_registers.MB_index],1);
// MB_registers.MB_index++;
// Frame_start_timer = 0;
//
// return 0;
// }
// return 1;
// }*/
//
//uint8_t uartRXHandler(ModbusBase_t *m_t)
//{
//	if (m_t->Modbus_status & MB_RX_RUN)
//	{
//		if (m_t->Frame_start_timer >= m_t->Time1_5)
//		{
//			m_t->MB_registers.MB_index = 0;
//			m_t->Modbus_status &= ~MB_RX_RUN;
//			m_t->Frame_start_timer = 0;
//			return 1;
//		}
//		if (m_t->MB_registers.MB_index < MAX_MB_BUFFER_SIZE)
//		{
//			m_t->MB_registers.MBpointer[m_t->MB_registers.MB_index] =
//					m_t->RX_Data;
//			m_t->MB_registers.MB_index++;
//			m_t->Frame_start_timer = 0;
//			return 0;
//		}
//		return 2;
//	}
//	if (m_t->Frame_start_timer >= m_t->Time3_5)
//	{
//		m_t->MB_registers.MB_index = 0;
//		m_t->Modbus_status |= MB_RX_RUN;
//		m_t->MB_registers.MBpointer[m_t->MB_registers.MB_index] = m_t->RX_Data;
//		m_t->MB_registers.MB_index++;
//		m_t->Frame_start_timer = 0;
//	}
//	return 0;
//}
//
//void newFrameWait(ModbusBase_t *m_t)
//{
//	m_t->MB_registers.MB_index = 0;
//	//RS485_RX_ENABLE();
//	if (!m_t->HardwaveFlow)
//	{
//		//HAL_GPIO_WritePin(m_t->GPIOx,m_t->GPIO_Pin,GPIO_PIN_RESET);
//	}
//
//}
//
//void modbusFrameControl(ModbusBase_t *m_t, uint8_t Device_address)
//{
//	if (m_t->Modbus_status & MB_TX_RUN)
//	{
//		return;
//	}
//
//	if (m_t->Modbus_status & MB_RX_FRAME_END)
//	{
//		uint8_t temp_DeviceAdres;
//		m_t->Modbus_status &= ~MB_BROADCASTS; /* Broadcasts disable */
//		if (m_t->modbusType == Modbus_Master)
//		{
//			temp_DeviceAdres = m_t->MasterDeviceAddres;
//		}
//		else
//		{
//			temp_DeviceAdres = Device_address;
//
//		}
//		if (temp_DeviceAdres
//				!= m_t->ModbusBuffer[MASTER_READ_DEVICE_ADRESS_INDEX]) // Adres kontrol kapatilmistir
//		{
//			if (0 == m_t->ModbusBuffer[0])
//			{
//				//Modbus_status |= MB_BROADCASTS;        /* Broadcasts enable */
//			}
//			else
//			{
//				newFrameWait(m_t);
//				m_t->Modbus_status &= ~MB_RX_FRAME_END;
//				return;
//			}
//		}
//		if (m_t->MB_registers.MB_index >= MIN_RX_BYTE_NUMBER)
//		{
//			if (!CRC16Calculate(m_t, m_t->MB_registers.MB_index))
//			{
//				if (m_t->modbusType == Modbus_Slave)
//				{
//					setLimitValsTablePointer(m_t, MB_limit_value_table);
//					modbusSLAVE_RXHandler(m_t);
//				}
//				else if (m_t->modbusType == Modbus_Master)
//				{
//					modbusMASTER_RXHandler(m_t);
//				}
//
//				// TO DO
//
//				//*//////
//			}
//		}
//		newFrameWait(m_t);
//		m_t->Modbus_status &= ~MB_RX_FRAME_END;
//	}
//}
//
//void setLimitValsTablePointer(ModbusBase_t *m_t,
//		const MB_range_td *MB_limit_val_table)
//{
//	m_t->pLimit_vals_table = MB_limit_val_table;
//#ifdef BIG_ENDIAN
///* Big Endian ise ------------------------------------------------------------*/
//  ((int8_t*)&m_t->MB_valid_address)[0] = m_t->ModbusBuffer[RXBF_ADDR_INDEX];   /* Adres MSB byte */
//  ((int8_t*)&m_t->MB_valid_address)[1] = m_t->ModbusBuffer[RXBF_ADDR_INDEX+1]; /* Adres LSB byte */
//#else
//	/* Little Endian ise ------------------------------------------------------------*/
//	((int8_t*) &m_t->MB_valid_address)[1] = m_t->ModbusBuffer[RXBF_ADDR_INDEX]; /* Adres MSB byte */
//	((int8_t*) &m_t->MB_valid_address)[0] = m_t->ModbusBuffer[RXBF_ADDR_INDEX
//			+ 1]; /* Adres LSB byte */
//#if !defined BIG_ENDIAN && !defined LITTLE_ENDIAN
//#error "sys_config.h dosyas�nda LITTEL_ENDIAN veya BIG_ENDIAN se�imi yap�lmad� "
//#endif
//#endif /* BIG_ENDIAN */
//	while (m_t->pLimit_vals_table->MbStarting_address <= m_t->MB_valid_address)
//	{
//		if (m_t->pLimit_vals_table->MbStarting_address == 0xFFFF)
//			break;
//		(m_t->pLimit_vals_table)++;
//	}
//	(m_t->pLimit_vals_table)--;
//	m_t->MB_valid_address -= m_t->pLimit_vals_table->MbStarting_address;
//}
//
//void modbusSLAVE_RXHandler(ModbusBase_t *m_t)
//{
//	if (m_t->Modbus_status & MB_BROADCASTS) /*Broadcast gelen ise read fonksiyonlar �al��mayacak */
//	{
//		switch (m_t->ModbusBuffer[RXBF_FUCT_INDEX])
//		{
//
//		case MODBUS_FUNC_WRITE_SINGLE_COIL:
//			modbusWriteSingleCoil(m_t);
//			break;
//		case MODBUS_FUNC_WRITE_MULTIPLE_COILS:
//			modbusWriteMultipleCoil(m_t);
//			break;
//		case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
//			modbusWriteSingleHoldingRegister(m_t);
//			break;
//		case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
//			modbusWriteMultipleHoldingRegister(m_t);
//			break;
//		default:
//			sendExceptionCode(m_t, MB_FUNCTION_ERROR);
//			return;
//		}
//	}
//	switch (m_t->ModbusBuffer[RXBF_FUCT_INDEX])
//	{
//	case MODBUS_FUNC_READ_COIL_STATUS:
//		modbusReadCoilStatus(m_t);
//		break;
//	case MODBUS_FUNC_READ_INPUT_STATUS:
//		modbusDiscrateStatus(m_t);
//		break;
//	case MODBUS_FUNC_READ_HOLDING_REGISTERS:
//		modbusReadHoldingRegisters(m_t);
//		break;
//	case MODBUS_FUNC_READ_INPUT_REGISTERS:
//		modbusReadInputRegisters(m_t);
//		break;
//	case MODBUS_FUNC_WRITE_SINGLE_COIL:
//		modbusWriteSingleCoil(m_t);
//		break;
//	case MODBUS_FUNC_WRITE_MULTIPLE_COILS:
//		modbusWriteMultipleCoil(m_t);
//		break;
//	case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
//		modbusWriteSingleHoldingRegister(m_t);
//		break;
//	case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
//		modbusWriteMultipleHoldingRegister(m_t);
//		break;
//	default:
//		sendExceptionCode(m_t, MB_FUNCTION_ERROR);
//	}
//}
//void inputQuantityAndAddressSet(ModbusBase_t *m_t)
//{
//	m_t->Phisical_address = m_t->pLimit_vals_table->PhisicalInputs_address;
//	m_t->Max_quantity = m_t->pLimit_vals_table->Inputs_quantity;
////  Phisical_address_end = Phisical_address + Max_quantity;
//}
//void modbusReadInputRegisters(ModbusBase_t *m_t)
//{
//	inputQuantityAndAddressSet(m_t);
//	modbusReadRegisters(m_t);
//}
//void modbusReadRegisters(ModbusBase_t *m_t)
//{
//	uint8_t TX_buffer_index = 3; /* Cevap ba�lang�� indexi */
//	uint8_t *pBuffer = (uint8_t*) m_t->Phisical_address;
//	uint8_t Word_count;
//	uint8_t Exception = quantityAndAddressControl(m_t);
//	uint16_t Holding_index = m_t->MB_valid_address * 2;
//	if (Exception)
//	{
//		sendExceptionCode(m_t, Exception);
//		return;
//	}
//	Word_count = m_t->Received_quantity;
//	m_t->ModbusBuffer[2] = Word_count * 2; /* ModbusBuffer[2] = Byte say�s� */
//	while (Word_count--)
//	{
//#ifdef BIG_ENDIAN
///* Big Endian ise ------------------------------------------------------------*/
//	  m_t->ModbusBuffer[TX_buffer_index] = pBuffer[Holding_index];
//    TX_buffer_index++;
//    Holding_index++;
//    m_t->ModbusBuffer[TX_buffer_index] = pBuffer[Holding_index];
//    TX_buffer_index++;
//    Holding_index++;
//#else
//		/* Little Endian ise ------------------------------------------------------------*/
//
//		m_t->ModbusBuffer[TX_buffer_index + 1] = pBuffer[Holding_index];
//		Holding_index++;
//		m_t->ModbusBuffer[TX_buffer_index] = pBuffer[Holding_index];
//		TX_buffer_index += 2;
//		Holding_index++;
//#if !defined BIG_ENDIAN && !defined LITTLE_ENDIAN
//#error "sys_config.h dosyas�nda LITTEL_ENDIAN veya BIG_ENDIAN se�imi yap�lmad� "
//#endif
//#endif /* BIG_ENDIAN */
//	}
//	sendResponse(m_t, TX_buffer_index);
//}
//void modbusReadHoldingRegisters(ModbusBase_t *m_t)
//{
//	holdingQuantityAndAddressSet(m_t);
//	modbusReadRegisters(m_t);
//}
//void modbusReadCoilStatus(ModbusBase_t *m_t)
//{
//	coilsQuantityAndAddressSet(m_t);
//	uint8_t Exception = quantityAndAddressControl(m_t);
//	if (Exception)
//	{
//		sendExceptionCode(m_t, Exception);
//		return;
//	}
//	bitStatusTransmit(m_t);
//}
//void discratesQuantityAndAddressSet(ModbusBase_t *m_t)
//{
//	m_t->Phisical_address = m_t->pLimit_vals_table->PhisicalDiscrates_address;
//	m_t->Max_quantity = m_t->pLimit_vals_table->Discrates_quantity;
////  Phisical_address_end = Phisical_address + Max_quantity;
//}
//void modbusDiscrateStatus(ModbusBase_t *m_t)
//{
//	discratesQuantityAndAddressSet(m_t);
//	uint8_t Exception = quantityAndAddressControl(m_t);
//	if (Exception)
//	{
//		sendExceptionCode(m_t, Exception);
//		return;
//	}
//	bitStatusTransmit(m_t);
//}
//void bitStatusTransmit(ModbusBase_t *m_t)
//{
//	uint8_t Byte_count, index;
//	coilBitAddressSet(m_t);
//	Byte_count = m_t->Received_quantity / 8;
//	if (m_t->Received_quantity % 8)
//		Byte_count++;
//	m_t->ModbusBuffer[2] = Byte_count;
//	index = 3;
//	m_t->ModbusBuffer[index] = 0;
//	uint8_t *pBuffer = (uint8_t*) m_t->Phisical_address;
//	while (m_t->Received_quantity)
//	{
//		if (pBuffer[m_t->MB_valid_address] & m_t->Bit_mask)
//		{
//			m_t->ModbusBuffer[index] |= m_t->Bit_wr_mask;
//		}
//		if (!(m_t->Bit_wr_mask <<= 1))
//		{
//			m_t->Bit_wr_mask = 1;
//			index++;
//			m_t->ModbusBuffer[index] = 0;
//		}
//		if (!(m_t->Bit_mask <<= 1))
//		{
//			m_t->Bit_mask = 1;
//			(m_t->MB_valid_address)++;
//		}
//		m_t->Received_quantity--;
//	}
//	sendResponse(m_t, Byte_count + 3);
//}
//uint8_t singleAddressControl(ModbusBase_t *m_t, uint16_t Max_value)
//{
//#ifdef BIG_ENDIAN
///* Big Endian ise ------------------------------------------------------------*/
//  ((int8_t*)&m_t->Received_quantity)[0] = m_t->ModbusBuffer[RXBF_QUAN_INDEX];   /* Single data MSB byte */
//  ((int8_t*)&m_t->Received_quantity)[1] = m_t->ModbusBuffer[RXBF_QUAN_INDEX+1]; /* Single data LSB byte */
//#else
//	/* Little Endian ise ------------------------------------------------------------*/
//	((int8_t*) &m_t->Received_quantity)[1] = m_t->ModbusBuffer[RXBF_QUAN_INDEX]; /* Single data MSB byte */
//	((int8_t*) &m_t->Received_quantity)[0] = m_t->ModbusBuffer[RXBF_QUAN_INDEX
//			+ 1]; /* Single data LSB byte */
//#if !defined BIG_ENDIAN && !defined LITTLE_ENDIAN
//#error "sys_config.h dosyas�nda LITTEL_ENDIAN veya BIG_ENDIAN se�imi yap�lmad� "
//#endif
//#endif /* BIG_ENDIAN */
//	if (m_t->Received_quantity <= Max_value)
//	{
//		if (m_t->MB_valid_address > m_t->Max_quantity)
//		{
//			return MB_ADDRES_ERROR;
//		}
//		return 0;
//	}
//	return MB_QUANTITY_ERROR;
//}
//void holdingQuantityAndAddressSet(ModbusBase_t *m_t)
//{
//	m_t->Phisical_address = m_t->pLimit_vals_table->PhisicalHoldings_address;
//	m_t->Max_quantity = m_t->pLimit_vals_table->Holdings_quantity;
////  Phisical_address_end = Phisical_address + Max_quantity;
//}
//void modbusWriteSingleHoldingRegister(ModbusBase_t *m_t)
//{
//	holdingQuantityAndAddressSet(m_t);
//	uint8_t Exception;
//	Exception = singleAddressControl(m_t, 0xffff);
//	if (Exception)
//	{
//		sendExceptionCode(m_t, Exception);
//		return;
//	}
//	writeMultipleRegister(m_t, 1, 4); /*Modbus Buffer[4] deki 1 word datat� holdinge yaz*/
//	sendResponse(m_t, 6); /* RX bufferdeki 6 byte geri yollan�yor */
//}
///*-- WRITE MULTIPLE REGISTER ALT FONKS�YONU ----------------------------------*/
//void writeMultipleRegister(ModbusBase_t *m_t, uint8_t Wr_word_count,
//		uint8_t Wr_data_index)
//{
//	uint8_t *pBuffer = (uint8_t*) m_t->Phisical_address;
//	uint16_t Holding_index = m_t->MB_valid_address * 2;
//	while (Wr_word_count--)
//	{
//#ifdef BIG_ENDIAN
///* Big Endian ise ------------------------------------------------------------*/
//    pBuffer[Holding_index] = m_t->ModbusBuffer[Wr_data_index];
//    Wr_data_index++;
//    Holding_index++;
//    pBuffer[Holding_index] = m_t->ModbusBuffer[Wr_data_index];
//    Wr_data_index++;
//    Holding_index++;
//#else
//		/* Little Endian ise ------------------------------------------------------------*/
//		int16_t temp = 0;
//		((uint8_t*) &temp)[0] = m_t->ModbusBuffer[Wr_data_index + 1];
//		((uint8_t*) &temp)[1] = m_t->ModbusBuffer[Wr_data_index];
//		m_t->limit_counter = (uint8_t) (Holding_index / 2);
//
//		if (temp <= Holding_Limit[m_t->limit_counter].up_limit
//				&& temp >= Holding_Limit[m_t->limit_counter].down_limit)
//		{
//			pBuffer[Holding_index + 1] = m_t->ModbusBuffer[Wr_data_index];
//			Wr_data_index++;
//			pBuffer[Holding_index] = m_t->ModbusBuffer[Wr_data_index];
//			Holding_index += 2;
//			Wr_data_index++;
//			m_t->Holding_Register_Change_Flag = 1;
//			MB_Set_HoldingChangeControl_flag(m_t);
//
//		}
//		else
//		{
//			Wr_data_index += 2;
//			Holding_index += 2;
//		}
//#endif
//	}
//}
//void MB_Set_HoldingChangeControl_flag(ModbusBase_t *m_t)
//{
//	m_t->Holding_Register_Change_Control_Flag = 1;
//}
//void modbusWriteMultipleHoldingRegister(ModbusBase_t *m_t)
//{
//	holdingQuantityAndAddressSet(m_t);
//	uint8_t Exception;
//	Exception = quantityAndAddressControl(m_t);
//	if (Exception)
//	{
//		sendExceptionCode(m_t, Exception);
//		return;
//	}
//	writeMultipleRegister(m_t, m_t->Received_quantity, 7);
//	sendResponse(m_t, 6); /* RX bufferdeki 6 byte geri yollan�yor */
//}
//void coilBitAddressSet(ModbusBase_t *m_t)
//{
//	m_t->Bit_mask = 1 << (m_t->MB_valid_address % 8); // Ge�erli Coil bit maskesi
//	m_t->MB_valid_address /= 8;                      // Ge�erli Coil byte adresi
//	m_t->Bit_wr_mask = 1;
//}
//void coilsQuantityAndAddressSet(ModbusBase_t *m_t)
//{
//	m_t->Phisical_address = m_t->pLimit_vals_table->PhisicalCoils_address;
//	m_t->Max_quantity = m_t->pLimit_vals_table->Coils_quantity;
//	// Phisical_address_end = Phisical_address + Max_quantity;
//}


//uint8_t quantityAndAddressControl(ModbusBase_t *m_t)
//{
//#ifdef BIG_ENDIAN
///* Big Endian ise ------------------------------------------------------------*/
//  ((int8_t*)&m_t->Received_quantity)[0] = m_t->ModbusBuffer[RXBF_QUAN_INDEX];   /* Quantity MSB byte */
//  ((int8_t*)&m_t->Received_quantity)[1] = m_t->ModbusBuffer[RXBF_QUAN_INDEX+1]; /* Quantity LSB byte */
//#else
//	/* Little Endian ise ------------------------------------------------------------*/
//	((int8_t*) &m_t->Received_quantity)[1] = m_t->ModbusBuffer[RXBF_QUAN_INDEX]; /* Quantity MSB byte */
//	((int8_t*) &m_t->Received_quantity)[0] = m_t->ModbusBuffer[RXBF_QUAN_INDEX
//			+ 1]; /* Quantity LSB byte */
//#if !defined BIG_ENDIAN && !defined LITTLE_ENDIAN
//#error "sys_config.h dosyas�nda LITTEL_ENDIAN veya BIG_ENDIAN se�imi yap�lmad� "
//#endif
//#endif /* BIG_ENDIAN */
//	if (m_t->Received_quantity <= m_t->Max_quantity)
//	{
//		if ((m_t->MB_valid_address + m_t->Received_quantity)
//				> m_t->Max_quantity)
//		{
//			return MB_ADDRES_ERROR;
//		}
//		return 0;
//	}
//	return MB_QUANTITY_ERROR;
//}

///*-- WRITE MULTI COILS FONKS�YONU (FONKSIYON KODU 0x0F) ----------------------*/
//void modbusWriteMultipleCoil(ModbusBase_t *m_t)
//{
//	coilsQuantityAndAddressSet(m_t);
//	uint8_t Exception = quantityAndAddressControl(m_t);
//	if (Exception)
//	{
//		sendExceptionCode(m_t, Exception);
//		return;
//	}
//	coilBitAddressSet(m_t);
//	writeMultiCoils(m_t, m_t->Received_quantity, 7,
//			m_t->ModbusBuffer[RXBF_BYTECOUNT_INDEX]);
//	sendResponse(m_t, 6);
//}
//void writeMultiCoils(ModbusBase_t *m_t, uint16_t Bit_count,
//		uint8_t RX_buffer_index, uint8_t Byte_count)
//{
//	uint8_t *pBuffer = (uint8_t*) (m_t->Phisical_address);
//	while (Bit_count)
//	{
//		if (m_t->ModbusBuffer[RX_buffer_index] & m_t->Bit_wr_mask)
//		{
//			pBuffer[m_t->MB_valid_address] |= m_t->Bit_mask;
//		}
//		else
//		{
//			pBuffer[m_t->MB_valid_address] &= ~(m_t->Bit_mask);
//		}
//		if (!(m_t->Bit_mask <<= 1))
//		{
//			m_t->Bit_mask = 1;
//			(m_t->MB_valid_address)++;
//		}
//		if (!(m_t->Bit_wr_mask <<= 1))
//		{
//			m_t->Bit_wr_mask = 1;
//			RX_buffer_index++;
//			if (--Byte_count == 0)
//				return;
//		}
//		Bit_count--;
//	}
//}
//void modbusWriteSingleCoil(ModbusBase_t *m_t)
//{
//	coilsQuantityAndAddressSet(m_t);
//#ifdef BIG_ENDIAN
///* Big Endian ise ------------------------------------------------------------*/
//  ((int8_t*)&m_t->Received_quantity)[0] = m_t->ModbusBuffer[RXBF_SCVAL_INDEX];   /* Coil value MSB byte */
//  ((int8_t*)&m_t->Received_quantity)[1] = m_t->ModbusBuffer[RXBF_SCVAL_INDEX+1]; /* Coil value LSB byte */
//#else
//	/* Little Endian ise ------------------------------------------------------------*/
//
//	((int8_t*) &m_t->Received_quantity)[1] =
//			m_t->ModbusBuffer[RXBF_SCVAL_INDEX]; /* Coil value MSB byte */
//	((int8_t*) &m_t->Received_quantity)[0] = m_t->ModbusBuffer[RXBF_SCVAL_INDEX
//			+ 1]; /* Coil value LSB byte */
//#if !defined BIG_ENDIAN && !defined LITTLE_ENDIAN
//#error "sys_config.h dosyas�nda LITTEL_ENDIAN veya BIG_ENDIAN se�imi yap�lmad� "
//#endif
//#endif /* BIG_ENDIAN */
//	if (!(m_t->Received_quantity == 0xFF00 || m_t->Received_quantity == 0x0000))
//	{
//		sendExceptionCode(m_t, MB_QUANTITY_ERROR);
//		return;
//	}
//	if (m_t->MB_valid_address >= m_t->Max_quantity)
//	{
//		sendExceptionCode(m_t, MB_ADDRES_ERROR);
//		return;
//	}
//	coilBitAddressSet(m_t);
//	writeMultiCoils(m_t, 1, 4, 1);
//	sendResponse(m_t, 6);
//}
////// MASTER SIDE
//
//void modbusMASTER_RXHandler(ModbusBase_t *m_t)
//{
//	switch (m_t->ModbusBuffer[MASTER_READ_FUNC_INDEX])
//	{
//	case MODBUS_FUNC_READ_COIL_STATUS:
//		Master_Read_Coil_Discrete(m_t);
//		break;
//	case MODBUS_FUNC_READ_INPUT_STATUS:
//		Master_Read_Coil_Discrete(m_t);
//		break;
//	case MODBUS_FUNC_READ_HOLDING_REGISTERS:
//		Master_Read_Holding_Input(m_t);
//		break;
//	case MODBUS_FUNC_READ_INPUT_REGISTERS:
//		Master_Read_Holding_Input(m_t);
//		break;
//	case MODBUS_FUNC_WRITE_SINGLE_COIL:
//		break;
//	case MODBUS_FUNC_WRITE_MULTIPLE_COILS:
//		break;
//	case MODBUS_FUNC_WRITE_SINGLE_REGISTER:
//		break;
//	case MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS:
//		break;
//	default:
//		ReadExceptionCode();
//	}
//}
//void Modbu_Master_Read_Reg(ModbusBase_t *m_t, ReadReg_TypeDef reg_type,
//		uint8_t slave_addr, uint16_t reg_addr, uint16_t size)
//{
//	m_t->masterReqDataAddres = reg_addr;
//
//	m_t->MasterDeviceAddres = slave_addr;
//	m_t->ModbusBuffer[0] = slave_addr;                   // Device Adres
//	m_t->ModbusBuffer[1] = (uint8_t) reg_type;             // Register Type
//	m_t->ModbusBuffer[2] = reg_addr >> 8;                  // MSB Register Adr
//	m_t->ModbusBuffer[3] = (uint8_t) reg_addr;            // LSB Register Adr
//	m_t->ModbusBuffer[4] = size >> 8; //SABIT 1 REG OKUNACAK   // MSB Byte Count
//	m_t->ModbusBuffer[5] = (uint8_t) size; //SABIT 1 REG OKUNACAK   // LSB Byte Count
//
//	sendResponse(m_t, 6);
//}
//void ModbusWrite_Reg(ModbusBase_t *m_t, WriteReg_TypeDef reg_type,
//		uint8_t slave_addr, uint16_t reg_addr, int16_t value)
//{
//	m_t->masterReqDataAddres = reg_addr;
//
//	m_t->MasterDeviceAddres = slave_addr;
//	m_t->ModbusBuffer[0] = slave_addr;                   // Device Adres
//	m_t->ModbusBuffer[1] = (uint8_t) reg_type;             // Register Type
//	m_t->ModbusBuffer[2] = reg_addr >> 8;                  // MSB Register Adr
//	m_t->ModbusBuffer[3] = (uint8_t) reg_addr;            // LSB Register Adr
//	m_t->ModbusBuffer[4] = (value >> 8) & 0xFF;             // MSB Byte Count
//	m_t->ModbusBuffer[5] = value & 0xFF;     //gerekesiz       // LSB Byte Count
//
//	sendResponse(m_t, 6);
//
//}
//void Master_Read_Coil_Discrete(ModbusBase_t *m_t)
//{
//	// TO DO
//	uint8_t toplam_data_sayisi = m_t->ModbusBuffer[MASTER_RX_DATA_COUNT_INDEX];
//	if (toplam_data_sayisi != 1)
//	{
//		return;
//	} // modbus gateway i�in sadece 1 bytel�k okuma yap�lacak. gelen giden 1 byte l�k data i�in olacak .
//	CRC16Calculate(m_t, MASTER_CRC_HARICI_C_D_BYTE_SAYISI);
//
//	if (m_t->ModbusBuffer[MASTER_CRC_HARICI_C_D_BYTE_SAYISI] != m_t->CRCLo
//			|| m_t->ModbusBuffer[MASTER_CRC_HARICI_C_D_BYTE_SAYISI + 1]
//					!= m_t->CRCHi)  // CRC kontrol� sorunsuz ise
//	{
//
//	}
//}
//void Master_Read_Disrecete(ModbusBase_t *m_t)
//{
//	// TO DO
//
//}
//void Master_Read_Holding_Input(ModbusBase_t *m_t)
//{
//
//	CRC16Calculate(m_t,
//			MASTER_CRC_HARICI_H_I_SABIT_BYTE_SAYISI
//					+ m_t->ModbusBuffer[MASTER_RX_DATA_COUNT_INDEX]);
//
//	if (m_t->ModbusBuffer[MASTER_CRC_HARICI_H_I_SABIT_BYTE_SAYISI
//			+ m_t->ModbusBuffer[MASTER_RX_DATA_COUNT_INDEX]] != m_t->CRCLo
//			|| m_t->ModbusBuffer[MASTER_CRC_HARICI_H_I_SABIT_BYTE_SAYISI
//					+ m_t->ModbusBuffer[MASTER_RX_DATA_COUNT_INDEX] + 1]
//					!= m_t->CRCHi)  // CRC kontrol� sorunsuz ise
//	{
//		return;
//	}
//	uint8_t temp_size = m_t->ModbusBuffer[MASTER_RX_DATA_COUNT_INDEX];
//	uint8_t *data_p = &m_t->ModbusBuffer[MASTER_READ_HOLDING_DATA_ADRES_0];
//	temp_size = (uint8_t) temp_size / 2;
//	for (int a = 0; a < temp_size; a++)
//	{
//		ReadBuffer[a] = data_p[a * 2] << 8 | data_p[(a * 2) + 1];
//	}
//	ModbusMaster_RXCallback(m_t,
//			m_t->ModbusBuffer[MASTER_READ_DEVICE_ADRESS_INDEX],
//			m_t->ModbusBuffer[MASTER_READ_FUNC_INDEX], ReadBuffer, temp_size);
//
//}
////////////////////////MASTER SIDE END//////////////////////////////////////
//
///*-- MODBUS HATA KODUNU G�NDEREN FONKS�YON -------------------------------------
// ExceptionCode ile girilen hata kodu master g�nderilir
// ------------------------------------------------------------------------------*/
//void sendExceptionCode(ModbusBase_t *m_t, uint8_t ExceptionCode)
//{
//	if (!(m_t->Modbus_status & MB_BROADCASTS))
//	{
//		m_t->ModbusBuffer[MASTER_READ_FUNC_INDEX] += 0x80;
//		m_t->ModbusBuffer[MASTER_READ_FUNC_INDEX + 1] = ExceptionCode;
//		sendResponse(m_t, 3); /* 3 Byte error cevab� g�nderilecek */
//		return;
//	}
//	newFrameWait(m_t);
//}
//void ReadExceptionCode(ModbusBase_t *m_t)
//{
//	if (!(m_t->Modbus_status & MB_BROADCASTS))
//	{
//		// TO DO
//		//ModbusMaster_ExceptionCallback
//		return;
//	}
//	// newFrameWait();
//}
//
//void sendResponse(ModbusBase_t *m_t, uint8_t RXTX_byte_number)
//{
//	if (!(m_t->Modbus_status & MB_BROADCASTS))
//	{
//		//RS485_TX_ENABLE();
//		if (!m_t->HardwaveFlow)
//		{
//			//HAL_GPIO_WritePin(m_t->GPIOx,m_t->GPIO_Pin,GPIO_PIN_SET);
//		}
//		CRC16Calculate(m_t, RXTX_byte_number);
//		m_t->ModbusBuffer[RXTX_byte_number] = m_t->CRCLo;
//		m_t->ModbusBuffer[RXTX_byte_number + 1] = m_t->CRCHi;
//		m_t->MB_registers.MB_byte_count = RXTX_byte_number + 1;
//		m_t->MB_registers.MB_index = 0;
//
//		m_t->Modbus_status |= MB_TX_RUN; /* TX run enable*/
//		HAL_UART_Transmit_IT(m_t->huart,
//				&m_t->ModbusBuffer[m_t->MB_registers.MB_index],
//				m_t->MB_registers.MB_byte_count + 1);
//
//		return;
//	}
//	//newFrameWait();
//}
//
//
//
//void baudRateSet(ModbusBase_t *m_t, BR_define_td Baud_rate)
//{
//
//	switch (Baud_rate)
//	{
//	case 0:
//		m_t->Time1_5 = T1_5_2400BR;
//		m_t->Time3_5 = T3_5_2400BR;
//		break;
//	case 1:
//		m_t->Time1_5 = T1_5_4800BR;
//		m_t->Time3_5 = T3_5_4800BR;
//		break;
//	case 2:
//		m_t->Time1_5 = T1_5_9600BR;
//		m_t->Time3_5 = T3_5_9600BR;
//		break;
//	case 3:
//		m_t->Time1_5 = T1_5_19200BR;
//		m_t->Time3_5 = T3_5_19200BR;
//		break;
//	case 4:
//		m_t->Time1_5 = T1_5_HSPEED;
//		m_t->Time3_5 = T3_5_HSPEED;
//		break;
//	case 5:
//		m_t->Time1_5 = T1_5_HSPEED;
//		m_t->Time3_5 = T3_5_HSPEED;
//		break;
//	case 6:
//		m_t->Time1_5 = T1_5_HSPEED;
//		m_t->Time3_5 = T3_5_HSPEED;
//		break;
//
//	}
//}
//
//__weak void ModbusMaster_ExceptionCallback(ModbusBase_t *m_t,
//		uint8_t deviceAdress, uint8_t funcCode,
//		Modbus_ERROR_Codes exceptionCode)
//{
//	UNUSED(m_t);
//	UNUSED(deviceAdress);
//	UNUSED(funcCode);
//	UNUSED(exceptionCode);
//	/*TO DO
//	 *
//	 * */
//}
//__weak void ModbusMaster_RXCallback(ModbusBase_t *m_t, uint8_t deviceAdress,
//		ReadReg_TypeDef regType, int16_t *data_p, uint8_t size)
//{
//	UNUSED(m_t);
//	UNUSED(deviceAdress);
//	UNUSED(regType);
//	UNUSED(data_p);
//	UNUSED(size);
//}
//
///* EXAMPLE INPUT READ
// *
// void ModbusMaster_RXCallback(uint8_t deviceAdress,ReadReg_TypeDef regType,uint8_t *data_p,uint8_t size)
// {
// uint8_t temp_size =(uint8_t) size / 2 ;
// for(int a = 0 ; a< temp_size ; a++)
// {
// vals[a] = data_p[a*2]<< 8 | data_p[(a*2)+1];
//
// }
//
// }
// *
// *
// *
// *
// * */
///************************ END OF FILE *****************************************/
