#pragma once

/**
 * @file StateMachine.h
 * @author 李明泽
 * @brief 整体流程控制采取FSM有限状态机模式。
 *			该文件是状态机，用于控制游戏流程，在不同的界面、状态之间切换。
 * @version 1.0
 */

#include <string>
#include <map>
#include "GameState.h"

class StateMachine {
public:

	StateMachine() {

	}

	void update(int x, int y);

	void render();

	void changeStateTo(std::string to);


private:

	std::map<std::string, GameState> _gameStates;
};