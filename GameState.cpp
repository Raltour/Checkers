/**
 * @file GameState.cpp
 * @brief GameState函数的实现
 * @author 张三
 * @version 1.8
 */

#include "StateMachine.h"
#include "GameState.h"


GameState::GameState(StateMachine &mach)
	: _mach(mach) {}