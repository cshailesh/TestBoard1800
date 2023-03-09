

#ifndef CONTEXT_HEADER_H_
#define CONTEXT_HEADER_H_

#include "main.h"
#include "stdio.h"
#include "stdint.h"

//-------- C'S ----------------------------------------------
#include "projectDefs.h"
#include <CDeviceDataTypes.h>
#include "ConHalConfig.h"
#include "modbusDriver/include/mb.h"
//
//#include "CModBusData.h"
//#include "CModbusCrc.h"
//#include "CModbusTiming.h"
//#include "CModbusUart.h"
//#include "CModbusSlave.h"
//

#include "l4flash.h"
#include "rng.h"
#include "addr.h"
#include "failsafe.h"
#include "CW25qxx.h"

//-------- CON'S ----------------------------------------------
#include <ConData.h>
#include <DigitalOut.h>
#include <DigitalOutPort.h>
#include <Keyboard.h>
#include <KeyboardPort.h>
#include <LedPort.h>
#include <LED.h>
#include <Pwm.h>
#include "ConModbusSlave.h"
#include "ConFlashMem.h"


#endif /* CONTEXT_HEADER_H_ */
