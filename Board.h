#pragma once

/**
 * @file Board.h
 * @brief ������������Լ���������
 * @author ����
 * @version 1.6
 */

#include "Chess.h"
#include "Player.h"
#include <easyx.h>

class Board {
public:

	Board(){}

	bool isHereAChess(ExMessage& msg, Chess &chess);

	bool moveChess(Chess &chess);//����ֵ���������û��ȡ��ʤ��

private:

	int _width;
	int _height;
	int _sell_size;

	//�����洢���ӵ�����
};

