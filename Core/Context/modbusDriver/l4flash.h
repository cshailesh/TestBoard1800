#ifndef L4FLASH_H_
#define L4FLASH_H_

#include "stm32g0xx_hal.h"
#include "uid.h"
#include "EEPROM_Emul/Core/eeprom_emul.h"
#include "projectDefs.h"

#define PROJECT_ID_VAL			14

#define NUM_OUTPUT_BYTES (NUM_DISC_OUTPUTS / 8 + (_Bool)(NUM_DISC_OUTPUTS % 8))
#define NUM_BITS_PER_BYTE		8
//60 seconds
#define FAILSAFE_LIMIT 60 * 1000
#define SIZE_OF_UID 8


enum flashEntry_t {
	// Each entry is stored as a 16-bit half word
	FLASH_INITIALIZED = 1,
	FLASH_MODBUS_ADDR,

	FLASH_START_CHANNEL,
	FLASH_END_CHANNEL,

	FLASH_FAIL_SAFE_START,
	FLASH_FAIL_SAFE_END = FLASH_FAIL_SAFE_START + NUM_OUTPUT_BYTES - 1,

	FLASH_UID_START,
	FLASH_UID_END = FLASH_UID_START + SIZE_OF_UID - 1,
	// Used only as markers
	FLASH_FIRST_ENTRY = FLASH_INITIALIZED,
	FLASH_LAST_ENTRY = FLASH_UID_END,
	FLASH_NUM_ENTRIES = FLASH_LAST_ENTRY,
};

#define NUM_OF_VAR               ((uint8_t)FLASH_NUM_ENTRIES)	// See enum flashEntry_t

void L4FLASH_Init(void);
EE_Status L4FLASH_WriteEntry(enum flashEntry_t entry, uint8_t data);
EE_Status L4FLASH_ReadEntry(enum flashEntry_t entry, uint8_t* pData);
void L4FLASH_Reset(void);

#endif /* L4FLASH_H_ */
