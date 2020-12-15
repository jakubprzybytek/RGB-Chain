#include "WS2812Driver.hpp"

uint8_t WS2812Driver::getNumberOfDiodes() {
	return numberOfDiodes;
}

void WS2812Driver::set(uint8_t diode, uint8_t r, uint8_t g, uint8_t b) {
	uint8_t* buf = buffer + (diode * 8);
	uint32_t value = (gamma8[r] << 16) | (gamma8[g] << 8) | gamma8[b];

	for (int i = 0; i < 8; i++) {
		uint32_t tmp = (value >> 21) & 0x7;
		*buf++ = ws_code[tmp];
		value <<= 3;
	}
}

void WS2812Driver::flush() {
	HAL_UART_Transmit(&huart, buffer, sizeof(buffer), HAL_MAX_DELAY);
}
