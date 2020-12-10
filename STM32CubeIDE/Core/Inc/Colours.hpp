/*
 * Colours.hpp
 *
 *  Created on: Dec 10, 2020
 *      Author: Chipotle
 */

#ifndef INC_COLOURS_HPP_
#define INC_COLOURS_HPP_

#include "stm32l0xx_hal.h"

typedef struct RgbColor {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} RgbColor;

typedef struct HsvColor {
	uint8_t h;
	uint8_t s;
	uint8_t v;
} HsvColor;

RgbColor HsvToRgb(HsvColor hsv);
HsvColor RgbToHsv(RgbColor rgb);

#endif /* INC_COLOURS_HPP_ */
