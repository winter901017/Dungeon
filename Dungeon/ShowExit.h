#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"
#include "Item.h"

//************************************************************
// AddHp Class
//************************************************************
/* �إ�Item Class�æb���U�~�ӱa���P�S�ʪ����PItem (0.3%) */
class ShowExit :public Item
{

public:
	bool pressed = false;
	// Default constructor
	ShowExit(void) 
	{
		this->sPos.x = 2;
		this->sPos.y = 3;
		this->sIcon = "��";
	};

	// Setting constructor
	ShowExit(int x, int y, string icon = "��") 
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
	};

	// Setting constructor
	ShowExit(Position& pos, string icon = "��") 
	{
		this->sPos = pos;
		this->sIcon = icon;
	};

	// �P�_�O�_����� ���h��ܲ��I
	void update(Hero &h) 
	{
		// ��Hero���Trigger���ɭ� ���
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

