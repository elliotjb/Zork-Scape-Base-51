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

using namespace std;



World::World()
{
}

World::~World()
{

}

void World::Create_World(){

	//Create Player


	//Create Rooms
	Room* MainRoom;//0
	Room* Aisle;//1...
	Room* DressingRoom;
	Room* OfficeRoom;
	Room* MysteryRoom;
	Room* Warehouse;
	Room* Warehouse2;
	Room* Gunsmith;
	Room* Aisle2;
	Room* Hall;
	Room* ExitRoom;
	Room* Aisle3;
	Room* Laboratory;

	//my_entities[0]
	my_entities.push_back(MainRoom = new Room("MAIN ROOM", "It is a small room with a table and chairs middle and one exit north", ROOM));
	
	//my_entities[1]
	my_entities.push_back(Aisle = new Room("SMALL AISLE", "It is small and with 3 outputs without why we have entered. To the north there is a door with a sign, it says: 'Dressing Room'", ROOM));
	
	//my_entities[2]
	my_entities.push_back(DressingRoom = new Room("DRESSING ROOM", "There are many lockers, you can see that there is an open locker", ROOM));
	
	//my_entities[3]
	my_entities.push_back(OfficeRoom = new Room("OFFICE ROOM", "It is a small room with a few tables working, there are 2 exits", ROOM));
	
	//my_entities[4]
	my_entities.push_back(MysteryRoom = new Room("MYSTERY ROOM", "It is a very large room with a giant cage, there seems to be something inside and the door is open.\nThere is a door to the north.", ROOM));
	
	//my_entities[5]
	my_entities.push_back(Warehouse = new Room("WAREHOUSE 1", "It is a normal warehouse, you can see a safe and it's open", ROOM));
	
	//my_entities[6]
	my_entities.push_back(Warehouse2 = new Room("WAREHOUSR 2", "It looks like a warehouse or I think, but there are not many things. There is a door to the west.", ROOM));
	
	//my_entities[7]
	my_entities.push_back(Gunsmith = new Room("GUNSMITH", "Is huge there are many boxes with weapons, there is an armory and is open", ROOM));
	
	//my_entities[8]
	my_entities.push_back(Aisle2 = new Room("AISLE 2", "It is normal in low light but enough to see everything hall.\nTo the north there are stairs going up and there is an exit south", ROOM));
	
	//my_entities[9]
	my_entities.push_back(Hall = new Room("HALL", "Beside this departure, and I almost get it! To the east is a keyboard to enter a key, surely this I will pull through. (Not implemented yet)", ROOM));
	
	//my_entities[10]
	my_entities.push_back(ExitRoom = new Room("THE EXIT", "These outside the building, no one is around, it seems as if the base was abandoned", ROOM));
	
	//my_entities[11]
	my_entities.push_back(Aisle3 = new Room("AILSE 3", "To the north there is a staircase going down and east have a door, you can put a card into the scanner", ROOM));
	
	//my_entities[12]
	my_entities.push_back(Laboratory = new Room("LABORATORY", "It is a research laboratory, it appears that all the material is new. In front there is a table with papers", ROOM));


	//Create EXITS
	//my_entities[13] - EXITS FROM MAIN ROOM
	my_entities.push_back(new Exits("Exit to AILSE 1.\n", "The next room is the AILSE.\n", EXIT, false, MainRoom, Aisle, 0));

	//my_entities[14] - EXITS FROM AILSE
	my_entities.push_back(new Exits("Exit to MAIN ROOM.\n", "The next room is the MAIN ROOM\n", EXIT, false, Aisle, MainRoom, 2));
	//my_entities[15] - EXITS FROM AILSE
	my_entities.push_back(new Exits("Exit to DRESSING ROOM.\n", "The next room is the DRESSING ROOM\n", EXIT, false, Aisle, DressingRoom, 0));
	//my_entities[16] - EXITS FROM AILSE
	my_entities.push_back(new Exits("Exit to OFFICE ROOM.\n", "The next room is the OFFICE ROOM\n", EXIT, false, Aisle, OfficeRoom, 1));
	//my_entities[17] - EXITS FROM AILSE
	my_entities.push_back(new Exits("Exit to AILSE 2.\n", "The next room is the AILSE 2\n", EXIT, false, Aisle, Aisle2, 3));

	//my_entities[18] - EXITS FROM DRESSING ROOM
	my_entities.push_back(new Exits("Exit to AILSE 1.\n", "The next room is the Aisle.\n", EXIT, false, DressingRoom, Aisle, 2));

	//my_entities[19] - EXITS FROM OFFICE ROOM
	my_entities.push_back(new Exits("Exit to MYSTERY ROOM.\n", "The next room is the MYSTERY ROOM.\n", EXIT, false, OfficeRoom, MysteryRoom, 1));
	//my_entities[20] - EXITS FROM OFFICE ROOM
	my_entities.push_back(new Exits("Exit to WAREHOUSE 2.\n", "The next room is the WAREHOUSE 2.\n", EXIT, false, OfficeRoom, Warehouse2, 2));
	//my_entities[21] - EXITS FROM OFFICE ROOM
	my_entities.push_back(new Exits("Exit to AILSE 1.\n", "The next room is the AILSE 1.\n", EXIT, false, OfficeRoom, Aisle, 3));
	
	//my_entities[22] - EXITS FROM MYSTERY ROOM
	my_entities.push_back(new Exits("Exit to DRESSING ROOM.\n", "The next room is the DRESSING ROOM.\n", EXIT, false, MysteryRoom, DressingRoom, 3));
	//my_entities[23] - EXITS FROM MYSTERY ROOM
	my_entities.push_back(new Exits("Exit to WAREHOUSE.\n", "The next room is the WAREHOUSE.\n", EXIT, false, MysteryRoom, Warehouse, 0));
	
	//my_entities[24] - EXITS FROM WAREHOUSE
	my_entities.push_back(new Exits("Exit to MYSTERY ROOM.\n", "The next room is the MYSTERY ROOM.\n", EXIT, false, Warehouse, MysteryRoom, 2));
	
	//my_entities[25] - EXITS FROM WAREHOUSE 2
	my_entities.push_back(new Exits("Exit to OFFICE ROOM.\n", "The next room is the OFFICE ROOM.\n", EXIT, false, Warehouse2, OfficeRoom, 0));
	//my_entities[26] - EXITS FROM WAREHOUSE 2
	my_entities.push_back(new Exits("Exit to GUNSMITH.\n", "The next room is the GUNSMITH.\n", EXIT, false, Warehouse2, Gunsmith, 1));
	
	//my_entities[27] - EXITS FROM GUNSMITH
	my_entities.push_back(new Exits("Exit to WAREHOUSE 2.\n", "The next room is the WAREHOUSE 2.\n", EXIT, false, Gunsmith, Warehouse2, 3));
	
	//my_entities[28] - EXITS FROM AILSE 2
	my_entities.push_back(new Exits("Exit to AISLE 3.\n", "The next room is the AISLE 3.\n", EXIT, false, Aisle2, Aisle3, 0));
	//my_entities[29] - EXITS FROM AILSE 2
	my_entities.push_back(new Exits("Exit to AISLE.\n", "The next room is the AISLE.\n", EXIT, false, Aisle2, Aisle, 1));
	//my_entities[30] - EXITS FROM AILSE 2
	my_entities.push_back(new Exits("Exit to HALL.\n", "The next room is the HALL.\n", EXIT, false, Aisle2, Hall, 2));
	
	//my_entities[31] - EXITS FROM HALL
	my_entities.push_back(new Exits("Exit to AISLE 2.\n", "The next room is the AISLE 2.\n", EXIT, false, Hall, Aisle2, 0));
	//my_entities[32] - EXITS FROM HALL
	my_entities.push_back(new Exits("Exit to EXIT.\n", "The next room is the EXIT.\n", EXIT, false, Hall, ExitRoom, 3));
	
	//my_entities[33] - EXITS FROM EXITROOM
	my_entities.push_back(new Exits("Exit to HALL.\n", "The next room is the HALL.\n", EXIT, false, ExitRoom, Hall, 1));
	
	//my_entities[34] - EXITS FROM AILSE 3
	my_entities.push_back(new Exits("Exit to AISLE 2.\n", "The next room is the AISLE 2.\n", EXIT, false, Aisle3, Aisle2, 2));
	//my_entities[35] - EXITS FROM AILSE 3
	my_entities.push_back(new Exits("Exit to LABORATORY.\n", "The next room is the LABORATORY.\n", EXIT, false, Aisle3, Laboratory, 1));
	
	//my_entities[36] - EXITS FROM LABORATORY
	my_entities.push_back(new Exits("Exit to AISLE 3.\n", "The next room is the AISLE 3.\n", EXIT, false, Laboratory, Aisle3, 3));
	
	//Create Doors
	door.push_back(new Door(0));
	door.push_back(new Door(0));
	door.push_back(new Door(0));
	door.push_back(new Door(0));
	door.push_back(new Door(0));

	//PLAYER

	//my_entities[26]
	my_entities.push_back(new Player("Elliot", "I'm a strong", PLAYER, 1, 0, 0));
	player->position = MainRoom;

	//ITEMS

	//my_entities[25]
	my_entities.push_back(new Item("bag", "It is a military backpack brown and is quite large\n", ITEM, MainRoom, false, false, false, false, 0, 0, 100));

	//my_entities[26]
	my_entities.push_back(new Item("lantern", "It is a lantern of those that are small but more light than the sun\n", ITEM, MainRoom, false, false, false, false, 0, 0, 10));//item[1], 

	//my_entities[27]
	my_entities.push_back(new Item("card", "It looks like a card to pass a security check, it may be useful\n", ITEM, Warehouse, false, false, false, false, 0, 0, 50));//item[2], 

	//my_entities[28]
	my_entities.push_back(new Item("lockpick", "It can be useful to open doors, thank god know how to use it\n", ITEM, OfficeRoom, false, false, false, false, 0, 0, 1));//item[3], 

	//my_entities[29]
	my_entities.push_back(new Item("key", "It is a normal key, with a label that puts armory\n", ITEM, DressingRoom, false, false, false, false, 0, 0, 10));//item[4], 

	//my_entities[30]
	my_entities.push_back(new Item("paper", "It is a small role. It has written a command: 'SZKMS'\n", ITEM, Laboratory, false, false, false, false, 0, 0, 100));//item[5], 12

	//my_entities[31]
	my_entities.push_back(new Item("gun", "It is a M4A1-S, it is one of my favorite weapons\n", ITEM, Gunsmith, false, false, false, false, 0, 5, 100));//item[6], 

	//my_entities[32]
	my_entities.push_back(new Item("ammo", "It is a ammo pack, but only has 10 bullets\n", ITEM, Gunsmith, false, false, false, false, 0, 45, 10));//item[7], 

	//my_entities[33]
	my_entities.push_back(new Item("camera", "Oh my camera, finally I ever have\n", ITEM, Warehouse, false, false, false, false, 0, 0, 100));//item[8], 5

	//my_entities[34]
	my_entities.push_back(new Item("vest", "It's a bulletproof vest might be useful.\n", ITEM, DressingRoom, false, false, false, false, 100, 0, 10));//item[9], 

	//my_entities[35]
	my_entities.push_back(new Item("safe", "It is safe, it seems that this open\n", ITEM, Warehouse, false, true, false, false, 0, 0, 15));//item[10], 

	//my_entities[36]
	my_entities.push_back(new Item("reader", "It seems that putting a password the door opened (no implemented yet)\n", ITEM, Hall, false, true, false, false, 0, 0, 0));//item[11], 

	//my_entities[37]
	my_entities.push_back(new Item("scanner", "It is a card reader, if I put a card surely will open\n", ITEM, Aisle3, false, true, false, false, 0, 0, 0));//item[12], to open door of laboratory

	//my_entities[38]
	my_entities.push_back(new Item("lock", "I think that i can force the lock with a lockpick would get it\n", ITEM, Aisle, false, true, false, false, 0, 0, 0));//item[13], 

	//my_entities[39]
	my_entities.push_back(new Item("padlock", "It's a big padlock, I think that I need something more than a lockpick, I could use the gun\n", ITEM, MysteryRoom, false, true, false, false, 0, 0, 0));//item[14], Candado

	//my_entities[40]
	my_entities.push_back(new Item("deadbolt", "This lock is special, I only can open with a key\n", ITEM, Warehouse2, false, true, false, false, 0, 0, 0));//item[15], 

	//my_entities[41]
	my_entities.push_back(new Item("armory", "It's an armory, it seems that there is only one gun and ammo\n", ITEM, Gunsmith, false, true, false, false, 0, 0, 15));//item[16], 

	//my_entities[42]
	my_entities.push_back(new Item("locker", "It's a locker, I can keep things inside\n", ITEM, DressingRoom, false, true, false, false, 0, 0, 15));//item[17], 

}

