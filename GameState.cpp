/**
 * @file GameState.cpp
 * @brief GameState������ʵ��
 * @author ����
 * @version 1.8
 */

#include "StateMachine.h"
#include "GameState.h"


GameState::GameState(StateMachine &mach)
	: _mach(mach) {}