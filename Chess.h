#pragma once

/**
 * @file Chess.h
 * @brief 棋盘中的棋子
 * @author 杜云飞
 * @version 2.0
 */

#include <string>

class Chess
{
public:

	Chess();

	int _x, _y;//棋子的坐标

	std::string _color;//棋子的颜色
	bool _is_picked;//棋子是否已被选中


};

