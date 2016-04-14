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
#include "Item.h"
#include "String_Class.h"
#include <string.h>

class Entity;
class Exits;
class Room;
class Door;
class Item;

class World:public Entity
{

public:

	Vector <Room*> rooms;
	//Vector <Player*> player;

	Vector <Exits*> exit;
	Vector <Door*> door;
	Vector <Item*> item;

	//Vector<ClString> option; //for items?

	Vector <Entity*> my_entities;

	Item* inventory = nullptr;
	ClString* comand;
	char comands[40];
	Player* player = nullptr;


public:

	World();
	~World();

	int quit = 0, cont = 0;

	void Create_World();

	//fucntions to put comands
	void Set_Command();

	//Funciton to go n, go w, go s and go e
	void Move();

	//Function to open
	/*void Open();

	//Function to close
	void Close();
	*/
	//Function to Look Room
	void Look() const;
	/*
	//Function to Look specify position (North, West, South and East)
	void Look_Specify_Position() const;
	*/
	//Function to exit the game
	bool Exit_zork();

	//Function to pick a item
	//void Pick_item(const ClString&);

	//Function to drop a item
	//void Drop_item(const ClString&);

};




#endif 