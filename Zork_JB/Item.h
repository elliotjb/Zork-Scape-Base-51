#ifndef _ITEM_
#define _ITEM_
#include "Entity.h"

class Item : public Entity{

public:


	Item(const char* str1, const char* str2, TYPE type, Room* link, bool istatus, bool object, bool equiped, bool isinside, int hp, int attack, int durability);
	~Item();

	TYPE type;
	Room* link;
	bool istatus;
	bool object;
	bool equiped;
	bool isinside;
	int hp;
	int attack;
	int durability; //With comand PUT [item] into/from [item]


};

#endif //_ITEM_