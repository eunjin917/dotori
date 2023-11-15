#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class SaveLoad
{
public:
	int mas;
	char player[20];
	CString b;
	FILE *master;

	CString playerID;
	int win;
	int draw;
	int lose;
	SaveLoad();
	~SaveLoad();
	void dataset(CString playerID, int win, int darw, int lose);
	void datasave();
	void dataload(CString playerID);
};

