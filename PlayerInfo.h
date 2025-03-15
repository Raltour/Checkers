#pragma once

/**
 * @file PlayerNumber.h
 * @brief 填入各个玩家的姓名，随后生成玩家
 * @author 李明泽
 * @version 2.5.3
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"
#include "Player.h"
#include <vector>
#include "TextBox.h"

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
	 * @author 李明泽
	 */
	virtual void render();


	/**
	 * @brief 进入该状态时做出对应调整
	 * @author 李明泽
	 */
	virtual void enter();


private:

	//储存所有输入的玩家昵称
	std::vector<std::string> names;
	//储存各个玩家的对应颜色
	std::vector<COLORREF> colors;

	std::vector<TextBox*> b;
	Button btnSubmit;
};