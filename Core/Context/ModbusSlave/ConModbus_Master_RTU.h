#ifndef __MODBUS_MASTER_RTU_H
#define __MODBUS_MASTER_RTU_H

#include "ContextHeader.h"


#define MAX_MB_BUFFER_SIZE 200
#define HOLDING_REGISTER_SIZE 10


typedef union
{
 uint16_t genIO;
 struct
 {
	 uint8_t bit0 : 1;
	 uint8_t bit1 : 1;
	 uint8_t bit2 : 1;
	 uint8_t bit3 : 1;
 }bits;

}tGenIO;

typedef union
{
 uint16_t MultipleDiscrete;
 struct
 {
	 uint8_t bit0 : 1;
	 uint8_t bit1 : 1;
	 uint16_t reserved :14;
 }bits;

}tMultipleDiscrete;

typedef union
{
 uint16_t FailSafe;
 struct
 {
	 uint8_t bit0 : 1;
	 uint8_t bit1 : 1;
	 uint16_t reserved :14;
 }bits;

}tFailSafe;

extern tMultipleDiscrete MultipleDiscrete ;
extern tFailSafe FailSafe ;
extern tGenIO GenericIO;

extern uint16_t Holding_register[HOLDING_REGISTER_SIZE];
extern int16_t temperatureVal ;


#define MbTypecastAddress uint32_t /* 32 bit adreslemeli i�lemci i�in */    


/*Modbus RX datas�n�n ge�erli olabilmesi i�in al�nmas� gerekli minimum byte ----
  say�s� = 1 Byte cihaz adresi + 1byte fonksiyon kodu + 2Byte CRC 
------------------------------------------------------------------------------*/
#define MIN_RX_BYTE_NUMBER 4 
/*----------------------------------------------------------------------------*/
#define LITTLE_ENDIAN  1234
/*--------------------------MASTER DEFINATIONS------------------------------*/


#define MASTER_READ_DEVICE_ADRESS_INDEX       0x0
#define MASTER_READ_FUNC_INDEX                0x1
#define MASTER_RX_DATA_COUNT_INDEX            0x2
#define MASTER_READ_COIL_DATA_ADRES_0         0x3
#define MASTER_READ_DISCRETE_DATA_ADRES_0     0x3
#define MASTER_READ_INPUT_DATA_ADRES_0        0x3
#define MASTER_READ_HOLDING_DATA_ADRES_0      0x3


#define MASTER_CRC_HARICI_H_I_SABIT_BYTE_SAYISI     0x3  // Holding ve �nput Register icin
#define MASTER_CRC_HARICI_C_D_BYTE_SAYISI     0x4  // Coil ve Discrete Register icin

#define HARDWARE_FLOW_CONTROL_ON  1
#define HARDWARE_FLOW_CONTROL_OFF 0

/*-- MODBUS BIT ACCESS FUNCTION CODES ----------------------------------------*/
#define MODBUS_FUNC_READ_COIL_STATUS			0x01
#define MODBUS_FUNC_READ_INPUT_STATUS			0x02
#define MODBUS_FUNC_WRITE_SINGLE_COIL			0x05
#define MODBUS_FUNC_WRITE_MULTIPLE_COILS		0x0F
/*-- MODBUS 16 BITS ACCESS FUNCTION CODES ------------------------------------*/
#define MODBUS_FUNC_READ_HOLDING_REGISTERS		0x03
#define MODBUS_FUNC_READ_INPUT_REGISTERS		0x04
#define MODBUS_FUNC_WRITE_SINGLE_REGISTER		0x06
#define MODBUS_FUNC_WRITE_MULTIPLE_REGISTERS	        0x10

//#define RS485_TX_ENABLE()   //HAL_GPIO_WritePin(MODBUS_RT_PORT,MODBUS_RT_PIN,GPIO_PIN_SET);
//#define RS485_RX_ENABLE()   //HAL_GPIO_WritePin(MODBUS_RT_PORT,MODBUS_RT_PIN,GPIO_PIN_RESET);

#define RXBF_DADDR_INDEX 0
#define RXBF_FUCT_INDEX  1
#define RXBF_ADDR_INDEX  2
#define RXBF_QUAN_INDEX  4
#define RXBF_SCVAL_INDEX  4
#define RXBF_BYTECOUNT_INDEX  6

/*-- 1.5 VE 3.5 KARAKTER ZAMANLARI TANIMLAMALARI ---100US TIME BASE ���N -----*/
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

typedef enum {
	BR_2400, BR_4800, BR_9600, BR_19200, BR_38400, BR_56000, BR_115200
} BR_define_td;
typedef enum {
	PR_EVEN = 0, PR_ODD, PR_NONE
} Parite_define_td;
typedef enum {
	STOP_1 = 0, STOP_2
} Stop_bit_define_td;


