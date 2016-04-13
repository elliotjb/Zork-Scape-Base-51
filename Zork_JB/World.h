#ifndef __World__
#define __World__

#include "Room.h"
#include "Player.h"
#include "Vector.h"
#include <string.h>


class Exits;
class Room;
class Player;
class Door;
class Item;

class World{

public:

	Vector <Room*> rooms;
	Vector <Player*> player;
	Vector <Exits*> exit;
	Vector <Door*> door;
	Vector <Item*> item;

	Vector <Entity*> my_entities;

	//ClString* comand = nullptr;
	char* comand = nullptr;

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


};




#endif 