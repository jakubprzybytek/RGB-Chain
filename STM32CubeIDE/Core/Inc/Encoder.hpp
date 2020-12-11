/*
 * Encoder.hpp
 *
 *  Created on: Dec 11, 2020
 *      Author: Chipotle
 */

#ifndef INC_ENCODER_HPP_
#define INC_ENCODER_HPP_

#include "stm32l0xx_hal.h"

class Encoder {

private:
	TIM_HandleTypeDef &htim;
	bool pressed;

public:
	Encoder(TIM_HandleTypeDef &htim) : htim(htim) {
	}

	void setPressed();
	bool getPressed();

	void setPosition(uint8_t position);
	uint8_t getPosition();

};

#endif /* INC_ENCODER_HPP_ */
