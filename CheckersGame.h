#pragma once

/**
 * @file CheckersGame.h
 * @brief 几个玩家轮流走棋，进行游戏
 * @author 李明泽
 * @version 2.5.7
 */

#include "StateMachine.h"
#include "GameState.h"
#include "Board.h"
#include "Player.h"


class CheckersGame : public GameState {
public:

	CheckersGame(StateMachine& _self_ref);


	~CheckersGame() {
		delete _chess_board;
	}


	/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * @param 鼠标所点击的位置或者键盘的输入字符
	 * @author 李明泽
	 */
	virtual void update(ExMessage& msg);


	/**
	 * @brief 游戏渲染
	 * @author 李明泽
	 */
	virtual void render();


	/**
	 * @brief 进入该状态
	 *
	 * 初始化
	 * 渲染界面
	 *
	 * @author 李明泽
	 */
	virtual void enter();


private:

	//游戏棋盘的指针
	Board* _chess_board;

	//由于目标棋子会不断变化，不能设为引用，采用指针
	Chess* _chess;

};