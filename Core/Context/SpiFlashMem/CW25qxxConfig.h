#ifndef _W25QXXCONFIG_H
#define _W25QXXCONFIG_H
#include <ConHeader.h>

#define		_W25QXX_SPI			hspi1

//#define		_W25QXX_CS_GPIO		SPI_FRAM_GPIO_Port
//#define		_W25QXX_CS_PIN		SPI_FRAM_Pin

#define		_W25QXX_CS_GPIO		FRAM_CS_GPIO_Port
#define		_W25QXX_CS_PIN		FRAM_CS_Pin

#define		_W25QXX_USE_FREERTOS		0
#define		_W25QXX_DEBUG				0

#endif

