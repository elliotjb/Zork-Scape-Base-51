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
	ClString comand;
	char* option = nullptr;
	Player* player = nullptr;


public:

	World();
	~World();

	int quit = 0, cont = 0;

	void Create_World();

	//fucntions to put comands
	void Set_Command();

	void Input();

	//Funciton to go n, go w, go s and go e
	void Move();
	//void Move(Vector<ClString>&);

	//Function to open
	void Open();

	//Function to close
	void Close();
	
	//Function to Look Room
	void Look() const;

	//function to look inventory
	void Look_inventory() const;

	//function to look item
	void Look_item(Vector<ClString> &) const;

	//Function to Look specify position (North, West, South and East)
	void Look_Specify_Position() const;
	
	//Function to exit the game
	bool Exit_zork();

	//Function to pick a item
	void Pick_item(Vector<ClString> &);

	//Function to drop a item
	void Drop_item(Vector<ClString> &);

	//Function to equip a item
	void Equip(Vector<ClString> &);

	//Function to unequip a item
	void UnEquip(Vector<ClString> &);

	//function to look your stats
	void Stats()const;
};




#endif 