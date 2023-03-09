/*
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef EXPANSION_BOARD_COMM_H_
#define EXPANSION_BOARD_COMM_H_


void Ex_Board_ModbusRtuRespondToBroadcast(Ex_Board_t *pDat);
void Ex_Board_GetModbusRtuAutoAddress(Ex_Board_t *pDat);

void Ex_Board_ModbusRtuReadInput(Ex_Board_t *pDat,Ex_Board_Input_Data_t pVal);
void Ex_Board_ModbusRtuReadInputs(Ex_Board_t *pDat,Ex_Board_Input_Data_t pVal[]);

void Ex_Board_ModbusRtuSetOutput(Ex_Board_t *pDat,Ex_Board_Output_Data_t pVal);
void Ex_Board_ModbusRtuSetOutputs(Ex_Board_t *pDat,Ex_Board_Output_Data_t pVal[]);

#endif /* CONTEXT_CONKEYBRD_H_ */
