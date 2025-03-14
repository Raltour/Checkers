/**
 * @file PlayerNum.cpp
 * @brief PlayerNum函数的实现
 * @author 
 * @version 2.4
 */

#include "PlayerNum.h"
#include "Render.h"


//储存玩家数量，在PlayerNum和PlayerNum之间共享
extern int _num_of_players = 10;//为了过编译随便写的


PlayerNum::PlayerNum(StateMachine& _self_ref)
	:GameState(_self_ref) {
}


void PlayerNum::update(ExMessage& msg) {

}


void PlayerNum::render() {

}


void PlayerNum::enter() {

}


void PlayerNum::exit() {
	
}