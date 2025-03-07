/**
 * @file MainGame.cpp
 * @author ������
 * @brief ��Ϸ��������
 * @version 1.0
 */

#include "StateMachine.h"

void gameLoop() {
	StateMachine mach;
	while (true) {
		mach.update(0, 0);
		mach.render();
	}
}

int main() {
	gameLoop();

	return 0;
}