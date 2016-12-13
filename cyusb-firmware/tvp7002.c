/*
 * tvp7002.c
 *
 *  Created on: Dec 3, 2016
 *      Author: domen
 */

#include "tvp7002.h"

#include <cyu3i2c.h>
#include <cyu3error.h>
#include <cyu3gpio.h>

#include "i2c.h"

static CyU3PReturnStatus_t tvp7002_reset() {
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;

	apiRetStatus = CyU3PGpioSetValue(TVP7002_RESET_GPIO, CyFalse);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		return apiRetStatus;
	}

	apiRetStatus = CyU3PGpioSetValue(TVP7002_PWDN_GPIO, CyFalse);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		return apiRetStatus;
	}

	CyU3PThreadSleep(50);

	apiRetStatus = CyU3PGpioSetValue(TVP7002_RESET_GPIO, CyTrue);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		return apiRetStatus;
	}

	CyU3PThreadSleep(100);

	return apiRetStatus;
}

// handle errors in shorter code
#define I2C_WRITE(address, reg, value) \
apiRetStatus = i2c_write(address, reg, value); \
if (apiRetStatus != CY_U3P_SUCCESS) { \
	return apiRetStatus; \
}

static CyU3PReturnStatus_t set_pll_divider(uint16_t clocks_per_line) {
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;

	I2C_WRITE(TVP7002_ADDRESS, 0x01, (clocks_per_line >> 4) & 0xff);
	I2C_WRITE(TVP7002_ADDRESS, 0x02, (clocks_per_line & 0xf) << 4);

	return apiRetStatus;
}

CyU3PReturnStatus_t tvp7002_init() {
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;

	apiRetStatus = tvp7002_reset();
	if (apiRetStatus != CY_U3P_SUCCESS) {
		return apiRetStatus;
	}

	// pll settings
	apiRetStatus = set_pll_divider(800);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		return apiRetStatus;
	}
	I2C_WRITE(TVP7002_ADDRESS, 0x03, 0x18);
	I2C_WRITE(TVP7002_ADDRESS, 0x04, 0x00);

	// clamp settings recommended for pc graphics
	I2C_WRITE(TVP7002_ADDRESS, 0x05, 0x06);
	I2C_WRITE(TVP7002_ADDRESS, 0x06, 0x10);

	// set gains and offsets from example settings
	// BGR gain
	I2C_WRITE(TVP7002_ADDRESS, 0x08, 0x04);
	I2C_WRITE(TVP7002_ADDRESS, 0x09, 0x04);
	I2C_WRITE(TVP7002_ADDRESS, 0x0a, 0x04);
	// BGR offsets
	I2C_WRITE(TVP7002_ADDRESS, 0x0b, 0x90);
	I2C_WRITE(TVP7002_ADDRESS, 0x0c, 0x90);
	I2C_WRITE(TVP7002_ADDRESS, 0x0d, 0x90);

	// Some sync input settings
	I2C_WRITE(TVP7002_ADDRESS, 0x0e, 0x12);

	// sog bottom level clamp for rgb
	I2C_WRITE(TVP7002_ADDRESS, 0x10, 0x58);

	// sync separator recommended for all formats
	I2C_WRITE(TVP7002_ADDRESS, 0x11, 0x40);

	// pre, post coast recommended for pc
	I2C_WRITE(TVP7002_ADDRESS, 0x12, 0x01);
	I2C_WRITE(TVP7002_ADDRESS, 0x13, 0x00);

	// output mode 422
	I2C_WRITE(TVP7002_ADDRESS, 0x15, 0x06);

	// outputs enabled
	I2C_WRITE(TVP7002_ADDRESS, 0x17, 0x00);

	// enable csc
	I2C_WRITE(TVP7002_ADDRESS, 0x18, 0x10);

	// input selection
	I2C_WRITE(TVP7002_ADDRESS, 0x19, 0x00);

	// hsout start in clock cycles
	I2C_WRITE(TVP7002_ADDRESS, 0x21, 0x0d);

	// hsout width in pixels
	I2C_WRITE(TVP7002_ADDRESS, 0x07, 0xa0);

	// disable macrovision stripper
	I2C_WRITE(TVP7002_ADDRESS, 0x22, 0x00);

	// enable CM offset
	I2C_WRITE(TVP7002_ADDRESS, 0x2a, 0x87);

	// ALC placement for pc graphics
	I2C_WRITE(TVP7002_ADDRESS, 0x31, 0x18);

	// vs-hs align
	I2C_WRITE(TVP7002_ADDRESS, 0x35, -1);

	// set recommended line length tolerance
	I2C_WRITE(TVP7002_ADDRESS, 0x3d, 0x06);

	return apiRetStatus;
}