typedef enum{
  MB_FUNCTION_ERROR = 0x01,
  MB_ADDRES_ERROR,
  MB_QUANTITY_ERROR,
  MB_FUNCTION_RUN_ERROR 
}Exception_define_td;
/*-- Modbus_status bit tan�mlamalar� -----------------------------------------*/
typedef enum{
  MB_STATUS_CLEAR =0x0,
  MB_RX_RUN = 0x01,
  MB_RX_FRAME_END = 0x02,
  MB_TX_RUN = 0x04,
  MB_BROADCASTS = 0x40,
  MB_WR_ENABLE = 0x80
}Mb_status_td;
/*---MODBUS MASTER GENEL TANIMLAMALARI----------------------------------------*/
typedef enum
{
  Read_Coil_e=0x01,
  Read_Discrete_e=0x02,
  Read_Holding_e=0x03,
  Read_Input_e=0x04
  
}ReadReg_TypeDef;

typedef enum
{
  Write_Coil_e=0x05,
  Write_Holding_e=0x06,
  
  
  
}WriteReg_TypeDef; 
typedef enum  // International Rules
{
 NO_ERROR_e ,
 Illegal_Function_e = 1 ,
 Illegal_Data_Address_e ,
 Illegal_Data_Value_e ,
 Slave_Device_Failure_e,
 Acknowledge_e,
 Slave_Device_Busy_e,
 Negative_Acknowledge_e,
 Memory_Parity_Error_e,
 Gateway_Path_Unavailable_e= 10 ,
 Gateway_Target_Device_Failed_to_Respond_e = 11
 

}Modbus_ERROR_Codes;

typedef union
{
	uint32_t Coil_Reg;
	struct
	{
		uint8_t bit0 : 1 ;
		uint8_t bit1 : 1 ;
		uint8_t bit2 : 1 ;
		uint8_t bit3 : 1 ;
		uint8_t bit4 : 1 ;
		uint8_t bit5 : 1 ;
		uint8_t bit6 : 1 ;
		uint8_t bit7 : 1 ;
		uint8_t bit8 : 1 ;
		uint8_t bit9 : 1 ;
		uint8_t bit10 : 1 ;
		uint8_t bit11 : 1 ;
		uint8_t bit12 : 1 ;
		uint8_t bit13 : 1 ;
		uint8_t bit14 : 1 ;
		uint8_t bit15 : 1 ;
		uint8_t bit16 : 1 ;
		uint8_t bit17 : 1 ;
		uint8_t bit18 : 1 ;
		uint8_t bit19 : 1 ;
		uint8_t bit20 : 1 ;
		uint8_t bit21 : 1 ;
		uint8_t bit22 : 1 ;
		uint8_t bit23 : 1 ;
		uint8_t bit24 : 1 ;
		uint8_t bit25 : 1 ;
		uint8_t bit26 : 1 ;
		uint8_t bit27 : 1 ;
		uint8_t bit28 : 1 ;
		uint8_t bit29 : 1 ;
		uint8_t bit30 : 1 ;
		uint8_t bit31 : 1 ;
	}bits;

}coilRegs_t;

typedef struct
{
uint8_t           Sorgu_Adresi;
uint16_t          Sorgu_Reg_Adresi;
ReadReg_TypeDef   Sorgu_Tipi;
int16_t           Sorgu_Data;
uint8_t           Hata_Durumu;
uint8_t           Hata_Sayaci;
}Modbus_Master_Sorgu_Pkt;


//----------------------------------------------------------------------------*/  
/*-- MODBUS REG�STER F�Z�KSEL ADRES VE SAYILARI TABLOSUNUN YAPISI ------------*/
typedef struct{
  uint16_t  MbStarting_address;         /*Modbus start adresi */
  MbTypecastAddress  PhisicalCoils_address;      /*Coil fiziksel start adresi */
  MbTypecastAddress  PhisicalDiscrates_address;  /*Discrates fiziksel start adresi */
  MbTypecastAddress  PhisicalInputs_address;     /*Inputs fiziksel start adresi */
  MbTypecastAddress  PhisicalHoldings_address;   /*Holdings fiziksel start adresi */
  uint16_t  Coils_quantity;             /*Maksimum Coil say�s� */        
  uint16_t  Discrates_quantity;         /*Maksimum Discrates input say�s� */
  uint16_t  Inputs_quantity;            /*Maksimum Inputs register say�s� */
  uint16_t  Holdings_quantity;          /*Maksimum Holding register say�s� */
}MB_range_td;  

typedef enum
{
	Modbus_Slave,
	Modbus_Master,
}ModbusType;

typedef struct{
  uint8_t *MBpointer;
  uint8_t MB_index;
  uint8_t MB_byte_count;
}Mb_buffer_td;

typedef struct
{
	int16_t down_limit;
	int16_t up_limit;


}MB_Holding_Limit;

