/*
 * SteadyColour.hpp
 *
 *  Created on: Dec 7, 2020
 *      Author: Chipotle
 */

#ifndef INC_EFFECTS_STEADYCOLOUR_HPP_
#define INC_EFFECTS_STEADYCOLOUR_HPP_

#include "..\WS2812Driver.hpp"

class SteadyColour {

private:
	WS2812Driver &ws2812;

	void tick();

public:
	SteadyColour(WS2812Driver &ws2812) : ws2812(ws2812) {
	}

	void loop();

};

#endif /* INC_EFFECTS_STEADYCOLOUR_HPP_ */
