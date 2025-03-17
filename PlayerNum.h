#pragma once

/**
 * @file PlayerNum.h
 * @brief 用户选择参与游戏的人数，支持2、4、6人
 * @author 李明泽
 * @version 2.5.8
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"

class PlayerNum : public GameState {
public:

	PlayerNum(StateMachine& _self_ref);


	/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * @param 鼠标所点击的位置或者键盘的输入字符
	 * @author 杜云飞
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
	Button btn2;
	Button btn4;
	Button btn6;
};