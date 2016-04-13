#include <stdio.h>
#include <stdlib.h>
#include "World.h"
#include "Room.h"
#include "Player.h"
#include "Door.h"
#include "Exits.h"
#include "Entity.h"
#include "Vector.h"
#include "Item.h"
#include "String_Class.h"
#include <string.h>

using namespace std;

//#define _CRT_SECURE_NO_WARNINGS


World::World(){
	comand = new char[];
}

World::~World()
{

}


void World::Create_World(){

	Player* gamer;
	//Create Player
	player.push_back(gamer = new Player("Player", "You have 20 years."));


	//Create Rooms
	Room* MainRoom;//0
	Room* Ailse;//1...
	Room* DressingRoom;
	Room* OfficeRoom;
	Room* MysteryRoom;
	Room* Warehouse;
	Room* Warehouse2;
	Room* Gunsmith;
	Room* Ailse2;
	Room* Hall;
	Room* ExitRoom;
	Room* Ailse3;
	Room* Laboratory;


	rooms.push_back(MainRoom = new Room("You are stay in the Main Room.\n", "ha"));
	rooms.push_back(Ailse = new Room("You are stay in the Aisle.\n", "ha"));
	rooms.push_back(DressingRoom = new Room("Room 2", "ha"));
	rooms.push_back(OfficeRoom = new Room("Room 3", "ha"));
	rooms.push_back(MysteryRoom = new Room("Room 4", "ha"));
	rooms.push_back(Warehouse = new Room("Room 5", "ha"));
	rooms.push_back(Warehouse2 = new Room("Room 6", "ha"));
	rooms.push_back(Gunsmith = new Room("Room 7", "ha"));
	rooms.push_back(Ailse2 = new Room("Room 8", "ha"));
	rooms.push_back(Hall = new Room("Room 9", "ha"));
	rooms.push_back(ExitRoom = new Room("Room 10", "ha"));
	rooms.push_back(Ailse3 = new Room("Room 11", "ha"));
	rooms.push_back(Laboratory = new Room("Room 12", "ha"));

	my_entities.push_back(MainRoom);
	my_entities.push_back(Ailse);
	my_entities.push_back(DressingRoom);
	my_entities.push_back(OfficeRoom);
	my_entities.push_back(MysteryRoom);
	my_entities.push_back(Warehouse);
	my_entities.push_back(Warehouse2);
	my_entities.push_back(Gunsmith);
	my_entities.push_back(Ailse2);
	my_entities.push_back(Hall);
	my_entities.push_back(ExitRoom);
	my_entities.push_back(Ailse3);
	my_entities.push_back(Laboratory);
	//rooms[0]->name();

	/*rooms[0].name = "hola";
	rooms[0].name = "You are stay in the Main Room.\n";
	rooms[0].description, "This room is very dark but there is a light above is enough to see everything. \nThere is only one door and the north.\n";

	rooms[1].name = "You are stay in the Aisle.\n";
	rooms[1].description = "This Aisle is small and it's a dimly lit.\n";

	rooms[2].name = "You are stay in the Dressing Room.\n";
	rooms[2].description = "You can see many lockers, and some are open.|nThere is also a window but it is locked with bars.\n";

	rooms[3].name = "You are stay in the Office Room.\n";
	rooms[3].description = "It is a large room, you see that this separated workspaces with computers at home space.\n";

	rooms[4].name = "You are stay in the Mystery Room.\n";
	rooms[4].description = "This room is has a gigantic cube in the middle of the room has a door and it seems that this open.\n";

	rooms[5].name = "You are stay in the Warehouse.\n";
	rooms[5].description = "There are many shelves.\n";

	rooms[6].name = "You are stay in the Warehouse II.\n";
	rooms[6].description = "There are many shelves.\n";

	rooms[7].name = "You are stay in the Gunsmith.\n";
	rooms[7].description = "Here are many weapons and lots of ammunition, it could be useful.\n";

	rooms[8].name = "You are stay in the Aisle 2.\n";
	rooms[8].description = "This Aisle is big room.\n";

	rooms[9].name = "You are stay in the Hall.\n";
	rooms[9].description = "It is a very large room with plenty of lighting.\n";

	rooms[10].name = "You are stay in the Exit.\n";
	rooms[10].description = "This is Exit.\n";

	rooms[11].name = "You are stay in the Aisle 3.\n";
	rooms[11].description = "This Aisle is long.\n";

	rooms[12].name = "You are stay in the Laboratory.\n";
	rooms[12].description = "There are many very strange instruments.\n";*/

	

	//Create Exits

	exit.push_back(new Exits("Exit to Main Room.\n", "There is a door.\nBehind the door is the Main Room.\n", 1));
	exit.push_back(new Exits("Exit to Ailse 1.\n", "There is a door.\nBehind the door is the Aisle.\n", 0));
	exit.push_back(new Exits("Exit to Dressing Room.\n", "There is a door.\nBehind the door is the Dressing Room.\n", 0));
	exit.push_back(new Exits("Exit to Office Room.\n", "There is a door.\nBehind the door is the Office Room.\n", 0));
	exit.push_back(new Exits("Exit to Mystery Spawn.\n", "There is a door.\nBehind the door is the Mystery Spawn.\n", 0));
	exit.push_back(new Exits("Exit to Warehouse.\n", "There is a door.\nBehind the door is the Warehouse.\n", 0));
	exit.push_back(new Exits("Exit to Warehouse 2.\n", "There is a door.\nBehind the door is the Warehouse.\n", 0));
	exit.push_back(new Exits("Exit to Gunsmith.\n", "There is a door.\nBehind the door is the Gunsmith.\n", 0));
	exit.push_back(new Exits("Exit to Ailse 2.\n", "There is a door.\nBehind the door is the Ailse 2.\n", 0));
	exit.push_back(new Exits("Exit to Hall.\n", "There is a door.\nBehind the door is the Hall.\n", 0));
	exit.push_back(new Exits("Exit to Exit.\n", "There is a door.\nBehind the door is the Exit.\n", 0));
	exit.push_back(new Exits("Exit to Ailse 3.\n", "There is a door.\nBehind the door is the Ailse 3.\n", 0));
	exit.push_back(new Exits("Exit to Laboratory.\n", "There is a door.\nBehind the door is the Laboratory.\n", 0));


	//Create Doors
	door.push_back(new Door(0));
	door.push_back(new Door(0));
	door.push_back(new Door(0));
	door.push_back(new Door(0));
	door.push_back(new Door(0));

	Item* Latern;
	Item* TargetLaboratory;
	Item* KeyDressing;
	Item* KeyGunsmith;
	Item* TargetMaster;
	Item* LockDressing;
	Item* LockGunsmith;
	Item* Locker;
	Item* Gun;
	Item* Ammo;
	Item* Camera;
	Item* ASafe;
	Item* CardReaderLabo;
	Item* CardReaderExit;
	Item* BackPack;

	item.push_back(Latern = new Item("Latern", "iluminate\n"));
	item.push_back(TargetLaboratory = new Item("Tarjet Laboratory", "Target\n"));
	item.push_back(KeyDressing = new Item("Key of Dressing Room", "key\n"));
	item.push_back(KeyGunsmith = new Item("Key of Gunsmith", "key\n"));
	item.push_back(TargetMaster = new Item("Target Master", "iluminate\n"));
	item.push_back(LockDressing = new Item("Lock of Dressing Room", "iluminate\n"));
	item.push_back(LockGunsmith = new Item("Lock of Gunsmith", "iluminate\n"));
	item.push_back(Locker = new Item("Locker", "Locker in Dressing Room\n"));
	item.push_back(Gun = new Item("Gun", "This gun is a M4A1-S.\n"));
	item.push_back(Ammo = new Item("Ammo", "1 cargador"));
	item.push_back(Camera = new Item("Camera", "iluminate"));
	item.push_back(ASafe = new Item("A Safe", "A Safe in Warehouse.\n"));
	item.push_back(CardReaderLabo = new Item("Card Reader of Laboratory", "iluminate"));
	item.push_back(CardReaderExit = new Item("Card Reader of Exit", "iluminate"));
	item.push_back(BackPack = new Item("Back Pack", "iluminate"));

	my_entities.push_back(Latern);
	my_entities.push_back(TargetLaboratory);
	my_entities.push_back(KeyDressing);
	my_entities.push_back(KeyGunsmith);
	my_entities.push_back(TargetMaster);
	my_entities.push_back(LockDressing);
	my_entities.push_back(LockGunsmith);
	my_entities.push_back(Locker);
	my_entities.push_back(Gun);
	my_entities.push_back(Ammo);
	my_entities.push_back(Camera);
	my_entities.push_back(ASafe);
	my_entities.push_back(CardReaderLabo);
	my_entities.push_back(CardReaderExit);
	my_entities.push_back(BackPack);


}


