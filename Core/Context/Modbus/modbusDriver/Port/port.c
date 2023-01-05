/*
 * port.c
 *
 *  Created on: May 11, 2019
 *      Author: wayne
 */
 
//don't think this is needed
#include <stdlib.h>
#include "port.h"
#define portNVIC_INT_CTRL_REG		( * ( ( volatile uint32_t * ) 0xe000ed04 ) )
/* Masks off all bits but the VECTACTIVE bits in the ICSR register. */
#define portVECTACTIVE_MASK					( 0xFFUL )
//static uint32_t uxCriticalNesting = 0;

void vPortEnterCritical( void )
{

//	uxCriticalNesting++;
//
//	/* This is not the interrupt safe version of the enter critical function so
//	assert_param() if it is being called from an interrupt context.  Only API
//	functions that end in "FromISR" can be used in an interrupt.  Only assert if
//	the critical nesting count is 1 to protect against recursive calls if the
//	assert function also uses a critical section. */
//	if( uxCriticalNesting == 1 )
//	{
//		assert_param( ( portNVIC_INT_CTRL_REG & portVECTACTIVE_MASK ) == 0 );
//	}
//
//	__disable_irq();
}
/*-----------------------------------------------------------*/

void vPortExitCritical( void )
{
//	assert_param( uxCriticalNesting );
//	uxCriticalNesting--;
//	if( uxCriticalNesting == 0 )
//	{
//		__enable_irq();
//	}
	
}
