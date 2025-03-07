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
	virtual void update(int x, int y) = 0;

	virtual void render() = 0;

	virtual void enter() = 0;

	virtual void exit() = 0;



protected:

	static StateMachine _state_machine();
};