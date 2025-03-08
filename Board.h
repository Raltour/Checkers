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
#include <string>

class Board {
public:

	Board(){}


	/**
	 * @brief �ж��������λ���ǲ���һ������
	 *
	 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
	 *
	 * @param �����Ϣ
	 * @return �����һ�����ӣ���ָ�뷵�أ����򷵻ؿռ���
	 * @author ��������
	 */
	Chess* isHereAChess(ExMessage &msg);


	/**
	 * @brief ���ݺ�����������룬�ƶ�����
	 *
	 * ���������е��ƶ������̼��������Ӷ�Ӧ�������û��ʤ��
	 * ͨ����isChessWin���ݸ����ӵ���ɫ�����ж�
	 *
	 * @param ��Ҫ�ƶ������ӵĵ�ַ
	 * @return ����Ƿ�ʤ��
	 * @author ��������
	 */
	bool moveChess(Chess *chess);//����ֵ���������û��ȡ��ʤ��

private:

	int _width;
	int _height;
	int _sell_size;

	//�����洢���ӵ�����





	bool isChessWin(std::string color)
};

