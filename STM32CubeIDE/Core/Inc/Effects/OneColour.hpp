/*
 * SteadyColour.hpp
 *
 *  Created on: Dec 7, 2020
 *      Author: Chipotle
 */

#ifndef INC_EFFECTS_ONECOLOUR_HPP_
#define INC_EFFECTS_ONECOLOUR_HPP_

#include "..\Effect.hpp"

class OneColour: public Effect {

private:

public:
	OneColour(WS2812Driver &ws2812, Encoder &encoder) : Effect(ws2812, encoder, 20) {
	}

	void loop();

};

#endif /* INC_EFFECTS_ONECOLOUR_HPP_ */
