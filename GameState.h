#pragma once

/**
 * @file GameState.h
 * @author 李明泽
 * @brief 定义了游戏的不同状态所具备的共有接口，供状态机使用。
 */

#include "Render.h"

class StateMachine;

class GameState {
public:

	/**
	 * @brief 构造GameState
	 *
	 * 将对StateMachine的引用记录为成员变量，
	 * 确保了全局只使用唯一的一个mach
	 * 
	 * @param 对mach的引用
	 * @author 李明泽
	 */
	GameState(StateMachine& mach) 
		:_mach(mach) {}


	/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * @param 鼠标所点击的位置或者键盘的输入字符
	 * @author 李明泽
	 */
	virtual void update(ExMessage &msg) = 0;


	/**
	 * @brief 游戏渲染
	 * @author 李明泽
	 */
	virtual void render() = 0;


	/**
	 * @brief 进入该状态
	 * 
	 * 初始化
	 * 渲染界面
	 * 
	 * @author 李明泽
	 */
	virtual void enter() = 0;



protected:

	/*
	* 在构造函数中对这个引用进行初始化，
	* 这样所有的GameState都可以继承这个引用，进而操作在MainGame中定义的唯一一个状态机实例，
	* 进而操作在MainGame中定义的唯一一个状态机实例，避免后续游戏控制发生混乱
	*/
	StateMachine& _mach;

};