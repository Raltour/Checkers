#pragma once

/**
 * @file CheckersGame.h
 * @brief 几个玩家轮流走棋，进行游戏
 * @author 李明泽
 * @version 1.6
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Board.h"
#include "Player.h"

class CheckersGame : public GameState {
public:

	CheckersGame(StateMachine& _self_ref)
		:GameState(_self_ref), _chess_board() {}


	/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * @param 鼠标所点击的位置或者键盘的输入字符
	 * @author 李明泽
	 */
	virtual void update(ExMessage &msg) {
		if (msg.message == WM_LBUTTONDOWN) {

			//点击的位置是个棋子，且与玩家对应
			if ((_chess = _chess_board.isHereAChess(msg)) && Player::getCurrentPlayer().chessMatchPlayer(_chess)) {

				Player::getCurrentPlayer().isWin(_chess_board.moveChess(_chess));

				if (Player::isGameOver()) {
					_mach.changeStateTo("WinView");
				}

			}


		}
	}


	/**
	 * @brief 游戏渲染
	 * @author
	 */
	virtual void render() {}


	/**
	 * @brief 进入该状态
	 *
	 * 初始化
	 * 渲染界面
	 *
	 * @author
	 */
	virtual void enter() {}


	/**
	 * @brief 退出当前状态
	 * @author
	 */
	virtual void exit() {}

private:

	//对游戏棋盘的引用
	Board &_chess_board;

	//由于目标棋子会不断变化，不能设为引用，1采用指针
	Chess* _chess;
};