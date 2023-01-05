/*
 * portserial.c
 *
 *  Created on: May 1, 2019
 *      Author: wayne
 */
/*
#include "stdio.h"
#include "string.h"
*/
#include "main.h"
//#include "stm32f10x.h"
#include "port.h"
#include "mbport.h"
#include "mb.h"
///#include "led.h"

/* ----------------------- static functions ---------------------------------*/
static void prvvUARTTxReadyISR( void );
static void prvvUARTRxISR( void );
//#include "link4_stm32f10x_usart.h"

typedef struct{
    uint8_t bIsRxEnabled;
    uint8_t bIsTxEnabled;
}xMBPSerialIntHandle;

xMBPSerialIntHandle serial;

UCHAR test[256];
void SetPortTxEmptyInt(_Bool bEnable)
{
	if (bEnable)
	{
		//SET_BIT(huart3.Instance->CR1, USART_CR1_TXEIE_TXFNFIE);
		__HAL_UART_ENABLE_IT(&huart3, UART_IT_TXE);
	}
	else
	{
		__HAL_UART_DISABLE_IT(&huart3, UART_IT_TXE);
		//CLEAR_BIT(huart3.Instance->CR1, USART_CR1_TXEIE_TXFNFIE);
	}
}

void SetPortTxCompleteInt(_Bool bEnable)
{
	bEnable ?
		__HAL_UART_ENABLE_IT(&huart3, UART_IT_TC) :
		__HAL_UART_DISABLE_IT(&huart3, UART_IT_TC);
}

void SetPortRxNotEmptyInt(_Bool bEnable)
{
	bEnable ?
		__HAL_UART_ENABLE_IT(&huart3, UART_IT_RXNE) :
		__HAL_UART_DISABLE_IT(&huart3, UART_IT_RXNE);
}

BOOL xMBPortSerialInit( UCHAR ucPort, ULONG ulBaudRate, UCHAR ucDataBits, eMBParity eParity)
{
	
	// Initializes the USART peripheral
	// Registers the USART interrupt
	//TODO: macro for ucPort or if/else to get it into huart3.Instance
	UNUSED(ucPort);//USART1 only for now.
	//UNREFERENCED_PARAMETER(eParity);//TODO:05052019 Wayne to check Link4 protocol if any eParity used

	huart3.Instance = USART3;
	huart3.Init.BaudRate = 19200;
	huart3.Init.WordLength = UART_WORDLENGTH_8B; //UART_WORDLENGTH_8B
	huart3.Init.StopBits = UART_STOPBITS_1;
	huart3.Init.Parity = UART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_TX_RX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;
	huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart3.Init.ClockPrescaler = UART_PRESCALER_DIV1;
	huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT;
	huart3.AdvancedInit.OverrunDisable = UART_ADVFEATURE_OVERRUN_DISABLE;
	//huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT;
	//huart3.AdvancedInit.OverrunDisable = UART_ADVFEATURE_OVERRUN_DISABLE;

	//IRQ setup in this function call

	//initializes the rs485 driver according to specified paramters
	//calls HAL_UART_MspInit which sets up interrupt vectors
	//sets driver enable bit so pin works properly
	//sets the driver enable assertion/deassertion times
	//enables peripheral
	//no need to disable interrupts - not set until HAL_UART_RECEIVE_IT called?
	//if (HAL_RS485Ex_Init(&huart3, UART_DE_POLARITY_HIGH, 0, 0) != HAL_OK)
	if (HAL_UART_Init(&huart3) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_UARTEx_DisableFifoMode(&huart3) != HAL_OK)
	{
		Error_Handler();
	}

	//TX callback
	HAL_UART_RegisterCallback(&huart3, HAL_UART_TX_COMPLETE_CB_ID, (pUART_CallbackTypeDef)prvvUARTTxReadyISR);
	//RX callback
	HAL_UART_RegisterCallback(&huart3, HAL_UART_RX_COMPLETE_CB_ID, (pUART_CallbackTypeDef)prvvUARTRxISR);
	
	SetPortTxEmptyInt( DISABLE );

	return TRUE;
}

//TODO:05052019 WAYNE to think about what should add here. I am very clear
// what situation we need call this. Modbus communication issues?
void vMBPortSerialClose( void )
{

}

void vMBPortSerialEnable(BOOL xRxEnable, BOOL xTxEnable)
{
	if(xRxEnable)
	{
		SetPortRxNotEmptyInt(ENABLE);		
	}
	else
	{
		//LED_SetOff(LED2);
		SetPortRxNotEmptyInt( DISABLE);
	}	
	if(xTxEnable)
	{

		SetPortTxEmptyInt( ENABLE );
		HAL_GPIO_WritePin(USART3_DE_GPIO_Port, USART3_DE_Pin, GPIO_PIN_SET);

	}
	else
	{
		//LED_SetOff(LED1);
		HAL_GPIO_WritePin(USART3_DE_GPIO_Port, USART3_DE_Pin, GPIO_PIN_RESET);
		SetPortTxEmptyInt( DISABLE );


	}
}


//we changed the modbus library here - put the entire packet and let the peripheral do the work
BOOL xMBPortSerialPutByte( CHAR ucByte)
{
	//LED_SetOn(LED1);
	huart3.Instance->TDR = ucByte;
	return TRUE;
}

//this function called as response to callback when an RX interrupt is generated
BOOL xMBPortSerialGetByte( CHAR * pucByte )
{
	//LED_SetOn(LED2);
	*pucByte = (uint8_t)(huart3.Instance->RDR & (uint8_t)0x00FF);
	return TRUE;
	/*
	if (HAL_UART_Receive_IT(&huart3, (uint8_t *)pucByte, 1) == HAL_OK)
		return TRUE;
	else
		return FALSE;
	*/
}

/* Create an interrupt handler for the transmit buffer empty interrupt
 * (or an equivalent) for your target processor. This function should then
 * call pxMBFrameCBTransmitterEmpty( ) which tells the protocol stack that
 * a new character can be sent. The protocol stack will then call
 * xMBPortSerialPutByte( ) to send the character.
 */
static void prvvUARTTxReadyISR( void )
{
	pxMBFrameCBTransmitterEmpty( );
}

/* Create an interrupt handler for the receive interrupt for your target
 * processor. This function should then call pxMBFrameCBByteReceived( ). The
 * protocol stack will then call xMBPortSerialGetByte( ) to retrieve the
 * character.
 */
static void prvvUARTRxISR( void )
{
	pxMBFrameCBByteReceived( );
	//set up the interrupt again
	SET_BIT(huart3.Instance->CR1, USART_CR1_RXNEIE_RXFNEIE);
}
