#pragma once

class Led {
public:
	enum class State {
		OFF,
		ON
	};

	Led(State dflt) : _state(dflt) {};

	void switchOn(void);
	void switchOff(void);

	State getState (void);

private:
	State 	_state;		//< Switch state of the led
};
