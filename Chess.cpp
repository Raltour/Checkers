/**
 * @file Chess.cpp
 * @brief Chess函数的具体实现
 * @author 
 * @version 2.5.4
 */

#include "Chess.h"


Chess* Chess::createChess(int x, int y, COLORREF) {
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


void Chess::setPosition(int x, int y) {

}


void Chess::setState(chessState state) {

}


void Chess::changeChess(COLORREF color) {

}


void Chess::recoveryColor() {

}