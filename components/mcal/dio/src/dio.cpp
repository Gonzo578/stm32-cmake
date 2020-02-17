#include "dio.h"
#include "stm32f4xx.h"
#include <cstdint>

static uint8_t ToggleState = 0;

void HWSetup(void)  {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->ODR   |= 0x0000F000;
	GPIOD->MODER |= 0x55000000;
}

void ToggleLeds(void) {
	if(ToggleState == 0) {
		ToggleState = 1;
		GPIOD->BSRR = 0x30000000;
		//GPIOD->BSRR = 0xF0000000;
	} else {
		ToggleState = 0;
		GPIOD->BSRR = 0x00003000;
		//GPIOD->BSRR = 0x0000F000;
	}
}
