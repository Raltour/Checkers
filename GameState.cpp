#include "StateMachine.h"
#include "GameState.h"


GameState::GameState(StateMachine &mach)
	: _mach(mach) {}