
#ifndef CONTEXT_MODBUSSLAVE_CMODBUS_TIMING_H_
#define CONTEXT_MODBUSSLAVE_CMODBUS_TIMING_H_

#include "ConHeader.h"


typedef struct
{
	uint16_t mComCount;
	uint16_t mComNewIDCount;
	uint8_t mIsComminicated;
	uint8_t mStartnewIDProcess;
} MODBUS_TIMING_t;

//#define CHECK_5_MINUTES 	300000U // 5min // this macro for the communication check
#define CHECK_5_MINUTES 	10000U // 10sec for the test
#define CHECK_20_SECONDS	20000U // 20sn // this macro for the newID process period check

void modbusFrameWait(MODBUS_DATA_t *pMb);
void newFrameWait(MODBUS_DATA_t *pMb);
void modbusFrameControl(MODBUS_DATA_t *pMb, uint8_t Device_address);


#endif /* CONTEXT_MODBUSSLAVE_CMODBUSCRC_H_ */
