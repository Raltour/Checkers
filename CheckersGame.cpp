/**
 * @file CheckersGame.cpp
 * @brief PlayerNum������ʵ��
 * @author ����
 * @version 1.8
 */

#include "StateMachine.h"
#include "GameState.h"
#include "CheckersGame.h"
#include "Board.h"
#include "Player.h"


CheckersGame::CheckersGame(StateMachine& _self_ref)
	:GameState(_self_ref), _chess_board() {
}


void CheckersGame::update(ExMessage& msg) {
	if (msg.message == WM_LBUTTONDOWN) {

		//�����λ���Ǹ����ӣ�������Ҷ�Ӧ
		if ((_chess = _chess_board.isHereAChess(msg)) && Player::getCurrentPlayer().chessMatchPlayer(_chess)) {

			Player::getCurrentPlayer().isWin(_chess_board.moveChess(_chess));

			if (Player::isGameOver()) {
				_mach.changeStateTo("WinView");
			}

		}


	}
}


void CheckersGame::render() {

}


void CheckersGame::enter() {

}


void CheckersGame::exit() {
	
}