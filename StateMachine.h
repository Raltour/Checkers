#pragma once

/**
 * @file StateMachine.h
 * @author ������
 * @brief �������̿��Ʋ�ȡFSM����״̬��ģʽ��
 * 
 *���ļ���״̬�������ڿ�����Ϸ���̣��ڲ�ͬ�Ľ��桢״̬֮���л���
 * 
 * @version 1.0
 */

#include <string>
#include <map>
#include "GameState.h"

class StateMachine {
public:

	/*
	* ��ʼ�����������
	* ��һ����Ϸ״̬�ǲ˵�
	* ��¼�����������
	*/
	StateMachine()
		:_self_ref(*this), _curr("StarMenu") {}

	~StateMachine();

	void update(int x, int y);

	void render();

	void changeStateTo(std::string to);


private:

	std::string _curr;
	std::map<std::string, GameState> _gameStates;
	StateMachine& _self_ref;
};