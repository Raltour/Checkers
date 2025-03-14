#pragma once

/**
 * @file WinView.h
 * @brief 胜利结算画面
 * @author 李明泽
 * @version 2.4
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"


class WinView : public GameState {
public:

	WinView(StateMachine& _self_ref);


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
	 * 初始化玩家数量
	 *
	 * @author
	 */
	virtual void enter();

private:

	std::vector<std::string> names;
	std::vector<std::string> colors;

};