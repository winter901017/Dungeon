#include <string>
#include "main.h"
#include "Viwer.h"
#include "Creature.h"
class Reverse : public Creature /* �~��Creature��public*/
{
public:



	Reverse() {

		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = "��";
	}

	Reverse(int y, int x)
	{
		this->sPos.x = x;
		this->sPos.y = y;
		this->sIcon = "��";
	};

	void update(Hero& hero)
	{

	}
};
