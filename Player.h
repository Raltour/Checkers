#pragma once

/**
 * @file Player.h
 * @brief 记录参与游戏的玩家
 * 
 * 建立一个数据结构，内置参与游戏的所有玩家
 * 利用不同Players之间的循环，实现轮流控制棋子行走的功能
 * 文件中所有函数功能都很简单，不需要单独建立源文件了
 * 直接在该文件中实现所有功能
 * 
 * @author 李明泽
 * @version 2.3
 */

#include "Chess.h"
#include <string>

class Player {
public:

	/**
	 * @brief 返回当前要走棋子的玩家
	 *
	 * @return 玩家容器最前端的一个人
	 * @author 作者名字
	 */
	static Player& getCurrentPlayer() {
		Player p(WHITE, "3");//为了过编译瞎写的
		return p;
	}


	/**
	 * @brief 判断游戏是否已经结束，清空堆内存
	 *
	 * 只需查看玩家容器是不是只剩一个人了
	 * 
	 * @return 布尔值
	 * @author 作者名字
	 */
	static bool isGameOver() {

		return false;
	}


	/**
	 * @brief 生成新玩家并放入玩家容器
	 *
	 * 将生成的玩家放到玩家容器的末尾
	 *
	 * @param 玩家的棋子颜色
	 * @param 玩家的名字
	 * @author 李明泽
	 */
	static void addNewPlayer(COLORREF color, std::string name) {
		Player* p = new Player(color, name);
		p->storeNewPlayer();
	}


	/**
	 * @brief 检测棋子是否属于玩家
	 *
	 * @return 布尔值
	 * @author 李明泽
	 */
	bool chessMatchPlayer(Chess* chess) {
		return this->_color == chess->color();
	}


	/**
	 * @brief 根据当前玩家是否已经走完所有棋子，进行处理
	 * 
	 * 如果确实获胜，将当前玩家挪入到胜者容器中
	 * 不再放入玩家容器
	 *
	 * @param Board中的检测函数的返回值
	 * @author 李明泽
	 */
	void isWin(bool b) {
		if (b) {
			this->moveToWinner();
		}
		turnToNextPlayer();
	}


private:

	/*
	* 构建静态玩家容器，用于轮换走棋权，内部储存指针
	* 这个容器应当能从一头拿出，也能从一头放入
	* 构建静态胜者容器，游戏结束后根据里面的信息显示名词并更新排行榜积分
	* 这个只要能按顺序存就好了
	* （你们自定用什么结构就行）
	*/






	Player(COLORREF color, std::string name)
		:_color(color), _name(name) {}

	COLORREF _color;
	std::string _name;


	/**
	 * @brief 把生成的新玩家放入到玩家容器的末尾
	 *
	 * 该函数将调用自身的玩家的指针放入到容器中
	 * 
	 * @author 作者名字
	 */
	void storeNewPlayer() {

	}


	/**
	 * @brief 游戏结束后，释放堆内存
	 *
	 * 必须要在胜利结算画面退出时使用这个函数
	 * 将玩家容器和胜者容器中的所有指针所指的对象清除掉
	 * 释放堆内存
	 * 
	 * @return 返回值的描述
	 * @author 作者名字
	 */
	static void deleteAllPlayers() {

	}


	/**
	 * @brief 轮换游戏的走棋权
	 *
	 * 把玩家容器头部的玩家扔到末尾去即可
	 *
	 * @author 作者名字
	 */
	void turnToNextPlayer() {
		
	}


	/**
	 * @brief 将胜利了的玩家放入到胜者容器中
	 *
	 * 不需要检测是否获胜，
	 * 这个函数就是在已知玩家胜利后，移动位置用的
	 * 
	 * @author 作者名字
	 */
	void moveToWinner() {

	}
};