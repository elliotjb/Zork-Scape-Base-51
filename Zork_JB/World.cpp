#include "World.h"
#include "Room.h"
#include "player.h"
#include "Door.h"
#include "Exits.h"
#include <string.h>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS


World::World(){
	rooms = new Room[13];
	player = new Player[1];
	exit = new Exits[13];
	door = new Door[5];

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
	strcpy_s(rooms[1].description, "This Aisle is small and it's a dimly lit.\n");

	strcpy_s(rooms[2].name, "You are stay in the Dressing Room.\n");
	strcpy_s(rooms[2].description, "You can see many lockers, and some are open.|nThere is also a window but it is locked with bars.\n");

	strcpy_s(rooms[3].name, "You are stay in the Office Room.\n");
	strcpy_s(rooms[3].description, "It is a large room, you see that this separated workspaces with computers at home space.\n");

	strcpy_s(rooms[4].name, "You are stay in the Mysteri Room.\n");
	strcpy_s(rooms[4].description, "This room is has a gigantic cube in the middle of the room has a door and it seems that this open.\n");

	strcpy_s(rooms[5].name, "You are stay in the Warehouse.\n");
	strcpy_s(rooms[5].description, "There are many shelves.\n");

	strcpy_s(rooms[6].name, "You are stay in the Warehouse II.\n");
	strcpy_s(rooms[6].description, "There are many shelves.\n");

	strcpy_s(rooms[7].name, "You are stay in the Gunsmith.\n");
	strcpy_s(rooms[7].description, "Here are many weapons and lots of ammunition, it could be useful.\n");

	strcpy_s(rooms[8].name, "You are stay in the Aisle.\n");
	strcpy_s(rooms[8].description, "This Aisle is big room.\n");

	strcpy_s(rooms[9].name, "You are stay in the Hall.\n");
	strcpy_s(rooms[9].description, "It is a very large room with plenty of lighting.\n");

	strcpy_s(rooms[10].name, "You are stay in the Exit.\n");
	strcpy_s(rooms[10].description, "This is Exit.\n");

	strcpy_s(rooms[11].name, "You are stay in the Aisle.\n");
	strcpy_s(rooms[11].description, "This Aisle is long.\n");

	strcpy_s(rooms[12].name, "You are stay in the Laboratory.\n");
	strcpy_s(rooms[12].description, "There are many very strange instruments.\n");

	

	//Create Exits
	strcpy_s(exit[0].description, "There is a door.\nBehind the door is the Main Room.\n");
	strcpy_s(exit[1].description, "There is a door.\nBehind the door is the Aisle.\n");
	strcpy_s(exit[2].description, "There is a door.\nBehind the door is the Dressing Room.\n");
	strcpy_s(exit[3].description, "There is a door.\nBehind the door is the Office Room.\n");
	strcpy_s(exit[4].description, "There is a door.\nBehind the door is the Alien Spawn.\n");
	strcpy_s(exit[5].description, "There is a door.\nBehind the door is the Warehouse.\n");
	strcpy_s(exit[6].description, "There is a door.\nBehind the door is the Warehouse.\n");
	strcpy_s(exit[7].description, "There is a door.\nBehind the door is the Gunsmith.\n");
	strcpy_s(exit[8].description, "There is a door.\nBehind the door is the Ailse.\n");
	strcpy_s(exit[9].description, "There is a door.\nBehind the door is the Hall.\n");
	strcpy_s(exit[10].description, "There is a door.\nBehind the door is the Exit.\n");
	strcpy_s(exit[11].description, "There is a door.\nBehind the door is the Ailse.\n");
	strcpy_s(exit[12].description, "There is a door.\nBehind the door is the Laboratory.\n");

	//Create Doors
	door[0].Num_doors = 0;// 0 = Close // 1 = Open
	door[1].Num_doors = 0;
	door[2].Num_doors = 0;
	door[3].Num_doors = 0;
	door[4].Num_doors = 0;
}

