/**
 * @file PlayerInfo.h
 * @brief PlayerInfo函数的实现
 * @author 
 * @version 2.4
 */

#include "StateMachine.h"
#include "Render.h"
#include "Player.h"
#include <vector>
#include "PlayerInfo.h"

//储存玩家数量，在PlayerNum和PlayerInfo之间共享
extern int _num_of_players;


PlayerInfo::PlayerInfo(StateMachine& _self_ref)
	:GameState(_self_ref) {
}


void PlayerInfo::update(ExMessage& msg) {

	//退出该界面时，根据已有信息生成对应的玩家
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

