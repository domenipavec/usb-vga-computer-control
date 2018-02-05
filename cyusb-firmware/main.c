/*
 * main.c
 *
 *  Created on: Jan 9, 2017
 *      Author: domen
 */

#include <cyu3error.h>
#include <cyu3system.h>

#include "uvc.h"

static CyU3PThread uvcAppThread;
static CyU3PThread uvcAppEP0Thread;

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

	CyU3PIoMatrixConfig_t io_cfg = {
		.isDQ32Bit = CyFalse, // gpif bus width
		.s0Mode = 0, // storage port 0 disabled
		.s1Mode = 0, // storage port 1 disabled
		.lppMode = CY_U3P_IO_MATRIX_LPP_UART_ONLY, // default peripheral pins layout with everything enabled

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

static void start_thread(CyU3PThread *thread, char *name, CyU3PThreadEntry_t entry) {
	const uint32_t stack_size = 1024;
	const uint32_t priority = 8;

	void *ptr = CyU3PMemAlloc(stack_size);
	if (ptr == NULL) {
		goto fatalErrorHandler;
	}

	uint32_t ret = CyU3PThreadCreate(
		thread,
		name,
		entry,
		0,
		ptr,
		stack_size,
		priority,
		priority, // preempt threshold
		CYU3P_NO_TIME_SLICE,
		CYU3P_AUTO_START
	);
	if (ret != 0) {
		goto fatalErrorHandler;
	}

	return;

fatalErrorHandler:
	for (;;);
}

/*
 * This function is called by the FX3 framework once the ThreadX RTOS has started up.
 * The application specific threads and other OS resources are created and initialized here.
 */
void CyFxApplicationDefine() {
	start_thread(
		&uvcAppThread,
		"30:UVC App Thread",
		UVCAppThread_Entry
	);

	start_thread(
		&uvcAppEP0Thread,
		"31:UVC App EP0 Thread",
		UVCAppEP0Thread_Entry
	);
}
