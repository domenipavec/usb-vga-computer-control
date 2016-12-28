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

volatile int8_t dx;

void uart_init() {
	// remap to PB2 and PA7
	SETBIT(REMAP, U0MAP);

	// enable rx complete interrupt
	SETBIT(UCSR0B, RXCIE0);

	// enable receiver
	SETBIT(UCSR0B, RXEN0);

	// set 8 bits byte mode
	SETBITS(UCSR0C, BIT(UCSZ00) | BIT(UCSZ01));

	// set baud rate
	UBRR0 = F_CPU/16/BAUDRATE - 1;
}

ISR(USART0_RX_vect) {
	uint8_t data = UDR0;
	if (data == 'a') {
		dx = 5;
	} else if (data == 'b') {
		dx = -5;
	}
}
