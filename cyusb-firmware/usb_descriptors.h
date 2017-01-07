/*
 * usb_descriptors.h
 *
 *  Created on: Jan 7, 2017
 *      Author: Domen Ipavec
 */

#ifndef USB_DESCRIPTORS_H
#define USB_DESCRIPTORS_H

#include <stdint.h>

extern const uint8_t UsbDescriptorDeviceUsb2[];
extern const uint8_t UsbDescriptorDeviceUsb3[];

extern const uint8_t UsbDescriptorDeviceQualifier[];
extern const uint8_t UsbDescriptorBOS[];

extern const uint8_t UsbDescriptorStringLangid[];
extern const uint8_t UsbDescriptorStringManufacturer[];
extern const uint8_t UsbDescriptorStringProduct[];

#endif
