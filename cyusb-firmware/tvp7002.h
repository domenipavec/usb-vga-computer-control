/*
 * tvp7002.h
 *
 *  Created on: Dec 3, 2016
 *      Author: Domen Ipavec
 */

#ifndef TVP7002_H_
#define TVP7002_H_

#include <cyu3types.h>

#define TVP7002_RESET_GPIO 17
#define TVP7002_PWDN_GPIO 18

#define TVP7002_ADDRESS 0xB8

CyU3PReturnStatus_t tvp7002_init();

CyU3PReturnStatus_t tvp7002_stream();

void tvp7002_print_debug_info();

#endif /* TVP7002_H_ */
