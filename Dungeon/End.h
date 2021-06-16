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
/* �إ�Item Class�æb���U�~�ӱa���P�S�ʪ����PItem (0.3%) */
class End :public Item
{

public:
	string story = "<R�ۤ��D>\n\n"

		"��M�o�{�A�۸O�W�@�~�p�̰s!!!\n\n"

		"�i�h�G�z�ٹ�ڨ���n�ڡA�X�Ө����٦����ƳܡA\n"
		"�i�h�G�B�P�B�P...\n\n"

		"�i�h�G����A�o�Ӥp�̰s�O���O�����D�A���Pı�ڶ}�l�ѱۦa��S�A\n"
		"�i�h�G�ڵ��藍�|�Q�s�르�˪��A�٦n���ɴN���V�m�A�H�٤ϧ@�ΤO�j�v�C\n";

	string endstory = "<��F�X�f>\n\n"

		"�Y�بӥX�f�ﱵ�ڤF�A�u�}�ߡA���֧�۸O�W���ܻ��X�ӧa\n\n"

		"�Y�ءG�i�h�ڡA��... �����ݡA�ڭ̱ڪ��믫�O����..\n\n"
		"�i�h�G�J��ĤH�A�禺���}...\n";

	bool pressed = false;
	string answer = "2021 OOP";

	// Default constructor
	End(void) {
		this->sPos.x = 1;
		this->sPos.y = 12;
		this->sIcon = "��";
	};

	// Setting constructor
	End(int x, int y, string icon = "��") {
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};

	// Setting constructor
	End(Position& pos, string icon = "��") {
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

	// �P�_�O�_����� ���h��ܲ��I
	void update(Hero& h) {

		// ��Hero���Trigger���ɭ� ���
		if ((this->sPos.x == h.getPos().x && this->sPos.y == h.getPos().y) && (!pressed))
		{
			//	�۸O�o�{�@���޾�
			system("cls");
			Sleep(100);
			cout << "�СССССССССССССССССССС�" << "\n";
			cout << "�O�۸O!!!\n" << endl;
			cout << "�ש�Q�ڧ��F�A�ӬݬݤW�����F�g�F�ƻ�F��..." << endl;
			cout << "�СССССССССССССССССССС�" << "\n";
			system("pause");

			//	�۸Oviewer
			system("cls");
			Sleep(100);
			Viewer viewer;
			viewer.showTips();

			//	�ۤϹC���@��
			system("cls");
			Sleep(100);
			cout << "�СССССССССССССССССССС�" << "\n";
			cout << story << endl;
			cout << "�СССССССССССССССССССС�" << "\n";
			system("pause");

			//	�ۤϹC���@��
			system("cls");
			Sleep(100);
			cout << "�СССССССССССССССССССС�" << "\n";
			cout << "�q�{�b�}�l�A�W�U���k�N�|�ۤ�\n" << endl;
			cout << "�ܧ��p�̰s����A�n�̪����餣�p��Ĳ�o�F�}���A\n�æ�ť��}�ާ�`�B�Ǩӫ��y���n..." << endl;
			cout << "�СССССССССССССССССССС�" << "\n";
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
			cout << "�СССССССССССССССССССС�" << "\n";
			cout << endstory << endl;
			cout << "�СССССССССССССССССССС�" << "\n";

			//	��J����
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
					cout << "��J���~�A�Э��s��J:\n";
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

