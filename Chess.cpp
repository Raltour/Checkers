/**
 * @file Chess.cpp
 * @brief Chess函数的具体实现
 * @author 张三
 * @version 2.2
 */

#include "Chess.h"




std::unique_ptr<Chess> Chess::create(int x, int y, COLORREF) {
	return nullptr;
}


int Chess::x() const {
	return 0;
}


int Chess::y() const {
	return 0;
}


COLORREF Chess::color() const {
	return WHITE;
}


chessState Chess::state() const {
	return NORMAL;
}


void Chess::draw() {

}


void Chess::setPosition(int x, int y) {

}


void Chess::setState(chessState state) {

}


void Chess::changeChess(COLORREF color) {

}


void Chess::removeChess() {

}