#pragma once

/**
 * @file Player.h
 * @brief ��¼������Ϸ�����
 * 
 * ����һ�����ݽṹ�����ò�����Ϸ���������
 * ���ò�ͬPlayers֮���ѭ����ʵ�����������������ߵĹ���
 * 
 * @author ������
 * @version 1.3
 */

#include "Chess.h"
#include <string>

class Player {
public:
	/**
	 * @brief �������ܵļ�Ҫ����
	 *
	 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
	 *
	 * @param ����1 ��������1������
	 * @param ����2 ��������2������
	 * @return ����ֵ������
	 * @author ��������
	 */
	static Player& getCurrentPlayer() {
		return;
	}


	/**
	 * @brief �������ܵļ�Ҫ����
	 *
	 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
	 *
	 * @param ����1 ��������1������
	 * @param ����2 ��������2������
	 * @return ����ֵ������
	 * @author ��������
	 */
	static bool isGameOver() {
		return false;
	}

private:
	//������̬���˫�˶��С���̬ʤ��ջ

	std::string _color;



	/**
	 * @brief �������ܵļ�Ҫ����
	 *
	 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
	 *
	 * @param ����1 ��������1������
	 * @param ����2 ��������2������
	 * @return ����ֵ������
	 * @author ��������
	 */
	void turnToNextPlayer() {
		
	}


	/**
	 * @brief �������ܵļ�Ҫ����
	 *
	 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
	 *
	 * @param ����1 ��������1������
	 * @param ����2 ��������2������
	 * @return ����ֵ������
	 * @author ��������
	 */
	bool isWin() {

	}


	/**
	 * @brief �������ܵļ�Ҫ����
	 *
	 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
	 *
	 * @param ����1 ��������1������
	 * @param ����2 ��������2������
	 * @return ����ֵ������
	 * @author ��������
	 */
	void currToWinner() {

	}
};