/**
 * @file MainGame.cpp
 * @author 李明泽
 * @brief 游戏的主函数
 *
 * 该文件包含游戏的主函数和游戏循环逻辑。
 * 在这里初始化了状态机的唯一实例 `mach`，并在其内部保存对自身的引用。
 * 该引用会被传递给所有的 `GameState`，以便在游戏过程中随时进行状态切换和操作。
 *
 * @version 2.5
 */

#include "StateMachine.h"
#include <easyx.h>


 /**
  * @brief 游戏循环
  *
  * 该函数是游戏的主循环，负责初始化状态机、处理用户输入、更新游戏状态和渲染画面。
  * 全局仅在此处初始化唯一的 `StateMachine` 实例。
  * 循环中不断获取用户输入的消息，更新状态机状态，并刷新一帧画面。
  *
  * @author 李明泽
  */
void gameLoop() {
	StateMachine mach; // 初始化状态机实例
	ExMessage meg;     // 用于存储用户输入的消息

	while (true) {
		// 获取用户输入（鼠标点击或键盘输入）
		getmessage(&meg);

		// 更新状态机状态
		mach.update(meg);

		// 渲染当前游戏状态
		mach.render();
	}
}

/**
 * @brief 程序入口
 *
 * 主函数，调用gameLoop启动游戏循环。
 *
 * @author 李明泽
 */
int main() {
	// 启动游戏循环
	gameLoop();

	return 0;
}