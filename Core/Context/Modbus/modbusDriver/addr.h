#ifndef ADDR_H_
#define ADDR_H_

#include <stdint.h>

void InitAddress(void);

uint8_t AddressGet(void);
void AddressSet(uint8_t address);

void ReadAddressFromFlash();
uint8_t CheckWriteAddressToFlash();

void SetAddressUpdateFlag(void);
#endif /* ADDR_H_ */
