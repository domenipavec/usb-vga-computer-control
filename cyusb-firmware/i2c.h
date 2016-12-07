/*
 * i2c.h
 *
 *  Created on: Dec 3, 2016
 *      Author: Domen Ipavec
 */

#ifndef I2C_H_
#define I2C_H_

#include <cyu3types.h>

CyU3PReturnStatus_t i2c_write(uint8_t address, uint8_t reg, uint8_t value);

CyU3PReturnStatus_t i2c_read(uint8_t address, uint8_t reg, uint8_t *value);


#endif /* I2C_H_ */
