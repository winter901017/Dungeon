#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"
#include "Item.h"

//************************************************************
// AddHp Class
//************************************************************
/* 建立Item Class並在底下繼承帶不同特性的不同Item (0.3%) */
class ShowExit :public Item
{

public:
	bool pressed = false;
	// Default constructor
	ShowExit(void) 
	{
		this->sPos.x = 2;
		this->sPos.y = 3;
		this->sIcon = "Ｔ";
	};

	// Setting constructor
	ShowExit(int x, int y, string icon = "Ｔ") 
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};

	// Setting constructor
	ShowExit(Position& pos, string icon = "Ｔ") 
	{
		this->sPos = pos;
		this->sIcon = icon;
	};

	// 判斷是否有踩到 踩到則顯示終點
	void update(Hero &h) 
	{
		// 當Hero踩到Trigger的時候 顯示
		if ((this->sPos.x == h.getPos().x && this->sPos.y == h.getPos().y) && (!pressed)) 
		{
			Viewer viewer;
			viewer.showTips();
			pressed = true;
			sIcon = "  ";
			h.setShowExit(true);
		}
		else
		{
			h.setShowExit(false);
		}
	}
};

