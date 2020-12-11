#include "Encoder.hpp"

void Encoder::setPressed() {
	pressed = true;
}

bool Encoder::getPressed() {
	if (pressed) {
		pressed = false;
		return true;
	}
	return false;
}

void Encoder::setPosition(uint8_t position) {
	htim.Instance->CNT = position;
}

uint8_t Encoder::getPosition() {
	return (uint8_t) htim.Instance->CNT;
}
