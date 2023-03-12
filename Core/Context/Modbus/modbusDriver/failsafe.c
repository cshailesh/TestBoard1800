#include "failsafe.h"
#include "stm32g0xx_hal.h"
#include "main.h"
#include "DigitalOut.h"
#include "l4flash.h"

static uint32_t failsafe_timer = 0;
static uint8_t restore_relay_flag = 0;
static uint8_t previousRelayState[NUM_OUTPUT_BYTES] = { 0 };

//void SetFailsafe( void )
//{
//	uint8_t temp[NUM_OUTPUT_BYTES];
//	//save previous relay expansion state
//	GetRelays(&previousRelayState[0], 0, NUM_DISC_OUTPUTS);
//
//	for (uint8_t i = 0; i < NUM_OUTPUT_BYTES; i++)
//	{
//		L4FLASH_ReadEntry(FLASH_FAIL_SAFE_START + i, &temp[i]);
//	}
//	SetRelays(&temp[0], 0, NUM_DISC_OUTPUTS);
//
//	//on communication restart, restore previous configuration
//	//if the next command sets the relays, this flag will be unset
//	restore_relay_flag = 1;
//}
//
//void WriteFailsafe(uint8_t idx, uint8_t val)
//{
//	uint8_t num_failsafe_bytes = FLASH_FAIL_SAFE_END - FLASH_FAIL_SAFE_START + 1;
//
//	if (idx < num_failsafe_bytes)
//		L4FLASH_WriteEntry(FLASH_FAIL_SAFE_START + idx, val);
//}
//
//uint8_t GetFailsafe(uint8_t idx)
//{
//	uint8_t val = 0;
//	uint8_t num_failsafe_bytes = FLASH_FAIL_SAFE_END - FLASH_FAIL_SAFE_START + 1;
//
//	if (idx < num_failsafe_bytes)
//		L4FLASH_ReadEntry(FLASH_FAIL_SAFE_START + idx, &val);
//
//	return val;
//}
//
//void RestoreRelays( void )
//{
//	SetRelays(previousRelayState, 0, NUM_DISC_OUTPUTS);
//	for (uint8_t i = 0; i < NUM_OUTPUT_BYTES; i++)
//		previousRelayState[i] = 0;
//	restore_relay_flag = 0;
//}
//

//called on successful modbus comms
void UpdateFailsafeTimer()
{
	failsafe_timer = HAL_GetTick();
}

uint32_t GetFailsafeTimer()
{
	return failsafe_timer;
}

//uint8_t CheckFailsafeTimer()
//{
//	uint8_t val = 0;
//	if ( (HAL_GetTick() - failsafe_timer > FAILSAFE_LIMIT ))
//	{
//		if (!restore_relay_flag)
//			SetFailsafe();
//		val = 1;
//	}
//	else
//	{
//		if (restore_relay_flag)
//			RestoreRelays();
//	}
//	return val;
//}
//

//void ClearRestoreRelayFlag()
//{
//	restore_relay_flag = 0;
//}
