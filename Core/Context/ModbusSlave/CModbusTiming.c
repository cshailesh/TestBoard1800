#include "CModbusTiming.h"

void Modbus_ReceiveInterrupt(MODBUS_DATA_t *pMb)
{
	HAL_UART_Receive_IT(pMb->mHuart, &(pMb->mRX_Data), 1);
}

void modbusFrameWait(MODBUS_DATA_t *pMb)
{
	if (pMb->mFrame_start_timer <= pMb->mTime3_5)
	{
		pMb->mFrame_start_timer++;
		return;
	}
	if (pMb->mMB_status & MB_TX_RUN)
	{
		//newFrameWait();
		pMb->mMB_status &= ~MB_TX_RUN;
	}
	if (pMb->mMB_status & MB_RX_RUN)
	{
		pMb->mMB_status |= MB_RX_FRAME_END;
		pMb->mMB_status &= ~MB_RX_RUN;
	}
}

uint8_t uartRXHandler(MODBUS_DATA_t *pMb)
{
	if (pMb->mMB_status & MB_RX_RUN)
	{
		if (pMb->mFrame_start_timer >= pMb->mTime1_5)
		{
			pMb->mMB_registers.mMB_index = 0;
			pMb->mMB_status &= ~MB_RX_RUN;
			pMb->mFrame_start_timer = 0;
			return 1;
		}
		if (pMb->mMB_registers.mMB_index < MAX_MB_BUFFER_SIZE)
		{
			pMb->mMB_registers.mMBpointer[pMb->mMB_registers.mMB_index] =
					pMb->mRX_Data;
			pMb->mMB_registers.mMB_index++;
			pMb->mFrame_start_timer = 0;
			return 0;
		}
		return 2;
	}

	if (pMb->mFrame_start_timer >= pMb->mTime3_5)
	{
		pMb->mMB_registers.mMB_index = 0;
		pMb->mMB_status |= MB_RX_RUN;
		pMb->mMB_registers.mMBpointer[pMb->mMB_registers.mMB_index] =
				pMb->mRX_Data;
		pMb->mMB_registers.mMB_index++;
		pMb->mFrame_start_timer = 0;
	}
	return 0;
}

void newFrameWait(MODBUS_DATA_t *pMb)
{
	pMb->mMB_registers.mMB_index = 0;
	//RS485_RX_ENABLE();
	if (!pMb->mHardwaveFlow)
	{
		//HAL_GPIO_WritePin(pMb->mGPIOx,pMb->mGPIO_Pin,GPIO_PIN_RESET);
	}

}

void modbusFrameControl(MODBUS_DATA_t *pMb, uint8_t Device_address)
{
	if (pMb->mMB_status & MB_TX_RUN)
	{
		return;
	}

	if (pMb->mMB_status & MB_RX_FRAME_END)
	{
		uint8_t temp_DeviceAdres;
		pMb->mMB_status &= ~MB_BROADCASTS; /* Broadcasts disable */
		if (pMb->mModbusType == Modbus_Master)
		{
			temp_DeviceAdres = pMb->mMasterDeviceAddres;
		}
		else
		{
			temp_DeviceAdres = Device_address;

		}
		if (temp_DeviceAdres
				!= pMb->mModbusBuffer[MASTER_READ_DEVICE_ADRESS_INDEX]) // Adres kontrol kapatilmistir
		{
			if (0 == pMb->mModbusBuffer[0])
			{
				//Modbus_status |= MB_BROADCASTS;        /* Broadcasts enable */
			}
			else
			{
				newFrameWait(pMb);
				pMb->mMB_status &= ~MB_RX_FRAME_END;
				return;
			}
		}
		if (pMb->mMB_registers.mMB_index >= MIN_RX_BYTE_NUMBER)
		{
			if (!CRC16Calculate(pMb, pMb->mMB_registers.mMB_index))
			{
				if (pMb->mModbusType == Modbus_Slave)
				{
					//setLimitValsTablePointer(pMb, MB_limit_value_table);
					modbusSLAVE_RXHandler(pMb);
				}
				else if (pMb->mModbusType == Modbus_Master)
				{
					//modbusMASTER_RXHandler(pMb);
				}
			}
		}
		newFrameWait(pMb);
		pMb->mMB_status &= ~MB_RX_FRAME_END;
	}
}

void MB_Syst_Tick(MODBUS_TIMING_t *pDat)
{
	pDat->mComCount++;
	  if(pDat->mComCount > CHECK_5_MINUTES)
	  {
		  pDat->mIsComminicated=0;
	  }

	  if(pDat->mStartnewIDProcess) // This id are used to control for NEWID request process (in devicealgorithm.)
	  {
		  pDat->mComNewIDCount++;
		  if(pDat->mComNewIDCount > CHECK_20_SECONDS) // if it occurs timeout , LED4 stop flushing, clear all button state and back to default or old iD
		  {
			  pDat->mStartnewIDProcess=0;
			  pDat->mComNewIDCount=0;
		  }
	  }
	  else
		  pDat->mComNewIDCount=0;
}
