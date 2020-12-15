/*
 * SteadyColour.hpp
 *
 *  Created on: Dec 7, 2020
 *      Author: Chipotle
 */

#ifndef INC_EFFECTS_STEADYCOLOUR_HPP_
#define INC_EFFECTS_STEADYCOLOUR_HPP_

#include "..\Effect.hpp"

class SteadyColour: public Effect {

private:
	static uint8_t delays[];

	uint8_t delayIndex = 5;

	bool sendColour(uint8_t h, uint8_t s, uint8_t v);

public:
	SteadyColour(WS2812Driver &ws2812, Encoder &encoder) : Effect(ws2812, encoder, 50) {
	}

	void loop();

};

#endif /* INC_EFFECTS_STEADYCOLOUR_HPP_ */
