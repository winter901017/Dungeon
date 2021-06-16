/************************************************************************
File:   source.cpp

Author:


Comment:
		1.登入畫面	我登入應該會模仿類似那種RPG的FU 
		2.生城地圖與角色
		3.創建主角 
		4.開始遊戲
		5.遇到怪物進入小遊戲	
		6.走到終點結束

************************************************************************/

#include "main.h"

// Dungeon Role
#include "Creature.h"
#include "MathGame.h"
#include "Item.h"
#include "ShowExit.h"
#include "ViewAdd.h"
#include "VocabularyGame.h"
#include "RunningGame.h"
#include "Kill.h"
#include "End.h"

#include<exception>
using std::exception;

// 建立英雄
Hero	 gHero(1, 1);

// 建立顯示
Viewer viewer;

// Constent value
const string GWALL = "■";
const string GNOTHING = "  ";

const int GWIDTH = 21;
const int GHEIGHT = 21;
const double gTimeLog = 0.033;

// Distance
const int gDistance = 4;

// Flooded 淹水
bool Flooded = false;

// 結束遊戲
bool GameLose = false;

//
bool GameWin = false;
// 計算淹水之後的步數
int countStep = 0;

// 用來儲存版面資料
string gBoard[GHEIGHT][GWIDTH] = 
{

"■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■",
"■","  ","  ","  ","■","  ","  ","  ","■","  ","  ","  ","  ","  ","■","  ","  ","  ","■","  ","■",
"■","  ","■","  ","■","  ","■","  ","■","  ","■","■","■","  ","■","  ","■","  ","■","  ","■",
"■","  ","■","  ","■","  ","■","  ","■","  ","  ","  ","■","  ","  ","  ","■","  ","  ","  ","■",
"■","  ","■","■","■","  ","■","■","■","  ","■","  ","■","■","■","  ","■","  ","■","  ","■",
"■","  ","■","  ","  ","  ","  ","  ","  ","  ","■","  ","  ","  ","■","  ","■","  ","■","  ","■",
"■","  ","■","  ","■","■","■","■","■","  ","■","■","■","  ","■","■","■","  ","■","■","■",
"■","  ","  ","  ","■","  ","  ","  ","  ","  ","  ","  ","  ","  ","■","  ","  ","  ","■","  ","■",
"■","  ","■","  ","■","  ","■","  ","■","  ","■","■","■","■","■","  ","■","■","■","  ","■",
"■","  ","  ","  ","  ","  ","■","  ","■","  ","  ","  ","  ","  ","■","  ","  ","  ","  ","  ","■",
"■","■","■","■","■","■","■","  ","■","  ","■","■","■","  ","■","■","■","  ","■","  ","■",
"■","  ","■","  ","  ","  ","■","■","■","  ","■","  ","■","  ","  ","  ","  ","  ","■","  ","■",
"■","  ","■","  ","■","  ","■","  ","  ","  ","■","  ","■","■","■","■","■","  ","■","■","■",
"■","  ","  ","  ","■","  ","■","■","■","■","■","  ","  ","  ","  ","  ","  ","  ","■","  ","■",
"■","  ","■","■","■","  ","  ","  ","  ","  ","  ","  ","■","  ","■","■","■","  ","■","  ","■",
"■","  ","■","  ","■","  ","  ","  ","■","  ","■","  ","■","  ","■","  ","■","  ","■","  ","■",
"■","■","■","  ","■","  ","■","■","■","  ","■","■","■","  ","■","  ","■","  ","  ","  ","■",
"■","  ","■","  ","■","  ","■","  ","  ","  ","■","  ","  ","  ","■","  ","  ","  ","■","  ","■",
"■","  ","■","  ","■","  ","■","  ","■","  ","■","  ","■","  ","■","■","■","■","■","  ","■",
"■","  ","  ","  ","  ","  ","  ","  ","■","  ","■","  ","■","  ","  ","  ","■","  ","  ","  ","■",
"■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■","■",

};

// 定義六種輸入指令與對應陣列index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	INVALID,
};

