/**
 * @file Board.cpp
 * @brief Board函数的实现
 * @author 
 * @version 2.3
 */

#include "Board.h"


Board::Board() {
    int i = 1 + 2;//为了过编译瞎写的
}


Board::~Board() {

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


std::unique_ptr<Board> Board::create(std::string filename) {
    return nullptr;
}


void Board::putImage() {

}


bool Board::isChessWin(COLORREF color) {
    return false;
}

