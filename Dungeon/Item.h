#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "Hero.h"
using namespace std;

//************************************************************
// Item Class
//************************************************************
class Item 
{
public:
	Position	sPos;			// Hero location
	string sIcon = "вт";	// Hero icon

public:
	// Default constructor
	Item(void) 
	{
		this->sPos.x = 6;
		this->sPos.y = 7;
		this->sIcon = "вт";
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }

	// Set position
	void setPos(int x, int y) 
	{
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	string getIcon(void) { return this->sIcon; }

	virtual void update(Hero& h) 
	{
		if (this->sPos.x == h.getPos().x && this->sPos.y == h.getPos().y) 
		{

		}
	}

};

