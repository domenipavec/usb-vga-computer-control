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

static CyU3PDmaChannel glChHandleUsbtoUart;
static CyU3PDmaChannel glChHandleUarttoUsb;

static CyU3PUartConfig_t uartConfig = {0};
static CyBool_t isAppActive = CyFalse;

static volatile uint16_t glPktsPending = 0;            /* Number of packets that have been committed since last check. */

#define CY_FX_EP_CONSUMER 0x85
#define CY_FX_EP_PRODUCER 0x05
#define CY_FX_EP_INTERRUPT 0x84

void uart_init() {
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;

	apiRetStatus = CyU3PUartInit();
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

// TODO use this thread
void uart_thread() {
	for (;;) {
		if (isAppActive)
		{
			/* While the application is active, check for data sent during the last 50 ms. If no data
			   has been sent to the host, use the channel wrap-up feature to send any partial buffer to
			   the USB host.
			   */
			if (glPktsPending == 0)
			{
				CyU3PDmaChannelSetWrapUp (&glChHandleUarttoUsb);
			}
			glPktsPending = 0;
		}
	}
}

static void uart_dma_callback(CyU3PDmaChannel *chHandle, CyU3PDmaCbType_t type, CyU3PDmaCBInput_t *input) {
	if (type == CY_U3P_DMA_CB_PROD_EVENT)
	{
		CyU3PDmaChannelCommitBuffer (&glChHandleUarttoUsb, input->buffer_p.count, 0);
		glPktsPending++;
	}
}

void uart_start() {
	uint16_t size = 0;
	CyU3PEpConfig_t epCfg;
	CyU3PDmaChannelConfig_t dmaCfg;
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;
	CyU3PUSBSpeed_t usbSpeed = CyU3PUsbGetSpeed();

	/* Based on the Bus speed configure the endpoint packet size */
	switch (usbSpeed)
	{
		case CY_U3P_FULL_SPEED:
			size = 64;
			break;

		case CY_U3P_HIGH_SPEED:
			size = 512;
			break;

		case  CY_U3P_SUPER_SPEED:
			/* Turning low power mode off to avoid USB transfer delays. */
			CyU3PUsbLPMDisable ();
			size = 1024;
			break;

		default:
			// TODO error handler
			break;
	}

	CyU3PMemSet ((uint8_t *)&epCfg, 0, sizeof (epCfg));
	epCfg.enable = CyTrue;
	epCfg.epType = CY_U3P_USB_EP_BULK;
	epCfg.burstLen = 1;
	epCfg.streams = 0;
	epCfg.pcktSize = size;

	/* Producer endpoint configuration */
	apiRetStatus = CyU3PSetEpConfig(CY_FX_EP_PRODUCER , &epCfg);
	if (apiRetStatus != CY_U3P_SUCCESS)
	{
		// TODO error handler
	}
	/* Consumer endpoint configuration */
	apiRetStatus = CyU3PSetEpConfig(CY_FX_EP_CONSUMER, &epCfg);
	if (apiRetStatus != CY_U3P_SUCCESS)
	{
		// TODO error handler
	}

	/* Interrupt endpoint configuration */
	epCfg.epType = CY_U3P_USB_EP_INTR;
	epCfg.pcktSize = 64;
	epCfg.isoPkts = 1;

	apiRetStatus = CyU3PSetEpConfig(CY_FX_EP_INTERRUPT, &epCfg);
	if (apiRetStatus != CY_U3P_SUCCESS)
	{
		// TODO error handler
	}


	/* Create a DMA_AUTO channel between usb producer socket and uart consumer socket */
	dmaCfg.size = size;
	dmaCfg.count = 8;
	dmaCfg.prodSckId = CY_U3P_UIB_SOCKET_PROD_5;
	dmaCfg.consSckId = CY_U3P_LPP_SOCKET_UART_CONS;
	dmaCfg.dmaMode = CY_U3P_DMA_MODE_BYTE;
	dmaCfg.notification = 0;
	dmaCfg.cb = NULL;
	dmaCfg.prodHeader = 0;
	dmaCfg.prodFooter = 0;
	dmaCfg.consHeader = 0;
	dmaCfg.prodAvailCount = 0;

	apiRetStatus = CyU3PDmaChannelCreate (&glChHandleUsbtoUart, CY_U3P_DMA_TYPE_AUTO, &dmaCfg);
	if (apiRetStatus != CY_U3P_SUCCESS)
	{
		// TODO error handler
	}

	/* Create a DMA_MANUAL channel between uart producer socket and usb consumer socket */
	/* Use a smaller buffer size (32 bytes) to ensure that packets get filled in a short time. */
	dmaCfg.size         = 32;
	dmaCfg.prodSckId    = CY_U3P_LPP_SOCKET_UART_PROD;
	dmaCfg.consSckId    = CY_U3P_UIB_SOCKET_CONS_5;
	dmaCfg.notification = CY_U3P_DMA_CB_PROD_EVENT;
	dmaCfg.cb           = uart_dma_callback;

	apiRetStatus = CyU3PDmaChannelCreate (&glChHandleUarttoUsb, CY_U3P_DMA_TYPE_MANUAL, &dmaCfg);
	if (apiRetStatus != CY_U3P_SUCCESS)
	{
		// TODO error handler
	}

	/* Set DMA Channel transfer size */
	apiRetStatus = CyU3PDmaChannelSetXfer (&glChHandleUsbtoUart,0);
	if (apiRetStatus != CY_U3P_SUCCESS)
	{
		// TODO error handler
	}

	apiRetStatus = CyU3PDmaChannelSetXfer (&glChHandleUarttoUsb, 0);
	if (apiRetStatus != CY_U3P_SUCCESS)
	{
		// TODO error handler
	}

	/* Update the status flag. */
	isAppActive = CyTrue;
}

void uart_stop() {
	CyU3PEpConfig_t epCfg;
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;

	/* Update the flag. */
	isAppActive = CyFalse;

	/* Flush the endpoint memory */
	CyU3PUsbFlushEp(CY_FX_EP_PRODUCER);
	CyU3PUsbFlushEp(CY_FX_EP_CONSUMER);
	CyU3PUsbFlushEp(CY_FX_EP_INTERRUPT);

	/* Destroy the channel */
	CyU3PDmaChannelDestroy (&glChHandleUsbtoUart);
	CyU3PDmaChannelDestroy (&glChHandleUarttoUsb);

	/* Disable endpoints. */
	CyU3PMemSet ((uint8_t *)&epCfg, 0, sizeof (epCfg));
	epCfg.enable = CyFalse;

	/* Producer endpoint configuration. */
	apiRetStatus = CyU3PSetEpConfig(CY_FX_EP_PRODUCER, &epCfg);
	if (apiRetStatus != CY_U3P_SUCCESS)
	{
		// TODO error handler
	}

	/* Consumer endpoint configuration. */
	apiRetStatus = CyU3PSetEpConfig(CY_FX_EP_CONSUMER, &epCfg);
	if (apiRetStatus != CY_U3P_SUCCESS)
	{
		// TODO error handler
	}

	/* Interrupt endpoint configuration. */
	apiRetStatus = CyU3PSetEpConfig(CY_FX_EP_INTERRUPT, &epCfg);
	if (apiRetStatus != CY_U3P_SUCCESS)
	{
		// TODO error handler
	}
}

CyBool_t uart_usb_setup_cb(uint8_t bReqType, uint8_t bRequest, uint16_t wValue) {
	uint16_t readCount = 0;
	uint8_t  bType, bTarget;
	uint8_t config_data[7];
	CyBool_t isHandled = CyFalse;
	CyU3PReturnStatus_t status = CY_U3P_SUCCESS;
	CyU3PReturnStatus_t apiRetStatus = CY_U3P_SUCCESS;
	CyU3PUartConfig_t newConfig;

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
				CyU3PMemSet ((uint8_t *)&newConfig, 0, sizeof (newConfig));
				newConfig.baudRate = (CyU3PUartBaudrate_t)(config_data[0] | (config_data[1]<<8)|
						(config_data[2]<<16)|(config_data[3]<<24));
				if (config_data[4] == 0)
				{
					newConfig.stopBit = CY_U3P_UART_ONE_STOP_BIT;
				}
				else if (config_data[4] == 2)
				{
					newConfig.stopBit = CY_U3P_UART_TWO_STOP_BIT;
				}
				else
				{
					/* Give invalid value. */
					newConfig.stopBit = (CyU3PUartStopBit_t)0;
				}
				if (config_data[5] == 1)
				{
					newConfig.parity = CY_U3P_UART_ODD_PARITY;
				}
				else if (config_data[5] == 2)
				{
					newConfig.parity = CY_U3P_UART_EVEN_PARITY;
				}
				else
				{
					/* 0 = no parity; any other value - invalid parity. */
					newConfig.parity = CY_U3P_UART_NO_PARITY;
				}

				newConfig.txEnable = CyTrue;
				newConfig.rxEnable = CyTrue;
				newConfig.flowCtrl = CyFalse;
				newConfig.isDma = CyTrue;

				/* Set the uart configuration */
				apiRetStatus = CyU3PUartSetConfig (&newConfig, NULL);
				if (apiRetStatus == CY_U3P_SUCCESS)
				{
					CyU3PMemCopy ((uint8_t *)&uartConfig, (uint8_t *)&newConfig,
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
