#ifndef _ITEM_
#define _ITEM_
#include "Entity.h"

class Item : public Entity{

public:


	Item(const char* str1, const char* str2, Room* link, bool istatus);
	virtual ~Item();

	Room* link;
	bool istatus;
	int position_item;

	//Item_Status: 0->room  1->into inventory  2-> equiped  
	int item_status[15];


};

#endif //_ITEM_