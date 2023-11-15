#include "stdafx.h"
#include "SaveLoad.h"


SaveLoad::SaveLoad()
{
}


SaveLoad::~SaveLoad()
{
}

void SaveLoad::dataset(CString playerID, int win, int draw, int lose)
{
	this->playerID = playerID;
	this->win = win;
	this->draw = draw;
	this->lose = lose;
}

void SaveLoad::datasave() {

	fopen_s(&master, "saveload.txt", "r+");
	if (master == 0) {
		exit(-1);
	}

	int count = 0;

	CT2CA pszConvertedAnsiString(playerID);
	string s1(pszConvertedAnsiString);
	const char *a = s1.c_str();

	int num1 = win;
	int num2 = draw;
	int num3 = lose;

	while (1) {
		mas = fscanf_s(master, "%s %d %d %d\n", player, sizeof(player), &win, &draw, &lose);
		b = (CString)player;
		if (player == playerID) {
			fseek(master, count + 1, SEEK_SET);
			fprintf_s(master, "xxxxxxxxxxx");
			break;
		}
		count = ftell(master);
		if (mas == EOF) {
			break;
		}
	}
	fseek(master, 0, SEEK_END);
	fprintf_s(master, "%s %d %d %d\n", a, num1, num2, num3);
	fclose(master);
}

void SaveLoad::dataload(CString playerID)
{
	string a;

	fopen_s(&master, "saveload.txt", "r");
	if (master == 0) {
		exit(-1);
	}

	while (1) {
		if (b == playerID) {
			break;
		}
		mas = fscanf_s(master, "%s %d %d %d\n", player, sizeof(player), &win, &draw, &lose);
		b = (CString)player;
		if (mas == EOF) {
			break;
		}
	}
	this->playerID = b;
	fclose(master);
}