#include "main.h"

#include "RgbChain.hpp"

#include "WS2812Driver.hpp"
#include "Effects/SteadyColour.hpp"
#include "Effects/OneColour.hpp"

extern UART_HandleTypeDef huart2;

WS2812Driver ws2812(huart2);

bool changeEffect = false;

SteadyColour steadyColour(ws2812);
OneColour oneColour(ws2812);

#define NUMBER_OF_EFFECTS 2
Effect *effects[NUMBER_OF_EFFECTS] = { &steadyColour, &oneColour };
uint8_t effectIndex = 0;

void RgbChain_Init() {
	HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, GPIO_PIN_SET);
}

void RgbChain_Loop() {
	while (1) {
		effects[effectIndex]->loop();
		effectIndex = effectIndex < NUMBER_OF_EFFECTS - 1 ? effectIndex + 1 : 0;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	HAL_GPIO_TogglePin(Led_GPIO_Port, Led_Pin);
	changeEffect = true;
}
