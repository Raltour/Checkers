#pragma once

/**
 * @file StartMenu.h
 * @author 李明泽
 * @brief 游戏开始时的菜单界面
 * @version 1.4
 */

#include "StateMachine.h"
#include "GameState.h"


class StartMenu : public GameState {
public:
	StartMenu(StateMachine& _self_ref)
		:GameState(_self_ref) {}


	/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * @param 鼠标所点击的位置或者键盘的输入字符
	 * @author 
	 */
	virtual void update() {}


	/**
	 * @brief 游戏渲染
	 * @author 
	 */
	virtual void render() {}


	/**
	 * @brief 进入该状态
	 *
	 * 初始化
	 * 渲染界面
	 *
	 * @author 
	 */
	virtual void enter() {}


	/**
	 * @brief 退出当前状态
	 *
	 * 记录、修改必要的数据
	 * 清空界面
	 *
	 * @author 
	 */
	virtual void exit() {}
};