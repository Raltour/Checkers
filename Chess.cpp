/**
 * @file Chess.cpp
 * @brief Chess函数的具体实现
 * @author 
 * @version 2.5.7
 */

#include "Chess.h"


Chess* Chess::createChess(int x, int y, COLORREF color) {
	return new Chess(x, y, 12, color);
}


// 获取棋子的x坐标
int Chess::x() const {
    return _x;
}


// 获取棋子的y坐标
int Chess::y() const {
    return _y;
}


// 获取棋子颜色
COLORREF Chess::color() const {
    return _current_color;
}


// 获取棋子状态
chessState Chess::state() const {
    return _is_selected ? SELECTED : NORMAL;
}


// 设置棋子的位置
void Chess::setPosition(int x, int y) {
    _x = x;
    _y = y;
}


// 设置棋子的状态
void Chess::setState(chessState state) {
    _is_selected = state == SELECTED;
}


// 改变棋子的颜色
void Chess::changeChess(COLORREF color) {
    _old_color = _current_color;
    _current_color = color;
}


// 恢复棋子的原来颜色
void Chess::recoveryColor() {
    _current_color = _old_color;
}


Chess::Chess(int x, int y, int chessSize, COLORREF currentColor)
    : _x(x), _y(y), _chess_size(chessSize), _old_color(currentColor),
    _current_color(currentColor), _is_selected(false) {
}