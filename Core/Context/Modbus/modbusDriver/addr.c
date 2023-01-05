#include "addr.h"
#include "l4flash.h"


static uint8_t addr = 0;
static uint8_t addr_flag;
void InitAddress(void)
{ 
	addr_flag = 0;
	ReadAddressFromFlash();
}

uint8_t AddressGet(void)
{
	//TODO fix
	//return 2;
	return addr;
}

void AddressSet(uint8_t address)
{
	addr = address;
}

void ReadAddressFromFlash()
{	
	L4FLASH_ReadEntry(FLASH_MODBUS_ADDR, &addr);
}

//if the address got updated, update value in flash
uint8_t CheckWriteAddressToFlash()
{
	uint8_t val = 0;
	if(addr_flag)
	{
		addr_flag = 0;
		L4FLASH_WriteEntry(FLASH_MODBUS_ADDR, addr);
		val = 1;
	}
	return val;
}

void SetAddressUpdateFlag(void)
{
	addr_flag = 1;
}

