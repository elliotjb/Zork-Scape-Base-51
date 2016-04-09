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
	void Set_Command();

	//Funciton to go n, go w, go s and go e
	void Move();

	void Look_position() const;

	void Open_Door_North();
	void Open_Door_West();
	void Open_Door_South();
	void Open_Door_East();

	void Close_Door_North();
	void Close_Door_West();
	void Close_Door_South();
	void Close_Door_East();

	void Look_Specify_position_North() const;
	void Look_Specify_position_West() const;
	void Look_Specify_position_South()const;
	void Look_Specify_position_East()const;

	bool Exit_zork();

};




#endif 