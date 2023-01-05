#include "uid.h"
#include "l4flash.h"
#include "main.h"
#include "projectDefs.h"

#include <stdio.h>


#define UID_UNLOCK 48526

#if defined(HARD_CODED_SERIAL_NUMBER)
static uint8_t UID[SIZE_OF_UID] = HARD_CODED_SERIAL_NUMBER;
#else
static uint8_t UID[SIZE_OF_UID];
#endif
static uint8_t UIDFlag = 0;
static uint8_t serial_flash_update;

//16 characters, 1 termination, 3 hyphens
#define UNIQUE_ID_STR_LENGTH 16 + 1 + 3 
static char unique_id_str[UNIQUE_ID_STR_LENGTH];

static void SetUIDStr( void );

//this relies on flash being initialized first
void InitUID()
{
#if defined(HARD_CODED_SERIAL_NUMBER)
	serial_flash_update = 1;
#else
	// Restore Unique ID from flash.
	ReadUIDFromFlash();
#endif
	SetUIDStr();
}

uint8_t GetUID(uint8_t idx)
{
	uint8_t UID_Byte = 0;
	if (idx < SIZE_OF_UID)
	{
		UID_Byte = UID[idx];
	}
	return UID_Byte;
}

void SetUID( uint8_t idx, uint8_t val )
{
	UID[idx] = val;
}

void ReadUIDFromFlash()
{
	uint8_t val = 0;
	uint8_t i = FLASH_UID_START;
	uint8_t j = 0;
	for ( ; j < SIZE_OF_UID; i++, j++)
	{
		L4FLASH_ReadEntry(i, &val);
		UID[j] = val;
	}
}

uint8_t CheckWriteUIDToFlash()
{
	uint8_t val = 0;
	if (serial_flash_update)
	{
		serial_flash_update = 0;
		uint8_t i = FLASH_UID_START;
		uint8_t j = 0;
		for ( ; j < SIZE_OF_UID; i++, j++)
		{
			L4FLASH_WriteEntry(i, UID[j]);
		}
		val = 1;
		SetUIDStr();
		ResetUIDFlag();
	}
	return val;
}

uint8_t GetUIDFlag()
{
	return UIDFlag;
}

void WriteUIDPassword(uint16_t password)
{
	if (password == UID_UNLOCK)
	{
		UIDFlag = 1;
	}
}

void ResetUIDFlag()
{
	UIDFlag = 0;
}

void SetSerialUpdateFlag(void)
{
	serial_flash_update = 1;
}

static void SetUIDStr( void )
{
	snprintf(unique_id_str, UNIQUE_ID_STR_LENGTH, "%04X-%04X-%04X-%04X", 
	         (uint16_t)(UID[0] | UID[1] << 8),
	         (uint16_t)(UID[2] | UID[3] << 8),
	         (uint16_t)(UID[4] | UID[5] << 8),
	         (uint16_t)(UID[6] | UID[7] << 8));
}

char * GetUIDStr( void )
{
	return unique_id_str;
}
