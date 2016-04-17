#include <stdio.h>
#include <stdlib.h>
#include "World.h"
#include "Room.h"
#include "player.h"
#include "Door.h"
#include "Exits.h"
#include "Entity.h"
#include "Vector.h"
#include "Item.h"
#include "String_Class.h"
//#include <string.h>

using namespace std;

//#define _CRT_SECURE_NO_WARNINGS


World::World()
{
	player = new Player;
}
World::~World()
{

}


void World::Create_World(){

	//Create Player


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


	rooms.push_back(MainRoom = new Room("You are stay in the Main Room.\n", "room[0]\n\n"));
	rooms.push_back(Ailse = new Room("You are stay in the Aisle.\n", "room[1]\n\n"));
	rooms.push_back(DressingRoom = new Room("Room 2", "room[2]\n\n"));
	rooms.push_back(OfficeRoom = new Room("Room 3", "room[3]\n\n"));
	rooms.push_back(MysteryRoom = new Room("Room 4", "room[4]\n\n"));
	rooms.push_back(Warehouse = new Room("Room 5", "room[5]\n\n"));
	rooms.push_back(Warehouse2 = new Room("Room 6", "room[6]\n\n"));
	rooms.push_back(Gunsmith = new Room("Room 7", "room[7]\n\n"));
	rooms.push_back(Ailse2 = new Room("Room 8", "room[8]\n\n"));
	rooms.push_back(Hall = new Room("Room 9", "room[9]\n\n"));
	rooms.push_back(ExitRoom = new Room("Room 10", "room[10]\n\n"));
	rooms.push_back(Ailse3 = new Room("Room 11", "room[11]\n\n"));
	rooms.push_back(Laboratory = new Room("Room 12", "room[12]\n\n"));

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

	//player.push_back(new Player(rooms[0]));


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

	//PLAYER
	player->position = rooms[0];

	//ITEMS
	item.push_back(new Item("bag", "It is a military backpack brown and is quite large.\n", rooms[0], false, false, false, false, 0, 0, 100));//item[0], 

	item.push_back(new Item("lantern", "It is a lantern of those that are small but more light than the sun.\n", rooms[0], false, false, false, false, 0, 0, 10));//item[1], 

	item.push_back(new Item("card", "It looks like a card to pass a security check, it may be useful!\n", rooms[5], false, false, false, false, 0, 0, 50));//item[2], 

	item.push_back(new Item("picklock", "It can be useful to open doors, thank god know how to use it.\n", rooms[3], false, false, false, false, 0, 0, 1));//item[3], 

	item.push_back(new Item("key", "It is a normal key, with a label that puts armory.\n", rooms[2], false, false, false, false, 0, 0, 10));//item[4], 

	item.push_back(new Item("paper", "It is a small role. It has written a command: 'SZKMS'.\n", rooms[12], false, false, false, false, 0, 0, 100));//item[5], 

	item.push_back(new Item("gun", "It is a M4A1-S, it is one of my favorite weapons.\n", rooms[7], false, false, false, false, 0, 5, 100));//item[6], 

	item.push_back(new Item("ammo", "It is a ammo pack, but only has 10 bullets.\n", rooms[7], false, false, false, false, 0, 45, 10));//item[7], 

	item.push_back(new Item("camera", "camera\n", rooms[5], false, false, false, false, 0, 0, 100));//item[8], 

	item.push_back(new Item("vest", "bulletproof vest!\n", rooms[0], false, false, false, false, 100, 0, 10));//item[9], 

	item.push_back(new Item("safe", "A Safe in Warehouse.\n", rooms[5], false, true, false, false, 0, 0, 0));//item[10], 

	item.push_back(new Item("reader", "Number Reader of Exit\n", rooms[9], false, true, false, false, 0, 0, 0));//item[11], 

	item.push_back(new Item("scanner", "Card Scanner of Laboratory\n", rooms[11], false, true, false, false, 0, 0, 0));//item[12], to open door of laboratory

	item.push_back(new Item("lock", "Lock of Dressing Room\n", rooms[1], false, true, false, false, 0, 0, 0));//item[13], 

	item.push_back(new Item("padlock", "Padlock of door in Mystery room!\n", rooms[4], false, true, false, false, 0, 0, 0));//item[14], Candado

	item.push_back(new Item("lock", "Lock of Gunsmith\n", rooms[6], false, true, false, false, 0, 0, 0));//item[15], 

	item.push_back(new Item("armory", "armory of Gunsmith", rooms[7], false, true, false, false, 0, 0, 0));//item[16], 

	item.push_back(new Item("locker", "You can store things inside.\n", rooms[0], false, true, false, false, 0, 0, 0));//item[17], 

}

