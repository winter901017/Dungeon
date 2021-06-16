#pragma once
#pragma once
#include <string>
#include "main.h"
#include "Viwer.h"
#include "Creature.h"
class Kill : public Creature /* �~��Creature��public*/
{
public:
	
	Kill() 
	{
		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = "��";
	}

	Kill(int y, int x)
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = "��";
	};

	void update(Hero& hero)
	{
		Position h = hero.getPos();
		if ((h.x == this->sPos.x) && (h.y == this->sPos.y))
		{
			Viewer viewer;
			
			//��ܶ¤H�ݸ�
			viewer.showQuestionMark();

			//�N�^������ (�S��P�w)
			GameLose = true;
			GameWin = true;
		}
	}
};