void World::Input()
{
	do
	{
		printf("> ");
		gets_s(option, 80);
	} while (option == NULL);

}

void World::Set_Command()
{
	Input();
	comand = option;

	if (option[0] != NULL && option[0] != ' ')
	{
		Vector<ClString> comand_tok = comand.tokenize(option);
		acon_moviment++;
		//Command - Help
		if (comand_tok[0] == "help"){
			printf("Useful commands:\n\n");
			printf("-[go north] or [go n]\n-[go west] or [go w]\n-[go south] or [go s]\n-[go east] or [go e]\n");
			printf("-[go up] or [go u]\n-[go down] or [go d]\n");
			printf("-[look]\n");
			printf("-[look inventory] or [i] and diminutives\n");
			printf("-[look (item)]\n");
			printf("-[look (the same way as above)]\n");
			printf("-[open door]\n-[close door]\n");
			printf("-[pick (item)]\n-[drop (item)]\n");
			printf("-[put (item) into (item)]\n-[get (item) from (item)]\n");
			printf("-[equip (item)] or [e (item)]\n-[unequip (item)] or [ue (item)]\n");
			printf("-[stats] or [st]\n");
			printf("-[quit]\n-[help]\n\n");
		}

		else if (comand == "pick" || comand == "p")
		{
			printf("Please, put pick [item]\n\n");
		}

		else if(comand_tok[0] == "pick" && option[4] == ' ' || comand_tok[0] == "p" && option[1] == ' '){
			Pick_item(comand_tok);
		}

		else if (comand == "drop" || comand == "d")
		{
			printf("Please, put drop [item]\n\n");
		}
		else if (comand_tok[0] == "drop" && option[4] == ' ' || comand_tok[0] == "d" && option[1] == ' '){
			Drop_item(comand_tok);
		}

		//Commands - Go
		else if (comand == "go"){
			printf("Where you want to go? [go north, go west, go south, go east]\n\n");
		}

		else if (comand == "go n" || comand == "go w" || comand == "go s" || comand == "go e" || comand == "go u" || comand == "go d"){
			Move();
		}
		else if (comand == "go north" || comand == "go westw" || comand == "go south" || comand == "go east" || comand == "go up" || comand == "go down"){
			Move();
		}

		//Comands - Open and Close
		else if (comand == "open"){
			printf("The command to open is [open door (direction) -> example: open door north]\n\n");
		}
		else if (comand == "close"){
			printf("The command to close is [close door (direction) -> example: close door north]\n\n");
		}

		//Open
		else if (comand == "open door" || comand == "open door n" || comand == "open door w" || comand == "open door s" || comand == "open door e"){
			Open();
		}
		else if (comand == "open door north" || comand == "open door west" || comand == "open door south" || comand == "open door east"){
			Open();
		}

		//Close
		else if (comand == "close door" || comand == "close door n" || comand == "close door w" || comand == "close door s" || comand == "close door e"){
			Close();
		}
		else if (comand == "close door north" || comand == "close door west" || comand == "close door south" || comand == "close door east"){
			Close();
		}

		//Command - Look
		else if (comand == "look"){
			Look();
			if (cont < 2){
				printf("If you want to specify where to look like this-> [ look north/n, look west/w, look south/s, look east/e ]\n\n");
				cont++;
			}
		}

		//Comand - look inventory
		else if (comand == "look inventory" || comand == "look inv" || comand == "look i"
			|| comand == "inventory" || comand == "inv" || comand == "i"){
			Look_inventory();
		}

		else if (comand_tok[0] == "look" && option[4] == ' ' && option[5] != '\0')
		{
			Look_item(comand_tok);
		}

		//Commands - Look Specify position
		else if (comand == "look n" || comand == "look w" || comand == "look s" || comand == "look e"){
			Look_Specify_Position();
		}
		else if (comand == "look north" || comand == "look west" || comand == "look south" || comand == "look east"){
			Look_Specify_Position();
		}

		//comands - equip
		else if (comand == "equip" || comand == "e")
		{
			printf("Please, write <equip [item]>\n\n");
		}

		else if (comand_tok[0] == "equip" && option[5] == ' ' || comand_tok[0] == "e" && option[1] == ' '){
			Equip(comand_tok);
		}

		//comands - uneequip
		else if (comand == "unequip" || comand == "ue")
		{
			printf("Please, write <drop [item]>\n\n");
		}

		else if (comand_tok[0] == "unequip" && option[7] == ' ' || comand_tok[0] == "ue" && option[2] == ' '){
			UnEquip(comand_tok);
		}

		//Comand - put
		else if (comand_tok[0] == "put" && option[4] != 'i')//TODO: Arreglar!
		{
			printf("Please, write <put [item] into [item]>\n\n");
		}

		else if (comand_tok[0] == "put" && comand_tok[2] == "into")//TODO: Arreglar!
		{
			Put_into(comand_tok);
		}

		//Comand - get
		else if (comand == "g" || comand == "get")//TODO: Arreglar!
		{
			printf("Please, write get [item] from [item]\n\n");
		}

		else if (comand_tok[0] == "get" && comand_tok[2] == "from")//TODO: Arreglar!
		{
			Get_from(comand_tok);
		}
		//Comand - stats

		else if (comand == "stats" || comand == "st")
		{
			Stats();
		}

		//Comand - Exit
		else if (comand == "quit" || comand == "q" || comand == "yes" && ((Exits*)my_entities[32])->discover == true ||
			comand == "y" && ((Exits*)my_entities[32])->discover == true){
			quit = 1;
			Exit_zork();
		}
		else
		{
			printf("I beg your pardon?\n\n");
		}
	}
	else
	{
	printf("I beg your pardon?\n\n");
	}
}

