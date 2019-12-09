/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "../contrib/CMSIS/device/stm32f4xx.h"
#include <cstdint>

static void HWSetup(void)  {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->ODR   |= 0x0000F000;
	GPIOD->MODER |= 0x55000000;
}

int main(void)
{
	uint32_t i;
	HWSetup();

	for(;;) {
		for(i = 1000000; i>0; i--) {

		}

		GPIOD->BSRR = 0xF0000000;

		for(i = 1000000; i>0; i--) {

		}

		GPIOD->BSRR = 0x0000F000;
	}

	return 0;
}
