/**
 * @file CheckersGame.cpp
 * @brief PlayerNum������ʵ��
 * @author 
 * @version 2.5.8
 */

#include "StateMachine.h"
#include "GameState.h"
#include "CheckersGame.h"
#include "Board.h"
#include "Player.h"
extern int _num_of_players;

CheckersGame::CheckersGame(StateMachine& _self_ref)
	:GameState(_self_ref), _chess(nullptr) {
	 Board board();
	 _chess_board = new Board;

}


void CheckersGame::update(ExMessage& msg) {
		////�����λ���Ǹ����ӣ�������Ҷ�Ӧ
		//if ((_chess = _chess_board->isHereAChess(msg)) && Player::getCurrentPlayer().chessMatchPlayer(_chess)) {

		//	Player::getCurrentPlayer().isWin(_chess_board->moveChess(_chess));

		//	if (Player::isGameOver()) {
		//		_mach.changeStateTo("WinView");
		//	}

		//}
		
	if (msg.message == WM_LBUTTONDOWN) {
		if (!_is_chess_selected) {
			//ѡ������
			_selected_chess = _chess_board->isHereAChess(msg);
			//std::cout << _selected_chess->x();
			if (_selected_chess && Player::getCurrentPlayer().chessMatchPlayer(_selected_chess)) {
				_is_chess_selected = true;
				_selected_chess->highLight(true); // ����ѡ��״̬
			}
		}
		else {
			if (_chess_board->isMoveChess(_selected_chess, msg))
			{
				Player::getCurrentPlayer().isWin(false);
				bool move_success = _chess_board->moveChess(_selected_chess, msg);
				if (move_success) {
					Player::getCurrentPlayer().isWin(false);
					if (Player::isGameOver()) {
						_mach.changeStateTo("WinView");
					}
				}
			}
			else {
				// �ƶ���Ч
				_selected_chess->highLight(false);
			}

			_selected_chess->setState(NORMAL);
			_selected_chess = nullptr;
			_is_chess_selected = false;
		}
	}
}


void CheckersGame::render() {
	drawChechersGame(*_chess_board);
}


void CheckersGame::enter() {
	switch (_num_of_players)
	{
	case 2:
		//��
		for (int i = 61; i < 71; i++)
		{
			_chess_board->m_chesses[i]->changeChess(RED);
			_chess_board->state[i] = true;
		}

		//��
		for (int i = 71; i < 81; i++)
		{
			_chess_board->m_chesses[i]->changeChess(GREEN);
			_chess_board->state[i] = true;
		}
		break;
	case 4:
		//��
		for (int i = 61; i < 71; i++)
		{
			_chess_board->m_chesses[i]->changeChess(RED);
			_chess_board->state[i] = true;
		}

		//��
		for (int i = 71; i < 81; i++)
		{
			_chess_board->m_chesses[i]->changeChess(GREEN);
			_chess_board->state[i] = true;
		}

		//����
		for (int i = 81; i < 91; i++)
		{
			_chess_board->m_chesses[i]->changeChess(BLUE);
			_chess_board->state[i] = true;
		}

		//����
		for (int i = 91; i < 101; i++)
		{
			_chess_board->m_chesses[i]->changeChess(YELLOW);
			_chess_board->state[i] = true;
		}
		break;
	case 6:
		//��
		for (int i = 61; i < 71; i++)
		{
			_chess_board->m_chesses[i]->changeChess(RED);
			_chess_board->state[i] = true;
		}

		//��
		for (int i = 71; i < 81; i++)
		{
			_chess_board->m_chesses[i]->changeChess(GREEN);
			_chess_board->state[i] = true;
		}

		//����
		for (int i = 81; i < 91; i++)
		{
			_chess_board->m_chesses[i]->changeChess(BLUE);
			_chess_board->state[i] = true;
		}

		//����
		for (int i = 91; i < 101; i++)
		{
			_chess_board->m_chesses[i]->changeChess(YELLOW);
			_chess_board->state[i] = true;
		}

		//����
		for (int i = 101; i < 111; i++)
		{
			_chess_board->m_chesses[i]->changeChess(CYAN);
			_chess_board->state[i] = true;
		}

		//����
		for (int i = 111; i < 121; i++)
		{
			_chess_board->m_chesses[i]->changeChess(MAGENTA);
			_chess_board->state[i] = true;
		}
		break;
	}


	render();
}