void World::Set_Command(){
	char comand[20];
	printf("> ");
	gets_s(comand);

	//Command - Help
	if (strcmp("help", comand) == 0){
		printf("Your commands:\n");
		printf("-[go north] or [go n]\n-[go west] or [go w]\n-[go south] or [go s]\n-[go east] or [go e]\n");
		printf("-[look (the same way as above)]\n");
		printf("-[open door]\n-[close door]\n");
		printf("-[quit]\n-[help]\n");
	}
	//Commands - Go
	if (strcmp("go", comand) == 0){
		printf("Where you want to go? [go north, go west, go south, go east]\n");
	}
	if (strcmp("go north", comand) == 0){
		Move_position_North();
	}
	if (strcmp("go west", comand) == 0){
		Move_position_West();
	}
	if (strcmp("go south", comand) == 0){
		Move_position_South();
	}
	if (strcmp("go east", comand) == 0){
		Move_position_East();
	}
	if (strcmp("go n", comand) == 0){
		Move_position_North();
	}
	if (strcmp("go w", comand) == 0){
		Move_position_West();
	}
	if (strcmp("go s", comand) == 0){
		Move_position_South();
	}
	if (strcmp("go e", comand) == 0){
		Move_position_East();
	}

	if (strcmp("open", comand) == 0){
		printf("The command to open is [open door (direction) -> example: open door north].\n");
	}
	if (strcmp("close", comand) == 0){
		printf("The command to close is [close door (direction) -> example: close door north].\n");
	}
	if (strcmp("open door north", comand) == 0){
		Open_Door_North();
	}
	if (strcmp("open door west", comand) == 0){
		Open_Door_West();
	}
	if (strcmp("open door south", comand) == 0){
		Open_Door_South();
	}
	if (strcmp("open door east", comand) == 0){
		Open_Door_East();
	}
	if (strcmp("close door nort", comand) == 0){
		Close_Door_North();
	}
	if (strcmp("close door west", comand) == 0){
		Close_Door_West();
	}
	if (strcmp("close door south", comand) == 0){
		Close_Door_South();
	}
	if (strcmp("close door east", comand) == 0){
		Close_Door_East();
	}


	//Commands - Look
	if (strcmp("look", comand) == 0){
		Look_position();
		if (cont < 1){
		printf("If you want to specify where to look like this-> [ look north/n, look west/w, look south/s, look east/e ]\n");
		cont++;
		}
	}
	if (strcmp("look north", comand) == 0){
		Look_Specify_position_North();
	}
	if (strcmp("look west", comand) == 0){
		Look_Specify_position_West();
	}
	if (strcmp("look south", comand) == 0){
		Look_Specify_position_South();
	}
	if (strcmp("look east", comand) == 0){
		Look_Specify_position_East();
	}
	if (strcmp("look n", comand) == 0){
		Look_Specify_position_North();
	}
	if (strcmp("look w", comand) == 0){
		Look_Specify_position_West();
	}
	if (strcmp("look s", comand) == 0){
		Look_Specify_position_South();
	}
	if (strcmp("look e", comand) == 0){
		Look_Specify_position_East();
	}

	if (strcmp("quit", comand) == 0){
		quit = 1;
		Exit_zork();
	}

}
void World::Open_Door_North()
{
	if (player[0].position == 1)
	{
		if (door[0].Num_doors == 1){
			printf("The door was already open.\n");
		}
		else{
			door[0].Num_doors = 1;
			printf("The door is already open.\n");
		}

	}
	else if (player[0].position == 4)
	{
		if (door[1].Num_doors == 1){
			printf("The door was already open.\n");
		}
		else{
			door[1].Num_doors = 1;
			printf("The door is already open.\n");
		}
	}
	else{
		printf("In this direction there isn't door.\n");
	}
}
void World::Open_Door_West()
{
	if (player[0].position == 6)
	{
		if (door[2].Num_doors == 1){
			printf("The door was already open.\n");
		}
		else{
			door[2].Num_doors = 1;
			printf("The door is already open.\n");
		}
	}
	else if (player[0].position == 11)
	{
		if (door[4].Num_doors == 1){
			printf("The door was already open.\n");
		}
		else{
			door[4].Num_doors = 1;
			printf("The door is already open.\n");
		}
	}
	else if (player[0].position == 10)
	{
		if (door[3].Num_doors == 1){
			printf("The door was already open.\n");
		}
		else{
			door[3].Num_doors = 1;
			printf("The door is already open.\n");
		}
	}
	else{
		printf("In this direction there isn't door.\n");
	}
}
void World::Open_Door_South()
{
	if (player[0].position == 2)
	{
		if (door[0].Num_doors == 1){
			printf("The door was already open.\n");
		}
		else{
			door[0].Num_doors = 1;
			printf("The door is already open.\n");
		}
	}
	else if (player[0].position == 5)
	{
		if (door[1].Num_doors == 1){
			printf("The door was already open.\n");
		}
		else{
			door[1].Num_doors = 1;
			printf("The door is already open.\n");
		}
	}
	else{
		printf("In this direction there isn't door.\n");
	}
}
void World::Open_Door_East()
{
	if (player[0].position == 7)
	{
		if (door[2].Num_doors == 1){
			printf("The door was already open.\n");
		}
		else{
			door[2].Num_doors = 1;
			printf("The door is already open.\n");
		}
	}
	else if (player[0].position == 9)
	{
		if (door[3].Num_doors == 1){
			printf("The door was already open.\n");
		}
		else{
			door[3].Num_doors = 1;
			printf("The door is already open.\n");
		}
	}
	else if (player[0].position == 12)
	{
		if (door[4].Num_doors == 1){
			printf("The door was already open.\n");
		}
		else{
			door[4].Num_doors = 1;
			printf("The door is already open.\n");
		}
	}
	else{
		printf("In this direction there isn't door.\n");
	}
}