/* 統一使用 Creature* 陣列 /Vector 管理 (0.2%) */
std::vector<Creature*> monster;

// function declare
// 偵測輸入狀態
void keyUpdate(bool key[]);
// 判斷位置是否為空
bool isPositionValid(Position& loc);
// 初始化版面
void setupBoard();
// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);
// 說明故事的
void drawStory(void);
// 程式主驅動函式
void update(bool key[]);
// 控制英雄可以看到的地圖範圍
bool heroViewControl(int boardY, int boardX);

/* 統一使用 Item* 陣列 /Vector 管理 (0.3%) */
std::vector<Item*> item;

int main(int argc, char** argv)
{
	/* login Initial */
	viewer.consoleFullScreen(); /* 最大化 */
	viewer.consoleTextSize(20); /* 設定一開始的文字大小 */
	viewer.clr(); /* 將原本控制台的資料清除 防止控制光標有Bug */
	viewer.setColor(); //設置文字顏色
	viewer.showTitle();
	Sleep(2000);
	system("cls"); /* 清除視窗 */
	viewer.showStory();
	system("pause");
	system("cls");
	//viewer.showHeroAttactPig();
	//viewer.showPigAttactHero();
	//viewer.showQuestionMark();
	//viewer.showHeroWin();
	//viewer.showHeroDie();

	//system("cls"); /* 清除視窗 */
	//system("pause");
	//viewer.readHero1TxtFile();
	//viewer.readHero2TxtFile();
	//viewer.readHero3TxtFile();
	//Sleep(500000);
	
	// 隱藏光標 防止螢幕刷新閃爍
	viewer.ShowCursor();

	// 用來管理鍵盤輸入狀態的陣列
	bool gKeyState[7];
	
	/* 存放MathGame 0 */
	MathGame* g1MathGame = new MathGame(15,17);
	monster.push_back(g1MathGame);

	/* 存放MathGame 1 */
	MathGame* g2MathGame = new MathGame(16,13);
	monster.push_back(g2MathGame);

	/* 存放MathGame 2 */
	MathGame* g3MathGame = new MathGame(14,10);
	monster.push_back(g3MathGame);

	/* 存放VocabularyGame 3 */
	VocabularyGame* g1VocabularyGame = new VocabularyGame(5,8);
	monster.push_back(g1VocabularyGame);

	/* 存放VocabularyGame 4 */
	VocabularyGame* g2VocabularyGame = new VocabularyGame(7,8);
	monster.push_back(g2VocabularyGame);

	/* 存放Kill 5 */
	Kill* g1Kill = new Kill(10,7);
	monster.push_back(g1Kill);

	/* 存放Kill 6 */
	Kill* g2Kill = new Kill(17,1);
	monster.push_back(g2Kill);

	/* 存放Pig 7 */
	RunningGame* g1RunningGame = new RunningGame(1,13);
	monster.push_back(g1RunningGame);

	/* 存放Reverse 8 */
	RunningGame* g2RunningGame = new RunningGame(7,16);
	monster.push_back(g2RunningGame);

	/* 存放Reverse 9 */
	RunningGame* g3RunningGame = new RunningGame(9,13);
	monster.push_back(g3RunningGame);


	/* 統一使用 Item* 陣列 /Vector 管理 (0.3%) */

	/* 存放gShowExit 0 */
	ShowExit* gShowExit = new ShowExit(7,3);
	item.push_back(gShowExit);

	/* 存放gShowExit 1 */
	ViewAdd* gViewAdd = new ViewAdd(7, 12);
	item.push_back(gViewAdd);

	/* 存放gShowExit 2 */
	End* gEnd = new End(1, 12);
	item.push_back(gEnd);

	// Draw the bord and information
	drawStory();
	draw();
	drawInfo();

	// Variable for game loop
	clock_t startT, endT;
	startT = clock();
	endT = clock();

	// 系統時間
	time_t tt;
	tt = time(NULL);
	time_t startSec = tt;

	// Get the press key
	keyUpdate(gKeyState);

	// Run the game loop
	while (!gKeyState[ValidInput::EESC]) {

		// Compute the time lap
		double timeFrame = (double)(endT - startT) / CLOCKS_PER_SEC;

		// Execute the game loop
		if (timeFrame >= gTimeLog) {
			update(gKeyState);
			startT = clock();
		}

		// 輸出秒數
		if ((!GameLose) && (!GameWin))
		{
			tt = time(NULL);
			//viewer.setCursorPosition(0, 35);
			if ((tt % 60) >= 10)
			{
				//cout << tt % 60;
			}
			else
			{
				//cout << ' ' << tt % 60;
			}
		}

		// 遇到黑人問號
		if (GameLose && GameWin)
		{
			break;
		}

		// 角色死亡
		if (GameLose)
		{
			Sleep(500);
			viewer.showHeroDie();
			break;
		};

		// 成功到達終點
		if (GameWin)
		{
			Sleep(500);
			viewer.showHeroWin();
			break;
		};

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();
	}
	system("pause");
	return 0;
}

