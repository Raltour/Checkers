#pragma once

/**
 * @file StateMachine.h
 * @author ������
 * @brief �������̿��Ʋ�ȡFSM����״̬��ģʽ��
 *			���ļ���״̬�������ڿ�����Ϸ���̣��ڲ�ͬ�Ľ��桢״̬֮���л���
 * @version 1.0
 */

#include <string>
#include <map>
#include "GameState.h"

class StateMachine{
public:
	std::map<std::string, GameState> gameStates;

	StateMachine() {

	}


	void update(int x, int y);

	void render();

	void changeState(std::string to);

}