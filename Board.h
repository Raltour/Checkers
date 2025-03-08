#pragma once

/**
 * @file Board.h
 * @brief 棋盘数据设计以及操作函数
 * @author 张三
 * @version 1.5
 */

#include "Chess.h"
#include "Player.h"
#include <easyx.h>

class Board {
public:

	Board(){}

	bool chessMatchPlayer();

	bool isHereAChess(ExMessage& msg, Chess &_chess);

	void moveChess();

private:

	int _width;
	int _height;
	int _sell_size;

	//构建存储棋子的容器
};

