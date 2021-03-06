#ifndef __Exits_H_
#define __Exits_H_

#include "Entity.h"
#include "Room.h"

class Exits : public Entity
{
public:
	Exits(const char* str1, const char* str2, Room* origin, Room* destination, int direction);
	~Exits();

	Room* origin;
	Room* destination;
	int direction;
	//0 -> NORTH ->up
	//1 -> WEST  ->left
	//2 -> SOUTH ->down
	//3 -> EAST  ->right

};

#endif 