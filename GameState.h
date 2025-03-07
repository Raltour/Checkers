#pragma once

/**
 * @file GameState.h
 * @author 李明泽
 * @brief 定义了游戏的不同状态所具备的共有接口，供状态机使用。
 * @version 1.0
 */

#include "StateMachine.h"

class GameState {
	static StateMachine _state_machine();

	virtual void update(int x, int y);

	virtual void render();

	virtual void enter();

	virtual void exit();
};