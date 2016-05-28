#ifndef __World__
#define __World__

#include <stdio.h>
#include <stdlib.h>
#include "Room.h"
#include "player.h"
#include "Door.h"
#include "Exits.h"
#include "Entity.h"
#include "Vector.h"
#include "Criature.h"
#include "Item.h"
#include "Alien.h"
#include "String_Class.h"

#define NUM_ITEMS 18
#define NUM_DOORS 10

/*class Entity;
class Exits;
class Room;
class Door;
class Item;*/

class World
{

public:

	//Vector <Room*> rooms;
	//Vector <Player*> player;
	/*Vector <Exits*> exit;
	Vector <Item*> item;*/

	Vector <Entity*> my_entities;
	Vector <Door*> door;

	Item* inventory = nullptr;
	ClString comand;
	char option[80];
	Player* player = nullptr;
	Alien* alien = nullptr;
	int acon_moviment = 0;

public:

	World();
	~World();

	int quit = 0, cont = 0;
	bool combat = false;
	bool respawn = false;
	bool canmove = false;
	bool alien_dead = false;
	bool stop = false;
	void Create_World();

	//fucntions to put comands
	void Set_Command();

	void Input();

	//Function to exit the game
	bool Exit_zork();


	
};

extern World* App;


#endif 