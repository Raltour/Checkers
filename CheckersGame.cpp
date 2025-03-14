/**
 * @file CheckersGame.cpp
 * @brief PlayerNum函数的实现
 * @author 
 * @version 2.5.4
 */

#include "StateMachine.h"
#include "GameState.h"
#include "CheckersGame.h"
#include "Board.h"
#include "Player.h"


CheckersGame::CheckersGame(StateMachine& _self_ref)
	:GameState(_self_ref), _chess(nullptr) {
	 Board board();
	 _chess_board = new Board;

}


void CheckersGame::update(ExMessage& msg) {
	if (msg.message == WM_LBUTTONDOWN) {

		//点击的位置是个棋子，且与玩家对应
		if ((_chess = _chess_board->isHereAChess(msg)) && Player::getCurrentPlayer().chessMatchPlayer(_chess)) {

			Player::getCurrentPlayer().isWin(_chess_board->moveChess(_chess));

			if (Player::isGameOver()) {
				_mach.changeStateTo("WinView");
			}

		}


	}
}


void CheckersGame::render() {
	drawChechersGame();
}


void CheckersGame::enter() {
	render();
}

