/**
 * @file MainGame.cpp
 * @author 李明泽
 * @brief 游戏的主函数
 * 
 *这里初始化了状态机的实例mach，并且在其内部保存对自身的引用，
 并将该引用传给所有的GameState，以便随时对其进行操作
 * 
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