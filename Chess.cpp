/**
 * @file Chess.cpp
 * @brief Chess�����ľ���ʵ��
 * @author 
 * @version 2.5.7
 */

#include "Chess.h"


Chess* Chess::createChess(int x, int y, COLORREF color) {
	return new Chess(x, y, 12, color);
}


// ��ȡ���ӵ�x����
int Chess::x() const {
    return _x;
}


// ��ȡ���ӵ�y����
int Chess::y() const {
    return _y;
}


// ��ȡ������ɫ
COLORREF Chess::color() const {
    return _current_color;
}


// ��ȡ����״̬
chessState Chess::state() const {
    return _is_selected ? SELECTED : NORMAL;
}


// �������ӵ�λ��
void Chess::setPosition(int x, int y) {
    _x = x;
    _y = y;
}


// �������ӵ�״̬
void Chess::setState(chessState state) {
    _is_selected = state == SELECTED;
}


// �ı����ӵ���ɫ
void Chess::changeChess(COLORREF color) {
    _old_color = _current_color;
    _current_color = color;
}


// �ָ����ӵ�ԭ����ɫ
void Chess::recoveryColor() {
    _current_color = _old_color;
}


Chess::Chess(int x, int y, int chessSize, COLORREF currentColor)
    : _x(x), _y(y), _chess_size(chessSize), _old_color(currentColor),
    _current_color(currentColor), _is_selected(false) {
}