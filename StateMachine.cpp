/**
 * @file StateMachine.cpp
 * @brief StateMachine������ʵ��
 * @author 
 * @version 2.4
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


/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author ������
	 */
void StateMachine::update(ExMessage& msg) {
	StateMachine::_game_states[_curr]->update(msg);
}


/**
 * @brief ��Ϸ��Ⱦ
 * @author ������
 */
void StateMachine::render() {
	_game_states[_curr]->render();
}


void StateMachine::changeStateTo(std::string to) {
	cleardevice();
	_curr = to;
	_game_states[_curr]->enter();
}