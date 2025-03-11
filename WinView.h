#pragma once

/**
 * @file WinView.h
 * @brief ʤ�����㻭��
 * @author 
 * @version 1.8
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"


class WinView : public GameState {
public:

	WinView(StateMachine& _self_ref)
		:GameState(_self_ref) {
	}


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author
	 */
	virtual void update(ExMessage& msg) {}


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author
	 */
	virtual void render() {}


	/**
	 * @brief �����״̬
	 *
	 * ��ʼ���������
	 *
	 * @author
	 */
	virtual void enter() {

	}


	/**
	 * @brief �˳�ʱ���ɸ������������
	 *
	 * ����˽�е��ַ�����Ա�������������ɶ�Ӧ����Щ���
	 *
	 * @author 
	 */
	virtual void exit() {
		cleardevice();
	}

private:

	std::vector<std::string> names;
	std::vector<std::string> colors;

};