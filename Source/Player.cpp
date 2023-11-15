#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

int Player::getPlayerWin() {
	return win;
}

int Player::getPlayerDraw() {
	return draw;
}

int Player::getPlayerLose() {
	return lose;
}
