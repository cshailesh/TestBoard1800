#ifndef _PORT_H
#define _PORT_H
#include <stdint.h>
//needed for __disable_irq / __enable_irq
#include "stm32g0xx_hal.h"

extern UART_HandleTypeDef huart3;
extern TIM_HandleTypeDef htim6;

//extern void vPortEnterCritical( void );
//extern void vPortExitCritical( void );

//use BASE_PRI here instead?
#define ENTER_CRITICAL_SECTION( )     (__disable_irq())
#define EXIT_CRITICAL_SECTION( )      (__enable_irq())



typedef   uint8_t	BOOL;
typedef   uint16_t	USHORT;
typedef   char 		CHAR;
typedef   unsigned char   UCHAR;
typedef   unsigned long   ULONG;

#ifndef TRUE
#define TRUE                           ( BOOL )1
#endif

#ifndef FALSE
#define FALSE                          ( BOOL )0
#endif

#endif
