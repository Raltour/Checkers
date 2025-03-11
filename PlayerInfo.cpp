/**
 * @file PlayerInfo.h
 * @brief PlayerInfo函数的实现
 * @author 张三
 * @version 1.8
 */

#include "StateMachine.h"
#include "GameState.h"
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

}


void PlayerInfo::render() {

}


void PlayerInfo::enter() {

}


void PlayerInfo::exit() {
	for (int i = 0; i < _num_of_players; i++) {
		Player::addNewPlayer(colors[i], names[i]);
	}
	cleardevice();
}