#pragma once

/**
 * @file PlayerNumber.h
 * @brief ���������ҵ�����������������
 * @author ������
 * @version 1.3
 */

#include "StateMachine.h"
#include "GameState.h"

class PlayerInfo : public GameState {
public:

	PlayerInfo(StateMachine& _self_ref)
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