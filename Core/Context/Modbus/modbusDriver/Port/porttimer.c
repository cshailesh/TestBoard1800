//#include <stdlib.h>
/* ----------------------- Platform includes --------------------------------*/
#include "port.h"
#include "stm32g0xx.h"
/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"
#include "main.h"

static void prvvTIMERExpiredISR( void );

USHORT timeout;
BOOL xMBPortTimersInit( USHORT usTim1Timerout50us )
{	

	long timerClock = 32000000;
	long prescaler = 32;
	long period = ( (timerClock * usTim1Timerout50us * 50E-6)  / prescaler);
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	htim6.Instance = TIM6;
	htim6.Init.Prescaler = prescaler - 1;
	htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim6.Init.Period = period - 1;
	htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
	{
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
	{
		Error_Handler();
	}
//#todo
	HAL_TIM_RegisterCallback(&htim6, HAL_TIM_PERIOD_ELAPSED_CB_ID, (pTIM_CallbackTypeDef)prvvTIMERExpiredISR);
	return TRUE;
}

inline void
vMBPortTimersEnable(  )
{	
	__HAL_TIM_SET_COUNTER(&htim6, 0);
	HAL_TIM_Base_Start_IT(&htim6);
	//set counter value to 0 - this is also used to refresh the timer on successfull RX read
}

inline void
vMBPortTimersDisable(  )
{
	HAL_TIM_Base_Stop_IT(&htim6);
}


/* Create an ISR which is called whenever the timer has expired. This function
 * must then call pxMBPortCBTimerExpired( ) to notify the protocol stack that
 * the timer has expired.
 */
static void prvvTIMERExpiredISR( void )
{
    ( void )pxMBPortCBTimerExpired(  );	
}

/*
void vModbusTickHook( void )
{
	if(modbusTimer.status == MODBUS_TIME_START)
	{
		modbusTimer.usNTimeLeft--;
		if(modbusTimer.usNTimeLeft == 0) // modbus time out
		{			
			modbusTimer.status=MODBUS_TIME_STOP;			
			modbusTimer.usNTimeLeft = modbusTimer.usNTimeOutMS ;
			pxMBPortCBTimerExpired();
		}
	}
}
*/

