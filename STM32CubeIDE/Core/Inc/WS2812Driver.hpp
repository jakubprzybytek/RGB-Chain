/*
 * WS2812Driver.hpp
 *
 *  Created on: Dec 8, 2020
 *      Author: Chipotle
 */

#ifndef INC_WS2812DRIVER_HPP_
#define INC_WS2812DRIVER_HPP_

#include "stm32l0xx_hal.h"

#define NUMBER_OF_DIODES 	10

static const uint8_t gamma[] = { 0, 1, 2, 3, 4, 5, 7, 9, 12, 15, 18, 22, 27, 32, 38, 44, 51, 58, 67, 76, 86, 96, 108, 120, 134, 148, 163, 180, 197, 216, 235,
		255 };

static const uint8_t gamma8[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 11, 11, 11, 12, 12, 13, 13,
		13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25, 25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35,
		36, 37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50, 51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68, 69, 70, 72, 73, 74,
		75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89, 90, 92, 93, 95, 96, 98, 99, 101, 102, 104, 105, 107, 109, 110, 112, 114, 115, 117, 119, 120, 122, 124, 126,
		127, 129, 131, 133, 135, 137, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 167, 169, 171, 173, 175, 177, 180, 182, 184, 186,
		189, 191, 193, 196, 198, 200, 203, 205, 208, 210, 213, 215, 218, 220, 223, 225, 228, 231, 233, 236, 239, 241, 244, 247, 249, 252, 255 };

static const uint8_t ws_code[] = { (uint8_t) ~0x24, (uint8_t) ~0x64, (uint8_t) ~0x2c, (uint8_t) ~0x6c, (uint8_t) ~0x25, (uint8_t) ~0x65, (uint8_t) ~0x2d,
		(uint8_t) ~0x6d };

class WS2812Driver {

private:
	UART_HandleTypeDef &huart;
	uint8_t numberOfDiodes;

	uint8_t buffer[NUMBER_OF_DIODES * 8];

public:
	WS2812Driver(UART_HandleTypeDef &huart) : huart(huart), numberOfDiodes(NUMBER_OF_DIODES) {
	}

	uint8_t getNumberOfDiodes();

	void set(uint8_t diode, uint8_t r, uint8_t g, uint8_t b);
	void flush();
};

#endif /* INC_WS2812DRIVER_HPP_ */