void World::Move()
{
	//NEW FUNCTION MOVE

}
	/*//Main Room
	if (player->position == rooms[0])
	{
		exit[0]->discover = 1;
		if (comand == "go n" || comand == "go north")
		{
			exit[1]->discover = 1;
			player->position = rooms[1];
			Look();
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n\n");
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
				Look();
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n\n");
			}
		}
		else if (comand == "go w" || comand == "go west")
		{
			exit[3]->discover = 1;
			player->position = rooms[3];
			Look();
			return;
		}
		if (comand == "go s" || comand == "go south")
		{
			player->position = rooms[0];
			Look();
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			exit[8]->discover = 1;
			player->position = rooms[8];
			Look();
			return;
		}
	}
	//Dressing Room
	if (player->position == rooms[2])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			if (door[0]->Num_doors == 1)
			{
				player->position = rooms[1];
				Look();
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n\n");
			}
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n\n");
			return;
		}
	}

	//Office Room
	if (player->position == rooms[3])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			exit[4]->discover = 1;
			player->position = rooms[4];
			Look();
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			exit[6]->discover = 1;
			player->position = rooms[6];
			Look();
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			player->position = rooms[1];
			Look();
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
				Look();
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n\n");
			}
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			player->position = rooms[3];
			Look();
			return;
		}
	}

	//Warehouse
	if (player->position == rooms[5])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			if (door[1]->Num_doors == 1){
				player->position = rooms[4];
				Look();
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n\n");
			}
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n\n");
			return;
		}
	}

	//Warehouse 2
	if (player->position == rooms[6])
	{
		if (comand == "go n" || comand == "go north")
		{
			player->position = rooms[3];
			Look();
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			if (door[2]->Num_doors == 1)
			{
				exit[7]->discover = 1;
				player->position = rooms[7];
				Look();
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n\n");
			}
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n\n");
			return;
		}
	}

	//Gunsmith
	if (player->position == rooms[7])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			if (door[2]->Num_doors == 1){
				player->position = rooms[6];
				Look();
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n\n");
			}
		}
	}

	//Aisle 2
	if (player->position == rooms[8])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There are stairs that go up.\n\n");
			return;
		}
		if (comand == "go u" || comand == "go up")
		{		
			exit[11]->discover = 1;
			player->position = rooms[11];
			Look();
			return;
		}

		else if (comand == "go w" || comand == "go west")
		{
			player->position = rooms[1];
			Look();
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			exit[9]->discover = 1;
			player->position = rooms[9];
			Look();
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n\n");
			return;
		}
	}

	//Hall
	if (player->position == rooms[9])
	{
		if (comand == "go n" || comand == "go north")
		{
			player->position = rooms[8];
			Look();
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			if (door[3]->Num_doors == 1)
			{
				if (item[8]->istatus == true)
				{
					exit[10]->discover = 1;
					player->position = rooms[10];
					Look();
					printf("Congratulations, you've got to leave the building.\n");
					printf("You want to leave the game? if you like to put [yes]\nif you want you can re-enter!!\n\n");
					return;
				}
				else{
					printf("WAIT! Before leaving I need the camera!\n\n");
					return;
				}

			}
			else{
				printf("You can't move, there is a front door and closed.\n\n");
			}
		}
	}

	//Exit
	if (player->position == rooms[10])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("You're out of the building, you want to leave the game?\n\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			if (door[3]->Num_doors == 1){
				player->position = rooms[9];
				Look();
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n\n");
			}
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("You're out of the building, you want to leave the game?\n\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("You're out of the building, you want to leave the game?\n\n");
			return;
		}
	}

	//Aisle 3
	if (player->position == rooms[11])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There are stairs that go down.\n\n");
			return;
		}
		if (comand == "go d" || comand == "go down")
		{
			player->position = rooms[8];
			Look();
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			if (door[4]->Num_doors == 1)
			{
				exit[12]->discover = 1;
				player->position = rooms[12];
				Look();
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n");
			}
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			printf("There is a wall!.\n\n");
			return;
		}
	}

	//Laboratory
	if (player->position == rooms[12])
	{
		if (comand == "go n" || comand == "go north")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go w" || comand == "go west")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go s" || comand == "go south")
		{
			printf("There is a wall!.\n\n");
			return;
		}
		else if (comand == "go e" || comand == "go east")
		{
			if (door[4]->Num_doors == 1){
				player->position = rooms[11];
				Look();
				return;
			}
			else{
				printf("You can't move, there is a front door and closed.\n\n");
			}
		}
	}
}*/

