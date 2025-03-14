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
 * @version 2.3
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
		Player p(WHITE, "3");//Ϊ�˹�����Ϲд��
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

		return false;
	}


	/**
	 * @brief ��������Ҳ������������
	 *
	 * �����ɵ���ҷŵ����������ĩβ
	 *
	 * @param ��ҵ�������ɫ
	 * @param ��ҵ�����
	 * @author ������
	 */
	static void addNewPlayer(COLORREF color, std::string name) {
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
		return this->_color == chess->color();
	}


	/**
	 * @brief ���ݵ�ǰ����Ƿ��Ѿ������������ӣ����д���
	 * 
	 * ���ȷʵ��ʤ������ǰ���Ų�뵽ʤ��������
	 * ���ٷ����������
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
	* ������̬��������������ֻ�����Ȩ���ڲ�����ָ��
	* �������Ӧ���ܴ�һͷ�ó���Ҳ�ܴ�һͷ����
	* ������̬ʤ����������Ϸ����������������Ϣ��ʾ���ʲ��������а����
	* ���ֻҪ�ܰ�˳���ͺ���
	* �������Զ���ʲô�ṹ���У�
	*/






	Player(COLORREF color, std::string name)
		:_color(color), _name(name) {}

	COLORREF _color;
	std::string _name;


	/**
	 * @brief �����ɵ�����ҷ��뵽���������ĩβ
	 *
	 * �ú����������������ҵ�ָ����뵽������
	 * 
	 * @author ��������
	 */
	void storeNewPlayer() {

	}


	/**
	 * @brief ��Ϸ�������ͷŶ��ڴ�
	 *
	 * ����Ҫ��ʤ�����㻭���˳�ʱʹ���������
	 * �����������ʤ�������е�����ָ����ָ�Ķ��������
	 * �ͷŶ��ڴ�
	 * 
	 * @return ����ֵ������
	 * @author ��������
	 */
	static void deleteAllPlayers() {

	}


	/**
	 * @brief �ֻ���Ϸ������Ȩ
	 *
	 * ���������ͷ��������ӵ�ĩβȥ����
	 *
	 * @author ��������
	 */
	void turnToNextPlayer() {
		
	}


	/**
	 * @brief ��ʤ���˵���ҷ��뵽ʤ��������
	 *
	 * ����Ҫ����Ƿ��ʤ��
	 * ���������������֪���ʤ�����ƶ�λ���õ�
	 * 
	 * @author ��������
	 */
	void moveToWinner() {

	}
};