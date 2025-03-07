/**
 * @file MainGame.cpp
 * @author 李明泽
 * @brief 游戏的主函数
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