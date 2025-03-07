#pragma once

/**
 * @file StartMenu.h
 * @author 李明泽
 * @brief 游戏开始时的菜单界面
 * @version 1.0
 */

#include "StateMachine.h"
#include "GameState.h"


class StartMenu : public GameState {
public:
	StartMenu(StateMachine& _self_ref)
		:GameState(_self_ref) {}


	/**
	 * @brief 构造GameState
	 *
	 * 将对StateMachine的引用记录为成员变量，
	 * 确保了全局只使用唯一的一个mach
	 *
	 * @param 鼠标所点击的位置或者键盘的输入字符
	 * @author 李明泽
	 */
	virtual void update() {}


	/**
	 * @brief 游戏渲染
	 * @author 李明泽
	 */
	virtual void render() {}


	/**
	 * @brief 进入该状态
	 *
	 * 初始化
	 * 渲染界面
	 *
	 * @author 李明泽
	 */
	virtual void enter() {}


	/**
	 * @brief 退出当前状态
	 *
	 * 记录、修改必要的数据
	 * 清空界面
	 *
	 * @author 李明泽
	 */
	virtual void exit() {}
};