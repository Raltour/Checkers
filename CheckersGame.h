#pragma once

/**
 * @file CheckersGame.h
 * @brief ��������������壬������Ϸ
 * @author ������
 * @version 1.8
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Board.h"
#include "Player.h"

class CheckersGame : public GameState {
public:

	CheckersGame(StateMachine& _self_ref);


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author ������
	 */
	virtual void update(ExMessage& msg);


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
	 * @author
	 */
	virtual void exit() {}

private:

	//����Ϸ���̵�����
	Board _chess_board;

	//����Ŀ�����ӻ᲻�ϱ仯��������Ϊ���ã�1����ָ��
	Chess* _chess;
};