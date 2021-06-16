#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"
#include "Item.h"
#include "Viwer.h"

//************************************************************
// AddHp Class
//************************************************************
/* 建立Item Class並在底下繼承帶不同特性的不同Item (0.3%) */
class End :public Item
{

public:
	string story = "<R相反題>\n\n"

		"突然發現，石碑上一瓶小米酒!!!\n\n"

		"勇士：哇還對我那麼好歐，出來受難還有飲料喝，\n"
		"勇士：咕嚕咕嚕...\n\n"

		"勇士：唉呦，這個小米酒是不是有問題，怎麼感覺我開始天旋地轉惹，\n"
		"勇士：我絕對不會被酒精打倒的，還好平時就有訓練，人稱反作用力大師。\n";

	string endstory = "<到達出口>\n\n"

		"頭目來出口迎接我了，真開心，趕快把石碑上的話說出來吧\n\n"

		"頭目：勇士啊，來... 說說看，我們族的精神是什麼..\n\n"
		"勇士：遇到敵人，寧死不屈...\n";

	bool pressed = false;
	string answer = "2021 OOP";

	// Default constructor
	End(void) {
		this->sPos.x = 1;
		this->sPos.y = 12;
		this->sIcon = "＃";
	};

	// Setting constructor
	End(int x, int y, string icon = "＃") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};

	// Setting constructor
	End(Position& pos, string icon = "＃") {
		this->sPos = pos;
		this->sIcon = icon;
	};

	bool checkAns(string tmp) {
		if (tmp == answer)
		{
			return true;
		}
		else {
			return false;
		}
	}

	// 判斷是否有踩到 踩到則顯示終點
	void update(Hero& h) {

		// 當Hero踩到Trigger的時候 顯示
		if ((this->sPos.x == h.getPos().x && this->sPos.y == h.getPos().y) && (!pressed))
		{
			//	石碑發現劇情引導
			system("cls");
			Sleep(100);
			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
			cout << "是石碑!!!\n" << endl;
			cout << "終於被我找到了，來看看上面祖靈寫了甚麼東西..." << endl;
			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
			system("pause");

			//	石碑viewer
			system("cls");
			Sleep(100);
			Viewer viewer;
			viewer.showTips();

			//	相反遊戲劇情
			system("cls");
			Sleep(100);
			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
			cout << story << endl;
			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
			system("pause");

			//	相反遊戲劇情
			system("cls");
			Sleep(100);
			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
			cout << "從現在開始，上下左右將會相反\n" << endl;
			cout << "喝完小米酒之後，搖晃的身體不小心觸發了開關，\n疑似聽到洞穴更深處傳來急急流水聲..." << endl;
			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
			system("pause");

			system("cls");
			Sleep(100);
			Flooded = true;
			this->sPos.x = 1;
			this->sPos.y = 1;
			pressed = true;
		}
		else if (this->sPos.x == h.getPos().x && this->sPos.y == h.getPos().y)
		{
			system("cls");
			_flushall();
			Sleep(100);
			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
			cout << endstory << endl;
			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";

			//	輸入答案
			char c;
			string tmp;
			bool lock = true;
			int k = 0;
			getline(cin, tmp);
			while (1) 
			{
				string tmp;
				getline(cin,tmp);
				/*c = _getch();
				tmp += c;*/
				//cout << tmp << endl;
				if (checkAns(tmp))
				{
					GameWin = true;
				}
				else {
					cout << "輸入錯誤，請重新輸入:\n";
					k++;
					if (k >= 3)
					{
						GameLose = true;
					}
				}
				if (GameLose || GameWin)break;
			}

			/*		if (checkAns(tmp))
					{
						GameWin = true;
					}
					else {
						GameLose = true;
					}*/

		}

	}
};

