#pragma once

#include <string>
#include <iostream>
#include "Position.h"

/* 所需重複使用的物件 */
class Object
{
public:
	Position	sPos;		/* 位置 */
	string sIcon = "C ";		/* 圖式 */

public:
	/* 設置positon位置 */
	void setPos(Position pos) 
	{ 
		this->sPos = pos; 
	}
	/* 設置int位置 x y */
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	/* 設置char圖式 */
	void setIcon(char& icon) { this->sIcon = icon; }

	/* 取得positon位置 */
	Position getPos(void) { return this->sPos; }

	/* 取得char圖式 */
	string getIcon(void) { return this->sIcon; }
};