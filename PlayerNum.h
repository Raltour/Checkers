#pragma once

/**
 * @file PlayerNum.h
 * @brief �û�ѡ�������Ϸ��������֧��2��4��6��
 * @author ������
 * @version 1.8
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"

class PlayerNum : public GameState {
public:

	PlayerNum(StateMachine& _self_ref);


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