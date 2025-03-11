#pragma once

/**
 * @file PlayerNum.h
 * @brief 用户选择参与游戏的人数，支持2、4、6人
 * @author 李明泽
 * @version 1.8
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
	 * @author 
	 */
	virtual void update(ExMessage& msg);


	/**
	 * @brief 游戏渲染
	 * @author 
	 */
	virtual void render();


	/**
	 * @brief 进入该状态
	 *
	 * 初始化
	 * 渲染界面
	 *
	 * @author 
	 */
	virtual void enter();


	/**
	 * @brief 退出当前状态
	 * @author 
	 */
	virtual void exit();

};