CyU3PReturnStatus_t tvp7002_stream() {
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;

	return apiRetStatus;
}

static CyU3PReturnStatus_t read16(uint8_t address, uint8_t reg, uint16_t *value) {
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;

	*value = 0;

	uint8_t tmp = 0;
	apiRetStatus = i2c_read(address, reg, &tmp);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		return apiRetStatus;
	}
	CyU3PDebugPrint(4, "Value1: %d\r\n", tmp);
	*value = tmp;

	apiRetStatus = i2c_read(address, reg + 1, &tmp);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		return apiRetStatus;
	}
	CyU3PDebugPrint(4, "Value2: %d\r\n", tmp);

	*value |= (tmp & 0xf) << 8;

	return apiRetStatus;
}

void tvp7002_print_debug_info() {
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;

	uint8_t value = 0;
	apiRetStatus = i2c_read(TVP7002_ADDRESS, 0x00, &value);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		CyU3PDebugPrint(4, "Failed i2c read: %d\r\n", apiRetStatus);
		return;
	}
	CyU3PDebugPrint(4, "Chip revision: %d\r\n", value);

	apiRetStatus = i2c_read(TVP7002_ADDRESS, 0x01, &value);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		CyU3PDebugPrint(4, "Failed i2c read: %d\r\n", apiRetStatus);
		return;
	}
	CyU3PDebugPrint(4, "0x01: %d\r\n", value);
	apiRetStatus = i2c_read(TVP7002_ADDRESS, 0x02, &value);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		CyU3PDebugPrint(4, "Failed i2c read: %d\r\n", apiRetStatus);
		return;
	}
	CyU3PDebugPrint(4, "0x02: %d\r\n", value);

	uint16_t value16;
	apiRetStatus = read16(TVP7002_ADDRESS, 0x37, &value16);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		CyU3PDebugPrint(4, "Failed i2c read: %d\r\n", apiRetStatus);
		return;
	}
	CyU3PDebugPrint(4, "Lines per frame: %d\r\n", value16);


	apiRetStatus = read16(TVP7002_ADDRESS, 0x39, &value16);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		CyU3PDebugPrint(4, "Failed i2c read: %d\r\n", apiRetStatus);
		return;
	}
	CyU3PDebugPrint(4, "Clocks per line: %d\r\n", value16);

	apiRetStatus = i2c_read(TVP7002_ADDRESS, 0x14, &value);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		CyU3PDebugPrint(4, "Failed i2c read: %d\r\n", apiRetStatus);
		return;
	}
	CyU3PDebugPrint(4, "HSYNC detect: %d\r\n", (value >> 7)&1);
	CyU3PDebugPrint(4, "Active HSYNC: %d\r\n", (value >> 6)&1);
	CyU3PDebugPrint(4, "Input HSYNC polarity: %d\r\n", (value >> 5)&1);
	CyU3PDebugPrint(4, "VSYNC detect: %d\r\n", (value >> 4)&1);
	CyU3PDebugPrint(4, "Active VSYNC: %d\r\n", (value >> 3)&1);
	CyU3PDebugPrint(4, "Input VSYNC polarity: %d\r\n", (value >> 2)&1);
	CyU3PDebugPrint(4, "SOG detect: %d\r\n", (value >> 1)&1);
	CyU3PDebugPrint(4, "Input coast polarity detect: %d\r\n", (value >> 0)&1);
}

