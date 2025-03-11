#pragma once

/**
 * @file WinView.h
 * @brief 胜利结算画面
 * @author 
 * @version 1.8
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"


class WinView : public GameState {
public:

	WinView(StateMachine& _self_ref)
		:GameState(_self_ref) {
	}


	/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * @param 鼠标所点击的位置或者键盘的输入字符
	 * @author
	 */
	virtual void update(ExMessage& msg) {}


	/**
	 * @brief 游戏渲染
	 * @author
	 */
	virtual void render() {}


	/**
	 * @brief 进入该状态
	 *
	 * 初始化玩家数量
	 *
	 * @author
	 */
	virtual void enter() {

	}


	/**
	 * @brief 退出时生成给定数量的玩家
	 *
	 * 利用私有的字符串成员变量，依次生成对应的这些玩家
	 *
	 * @author 
	 */
	virtual void exit() {
		cleardevice();
	}

private:

	std::vector<std::string> names;
	std::vector<std::string> colors;

};