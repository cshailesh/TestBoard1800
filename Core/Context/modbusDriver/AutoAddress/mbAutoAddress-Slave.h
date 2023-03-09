/*
 * mbAutoAddress-Slave.h
 *
 */

#ifndef MBAUTOADDRESS_SLAVE_H_
#define MBAUTOADDRESS_SLAVE_H_

#include "mbproto.h"
#include "port.h"

eMBException AutoAddress_SetRange(UCHAR *, USHORT);
eMBException AutoAddress_Randomize(UCHAR *, USHORT);
eMBException AutoAddress_ReadUniqueID(UCHAR *, USHORT *);

#endif // Prevent multiple includes
