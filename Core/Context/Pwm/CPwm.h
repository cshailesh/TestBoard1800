/*
 * CPwm.h
 *
 *  Created on: 20 SEPT 2022
 *  Author: LINK4
 */

#ifndef CPWM_H_
#define CPWM_H_

#include <ConHeader.h>

#define PWM_OUT_CH1	1
#define PWM_OUT_CH2	2
#define PWM_OUT_CH3	3
#define PWM_OUT_CH4	4

#define PWM_VAL_MIN		0
#define PWM_VAL_MAX		999

//uint16_t PwnCalcPuse(uint8_t pPer);
//uint8_t PwmValIsInLimit(uint8_t pVal);
//void PwmSetChannel(uint8_t pChNo, uint16_t pPwmVal);

void PwmSetPercent(PWM_OUT_DATA_t *pData, uint8_t pChNo, uint8_t pPercent);
void PwmDataInit(PWM_OUT_DATA_t *pDat);
void PwmProcess(PWM_OUT_DATA_t *pDat);

#endif /* CPWM_H */
