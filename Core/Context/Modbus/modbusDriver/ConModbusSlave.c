/*
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#include "projectDefs.h"
#include "ConModbusSlave.h"
#include "uid.h"
#include "addr.h"
#include "DigitalOutputPort.h"
#include "failsafe.h"
#include "mb.h"
#include "l4flash.h"

//#include "switchposition.h"

//const char gVersion[] = "VERSION NUMBER: 1.0" BOARD_VER " END NUMBER";

typedef enum
{

	PROJECT_ID = 0,
	VERSION_MAJOR,
	VERSION_MINOR,
	FEATURES = 4,
	MODBUS_ADDRESS = 5,
	PERIPHERAL_COMMAND_STATUS = 9,
	ANALOG_VOLTAGE_IO_START = 99,
	MULTIPLE_DISCRETE_IO_START = 199,
	MULTIPLE_DISCRETE_IO_END = MULTIPLE_DISCRETE_IO_START
			+ (NUM_DISC_OUTPUTS / 16),
	SWITCH_POSITION = 209,
	RELAY_STATE = 210,
	OUTPUT_FAILSAFE_START = 249,
	OUTPUT_FAILSAFE_END = OUTPUT_FAILSAFE_START + (NUM_DISC_OUTPUTS / 16),
	TEMPERATURE_INPUT0 = 299,
	SERIAL_UNLOCK = 7249,
	UNIQUE_ID_START = 7250,
	UNIQUE_ID_END = UNIQUE_ID_START + ((SIZE_OF_UID) / 2) - 1,

} ModbusHoldingRegister;

typedef enum
{
	C_OUTPUT1 = 0,
	C_OUTPUT2 = 1,
	C_OUTPUT3 = 2,
	C_OUTPUT4 = 3,
	C_OUTPUT5 = 4,
	C_OUTPUT6 = 5,
	C_OUTPUT7 = 6,
	C_OUTPUT8 = 7,
} ModbusCoilRegister;


eMBErrorCode eMBRegHoldingCB(UCHAR *pucRegBuffer, USHORT usAddress,
		USHORT usNRegs, eMBRegisterMode eMode)
{
	eMBErrorCode eStatus = MB_ENOERR;
	//return eStatus;
	int i = 0;
	int idx;
	uint16_t registerOffset = usAddress - 1;

	if (pucRegBuffer == NULL)
	{
		eStatus = MB_EINVAL;
	}
	//this seems unnecessary
	else if (registerOffset < PERIPHERAL_COMMAND_STATUS)
	{
		if (usNRegs >= PERIPHERAL_COMMAND_STATUS)
		{
			eStatus = MB_ENOREG;
		}

		for (i = 0; i < usNRegs; i++)
		{
			idx = registerOffset + i;
			switch (idx)
			{
			case PROJECT_ID:
				pucRegBuffer[i * 2] = HIGH_BYTE_OF_WORD(PROJECT_ID_VAL);
				pucRegBuffer[i * 2 + 1] = LOW_BYTE_OF_WORD(PROJECT_ID_VAL);
				break;

			case VERSION_MAJOR:
				pucRegBuffer[i * 2] = HIGH_BYTE_OF_WORD(FW_MAJOR_VERSION);
				pucRegBuffer[i * 2 + 1] = LOW_BYTE_OF_WORD(FW_MAJOR_VERSION);
				break;

			case VERSION_MINOR:
				pucRegBuffer[i * 2] = HIGH_BYTE_OF_WORD(FW_MINOR_VERSION);
				pucRegBuffer[i * 2 + 1] = LOW_BYTE_OF_WORD(FW_MINOR_VERSION);
				break;

			case FEATURES:

				break;

			case MODBUS_ADDRESS:

				//address gets written to RAM here, written to flash in main
				SetAddressUpdateFlag();
				//modbus address is only going to be 1 byte
				AddressSet(pucRegBuffer[i * 2 + 1]);
				break;

			default:
				eStatus = MB_ENOREG;
				break;
			}
		}

	}
	else if (((registerOffset) < TEMPERATURE_INPUT0)
			&& ((registerOffset) >= MULTIPLE_DISCRETE_IO_START))
	{
		for (i = 0; i < usNRegs; i++)
		{
			idx = registerOffset + i;
			switch (idx)
			{
			case MULTIPLE_DISCRETE_IO_START ... MULTIPLE_DISCRETE_IO_END:
				if (eMode == MB_REG_WRITE)
				{
//					//high byte
//					SetRelays(&pucRegBuffer[2*i], ((idx - MULTIPLE_DISCRETE_IO_START) * 16) + 8, 8);
//
//					//low byte
//					SetRelays(&pucRegBuffer[2*i+1], (idx - MULTIPLE_DISCRETE_IO_START) * 16, 8);
//					//don't restore relays
//					ClearRestoreRelayFlag();
				}
				else if (eMode == MB_REG_READ)
				{
//					//High Byte
//					GetRelays(&pucRegBuffer[2 * i], ((idx - MULTIPLE_DISCRETE_IO_START) * 16) + 8, 8);
//
//					//Low Byte
//					GetRelays(&pucRegBuffer[2 * i + 1], (idx - MULTIPLE_DISCRETE_IO_START) * 16, 8);
				}

				break;

			case SWITCH_POSITION:
			{
				if (eMode == MB_REG_READ)
				{
//					pucRegBuffer[2 * i] = GetSwPos(
//							2 * (idx - SWITCH_POSITION) + 1);
//					pucRegBuffer[2 * i + 1] = GetSwPos(
//							2 * (idx - SWITCH_POSITION));
				}
			}
				break;

			case RELAY_STATE:
			{
				if (eMode == MB_REG_READ)
				{
//					pucRegBuffer[2 * i] = GetRelayState(
//							2 * (idx - RELAY_STATE) + 1);
//					pucRegBuffer[2 * i + 1] = GetRelayState(
//							2 * (idx - RELAY_STATE));
				}
			}
				break;

			case OUTPUT_FAILSAFE_START ... OUTPUT_FAILSAFE_END:
				if (eMode == MB_REG_WRITE)
				{
//					//High Byte
//					WriteFailsafe(2 * (idx - OUTPUT_FAILSAFE_START) + 1,
//							pucRegBuffer[2 * i]);
//
//					//Low Byte
//					WriteFailsafe(2 * (idx - OUTPUT_FAILSAFE_START),
//							pucRegBuffer[2 * i + 1]);
				}
				else if (eMode == MB_REG_READ)
				{
//					//High Byte
//					pucRegBuffer[2 * i] = GetFailsafe(
//							2 * (idx - OUTPUT_FAILSAFE_START) + 1);
//
//					//Low Byte
//					pucRegBuffer[2 * i + 1] = GetFailsafe(
//							2 * (idx - OUTPUT_FAILSAFE_START));
				}
				break;

			default:
				eStatus = MB_ENOREG;
				break;
			}
		}
	}
	else if (registerOffset >= SERIAL_UNLOCK)
	{
		bool WroteUniqueID = false;
		for (i = 0; i < usNRegs; i++)
		{
			idx = registerOffset + i;
			switch (idx)
			{
			case SERIAL_UNLOCK:
				if (eMode == MB_REG_WRITE)
				{
					WriteUIDPassword(
							pucRegBuffer[2 * i] << 8 | pucRegBuffer[2 * i + 1]);
				}
				break;

			case UNIQUE_ID_START ... UNIQUE_ID_END:
				if (eMode == MB_REG_WRITE)
				{
					//make sure that the passcode has been written correctly
					//in place so users cannot change their serial number willy nilly
					if (GetUIDFlag())
					{
						//serial gets written to ram here, written to flash in main loop
						SetUID(2 * (idx - UNIQUE_ID_START) + 1,
								pucRegBuffer[2 * i]);
						SetUID(2 * (idx - UNIQUE_ID_START),
								pucRegBuffer[2 * i + 1]);
						WroteUniqueID = true;
					}
				}
				else if (eMode == MB_REG_READ)
				{
					pucRegBuffer[2 * i] = GetUID(
							2 * (idx - UNIQUE_ID_START) + 1);
					pucRegBuffer[2 * i + 1] = GetUID(
							2 * (idx - UNIQUE_ID_START));
				}
				break;
			}
		}

		if (WroteUniqueID)
		{// If any update to the unique ID in RAM, set flag to write it to flash.
			SetSerialUpdateFlag();
		}
	}
	else
	{
		eStatus = MB_ENOREG;
	}

	UpdateFailsafeTimer();

	return eStatus;
}

eMBErrorCode eMBRegCoilsCB(UCHAR *pucRegBuffer, USHORT usAddress,
		USHORT usNRegs, eMBRegisterMode eMode)
{
	eMBErrorCode eStatus = MB_ENOERR;
	return eStatus;
//  int idx;
//  uint8_t byte;
//  uint8_t bit;
//  if (pucRegBuffer == NULL)
//  {
//    eStatus = MB_EINVAL;
//  }
//  else
//  {
//    for ( int i = 0; i < usNRegs; i++)
//    {
//      byte = i / 8;
//      bit = 1 << i % 8;
//      switch (usAddress - 1)
//      {
//        case C_OUTPUT1 ... C_OUTPUT8:
//          idx = (usAddress - 1 + i) - C_OUTPUT1;
//
//          if (eMode == MB_REG_WRITE)
//          {
//              SetRelay( !!(pucRegBuffer[byte] & bit), idx);
//          }
//          else if (eMode ==  MB_REG_READ)
//          {
//            pucRegBuffer[byte] |= (!!_DigitOutRead(idx)) << i;
//          }
//          //don't restore relays, we're setting them here
//          ClearRestoreRelayFlag();
//        break;
//
//        default:
//          eStatus = MB_ENOREG;
//          break;
//      }
//
//    }
//  }
//
//  UpdateFailsafeTimer();

	return eStatus;
}
