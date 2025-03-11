/**
 * @file PlayerNum.cpp
 * @brief PlayerNum函数的实现
 * @author 张三
 * @version 1.8
 */

#include "PlayerNum.h"
#include "Render.h"



//储存玩家数量，在PlayerNum和PlayerInfo之间共享
extern int _num_of_players = 10;//为了过编译随便写的


PlayerNum::PlayerNum(StateMachine& _self_ref)
	:GameState(_self_ref) {
}