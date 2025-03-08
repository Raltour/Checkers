#pragma once

/**
 * @file Player.h
 * @brief ��¼������Ϸ�����
 * 
 * ����һ�����ݽṹ�����ò�����Ϸ���������
 * ���ò�ͬPlayers֮���ѭ����ʵ�����������������ߵĹ���
 * 
 * @author ������
 * @version 1.5
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
		deleteAllPlayers();
		return false;
	}


	/**
	 * @brief �������ܵļ�Ҫ����
	 *
	 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
	 *
	 * @param ����1 ��������1������
	 * @param ����2 ��������2������
	 * @return ����ֵ������
	 * @author ������
	 */
	static void addNewPlayer(std::string color, std::string name) {
		Player* p = new Player(color, name);
		p->storeNewPlayer();
	}


	/**
	 * @brief �������ܵļ�Ҫ����
	 *
	 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
	 *
	 * @param ����1 ��������1������
	 * @param ����2 ��������2������
	 * @return ����ֵ������
	 * @author 
	 */
	bool chessMatchPlayer(Chess& chess);


	/**
	 * @brief �������ܵļ�Ҫ����
	 *
	 * ��ϸ���������Ĺ��ܡ�����������ֵ����Ϣ��
	 *
	 * @param ����1 ��������1������
	 * @param ����2 ��������2������
	 * @return ����ֵ������
	 * @author ������
	 */
	bool isWin(bool b) {
		if (b) {
			this->moveToWinner();
		}
		turnToNextPlayer();
	}


private:
	//������̬���˫�˶��С���̬ʤ��ջ



	Player(std::string color, std::string name)
		:_color(color), _name(name) {}

	std::string _color;
	std::string _name;


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
	void storeNewPlayer();


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
	static void deleteAllPlayers();


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
	void moveToWinner() {

	}
};