void World::Close_Door_North()
{
	if (player[0].position == 1)
	{
		if (door[0].Num_doors == 0){
			printf("The door was already closed.\n");
		}
		else{
			door[0].Num_doors = 0;
			printf("The door is already close.\n");
		}

	}
	else if (player[0].position == 4)
	{
		if (door[1].Num_doors == 0){
			printf("The door was already closed.\n");
		}
		else{
			door[1].Num_doors = 0;
			printf("The door is already close.\n");
		}
	}
	else{
		printf("In this direction there isn't door.\n");
	}
}

void World::Close_Door_West()
{
	if (player[0].position == 10)
	{
		if (door[3].Num_doors == 0){
			printf("The door was already closed.\n");
		}
		else{
			door[3].Num_doors = 0;
			printf("The door is already close.\n");
		}

	}
	else if (player[0].position == 6)
	{
		if (door[2].Num_doors == 0){
			printf("The door was already closed.\n");
		}
		else{
			door[2].Num_doors = 0;
			printf("The door is already close.\n");
		}
	}
	else if (player[0].position == 11)
	{
		if (door[4].Num_doors == 0){
			printf("The door was already closed.\n");
		}
		else{
			door[4].Num_doors = 0;
			printf("The door is already close.\n");
		}
	}
	else{
		printf("In this direction there isn't door.\n");
	}
}
void World::Close_Door_South()
{
	if (player[0].position == 2)
	{
		if (door[0].Num_doors == 0){
			printf("The door was already closed.\n");
		}
		else{
			door[0].Num_doors = 0;
			printf("The door is already close.\n");
		}

	}
	else if (player[0].position == 5)
	{
		if (door[1].Num_doors == 0){
			printf("The door was already closed.\n");
		}
		else{
			door[1].Num_doors = 0;
			printf("The door is already close.\n");
		}
	}
	else{
		printf("In this direction there isn't door.\n");
	}
}
void World::Close_Door_East()
{
	if (player[0].position == 7)
	{
		if (door[2].Num_doors == 0){
			printf("The door was already closed.\n");
		}
		else{
			door[2].Num_doors = 0;
			printf("The door is already close.\n");
		}

	}
	else if (player[0].position == 12)
	{
		if (door[4].Num_doors == 0){
			printf("The door was already closed.\n");
		}
		else{
			door[4].Num_doors = 0;
			printf("The door is already close.\n");
		}
	}
	else if (player[0].position == 9)
	{
		if (door[3].Num_doors == 0){
			printf("The door was already closed.\n");
		}
		else{
			door[3].Num_doors = 0;
			printf("The door is already close.\n");
		}
	}
	else{
		printf("In this direction there isn't door.\n");
	}
}

