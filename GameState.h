#pragma once

/**
 * @file GameState.h
 * @author ������
 * @brief ��������Ϸ�Ĳ�ͬ״̬���߱��Ĺ��нӿڣ���״̬��ʹ�á�
 * @version 1.0
 */

#include "StateMachine.h"

class GameState {
public:

	GameState(StateMachine& mach)
		:_mach(mach) {}

	virtual ~GameState();

	virtual void update(int x, int y) = 0;

	virtual void render() = 0;

	virtual void enter() = 0;

	virtual void exit() = 0;



protected:

	/*
	* �ڹ��캯���ж�������ý��г�ʼ����
	* �������е�GameState�����Բ�����MainGame�ж����Ψһһ��״̬��ʵ����
	* ���������Ϸ���Ʒ�������
	*/
	StateMachine& _mach;
};