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

	MathGame() {
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
	void newQuest() {
		//	use for division get 0.0x
		double tmp = 0;

		intA = rand() % 100;
		intB = rand() % 100;

		intSign = rand() % 4;

		//	compute the question ANSWER
		switch (intSign) {
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
			if (intB == 0) {	//	處理 除數不為 0
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

	double getAns() {
		return answer;
	}

	bool checkAns(double long ans) {
		if (answer == ans)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend ostream& operator<<(ostream& output, MathGame maG) {
		//output << maG.intA << " " << maG.arrySign[maG.intSign] << " " << maG.intB << " = " << maG.answer;
		output << maG.intA << " " << maG.arrySign[maG.intSign] << " " << maG.intB << " = ";
		return output;
	}

	void update(Hero& hero)
	{
		Position h = hero.getPos();
		if ((h.x == this->sPos.x) && (h.y == this->sPos.y) && (!this->pressed))
		{
			system("cls");
			Sleep(100);
			this->newQuest();
			/*	印出題目	*/
			cout << *this << endl;


			/*	輸入答案，需是double，cin >> double type !!	*/
			double a;
			cin >> a;


			/*	檢查答案	*/
			if (this->checkAns(a))
			{
				cout << "Yes!" << endl;
			}
			else
			{
				cout << "No..." << endl;
				/*	印出答案	*/
				cout << "Answer is : " << this->getAns() << endl;
				/* 扣英雄的血量 */
				hero.damage(2);
			}
			Sleep(1000);
			system("cls");

			pressed = true;
			this->sIcon = "  ";
		}
	}
};
