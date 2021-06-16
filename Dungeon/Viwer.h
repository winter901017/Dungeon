/*顯示*/
#pragma once
#ifndef VIEWER_H
#define VIEWER_H

#include <iostream>
#include <string>
#include<windows.h>
#include<winusb.h>
#include <cwchar>
#include <math.h>
#include <ctime>
#include <conio.h>  /*  _getch() */
#include <iomanip> 
#include <fstream>

using namespace std;

/* 設置文字顏色 */
/* 119 淺灰色 lightGray */
/* 136 深灰色 darkGray */
/* 255 白色 white */
/*   7 黑色 black */
const int LIGHTGRAY = 119;
const int DARKGRAY = 136;
const int WHITE = 255;
const int BLACK = 15;
const int DARKBLUE = 31;
const int GRAY = 127;

class Viewer
{
public:

	COORD cursorPosition;// 現在光標的位置
	//-------------------------------------------------------------------------------------
	/*                              一開始進來的時候介面 單純顯示						 */
	//-------------------------------------------------------------------------------------
	/* 顯示標題 */
	void showStory()
	{
		// 關閉光標
		this->HideCursor();

		/* 重複卡在這裡直到正確或是離開 */
		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */
		Sleep(100);
		cout << "<起頭劇情>\n\n";
		cout << "於1945年，逮丸的古老部落...\n\n"

			"長老告訴即將畢業的年輕小夥子，如何成為部落英勇勇士的方法...\n\n"

			"今天年輕小夥子即將踏上未知的地洞中，帶著部落的祝福，\n"
			"去將終點石碑上的祖靈給後代的話記下來，\n"
			"回到村莊中正確得告訴長老，這才能成為真正的勇士、真正的男人!!\n\n"

			"勇士：等我回來要煮好吃的山豬肉給我吃哦。 \n";

		// 關閉光標
		this->ShowCursor();
	}

