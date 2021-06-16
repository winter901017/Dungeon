#pragma once
#include <string>
#include "Position.h"
#include "main.h"
#include "Object.h"
#include "Hero.h"
class Creature: public Object 
{ 
public:
	// Default constructor
	Creature(void) 
	{
		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = "ขั";
	};

	virtual void update(Hero &h) 
	{
		
	}
};