/**
 * @file Board.cpp
 * @brief Board函数的实现
 * @author 
 * @version 2.5.6
 */

#include "Board.h"


Board::Board() {
    int i = 1 + 2;//为了过编译瞎写的
}


Board::~Board() {

}


void Board::addChess(Chess* chess) {

}


void Board::hashIndex() {

}


void Board::buildadj() {

}


bool Board::isMoveChess(Chess* chess, int newX, int newY) {
    return false;
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

