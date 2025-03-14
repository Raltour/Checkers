/**
 * @file PlayerInfo.h
 * @brief PlayerInfo������ʵ��
 * @author 
 * @version 2.4
 */

#include "StateMachine.h"
#include "Render.h"
#include "Player.h"
#include <vector>
#include "PlayerInfo.h"

//���������������PlayerNum��PlayerInfo֮�乲��
extern int _num_of_players;


PlayerInfo::PlayerInfo(StateMachine& _self_ref)
	:GameState(_self_ref) {
}


void PlayerInfo::update(ExMessage& msg) {

	//�˳��ý���ʱ������������Ϣ���ɶ�Ӧ�����
	if (true) {
		for (int i = 0; i < _num_of_players; i++) {
			Player::addNewPlayer(colors[i], names[i]);
		}
		cleardevice();
	}
}


void PlayerInfo::render() {

}


void PlayerInfo::enter() {

}

