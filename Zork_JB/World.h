#ifndef __World__
#define __World__

#include "Room.h"
#include "player.h"
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

class World{
public:
	Room* rooms = nullptr;
	Player* player = nullptr;
	Exits* exit = nullptr;

	World();
	~World();
	void Create_World();
	int num_room;
};




#endif 