#pragma once
#pragma once
#include <string>
#include "main.h"
#include "Viwer.h"
#include "Creature.h"
class Kill : public Creature /* 繼承Creature的public*/
{
public:
	
	Kill() 
	{
		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = "Ｋ";
	}

	Kill(int y, int x)
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = "Ｋ";
	};

	void update(Hero& hero)
	{
		Position h = hero.getPos();
		if ((h.x == this->sPos.x) && (h.y == this->sPos.y))
		{
			Viewer viewer;
			
			//顯示黑人問號
			viewer.showQuestionMark();

			//將英雄殺死 (特殊判定)
			GameLose = true;
			GameWin = true;
		}
	}
};
