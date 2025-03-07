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

class StateMachine{
public:
	std::map<std::string, GameState> gameStates;

	StateMachine() {

	}


	void update(int x, int y);

	void render();

	void changeState(std::string to);

}