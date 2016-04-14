#ifndef _ITEM_
#define _ITEM_
#include "Entity.h"

class Item : public Entity{

public:


	Item(const char* str1, const char* str2, Room* link, bool istatus);
	virtual ~Item();

	Room* link;
	bool istatus;



};

#endif //_ITEM_