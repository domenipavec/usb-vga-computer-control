/*
 * uart.c
 *
 *  Created on: Jan 10, 2017
 *      Author: Domen Ipavec
 */

#include "uart.h"

#include <cyu3uart.h>
#include <cyu3usb.h>
#include <cyu3error.h>

/* CDC Class specific requests to be handled by this application. */
#define SET_LINE_CODING        0x20
#define GET_LINE_CODING        0x21
#define SET_CONTROL_LINE_STATE 0x22

static CyU3PUartConfig_t uartConfig = {0};
static CyBool_t isAppActive = CyFalse;

void uart_init() {

	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;

	if (apiRetStatus != CY_U3P_SUCCESS) {
		// TODO error handler
	}


	CyU3PMemSet ((uint8_t *)&uartConfig, 0, sizeof (uartConfig));
	uartConfig.baudRate = CY_U3P_UART_BAUDRATE_115200;
	uartConfig.stopBit = CY_U3P_UART_ONE_STOP_BIT;
	uartConfig.parity = CY_U3P_UART_NO_PARITY;
	uartConfig.flowCtrl = CyFalse;
	uartConfig.txEnable = CyTrue;
	uartConfig.rxEnable = CyTrue;
	uartConfig.isDma = CyTrue;

	apiRetStatus = CyU3PUartSetConfig(&uartConfig, NULL);
	if (apiRetStatus != CY_U3P_SUCCESS ) {
		// TODO error handler
	}
}

void uart_start() {

}

void uart_stop() {

}

CyBool_t uart_usb_setup_cb(uint8_t bReqType, uint8_t bRequest, uint16_t wValue) {
	uint16_t readCount = 0;
	uint8_t  bType, bTarget;
	uint8_t config_data[7];
	CyBool_t isHandled = CyFalse;
	CyU3PReturnStatus_t status = CY_U3P_SUCCESS;
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;
	CyU3PUartConfig_t uartConfig;

	/* Decode the fields from the setup request. */
	bType    = (bReqType & CY_U3P_USB_TYPE_MASK);
	bTarget  = (bReqType & CY_U3P_USB_TARGET_MASK);


	if (bType == CY_U3P_USB_STANDARD_RQT)
	{
		/* Handle SET_FEATURE(FUNCTION_SUSPEND) and CLEAR_FEATURE(FUNCTION_SUSPEND)
		 * requests here. It should be allowed to pass if the device is in configured
		 * state and failed otherwise. */
		if ((bTarget == CY_U3P_USB_TARGET_INTF) && ((bRequest == CY_U3P_USB_SC_SET_FEATURE)
					|| (bRequest == CY_U3P_USB_SC_CLEAR_FEATURE)) && (wValue == 0))
		{
			if (isAppActive)
				CyU3PUsbAckSetup ();
			else
				CyU3PUsbStall (0, CyTrue, CyFalse);

			isHandled = CyTrue;
		}
	}

	/* Check for CDC Class Requests */
	if (bType == CY_U3P_USB_CLASS_RQT)
	{
		isHandled = CyTrue;

		/* CDC Specific Requests */
		/* set_line_coding */
		if (bRequest == SET_LINE_CODING)
		{
			status = CyU3PUsbGetEP0Data(0x07, config_data, &readCount);
			if (status != CY_U3P_SUCCESS)
			{
				// TODO erro rhandler
			}
			if (readCount != 0x07)
			{
				// TODO error handler
			}
			else
			{
				CyU3PMemSet ((uint8_t *)&uartConfig, 0, sizeof (uartConfig));
				uartConfig.baudRate = (CyU3PUartBaudrate_t)(config_data[0] | (config_data[1]<<8)|
						(config_data[2]<<16)|(config_data[3]<<24));
				if (config_data[4] == 0)
				{
					uartConfig.stopBit = CY_U3P_UART_ONE_STOP_BIT;
				}
				else if (config_data[4] == 2)
				{
					uartConfig.stopBit = CY_U3P_UART_TWO_STOP_BIT;
				}
				else
				{
					/* Give invalid value. */
					uartConfig.stopBit = (CyU3PUartStopBit_t)0;
				}
				if (config_data[5] == 1)
				{
					uartConfig.parity = CY_U3P_UART_ODD_PARITY;
				}
				else if (config_data[5] == 2)
				{
					uartConfig.parity = CY_U3P_UART_EVEN_PARITY;
				}
				else
				{
					/* 0 = no parity; any other value - invalid parity. */
					uartConfig.parity = CY_U3P_UART_NO_PARITY;
				}

				uartConfig.txEnable = CyTrue;
				uartConfig.rxEnable = CyTrue;
				uartConfig.flowCtrl = CyFalse;
				uartConfig.isDma = CyTrue;

				/* Set the uart configuration */
				apiRetStatus = CyU3PUartSetConfig (&uartConfig, NULL);
				if (apiRetStatus == CY_U3P_SUCCESS)
				{
					CyU3PMemCopy ((uint8_t *)&uartConfig, (uint8_t *)&uartConfig,
							sizeof (CyU3PUartConfig_t));
				}
			}
		}
		/* get_line_coding */
		else if (bRequest == GET_LINE_CODING )
		{
			/* get current uart config */
			config_data[0] = uartConfig.baudRate&(0x000000FF);
			config_data[1] = ((uartConfig.baudRate&(0x0000FF00))>> 8);
			config_data[2] = ((uartConfig.baudRate&(0x00FF0000))>>16);
			config_data[3] = ((uartConfig.baudRate&(0xFF000000))>>24);
			if (uartConfig.stopBit == CY_U3P_UART_ONE_STOP_BIT)
			{
				config_data[4] = 0;
			}
			else /* CY_U3P_UART_TWO_STOP_BIT */
			{
				config_data[4] = 2;
			}

			if (uartConfig.parity == CY_U3P_UART_EVEN_PARITY)
			{
				config_data[5] = 2;
			}
			else if (uartConfig.parity == CY_U3P_UART_ODD_PARITY)
			{
				config_data[5] = 1;
			}
			else
			{
				config_data[5] = 0;
			}

			config_data[6] =  0x08;
			status = CyU3PUsbSendEP0Data( 0x07, config_data);
			if (status != CY_U3P_SUCCESS)
			{
				// TODO eror handler
			}
		}
		/* SET_CONTROL_LINE_STATE */
		else if (bRequest == SET_CONTROL_LINE_STATE)
		{
			if (isAppActive)
			{
				CyU3PUsbAckSetup ();
			}
			else
				CyU3PUsbStall (0, CyTrue, CyFalse);
		}
		else
		{
			status = CY_U3P_ERROR_FAILURE;
		}

		if (status != CY_U3P_SUCCESS)
		{
			isHandled = CyFalse;
		}
	}

	return isHandled;
}
