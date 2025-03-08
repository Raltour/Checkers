#pragma once

/**
 * @file CheckersGame.h
 * @brief ���������ҵ�����������������
 * @author ������
 * @version 1.3
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Board.h"

class CheckersGame : public GameState {
public:

	CheckersGame(StateMachine& _self_ref)
		:GameState(_self_ref), _chess_board() {

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

private:

	Board _chess_board;
};