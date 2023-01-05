#ifndef UID_H 
#define UID_H

#include <stdint.h>
#include "main.h"

void InitUID();
uint8_t GetUID(uint8_t idx);
void SetUID(uint8_t idx, uint8_t val);

void ReadUIDFromFlash();
uint8_t CheckWriteUIDToFlash();

uint8_t GetUIDFlag();

void WriteUIDPassword(uint16_t password);
void ResetUIDFlag();
void SetSerialUpdateFlag(void);
char * GetUIDStr( void );
#endif /* UID_H */
