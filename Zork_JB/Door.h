#ifndef _Door_
#define _Door_

#include "Room.h"

using namespace std;

class Door{

public:
	Door(bool isOP, Room* door_origin, Room* door_dst);
	~Door();
	bool isOP;
	Room* door_origin;
	Room* door_dst;

};

#endif 