void World::Move_position_North()
{

	if (player[0].position == 0)
	{
		printf("\n%s\n", (rooms[1].name));
		printf("%s\n", (rooms[1].description));
		player[0].position = 1;
		return;
	}
	if (player[0].position == 1)
	{
		if (door[0].Num_doors == 1){
			player[0].position = 2;
			printf("\n%s\n", (rooms[2].name));
			printf("%s\n", (rooms[2].description));
			return;
		}
		else{
			printf("You can't move, there is a front door and closed.\n");
		}

	}
	if (player[0].position == 2)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 3)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 4)
	{
		if (door[1].Num_doors == 1){
			player[0].position = 5;
			printf("\n%s\n", (rooms[5].name));
			printf("%s\n", (rooms[5].description));
			return;
		}
		else{
			printf("You can't move, there is a front door and closed.\n");
		}

	}
	if (player[0].position == 5)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 6)
	{
		player[0].position = 3;
		printf("\n%s\n", (rooms[3].name));
		printf("%s\n", (rooms[3].description));
		return;
	}
	if (player[0].position == 7)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 8)
	{
		player[0].position = 11;
		printf("\n%s\n", (rooms[11].name));
		printf("%s\n", (rooms[11].description));
		return;
	}
	if (player[0].position == 9)
	{
		player[0].position = 8;
		printf("\n%s\n", (rooms[8].name));
		printf("%s\n", (rooms[8].description));
		return;
	}
	if (player[0].position == 10)
	{
		printf("This is Exit!\n");
		return;
	}
	if (player[0].position == 11)
	{
		player[0].position = 8;
		printf("\n%s\n", (rooms[8].name));
		printf("%s\n", (rooms[8].description));
		return;
	}
	if (player[0].position == 12)
	{
		printf("There is a wall!.\n");
		return;
	}
}

void World::Move_position_West(){

	if (player[0].position == 0)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 1)
	{
		player[0].position = 3;
		printf("\n%s\n", (rooms[3].name));
		printf("%s\n", (rooms[3].description));
		return;
	}
	if (player[0].position == 2)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 3)
	{
		player[0].position = 4;
		printf("\n%s\n", (rooms[4].name));
		printf("%s\n", (rooms[4].description));
		return;
	}
	if (player[0].position == 4)
	{
		printf("There is a wall.\n");
		return;
	}
	if (player[0].position == 5)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 6)
	{
		if (door[2].Num_doors == 1){
		player[0].position = 7;
		printf("\n%s\n", (rooms[7].name));
		printf("%s\n", (rooms[7].description));
		return;
		}
		else{
			printf("You can't move, there is a front door and closed.\n");
		}

	}
	if (player[0].position == 7)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 8)
	{
		player[0].position = 1;
		printf("\n%s\n", (rooms[1].name));
		printf("%s\n", (rooms[1].description));
		return;
	}
	if (player[0].position == 9)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 10)
	{
		if (door[3].Num_doors == 1){
		player[0].position = 9;
		printf("\n%s\n", (rooms[9].name));
		printf("%s\n", (rooms[9].description));
		return;
		}
		else{
			printf("You can't move, there is a front door and closed.\n");
		}

	}
	if (player[0].position == 11)
	{
		if (door[4].Num_doors == 1){
		player[0].position = 12;
		printf("\n%s\n", (rooms[12].name));
		printf("%s\n", (rooms[12].description));
		return;
		}
		else{
			printf("You can't move, there is a front door and closed.\n");
		}

	}
	if (player[0].position == 12)
	{
		printf("There is a wall!.\n");
		return;
	}
}

