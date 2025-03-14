#pragma once

/**
 * @file StateMachine.h
 * @author ������
 * @brief �������̿��Ʋ�ȡFSM����״̬��ģʽ��
 * 
 * ���ļ���״̬�������ڿ�����Ϸ���̣��ڲ�ͬ�Ľ��桢״̬֮���л���
 * 
 * @version 2.4
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

	/*
	* ��ʼ�����������
	* ��һ����Ϸ״̬�ǲ˵�
	* ��¼�����������
	*/
	StateMachine();


	~StateMachine() {}


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author ������
	 */
	void update(ExMessage& msg);


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author ������
	 */
	void render();


	/**
	 * @brief ����״̬����������Ϸ״̬λ��
	 * 
	 * �˳�ԭ״̬
	 * �Դ�����ַ�������ӳ�䣬�����Ϊ��Ӧ��GameState
	 * ������״̬
	 * 
	 * @param �����ʾ��һ״̬���Ƶ��ַ���
	 * @author ������
	 */
	void changeStateTo(std::string to);


private:


	std::string _curr;//��¼��Ϸ��ǰ״̬
	std::map<std::string, GameState*> _game_states;//���ַ�������ӳ��Ϊ��Ӧ��GameState
	StateMachine& _self_ref;//����������ã�����GameStateʱ��Ϊ��������

};