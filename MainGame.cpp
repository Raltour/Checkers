/**
 * @file MainGame.cpp
 * @author 李明泽
 * @brief 游戏的主函数
 * 
 * 这里初始化了状态机的实例mach，并且在其内部保存对自身的引用，
 * 并将该引用传给所有的GameState，以便随时对其进行操作
 * 
 * @version 2.0
 */

#include "StateMachine.h"
#include <easyx.h>


 /**
  * @brief 游戏循环
  *
  * 全局仅在此处初始化唯一的StateMachine实例
  * 获取用户输入的消息，更新状态，然后刷新一帧
  *
  * @author 李明泽
  */
void gameLoop() {
	StateMachine mach;
	ExMessage meg;
	while (true) {
		peekmessage(&meg);
		mach.update(meg);
		mach.render();
	}
}

int main() {
	gameLoop();

	return 0;
}


//文件注释规范
/**
 * @file MyClass.cpp
 * @brief 该文件实现了 MyClass 类的功能。
 * @author 张三
 * @version 1.0
 */


//函数注释规范
/**
 * @brief 函数功能的简要描述
 *
 * 详细描述函数的功能、参数、返回值等信息。
 *
 * @param 参数1 描述参数1的作用
 * @param 参数2 描述参数2的作用
 * @return 返回值的描述
 * @author 作者名字
 */