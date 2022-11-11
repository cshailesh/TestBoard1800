/*
 * ContextData.h
 *
 *  Created on: Feb 10, 2022
 *      Author: ADITYA
 */

#ifndef CONTEXT_CONTEXTDATA_H_
#define CONTEXT_CONTEXTDATA_H_

#include "ContextHeader.h"

CONTEXT_DATA_t gContextLedData;
CONTEXT_DATA_t *gPtrCD;

void ContextDataInit(CONTEXT_DATA_t *pCD);

#endif /* CONTEXT_CONTEXTDATA_H_ */
