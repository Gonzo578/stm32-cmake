/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include <cstdint>
#include "dio.h"

int main(void)
{
	uint32_t i;

	HWSetup();

	for(;;) {
		for(i = 1000000; i>0; i--) {

		}

		ToggleLeds();

		for(i = 1000000; i>0; i--) {

		}

		ToggleLeds();
	}

	return 0;
}
