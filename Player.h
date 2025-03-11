#pragma once

/**
 * @file Player.h
 * @brief ��¼������Ϸ�����
 * 
 * ����һ�����ݽṹ�����ò�����Ϸ���������
 * ���ò�ͬPlayers֮���ѭ����ʵ�����������������ߵĹ���
 * �ļ������к������ܶ��ܼ򵥣�����Ҫ��������Դ�ļ���
 * ֱ���ڸ��ļ���ʵ�����й���
 * 
 * @author ������
 * @version 1.8
 */

#include "Chess.h"
#include <string>

class Player {
public:

	/**
	 * @brief ���ص�ǰҪ�����ӵ����
	 *
	 * @return ���������ǰ�˵�һ����
	 * @author ��������
	 */
	static Player& getCurrentPlayer() {
		Player p("1", "3");//Ϊ�˹�����Ϲд��
		return p;
	}


	/**
	 * @brief �ж���Ϸ�Ƿ��Ѿ���������ն��ڴ�
	 *
	 * ֻ��鿴��������ǲ���ֻʣһ������
	 *
	 * @return ����ֵ
	 * @author ��������
	 */
	static bool isGameOver() {
		deleteAllPlayers();
		return false;
	}


	/**
	 * @brief ��������Ҳ������������
	 *
	 * ��������ĩβ
	 *
	 * @param ��ҵ�������ɫ
	 * @param ��ҵ�����
	 * @author ������
	 */
	static void addNewPlayer(std::string color, std::string name) {
		Player* p = new Player(color, name);
		p->storeNewPlayer();
	}


	/**
	 * @brief ��������Ƿ��������
	 *
	 * @return ����ֵ
	 * @author ������
	 */
	bool chessMatchPlayer(Chess* chess) {
		return this->_color == chess->_color;
	}


	/**
	 * @brief ���ݵ�ǰ����Ƿ��Ѿ������������ӣ����д���
	 *
	 * @param Board�еļ�⺯���ķ���ֵ
	 * @author ������
	 */
	void isWin(bool b) {
		if (b) {
			this->moveToWinner();
		}
		turnToNextPlayer();
	}


private:

	/*
	* ������̬��������������ֻ�����Ȩ
	* �������Ӧ���ܴ�һͷ�ó���Ҳ�ܴ�һͷ����
	* ������̬ʤ����������Ϸ����������������Ϣ��ʾ���ʲ��������а����
	* ���ֻҪ�ܰ�˳���ͺ���
	* �������Զ���ʲô�ṹ���У�
	*/






	Player(std::string color, std::string name)
		:_color(color), _name(name) {}

	std::string _color;
	std::string _name;


	/**
	 * @brief �����ɵ�����ҷ��뵽���������ĩβ
	 *
	 * @author ��������
	 */
	void storeNewPlayer() {

	}


	/**
	 * @brief ��Ϸ�������ͷŶ��ڴ�
	 *
	 * @return ����ֵ������
	 * @author ��������
	 */
	static void deleteAllPlayers() {

	}


	/**
	 * @brief �ֻ���Ϸ������Ȩ��
	 *
	 * ���������ͷ��������ӵ�ĩβȥ
	 *
	 * @author ��������
	 */
	void turnToNextPlayer() {
		
	}


	/**
	 * @brief ��ʤ���˵���ҷ��뵽ʤ��������
	 *
	 * @author ��������
	 */
	void moveToWinner() {

	}
};