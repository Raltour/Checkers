#pragma once

/**
 * @file StartMenu.h
 * @author ������
 * @brief ��Ϸ��ʼʱ�Ĳ˵�����
 * @version 1.0
 */

#include "StateMachine.h"
#include "GameState.h"


class StartMenu : public GameState {
public:
	StartMenu(StateMachine& _self_ref)
		:GameState(_self_ref) {}


	/**
	 * @brief ����GameState
	 *
	 * ����StateMachine�����ü�¼Ϊ��Ա������
	 * ȷ����ȫ��ֻʹ��Ψһ��һ��mach
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author ������
	 */
	virtual void update() {}


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author ������
	 */
	virtual void render() {}


	/**
	 * @brief �����״̬
	 *
	 * ��ʼ��
	 * ��Ⱦ����
	 *
	 * @author ������
	 */
	virtual void enter() {}


	/**
	 * @brief �˳���ǰ״̬
	 *
	 * ��¼���޸ı�Ҫ������
	 * ��ս���
	 *
	 * @author ������
	 */
	virtual void exit() {}
};