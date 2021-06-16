#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Position.h"
#include "main.h"
#include "Creature.h"

class VocabularyGame : public Creature /* 繼承Creature的public*/
{
public:

	vector<string> dictionary;
	int intDic;
	string answer;
	bool pressed = false;
	string story = "<V單字題>\n\n"
		"岔路上遇到迷路的歪國郎，他們已經受困於洞穴中好幾天了!!!\n\n"
		"突然想起頭目說的話：\n部落的英雄，必須幫助有困難的人，這樣才成為被尊敬的勇士。\n\n"
		"勇士：但是部落中沒有人跟我講過英文，還好我有讀過小學，\n"
		"我應該還記得一點點，"
		"試著將想到的幾個單字拚出來與歪國人溝通吧。\n";

	//	init parameter, and load 2000words.txt to dictionary_vector
	VocabularyGame() 
	{

		dictionary.clear();
		//	set Random seed
		srand(time(NULL));
		answer = "";


		/*	讀檔區塊	*/
		char content[30];
		string tmpStr = "";

		fstream fs;
		fs.open("2000words.txt", ios::in);
		if (fs.is_open())
		{
			while (!fs.eof())
			{
				//	跳過編號
				fs.getline(content, 30, '\t');
				//	讀取單字
				fs.getline(content, 30, '\n');
				tmpStr = content;
				//	印出單字
				//cout << str << endl;
				dictionary.push_back(tmpStr);
			}
		}
		fs.close();

		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = "Ｖ";
	}

	VocabularyGame(int y,int x) 
	{

		dictionary.clear();
		//	set Random seed
		srand(time(NULL));
		answer = "";


		/*	讀檔區塊	*/
		char content[30];
		string tmpStr = "";

		fstream fs;
		fs.open("2000words.txt", ios::in);
		if (fs.is_open())
		{
			while (!fs.eof())
			{
				//	跳過編號
				fs.getline(content, 30, '\t');
				//	讀取單字
				fs.getline(content, 30, '\n');
				tmpStr = content;
				//	印出單字
				//cout << str << endl;
				dictionary.push_back(tmpStr);
			}
		}
		fs.close();

		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = "Ｖ";
	}

	void newQuest() 
	{
		//	取到亂數index
		intDic = rand() % dictionary.size();
		answer = dictionary[intDic];
	}

	bool checkAns(string ans) 
	{
		if (answer == ans)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend ostream& operator<<(ostream& output, VocabularyGame vbG) 
	{
		//output << maG.intA << " " << maG.arrySign[maG.intSign] << " " << maG.intB << " = " << maG.answer;
		output << "請跟著拼出 : " << vbG.answer;
		return output;
	}

	//~VocabularyGame();

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

			this->newQuest();
			string str;
			
			//	進行四次回遊戲
			for (int i = 0; i < 4; i++)
			{
				cout << *this << endl;
				cin >> str;
				if (this->checkAns(str))
				{
					cout << "->Currect" << endl;
				}
				else
				{
					/* 扣英雄的血量 */
					hero.damage(2);
					cout << "->Have some mistake" << endl;
				}
				this->newQuest();
			}

			Sleep(1000);
			system("cls");

			pressed = true;
			this->sIcon = "  ";

			//while (cin >> str)
			//{
			//	if (this->checkAns(str))
			//	{
			//		cout << "Currect" << endl;
			//	}
			//	else
			//	{
			//		/* 扣英雄的血量 */
			//		hero.damage(2);

			//		cout << "have some mistake" << endl;
			//	}

			//	Sleep(1000);
			//	system("cls");

			//	pressed = true;
			//	this->sIcon = "  ";
			//}
		}
	}
};
