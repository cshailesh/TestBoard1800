#ifndef RNG_H
#define RNG_H

#include <stdint.h>

void InitRNG(char *str);
uint32_t Hash (char *str);
void UpdateRandomNumber();
uint32_t GetRandomNumber();

#endif /* RNG_H */
