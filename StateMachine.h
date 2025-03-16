#pragma once

/**
 * @file StateMachine.h
 * @author 李明泽
 * @brief 整体流程控制采取FSM有限状态机模式。
 *
 * 该文件是状态机，用于控制游戏流程，在不同的界面、状态之间切换。
 * 状态机通过管理不同的游戏状态（如开始菜单、玩家数量选择、游戏界面等），
 * 实现游戏流程的控制和状态切换。
 *
 * @version 2.5.6
 */

#include <string>
#include <map>
#include "StartMenu.h"
#include "PlayerNum.h"
#include "PlayerInfo.h"
#include "CheckersGame.h"
#include "WinView.h"
#include <easyx.h>

class GameState;

class StateMachine {
public:

	/**
	 * @brief 构造函数，初始化状态机
	 *
	 * 初始化状态机时，第一个游戏状态是开始菜单。
	 * 同时记录对自身的引用，以便在状态切换时使用。
	 *
	 * @author 李明泽
	 */
	StateMachine();


	/**
	 * @brief 析构函数
	 *
	 * 释放状态机占用的资源。
	 *
	 * @author 李明泽
	 */
	~StateMachine();


	/**
	 * @brief 利用输入信息更新游戏状态
	 *
	 * 根据鼠标点击位置或键盘输入字符，更新当前游戏状态。
	 * 该函数通常由游戏主循环调用，以处理用户输入并更新状态。
	 *
	 * @param msg 输入信息，包括鼠标点击位置或键盘输入字符
	 * @author 李明泽
	 */
	void update(ExMessage& msg);


	/**
	 * @brief 游戏渲染
	 *
	 * 调用当前游戏状态的渲染函数，绘制游戏界面。
	 * 该函数通常由游戏主循环调用，以确保界面能够正确显示。
	 *
	 * @author 李明泽
	 */
	void render();


	/**
	 * @brief 更新状态机所处的游戏状态
	 *
	 * 退出当前状态，并根据传入的字符串映射到对应的游戏状态。
	 * 进入新的游戏状态，完成状态切换。
	 *
	 * @param to 表示下一状态名称的字符串
	 * @author 李明泽
	 */
	void changeStateTo(std::string to);


private:

	std::string _curr; // 记录当前游戏状态
	std::map<std::string, GameState*> _game_states; // 将字符串名称映射为对应的GameState
	StateMachine& _self_ref; // 对自身的引用，构建GameState时作为参数传入

};