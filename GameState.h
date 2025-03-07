#pragma once

/**
 * @file GameState.h
 * @author 李明泽
 * @brief 定义了游戏的不同状态所具备的共有接口，供状态机使用。
 * @version 1.0
 */

#include "StateMachine.h"

class GameState {
public:
	virtual void update(int x, int y) = 0;

	virtual void render() = 0;

	virtual void enter() = 0;

	virtual void exit() = 0;



protected:

	static StateMachine _state_machine();
};