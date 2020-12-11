/*
 * Colours.hpp
 *
 *  Created on: Dec 10, 2020
 *      Author: Chipotle
 */

#ifndef INC_COLOURS_HPP_
#define INC_COLOURS_HPP_

#include "stm32l0xx_hal.h"

class RgbColor {

public:
	uint8_t r;
	uint8_t g;
	uint8_t b;

	RgbColor(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {
	}

	static RgbColor fromHsv(uint8_t h, uint8_t s, uint8_t v);

};

class HsvColor {

public:
	uint8_t h;
	uint8_t s;
	uint8_t v;

	HsvColor(uint8_t h, uint8_t s, uint8_t v) : h(h), s(s), v(v) {
	}

	static HsvColor fromRgb(uint8_t r, uint8_t g, uint8_t b);

};

#endif /* INC_COLOURS_HPP_ */