	//-------------------------------------------------------------------------------------
	/*                              一開始進來的時候介面 單純顯示						 */
	//-------------------------------------------------------------------------------------
	/* 顯示標題 */
	void showTitle()
	{
		// 關閉光標
		this->HideCursor();

		/* 重複卡在這裡直到正確或是離開 */
		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */
		Sleep(100);
		vector<string> outputTitle;
		string line[7];
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

		line[0] = "				       ########     #######    ##    ##    ######     ########    #######    ##    ##\n";
		line[1] = "				       ##     ##   ##     ##   ###   ##   ##    ##    ##         ##     ##   ###   ##\n";
		line[2] = "				       ##     ##   ##     ##   ####  ##   ##          ##         ##     ##   ####  ##\n";
		line[3] = "				       ##     ##   ##     ##   ## ## ##   ##   ####   ######     ##     ##   ## ## ##\n";
		line[4] = "				       ##     ##   ##     ##   ##  ####   ##    ##    ##         ##     ##   ##  ####\n";
		line[5] = "				       ##     ##   ##     ##   ##   ###   ##    ##    ##         ##     ##   ##   ###\n";
		line[6] = "				       ########     #######    ##    ##    ######     ########    #######    ##    ##\n";

		for (int i = 0; i < 7; i++)
		{
			outputTitle.push_back(line[i]);
		}
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 91; j++)
			{
				cout << line[i][j];
				for (int delay = 0; delay < 3000000; delay++); // 延遲
			}
		}

		// 關閉光標
		this->ShowCursor();
	}

	//-------------------------------------------------------------------------------------
	/*                             角色踩到終點時顯示									 */
	//-------------------------------------------------------------------------------------

	/* 顯示標題 */
	void showHeroWin()
	{
		// 關閉光標
		this->HideCursor();

		system("cls");

		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */
		Sleep(100);
		vector<string> outputTitle;
		string line[7];
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

		line[0] = "					                  ##      ##     ####     ##    ##\n";
		line[1] = "					                  ##  ##  ##      ##      ###   ##\n";
		line[2] = "					                  ##  ##  ##      ##      ####  ##\n";
		line[3] = "					                  ##  ##  ##      ##      ## ## ##\n";
		line[4] = "					                  ##  ##  ##      ##      ##  ####\n";
		line[5] = "					                  ##  ##  ##      ##      ##   ###\n";
		line[6] = "					                   ###  ###      ####     ##    ## ";

		for (int i = 0; i < 7; i++)
		{
			outputTitle.push_back(line[i]);
		}
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 57; j++)
			{
				cout << line[i][j];
				for (int delay = 0; delay < 3000000; delay++); // 延遲
			}
		}

		for (int j = 0; j < 8; j++)
		{
			cout << "．";
			for (int delay = 0; delay < 100000000; delay++); // 延遲
		}
		cout << "\n\n\n\n\n\n\n";
		for (int i = 0; i < 58; i++)cout << " ";
		Sleep(1000);
	}

	//-------------------------------------------------------------------------------------
	/*                             角色死亡時顯示										 */
	//-------------------------------------------------------------------------------------
	void showHeroDie()
	{
		// 關閉光標
		this->HideCursor();

		system("cls");
		this->setCursorPosition(0, 0);
		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */
		Sleep(100);
		vector<string> outputTitle;
		string line[7];
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

		line[0] = "					                  ########      ####     ########\n";
		line[1] = "					                  ##     ##      ##      ##      \n";
		line[2] = "					                  ##     ##      ##      ##      \n";
		line[3] = "					                  ##     ##      ##      ######  \n";
		line[4] = "					                  ##     ##      ##      ##      \n";
		line[5] = "					                  ##     ##      ##      ##      \n";
		line[6] = "					                  ########      ####     ########  ";

		for (int i = 0; i < 7; i++)
		{
			outputTitle.push_back(line[i]);
		}
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 56; j++)
			{
				cout << line[i][j];
				for (int delay = 0; delay < 3000000; delay++); // 延遲
			}
		}

		for (int j = 0; j < 8; j++)
		{
			cout << "．";
			for (int delay = 0; delay < 100000000; delay++); // 延遲
		}

		cout << "\n\n\n\n\n\n\n";
		for (int i = 0; i < 58; i++)cout << " ";
		Sleep(1000);
	}

	//-------------------------------------------------------------------------------------
	/*                             碰到石碑時顯示										 */
	//-------------------------------------------------------------------------------------

	/* 顯示標題 */
	void showTips()
	{
		system("cls");

		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */
		Sleep(100);
		vector<string> outputTitle;
		string line[7];
		cout << "\n\n\n\n\n\n\n\n\n";

		line[0] = "					 #######    #####    #######     ##        #######   #######  ########  \n";
		line[1] = "					##     ##  ##   ##  ##     ##  ####       ##     ## ##     ## ##     ## \n";
		line[2] = "					       ## ##     ##        ##    ##       ##     ## ##     ## ##     ## \n";
		line[3] = "					 #######  ##     ##  #######     ##       ##     ## ##     ## ########  \n";
		line[4] = "					##        ##     ## ##           ##       ##     ## ##     ## ##        \n";
		line[5] = "					##         ##   ##  ##           ##       ##     ## ##     ## ##        \n";
		line[6] = "					#########   #####   #########  ######      #######   #######  ##         ";

		for (int i = 0; i < 7; i++)
		{
			outputTitle.push_back(line[i]);
		}
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 79; j++)
			{
				cout << line[i][j];
				for (int delay = 0; delay < 3000000; delay++); // 延遲
			}
		}

		cout << "\n\n\n\n\n\n\n";
		for (int i = 0; i < 45; i++)cout << " ";
		Sleep(1000);
		system("cls");
	}

	//-------------------------------------------------------------------------------------
	/*                             角色直接遇到Pig時顯示								 */
	//-------------------------------------------------------------------------------------

	/* 顯示標題 */
	void showQuestionMark()
	{
		system("cls");
		this->consolePhotoTextSize(3); /* 設定一開始的文字大小 */
		this->consoleFullScreen();
		system("cls");

		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */
		Sleep(100);

		fstream file;
		string fileName = "QuestionMark.txt";
		file.open(fileName, ios::in);
		string tmp;
		while (getline(file, tmp))
		{
			cout << tmp << '\n';
		}

		Sleep(3000); // dealy

		system("cls"); // clear screen
		this->consoleTextSize(24);
		this->consoleFullScreen();
		cout << "\n\n\n\n\n\n\n\n                                       你遇到BUG囉  哈哈哈哈哈哈哈哈" << "\n\n\n\n\n\n\n";
		cout << "                                       "; // set view

	}

	//-------------------------------------------------------------------------------------
	/*                             人攻擊肥肥 											 */
	//-------------------------------------------------------------------------------------
	void showHeroAttactPig()
	{
		// 隱藏光標
		this->ShowCursor();
		system("cls");

		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */

		//讀英雄的ascii
		vector<string> data;
		this->readHeroTxtFile(data);

		//讀豬的ascii 
		vector<string> tmp;
		this->readPigTxtFile(tmp);


		int  count = 0;
		// 英雄與怪物需要一樣高
		for (int heroTall = 0; heroTall < data.size(); heroTall++)
		{
			//新增角色的距離
			for (int i = 0; i < 80; i++)
			{
				data[count] += ' ';
			}
			count++;
			data[heroTall] += tmp[heroTall];
		};

		// 輸出圖形
		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data[i].size(); j++)
			{
				cout << data[i][j];
			}
			cout << '\n';
		}
		Sleep(500); // dealy 顯示一下初始畫面

		// 以下是在做排版 慢慢數的
		for (int run = 0; run < 120; run++)
		{
			vector<string> temp = data;
			Sleep(9); // dealy
			this->clr();
			// input.replace(input.find("$_"), 2, order);
			for (int i = 31+run; i < 35+run; i++) //輸出子彈
			{
				temp[8][i] = '-';
			};
			temp[8][34+run] = '>';

			this->setCursorPosition(31 + run-1, 8); 
			cout << ' '; // 清除上一步的位置

			for (int j = 31 + run; j < temp[8].size(); j++) //更改31行的顯示 
			{
				cout << temp[8][j];
			}
			cout << '\n';

		}
		Sleep(3000); // dealy

		system("cls"); // clear screen

		// 開啟光標
		this->ShowCursor();
	}

	//-------------------------------------------------------------------------------------
	/*                             肥肥攻擊人 											 */
	//-------------------------------------------------------------------------------------
	void showPigAttactHero()
	{
		// 隱藏光標
		this->ShowCursor();
		system("cls");

		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */

		//讀英雄的ascii
		vector<string> data;
		this->readHeroTxtFile(data);

		//讀豬的ascii 
		vector<string> pig;
		this->readPigTxtFile(pig);

		vector<string>showIntial = data;
		int  count = 0;
		// 英雄與怪物需要一樣高
		for (int heroTall = 0; heroTall < showIntial.size(); heroTall++)
		{
			//新增角色的距離
			for (int i = 0; i < 80; i++)
			{
				showIntial[count] += ' ';
			}
			count++;
			showIntial[heroTall] += pig[heroTall];
		};
		
		// 輸出圖形
		for (int i = 0; i < showIntial.size(); i++)
		{
			for (int j = 0; j < showIntial[i].size(); j++)
			{
				cout << showIntial[i][j];
			}
			cout << '\n';
		}



		Sleep(500); // dealy 顯示一下初始畫面

		int blank = 80;
		// 以下是在做排版 慢慢數的
		for (int run = 0; run < 113; run++)
		{//0~pig.size() 9
			this->clr();
			vector<string>tmp = showIntial;

			for (int a = 0; a < showIntial.size(); a++)
			{
				showIntial[a].erase(showIntial[a].begin()+30, showIntial[a].begin()+31);
				showIntial[a].erase(showIntial[a].begin() + 153 - run, showIntial[a].begin() + 154 - run);
			}

			for (int i = 0; i < showIntial.size(); i++)
			{
				for (int j = 0; j < showIntial[i].size(); j++)
				{
					cout << showIntial[i][j];
					if ((i == (17)) && (j == (154 - run)))cout << ' ';
					if ((i == (18)) && (j == (154 - run)))cout << ' ';
				}
				cout << '\n';
			}

		}
		Sleep(5000); // dealy

		system("cls"); // clear screen

		// 開啟光標
		this->ShowCursor();
	}

	//-------------------------------------------------------------------------------------
	/*                             顯示Hero1 											 */
	//-------------------------------------------------------------------------------------
	void showHero1()
	{
		// 隱藏光標
		this->ShowCursor();
		system("cls");

		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */

		//讀英雄的ascii
		vector<string> data;
		this->readHero1TxtFile(data);

		//讀豬的ascii 
		vector<string> tmp;
		this->readPigTxtFile(tmp);


		int  count = 0;
		// 英雄與怪物需要一樣高
		for (int heroTall = 0; heroTall < data.size(); heroTall++)
		{
			//新增角色的距離
			for (int i = 0; i < 12; i++)
			{
				data[count] += ' ';
			}
			count++;
			data[heroTall] += tmp[heroTall];
		};

		// 輸出圖形
		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data[i].size(); j++)
			{
				cout << data[i][j];
			}
			cout << '\n';
		}
		Sleep(500); // dealy 顯示一下初始畫面

		//system("cls"); // clear screen

		// 開啟光標
		this->ShowCursor();
	}

	//-------------------------------------------------------------------------------------
	/*                             顯示Hero2 											 */
	//-------------------------------------------------------------------------------------
	void showHero2()
	{
		// 隱藏光標
		this->ShowCursor();
		system("cls");

		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */

		//讀英雄的ascii
		vector<string> data;
		this->readHero2TxtFile(data);

		//讀豬的ascii 
		vector<string> tmp;
		this->readPigTxtFile(tmp);
		 

		int  count = 0;
		// 英雄與怪物需要一樣高
		for (int heroTall = 0; heroTall < data.size(); heroTall++)
		{
			//新增角色的距離
			for (int i = 0; i < 48; i++)
			{
				data[count] += ' ';
			}
			count++;
			data[heroTall] += tmp[heroTall];
		};

		// 輸出圖形
		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data[i].size(); j++)
			{
				cout << data[i][j];
			}
			cout << '\n';
		}
		Sleep(500); // dealy 顯示一下初始畫面

		//system("cls"); // clear screen

		// 開啟光標
		this->ShowCursor();
	}

	//-------------------------------------------------------------------------------------
	/*                             顯示Hero3 											 */
	//-------------------------------------------------------------------------------------
	void showHero3()
	{
		// 隱藏光標
		this->ShowCursor();
		system("cls");

		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */

		//讀英雄的ascii
		vector<string> data;
		this->readHero3TxtFile(data);

		//讀豬的ascii 
		vector<string> tmp;
		this->readPigTxtFile(tmp);


		int  count = 0;
		// 英雄與怪物需要一樣高
		for (int heroTall = 0; heroTall < data.size(); heroTall++)
		{
			//新增角色的距離
			for (int i = 0; i < 80; i++)
			{
				data[count] += ' ';
			}
			count++;
			data[heroTall] += tmp[heroTall];
		};

		// 輸出圖形
		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data[i].size(); j++)
			{
				cout << data[i][j];
			}
			cout << '\n';
		}
		Sleep(500); // dealy 顯示一下初始畫面

		//system("cls"); // clear screen

		// 開啟光標
		this->ShowCursor();
	}

	//-------------------------------------------------------------------------------------
	/*                             讀取英雄的txt 										 */
	//-------------------------------------------------------------------------------------
	void readHeroTxtFile(vector<string> & data)
	{
		fstream file;
		string fileName = "Hero.txt";
		file.open(fileName, ios::in);
		string tmp;
		while (getline(file, tmp))
		{
			data.push_back(tmp);
		}
		file.close();

	}

	//-------------------------------------------------------------------------------------
	/*                             讀取英雄1的txt 										 */
	//-------------------------------------------------------------------------------------
	void readHero1TxtFile(vector<string> &data)
	{
		fstream file;
		string fileName = "Hero1.txt";
		file.open(fileName, ios::in);
		string tmp;
		while (getline(file, tmp))
		{
			data.push_back(tmp);
		}
		file.close();

	}

	//-------------------------------------------------------------------------------------
