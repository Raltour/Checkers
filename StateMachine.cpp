/**
 * @file StateMachine.cpp
 * @brief StateMachine函数的实现
 * @author 
 * @version 2.5.7
 */

#include "StateMachine.h"
#include "GameState.h"



StateMachine::StateMachine()
	:_self_ref(*this), _curr("StartMenu") {

	_game_states["StartMenu"] = new StartMenu(_self_ref);
	_game_states["PlayerNum"] = new PlayerNum(_self_ref);
	_game_states["PlayerInfo"] = new PlayerInfo(_self_ref);
	_game_states["ChechersGame"] = new CheckersGame(_self_ref);
	_game_states["WinView"] = new WinView(_self_ref);

	this->_game_states[_curr]->enter();
}


StateMachine::~StateMachine() {
	delete _game_states["StartMenu"];
	delete _game_states["PlayerNum"];
	delete _game_states["PlayerInfo"];
	delete _game_states["ChechersGame"];
	delete _game_states["WinView"];
}


void StateMachine::update(ExMessage& msg) {
	StateMachine::_game_states[_curr]->update(msg);
}


void StateMachine::render() {
	_game_states[_curr]->render();
}


void StateMachine::changeStateTo(std::string to) {
	cleardevice();
	_curr = to;
	_game_states[_curr]->enter();
}