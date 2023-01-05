/*
  ******************************************************************************
  * File Name          : projectDefs.h
  * Description        : This file defines options that are typically resolved at build-time,
  * such as debugging features.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
#ifndef PROJECTDEFS_H_
#define PROJECTDEFS_H_

#define FW_MAJOR_VERSION				1
#define FW_MINOR_VERSION				0

#define USE_DEBUG_PRINTF				0
#define TEST_CONFIGURATION			0

#define DEBUG_POLLING						0
#define DEBUG_MODBUS						0
#define DEBUG_LEDS							0
#define DEBUG_AUTOADDRESS				0

#define FAKE_INPUTS							0
#define DISABLE_MODBUS					0
#define DISABLE_AUTOADDRESS			0

// If you want to hard-code a serial number, uncomment this and set it accordingly.
#define HARD_CODED_SERIAL_NUMBER	{0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x0b, 0x13}

#define NUM_DISC_OUTPUTS 8
#define NUM_BITS_PER_BYTE 8

#define UNREFERENCED_PARAMETER(x) (void)x

#define HIGH_BYTE_OF_WORD(x)    ((uint8_t)((x >> 8) & 0x00FF))
#define LOW_BYTE_OF_WORD(x)     ((uint8_t)(x & 0x00FF))


#endif /* PROJECTDEFS_H_ */
