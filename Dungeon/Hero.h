#pragma once
#include <string>
#include "Position.h"
#include "main.h"
//************************************************************
// Hero Class, only has requirement part for example
//************************************************************

#include<exception>
using std::exception;
using namespace std;
class Hero {

private:
	Position	sPos;			// Hero location
	string sIcon = "Ｈ";	// Hero icon
	bool		showExit = false;
	bool		live = true;
	int			health = 10;	// health of hero
	int			heroCanSeeView = 1;

public:
	// Default constructor
	Hero() 
	{
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sIcon = "Ｈ";
		this->showExit = false;
	};
	// Setting constructor
	Hero(int x, int y, int level = 1, string icon = "Ｈ") 
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = icon;
		this->showExit = false;
	};

	// Setting constructor
	Hero(Position& pos, int level = 1, string icon = "Ｈ") 
	{
		this->sPos = pos;
		this->sIcon = icon;
		this->showExit = false;
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	//Set hp
	void setHp(int hp) { this->health = hp; }

	// Set showExit
	void setShowExit(bool show) { this->showExit = show; }

	// Set showExit
	void setLive(bool exist) { this->live = exist; }

	// Set showExit
	void setHeroCanSeeView(int view) { this->heroCanSeeView = view; }
	
	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	string getIcon(void) { return this->sIcon; }

	//Get hp
	int setHp(void) { return this->health; }

	// Get Health
	int getHealth(void) { return this->health; }

	// Get showExit
	int getShowExit(void) { return this->showExit; }

	// Get live
	bool getLive(void) { return this->live; }

	// Get HeroCanSeeView
	int getHeroCanSeeView(void) { return this->heroCanSeeView; }

	// Incrementally move the elements 
	bool move(int x, int y) 
	{
		// Compute the next position
		Position next;
		next.x = this->sPos.x + x;
		next.y = this->sPos.y + y;

		/* 當使用者試圖往牆走時輸出 ”Invalid location”(0.5%) */
		try 
		{
			if (isPositionValid(next))
				this->sPos = next;
			else 
			{
				throw "Invalid location";
			}
		}
		catch (const char* msg) 
		{
		}

	}

	// 英雄受到多少傷害
	void damage(int points) 
	{
		this->health -= points;
	}
};
