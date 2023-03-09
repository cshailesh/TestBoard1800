#ifndef PORT_TIMER_H

#include "port.h"

typedef enum{
	MODBUS_TIME_UNINITIALIZED,
	MODBUS_TIME_START,
	MODBUS_TIME_STOP
}xTimeStatus;

typedef struct
{   
	volatile uint32_t usNTimeLeft;
    uint32_t usNTimeOutMS;
	xTimeStatus status;
} xTimerInternalHandle;

void vModbusTickHook( void );

#endif

