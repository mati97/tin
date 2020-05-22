/*
 * gpio.h
 *
 *  Created on: May 22, 2020
 *      Author: mati97
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "main.h"

void write(uint32_t address, uint8_t data);
uint8_t read(uint32_t address);

#endif /* GPIO_H_ */
