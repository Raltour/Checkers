/**
 * @file MainGame.cpp
 * @author 李明泽
 * @brief 游戏的主函数
 *
 * 该文件包含游戏的主函数和游戏循环逻辑。
 * 在这里初始化了状态机的唯一实例 `mach`，并在其内部保存对自身的引用。
 * 该引用会被传递给所有的 `GameState`，以便在游戏过程中随时进行状态切换和操作。
 *
 * @version 2.5.6
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

		BeginBatchDraw();
		//获取用户输入（鼠标点击或键盘输入）
		while (peekmessage(&meg, EX_MOUSE | EX_KEY, true)) { // true表示移除消息
			mach.update(meg);
		}

		cleardevice();     // 清空画布
		// 渲染当前游戏状态
		mach.render();


		EndBatchDraw();
		Sleep(1);
	}
	closegraph();
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