/*
 * SteadyColour.hpp
 *
 *  Created on: Dec 7, 2020
 *      Author: Chipotle
 */

#ifndef INC_EFFECT_HPP_
#define INC_EFFECT_HPP_

#include "WS2812Driver.hpp"
#include "Encoder.hpp"

class Effect {

protected:
	WS2812Driver &ws2812;
	Encoder &encoder;

	uint8_t tickDelay;

	bool tick();

public:
	Effect(WS2812Driver &ws2812, Encoder &encoder, uint8_t tickDelay) : ws2812(ws2812), encoder(encoder), tickDelay(tickDelay) {}

	virtual void loop() {};

};

#endif /* INC_EFFECT_HPP_ */
