#pragma once

/**
 * @file PlayerNum.h
 * @brief �û�ѡ�������Ϸ��������֧��2��4��6��
 * @author ������
 * @version 1.3
 */

#include "StateMachine.h"
#include "GameState.h"

class PlayerNum : public GameState {
public:

	PlayerNum(StateMachine& _self_ref)
		:GameState(_self_ref) {
	}


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author 
	 */
	virtual void update() {}


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author 
	 */
	virtual void render() {}


	/**
	 * @brief �����״̬
	 *
	 * ��ʼ��
	 * ��Ⱦ����
	 *
	 * @author 
	 */
	virtual void enter() {}


	/**
	 * @brief �˳���ǰ״̬
	 *
	 * ��¼���޸ı�Ҫ������
	 * ��ս���
	 *
	 * @author 
	 */
	virtual void exit() {}
};