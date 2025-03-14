/**
 * @file StateMachine.cpp
 * @brief StateMachine函数的实现
 * @author 
 * @version 2.4
 */

#include "StateMachine.h"
#include "GameState.h"



StateMachine::StateMachine()
	:_self_ref(*this), _curr("StarMenu") {
	StartMenu start_menu(_self_ref);
	_game_states["StarMenu"] = &start_menu;
	PlayerNum player_num(_self_ref);
	_game_states["PlayerMenu"] = &player_num;
	PlayerInfo player_info(_self_ref);
	_game_states["PlayerMenu"] = &player_info;
	CheckersGame checkers_game(_self_ref);
	_game_states["PlayerMenu"] = &checkers_game;
	WinView win_view(_self_ref);
	_game_states["WinView"] = &win_view;

	this->_game_states[_curr]->enter();
}


/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * @param 鼠标所点击的位置或者键盘的输入字符
	 * @author 李明泽
	 */
void StateMachine::update(ExMessage& msg) {
	StateMachine::_game_states[_curr]->update(msg);
}


/**
 * @brief 游戏渲染
 * @author 李明泽
 */
void StateMachine::render() {
	_game_states[_curr]->render();
}


void StateMachine::changeStateTo(std::string to) {
	cleardevice();
	_curr = to;
	_game_states[_curr]->enter();
}