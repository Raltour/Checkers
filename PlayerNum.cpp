/**
 * @file PlayerNum.cpp
 * @brief PlayerNum������ʵ��
 * @author ����
 * @version 1.8
 */

#include "PlayerNum.h"
#include "Render.h"



//���������������PlayerNum��PlayerInfo֮�乲��
extern int _num_of_players;


PlayerNum::PlayerNum(StateMachine& _self_ref)
	:GameState(_self_ref) {
}