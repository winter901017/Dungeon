#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Position.h"
#include "main.h"
#include "Creature.h"

class VocabularyGame : public Creature /* �~��Creature��public*/
{
public:

	vector<string> dictionary;
	int intDic;
	string answer;
	bool pressed = false;

	//	init parameter, and load 2000words.txt to dictionary_vector
	VocabularyGame() {

		dictionary.clear();
		//	set Random seed
		srand(time(NULL));
		answer = "";


		/*	Ū�ɰ϶�	*/
		char content[30];
		string tmpStr = "";

		fstream fs;
		fs.open("2000words.txt", ios::in);
		if (fs.is_open())
		{
			while (!fs.eof())
			{
				//	���L�s��
				fs.getline(content, 30, '\t');
				//	Ū����r
				fs.getline(content, 30, '\n');
				tmpStr = content;
				//	�L�X��r
				//cout << str << endl;
				dictionary.push_back(tmpStr);
			}
		}
		fs.close();

		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = "��";
	}

	VocabularyGame(int y,int x) {

		dictionary.clear();
		//	set Random seed
		srand(time(NULL));
		answer = "";


		/*	Ū�ɰ϶�	*/
		char content[30];
		string tmpStr = "";

		fstream fs;
		fs.open("2000words.txt", ios::in);
		if (fs.is_open())
		{
			while (!fs.eof())
			{
				//	���L�s��
				fs.getline(content, 30, '\t');
				//	Ū����r
				fs.getline(content, 30, '\n');
				tmpStr = content;
				//	�L�X��r
				//cout << str << endl;
				dictionary.push_back(tmpStr);
			}
		}
		fs.close();

		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = "��";
	}

	void newQuest() {
		//	����ü�index
		intDic = rand() % dictionary.size();
		answer = dictionary[intDic];
	}

	bool checkAns(string ans) {
		if (answer == ans)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend ostream& operator<<(ostream& output, VocabularyGame vbG) {
		//output << maG.intA << " " << maG.arrySign[maG.intSign] << " " << maG.intB << " = " << maG.answer;
		output << "�и�ۿ�J : " << vbG.answer;
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

			this->newQuest();
			cout << *this << endl;
			string str;
			/*/while (*/cin >> str;//)
			//{
				if (this->checkAns(str))
				{
					cout << "Currect" << endl;
				}
				else
				{
					/* ���^������q */
					hero.damage(2);

					cout << "have some mistake" << endl;
				}


				//this->newQuest();
				//cout << *this << endl;
			//}
			Sleep(1000);
			system("cls");

			pressed = true;
			this->sIcon = "  ";
		}
	}
};
