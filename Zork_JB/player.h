#ifndef _Player_
#define _Player_

#include "Entity.h"
#include "Room.h"

class Player
{
public:

	Room* position;

	int hp = 0;
	int attack = 0;

};

#endif

