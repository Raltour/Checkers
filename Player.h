#pragma once

/**
 * @file Player.h
 * @brief 记录参与游戏的玩家
 * 
 * 建立一个数据结构，内置参与游戏的所有玩家
 * 利用不同Players之间的循环，实现轮流控制棋子行走的功能
 * 
 * @author 李明泽
 * @version 1.2
 */

#include "Chess.h"
#include <string>

class Player {
public:
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
	static Player& getCurrentPlayer() {
		return;
	}


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
	static bool isGameOver() {
		return false;
	}

private:
	//构建静态玩家双端队列、静态胜者栈

	std::string _color;



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
	void turnToNextPlayer() {
		
	}


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
	bool isWin() {

	}


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
	void currToWinner() {

	}
};