#pragma once

/**
 * @file PlayerNum.h
 * @brief �û�ѡ�������Ϸ��������֧��2��4��6��
 * @author ������
 * @version 2.5.8
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
	 * @author ���Ʒ�
	 */
	virtual void update(ExMessage& msg);


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author ������
	 */
	virtual void render();


	/**
	 * @brief �����״̬
	 *
	 * ��ʼ��
	 * ��Ⱦ����
	 *
	 * @author ������
	 */
	virtual void enter();

private:
	Button btn2;
	Button btn4;
	Button btn6;
};