void World::Input()
{
	do
	{
		printf("> ");
		gets_s(option, 40);
	} while (option == NULL);

}


void World::Set_Command()
{
	Input();
	comand = option;
	printf("\n");

	if (option[0] != NULL && option[0] != ' ')
	{
		Vector<ClString> comand_tok = comand.tokenize(option);

		//Command - Help
		if (comand_tok[0] == "help"){
			printf("Your commands:\n");
			printf("-[go north] or [go n]\n-[go west] or [go w]\n-[go south] or [go s]\n-[go east] or [go e]\n");
			printf("-[go up] or [go u]\n-[go down] or [go d]\n");
			printf("-[look (the same way as above)]\n");
			printf("-[open door]\n-[close door]\n");
			printf("-[quit]\n-[help]\n");
		}

		if (comand == "pick" || comand == "p")
		{
			printf("Please, put pick [item]\n");
		}

		if (comand_tok[0] == "pick" && option[4] == ' ' || comand_tok[0] == "p" && option[1] == ' '){
			Pick_item(comand_tok);
		}

		if (comand == "drop" || comand == "d")
		{
			printf("Please, put drop [item]\n");
		}
		if (comand_tok[0] == "drop" && option[4] == ' ' || comand_tok[0] == "d" && option[1] == ' '){
			Drop_item(comand_tok);
		}

		//Commands - Go
		if (comand == "go"){
			printf("Where you want to go? [go north, go west, go south, go east]\n");
		}

		if (comand == "go n" || comand == "go w" || comand == "go s" || comand == "go e" || comand == "go u" || comand == "go d"){
			Move();
		}
		if (comand == "go north" || comand == "go westw" || comand == "go south" || comand == "go east" || comand == "go up" || comand == "go down"){
			Move();
		}

		//Comands - Open and Close
		if (comand == "open"){
			printf("The command to open is [open door (direction) -> example: open door north].\n");
		}
		if (comand == "close"){
			printf("The command to close is [close door (direction) -> example: close door north].\n");
		}

		//Open
		if (comand == "open door n" || comand == "open door w" || comand == "open door s" || comand == "open door e"){
			Open();
		}
		if (comand == "open door north" || comand == "open door west" || comand == "open door south" || comand == "open door east"){
			Open();
		}

		//Close
		if (comand == "close door n" || comand == "close door w" || comand == "close door s" || comand == "close door e"){
			Close();
		}
		if (comand == "close door north" || comand == "close door west" || comand == "close door south" || comand == "close door east"){
			Close();
		}

		//Command - Look
		if (comand == "look"){
			Look();
			if (cont < 2){
				printf("\nIf you want to specify where to look like this-> [ look north/n, look west/w, look south/s, look east/e ]\n");
				cont++;
			}
		}

		//Comand - look inventory
		if (comand == "look inventory" || comand == "look inv" || comand == "look i"
			|| comand == "inventory" || comand == "inv" || comand == "i"){
			Look_inventory();
		}

		if (comand_tok[0] == "look" && option[4] == ' ')
		{
			Look_item(comand_tok);
		}

		//Commands - Look Specify position
		if (comand == "look n" || comand == "look w" || comand == "look s" || comand == "look e"){
			Look_Specify_Position();
		}
		if (comand == "look north" || comand == "look west" || comand == "look south" || comand == "look east"){
			Look_Specify_Position();
		}

		//comands - equip
		if (comand == "equip" || comand == "e")
		{
			printf("Please, put equip [item]!\n");
		}

		if (comand_tok[0] == "equip" && option[5] == ' ' || comand_tok[0] == "e" && option[1] == ' '){
			Equip(comand_tok);
		}

		//comands - uneequip
		if (comand == "unequip" || comand == "ue")
		{
			printf("Please, put drop [item]\n\n");
		}

		if (comand_tok[0] == "unequip" && option[7] == ' ' || comand_tok[0] == "ue" && option[2] == ' '){
			UnEquip(comand_tok);
		}

		//Comand - put
		if (comand == "put" || comand == "put")
		{
			printf("Please, write put [item] into [item]\n\n");
		}

		if (comand_tok[0] == "put" && comand_tok[2] == "into")
		{
			Put_into(comand_tok);
		}

		//Comand - get
		if (comand == "g" || comand == "get")
		{
			printf("Please, write get [item] from [item]\n\n");
		}

		if (comand_tok[0] == "get" && comand_tok[2] == "from")
		{
			Get_from(comand_tok);
		}
		//Comand - stats

		if (comand == "stats" || comand == "st")
		{
			Stats();
		}

		//Comand - Exit
		if (comand == "quit"){
			quit = 1;
			Exit_zork();
		}
	}

}

