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
#include "adder.h"

int main(void)
{
	uint32_t i;
	uint32_t Result = 0;
	Adder AddComponent;

	HWSetup();

	for(;;) {
		for(i = 1000000; i>0; i--) {
			Result = AddComponent.add(i, Result);
		}

		ToggleLeds();

		for(i = 1000000; i>0; i--) {

		}

		ToggleLeds();
	}

	return 0;
}
