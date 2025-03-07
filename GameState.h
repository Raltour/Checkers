#pragma once

/**
 * @file GameState.h
 * @author ������
 * @brief ��������Ϸ�Ĳ�ͬ״̬���߱��Ĺ��нӿڣ���״̬��ʹ�á�
 * @version 1.0
 */

#include "StateMachine.h"

class GameState {
	static StateMachine _state_machine();

	virtual void update(int x, int y);

	virtual void render();

	virtual void enter();

	virtual void exit();
};