void World::Move()
{

	//Main Room
	if (player->position == rooms[0])
	{
		if (comand == "go n" || comand == "go north")
		{
			exit[1]->discover = 1;
			printf("%s\n", rooms[1]->name.getstr());
			printf("%s\n", rooms[1]->description.getstr());
			player->position = rooms[1];
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n");
			return;
		}
	}
	//Ailse 1
	if (player->position == rooms[1])
	{
		if (comand == "go n" || comand == "go north")
		{
			if (door[0]->Num_doors == 1)
			{
				exit[2]->discover = 1;
				player->position = rooms[2];
				printf("\n%s\n", rooms[2]->name.getstr());
				printf("%s\n", rooms[2]->description.getstr());
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if (comand == "go w" || comand == "go west")
		{
			exit[3]->discover = 1;
			player->position = rooms[3];
			printf("\n%s\n", rooms[3]->name.getstr());
			printf("%s\n", rooms[3]->description.getstr());
			return;
		}
		if (comand == "go s" || comand == "go south")
		{
			player->position = rooms[0];
			printf("\n%s\n", rooms[0]->name.getstr());
			printf("%s\n", rooms[0]->description.getstr());
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			exit[8]->discover = 1;
			player->position = rooms[8];
			printf("\n%s\n", rooms[8]->name.getstr());
			printf("%s\n", rooms[8]->description.getstr());
			return;
		}
	}
	//Dressing Room
	if (player->position == rooms[2])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			if (door[0]->Num_doors == 1)
			{
				player[0].position = rooms[1];
				printf("\n%s\n", rooms[1]->name.getstr());
				printf("%s\n", rooms[1]->description.getstr());
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n");
			return;
		}
	}

	//Office Room
	if (player->position == rooms[3])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			exit[4]->discover = 1;
			player->position = rooms[4];
			printf("\n%s\n", rooms[4]->name.getstr());
			printf("%s\n", rooms[4]->description.getstr());
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			exit[6]->discover = 1;
			player->position = rooms[6];
			printf("\n%s\n", rooms[6]->name.getstr());
			printf("%s\n", rooms[6]->description.getstr());
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			player->position = rooms[1];
			printf("\n%s\n", (rooms[1]->name));
			printf("%s\n", (rooms[1]->description));
			return;
		}
	}

	//Alien Spawn
	if (player->position == rooms[4])
	{
		if (comand == "go n" || comand == "go north")
		{
			if (door[1]->Num_doors == 1)
			{
				exit[5]->discover = 1;
				player->position = rooms[5];
				printf("\n%s\n", rooms[5]->name.getstr());
				printf("%s\n", rooms[5]->description.getstr());
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			player->position = rooms[3];
			printf("\n%s\n", rooms[3]->name.getstr());
			printf("%s\n", rooms[3]->description.getstr());
			return;
		}
	}

	//Warehouse
	if (player->position == rooms[5])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			if (door[1]->Num_doors == 1){
				player->position = rooms[4];
				printf("\n%s\n", rooms[4]->name.getstr());
				printf("%s\n", rooms[4]->description.getstr());;
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n");
			return;
		}
	}

	//Warehouse 2
	if (player->position == rooms[6])
	{
		if (comand == "go n" || comand == "go north")
		{
			player->position = rooms[3];
			printf("\n%s\n", rooms[3]->name.getstr());
			printf("%s\n", rooms[3]->description.getstr());
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			if (door[2]->Num_doors == 1)
			{
				exit[7]->discover = 1;
				player->position = rooms[7];
				printf("\n%s\n", rooms[7]->name.getstr());
				printf("%s\n", rooms[7]->description.getstr());
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n");
			return;
		}
	}

	//Gunsmith
	if (player->position == rooms[7])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			if (door[2]->Num_doors == 1){
				player->position = rooms[6];
				printf("\n%s\n", rooms[6]->name.getstr());
				printf("%s\n", rooms[6]->description.getstr());
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
	}

	//Aisle 2
	if (player->position == rooms[8])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There are stairs that go up.\n");
			return;
		}
		if (comand == "go u" || comand == "go up")
		{		
			exit[11]->discover = 1;
			player->position = rooms[11];
			printf("\n%s\n", rooms[11]->name.getstr());
			printf("%s\n", rooms[11]->description.getstr());
			return;
		}

		else if (comand == "go w" || comand == "go west")
		{
			player->position = rooms[1];
			printf("\n%s\n", (rooms[1]->name));
			printf("%s\n", (rooms[1]->description));
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			exit[9]->discover = 1;
			player->position = rooms[9];
			printf("\n%s\n", rooms[9]->name.getstr());
			printf("%s\n", rooms[9]->description.getstr());
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n");
			return;
		}
	}

	//Hall
	if (player->position == rooms[9])
	{
		if (comand == "go n" || comand == "go north")
		{
			player->position = rooms[8];
			printf("\n%s\n", rooms[8]->name.getstr());
			printf("%s\n", rooms[8]->description.getstr());
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			if (door[3]->Num_doors == 1)
			{
				exit[10]->discover = 1;
				player->position = rooms[10];
				printf("\n%s\n", rooms[10]->name.getstr());
				printf("%s\n", rooms[10]->description.getstr());
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
	}

	//Exit
	if (player->position == rooms[10])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("This is Exit!\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			if (door[3]->Num_doors == 1){
				player->position = rooms[9];
				printf("\n%s\n", rooms[9]->name.getstr());
				printf("%s\n", rooms[9]->description.getstr());
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("This is Exit!\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("This is Exit!\n");
			return;
		}
	}

	//Aisle 3
	if (player->position == rooms[11])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There are stairs that go down.\n");
			return;
		}
		if (comand == "go d" || comand == "go down")
		{
			player->position = rooms[8];
			printf("\n%s\n", rooms[8]->name.getstr());
			printf("%s\n", rooms[8]->description.getstr());
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			if (door[4]->Num_doors == 1)
			{
				exit[12]->discover = 1;
				player->position = rooms[12];
				printf("\n%s\n", rooms[12]->name.getstr());
				printf("%s\n", rooms[12]->description.getstr());
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n");
			return;
		}
	}

	//Laboratory
	if (player->position == rooms[12])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			if (door[4]->Num_doors == 1){
				player->position = rooms[11];
				printf("\n%s\n", rooms[11]->name.getstr());
				printf("%s\n", rooms[11]->description.getstr());
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
	if (comand == "open door n" || comand == "open door north")
	{
		if (player->position == rooms[1])
		{
			if (item[3]->link == item[13]->link)
			{
				if (door[0]->Num_doors == 1){
					printf("The door was already open.\n\n");
				}
				else{
					door[0]->Num_doors = 1;
					printf("The door is already open.\n\n");
				}
			}
			else
			{
				printf("First you need to unlock! Uses a key or something.\n\n");
			}
		}
		else if (player->position == rooms[4])
		{
			if (item[6]->link == item[14]->link)
			{
				if (door[1]->Num_doors == 1){
					printf("The door was already open.\n\n");
				}
				else{
					door[1]->Num_doors = 1;
					printf("The door is already open.\n\n");
				}
			}
			else
			{
				printf("First you need to unlock! Uses a key or something.\n\n");
			}
		}
		else{
			printf("In this direction there isn't door.\n\n");
		}
	}
	if (comand == "open door west" || comand == "open door w")
	{
		if (player->position == rooms[6])
		{
			if (item[4]->link == item[15]->link)
			{
				if (door[2]->Num_doors == 1){
					printf("The door was already open.\n\n");
				}
				else{
					door[2]->Num_doors = 1;
					printf("The door is already open.\n\n");
				}
			}
			else
			{
				printf("First you need to unlock! Uses a key or something.\n\n");
			}
		}
		else if (player->position == rooms[11])
		{
			if (item[2]->link == item[12]->link)
			{
				if (door[4]->Num_doors == 1){
					printf("The door was already open.\n\n");
				}
				else{
					door[4]->Num_doors = 1;
					printf("The door is already open.\n\n");
				}
			}
			else
			{
				printf("First you need to unlock! Uses a key or something.\n\n");
			}
		}
		else if (player->position == rooms[10])
		{
			if (item[6]->link == item[13]->link)
			{
				if (door[3]->Num_doors == 1){
					printf("The door was already open.\n\n");
				}
				else{
					door[3]->Num_doors = 1;
					printf("The door is already open.\n\n");
				}
			}
			else
			{
				printf("First you need to unlock! Uses a key or something.\n\n");
			}
		}
		else{
			printf("In this direction there isn't door.\n\n");
		}
	}
	if (comand == "open door south" || comand == "open door s" )
	{
		if (player->position == rooms[2])
		{
			if (door[0]->Num_doors == 1){
				printf("The door was already open.\n\n");
			}
			else{
				door[0]->Num_doors = 1;
				printf("The door is already open.\n");
			}
		}
		else if (player->position == rooms[5])
		{
			if (door[1]->Num_doors == 1){
				printf("The door was already open.\n");
			}
			else{
				door[1]->Num_doors = 1;
				printf("The door is already open.\n");
			}
		}
		else{
			printf("In this direction there isn't door.\n");
		}
	}
	if (comand == "open door south" || comand == "open door s")
	{
		if (player->position == rooms[7])
		{
			if (door[2]->Num_doors == 1){
				printf("The door was already open.\n");
			}
			else{
				door[2]->Num_doors = 1;
				printf("The door is already open.\n");
			}
		}
		else if (player->position == rooms[9])
		{
			if (door[3]->Num_doors == 1){
				printf("The door was already open.\n");
			}
			else{
				door[3]->Num_doors = 1;
				printf("The door is already open.\n");
			}
		}
		else if (player->position == rooms[12])
		{
			if (door[4]->Num_doors == 1){
				printf("The door was already open.\n");
			}
			else{
				door[4]->Num_doors = 1;
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
	if (comand =="close door north" || comand == "close door n")
	{
		if (player->position == rooms[1])
		{
			if (door[0]->Num_doors == 0){
				printf("The door was already closed.\n");
			}
			else{
				door[0]->Num_doors = 0;
				printf("The door is already close.\n");
			}

		}
		else if (player->position == rooms[4])
		{
			if (door[1]->Num_doors == 0){
				printf("The door was already closed.\n");
			}
			else{
				door[1]->Num_doors = 0;
				printf("The door is already close.\n");
			}
		}
		else{
			printf("In this direction there isn't door.\n");
		}
	}
	if (comand == "close door west" || comand == "close door w")
	{
		if (player->position == rooms[10])
		{
			if (door[3]->Num_doors == 0){
				printf("The door was already closed.\n");
			}
			else{
				door[3]->Num_doors = 0;
				printf("The door is already close.\n");
			}

		}
		else if (player->position == rooms[6])
		{
			if (door[2]->Num_doors == 0){
				printf("The door was already closed.\n");
			}
			else{
				door[2]->Num_doors = 0;
				printf("The door is already close.\n");
			}
		}
		else if (player->position == rooms[11])
		{
			if (door[4]->Num_doors == 0){
				printf("The door was already closed.\n");
			}
			else{
				door[4]->Num_doors = 0;
				printf("The door is already close.\n");
			}
		}
		else{
			printf("In this direction there isn't door.\n");
		}
	}
	if (comand == "close door south"|| comand == "close door s")
	{
		if (player->position == rooms[2])
		{
			if (door[0]->Num_doors == 0){
				printf("The door was already closed.\n");
			}
			else{
				door[0]->Num_doors = 0;
				printf("The door is already close.\n");
			}

		}
		else if (player->position == rooms[5])
		{
			if (door[1]->Num_doors == 0){
				printf("The door was already closed.\n");
			}
			else{
				door[1]->Num_doors = 0;
				printf("The door is already close.\n");
			}
		}
		else{
			printf("In this direction there isn't door.\n");
		}
	}
	if (comand == "close door south" || comand == "close door s")
	{
		if (player->position == rooms[7])
		{
			if (door[2]->Num_doors == 0){
				printf("The door was already closed.\n");
			}
			else{
				door[2]->Num_doors = 0;
				printf("The door is already close.\n");
			}

		}
		else if (player->position == rooms[12])
		{
			if (door[4]->Num_doors == 0){
				printf("The door was already closed.\n");
			}
			else{
				door[4]->Num_doors = 0;
				printf("The door is already close.\n");
			}
		}
		else if (player->position == rooms[9])
		{
			if (door[3]->Num_doors == 0){
				printf("The door was already closed.\n");
			}
			else{
				door[3]->Num_doors = 0;
				printf("The door is already close.\n");
			}
		}
		else{
			printf("In this direction there isn't door.\n");
		}
	}
}

void World::Look()const{

	int conti = 0, conto = 0;
	for (int i = 0; i < NUM_ROOMS; i++)
	{
		if (player->position == rooms[i])
		{
			printf("%s", rooms[i]->name.getstr());
			printf("%s", rooms[i]->description.getstr());


			for (int j = 0; j < NUM_ITEMS; j++)
			{
				if (item[j]->link == rooms[i] && item[j]->istatus == false && item[j]->object == false)
				{
					conti++;
				}
			}
			if (conti > 0)
			{
				printf("Items in this room:\n");
			}

			for (int j = 0; j < NUM_ITEMS; j++)
			{
				if (item[j]->link == rooms[i] && item[j]->istatus == false && item[j]->object == false && item[j]->isinside == false)
				{
					printf("- %s\n", item[j]->name.getstr());
				}
			}

			for (int z = 0; z < NUM_ITEMS; z++)
			{
				if (item[z]->link == rooms[i] && item[z]->object == true)
				{
					conto++;
				}
			}
			if (conto > 0)
			{
				printf("Objects in this room:\n");
			}
			for (int j = 0; j < NUM_ITEMS; j++)
			{
				if (item[j]->link == rooms[i] && item[j]->object == true)
				{
					printf("- %s\n", item[j]->name.getstr());
				}
			}
		}
	}
}

void World::Look_inventory() const
{
	if (item[0]->istatus == true)
	{
		printf("You have these items:\n");
		for (int i = 0; i < NUM_ITEMS; i++)
		{
			if (item[i+1]->istatus == true && item[i+1]->equiped == false && item[i+1]->object == false)
			{
				printf("- %s\n", item[i+1]->name.getstr());
				return;
			}
			else
			{
				printf("\n");
				return;
			}
		}
	}
	else
	{
		printf("Sorry you don't have inventory!\n");
		printf("First you need a bag to look inventory!!!\n");
		return;
	}
}

void World::Look_item(Vector<ClString> &comand)const
{
	int cont = 0;
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (item[i]->name == comand[1] && item[i]->link == player->position)
		{
			if (item[i]->istatus == true && item[i]->isinside == false || item[i]->istatus == false && item[i]->isinside == false
				|| item[i]->equiped == true)
			{
				printf("- %s\n", item[i]->name.getstr());
				printf("%s\n", item[i]->description.getstr());
			}
			if (item[i]->object == true )
			{
				printf("Inside there: \n");
				for (int i = 0; i < NUM_ITEMS; i++)
				{
					if (item[i]->link == player->position && item[i]->isinside == true)
					{
						printf("%s\n", item[i]->name.getstr());
					}
				}
				printf("\n");
				return;
			}
		}
	}
}

void World::Look_Specify_Position() const
{
	//Main Room
	if (player->position == rooms[0])
	{
		if (comand == "look n" || comand == "look north")
		{
			if (exit[1]->discover == 1)
			{
				printf("%s\n", exit[1]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}

		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
	}

	//Ailse
	if (player->position == rooms[1])
	{
		if (comand == "look n" || comand == "look north")
		{
			if (exit[2]->discover == 1)
			{
				printf("%s\n", exit[2]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[3]->discover == 1)
			{
				printf("%s\n", exit[3]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[0]->discover == 1)
			{
				printf("%s\n", exit[0]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[8]->discover == 1)
			{
				printf("%s\n", exit[8]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}

	}

	//Dressing Room
	if (player->position == rooms[2])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if(comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[1]->discover == 1)
			{
				printf("%s\n", exit[1]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
	}

	//Office Room
	if (player->position == rooms[3])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[4]->discover == 1)
			{
				printf("%s\n", exit[4]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[6]->discover == 1)
			{
				printf("%s\n", exit[6]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[1]->discover == 1)
			{
				printf("%s\n", exit[1]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
	}

	//Mystery Room (alien-room)
	if (player->position == rooms[4])
	{
		if (comand == "look n" || comand == "look north")
		{
			if (exit[5]->discover == 1)
			{
				printf("%s\n", exit[5]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[3]->discover == 1)
			{
				printf("%s\n", exit[3]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
	}

	//Warehouse
	if (player->position == rooms[5])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if(comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[4]->discover == 1)
			{
				printf("%s\n", exit[4]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		printf("There is a Wall.\n");
	}

	//Warehouse 2
	if (player->position == rooms[6])
	{
		if (comand == "look n" || comand == "look north")
		{
			if (exit[3]->discover == 1)
			{
				printf("%s\n", exit[3]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[7]->discover == 1)
			{
				printf("%s\n", exit[7]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
	}

	//Gunsmith
	if (player->position == rooms[7])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[6]->discover == 1)
			{
				printf("%s\n", exit[6]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
	}

	//Ailse 2
	if (player->position == rooms[8])
	{
		if (comand == "look n" || comand == "look north")
		{
			if (exit[11]->discover == 1)
			{
				printf("%s\n", exit[11]->description.getstr());
			}
			else
			{
				printf("There are stairs that go up and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[1]->discover == 1)
			{
				printf("%s\n", exit[1]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[9]->discover == 1)
			{
				printf("%s\n", exit[9]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
	}

	//Hall
	if (player->position == rooms[9])
	{
		if (comand == "look n" || comand == "look north")
		{
			if (exit[8]->discover == 1)
			{
				printf("%s\n", exit[8]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[10]->discover == 1)
			{
				printf("%s\n", exit[10]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
	}

	//Exit
	if (player->position == rooms[10])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("There is a Exit.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[9]->discover == 1)
			{
				printf("%s\n", exit[9]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Exit.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Exit.\n");
		}
	}

	//Ailse 3
	if (player->position == rooms[11])
	{
		if (comand == "look n" || comand == "look north")
		{
			if (exit[8]->discover == 1)
			{
				printf("%s\n", exit[8]->description.getstr());
			}
			else
			{
				printf("There are stairs that go up and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[12]->discover == 1)
			{
				printf("%s\n", exit[12]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n");
			}
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
	}

	//Laboratory
	if (player->position == rooms[12])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n");
		}
		else if (comand == "look n" || comand == "look north")
		{
			if (exit[11]->discover == 1)
			{
				printf("%s\n", exit[11]->description.getstr());
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

void World::Pick_item(Vector<ClString> &comand)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (player->position == item[i]->link && item[i]->istatus == false && item[i]->name == comand[1] && item[i]->object == false && item[i]->isinside == false)
		{
			item[i]->istatus = true;
			if (item[0]->istatus == true)
			{
				printf("You picked-> %s\n\n", item[i]->name.getstr());
				return;
			}
			else if (item[0]->istatus == false)
			{
				printf("First you need a bag to pick items!!!\n\n");
				item[i]->istatus = false;
				return;
			}
		}
	}
	printf("In this room, there are no items with that name.\n\n");
	return;
}

void World::Drop_item(Vector<ClString> &comand)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (item[i]->istatus == true && item[i]->name == comand[1] && item[i]->object == false && item[i]->equiped == false)
		{
			item[i]->istatus = false;
			item[i]->link = player->position;
			printf("You dropped-> %s\n\n", item[i]->name.getstr());
			return;
		}
		else if (item[i]->equiped == true)
		{
			printf("You can't drop an equiped item!\n\n");
			return;
		}
	}
	printf("You dont have any object with this name!\n\n");
	return;
}

void World::Equip(Vector<ClString> &comand)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (item[i]->istatus == true && item[i]->name == comand[1] && item[i]->object == false && item[i]->equiped == false)
		{
			item[i]->equiped = true;

			if (item[6]->name == comand[1])
			{
				player->attack += item[6]->attack;
				printf("You equiped-> %s\n\n", item[6]->name.getstr());
				return;
			}
			else if (item[9]->name == comand[1])
			{
				player->hp += item[9]->hp;
				player->attack += item[9]->attack;
				printf("You equiped-> %s\n\n", item[9]->name.getstr());
				return;
			}
			else if (item[7]->name == comand[1])
			{
				if (item[6]->equiped == true)
				{
					player->attack += item[7]->attack;
					printf("You equiped-> %s\n\n", item[7]->name.getstr());
					return;
				}
				printf("You can not equip <Ammo> pack, first you need a gun!\n\n");
				item[i]->equiped = false;
				return;
			}
			else
			{
				printf("You can't equip -> %s\n\n", item[i]->name.getstr());
				item[i]->equiped = false;
				return;
			}
		}
	}
	printf("You can't equip this item with this name!\n\n");
	return;
}

void World::UnEquip(Vector<ClString> &comand)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (item[i]->istatus == true && item[i]->name == comand[1] && item[i]->object == false && item[i]->equiped == true)
		{
			item[i]->equiped = false;
			if (item[6]->name == comand[1])
			{
				player->hp -= item[6]->hp;
				player->attack -= item[6]->attack;
				printf("You unequiped-> %s\n", item[6]->name.getstr());
				return;
			}
			else if (item[9]->name == comand[1])
			{
				player->hp -= item[9]->hp;
				player->attack -= item[9]->attack;
				printf("You unequiped-> %s\n", item[9]->name.getstr());
				return;
			}
			else
			{
				printf("You can't UnEquip -> %s\n", item[i]->name.getstr());
				item[i]->equiped = true;
				return;
			}
		}
	}
	printf("You can't unequip this item with this name or you don't have equiped this item!\n");
	return;
}

void World::Stats()const
{
	printf("----------\n");
	printf("HP:     %i\n", player->hp);
	printf("ATTACK: %i\n", player->attack);
	printf("----------\n");
}

void World::Put_into(Vector<ClString> &comand_tok)
{
	for (int i = 0; i < NUM_ITEMS; i++)//put [item]
	{
		if (item[i]->istatus == true && item[i]->equiped == false && item[i]->name == comand_tok[1])
		{
			for (int j = 0; j < NUM_ITEMS; j++)//into [item]
			{
				if (player->position == item[j]->link && item[j]->object == true && item[j]->name == comand_tok[3])
				{
					item[i]->isinside = true;
					item[i]->link = item[j]->link;
					item[i]->istatus = false;
					printf("You put %s into %s!\n\n", item[i]->name.getstr(), item[j]->name.getstr());
					return;
				}
				else if (item[j]->link != player->position && comand_tok[3] == item[j]->name)
				{
					printf("There is no item here by that name!\n\n");
					return;
				}
			}
		}
		else if (item[i]->equiped == true && comand_tok[1] == item[i]->name)
		{
			printf("You can not put this item, first unequip item!\n\n");
			return;
		}
	}
}

void World::Get_from(Vector<ClString> &comand_tok)
{
	for (int i = 0; i < NUM_ITEMS; i++)//put [item]
	{
		if (item[i]->istatus == false && item[i]->name == comand_tok[1] && item[i]->isinside == true)
		{
			for (int j = 0; j < NUM_ITEMS; j++)//into [item]
			{
				if (player->position == item[j]->link && item[j]->object == true && item[j]->name == comand_tok[3] && item[i]->link == item[j]->link)
				{
					item[i]->isinside = false;
					item[i]->istatus = true;
					printf("You get %s from %s!\n\n", item[i]->name.getstr(), item[j]->name.getstr());
					return;
				}
				else if (item[j]->link != player->position && comand_tok[3] == item[j]->name)
				{
					printf("There is no item here by that name!\n\n");
					return;
				}
			}
		}
		else if (item[i]->equiped == true && comand_tok[1] == item[i]->name)
		{
			printf("You can not get this item, first unequip item!\n\n");
			return;
		}
		else if (item[0]->istatus == false && comand_tok[1] == item[i+1]->name)
		{
			printf("You can not get this item because you do not have a bag!\n\n");
			return;
		}
	}
}

