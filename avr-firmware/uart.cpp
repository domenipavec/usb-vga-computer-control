/* File: uart.cpp
 * uart handling
 */
/* Copyright (c) 2012-2013 Domen Ipavec (domen.ipavec@z-v.si)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "uart.h"

#include <avr/interrupt.h>


#include "bitop.h"
#include "usb.h"

volatile int8_t dx;

void uart_init() {
	// remap to PB2 and PA7
	SETBIT(REMAP, U0MAP);

	// enable rx complete interrupt
	SETBIT(UCSR0B, RXCIE0);

	// set 8 bits byte mode
	SETBITS(UCSR0C, BIT(UCSZ00) | BIT(UCSZ01));

	// set baud rate
	UBRR0 = F_CPU/16/BAUDRATE - 1;

	// enable receiver
	SETBIT(UCSR0B, RXEN0);

	// enable transmitter
	SETBIT(UCSR0B, TXEN0);
}

ISR(USART0_RX_vect) {
	static uint8_t state = 0;
	static uint8_t substate = 0;
	uint8_t data = UDR0;
	substate++;
	switch (state) {
		case 0:
			if (data == 0xAA) {
				state = 0xFF;
			}
			break;
		case 0xFF:
			state = data;
			substate = 0;
			break;
		case 1:
			switch (substate) {
				case 1:
					hid_report_mouse_abs.x.bytes[0] = data;
					break;
				case 2:
					hid_report_mouse_abs.x.bytes[1] = data;
					break;
				case 3:
					hid_report_mouse_abs.y.bytes[0] = data;
					break;
				case 4:
					hid_report_mouse_abs.y.bytes[1] = data;
					SETBIT(hid_report_dirty, HID_REPORT_MOUSE_ABS_DIRTY);
					state = 0;
					break;
				default:
					state = 0;
					break;
			}
			break;
		case 2:
			hid_report_mouse_rel.buttonMask = data;
			hid_report_mouse_rel.dx = 0;
			hid_report_mouse_rel.dy = 0;
			SETBIT(hid_report_dirty, HID_REPORT_MOUSE_REL_DIRTY);
			state = 0;
			break;
		case 3:
			switch (substate) {
				case 1:
					hid_report_mouse_abs.x.bytes[0] = data;
					break;
				case 2:
					hid_report_mouse_abs.x.bytes[1] = data;
					break;
				case 3:
					hid_report_mouse_abs.y.bytes[0] = data;
					break;
				case 4:
					hid_report_mouse_abs.y.bytes[1] = data;
					break;
				case 5:
					if (data) {
						SETBIT(hid_report_mouse_abs.buttonMask, 0);
					} else {
						CLEARBIT(hid_report_mouse_abs.buttonMask, 0);
					}
					SETBIT(hid_report_dirty, HID_REPORT_MOUSE_ABS_DIRTY);
					state = 0;
					break;
				default:
					state = 0;
					break;
			}
			break;
		default:
			state = 0;
			break;
	}
}
