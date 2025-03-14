#pragma once

/**
 * @file PlayerNumber.h
 * @brief 填入各个玩家的姓名，随后生成玩家
 * @author 李明泽
 * @version 2.4
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"
#include "Player.h"
#include <vector>

class PlayerInfo : public GameState {
public:

	PlayerInfo(StateMachine& _self_ref);


	/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * 退出该界面时，根据输入的玩家信息生成对应的若干玩家
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
	 * @author
	 */
	virtual void enter();


private:

	std::vector<std::string> names;
	std::vector<COLORREF> colors;

};