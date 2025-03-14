#pragma once

/**
 * @file StateMachine.h
 * @author 李明泽
 * @brief 整体流程控制采取FSM有限状态机模式。
 * 
 * 该文件是状态机，用于控制游戏流程，在不同的界面、状态之间切换。
 * 
 * @version 2.4
 */

#include <string>
#include <map>
#include "StartMenu.h"
#include "PlayerNum.h"
#include "PlayerInfo.h"
#include "CheckersGame.h"
#include "WinView.h"
#include <easyx.h>
class GameState;

class StateMachine {
public:

	/*
	* 初始化，无需参数
	* 第一个游戏状态是菜单
	* 记录对自身的引用
	*/
	StateMachine();


	~StateMachine() {}


	/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * @param 鼠标所点击的位置或者键盘的输入字符
	 * @author 李明泽
	 */
	void update(ExMessage& msg);


	/**
	 * @brief 游戏渲染
	 * @author 李明泽
	 */
	void render();


	/**
	 * @brief 更新状态机所处的游戏状态位置
	 * 
	 * 退出原状态
	 * 对传入的字符串进行映射，将其变为对应的GameState
	 * 进入新状态
	 * 
	 * @param 传入表示下一状态名称的字符串
	 * @author 李明泽
	 */
	void changeStateTo(std::string to);


private:


	std::string _curr;//记录游戏当前状态
	std::map<std::string, GameState*> _game_states;//将字符串名称映射为对应的GameState
	StateMachine& _self_ref;//对自身的引用，构建GameState时作为参数传入

};