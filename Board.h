#pragma once

/**
 * @file Board.h
 * @brief ������������Լ���������
 * @author ����
 * @version 1.4
 */

#include "Chess.h"
#include "Player.h"

class Board {
public:

	Board(){}

	bool chessMatchPlayer();

	void moveChess();

private:

	int _width;
	int _height;
	int _sell_size;

	//�����洢���ӵ�����
};

