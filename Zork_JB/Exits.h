#ifndef __Exits_H_
#define __Exits_H_

#include "Entity.h"
#include "Room.h"

class Exits : public Entity
{
public:
	Exits(const char* str1, const char* str2, TYPE type, bool discover, Room* origin, Room* destination, int direction);
	~Exits();

	TYPE type;
	bool discover;
	Room* origin;
	Room* destination;
	int direction;

};

#endif 