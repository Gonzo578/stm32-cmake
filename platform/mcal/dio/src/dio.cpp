#include "dio.h"
#include "stm32g4xx.h"
#include <cstdint>

static uint8_t ToggleState = 0;

void HWSetup(void)  {
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER = 0xABFFF7FF;
	GPIOA->ODR   |= 0x00000020;
}

void ToggleLeds(void) {
	if(ToggleState == 0) {
		ToggleState = 1;
		GPIOA->BSRR = 0x00000020;
	} else {
		ToggleState = 0;
		GPIOA->BSRR = 0x00200000;
	}
}