//******************************************************************
//
// * 偵測輸入狀態
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++) {
		key[i] = false;
	}

	bool hasInput = false;
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); // Get Input Handle
	INPUT_RECORD InputRecord; // Recode Console Input
	DWORD Events;

	SetConsoleMode(hin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT);

	ReadConsoleInput(hin, &InputRecord, 1, &Events); // Read Console Input
	 
	switch (InputRecord.EventType)
	{
	case KEY_EVENT: // Keyboard Input
		if (InputRecord.Event.KeyEvent.bKeyDown) // Keyboard Press
		{
			hasInput = true;
			switch (InputRecord.Event.KeyEvent.wVirtualKeyCode) // Trigger Button
			{
			case int('W') :
				key[ValidInput::EW] = true;
				break;
			case int('A') :
				key[ValidInput::EA] = true;
				break;
			case int('S') :
				key[ValidInput::ES] = true;
				break;
			case int('D') :
				key[ValidInput::ED] = true;
				break;
			case 27: // ESC
				key[ValidInput::EESC] = true;
				break;
			}
		}
		break;

	default:
		break;
	}
	FlushConsoleInputBuffer(hin);

}

//******************************************************************
//
// * 判斷位置是否為空
//==================================================================
bool isPositionValid(Position& pos)
//==================================================================
{
	// Check whether it is an empty space
	if (gBoard[pos.y][pos.x] == GNOTHING) {
		return true;
	}
	return false;
}

//******************************************************************
//
// * clip algroithm
//==================================================================
float clip(float n, float minimum, float maximum)
//==================================================================
{
	return max(minimum, min(n, maximum));
}

//******************************************************************
//
// * 利用 call-by-referce 將計算得到的方向回傳
//==================================================================
bool canSee(Position cPos, Position hPos, Position& dir)
//==================================================================
{
	// the dir_x and dir_y value are call-by-refernce
	dir.x = (int)clip((float)(hPos.x - cPos.x), -1.f, 1.f); // clip the value between -1 ~ 1
	dir.y = (int)clip((float)(hPos.y - cPos.y), -1.f, 1.f);
	int count = 0;
	do {
		// spot the target position
		if (cPos.x + dir.x * count == hPos.x &&
			cPos.y + dir.y * count == hPos.y) {
			return true;
		}
		count++;
	} while (count < gDistance); // check the range in 4 units
	return false;
}

//******************************************************************
//
// * Control Hero Can See View 
//	判斷如果傳進來的參數在英雄身旁 回傳 True
//	不是則 回傳 False
//==================================================================
bool heroViewControl(int boardY, int boardX)
//==================================================================
{	
	// 控制視野範圍
	int heroCanSeeView= gHero.getHeroCanSeeView(); // 資料記錄在hero

	Position h = gHero.getPos();
	int HeroX = h.x;
	int HeroY = h.y;

	int exitX = 1;
	int exitY = 12;

	// 判斷 英雄身旁是否是 (heroCanSeeView  * heroCanSeeView) 是的話就顯示出來
	if (((boardX >= (HeroX - heroCanSeeView)) && (boardX <= (HeroX + heroCanSeeView))) && ((boardY >= (HeroY - heroCanSeeView)) && (boardY <= (HeroY + heroCanSeeView))))
	{
		return true;
	}

	// 判斷是否到達ShowExit 是的話顯示出來 
	else if ((boardY == exitY) && (boardX == exitX)) 
	{
		// 判斷是否踩到Trigger 有的話顯示 沒有的話不顯示
		if (gHero.getShowExit())
		{
			return true;
		}
	}
	else
	{
		return false;
	}
	return false;
}


