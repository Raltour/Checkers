#pragma once

/**
 * @file Board.h
 * @brief 棋盘数据设计以及操作函数
 * @author 张三
 * @version 1.6
 */

#include "Chess.h"
#include "Player.h"
#include <easyx.h>
#include <string>

class Board {
public:

	Board(){}


	/**
	 * @brief 判断鼠标点击的位置是不是一个棋子
	 *
	 * 详细描述函数的功能、参数、返回值等信息。
	 *
	 * @param 鼠标信息
	 * @return 如果是一个棋子，则将指针返回；否则返回空即可
	 * @author 作者名字
	 */
	Chess* isHereAChess(ExMessage &msg);


	/**
	 * @brief 根据后续的鼠标输入，移动棋子
	 *
	 * 进行完所有的移动后，立刻检测这个棋子对应的玩家有没有胜利
	 * 通过向isChessWin传递该棋子的颜色进行判断
	 *
	 * @param 需要移动的棋子的地址
	 * @return 玩家是否胜利
	 * @author 作者名字
	 */
	bool moveChess(Chess *chess);//返回值：该玩家有没有取得胜利

private:

	int _width;
	int _height;
	int _sell_size;

	//构建存储棋子的容器





	bool isChessWin(std::string color)
};

