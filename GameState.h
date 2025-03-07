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

	GameState(StateMachine& mach)
		:_mach(mach) {}

	virtual ~GameState();

	virtual void update(int x, int y) = 0;

	virtual void render() = 0;

	virtual void enter() = 0;

	virtual void exit() = 0;



protected:

	/*
	* 在构造函数中对这个引用进行初始化，
	* 这样所有的GameState都可以操作在MainGame中定义的唯一一个状态机实例，
	* 避免后续游戏控制发生混乱
	*/
	StateMachine& _mach;
};