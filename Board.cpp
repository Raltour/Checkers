/**
 * @file Board.cpp
 * @brief Board函数的实现
 * @author 张三
 * @version 2.1
 */

#include "Board.h"


std::unique_ptr<Board> Board::create() {

}


void Board::addChess(std::unique_ptr<Chess> chess) {

}


Chess* Board::chessAt(ExMessage& msg) {
    return NULL;
}


bool Board::isMoveChess(Chess* chess, int newX, int newY) {
    return false;
}


void Board::drawTriangle(int p_x, int p_y, const char c, int n, COLORREF color) {
    
}


void Board::draw() {

}


void Board::hashIndex() {

}


void Board::buildadj() {

}


int Board::handleClick(ExMessage& msg) {
    return 0;
}


void Board::findSingleJumpMove(Chess* chess) {

}


void Board::findDoybleJumpMove(Chess* chess, int step) {

}


void Board::getJumpMove(Chess* chess) {

}


Chess* Board::isHereAChess(ExMessage& msg) {
	return NULL;
}


bool Board::moveChess(Chess* chess) {
	return false;
}


bool Board::isChessWin(COLORREF color) {
    return false;
}

