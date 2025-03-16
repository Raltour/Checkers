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
 * @version 2.5.5
 */

#include "Chess.h"
#include <easyx.h>
#include <string>
#include <deque>
#include <queue>
#include <vector>

class Player {
public:

	/**
	 * @brief ���ص�ǰҪ�����ӵ����
	 *
	 * @return ���������ǰ�˵�һ����
	 * @author ������
	 */
	static Player& getCurrentPlayer();


	/**
	 * @brief �ж���Ϸ�Ƿ��Ѿ�����
	 *
	 * ֻ��鿴��������ǲ���ֻʣһ������
	 * 
	 * @return ����ֵ
	 * @author ������ ������
	 */
	static bool isGameOver();


	/**
	 * @brief ��������Ҳ������������
	 *
	 * �����ɵ���ҷŵ����������ĩβ
	 *
	 * @param ��ҵ�������ɫ
	 * @param ��ҵ�����
	 * @author ������
	 */
	static void addNewPlayer(COLORREF color, std::string name);


	/**
	 * @brief ��������Ƿ��������
	 *
	 * @return ����ֵ
	 * @author ������
	 */
	bool chessMatchPlayer(Chess* chess);


	/**
	 * @brief ���ݵ�ǰ����Ƿ��Ѿ������������ӣ����д���
	 * 
	 * ���ȷʵ��ʤ������ǰ���Ų�뵽ʤ��������
	 * ���ٷ����������
	 *
	 * @param Board�еļ�⺯���ķ���ֵ
	 * @author ������
	 */
	void isWin(bool b);


private:

	/*
	* ������̬��������������ֻ�����Ȩ���ڲ�����ָ��
	* �������Ӧ���ܴ�һͷ�ó���Ҳ�ܴ�һͷ����
	* ������̬ʤ����������Ϸ����������������Ϣ��ʾ���ʲ��������а����
	* ���ֻҪ�ܰ�˳���ͺ���
	*/

	// ��̬���������˫����У�
	static std::queue<Player*> playerQueue;

	// ��̬ʤ����������˳��洢��
	static std::vector<Player*> winnerList;

	//�����������ɫ������
	Player(COLORREF color, std::string name);


	COLORREF _color;
	std::string _name;


	/**
	 * @brief �����ɵ�����ҷ��뵽���������ĩβ
	 *
	 * �ú����������������ҵ�ָ����뵽������
	 * 
	 * @author ������
	 */
	void storeNewPlayer();


	/**
	 * @brief ��Ϸ�������ͷŶ��ڴ�
	 *
	 * ����Ҫ��ʤ�����㻭���˳�ʱʹ���������
	 * �����������ʤ�������е�����ָ����ָ�Ķ��������
	 * �ͷŶ��ڴ�
	 * 
	 * @return ����ֵ������
	 * @author ������
	 */
	static void deleteAllPlayers();


	/**
	 * @brief �ֻ���Ϸ������Ȩ
	 *
	 * ���������ͷ��������ӵ�ĩβȥ����
	 *
	 * @author ������
	 */
	void turnToNextPlayer();


	/**
	 * @brief ��ʤ���˵���ҷ��뵽ʤ��������
	 *
	 * ����Ҫ����Ƿ��ʤ��
	 * ���������������֪���ʤ�����ƶ�λ���õ�
	 * 
	 * @author ������
	 */
	void moveToWinner();
};