void World::Set_Command(){

	printf("> ");

	gets_s(comand, 20);
	//comand->set();

	if (strcmp("look inventory", comand) == 0 || strcmp("look i", comand) == 0){
		//Look();
	}

	//Command - Help
	if (strcmp("help", comand) == 0){
		printf("Your commands:\n");
		printf("-[go north] or [go n]\n-[go west] or [go w]\n-[go south] or [go s]\n-[go east] or [go e]\n");
		printf("-[go up] or [go u]\n-[go down] or [go d]\n");
		printf("-[look (the same way as above)]\n");
		printf("-[open door]\n-[close door]\n");
		printf("-[quit]\n-[help]\n");
	}


	//Commands - Go
	if (strcmp("go", comand) == 0){
		printf("Where you want to go? [go north, go west, go south, go east]\n");
	}
	if (strcmp("go n", comand) == 0 || strcmp("go w", comand) == 0 || strcmp("go s", comand) == 0 || strcmp("go e", comand) == 0 || strcmp("go u", comand) == 0 || strcmp("go d", comand) == 0){
		Move();
	}
	if (strcmp("go north", comand) == 0 || strcmp("go west", comand) == 0 || strcmp("go south", comand) == 0 || strcmp("go east", comand) == 0 || strcmp("go up", comand) == 0 || strcmp("go down", comand) == 0){
		Move();
	}

	//Comands - Open and Close
	/*if (strcmp("open", comand) == 0){
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
	*/
	//Comand - Exit
	if (strcmp("quit", comand) == 0){
		quit = 1;
		Exit_zork();
	}
}

