#pragma once

#include <string>
#include <iostream>
#include "Position.h"

/* �һݭ��ƨϥΪ����� */
class Object
{
public:
	Position	sPos;		/* ��m */
	string sIcon = "C ";		/* �Ϧ� */

public:
	/* �]�mpositon��m */
	void setPos(Position pos) 
	{ 
		this->sPos = pos; 
	}
	/* �]�mint��m x y */
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	/* �]�mchar�Ϧ� */
	void setIcon(char& icon) { this->sIcon = icon; }

	/* ���opositon��m */
	Position getPos(void) { return this->sPos; }

	/* ���ochar�Ϧ� */
	string getIcon(void) { return this->sIcon; }
};