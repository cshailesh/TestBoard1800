/*
 * mbAutoAddress-Master.c
 */
#include "mbAutoAddress-Slave.h"

#include "main.h"
#include "mb.h"
#include "mbframe.h"
#include "mbproto.h"
#include "port.h"
#include "projectDefs.h"
#include "addr.h"
#include "rng.h"
#include "uid.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
	MODBUS_SUBFUNCTION_SET_ADDRESS_RANGE = 0x20,
	MODBUS_SUBFUNCTION_RANDOMIZE_ADDRESSES = 0x21,
	MODBUS_SUBFUNCTION_GET_UNIQUE_ID = 0x22
} ModbusSubFunctionT;


uint8_t MinAddress = 1;
uint8_t MaxAddress = 30;

#define UNIQUE_ID_LENGTH_BYTES		12

BOOL NumberInArray(uint8_t, uint8_t *, unsigned int);

/*********************************************************************************************************************
 * Sets the RS-485 address min and max values, based on a received Modbus message.
 *
 * Inputs:
 * 	Payload:	Message payload.
 * 	Length:		Message length.
 *
 * Outputs:
 * 	MinAddress:	Min RS-485 address.
 * 	MaxAddress:	Max RS-485 address.
 *
 * Return:			MB_EX_NONE if all is well. MB_EX_ILLEGAL_DATA_VALUE if the payload length is too short.
 *********************************************************************************************************************/
eMBException AutoAddress_SetRange(UCHAR *Payload, USHORT Length)
{
	eMBException status = MB_EX_NONE;
	if (Length >= 2)
	{
		// Get the first byte of the payload
		MinAddress = *(Payload + 4);
		MaxAddress = *(Payload + 5);
		if (DEBUG_AUTOADDRESS) {
			printf("AutoAddr: Set range min=%d, max=%d\r\n", MinAddress, MaxAddress);
		}
	}
	else
	{
		status = MB_EX_ILLEGAL_DATA_VALUE;
		if (DEBUG_AUTOADDRESS) {
			printf("AutoAddr: Set range error %d\r\n", status);
		}
	}
	// else, invalid message

	return status;
}

/*********************************************************************************************************************
 * Selects an RS-485 address between MinAddress and MaxAddress, using a pseudoRNG.
 * If the new address conflicts with a list of used addresses in the Payload, increments the address until it finds
 * an available number.
 *
 * Inputs:
 * 	Payload:	Message payload. May contain a list of addresses to avoid.
 * 	Length:		Message length. If 0, there are no used addresses to avoid.
 *
 * Outputs:
 * 	ucMBAddress:	Updated modbus address for this device.
 *
 * Return:		MB_EX_NONE if all is well. MB_EX_ILLEGAL_DATA_VALUE if there are no remaining addresses with the
 * 						current range.
 *********************************************************************************************************************/
eMBException AutoAddress_Randomize(UCHAR *Payload, USHORT Length)
{
	eMBException status = MB_EX_NONE;

	// Get a random number
	int RandomNumberCopy =  GetRandomNumber(); //RandomNumber;
	// Scale the random number to the range MinAddress to MaxAddress.
	uint8_t AddressRange = MaxAddress - MinAddress + 1;
	unsigned int PayloadLength = *(Payload + 3);		// Length is 3 bytes into the payload.
	uint8_t *pPayload = Payload + 4;					// List of used addresses starts 4 bytes in.

	if (DEBUG_AUTOADDRESS) {
		printf("AutoAddr: Rand. Used addr =");
		for (int i = 0; i < Length; i++)
		{
			printf("%d ", *(Payload+i));
		}
		printf("\r\n");
	}

	float RandomNumberFraction = (float)RandomNumberCopy/(float)RAND_MAX;
	uint8_t NewRS485Address = MinAddress + (uint8_t)((float)RandomNumberFraction * (float)AddressRange);
	if (DEBUG_AUTOADDRESS) {
		printf("AutoAddr: Rand. New Addr %d\r\n", NewRS485Address);
	}
	uint8_t StartingAddress = NewRS485Address;
	BOOL DuplicateAddress = TRUE;
	while (DuplicateAddress)
	{	// Cannot use this address
		DuplicateAddress = NumberInArray(NewRS485Address, pPayload, PayloadLength);
		if (DuplicateAddress)
		{
			if (DEBUG_AUTOADDRESS) {
				printf("AutoAddr: Rand. Addr %d is unavailable\r\n", NewRS485Address);
			}

			// Increment address to try and find one that's available.
			NewRS485Address++;
			if (NewRS485Address > MaxAddress)
			{	// Roll over
				NewRS485Address = MinAddress;
			}
			if (NewRS485Address == StartingAddress)
			{	// We've exhausted all addresses possibilities. Bail.
				status = MB_EX_ILLEGAL_DATA_VALUE;
				if (DEBUG_AUTOADDRESS) {
					printf("AutoAddr: Rand. No addr available\r\n");
				}
				break;
			}
		}
		else
		{	// We found a valid address
			// Set the new address
			//TODO fix
			AddressSet((UCHAR)NewRS485Address);
			SetAddressUpdateFlag();
			if (DEBUG_AUTOADDRESS) {
				printf("AutoAddr: Rand. Addr finished %d\r\n", NewRS485Address);
			}
		}
	}	// while

	return status;
}

/*********************************************************************************************************************
 * Searches an array to see if NumberToCheck is alreay in the array.
 *
 * Inputs:
 * 	NumberToCheck:	The number to search for.
 * 	Array:					The array of numbers to check.
 * 	Length:					The length of the array.
 *
 * Outputs:	None
 *
 * Return:	TRUE if the number is in the array. FALSE if it's not.
 *
 * Note:		This is a utility like function. It should be in a file of utilities.
 *********************************************************************************************************************/
BOOL NumberInArray(uint8_t NumberToCheck, uint8_t Array[], unsigned int ArrayLength)
{
	BOOL FoundInArray = FALSE;
	for (int i = 0; i < ArrayLength; i++)
	{
		if (Array[i] == NumberToCheck)
		{	// We found it
			FoundInArray = TRUE;
			break;
		}
	}
	return FoundInArray;
}

/*********************************************************************************************************************
 * Sends the unique ID of this device in response to a Modbus request.
 *
 * Inputs:
 *
 * Outputs:
 * 	Payload:	Modbus response payload is updated with the unique ID.
 * 	Length:		Response length.
 *
 * Return:		MB_EX_NONE.
 *********************************************************************************************************************/
eMBException AutoAddress_ReadUniqueID(UCHAR *pPayload, USHORT *pLength)
{
	eMBException status = MB_EX_NONE;

	/* Payload points to the 2nd byte of the Rx message (the address has been handled previously).
	 * We're going to reply with the same function and subfunction, so we advance the pointer past this.
	 */
	UCHAR *pMsg = pPayload;
	*pMsg++ = MB_FUNC_DIAG_DIAGNOSTIC;
	*pMsg++ = (UCHAR)(((uint16_t)MODBUS_SUBFUNCTION_GET_UNIQUE_ID) >> 8);			// High byte
	*pMsg++ = (UCHAR)(((uint16_t)MODBUS_SUBFUNCTION_GET_UNIQUE_ID) & 0xFF);	// Low byte

	*pMsg++ = UNIQUE_ID_LENGTH_BYTES;		// Size of unique ID payload

	// Copy our unique ID to the payload. We start with the MS byte, and work backward to the least significant byte.
	for (int i = 0; i < UNIQUE_ID_LENGTH_BYTES; i++)
	{
		*pMsg++ = GetUID(i);
	}
	*pLength = pMsg - pPayload;
	return status;
}
