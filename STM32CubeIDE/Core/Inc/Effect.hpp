/*
 * SteadyColour.hpp
 *
 *  Created on: Dec 7, 2020
 *      Author: Chipotle
 */

#ifndef INC_EFFECT_HPP_
#define INC_EFFECT_HPP_

#include "WS2812Driver.hpp"

class Effect {

protected:
	WS2812Driver &ws2812;

	bool tick();

public:
	Effect(WS2812Driver &ws2812) : ws2812(ws2812) {
	}

	virtual void loop() {};

};

#endif /* INC_EFFECT_HPP_ */
