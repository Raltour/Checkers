#pragma once

/**
 * @file StateMachine.h
 * @author ������
 * @brief �������̿��Ʋ�ȡFSM����״̬��ģʽ��
 *
 * ���ļ���״̬�������ڿ�����Ϸ���̣��ڲ�ͬ�Ľ��桢״̬֮���л���
 * ״̬��ͨ������ͬ����Ϸ״̬���翪ʼ�˵����������ѡ����Ϸ����ȣ���
 * ʵ����Ϸ���̵Ŀ��ƺ�״̬�л���
 *
 * @version 2.5.6
 */

#include <string>
#include <map>
#include "StartMenu.h"
#include "PlayerNum.h"
#include "PlayerInfo.h"
#include "CheckersGame.h"
#include "WinView.h"
#include <easyx.h>

class GameState;

class StateMachine {
public:

	/**
	 * @brief ���캯������ʼ��״̬��
	 *
	 * ��ʼ��״̬��ʱ����һ����Ϸ״̬�ǿ�ʼ�˵���
	 * ͬʱ��¼����������ã��Ա���״̬�л�ʱʹ�á�
	 *
	 * @author ������
	 */
	StateMachine();


	/**
	 * @brief ��������
	 *
	 * �ͷ�״̬��ռ�õ���Դ��
	 *
	 * @author ������
	 */
	~StateMachine();


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * ���������λ�û���������ַ������µ�ǰ��Ϸ״̬��
	 * �ú���ͨ������Ϸ��ѭ�����ã��Դ����û����벢����״̬��
	 *
	 * @param msg ������Ϣ�����������λ�û���������ַ�
	 * @author ������
	 */
	void update(ExMessage& msg);


	/**
	 * @brief ��Ϸ��Ⱦ
	 *
	 * ���õ�ǰ��Ϸ״̬����Ⱦ������������Ϸ���档
	 * �ú���ͨ������Ϸ��ѭ�����ã���ȷ�������ܹ���ȷ��ʾ��
	 *
	 * @author ������
	 */
	void render();


	/**
	 * @brief ����״̬����������Ϸ״̬
	 *
	 * �˳���ǰ״̬�������ݴ�����ַ���ӳ�䵽��Ӧ����Ϸ״̬��
	 * �����µ���Ϸ״̬�����״̬�л���
	 *
	 * @param to ��ʾ��һ״̬���Ƶ��ַ���
	 * @author ������
	 */
	void changeStateTo(std::string to);


private:

	std::string _curr; // ��¼��ǰ��Ϸ״̬
	std::map<std::string, GameState*> _game_states; // ���ַ�������ӳ��Ϊ��Ӧ��GameState
	StateMachine& _self_ref; // ����������ã�����GameStateʱ��Ϊ��������

};