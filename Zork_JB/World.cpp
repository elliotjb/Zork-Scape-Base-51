#include <stdio.h>
#include <stdlib.h>
#include "World.h"
#include "Room.h"
#include "player.h"
#include "Door.h"
#include "Exits.h"
#include "Entity.h"
#include "String_Class.h"
#include <string.h>

using namespace std;

//#define _CRT_SECURE_NO_WARNINGS


World::World(){
	rooms = new Room[13];
	player = new Player[1];
	exit = new Exits[13];
	door = new Door[5];
	comand = new char[];

}

World::~World(){
	delete[]rooms;
	delete[]player;
	delete[]exit;
	delete[]door;
	delete[]comand;
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

	strcpy_s(rooms[4].name, "You are stay in the Mystery Room.\n");
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
	strcpy_s(exit[4].description, "There is a door.\nBehind the door is the Mystery Spawn.\n");
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

	//Discover Rooms
	exit[0].discover = 1;// 0 = No discover // 1 = Discover
	exit[1].discover = 0;
	exit[2].discover = 0;
	exit[3].discover = 0;
	exit[4].discover = 0;
	exit[5].discover = 0;
	exit[6].discover = 0;
	exit[7].discover = 0;
	exit[8].discover = 0;
	exit[9].discover = 0;
	exit[10].discover = 0;
	exit[11].discover = 0;
	exit[12].discover = 0;

}

void World::Set_Command(){

	printf("> ");
	gets_s(comand, 20);

	//App->comands = comand;

	/*if (App->comands == "go n"){
		printf("HOLAAAAAAAAAA\n");
	}*/
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
	if (strcmp("go n", comand) == 0 || strcmp("go w", comand) == 0 || strcmp("go s", comand) == 0 || strcmp("go e", comand) == 0){
		Move();
	}
	if (strcmp("go north", comand) == 0 || strcmp("go west", comand) == 0 || strcmp("go south", comand) == 0 || strcmp("go east", comand) == 0){
		Move();
	}

	//Comands - Open and Close
	if (strcmp("open", comand) == 0){
		printf("The command to open is [open door (direction) -> example: open door north].\n");
	}
	if (strcmp("close", comand) == 0){
		printf("The command to close is [close door (direction) -> example: close door north].\n");
	}

	//Open
	if (strcmp("open door n", comand) == 0 || strcmp("open door w", comand) == 0 || strcmp("open door s", comand) == 0 || strcmp("open door e", comand) == 0){
		Open();
	}
	if (strcmp("open door north", comand) == 0 || strcmp("open door west", comand) == 0 || strcmp("open door south", comand) == 0 || strcmp("open door east", comand) == 0){
		Open();
	}

	//Close
	if (strcmp("close door n", comand) == 0 || strcmp("close door w", comand) == 0 || strcmp("close door s", comand) == 0 || strcmp("close door e", comand) == 0){
		Close();
	}
	if (strcmp("close door north", comand) == 0 || strcmp("close door west", comand) == 0 || strcmp("close door south", comand) == 0 || strcmp("close door east", comand) == 0){
		Close();
	}


	//Command - Look
	if (strcmp("look", comand) == 0){
		Look();
		if (cont < 2){
			printf("If you want to specify where to look like this-> [ look north/n, look west/w, look south/s, look east/e ]\n");
			cont++;
		}
	}

	//Commands - Look Specify position
	if (strcmp("look n", comand) == 0 || strcmp("look w", comand) == 0 || strcmp("look s", comand) == 0 || strcmp("look e", comand) == 0){
		Look_Specify_Position();
	}
	if (strcmp("look north", comand) == 0 || strcmp("look west", comand) == 0 || strcmp("look south", comand) == 0 || strcmp("look east", comand) == 0){
		Look_Specify_Position();
	}

	//Comand - Exit
	if (strcmp("quit", comand) == 0){
		quit = 1;
		Exit_zork();
	}
}

