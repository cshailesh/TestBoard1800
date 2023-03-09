/* 
 * MODBUS CRC:
 * Based on code from https://www.modbustools.com/modbus_crc16.html.
 */


#ifndef CRC_H
#define CRC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*! \brief Calculates the CRC16 checksum
 *
 * \param pData:  A pointer to an array of bytes on which to calculate the CRC.
 * \param Length: Size of the frame to check.
 * \return: CRC16 checksum for this frame.
 */
uint16_t CRC16 (const uint8_t *pData, uint16_t Length);

/*! 
 * \if INTERNAL_DOCS
 * @} 
 * \endif
 */

#ifdef __cplusplus
}
#endif
#endif	// prevent multiple includes
