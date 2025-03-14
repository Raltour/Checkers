#pragma once

/**
 * @file StartMenu.h
 * @author ������
 * @brief ��Ϸ��ʼʱ�Ĳ˵�����
 * @version 2.3
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"


class StartMenu : public GameState {
public:
	StartMenu(StateMachine& _self_ref);


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author 
	 */
	virtual void update(ExMessage& msg);


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author 
	 */
	virtual void render();


	/**
	 * @brief �����״̬
	 *
	 * ��ʼ��
	 * ��Ⱦ����
	 *
	 * @author 
	 */
	virtual void enter();


	/**
	 * @brief �˳���ǰ״̬
	 * @author
	 */
	virtual void exit();
};