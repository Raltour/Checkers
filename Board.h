#pragma once

/**
 * @file Board.h
 * @brief ������������Լ���������
 * @author ����
 * @version 2.0
 */

#include "Chess.h"
#include "Player.h"
#include <easyx.h>
#include <string>

class Board {
public:

	Board(){
		_width = 1;
		_height = 1;
		_sell_size = 1;
	}


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

	//�����洢���ӵ�������������Ҫ�����������Ϣ��������CheckersGame���ν����캯��




	/**
	 * @brief �ж��ƶ���ɺ���û��ʤ��
	 * 
	 * �����ϵ���ɫ�ֲ��ǹ̶��ģ��������Ӧ��ȥ��λ��
	 *
	 * @param ��Ҫ�жϵ����ӵ���ɫ
	 * @return ����Ƿ�ʤ��
	 * @author ��������
	 */
	bool isChessWin(std::string color);
};

