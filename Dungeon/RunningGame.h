#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#include "Position.h"
#include "main.h"
#include "Creature.h"


using namespace std;

class RunningGame:public Creature
{
public:

	char sign[3] = { 97, 115, 100 };
	int intSign;
	char answer;
	bool pressed = false;

	string story = "<P奔跑題>\n\n"
		"路途上發現洞穴山豬之王!!!\n"
		"那隻山豬正朝著我飛奔過來，要趕快酸了。\n\n"
		"勇士：等我找到時間再把他獵下來。\n";

	RunningGame() {
		intSign = 0;
		answer = ' ';
		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = "Ｐ";
	}

	RunningGame(int y,int x) {
		intSign = 0;
		answer = ' ';
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = "Ｐ";
	}

	void newQuest() {
		answer = sign[intSign];
	}

	bool getAns() {
		int c = _getch();
		if (sign[intSign] == c)
		{
			cout << c << endl;
			intSign = (intSign + 1) % 3;
			return true;
		}
		else {
			cout << "no" << endl;
			return false;
		}

	}

	friend ostream& operator<<(ostream& output, RunningGame rnG) {
		output << "請輸入完成以下動作指令:" << rnG.sign[rnG.intSign];
		return output;
	}
	//~RunningGame();

	void update(Hero& hero)
	{
		Position h = hero.getPos();
		if ((h.x == this->sPos.x) && (h.y == this->sPos.y) && (!this->pressed))
		{
			system("cls");
			Sleep(100);

			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
			cout << story << endl;
			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
			system("pause");


			Viewer viewer;
			viewer.showHero2();
			this->newQuest();
			int yes = 0;
			while(yes!=3)
			{
				cout << *this << endl;
				if (this->getAns())
				{
					yes++;
					if (sign[intSign] == 'a')
					{
						viewer.showHero2();
					}
					else if (sign[intSign] == 's')
					{
						viewer.showHero3();
					}
					else if (sign[intSign] == 'd')
					{
						viewer.showHero1();
					}
				}
				this->newQuest();
			}
			viewer.showHero3();
			viewer.showHero1();
			viewer.showHero2();
			viewer.showHeroAttactPig();
			Sleep(1000);
			system("cls");
			pressed = true;
			this->sIcon = "  ";
		}
	}
};
