/*
 * i2c.c
 *
 *  Created on: Dec 3, 2016
 *      Author: Domen Ipavec
 */

#include "i2c.h"

#include <cyu3i2c.h>
#include <cyu3error.h>
#include <cyu3utils.h>

static void i2c_delay(CyU3PReturnStatus_t status) {
    if (status == CY_U3P_SUCCESS) {
        CyU3PBusyWait(10);
    }
}

CyU3PReturnStatus_t i2c_write(uint8_t address, uint8_t reg, uint8_t value) {
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;

	CyU3PI2cPreamble_t  preamble;
    preamble.buffer[0] = address;
    preamble.buffer[1] = reg;
    preamble.length    = 2;
    preamble.ctrlMask  = 0x0000;

    apiRetStatus = CyU3PI2cTransmitBytes (&preamble, &value, 1, 0);
    i2c_delay(apiRetStatus);

    return apiRetStatus;
}

CyU3PReturnStatus_t i2c_read(uint8_t address, uint8_t reg, uint8_t *value) {
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;

	CyU3PI2cPreamble_t  preamble;
    preamble.buffer[0] = address;
    preamble.buffer[1] = reg;
    preamble.buffer[2] = address | 0x01;
    preamble.length    = 3;
    preamble.ctrlMask  = 0x0002;

    apiRetStatus = CyU3PI2cReceiveBytes(&preamble, value, 1, 0);
    i2c_delay(apiRetStatus);

    return apiRetStatus;
}
