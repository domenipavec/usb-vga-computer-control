/*
 * main.c
 *
 *  Created on: Jan 9, 2017
 *      Author: domen
 */

#include <cyu3error.h>
#include <cyu3system.h>

int main(void) {
	CyU3PReturnStatus_t apiRetStatus;

	// init to default max clocks for cpu, dma and mmio
	apiRetStatus = CyU3PDeviceInit(NULL);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		goto handle_fatal_error;
	}

	const CyBool_t isInstructionCacheEnable = CyTrue;
	const CyBool_t isDataCacheEnable = CyFalse;
	const CyBool_t isDmaHandleDataCacheEnable = CyFalse;
	apiRetStatus = CyU3PDeviceCacheControl(isInstructionCacheEnable, isDataCacheEnable, isDmaHandleDataCacheEnable);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		goto handle_fatal_error;
	}

	const CyU3PIoMatrixConfig_t io_cfg = {
		.isDQ32Bit = CyTrue, // gpif bus width
		.s0Mode = 0, // storage port 0 disabled
		.s1Mode = 0, // storage port 1 disabled
		.lppMode = CY_U3P_IO_MATRIX_LPP_DEFAULT, // default peripheral pins layout with everything enabled

		.gpioSimpleEn = {0, 0}, // which pins are configured as simple gpio
		.gpioComplexEn = {0, 0}, // which pins are configured as complex gpio

		.useUart = CyTrue,
		.useI2C = CyTrue,
		.useI2S = CyFalse,
		.useSpi = CyFalse,
	};
	apiRetStatus = CyU3PDeviceConfigureIOMatrix(&io_cfg);
	if (apiRetStatus != CY_U3P_SUCCESS) {
		goto handle_fatal_error;
	}

	// non returnable rtos kernel entry
	CyU3PKernelEntry();

	return 0;

handle_fatal_error:
	for (;;);
}
