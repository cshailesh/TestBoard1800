/* 
 * FreeModbus Libary: A portable Modbus implementation for Modbus ASCII/RTU.
 * Copyright (c) 2006-2018 Christian Walter <cwalter@embedded-solutions.at>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "mbconfig.h"
#include "mbAutoAddress-Slave.h"
//#include "projectDefs.h"


#if MB_FUNC_DIAGNOSTICS_ENABLED > 0
eMBException HandleDiagnostics(UCHAR *pucFrame, USHORT *usLen)
{
	eMBException	status = MB_EX_NONE;

	#if (DEFAULT_MODBUS_ADDRESS == 0)
		// Get the sub function
		uint16_t SubFunction = 0;
		UCHAR *pMsg = pucFrame;
		pMsg++;			// Skip the function code
		SubFunction = (*pMsg++) << 8;
		SubFunction |= (*pMsg++);

		uint8_t Length = (*pMsg++);

		switch (SubFunction)
		{
			case 0x20:
				status = AutoAddress_SetRange(pucFrame, Length);
				break;

			case 0x21:
				status = AutoAddress_Randomize(pucFrame, Length);
				break;

			case 0x22:
				status = AutoAddress_ReadUniqueID(pucFrame, usLen);
				break;

			default:
				// Unhandled. Do nothing.
				status = MB_EX_ILLEGAL_FUNCTION;
				break;
		}
	#endif

  return status;
}
#endif
