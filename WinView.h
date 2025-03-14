#pragma once

/**
 * @file WinView.h
 * @brief ʤ�����㻭��
 * @author ������
 * @version 2.4
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"


class WinView : public GameState {
public:

	WinView(StateMachine& _self_ref);


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
	 * ��ʼ���������
	 *
	 * @author
	 */
	virtual void enter();

private:

	std::vector<std::string> names;
	std::vector<std::string> colors;

};