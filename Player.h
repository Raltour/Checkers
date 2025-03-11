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
 * @version 1.8
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
		Player p("1", "3");//为了过编译瞎写的
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
		deleteAllPlayers();
		return false;
	}


	/**
	 * @brief 生成新玩家并放入玩家容器
	 *
	 * 放入容器末尾
	 *
	 * @param 玩家的棋子颜色
	 * @param 玩家的名字
	 * @author 李明泽
	 */
	static void addNewPlayer(std::string color, std::string name) {
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
		return this->_color == chess->_color;
	}


	/**
	 * @brief 根据当前玩家是否已经走完所有棋子，进行处理
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
	* 构建静态玩家容器，用于轮换走棋权
	* 这个容器应当能从一头拿出，也能从一头放入
	* 构建静态胜者容器，游戏结束后根据里面的信息显示名词并更新排行榜积分
	* 这个只要能按顺序存就好了
	* （你们自定用什么结构就行）
	*/






	Player(std::string color, std::string name)
		:_color(color), _name(name) {}

	std::string _color;
	std::string _name;


	/**
	 * @brief 把生成的新玩家放入到玩家容器的末尾
	 *
	 * @author 作者名字
	 */
	void storeNewPlayer() {

	}


	/**
	 * @brief 游戏结束后，释放堆内存
	 *
	 * @return 返回值的描述
	 * @author 作者名字
	 */
	static void deleteAllPlayers() {

	}


	/**
	 * @brief 轮换游戏的走棋权力
	 *
	 * 把玩家容器头部的玩家扔到末尾去
	 *
	 * @author 作者名字
	 */
	void turnToNextPlayer() {
		
	}


	/**
	 * @brief 将胜利了的玩家放入到胜者容器中
	 *
	 * @author 作者名字
	 */
	void moveToWinner() {

	}
};