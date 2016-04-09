#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "String_Class.h"

class World;
class Exits;
class Player;
class Room;
class Door;

class Entity
{
public:

	World* world;
	Exits* exits;
	Player* player;
	Room* room;
	Door* door;
	ClString comands;

public:

	Entity();
	~Entity();

};

// Global var made extern for Application ---
extern Entity* App;

#endif // __APPLICATION_H__