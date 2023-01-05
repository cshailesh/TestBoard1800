#include "l4flash.h"

__IO uint32_t ErasingOnGoing = 0;

void L4FLASH_Init(void)
{
	EE_Status ee_status = EE_OK;
	uint8_t val = 0;
	//check integrity of flash
	HAL_NVIC_SetPriority(FLASH_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(FLASH_IRQn);

	HAL_FLASH_Unlock();
	__HAL_FLASH_ENABLE_IT(FLASH_IT_ECCC);

	/* Set EEPROM emulation firmware to erase all potentially incompletely erased
     pages if the system came from an asynchronous reset. Conditional erase is
     safe to use if all Flash operations where completed before the system reset */
	if(__HAL_PWR_GET_FLAG(PWR_FLAG_SB) == RESET)
	{    
		/* System reset comes from a power-on reset: Forced Erase */
		/* Initialize EEPROM emulation driver (mandatory) */
		ee_status = EE_Init(EE_FORCED_ERASE);
		if(ee_status != EE_OK) {Error_Handler();}
	}
	else
	{
		/* Clear the Standby flag */
		__HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB);
		ee_status = EE_Init(EE_CONDITIONAL_ERASE);
		if(ee_status != EE_OK) {Error_Handler();}
	}

	//if flash isn't initialized, set default values 
	// and write to flash. otherwise, read from flash into ram
	ee_status = EE_ReadVariable8bits(FLASH_INITIALIZED, &val);
	if (val == 0)
	{
		//load default values into flash
		L4FLASH_Reset();
	}

    //HAL_FLASH_Lock();   
}

EE_Status L4FLASH_WriteEntry(enum flashEntry_t entry, uint8_t data)
{
	// To prevent excessive writes, check if the data to write is different from what is stored
	uint8_t temp;
	EE_Status status = L4FLASH_ReadEntry(entry, &temp);
	if (status == 0 && temp == data)
		return EE_OK;

	return EE_WriteVariable8bits(entry, data);
}

EE_Status L4FLASH_ReadEntry(enum flashEntry_t entry, uint8_t* pData)
{
	// Same return values as EE_ReadVariable()
	return EE_ReadVariable8bits(entry, pData);
}

void L4FLASH_Reset(void)
{
	EE_Status ee_status = EE_OK;

	ee_status |= EE_WriteVariable8bits(FLASH_INITIALIZED, 1);
	for (uint8_t i = FLASH_FAIL_SAFE_START; i <= FLASH_FAIL_SAFE_END; i++)
	{
		//default fail off
		ee_status |= EE_WriteVariable8bits(i, 0);
	}

	for (uint8_t i = FLASH_START_CHANNEL; i <= FLASH_END_CHANNEL; i++)
		ee_status |= EE_WriteVariable8bits(i, 0xFF);
		
	ee_status |= EE_WriteVariable8bits(FLASH_MODBUS_ADDR, 230);

	for (uint8_t i = FLASH_UID_START; i <= FLASH_UID_END; i++)
	{
		ee_status |= EE_WriteVariable8bits(i, 0xFF); 
	}

	if ((ee_status & EE_STATUSMASK_CLEANUP) == EE_STATUSMASK_CLEANUP) 
		{
			ErasingOnGoing = 0;
			ee_status|= EE_CleanUp();
		}
    if ((ee_status & EE_STATUSMASK_ERROR) == EE_STATUSMASK_ERROR) {Error_Handler();}
}

