#pragma once

/**
 * @file StartMenu.h
 * @author 李明泽
 * @brief 游戏开始时的菜单界面
 * @version 2.5.3
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"


class StartMenu : public GameState {
public:
	StartMenu(StateMachine& _self_ref);


	/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * @param 鼠标所点击的位置或者键盘的输入字符
	 * @author 李明泽
	 */
	virtual void update(ExMessage& msg);


	/**
	 * @brief 游戏渲染
	 * @author 李明泽
	 */
	virtual void render();


	/**
	 * @brief 进入该状态
	 *
	 * 初始化
	 * 渲染界面
	 *
	 * @author 李明泽
	 */
	virtual void enter();

private:

	Button b1;
	Button b2;
};