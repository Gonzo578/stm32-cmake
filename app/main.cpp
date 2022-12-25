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
#include "BSP_setup.h"
#include "dio.h"
#include "led.h"
#include "IObserver.h"
#include "obs_example.h"
#include "fpmath.h"

Led LifeLED{Led::State::OFF};
ObsExampleObj_t  OBS_DemoObj;

static void NotifyStateChange_CB(void) {
	ObsDemoState_t _state;
	TPolNum polNum = {0, 0};
	TCartNum cartNum = {FP(0.5), FP(0.5)};
	TAngle angle = 0;

	_state = OBS_GetDemoState(&OBS_DemoObj);

	if(_state == ON) {
		SetPin();
		FPM_vCart2Pol(&cartNum, &polNum);
		ResetPin();
		angle = polNum.siAngle;
		if(angle < 10) {
			angle ++;
		}
	} else {
		//LifeLED.switchOff();
	}
}

int main(void)
{
	Observer_t DemoObsObj;
	
	BSP_HWSetup();

	OBS_CreateObserver(&DemoObsObj, NotifyStateChange_CB);
	OBS_CreateObserverDemo(&OBS_DemoObj);
	OBS_AttachObserver(&OBS_DemoObj, &DemoObsObj);

	for(;;) {
		(void)OBS_HandleOberverDemo(&OBS_DemoObj);		
	}

	return 0;
}
