#ifndef _ITEM_
#define _ITEM_

#include "Entity.h"

class Item : public Entity
{

public:


	Item(const char* str1, const char* str2, Room* link, bool istatus, bool object, bool equiped, bool isinside, int hp, int attack, int durability, int price);
	~Item();

	Room* link;
	bool istatus;//In your inventory
	bool object;
	bool equiped;
	bool isinside;
	int hp;
	int attack;
	int durability; //With comand PUT [item] into/from [item]
	int price;


};

#endif //_ITEM_