/*                             讀取英雄2的txt 										 */
//-------------------------------------------------------------------------------------
	void readHero2TxtFile(vector<string>& data)
	{
		fstream file;
		string fileName = "Hero2.txt";
		file.open(fileName, ios::in);
		string tmp;
		while (getline(file, tmp))
		{
			data.push_back(tmp);
		}
		file.close();

	}

	//-------------------------------------------------------------------------------------
/*                             讀取英雄3的txt 										 */
//-------------------------------------------------------------------------------------
	void readHero3TxtFile(vector<string>& data)
	{
		fstream file;
		string fileName = "Hero3.txt";
		file.open(fileName, ios::in);
		string tmp;
		while (getline(file, tmp))
		{
			data.push_back(tmp);
		}
		file.close();

	}
	//-------------------------------------------------------------------------------------
	/*                             讀取肥肥的txt 										 */
	//-------------------------------------------------------------------------------------
	void readPigTxtFile(vector<string>& data)
	{
		fstream file;
		string fileName = "Pig.txt";
		file.open(fileName, ios::in);
		string tmp;
		while (getline(file, tmp))
		{
			data.push_back(tmp);
		}
		file.close();

	}

	//-------------------------------------------------------------------------------------
	/*                                隱藏光標											 */
	//-------------------------------------------------------------------------------------
	void HideCursor()
	{
		CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	}

	//-------------------------------------------------------------------------------------
	/*                                開啟光標											 */
	//-------------------------------------------------------------------------------------
	void ShowCursor()
	{
		CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	}

	//-------------------------------------------------------------------------------------
	/*                              設置光標位置			                             */
	//-------------------------------------------------------------------------------------
	void setCursorPosition(short x, short y)
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		cursorPosition.X = x; // 更動儲存的光標位置
		cursorPosition.Y = y; // 更動儲存的光標位置
		SetConsoleCursorPosition(screen, cursorPosition); //設定光標
	}

	//-------------------------------------------------------------------------------------
	/*                              設置光標絕對位置			                         */
	//-------------------------------------------------------------------------------------
	void setCursorAbsolutePosition(short x, short y)
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		cursorPosition.X += x; // 從原本位置上進行增加
		cursorPosition.Y += y; // 從原本位置上進行增加
		SetConsoleCursorPosition(screen, cursorPosition); //設定光標
	}

	//-------------------------------------------------------------------------------------
	/*                              取得光標位置X										 */
	//-------------------------------------------------------------------------------------
	short getCursorPositionX()
	{
		return cursorPosition.X;
	}

	//-------------------------------------------------------------------------------------
	/*                              取得光標位置Y										 */
	//-------------------------------------------------------------------------------------
	short getCursorPositionY()
	{
		return cursorPosition.Y;
	}

	//-------------------------------------------------------------------------------------
	/*                             文字顏色設置						                     */
	//-------------------------------------------------------------------------------------
	void setColor(int color = BLACK) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
	}

	//-------------------------------------------------------------------------------------
	/*                               清除畫面							                 */
	//------------------------------------------------------------------------------------- 
	//清除畫面 解決使用 system("cls") 會有閃爍問題 
	void clr()
	{
		//system("cls");
		
		COORD cursorPosition;
		cursorPosition.X = 0;
		cursorPosition.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
		
	}

	//-------------------------------------------------------------------------------------
	/*                               螢幕最大化							                 */
	//-------------------------------------------------------------------------------------

		/*  Console設為全螢幕 */
	void consoleFullScreen()
	{
		//設置大小 x, y, width, height
		HWND hwnd = GetConsoleWindow();
		if (hwnd != NULL) { MoveWindow(hwnd, 0, 0, 1400, 800, TRUE); }
		MoveWindow(hwnd, 0, 0, 1400, 800, TRUE);
		SetWindowPos(hwnd, 0, 0, 0, 1400, 800, SWP_SHOWWINDOW | SWP_NOMOVE);

		//最大化
		//HWND hwnd = GetForegroundWindow();
		//PostMessage(hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);

	}

	//-------------------------------------------------------------------------------------
	/*                               設置文字大小							             */
	//-------------------------------------------------------------------------------------

		/*  Console設置文字大小 */
	void consoleTextSize(int size)
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;                   // Width of each character in the font
		cfi.dwFontSize.Y = size;                  // 修改文字大小
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		//std::wcscpy(cfi.FaceName, L"Console"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}


	//-------------------------------------------------------------------------------------
	/*                               設置文字大小(圖片使用)							     */
	//-------------------------------------------------------------------------------------
	void consolePhotoTextSize(int size)
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = size;                   // Width of each character in the font
		cfi.dwFontSize.Y = size;                  // 修改文字大小
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		//std::wcscpy(cfi.FaceName, L"Console"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}
};

#endif // !VIEWER_H