//******************************************************************
//
// * Draw the board
//==================================================================
void draw()
//==================================================================
{
	// 將角色放入地圖中
	string drawBoard[GHEIGHT][GWIDTH];

	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// 淹水後 地圖要從Y軸底下往上填補
	if (Flooded)
	{
		for (int fill = 0; fill < (countStep / 5); fill++)
		{
			int heigh = GHEIGHT;
			heigh -= (fill + 2);
			for (int j = 0; j < GWIDTH; j++)
			{
				if (gBoard[heigh][j] != "■")gBoard[heigh][j] = "Ｘ";
			}
		}
		// 當淹水到最頂時 遊戲結束 輸了
		if ((countStep / 5) == (GHEIGHT-1))GameLose = true;
	}
	else
	{
		//Update the MathGame information
		Position m1 = monster[0]->getPos();
		int MathGameX1 = m1.x;
		int MathGameY1 = m1.y;
		drawBoard[MathGameY1][MathGameX1] = monster[0]->getIcon();

		//Update the MathGame information
		Position m2 = monster[1]->getPos();
		int MathGameX2 = m2.x;
		int MathGameY2 = m2.y;
		drawBoard[MathGameY2][MathGameX2] = monster[1]->getIcon();

		//Update the MathGame information
		Position m3 = monster[2]->getPos();
		int MathGameX3 = m3.x;
		int MathGameY3 = m3.y;
		drawBoard[MathGameY3][MathGameX3] = monster[2]->getIcon();

		//Update the VocabularyGame information
		Position v1 = monster[3]->getPos();
		int VocabularyGameX1 = v1.x;
		int VocabularyGameY1 = v1.y;
		drawBoard[VocabularyGameY1][VocabularyGameX1] = monster[3]->getIcon();

		//Update the VocabularyGame information
		Position v2 = monster[4]->getPos();
		int VocabularyGameX2 = v2.x;
		int VocabularyGameY2 = v2.y;
		drawBoard[VocabularyGameY2][VocabularyGameX2] = monster[4]->getIcon();

		//Update the Kill information
		Position k1 = monster[5]->getPos();
		int KillX1 = k1.x;
		int KillY1 = k1.y;
		drawBoard[KillY1][KillX1] = monster[5]->getIcon();

		//Update the Kill information
		Position k2 = monster[6]->getPos();
		int KillX2 = k2.x;
		int KillY2 = k2.y;
		drawBoard[KillY2][KillX2] = monster[6]->getIcon();

		//Update the Pig information
		Position p1 = monster[7]->getPos();
		int PigX1 = p1.x;
		int PigY1 = p1.y;
		drawBoard[PigY1][PigX1] = monster[7]->getIcon();

		//Update the Pig information
		Position p2 = monster[8]->getPos();
		int PigY2 = p2.y;
		int PigX2 = p2.x;
		drawBoard[PigY2][PigX2] = monster[8]->getIcon();

		//Update the Pig information
		Position p3 = monster[9]->getPos();
		int PigY3 = p3.y;
		int PigX3 = p3.x;
		drawBoard[PigY3][PigX3] = monster[9]->getIcon();

		//Update the ShowExit Trigger information
		Position t1 = item[0]->getPos();
		int ShowExitTriggerX1 = t1.x;
		int ShowExitTriggerY1 = t1.y;
		drawBoard[ShowExitTriggerY1][ShowExitTriggerX1] = item[0]->getIcon();

		//Update the ViewAdd Trigger information
		Position t2 = item[1]->getPos();
		int ViewAddX1 = t2.x;
		int ViewAddY1 = t2.y;
		drawBoard[ViewAddY1][ViewAddX1] = item[1]->getIcon();
	};

	//Update the End information
	Position t3 = item[2]->getPos();
	int EndX1 = t3.x;
	int EndY1 = t3.y;
	drawBoard[EndY1][EndX1] = item[2]->getIcon();


	// Update the hero information
	Position h = gHero.getPos();
	int HeroX = h.x;
	int HeroY = h.y;
	drawBoard[HeroY][HeroX] = gHero.getIcon();

	// Draw the board
	for (int BoardY = 0; BoardY < GHEIGHT; BoardY++) {
		for (int BoardX = 0; BoardX < GWIDTH; BoardX++) {
			// 判斷是否在英雄旁邊 
			if (heroViewControl(BoardY, BoardX) )
			{
				// 淹水後的顯示 淹水且已填充
				if (Flooded && (drawBoard[BoardY][BoardX]=="Ｘ"))
				{
					viewer.setColor(153);
					cout << drawBoard[BoardY][BoardX]; //  output
					viewer.setColor();
				}
				else
				{
					cout << drawBoard[BoardY][BoardX]; //  output
				}
			}
			else
			{
				cout << "  "; //  output
			}
		}
		cout << "\n";
	}

}

