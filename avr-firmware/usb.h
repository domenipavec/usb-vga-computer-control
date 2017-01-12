/* File: usb.h
 * Usb handling
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

#ifndef USB_H
#define USB_H

#include "stdint.h"

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC {
#include "usbdrv.h"
}

EXTERNC usbMsgLen_t usbFunctionSetup(uchar data[8]);

void usb_init();
void usb_loop();

struct hid_report_mouse_rel_t {
	uint8_t report_id;
    uint8_t   buttonMask;
    char    dx;
    char    dy;
};

struct hid_report_keyboard_t {
    uint8_t report_id;
    uint8_t modifier;
    uint8_t reserved;
    uint8_t keycode[6];
};

struct hid_report_mouse_abs_t {
	uint8_t report_id;
    uint8_t buttonMask;
    usbWord_t    x;
    usbWord_t    y;
};

union hid_report_t {
	hid_report_mouse_abs_t mouse_abs;
	hid_report_keyboard_t keyboard;
	hid_report_mouse_rel_t mouse_rel;
};

extern volatile hid_report_mouse_rel_t hid_report_mouse_rel;
extern volatile hid_report_keyboard_t hid_report_keyboard;
extern volatile hid_report_mouse_abs_t hid_report_mouse_abs;

const uint8_t HID_REPORT_MOUSE_REL_DIRTY = 0;
const uint8_t HID_REPORT_KEYBOARD_DIRTY = 1;
const uint8_t HID_REPORT_MOUSE_ABS_DIRTY = 2;
extern volatile uint8_t hid_report_dirty;

#endif
