#pragma once
#include <string>
#include "Position.h"
#include "main.h"
#include "Creature.h"

class MathGame : public Creature /* �~��Creature��public*/
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
	string story = "<M��N�D>\n\n"
		"�o�{�o�̦��@�i�a�ϡA�i�H��Ǫ����X�۸O����m!!!\n"
		"�W�����n�X��⦡�A���F�i�H��ֳ\�h�������ɶ��A�J�찣�k���p�ƲĤG��Y�i�C\n\n"
		"�i�h�G���O�������S���b��ƾǪ��աA�w���A�n�ګ���A\n"
		"�u�n�w���Y�֤W�F�C";

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
		this->sIcon = "��";
	}

	MathGame(int y, int x)
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = "��";
	};

	/* want to get next question, and get rand() to assign all parameter
	*
	*	A		LHS���Q O��
	*	B		LHS�� O��
	*	sign	LHS�B��Ÿ�
	*	ans		RHS������
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
			{	//	�B�z ���Ƥ��� 0
				intB = 1;
			}
			//	���p�ƫ�ĤG��
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

			//	�L�X�@��
			cout << "�СССССССССССССССССССС�" << "\n";
			cout << story << endl;
			cout << "�СССССССССССССССССССС�" << "\n";

			this->newQuest();

			/*	��J���סA�ݬOdouble�Acin >> double type !!	*/
			double a;

			//	�i��|���^�C��
			for (int i = 0; i < 4; i++)
			{
				/*	�L�X�D��	*/
				cout << *this;

				cin >> a;
				/*	�ˬd����	*/
				if (this->checkAns(a))
				{
					cout << "->Yes!" << endl;
				}
				else
				{
					cout << "->No..." << endl;
					/*	�L�X����	*/
					cout << "Answer is : " << this->getAns() << endl;
					/* ���^������q */
					hero.damage(2);
					winGame = false;
				}
				this->newQuest();
			}

			if (winGame)
			{
				system("cls");
				cout << "�СССССССССССССССССССС�" << "\n";
				cout << "�A�{�b����m (" << h.x << ", " << h.y <<")"<< endl;
				cout << "�۸O����m (" << 1 << ", " << 12 <<")"<< endl;
				cout << "�СССССССССССССССССССС�" << "\n";
				
			}
			else {
				system("cls");
				cout << "�СССССССССССССССССССС�" << "\n";
				cout << "�A�{�b����m (" << h.x << ", " << h.y << ")" << endl;
				cout << "�۸O����m (" << rand()%20 << ", " << rand() % 20 << ")" << endl;
				cout << "�СССССССССССССССССССС�" << "\n";
			}
			
			system("pause");

			Sleep(1000);
			system("cls");

			pressed = true;
			this->sIcon = "  ";
		}
	}
};