//******************************************************************
//
// * Output Stroy
//==================================================================
void drawStory(void)
//==================================================================
{
	std::cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
	std::cout << "1. 找到洞穴裡的的石碑。\n2. 將上面寫的字記下來，告訴頭目。\n3. 開始探險吧，請輸入WASD移動。" << "\n";
	std::cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
}

//******************************************************************
//
// * Output information
//==================================================================
void drawInfo(void)
//==================================================================
{
	std::cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
	std::cout << "The hero HP " << gHero.getHealth() << '\n';
	std::cout << "Press ESC key to exit\n";
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
	
	// 是否有input
	bool hasInput = false;

	/* 出現任何不合法的輸入時，輸出 ”invalid input”(0.5%) */
	try {
		// 當還沒有走到終點1
		if (!Flooded)
		{
			if (key[ValidInput::EW])
			{
				gHero.move(0, -1);
				hasInput = true;
			}
			else if (key[ValidInput::ES])
			{
				gHero.move(0, 1);
				hasInput = true;
			}
			else if (key[ValidInput::EA])
			{
				gHero.move(-1, 0);
				hasInput = true;
			}
			else if (key[ValidInput::ED])
			{
				gHero.move(1, 0);
				hasInput = true;
			}
		}
		else //當走到終點1 方向鍵方反
		{
			if (key[ValidInput::EW])
			{
				gHero.move(0, 1);
				hasInput = true;
			}
			else if (key[ValidInput::ES])
			{
				gHero.move(0, -1);
				hasInput = true;
			}
			else if (key[ValidInput::EA])
			{
				gHero.move(1, 0);
				hasInput = true;
			}
			else if (key[ValidInput::ED])
			{
				gHero.move(-1, 0);
				hasInput = true;
			}

			// 淹水後計算步數
			if (hasInput)countStep++;
		}
	}catch (const char* msg) 
	{

	}

	// 判斷輸入是正確的才做顯示更新
	if (hasInput)
	{
		// 清除版面
		viewer.clr();
		
		//淹水後 只有出口有效 其他功能無效化
		if (Flooded)
		{
			item[2]->update(gHero); // Trigger ShowExit
		}
		else
		{
			int monsterSize = monster.size();
			for (int i = 0; i < monsterSize; i++)
			{
				monster[i]->update(gHero);
			}

			int triggerSize = item.size();
			for (int i = 0; i < triggerSize; i++)
			{
				item[i]->update(gHero); // Trigger ShowExit
			}
		}
		// 防止繪圖重複
		if (gHero.getLive() && (!GameLose) && (!GameWin))
		{
			drawStory();
			draw();
			drawInfo();
		}
	}
	
	// 當血量為0
	if (gHero.getHealth() <= 0)
	{
		GameLose =  true;
	}
}
