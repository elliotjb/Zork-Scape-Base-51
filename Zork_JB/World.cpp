#include <stdio.h>
#include <stdlib.h>
#include "World.h"



World::World()
{
}

World::~World()
{
	for (int i = 0; i < my_entities.size(); i++)
	{
		delete my_entities[i];
	}
}

void World::Create_World(){

	//Create Player


	//Create Rooms
	Room* MainRoom = new Room("MAIN ROOM", "It is a small room with a table and chairs middle and one exit north");//0
	Room* Aisle = new Room("SMALL AISLE", "It is small and with 3 outputs without why we have entered. To the north there is a door with a sign, it says: 'Dressing Room'");//1...
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
	my_entities.push_back(MainRoom);
	
	//my_entities[1]
	my_entities.push_back(Aisle);
	
	//my_entities[2]
	my_entities.push_back(DressingRoom = new Room("DRESSING ROOM", "There are many lockers, you can see that there is an open locker"));
	
	//my_entities[3]
	my_entities.push_back(OfficeRoom = new Room("OFFICE ROOM", "It is a small room with a few tables working, there are 2 exits"));
	
	//my_entities[4]
	my_entities.push_back(MysteryRoom = new Room("MYSTERY ROOM", "It is a very large room with a giant cage, there seems to be something inside and the door is open.\nThere is a door to the north."));
	
	//my_entities[5]
	my_entities.push_back(Warehouse = new Room("WAREHOUSE 1", "It is a normal warehouse, you can see a safe and it's open"));
	
	//my_entities[6]
	my_entities.push_back(Warehouse2 = new Room("WAREHOUSR 2", "It looks like a warehouse or I think, but there are not many things. There is a door to the west."));
	
	//my_entities[7]
	my_entities.push_back(Gunsmith = new Room("GUNSMITH", "Is huge there are many boxes with weapons, there is an armory and is open"));
	
	//my_entities[8]
	my_entities.push_back(Aisle2 = new Room("AISLE 2", "It is normal in low light but enough to see everything hall.\nTo the north there are stairs going up and there is an exit south"));
	
	//my_entities[9]
	my_entities.push_back(Hall = new Room("HALL", "Beside this departure, and I almost get it! To the east is a keyboard to enter a key, surely this I will pull through. (Not implemented yet)"));
	
	//my_entities[10]
	my_entities.push_back(ExitRoom = new Room("THE EXIT", "These outside the building, no one is around, it seems as if the base was abandoned"));
	
	//my_entities[11]
	my_entities.push_back(Aisle3 = new Room("AILSE 3", "To the north there is a staircase going down and east have a door, you can put a card into the scanner"));
	
	//my_entities[12]
	my_entities.push_back(Laboratory = new Room("LABORATORY", "It is a research laboratory, it appears that all the material is new. In front there is a table with papers"));


	//Create EXITS
	//my_entities[13] - EXITS FROM MAIN ROOM
	my_entities.push_back(new Exits("Exit to AILSE 1.\n", "The next room is the AILSE.\n", false, MainRoom, Aisle, 0));

	//my_entities[14] - EXITS FROM AILSE
	my_entities.push_back(new Exits("Exit to MAIN ROOM.\n", "The next room is the MAIN ROOM\n", false, Aisle, MainRoom, 2));
	//my_entities[15] - EXITS FROM AILSE
	my_entities.push_back(new Exits("Exit to DRESSING ROOM.\n", "The next room is the DRESSING ROOM\n", false, Aisle, DressingRoom, 0));
	//my_entities[16] - EXITS FROM AILSE
	my_entities.push_back(new Exits("Exit to OFFICE ROOM.\n", "The next room is the OFFICE ROOM\n", false, Aisle, OfficeRoom, 1));
	//my_entities[17] - EXITS FROM AILSE
	my_entities.push_back(new Exits("Exit to AILSE 2.\n", "The next room is the AILSE 2\n", false, Aisle, Aisle2, 3));

	//my_entities[18] - EXITS FROM DRESSING ROOM
	my_entities.push_back(new Exits("Exit to AILSE 1.\n", "The next room is the Aisle.\n", false, DressingRoom, Aisle, 2));

	//my_entities[19] - EXITS FROM OFFICE ROOM
	my_entities.push_back(new Exits("Exit to MYSTERY ROOM.\n", "The next room is the MYSTERY ROOM.\n", false, OfficeRoom, MysteryRoom, 1));
	//my_entities[20] - EXITS FROM OFFICE ROOM
	my_entities.push_back(new Exits("Exit to WAREHOUSE 2.\n", "The next room is the WAREHOUSE 2.\n", false, OfficeRoom, Warehouse2, 2));
	//my_entities[21] - EXITS FROM OFFICE ROOM
	my_entities.push_back(new Exits("Exit to AILSE 1.\n", "The next room is the AILSE 1.\n", false, OfficeRoom, Aisle, 3));
	
	//my_entities[22] - EXITS FROM MYSTERY ROOM
	my_entities.push_back(new Exits("Exit to DRESSING ROOM.\n", "The next room is the DRESSING ROOM.\n", false, MysteryRoom, DressingRoom, 3));
	//my_entities[23] - EXITS FROM MYSTERY ROOM
	my_entities.push_back(new Exits("Exit to WAREHOUSE.\n", "The next room is the WAREHOUSE.\n", false, MysteryRoom, Warehouse, 0));
	
	//my_entities[24] - EXITS FROM WAREHOUSE
	my_entities.push_back(new Exits("Exit to MYSTERY ROOM.\n", "The next room is the MYSTERY ROOM.\n", false, Warehouse, MysteryRoom, 2));
	
	//my_entities[25] - EXITS FROM WAREHOUSE 2
	my_entities.push_back(new Exits("Exit to OFFICE ROOM.\n", "The next room is the OFFICE ROOM.\n", false, Warehouse2, OfficeRoom, 0));
	//my_entities[26] - EXITS FROM WAREHOUSE 2
	my_entities.push_back(new Exits("Exit to GUNSMITH.\n", "The next room is the GUNSMITH.\n", false, Warehouse2, Gunsmith, 1));
	
	//my_entities[27] - EXITS FROM GUNSMITH
	my_entities.push_back(new Exits("Exit to WAREHOUSE 2.\n", "The next room is the WAREHOUSE 2.\n", false, Gunsmith, Warehouse2, 3));
	
	//my_entities[28] - EXITS FROM AILSE 2
	my_entities.push_back(new Exits("Exit to AISLE 3.\n", "The next room is the AISLE 3.\n", false, Aisle2, Aisle3, 0));
	//my_entities[29] - EXITS FROM AILSE 2
	my_entities.push_back(new Exits("Exit to AISLE.\n", "The next room is the AISLE.\n", false, Aisle2, Aisle, 1));
	//my_entities[30] - EXITS FROM AILSE 2
	my_entities.push_back(new Exits("Exit to HALL.\n", "The next room is the HALL.\n", false, Aisle2, Hall, 2));
	
	//my_entities[31] - EXITS FROM HALL
	my_entities.push_back(new Exits("Exit to AISLE 2.\n", "The next room is the AISLE 2.\n", false, Hall, Aisle2, 0));
	//my_entities[32] - EXITS FROM HALL
	my_entities.push_back(new Exits("Exit to EXIT.\n", "The next room is the EXIT.\n", false, Hall, ExitRoom, 3));
	
	//my_entities[33] - EXITS FROM EXITROOM
	my_entities.push_back(new Exits("Exit to HALL.\n", "The next room is the HALL.\n", false, ExitRoom, Hall, 1));
	
	//my_entities[34] - EXITS FROM AILSE 3
	my_entities.push_back(new Exits("Exit to AISLE 2.\n", "The next room is the AISLE 2.\n", false, Aisle3, Aisle2, 2));
	//my_entities[35] - EXITS FROM AILSE 3
	my_entities.push_back(new Exits("Exit to LABORATORY.\n", "The next room is the LABORATORY.\n", false, Aisle3, Laboratory, 1));
	
	//my_entities[36] - EXITS FROM LABORATORY
	my_entities.push_back(new Exits("Exit to AISLE 3.\n", "The next room is the AISLE 3.\n", false, Laboratory, Aisle3, 3));
	
	//Create Doors
	//door[0]  -   DOOR 0
	door.push_back(new Door(false, Aisle, DressingRoom));
	//door[1]  -   DOOR 0
	door.push_back(new Door(false, DressingRoom, Aisle));

	//door[2]  -   DOOR 1
	door.push_back(new Door(false, MysteryRoom, Warehouse));
	//door[3]  -   DOOR 1
	door.push_back(new Door(false, Warehouse, MysteryRoom));

	//door[4]  -   DOOR 2
	door.push_back(new Door(false, Warehouse2, Gunsmith));
	//door[5]  -   DOOR 2
	door.push_back(new Door(false, Gunsmith, Warehouse2));

	//door[6]  -   DOOR 3
	door.push_back(new Door(false, ExitRoom, Hall));
	//door[7]  -   DOOR 3
	door.push_back(new Door(false, Hall, ExitRoom));

	//door[8]  -   DOOR 4
	door.push_back(new Door(false, Aisle3, Laboratory));
	//door[9]  -   DOOR 4
	door.push_back(new Door(false, Laboratory, Aisle3));


	//PLAYER
	//my_entities[37]
	my_entities.push_back(new Player("Elliot", "I'm a strong", 1, 0, 0));
	player = (Player*)my_entities[37];
	player->position = MainRoom;

	//ITEMS
	Item* Bag;
	Item* Lantern;
	Item* Card;
	Item* Lockpick;
	Item* Key;
	Item* Paper;
	Item* Gun;
	Item* Ammo;
	Item* Camera;
	Item* Vest;
	Item* Safe;
	Item* Reader;
	Item* Scanner;
	Item* Lock;
	Item* Padlock;
	Item* Deadbolt;
	Item* Armory;
	Item* Locker;

	//my_entities[38]
	my_entities.push_back(Bag = new Item("bag", "It is a military backpack brown and is quite large\n", MainRoom, false, false, false, false, 0, 0, 100));
	MainRoom->list.push_back(Bag);
	//my_entities[39]
	my_entities.push_back(Lantern = new Item("lantern", "It is a lantern of those that are small but more light than the sun\n", MainRoom, false, false, false, false, 0, 0, 10));
	MainRoom->list.push_back(Lantern);
	//my_entities[40]
	my_entities.push_back(Card = new Item("card", "It looks like a card to pass a security check, it may be useful\n", Warehouse, false, false, false, false, 0, 0, 50));
	Warehouse->list.push_back(Card);
	//my_entities[41]
	my_entities.push_back(Lockpick = new Item("lockpick", "It can be useful to open doors, thank god know how to use it\n", OfficeRoom, false, false, false, false, 0, 0, 1));
	OfficeRoom->list.push_back(Lockpick);
	//my_entities[42]
	my_entities.push_back(Key = new Item("key", "It is a normal key, with a label that puts armory\n", DressingRoom, false, false, false, false, 0, 0, 10));//item[4], 
	DressingRoom->list.push_back(Key);
	//my_entities[43]
	my_entities.push_back(Paper = new Item("paper", "It is a small role. It has written a command: 'SZKMS'\n", Laboratory, false, false, false, false, 0, 0, 100));//item[5], 12
	Laboratory->list.push_back(Paper);
	//my_entities[44]
	my_entities.push_back(Gun = new Item("gun", "It is a M4A1-S, it is one of my favorite weapons\n", Gunsmith, false, false, false, false, 0, 5, 100));//item[6], 
	Gunsmith->list.push_back(Gun);
	//my_entities[45]
	my_entities.push_back(Ammo = new Item("ammo", "It is a ammo pack, but only has 10 bullets\n", Gunsmith, false, false, false, false, 0, 45, 10));//item[7], 
	Gunsmith->list.push_back(Ammo);
	//my_entities[46]
	my_entities.push_back(Camera = new Item("camera", "Oh my camera, finally I ever have\n", Warehouse, false, false, false, false, 0, 0, 100));//item[8], 5
	Warehouse->list.push_back(Camera);
	//my_entities[47]
	my_entities.push_back(Vest = new Item("vest", "It's a bulletproof vest might be useful.\n", DressingRoom, false, false, false, false, 100, 0, 10));//item[9], 
	DressingRoom->list.push_back(Vest);
	//my_entities[48]
	my_entities.push_back(Safe = new Item("safe", "It is safe, it seems that this open\n", Warehouse, false, true, false, false, 0, 0, 15));//item[10], 
	Warehouse->list.push_back(Safe);
	//my_entities[49]
	my_entities.push_back(Reader = new Item("reader", "It seems that putting a password the door opened (no implemented yet)\n", Hall, false, true, false, false, 0, 0, 0));//item[11], 
	Hall->list.push_back(Reader);
	//my_entities[50]
	my_entities.push_back(Scanner = new Item("scanner", "It is a card reader, if I put a card surely will open\n", Aisle3, false, true, false, false, 0, 0, 0));//item[12], to open door of laboratory
	Aisle3->list.push_back(Scanner);
	//my_entities[51]
	my_entities.push_back(Lock = new Item("lock", "I think that i can force the lock with a lockpick would get it\n", Aisle, false, true, false, false, 0, 0, 0));//item[13], 
	Aisle->list.push_back(Lock);
	//my_entities[52]
	my_entities.push_back(Padlock = new Item("padlock", "It's a big padlock, I think that I need something more than a lockpick, I could use the gun\n", MysteryRoom, false, true, false, false, 0, 0, 0));//item[14], Candado
	MysteryRoom->list.push_back(Padlock);
	//my_entities[53]
	my_entities.push_back(Deadbolt = new Item("deadbolt", "This lock is special, I only can open with a key\n", Warehouse2, false, true, false, false, 0, 0, 0));//item[15], 
	Warehouse2->list.push_back(Deadbolt);
	//my_entities[54]
	my_entities.push_back(Armory = new Item("armory", "It's an armory, it seems that there is only one gun and ammo\n", Gunsmith, false, true, false, false, 0, 0, 15));//item[16], 
	Gunsmith->list.push_back(Armory);
	//my_entities[55]
	my_entities.push_back(Locker = new Item("locker", "It's a locker, I can keep things inside\n", DressingRoom, false, true, false, false, 0, 0, 15));//item[17], 
	DressingRoom->list.push_back(Locker);
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

		else if (comand == "go n" || comand == "go w" || comand == "go s" || comand == "go e" || comand == "go u" || comand == "go d")
		{
			player->Move(comand_tok);
		}
		else if (comand == "look")
		{
			player->Look();
		}
		else if(comand_tok[0] == "pick" && option[4] == ' ' || comand_tok[0] == "p" && option[1] == ' '){
			player->Pick_item(comand_tok);
		}

		else if (comand == "drop" || comand == "d")
		{
			printf("Please, put drop [item]\n\n");
		}
		else if (comand_tok[0] == "drop" && option[4] == ' ' || comand_tok[0] == "d" && option[1] == ' '){
			player->Drop_item(comand_tok);
		}
		else if (comand == "look inventory" || comand == "look inv" || comand == "look i" || 
			comand == "inventory" || comand == "inv" || comand == "i")
		{
			player->Look_inventory();
		}

		/*//Commands - Go
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
		*/
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

/*void World::Open()
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
}*/
/*
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
}*/

/*void World::Look()const{

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



void World::Pick_item(Vector<ClString> &comand)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (player->position == item[i]->link && item[i]->istatus == false && item[i]->name == comand[1] && 
		item[i]->object == false && item[i]->isinside == false)
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
		if (item[i]->istatus == true && item[i]->name == comand[1] && item[i]->object == false && 
		item[i]->equiped == false)
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
*/
void World::Stats()const
{
	printf("----------\n");
	printf("HP:     %i\n", player->hp);
	printf("ATTACK: %i\n", player->attack);
	printf("----------\n");
}

bool World::Exit_zork(){
	if (quit == 1)
		return false;
	else
		return true;
}