#pragma once

/**
 * @file Board.h
 * @brief ������������Լ���������
 * @author ����
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

	//�����洢���ӵ�����
};

