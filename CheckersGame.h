#pragma once

/**
 * @file CheckersGame.h
 * @brief ���������ҵ�����������������
 * @author ������
 * @version 1.5
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Board.h"
#include "Player.h"

class CheckersGame : public GameState {
public:

	CheckersGame(StateMachine& _self_ref)
		:GameState(_self_ref), _chess_board() {

	}


	/**
	 * @brief ����������Ϣ������Ϸ״̬
	 *
	 * @param ����������λ�û��߼��̵������ַ�
	 * @author ������
	 */
	virtual void update(ExMessage &msg) {
		if (msg.message == WM_LBUTTONDOWN) {

			//�����λ���Ǹ����ӣ�������Ҷ�Ӧ
			if (_chess_board.isHereAChess(msg, _chess) && Player::getCurrentPlayer().chessMatchPlayer(_chess)) {
				Player::getCurrentPlayer().isWin(_chess_board.moveChess(_chess));

				if (Player::isGameOver()) {
					_mach.changeStateTo("WinView");
				}

			}


		}
	}


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
	Chess _chess;
};