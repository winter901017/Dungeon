#include <string>
#include "main.h"
#include "Viwer.h"
#include "Creature.h"
class Reverse : public Creature /* Ä~©ÓCreatureªºpublic*/
{
public:



	Reverse() {

		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = "¢à";
	}

	Reverse(int y, int x)
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = "¢à";
	};

	void update(Hero& hero)
	{

	}
};