void World::Move()
{
	//Main Room
	if (player[0].position == 0)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			exit[1].discover = 1;
			printf("\n%s\n", (rooms[1].name));
			printf("%s\n", (rooms[1].description));
			player[0].position = 1;
			return;
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
	}
	//Ailse 1
	if (player[0].position == 1)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			if (door[0].Num_doors == 1)
			{
				exit[2].discover = 1;
				player[0].position = 2;
				printf("\n%s\n", (rooms[2].name));
				printf("%s\n", (rooms[2].description));
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			exit[3].discover = 1;
			player[0].position = 3;
			printf("\n%s\n", (rooms[3].name));
			printf("%s\n", (rooms[3].description));
			return;
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			player[0].position = 0;
			printf("\n%s\n", (rooms[0].name));
			printf("%s\n", (rooms[0].description));
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			exit[8].discover = 1;
			player[0].position = 8;
			printf("\n%s\n", (rooms[8].name));
			printf("%s\n", (rooms[8].description));
			return;
		}
	}
	//Dressing Room
	if (player[0].position == 2)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			if (door[0].Num_doors == 1)
			{
				player[0].position = 1;
				printf("\n%s\n", (rooms[1].name));
				printf("%s\n", (rooms[1].description));
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
	}

	//Office Room
	if (player[0].position == 3)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			exit[4].discover = 1;
			player[0].position = 4;
			printf("\n%s\n", (rooms[4].name));
			printf("%s\n", (rooms[4].description));
			return;
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			exit[6].discover = 1;
			player[0].position = 6;
			printf("\n%s\n", (rooms[6].name));
			printf("%s\n", (rooms[6].description));
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			player[0].position = 1;
			printf("\n%s\n", (rooms[1].name));
			printf("%s\n", (rooms[1].description));
			return;
		}
	}

	//Alien Spawn
	if (player[0].position == 4)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			if (door[1].Num_doors == 1)
			{
				exit[5].discover = 1;
				player[0].position = 5;
				printf("\n%s\n", (rooms[5].name));
				printf("%s\n", (rooms[5].description));
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			player[0].position = 3;
			printf("\n%s\n", (rooms[3].name));
			printf("%s\n", (rooms[3].description));
			return;
		}
	}

	//Warehouse
	if (player[0].position == 5)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
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
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
	}

	//Warehouse 2
	if (player[0].position == 6)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			player[0].position = 3;
			printf("\n%s\n", (rooms[3].name));
			printf("%s\n", (rooms[3].description));
			return;
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			if (door[2].Num_doors == 1)
			{
				exit[7].discover = 1;
				player[0].position = 7;
				printf("\n%s\n", (rooms[7].name));
				printf("%s\n", (rooms[7].description));
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
	}

	//Gunsmith
	if (player[0].position == 7)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
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
	}

	//Aisle 2
	if (player[0].position == 8)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			exit[11].discover = 1;
			player[0].position = 11;
			printf("\n%s\n", (rooms[11].name));
			printf("%s\n", (rooms[11].description));
			return;
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			player[0].position = 1;
			printf("\n%s\n", (rooms[1].name));
			printf("%s\n", (rooms[1].description));
			return;
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			exit[9].discover = 1;
			player[0].position = 9;
			printf("\n%s\n", (rooms[9].name));
			printf("%s\n", (rooms[9].description));
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
	}

	//Hall
	if (player[0].position == 9)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			player[0].position = 8;
			printf("\n%s\n", (rooms[8].name));
			printf("%s\n", (rooms[8].description));
			return;
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			if (door[3].Num_doors == 1)
			{
				exit[10].discover = 1;
				player[0].position = 10;
				printf("\n%s\n", (rooms[10].name));
				printf("%s\n", (rooms[10].description));
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
	}

	//Exit
	if (player[0].position == 10)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			printf("This is Exit!\n");
			return;
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
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
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			printf("This is Exit!\n");
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			printf("This is Exit!\n");
			return;
		}
	}

	//Aisle 3
	if (player[0].position == 11)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			player[0].position = 8;
			printf("\n%s\n", (rooms[8].name));
			printf("%s\n", (rooms[8].description));
			return;
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			if (door[4].Num_doors == 1)
			{
				exit[12].discover = 1;
				player[0].position = 12;
				printf("\n%s\n", (rooms[12].name));
				printf("%s\n", (rooms[12].description));
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
	}

	//Laboratory
	if (player[0].position == 12)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			printf("There is a wall!.\n");
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
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
}

void World::Open()
{
	if ((strcmp(comand, "open door north") == 0) || (strcmp(comand, "open door n") == 0))
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
	if ((strcmp(comand, "open door west") == 0) || (strcmp(comand, "open door w") == 0))
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
	if ((strcmp(comand, "open door south") == 0) || (strcmp(comand, "open door s") == 0))
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
	if ((strcmp(comand, "open door south") == 0) || (strcmp(comand, "open door s") == 0))
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
}

