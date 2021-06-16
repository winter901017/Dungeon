#pragma once
#include <string>
#include "Position.h"
#include "main.h"
#include "Creature.h"

class MathGame : public Creature /* 繼承Creature的public*/
{
public:

   /*	Operator ASCII
	*	+		43
	*	-		45
	*	*		42
	*	/		47
	*	=		61
	*/
	char arrySign[5] = { '+', '-', '*', '/', '=' };
	int intSign;
	//	store number info
	int intA, intB;
	double long answer;
	bool pressed = false;
	string story = "<M算術題>\n\n"
		"發現這裡有一張地圖，可以精準的指出石碑的位置!!!\n"
		"上面有好幾行算式，算對了可以減少許多探路的時間，遇到除法算到小數第二位即可。\n\n"
		"勇士：但是部落中沒有在算數學的啦，安捏你要我怎麼辦，\n"
		"只好硬的頭皮上了。";

	MathGame() 
	{
		//	init value
		intSign = 0;
		intA = 0;
		intB = 0;
		answer = 0;

		//	get rand seed
		srand(time(NULL));

		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = "Ｍ";
	}

	MathGame(int y, int x)
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = "Ｍ";
	};

	/* want to get next question, and get rand() to assign all parameter
	*
	*	A		LHS的被 O數
	*	B		LHS的 O數
	*	sign	LHS運算符號
	*	ans		RHS的答案
	*/
	//void newQuest(int A, int B, char sign, int& ans) {
	void newQuest() 
	{
		//	use for division get 0.0x
		double tmp = 0;

		intA = rand() % 100;
		intB = rand() % 100;

		intSign = rand() % 4;

		//	compute the question ANSWER
		switch (intSign) 
		{
		case 0:
			//	PLUS +
			answer = intA + intB;
			break;
		case 1:
			//	MINUS -
			answer = intA - intB;
			break;
		case 2:
			//	STAR *
			answer = intA * intB;
			break;
		case 3:
			//	SLASH 
			if (intB == 0) 
			{	//	處理 除數不為 0
				intB = 1;
			}
			//	取小數後第二位
			tmp = floor(intA / double(intB) * 100) / 100;
			answer = tmp;
			break;
		default:
			break;
		}

	}

	double getAns() 
	{
		return answer;
	}

	bool checkAns(double long ans) 
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

	friend ostream& operator<<(ostream& output, MathGame maG) 
	{
		//output << maG.intA << " " << maG.arrySign[maG.intSign] << " " << maG.intB << " = " << maG.answer;
		output << maG.intA << " " << maG.arrySign[maG.intSign] << " " << maG.intB << " = ";
		return output;
	}

	void update(Hero& hero)
	{
		bool winGame = true;

		Position h = hero.getPos();
		if ((h.x == this->sPos.x) && (h.y == this->sPos.y) && (!this->pressed))
		{
			system("cls");
			Sleep(100);

			//	印出劇情
			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
			cout << story << endl;
			cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";

			this->newQuest();

			/*	輸入答案，需是double，cin >> double type !!	*/
			double a;

			//	進行四次回遊戲
			for (int i = 0; i < 4; i++)
			{
				/*	印出題目	*/
				cout << *this;

				cin >> a;
				/*	檢查答案	*/
				if (this->checkAns(a))
				{
					cout << "->Yes!" << endl;
				}
				else
				{
					cout << "->No..." << endl;
					/*	印出答案	*/
					cout << "Answer is : " << this->getAns() << endl;
					/* 扣英雄的血量 */
					hero.damage(2);
					winGame = false;
				}
				this->newQuest();
			}

			if (winGame)
			{
				system("cls");
				cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
				cout << "你現在的位置 (" << h.x << ", " << h.y <<")"<< endl;
				cout << "石碑的位置 (" << 1 << ", " << 12 <<")"<< endl;
				cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
				
			}
			else {
				system("cls");
				cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
				cout << "你現在的位置 (" << h.x << ", " << h.y << ")" << endl;
				cout << "石碑的位置 (" << rand()%20 << ", " << rand() % 20 << ")" << endl;
				cout << "－－－－－－－－－－－－－－－－－－－－－" << "\n";
			}
			
			system("pause");

			Sleep(1000);
			system("cls");

			pressed = true;
			this->sIcon = "  ";
		}
	}
};
