#pragma once

/**
 * @file StartMenu.h
 * @author 
 * @brief ��Ϸ��ʼʱ�Ĳ˵�����
 * @version 1.8
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Render.h"


class StartMenu : public GameState {
public:
	StartMenu(StateMachine& _self_ref)
		:GameState(_self_ref) {}


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author 
	 */
	virtual void update(ExMessage &msg) override {

	}


	/**
	 * @brief ��Ϸ��Ⱦ
	 * @author 
	 */
	virtual void render() override {

	}


	/**
	 * @brief �����״̬
	 *
	 * ��ʼ��
	 * ��Ⱦ����
	 *
	 * @author 
	 */
	virtual void enter() override {

	}


	/**
	 * @brief �˳���ǰ״̬
	 * @author
	 */
	virtual void exit() override {

	}
};