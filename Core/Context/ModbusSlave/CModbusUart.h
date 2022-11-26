#ifndef CONTEXT_MODBUSSLAVE_CMODBUSUART_H_
#define CONTEXT_MODBUSSLAVE_CMODBUSUART_H_

//#define RS485_TX_ENABLE()   //HAL_GPIO_WritePin(MODBUS_RT_PORT,MODBUS_RT_PIN,GPIO_PIN_SET);
//#define RS485_RX_ENABLE()   //HAL_GPIO_WritePin(MODBUS_RT_PORT,MODBUS_RT_PIN,GPIO_PIN_RESET);

#define RXBF_DADDR_INDEX 0
#define RXBF_FUCT_INDEX  1
#define RXBF_ADDR_INDEX  2
#define RXBF_QUAN_INDEX  4
#define RXBF_SCVAL_INDEX  4
#define RXBF_BYTECOUNT_INDEX  6

#define  T1_5_2400BR 69          /* 2400 Baudrate i�in 1.5T 6.9ms*/
#define  T3_5_2400BR 161         /* 2400 Baudrate i�in 3.5T 16.1ms*/
#define  T1_5_4800BR 35          /* 4800 Baudrate i�in 1.5T 3.5ms*/
#define  T3_5_4800BR 81          /* 4800 Baudrate i�in 3.5T 8.1ms*/
#define  T1_5_9600BR 18          /* 9600 Baudrate i�in 1.5T 1.8ms*/
#define  T3_5_9600BR 41          /* 9600 Baudrate i�in 3.5T 4.1ms*/
#define  T1_5_19200BR 9          /* 19200 Baudrate i�in 1.5T 0.9ms*/
#define  T3_5_19200BR 21         /* 19200 Baudrate i�in 3.5T 2.1ms*/
#define  T1_5_HSPEED  7          /* 19200 Baudrate �st� i�in 1.5T 0.7ms*/
#define  T3_5_HSPEED 18          /* 19200 Baudrate �st� i�in 3.5T 1.8ms*/

typedef enum
{
	BR_2400, BR_4800, BR_9600, BR_19200, BR_38400, BR_56000, BR_115200
} eMB_BAUD_RATE;

typedef enum
{
	PR_EVEN = 0, PR_ODD, PR_NONE
} eMB_UART_PARITY;

typedef enum
{
	STOP_1 = 0, STOP_2
} eMB_UART_STOP_BIT;


void baudRateSet(MODBUS_DATA_t *m_t, eMB_BAUD_RATE Baud_rate);

#endif /* CONTEXT_MODBUSSLAVE_CMODBUSUART_H_ */