void World::Open()
{
	if (comand == "open door")
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
					printf("DOOR OPEN\n\n");
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
					printf("DOOR OPEN\n\n");
				}
			}
			else
			{
				printf("First you need to unlock! Uses a key or something.\n\n");
			}
		}
		else if (player->position == rooms[6])
		{
			if (item[4]->link == item[15]->link)
			{
				if (door[2]->Num_doors == 1){
					printf("The door was already open.\n\n");
				}
				else{
					door[2]->Num_doors = 1;
					printf("DOOR OPEN\n\n");
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
					printf("DOOR OPEN\n\n");
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
					printf("DOOR OPEN\n\n");
				}
			}
			else
			{
				printf("First you need to unlock! Uses a key or something.\n\n");
			}
		}
		else if (player->position == rooms[2])
		{
			if (door[0]->Num_doors == 1){
				printf("The door was already open.\n\n");
			}
			else{
				door[0]->Num_doors = 1;
				printf("DOOR OPEN\n\n");
			}
		}
		else if (player->position == rooms[5])
		{
			if (door[1]->Num_doors == 1){
				printf("The door was already open.\n");
			}
			else{
				door[1]->Num_doors = 1;
				printf("DOOR OPEN\n\n");
			}
		}
		else if (player->position == rooms[7])
		{
			if (door[2]->Num_doors == 1){
				printf("The door was already open.\n");
			}
			else{
				door[2]->Num_doors = 1;
				printf("DOOR OPEN\n\n");
			}
		}
		else if (player->position == rooms[9])
		{
			if (door[3]->Num_doors == 1){
				printf("The door was already open.\n");
			}
			else{
				door[3]->Num_doors = 1;
				printf("DOOR OPEN\n\n");
			}
		}
		else if (player->position == rooms[12])
		{
			if (door[4]->Num_doors == 1){
				printf("The door was already open.\n");
			}
			else{
				door[4]->Num_doors = 1;
				printf("DOOR OPEN\n\n");
			}
		}
		else if (player->position == rooms[0] || player->position == rooms[8] || player->position == rooms[3])
		{
			printf("Here there is no door\n\n");
		}
	}
}

