#pragma once
class Player
{
public:
	Player();
	~Player();
	CString playerID;
	int win;//½Â
	int draw;//¹«
	int lose;//ÆÐ
	int getPlayerWin();
	int getPlayerDraw();
	int getPlayerLose();
};