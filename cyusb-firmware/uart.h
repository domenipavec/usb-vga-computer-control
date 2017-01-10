/*
 * uart.h
 *
 *  Created on: Jan 10, 2017
 *      Author: Domen Ipavec
 */

#ifndef UART_H
#define UART_H

#include <cyu3types.h>

void uart_init();
void uart_stop();
void uart_start();
CyBool_t uart_usb_setup_cb(uint8_t bReqType, uint8_t bRequest, uint16_t wValue);

#endif /* UART_H */