typedef struct
{
	ModbusType modbusType;
	uint8_t HardwaveFlow;
	uint8_t RX_Data;
	uint8_t  ModbusBuffer[MAX_MB_BUFFER_SIZE]; //[MAX_VAR_NUMBER*2 + 8];   /*Al�nan/G�nderilen frame in kaydedildi�i buffer*/
	Mb_buffer_td MB_registers;
	uint8_t Frame_start_timer;
	uint32_t Phisical_address;
	uint16_t Max_quantity;
	uint16_t Received_quantity;
	uint8_t Time1_5,Time3_5,CRCLo,CRCHi;
	const MB_range_td *pLimit_vals_table;
	uint8_t Bit_mask,Bit_wr_mask;
	uint16_t MB_valid_address;
	uint8_t limit_counter;
	uint8_t MasterDeviceAddres;// Kullanilmayacak. Kutuphane kendi icinde kullaniyor.
	uint8_t Holding_Register_Change_Flag;
	uint8_t Holding_Register_Change_Control_Flag;
	uint8_t masterReqDataAddres; //master sorgulama yaparken otomatik olarak hangi adresten itibaren sorguladıgı verisini tutar.
	Mb_status_td Modbus_status ;
	UART_HandleTypeDef *huart;
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
}ModbusBase_t;




void modbusInit(ModbusBase_t *m_t,UART_HandleTypeDef *huart,GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin,BR_define_td br,uint8_t hardwave_control,ModbusType modbusType);

void modbusFrameWait(ModbusBase_t *m_t);

uint8_t uartTXHandler(ModbusBase_t *m_t);

uint8_t uartRXHandler(ModbusBase_t *m_t);

void newFrameWait(ModbusBase_t *m_t);

void modbusFrameControl(ModbusBase_t *m_t,uint8_t Device_address);

void sendExceptionCode(ModbusBase_t *m_t,uint8_t ExceptionCode);

void sendResponse(ModbusBase_t *m_t,uint8_t RXTX_byte_number);

uint8_t CRC16Calculate(ModbusBase_t *m_t,uint8_t Byte_number);

void Modbu_Master_Read_Reg(ModbusBase_t *m_t,ReadReg_TypeDef reg_type,uint8_t slave_addr,uint16_t reg_addr,uint16_t size);

void ModbusWrite_Reg(ModbusBase_t *m_t,WriteReg_TypeDef reg_type,uint8_t slave_addr,uint16_t reg_addr,int16_t value);

__weak void ModbusMaster_RXCallback(ModbusBase_t *m_t,uint8_t deviceAdress,ReadReg_TypeDef regType,int16_t *data_p,uint8_t size);

void Master_Read_Input(ModbusBase_t *m_t);

void Master_Read_Holding_Input(ModbusBase_t *m_t);

void Master_Read_Coil_Discrete(ModbusBase_t *m_t);

void modbusMASTER_RXHandler(ModbusBase_t *m_t);

void ReadExceptionCode();

void baudRateSet(ModbusBase_t *m_t, BR_define_td Baud_rate);

void Modbus_ReceiveInterrupt(ModbusBase_t *m_t);

void modbusSLAVE_RXHandler(ModbusBase_t *m_t);

void setLimitValsTablePointer(ModbusBase_t *m_t,const MB_range_td *MB_limit_val_table);

void coilsQuantityAndAddressSet(ModbusBase_t *m_t);

uint8_t quantityAndAddressControl(ModbusBase_t *m_t);

void coilBitAddressSet(ModbusBase_t *m_t);

void modbusWriteMultipleCoil(ModbusBase_t *m_t);

void modbusWriteSingleCoil(ModbusBase_t *m_t);

void modbusWriteSingleHoldingRegister(ModbusBase_t *m_t);

void holdingQuantityAndAddressSet(ModbusBase_t *m_t);

uint8_t singleAddressControl(ModbusBase_t *m_t,uint16_t Max_value);

void writeMultiCoils(ModbusBase_t *m_t,uint16_t Bit_count,uint8_t RX_buffer_index,uint8_t Byte_count);

void writeMultipleRegister(ModbusBase_t *m_t,uint8_t Wr_word_count,uint8_t Wr_data_index);

void modbusWriteMultipleHoldingRegister(ModbusBase_t *m_t);

void modbusReadCoilStatus(ModbusBase_t *m_t);

void modbusDiscrateStatus(ModbusBase_t *m_t);

void bitStatusTransmit(ModbusBase_t *m_t);

void discratesQuantityAndAddressSet(ModbusBase_t *m_t);

void modbusReadHoldingRegisters(ModbusBase_t *m_t);

void modbusReadRegisters(ModbusBase_t *m_t);

void inputQuantityAndAddressSet(ModbusBase_t *m_t);

void modbusReadInputRegisters(ModbusBase_t *m_t);

void MB_Set_HoldingChangeControl_flag(ModbusBase_t *m_t);

#endif /* __ENDA_MODBUS_RTU_H */
