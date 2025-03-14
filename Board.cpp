/**
 * @file Board.cpp
 * @brief Board函数的实现
 * @author 
 * @version 2.4
 */

#include "Board.h"


Board::Board() {
    int i = 1 + 2;//为了过编译瞎写的
}


Board::~Board() {

}


void Board::addChess(std::unique_ptr<Chess> chess) {

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

