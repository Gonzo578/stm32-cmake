#include "led.h"
#include "dio.h"

void Led::switchOn(void) {
	SetPin();
	_state = State::ON;
}

void Led::switchOff(void) {
	ResetPin();
	_state = State::OFF;
}

Led::State Led::getState (void) {
	return _state;
}