void World::Move()
{
	//Main Room
	if (player[0]->position == 0)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			exit[1]->discover = 1;
			printf("%s\n", rooms[1]->name());
			printf("%s\n", rooms[1]->description());
			player[0]->position = 1;
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
	if (player[0]->position == 1)
	{
		if ((strcmp("go n", comand) == 0) || (strcmp("go north", comand) == 0))
		{
			if (door[0]->Num_doors == 1)
			{
				exit[2]->discover = 1;
				player[0]->position = 2;
				printf("\n%s\n", (rooms[2]->name()));
				printf("%s\n", (rooms[2]->description()));
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if ((strcmp("go w", comand) == 0) || (strcmp("go west", comand) == 0))
		{
			exit[3]->discover = 1;
			player[0]->position = 3;
			printf("\n%s\n", (rooms[3]->name()));
			printf("%s\n", (rooms[3]->description()));
			return;
		}
		else if ((strcmp("go s", comand) == 0) || (strcmp("go south", comand) == 0))
		{
			player[0]->position = 0;
			printf("\n%s\n", (rooms[0]->name()));
			printf("%s\n", (rooms[0]->description()));
			return;
		}
		else if ((strcmp("go e", comand) == 0) || (strcmp("go east", comand) == 0))
		{
			exit[8]->discover = 1;
			player[0]->position = 8;
			printf("\n%s\n", (rooms[8]->name()));
			printf("%s\n", (rooms[8]->description()));
			return;
		}
	}
	/*//Dressing Room
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
			printf("There are stairs that go up.\n");
			return;
		}
		if ((strcmp("go u", comand) == 0) || (strcmp("go up", comand) == 0))
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
			printf("There are stairs that go down.\n");
			return;
		}
		if ((strcmp("go d", comand) == 0) || (strcmp("go down", comand) == 0))
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
	}*/
}

/*
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
		rooms[0]->name();
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

	if (strcmp("look inventory", comand) == 0 || strcmp("look i", comand) == 0){
		printf("Your inventory:\n");
		for (int i = 0; i < 2; i++)
		{
			if (item[i].item_status == 1)
			{
				printf("%s\n", (item[i].name));
			}
			else{
				printf("No inventory!\n");
			}
		}
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
				printf("There are stairs that go up and that room has not been discovered yet.\n");
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
				printf("There are stairs that go up and that room has not been discovered yet.\n");
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
*/

void World::Look()const
{

}
bool World::Exit_zork(){
	if (quit == 1)
		return false;
	else
		return true;
}