void World::Move_position_South(){

	if (player[0].position == 0)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 1)
	{
		player[0].position = 0;
		printf("\n%s\n", (rooms[0].name));
		printf("%s\n", (rooms[0].description));
		return;
	}
	if (player[0].position == 2)
	{
		if (door[0].Num_doors == 1){
		player[0].position = 1;
		printf("\n%s\n", (rooms[1].name));
		printf("%s\n", (rooms[1].description));
		return;
		}
		else{
			printf("You can't move, there is a front door and closed.\n");
		}

	}
	if (player[0].position == 3)
	{
		player[0].position = 6;
		printf("\n%s\n", (rooms[6].name));
		printf("%s\n", (rooms[6].description));
		return;
	}
	if (player[0].position == 4)
	{
		printf("There is a wall.\n");
		return;
	}
	if (player[0].position == 5)
	{
		if (door[1].Num_doors == 1){
		player[0].position = 4;
		printf("\n%s\n", (rooms[4].name));
		printf("%s\n", (rooms[4].description));
		return;
		}
		else{
			printf("You can't move, there is a front door and closed.\n");
		}

	}
	if (player[0].position == 6)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 7)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 8)
	{
		player[0].position = 9;
		printf("\n%s\n", (rooms[9].name));
		printf("%s\n", (rooms[9].description));
		return;
	}
	if (player[0].position == 9)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 10)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 11)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 12)
	{
		printf("There is a wall!.\n");
		return;
	}
}

void World::Move_position_East(){

	if (player[0].position == 0)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 1)
	{
		player[0].position = 8;
		printf("\n%s\n", (rooms[8].name));
		printf("%s\n", (rooms[8].description));
		return;
	}
	if (player[0].position == 2)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 3)
	{
		player[0].position = 1;
		printf("\n%s\n", (rooms[1].name));
		printf("%s\n", (rooms[1].description));
		return;
	}
	if (player[0].position == 4)
	{
		player[0].position = 3;
		printf("\n%s\n", (rooms[3].name));
		printf("%s\n", (rooms[3].description));
		return;
	}
	if (player[0].position == 5)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 6)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 7)
	{
		if (door[2].Num_doors == 1){
		player[0].position = 6;
		printf("\n%s\n", (rooms[6].name));
		printf("%s\n", (rooms[6].description));
		return;
		}
		else{
			printf("You can't move, there is a front door and closed.\n");
		}

	}
	if (player[0].position == 8)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (player[0].position == 9)
	{
		if (door[3].Num_doors == 1){
		player[0].position = 10;
		printf("\n%s\n", (rooms[10].name));
		printf("%s\n", (rooms[10].description));
		return;
		}
		else{
			printf("You can't move, there is a front door and closed.\n");
		}
	}

	if (player[0].position == 10)
	{
		printf("There is a wall!.\n");
		return;
	}

	if (player[0].position == 11)
	{
		printf("There is a wall!.\n");
		return;
	}

	if (player[0].position == 12)
	{
		if (door[4].Num_doors == 1){
		player[0].position = 11;
		printf("\n%s\n", (rooms[11].name));
		printf("%s\n", (rooms[11].description));
		return;
		}
		else{
			printf("You can't move, there is a front door and closed.\n");
		}
	}
}

