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

#include "i2c.h"

#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "bitop.h"

static const uint8_t EDID_DATA[] PROGMEM = {
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, // fixed pattern
	0x11, 0x35, // Manufacturer id - DIU
	0x01, 0x00, // Manufacturer product code
	0x01, 0x00, 0x00, 0x00, // Serial number
	0x00, // week of manufacture
	0x1a, // year of manufacture
	0x01, // edid version
	0x03, // edid revision

	0x00, // video input parameters
	0x00, // max horizontal image size - undefined
	0x00, // max vertical image size - undefined
	0x00, // display gamma
	0x08, // supported features bitmap - RGB color

	// crhomaticity coordinates
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,

	// common output modes
	0x20, // 640x480@60
	0x00,
	0x00,

	// standard timing information
	0x01, 0x01,
	0x01, 0x01,
	0x01, 0x01,
	0x01, 0x01,
	0x01, 0x01,
	0x01, 0x01,
	0x01, 0x01,
	0x01, 0x01,

	// descriptors
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, // number of extensions
};

void i2c_init() {
	// set address
	TWSA = 0x50 << 1;

	// enable address/stop interrupt and data interrupt
	SETBITS(TWSCRA, BIT(TWDIE) | BIT(TWASIE));

	// enable i2c
	SETBIT(TWSCRA, TWEN);
}

ISR(TWI_SLAVE_vect) {
	static uint8_t address = 0;
    if (BITSET(TWSSRA, TWASIF)) {
        // received address/stop
        if (BITSET(TWSSRA, TWAS)) {
            // received address
            if (BITSET(TWSSRA, TWDIR)) {
                // read operation
                TWSCRB = 0b00000011;
            } else {
                // write operation
                TWSCRB = 0b00000011;
            }
        } else {
            // received stop
            TWSCRB = 0b00000010;
        }
    } else if (BITSET(TWSSRA, TWDIF)) {
		if (BITSET(TWSSRA, TWDIR)) {
			// read operation
			if (address > 127) {
				// invalid address
				TWSCRB = 0b00000110;
			} else if (address == 127) {
				// calculate checksum
				uint8_t checksum = 0;
				for (uint8_t i = 0; i < 127; i++) {
					checksum += pgm_read_byte(&(EDID_DATA[i]));
				}
				TWSD = 0-checksum;
				address++;
				TWSCRB = 0b00000011;
			} else {
				TWSD = pgm_read_byte(&(EDID_DATA[address]));
				address++;
				TWSCRB = 0b00000011;
			}
		} else {
			address = TWSD;
			// send address over uart if buffer empty
			if (BITSET(UCSR0A, UDRE0)) {
				UDR0 = address;
			}
			TWSCRB = 0b00000011;
		}
    } else {
        TWSCRB = 0b00000111;
    }
}

