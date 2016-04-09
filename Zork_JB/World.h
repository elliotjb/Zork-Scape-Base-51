#ifndef __World__
#define __World__

#include "Room.h"
#include "player.h"
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
class Exits;
class Room;
class Player;
class Door;

class World{
public:
	Room* rooms = nullptr;
	Player* player = nullptr;
	Exits* exit = nullptr;
	Door* door = nullptr;

	char* comand = nullptr;
	//ClString* comand = nullptr;

	World();
	~World();

	int quit = 0, cont = 0;

	void Create_World();

	//fucntions to put comands
	void Set_Command();

	//Funciton to go n, go w, go s and go e
	void Move();

	//Function to open
	void Open();

	//Function to close
	void Close();

	//Function to Look Room
	void Look() const;

	//Function to Look specify position (North, West, South and East)
	void Look_Specify_Position() const;

	//Function to exit the game
	bool Exit_zork();

};




#endif 