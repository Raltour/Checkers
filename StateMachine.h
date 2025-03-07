#pragma once

/**
 * @file StateMachine.h
 * @author ������
 * @brief �������̿��Ʋ�ȡFSM����״̬��ģʽ��
 * 
 *���ļ���״̬�������ڿ�����Ϸ���̣��ڲ�ͬ�Ľ��桢״̬֮���л���
 * 
 * @version 1.0
 */

#include <string>
#include <map>
#include "GameState.h"

class StateMachine {
public:

	/*
	* ��ʼ�����������
	* ��һ����Ϸ״̬�ǲ˵�
	* ��¼�����������
	*/
	StateMachine()
		:_self_ref(*this), _curr("StarMenu") {}


	~StateMachine();


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author ������
	 */
	void update(int x, int y);


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author ������
	 */
	void render();


	/**
	 * @brief ����״̬����������Ϸ״̬λ��
	 *
	 * �Դ�����ַ�������ӳ�䣬�����Ϊ��Ӧ��GameState
	 * 
	 * @param �����ʾ��һ״̬���Ƶ��ַ���
	 * @author ������
	 */
	void changeStateTo(std::string to);


private:

	std::string _curr;//��¼��Ϸ��ǰ״̬
	std::map<std::string, GameState> _gameStates;//���ַ�������ӳ��Ϊ��Ӧ��GameState
	StateMachine& _self_ref;//����������ã�����GameStateʱ��Ϊ��������
};