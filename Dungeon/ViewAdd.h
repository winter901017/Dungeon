#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"
#include "Item.h"

class ViewAdd :public Item
{
	
public:

	bool pressed = false;

	// Default constructor
	ViewAdd(void) 
	{
		this->sPos.x = 2;
		this->sPos.y = 3;
		this->sIcon = "��";
	};

	// Setting constructor
	ViewAdd(int x, int y, string icon = "��") 
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};

	// Setting constructor
	ViewAdd(Position& pos, string icon = "��") 
	{
		this->sPos = pos;
		this->sIcon = icon;
	};

	// �P�_�O�_����� ���h��ܲ��I
	void update(Hero& h) 
	{

		// ��Hero���Trigger���ɭ� ���
		if ((this->sPos.x == h.getPos().x && this->sPos.y == h.getPos().y)&& (!pressed))
		{
			Sleep(100);
			h.setHeroCanSeeView(h.getHeroCanSeeView() + 1);

			this->sIcon = "  ";
			pressed = true;
		}
	}
};