void World::Close()
{
	if ((strcmp(comand, "close door north") == 0) || (strcmp(comand, "close door n") == 0))
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
	if ((strcmp(comand, "close door west") == 0) || (strcmp(comand, "close door w") == 0))
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
	if ((strcmp(comand, "close door south") == 0) || (strcmp(comand, "close door s") == 0))
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
	if ((strcmp(comand, "close door south") == 0) || (strcmp(comand, "close door s") == 0))
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
}

void World::Look()const{

	if (player[0].position == 0){
		printf("%s", (rooms[0].name));
		printf("%s", (rooms[0].description));
	}
	if (player[0].position == 1){
		printf("%s", (rooms[1].name));
		printf("%s", (rooms[1].description));
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
	if (player[0].position == 10){
		printf("%s", (rooms[10].name));
		printf("%s", (rooms[10].description));
	}
	if (player[0].position == 11){
		printf("%s", (rooms[11].name));
		printf("%s", (rooms[11].description));
	}
	if (player[0].position == 12){
		printf("%s", (rooms[12].name));
		printf("%s", (rooms[12].description));
	}
}

void World::Look_Specify_Position() const
{
	//Main Room
	if (player[0].position == 0)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			if (exit[1].discover == 1)
			{
				printf("%s\n", exit[1].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}

		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
	}

	//Ailse
	if (player[0].position == 1)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			if (exit[2].discover == 1)
			{
				printf("%s\n", exit[2].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			if (exit[3].discover == 1)
			{
				printf("%s\n", exit[3].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			if (exit[0].discover == 1)
			{
				printf("%s\n", exit[0].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			if (exit[8].discover == 1)
			{
				printf("%s\n", exit[8].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}

	}

	//Dressing Room
	if (player[0].position == 2)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			if (exit[1].discover == 1)
			{
				printf("%s\n", exit[1].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
	}

	//Office Room
	if (player[0].position == 3)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			if (exit[4].discover == 1)
			{
				printf("%s\n", exit[4].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			if (exit[6].discover == 1)
			{
				printf("%s\n", exit[6].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			if (exit[1].discover == 1)
			{
				printf("%s\n", exit[1].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
	}

	//Mystery Room (alien-room)
	if (player[0].position == 4)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			if (exit[5].discover == 1)
			{
				printf("%s\n", exit[5].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			if (exit[3].discover == 1)
			{
				printf("%s\n", exit[3].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
	}

	//Warehouse
	if (player[0].position == 5)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			if (exit[4].discover == 1)
			{
				printf("%s\n", exit[4].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		printf("There is a Wall.\n");
	}

	//Warehouse 2
	if (player[0].position == 6)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			if (exit[3].discover == 1)
			{
				printf("%s\n", exit[3].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			if (exit[7].discover == 1)
			{
				printf("%s\n", exit[7].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
	}

	//Gunsmith
	if (player[0].position == 7)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			if (exit[6].discover == 1)
			{
				printf("%s\n", exit[6].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
	}

	//Ailse 2
	if (player[0].position == 8)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			if (exit[11].discover == 1)
			{
				printf("%s\n", exit[11].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			if (exit[1].discover == 1)
			{
				printf("%s\n", exit[1].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			if (exit[9].discover == 1)
			{
				printf("%s\n", exit[9].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
	}

	//Hall
	if (player[0].position == 9)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			if (exit[8].discover == 1)
			{
				printf("%s\n", exit[8].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			if (exit[10].discover == 1)
			{
				printf("%s\n", exit[10].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
	}

	//Exit
	if (player[0].position == 10)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			printf("There is a Exit.\n");
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			if (exit[9].discover == 1)
			{
				printf("%s\n", exit[9].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			printf("There is a Exit.\n");
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			printf("There is a Exit.\n");
		}
	}

	//Ailse 3
	if (player[0].position == 11)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			if (exit[8].discover == 1)
			{
				printf("%s\n", exit[8].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			if (exit[12].discover == 1)
			{
				printf("%s\n", exit[12].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
	}

	//Laboratory
	if (player[0].position == 12)
	{
		if ((strcmp("look n", comand) == 0) || (strcmp("look north", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look w", comand) == 0) || (strcmp("look west", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look s", comand) == 0) || (strcmp("look south", comand) == 0))
		{
			printf("There is a Wall.\n");
		}
		else if ((strcmp("look e", comand) == 0) || (strcmp("look east", comand) == 0))
		{
			if (exit[11].discover == 1)
			{
				printf("%s\n", exit[11].description);
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
	}
}

bool World::Exit_zork(){
	if (quit == 1)
		return false;
	else
		return true;
}

