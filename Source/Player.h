#pragma once
class Player
{
public:
	Player();
	~Player();
	CString playerID;
	int win;//��
	int draw;//��
	int lose;//��
	int getPlayerWin();
	int getPlayerDraw();
	int getPlayerLose();
};