void World::Close()
{
	if (comand == "close door")
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
		else if (player->position == rooms[10])
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
		else if (player->position == rooms[2])
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
		else if (player->position == rooms[0] || player->position == rooms[8] || player->position == rooms[3])
		{
			printf("Here there is no door\n\n");
		}
	}
}

void World::Look()const{

	int conti = 0, conto = 0;
	for (int i = 0; i < 13; i++)
	{
		if (player->position == rooms[i])
		{
			printf("%s\n", rooms[i]->name.getstr());
			printf("%s\n", rooms[i]->description.getstr());


			for (int j = 0; j < NUM_ITEMS; j++)
			{
				if (item[j]->link == rooms[i] && item[j]->istatus == false && item[j]->object == false && item[j]->isinside == false)
				{
					conti++;
				}
			}
			if (conti > 0)
			{
				printf("\nItems in this room:\n");
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
				printf("\nObjects in this room:\n");
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
	printf("\n");
}

void World::Look_inventory() const
{
	if (item[0]->istatus == true)
	{
		printf("You have these items:\n");
		for (int i = 1; i < NUM_ITEMS; i++)
		{
			if (item[i]->istatus == true && item[i]->equiped == false && item[i]->object == false)
			{
				printf("- %s\n", item[i]->name.getstr());
			}
		}
	}
	else
	{
		printf("Sorry you don't have inventory!\n");
		printf("First you need a bag to look inventory!!!\n");
	}
	printf("\n");
}

void World::Look_item(Vector<ClString> &comand)const
{
	int cont = 0;
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (item[i]->name == comand[1])
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
		else if (item[i]->name == comand[1] && item[i]->link != player->position)
		{
		}
	}
}

void World::Look_Specify_Position() const
{
	//Main Room
	if (player->position == (Room*)my_entities[0])
	{
		if (comand == "look n" || comand == "look north")
		{
			if ((Exits*)my_entities[0]->discover == 1)
			{
				printf("%s\n", exit[1]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}

		}
		else if (comand == "look w" || comand == "look west")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look s" || comand == "look south")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look e" || comand == "look east")
		{
			printf("There is a Wall.\n\n");
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
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look w" || comand == "look west")
		{
			if (exit[3]->discover == 1)
			{
				printf("%s\n", exit[3]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look s" || comand == "look south")
		{
			if (exit[0]->discover == 1)
			{
				printf("%s\n", exit[0]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look e" || comand == "look east")
		{
			if (exit[8]->discover == 1)
			{
				printf("%s\n", exit[8]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}

	}

	//Dressing Room
	if (player->position == rooms[2])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n\n");
		}
		else if(comand == "look w" || comand == "look west")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look s" || comand == "look south")
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
		else if (comand == "look e" || comand == "look east")
		{
			printf("There is a Wall.\n\n");
		}
	}

	//Office Room
	if (player->position == rooms[3])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look w" || comand == "look west")
		{
			if (exit[4]->discover == 1)
			{
				printf("%s\n", exit[4]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look s" || comand == "look south")
		{
			if (exit[6]->discover == 1)
			{
				printf("%s\n", exit[6]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look e" || comand == "look east")
		{
			if (exit[1]->discover == 1)
			{
				printf("%s\n", exit[1]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
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
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look w" || comand == "look west")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look s" || comand == "look south")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look e" || comand == "look east")
		{
			if (exit[3]->discover == 1)
			{
				printf("%s\n", exit[3]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
	}

	//Warehouse
	if (player->position == rooms[5])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n\n");
		}
		else if(comand == "look w" || comand == "look west")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look s" || comand == "look south")
		{
			if (exit[4]->discover == 1)
			{
				printf("%s\n", exit[4]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look e" || comand == "look east")
		{
			printf("There is a Wall.\n\n");
		}
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
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look w" || comand == "look west")
		{
			if (exit[7]->discover == 1)
			{
				printf("%s\n", exit[7]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look s" || comand == "look south")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look e" || comand == "look east")
		{
			printf("There is a Wall.\n\n");
		}
	}

	//Gunsmith
	if (player->position == rooms[7])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look w" || comand == "look west")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look s" || comand == "look south")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look e" || comand == "look east")
		{
			if (exit[6]->discover == 1)
			{
				printf("%s\n", exit[6]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
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
				printf("There are stairs that go up and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look w" || comand == "look west")
		{
			if (exit[1]->discover == 1)
			{
				printf("%s\n", exit[1]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look s" || comand == "look south")
		{
			if (exit[9]->discover == 1)
			{
				printf("%s\n", exit[9]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look e" || comand == "look east")
		{
			printf("There is a Wall.\n\n");
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
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look w" || comand == "look west")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look s" || comand == "look south")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look e" || comand == "look east")
		{
			if (exit[10]->discover == 1)
			{
				printf("%s\n", exit[10]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
	}

	//Exit
	if (player->position == rooms[10])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("No one outside the building where everyone is?\n\n");
		}
		else if (comand == "look w" || comand == "look west")
		{
			if (exit[9]->discover == 1)
			{
				printf("%s\n", exit[9]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look s" || comand == "look south")
		{
			printf("No one outside the building where everyone is?\n\n");
		}
		else if (comand == "look e" || comand == "look east")
		{
			printf("No one outside the building where everyone is?\n\n");
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
				printf("There are stairs that go up and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look w" || comand == "look west")
		{
			if (exit[12]->discover == 1)
			{
				printf("%s\n", exit[12]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
			}
		}
		else if (comand == "look s" || comand == "look south")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look e" || comand == "look east")
		{
			printf("There is a Wall.\n\n");
		}
	}

	//Laboratory
	if (player->position == rooms[12])
	{
		if (comand == "look n" || comand == "look north")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look w" || comand == "look west")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look s" || comand == "look south")
		{
			printf("There is a Wall.\n\n");
		}
		else if (comand == "look e" || comand == "look east")
		{
			if (exit[11]->discover == 1)
			{
				printf("%s\n", exit[11]->description.getstr());
			}
			else
			{
				printf("There is a door and that room has not been discovered yet.\n\n");
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
	printf("In this room, there are no ITEMS with that name.\n\n");
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
		if (item[i]->istatus == true)
		{
			if (item[i]->istatus == true && item[i]->equiped == false && item[i]->name == comand_tok[1])
			{
				for (int j = 0; j < NUM_ITEMS; j++)//into [item]
				{
					if (player->position == item[j]->link && item[j]->object == true && item[j]->name == comand_tok[3] && item[j]->durability > 2)
					{
						item[i]->isinside = true;
						item[i]->link = item[j]->link;
						item[i]->istatus = false;
						printf("You put %s into %s!\n\n", item[i]->name.getstr(), item[j]->name.getstr());
						return;
					}

					else if (player->position == item[j]->link && item[j]->object == true && item[j]->name == comand_tok[3] && item[j]->durability == 0)
					{
						if (item[j] == item[13])
						{
							if (item[i] == item[3])
							{
								item[j]->durability++;
								item[i]->isinside = true;
								item[i]->link = item[j]->link;
								item[i]->istatus = false;
								printf("You put %s into %s!\n", item[i]->name.getstr(), item[j]->name.getstr());
								printf("The door is unlocked\n\n");
								return;
							}
							else
							{
								printf("This is not the item to open the door.\n\n");
								return;
							}
						}
						else if (item[j] == item[14])
						{
							if (item[i] == item[6])
							{
								item[j]->durability++;
								item[i]->isinside = true;
								item[i]->link = item[j]->link;
								item[i]->istatus = false;
								printf("You put %s into %s!\n", item[i]->name.getstr(), item[j]->name.getstr());
								printf("The door is unlocked\n\n");
								return;
							}
							else
							{
								printf("This is not the item to open the door.\n\n");
								return;
							}

						}
						else if (item[j] == item[15])
						{
							if (item[i] == item[4])
							{
								item[j]->durability++;
								item[i]->isinside = true;
								item[i]->link = item[j]->link;
								item[i]->istatus = false;
								printf("You put %s into %s!\n", item[i]->name.getstr(), item[j]->name.getstr());
								printf("The door is unlocked\n\n");
								return;
							}
							else
							{
								printf("This is not the item to open the door.\n\n");
								return;
							}

						}
						else if (item[j] == item[12])
						{
							if (item[i] == item[2])
							{
								item[j]->durability++;
								item[i]->isinside = true;
								item[i]->link = item[j]->link;
								item[i]->istatus = false;
								printf("You put %s into %s!\n", item[i]->name.getstr(), item[j]->name.getstr());
								printf("The door is unlocked\n\n");
								return;
							}
							else
							{
								printf("This is not the item to open the door.\n\n");
								return;
							}

						}
						else if (item[j] == item[11])
						{
							if (item[i] == item[5])
							{
								item[j]->durability++;
								item[i]->isinside = true;
								item[i]->link = item[j]->link;
								item[i]->istatus = false;
								printf("You put %s into %s!\n", item[i]->name.getstr(), item[j]->name.getstr());
								printf("The door is unlocked\n\n");
								return;
							}
							else
							{
								printf("This is not the item to open the door.\n\n");
								return;
							}

						}

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
		if (i == 17)
		{
			printf("You do not have this item\n\n");
		}
	}
}

void World::Get_from(Vector<ClString> &comand_tok)
{
	for (int i = 0; i < NUM_ITEMS; i++)//get [item]
	{
		if (item[i]->istatus == false && item[i]->name == comand_tok[1] && item[i]->isinside == true)
		{
			for (int j = 0; j < NUM_ITEMS; j++)//from [item]
			{
				if (player->position == item[j]->link && item[j]->object == true && item[j]->name == comand_tok[3] && item[i]->link == item[j]->link && item[j]->durability > 2)
				{
					item[i]->isinside = false;
					item[i]->istatus = true;
					printf("You get %s from %s!\n\n", item[i]->name.getstr(), item[j]->name.getstr());
					return;
				}
				else if (player->position == item[j]->link && item[j]->object == true && item[j]->name == comand_tok[3] && item[i]->link == item[j]->link && item[j]->durability == 1)
				{
					item[j]->durability--;
					item[i]->isinside = false;
					item[i]->istatus = true;
					printf("You get %s from %s!\n\n", item[i]->name.getstr(), item[j]->name.getstr());
					return;
				}
				else if (item[j]->link != player->position && comand_tok[3] == item[j]->name && item[i]->link != item[j]->link)
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