void World::Look_position()const{

	if (player[0].position == 0){
		printf("%s", (rooms[0].name));
		printf("%s", (rooms[0].description));
	}
	if (player[0].position == 1){
		printf("%s", (rooms[1].name));
		printf("%s", (rooms[1].description));
		system("pause");
	}
	if (player[0].position == 2){
		printf("%s", (rooms[2].name));
		printf("%s", (rooms[2].description));
	}
	if (player[0].position == 3){
		printf("%s", (rooms[3].name));
		printf("%s", (rooms[3].description));
	}
	if (player[0].position == 4){
		printf("%s", (rooms[4].name));
		printf("%s", (rooms[4].description));
	}
	if (player[0].position == 5){
		printf("%s", (rooms[5].name));
		printf("%s", (rooms[5].description));
	}
	if (player[0].position == 6){
		printf("%s", (rooms[6].name));
		printf("%s", (rooms[6].description));
	}
	if (player[0].position == 7){
		printf("%s", (rooms[7].name));
		printf("%s", (rooms[7].description));
	}
	if (player[0].position == 8){
		printf("%s", (rooms[8].name));
		printf("%s", (rooms[8].description));
	}
	if (player[0].position == 9){
		printf("%s", (rooms[9].name));
		printf("%s", (rooms[9].description));
	}
}

void World::Look_Specify_position_North()const{

	if (player[0].position == 0){
		printf("%s\n", exit[1].description);
	}
	if (player[0].position == 1){
		printf("%s\n", exit[2].description);
	}
	if (player[0].position == 2){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 3){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 4){
		printf("%s\n", exit[5].description);
	}
	if (player[0].position == 5){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 6){
		printf("%s\n", exit[3].description);
	}
	if (player[0].position == 7){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 8){
		printf("%s\n", exit[11].description);
	}
	if (player[0].position == 9){
		printf("%s\n", exit[8].description);
	}
	if (player[0].position == 10){
		printf("There is a Exit.\n");
	}
	if (player[0].position == 11){
		printf("%s\n", exit[8].description);
	}
	if (player[0].position == 12){
		printf("There is a Wall.\n");
	}

}
void World::Look_Specify_position_West()const{

	if (player[0].position == 0){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 1){
		printf("%s\n", exit[3].description);
	}
	if (player[0].position == 2){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 3){
		printf("%s\n", exit[4].description);
	}
	if (player[0].position == 4){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 5){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 6){
		printf("%s\n", exit[7].description);
	}
	if (player[0].position == 7){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 8){
		printf("%s\n", exit[1].description);
	}
	if (player[0].position == 9){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 10){
		printf("%s\n", exit[9].description);
	}
	if (player[0].position == 11){
		printf("%s\n", exit[12].description);
	}
	if (player[0].position == 12){
		printf("There is a Wall.\n");
	}
}
void World::Look_Specify_position_South()const{

	if (player[0].position == 0){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 1){
		printf("%s\n", exit[0].description);
	}
	if (player[0].position == 2){
		printf("%s\n", exit[1].description);
	}
	if (player[0].position == 3){
		printf("%s\n", exit[6].description);
	}
	if (player[0].position == 4){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 5){
		printf("%s\n", exit[4].description);
	}
	if (player[0].position == 6){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 7){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 8){
		printf("%s\n", exit[9].description);
	}
	if (player[0].position == 9){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 10){
		printf("There is a Exit.\n");
	}
	if (player[0].position == 11){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 12){
		printf("There is a Wall.\n");
	}
}
void World::Look_Specify_position_East()const{

	if (player[0].position == 0){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 1){
		printf("%s\n", exit[8].description);
	}
	if (player[0].position == 2){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 3){
		printf("%s\n", exit[1].description);
	}
	if (player[0].position == 4){
		printf("%s\n", exit[3].description);
	}
	if (player[0].position == 5){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 6){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 7){
		printf("%s\n", exit[6].description);
	}
	if (player[0].position == 8){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 9){
		printf("%s\n", exit[10].description);
	}
	if (player[0].position == 10){
		printf("There is a Exit.\n");
	}
	if (player[0].position == 11){
		printf("There is a Wall.\n");
	}
	if (player[0].position == 12){
		printf("%s\n", exit[11].description);
	}
}

bool World::Exit_zork(){
	if (quit == 1)
		return false;
	else
		return true;
}