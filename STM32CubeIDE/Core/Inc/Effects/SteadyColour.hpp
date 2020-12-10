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
	bool sendColour(uint8_t h, uint8_t v);

public:
	SteadyColour(WS2812Driver &ws2812) : Effect(ws2812) {
	}

	void loop();

};

#endif /* INC_EFFECTS_STEADYCOLOUR_HPP_ */
