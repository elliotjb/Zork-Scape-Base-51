#include "World.h"
#include "Room.h"
#include "player.h"
#include "Exits.h"
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS


World::World(){
	rooms = new Room[13];
	player = new Player[1];
	exit = new Exits[13];

}
World::~World(){
	delete[]rooms;
	delete[]player;
	delete[]exit;
}


void World::Create_World(){

	//Create Player
	strcpy_s(player[0].name, "Player");
	strcpy_s(player[0].descrption, "You have 20 years.");
	player[0].position = 0; //Position start-> Main Room.


	//Create Rooms
	strcpy_s(rooms[0].name, "You are stay in the Main Room.\n");
	strcpy_s(rooms[0].description, "This room is very dark but there is a light above is enough to see everything. \nThere is only one door and the north.\n");

	strcpy_s(rooms[1].name, "You are stay in the Aisle.\n");
	strcpy_s(rooms[1].description, "es 1");

	strcpy_s(rooms[2].name, "You are stay in the Dressing Room.\n");
	strcpy_s(rooms[2].description, "es 2");

	strcpy_s(rooms[3].name, "You are stay in the Office Room.\n");
	strcpy_s(rooms[3].description, "es 3");

	strcpy_s(rooms[4].name, "You are stay in the Mysteri Room.\n");
	strcpy_s(rooms[4].description, "es 4");

	strcpy_s(rooms[5].name, "You are stay in the Warehouse.\n");
	strcpy_s(rooms[5].description, "es 5");

	strcpy_s(rooms[6].name, "You are stay in the Warehouse II.\n");
	strcpy_s(rooms[6].description, "es 6");

	strcpy_s(rooms[7].name, "You are stay in the Gunsmith.\n");
	strcpy_s(rooms[7].description, "es 7");

	strcpy_s(rooms[8].name, "You are stay in the Aisle.\n");
	strcpy_s(rooms[8].description, "es 8");

	strcpy_s(rooms[9].name, "You are stay in the Hall.\n");
	strcpy_s(rooms[9].description, "es 9");

	strcpy_s(rooms[10].name, "You are stay in the Exit.\n");
	strcpy_s(rooms[10].description, "es 10");

	strcpy_s(rooms[11].name, "You are stay in the Aisle.\n");
	strcpy_s(rooms[11].description, "es 11");

	strcpy_s(rooms[12].name, "You are stay in the Laboratory.\n");
	strcpy_s(rooms[12].description, "es 12");

	

	//Create Exits
	strcpy_s(exit[0].description, "Around Here is the Main Room.\n");
	strcpy_s(exit[1].description, "Around Here is the Aisle.\n");
	strcpy_s(exit[2].description, "Around Here is the Dressing Room.\n");
	strcpy_s(exit[3].description, "Around Here is the Office Room.\n");
	strcpy_s(exit[4].description, "Around Here is the Alien Spawn.\n");
	strcpy_s(exit[5].description, "Around Here is the Warehouse.\n");
	strcpy_s(exit[6].description, "Around Here is the Warehouse.\n");
	strcpy_s(exit[7].description, "Around Here is the Gunsmith.\n");
	strcpy_s(exit[8].description, "Around Here is the Ailse.\n");
	strcpy_s(exit[9].description, "Around Here is the Hall.\n");
	strcpy_s(exit[10].description, "Around Here is the Exit.\n");
	strcpy_s(exit[11].description, "Around Here is the Ailse.\n");
	strcpy_s(exit[12].description, "Around Here is the Laboratory.\n");

	//Create Exits dst.
	exit[0].dst_N = 1;

	exit[1].dst_N = 2;
	exit[1].dst_E = 8;
	exit[1].dst_S = 0;
	exit[1].dst_W = 3;

	exit[2].dst_S = 1;

	exit[3].dst_W = 4;
	exit[3].dst_S = 6;
	exit[3].dst_E = 1;

	exit[4].dst_N = 5;
	exit[4].dst_E = 3;

	exit[5].dst_S = 4;

	exit[6].dst_N = 3;
	exit[6].dst_W = 7;

	exit[7].dst_E = 6;

	exit[8].dst_N = 11;
	exit[8].dst_W = 1;
	exit[8].dst_S = 9;

	exit[9].dst_N = 8;
	exit[9].dst_E = 10;

	exit[10].dst_W = 9;

	exit[11].dst_N = 8;
	exit[11].dst_W = 12;

	exit[12].dst_E = 11;


}






