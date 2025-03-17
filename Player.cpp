/**
 * @file Player.cpp
 * @brief Player函数的实现
 * @author
 * @version 2.5.7
 */
#include "Player.h"

Player& Player::getCurrentPlayer() {
	return *playerQueue.front();
}


bool Player::isGameOver() {
	if (playerQueue.size() == 1) {
		winnerList.push_back(playerQueue.front());
		playerQueue.pop();
		return true;
	}
	return false;
}


void Player::addNewPlayer(COLORREF color, std::string name) {
	Player* p = new Player(color, name);
	p->storeNewPlayer();
}


bool Player::chessMatchPlayer(Chess* chess) {
	return this->_color == chess->color();
}


void Player::isWin(bool b) {
	if (b) {
		this->moveToWinner();
	}
	turnToNextPlayer();
}


Player::Player(COLORREF color, std::string name)
	:_color(color), _name(name) {
}


// 静态成员变量必须在类外定义并初始化
std::queue<Player*> Player::playerQueue;
std::vector<Player*> Player::winnerList;


void Player::storeNewPlayer() {
	playerQueue.push(this);
}


void Player::deleteAllPlayers() {
	for (auto player : winnerList) {
		delete player;
	}
}


void Player::turnToNextPlayer() {
	playerQueue.push(playerQueue.front());
	playerQueue.pop();
}


void Player::moveToWinner() {
	winnerList.push_back(playerQueue.front());
	playerQueue.pop();
}