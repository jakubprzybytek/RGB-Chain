#include "main.h"

#include "RgbChain.hpp"

#include "WS2812Driver.hpp"
#include "Effects/SteadyColour.hpp"

extern UART_HandleTypeDef huart2;

WS2812Driver ws2812(huart2);

SteadyColour steadyColour(ws2812);

void RgbChain_Init() {
	HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, GPIO_PIN_SET);
}

void RgbChain_Loop() {
	steadyColour.loop();
}
