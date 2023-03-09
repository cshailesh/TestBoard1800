#include "rng.h"
#include "projectDefs.h"
#include <stdlib.h>

#define HAS_RANGE UINT_MAX

static uint32_t random_number = 0;

uint32_t Hash (char *str)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c;
	}
	return (unsigned int)(hash);
}

void InitRNG(char *str)
{
	int random_seed = Hash(str);
	srand(random_seed);
	UpdateRandomNumber();
}

void UpdateRandomNumber()
{
	random_number = rand();
}

uint32_t GetRandomNumber()
{
	return random_number;
}
