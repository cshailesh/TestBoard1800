#ifndef FAILSAFE_H
#define FAILSAFE_H

#include <stdint.h>
#include <stdbool.h>
#include "main.h"

void SetFailsafe( void );
void WriteFailsafe(uint8_t idx, uint8_t val);
uint8_t GetFailsafe(uint8_t idx);
void RestoreRelays( void );

void UpdateFailsafeTimer();
uint32_t GetFailsafeTimer();

uint8_t CheckFailsafeTimer();

void ClearRestoreRelayFlag();
#endif /* FAILSAFE_H */
