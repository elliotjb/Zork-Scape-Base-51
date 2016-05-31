#include "World.h"
#include "player.h"

Player::Player(const char* name, const char* des, int hp, int attack, int coins) : Criature(name, des, hp, attack, coins)
{
	type = PLAYER;
}

Player::~Player()
{

}



void Player::Move(Vector<ClString> &str)
{
	bool direct = true;
	int i = 0;
	int dir = -1;

	if (str[1] == "n" || str[1] == "north")
	{
		direct = false; dir = 0;
	}
	else if (str[1] == "w" || str[1] == "west")
	{
		direct = false; dir = 1;
	}
	else if (str[1] == "s" || str[1] == "south")
	{
		direct = false; dir = 2;
	}
	else if (str[1] == "e" || str[1] == "east")
	{
		direct = false; dir = 3;
	}
	else
	{
		printf("Invalid direction!\n\n");
		return;
	}
	//NEW FUNCTION MOVE
	for (int i = 0; i < App->my_entities.size(); i++)
	{
		if (App->my_entities[i]->type == EXIT)
		{
			if (((Exits*)App->my_entities[i])->direction == dir && ((Exits*)App->my_entities[i])->origin == position)
			{
				for (int j = 0; j < App->door.size(); j++)
				{
					if (((Door*)App->door[j])->door_origin == position && ((Door*)App->door[j])->door_dst == ((Exits*)App->my_entities[i])->destination)
					{
						if (((Door*)App->door[j])->isOP == true)
						{
							position = ((Exits*)App->my_entities[i])->destination;
							for (int z = 0; i < 13; i++)
							{
								if (position == ((Room*)App->my_entities[z]) && ((Room*)App->my_entities[z])->discover == false)
								{
									((Room*)App->my_entities[z])->discover = true;
								}
							}
							Look();
							return;
						}
						if (((Door*)App->door[j])->isOP == false)
						{
							printf("Frist You need open the door!\n\n");
							return;
						}
					}
				}
				if (((Exits*)App->my_entities[i])->destination == App->alien->position)
				{
					DList<Entity*>::Node* node_player = App->player->list.first;
					while (node_player != nullptr)
					{
						if (node_player->data->name == ((Item*)App->my_entities[44])->name)
						{
							printf("WHAT THE FUCK??, There's a fucking alien inside! I think it's better not to go, but i have a gun...\nBufff, okey lets go!!");
							position = ((Exits*)App->my_entities[i])->destination;
							Look();
							return;
						}
						node_player = node_player->next;
					}
					printf("WAIT, WAIT, WAIT\nYou're crazy???, there's a fucking alien inside! and i don't have any gun!!\n\n");
					position = ((Exits*)App->my_entities[i])->destination;
					Look();
					return;
				}
				if (((Exits*)App->my_entities[i])->destination != App->alien->position)
				{
					position = ((Exits*)App->my_entities[i])->destination;
					Look();
					return;
				}
			}
		}
	}
	printf("In this direction there is a wall\n\n");
	return;
}

void Player::Look() const
{
	App->my_entities[0]->list.first->data;
	printf("%s \n%s \n", position->name.getstr(), position->description.getstr());
	bool oneprint_item = false;
	bool oneprint_obj = false;

	DList<Entity*>::Node* node_room = position->list.first;
	while (node_room != nullptr)
	{
		if (node_room->data->type == ITEM)
		{
			oneprint_item = true;
		}
		if (node_room->data->type == OBJECT)
		{
			if (((Item*)App->my_entities[52])->istatus == false)
			{
				oneprint_obj = true;
			}
		}
		node_room = node_room->next;
	}
	const DList<Entity*>::Node* new_node_room = position->list.first;
	if (oneprint_item)
	{
		printf("\nItems in this Room: \n");
	}
	while (new_node_room != nullptr)
	{
		if (new_node_room->data->type == ITEM)
		{
			printf("- %s\n", new_node_room->data->name.getstr());
		}
		new_node_room = new_node_room->next;
	}
	if (oneprint_obj)
	{
		printf("\nObjects in this Room: \n");
	}
	new_node_room = position->list.first;
	while (new_node_room != nullptr && oneprint_obj == true)
	{
		if (new_node_room->data->type == OBJECT)
		{
			printf("- %s\n", new_node_room->data->name.getstr());
		}
		new_node_room = new_node_room->next;
	}
	if (App->seller->position == position)
	{
		printf("\nHere are a Seller, He can have interesting things.\n");
	}
	if (App->combat == true)
	{
		printf("In front of me there is an alien with a gun... WTF GUN???\nI think that is better kill him or I'll die.\n");
	}
	printf("\n");
}

void Player::Look_inventory() const
{
	DList<Entity*>::Node* node_player = App->player->list.first;
	if (App->player->list.first->data == ((Item*)App->my_entities[38]))
	{
		printf("You have these items:\n");
		while (node_player != nullptr)
		{
			for (int i = 0; i < App->my_entities.size(); i++)
			{
				if (((Item*)App->my_entities[i])->equiped == false && node_player->data == ((Item*)App->my_entities[i]))
				{
					printf("- %s\n", node_player->data->name.getstr());
				}
			}
			node_player = node_player->next;
		}
	}
	else
	{
		printf("Sorry you don't have inventory!\n");
		printf("First you need a bag to look inventory!!!\n");
	}
	printf("\n");
}

void Player::Look_item(Vector<ClString> &str) const
{
	int cont = 0;
	DList<Entity*>::Node* node_player = list.first;
	DList<Entity*>::Node* node_room = position->list.first;
	if (position->list.empty() == false)
	{
		while (node_room != nullptr)
		{
			if (node_room->data->type == ITEM && node_room->data->name == str[1])
			{
				if (node_room->data->name == ((Item*)App->my_entities[45])->name)
				{
					printf("%s\n", node_room->data->name.getstr());
					printf("It is a ammo pack, but only has %i bullets\n\n", ((Item*)App->my_entities[45])->durability);
					return;
				}
				printf("%s\n", node_room->data->name.getstr());
				printf("%s\n", node_room->data->description.getstr());
				printf("\n");
				return;
			}

			if (node_room->data->type == OBJECT && node_room->data->name == str[1])
			{
				printf("Inside there: \n");
				for (int i = 0; i < App->my_entities.size(); i++)
				{
					if (App->my_entities[i]->type == OBJECT && ((Item*)App->my_entities[i])->link == position && node_room->data->name == str[1])
					{
						if (((Item*)App->my_entities[i])->isinside == true)
						{
							DList<Entity*>::Node* node_item = ((Item*)App->my_entities[i])->list.first;
							while (node_item != nullptr)
							{
								if (((Item*)App->my_entities[i])->list.empty() == false)
								{
									printf("- %s\n", node_item->data->name.getstr());
									printf("%s\n", node_item->data->description.getstr());
								}
								node_item = node_item->next;
							}
						}
					}
				}
				return;
			}
			node_room = node_room->next;
		}
	}
	if (list.empty() == false)
	{
		while (node_player != nullptr)
		{
			if (node_player->data->type == ITEM && node_player->data->name == str[1])
			{
				if (node_player->data->name == ((Item*)App->my_entities[45])->name)
				{
					printf("%s\n", node_player->data->name.getstr());
					printf("It is a ammo pack, but only has %i bullets\n\n", ((Item*)App->my_entities[45])->durability);
					return;
				}
				printf("%s\n", node_player->data->name.getstr());
				printf("%s\n", node_player->data->description.getstr());
				return;
			}
			node_player = node_player->next;
		}
	}
	printf("Wrong, this item is no here or dosent exist.\n\n");
}

void Player::Open()
{
	for (int i = 0; i < NUM_DOORS; i++)
	{
		if (position == ((Door*)App->door[0])->door_origin || position == ((Door*)App->door[1])->door_origin)
		{
			DList<Entity*>::Node* node_item = ((Item*)App->my_entities[51])->list.first;
			if (((Door*)App->door[0])->isOP == false)
			{
				if (node_item != nullptr)
				{
					if (node_item->data == ((Item*)App->my_entities[41]))
					{
						((Door*)App->door[0])->isOP = true;
						((Door*)App->door[1])->isOP = true;
						printf("The door has just been opened.\n\n");
						return;
					}
					else
					{
						printf("First you need a key to Unlock the door!\n\n");
						return;
					}
				}
				else
				{
					printf("First you need unlock the door!!\n\n");
				}
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == true)
			{
				printf("The door was already open.\n\n");
				return;
			}
		}
		if (position == ((Door*)App->door[2])->door_origin || position == ((Door*)App->door[3])->door_origin)
		{
			if (((Door*)App->door[2])->isOP == false)
			{
				if (((Item*)App->my_entities[52])->istatus == true)
				{
					printf("The door has just been opened.\n\n");
					((Door*)App->door[2])->isOP = true;
					((Door*)App->door[3])->isOP = true;
					return;
				}
				DList<Entity*>::Node* node_player = list.first;
				bool havegun = false;
				while (node_player != nullptr)
				{
					if (node_player->data == ((Item*)App->my_entities[44]))
					{
						havegun = true;
					}
					node_player = node_player->next;
				}
				node_player = list.first;
				while (node_player != nullptr)
				{
					if (node_player->data == ((Item*)App->my_entities[45]) && havegun == true)
					{
						printf("Attempts to shoot the padlock\n\n");
						return;
					}
					node_player = node_player->next;
				}
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == true)
			{
				printf("The door was already open.\n\n");
				return;
			}
		}
		if (position == ((Door*)App->door[4])->door_origin || position == ((Door*)App->door[5])->door_origin)
		{
			DList<Entity*>::Node* node_item = ((Item*)App->my_entities[53])->list.first;
			if (((Door*)App->door[4])->isOP == false)
			{
				if (node_item != nullptr)
				{
					if (node_item->data == ((Item*)App->my_entities[42]))
					{
						((Door*)App->door[4])->isOP = true;
						((Door*)App->door[5])->isOP = true;
						printf("The door has just been opened.\n\n");
						return;
					}
					else
					{
						printf("First you need a key to Unlock the door!\n\n");
						return;
					}
				}
				else
				{
					printf("First you need unlock the door!!\n\n");
				}
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == true)
			{
				printf("The door was already open.\n\n");
				return;
			}
		}
		if (position == ((Door*)App->door[6])->door_origin || position == ((Door*)App->door[7])->door_origin)
		{
			DList<Entity*>::Node* node_item = ((Item*)App->my_entities[49])->list.first;
			if (((Door*)App->door[6])->isOP == false)
			{
				if (node_item != nullptr)
				{
					if (node_item->data == ((Item*)App->my_entities[43]))
					{
						((Door*)App->door[6])->isOP = true;
						((Door*)App->door[7])->isOP = true;
						printf("The door has just been opened.\n\n");
						return;
					}
					else
					{
						printf("First you need a key to Unlock the door!\n\n");
						return;
					}
				}
				else
				{
					printf("First you need unlock the door!!\n\n");
				}
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == true)
			{
				printf("The door was already open.\n\n");
				return;
			}
		}
		if (position == ((Door*)App->door[8])->door_origin || position == ((Door*)App->door[9])->door_origin)
		{
			DList<Entity*>::Node* node_item = ((Item*)App->my_entities[50])->list.first;
			if (((Door*)App->door[8])->isOP == false)
			{
				if (node_item != nullptr)
				{
					if (node_item->data == ((Item*)App->my_entities[40]))
					{
						((Door*)App->door[8])->isOP = true;
						((Door*)App->door[9])->isOP = true;
						printf("The door has just been opened.\n\n");
						return;
					}
					else
					{
						printf("First you need a key to Unlock the door!\n\n");
						return;
					}
				}
				else
				{
					printf("First you need unlock the door!!\n\n");
				}
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == true)
			{
				printf("The door was already open.\n\n");
				return;
			}
		}
	}
}

void Player::Close()
{
	for (int i = 0; i < NUM_DOORS; i++)
	{
		if (position == ((Door*)App->door[0])->door_origin || position == ((Door*)App->door[1])->door_origin)
		{
			DList<Entity*>::Node* node_item = ((Item*)App->my_entities[51])->list.first;
			if (((Door*)App->door[0])->isOP == true)
			{
				if (node_item != nullptr)
				{
					if (node_item->data == ((Item*)App->my_entities[41]))
					{
						((Door*)App->door[0])->isOP = false;
						((Door*)App->door[1])->isOP = false;
						printf("The door has just been Closed.\n\n");
						return;
					}
					else
					{
						printf("First you need a key to lock the door!\n\n");
						return;
					}
				}
				else
				{
					printf("First you need put <item> into the door!!\n\n");
					return;
				}
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == false)
			{
				printf("The door was already close.\n\n");
				return;
			}
		}
		if (position == ((Door*)App->door[2])->door_origin || position == ((Door*)App->door[3])->door_origin)
		{
			if (((Door*)App->door[2])->isOP == true)
			{
				if (((Item*)App->my_entities[52])->istatus == true)
				{
					printf("The door has just been Closed.\n\n");
					((Door*)App->door[2])->isOP = false;
					((Door*)App->door[3])->isOP = false;
					return;
				}
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == false)
			{
				printf("The door was already close.\n\n");
				return;
			}
		}
		if (position == ((Door*)App->door[4])->door_origin || position == ((Door*)App->door[5])->door_origin)
		{
			DList<Entity*>::Node* node_item = ((Item*)App->my_entities[53])->list.first;
			if (((Door*)App->door[4])->isOP == true)
			{
				if (node_item != nullptr)
				{
					if (node_item->data == ((Item*)App->my_entities[42]))
					{
						((Door*)App->door[4])->isOP = false;
						((Door*)App->door[5])->isOP = false;
						printf("The door has just been Closed.\n\n");
						return;
					}
					else
					{
						printf("First you need a key to lock the door!\n\n");
						return;
					}
				}
				else
				{
					printf("First you need put <item> into the door!!\n\n");
					return;
				}
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == false)
			{
				printf("The door was already close.\n\n");
				return;
			}
		}
		if (position == ((Door*)App->door[6])->door_origin || position == ((Door*)App->door[7])->door_origin)
		{
			DList<Entity*>::Node* node_item = ((Item*)App->my_entities[49])->list.first;
			if (((Door*)App->door[6])->isOP == true)
			{
				if (node_item != nullptr)
				{
					if (node_item->data == ((Item*)App->my_entities[43]))
					{
						((Door*)App->door[6])->isOP = false;
						((Door*)App->door[7])->isOP = false;
						printf("The door has just been Closed.\n\n");
						return;
					}
					else
					{
						printf("First you need a key to lock the door!\n\n");
						return;
					}
				}
				else
				{
					printf("First you need put <item> into the door!!\n\n");
					return;
				}
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == false)
			{
				printf("The door was already close.\n\n");
				return;
			}
		}
		if (position == ((Door*)App->door[8])->door_origin || position == ((Door*)App->door[9])->door_origin)
		{
			DList<Entity*>::Node* node_item = ((Item*)App->my_entities[50])->list.first;
			if (((Door*)App->door[8])->isOP == true)
			{
				if (node_item != nullptr)
				{
					if (node_item->data == ((Item*)App->my_entities[40]))
					{
						((Door*)App->door[8])->isOP = false;
						((Door*)App->door[9])->isOP = false;
						printf("The door has just been Closed.\n\n");
						return;
					}
					else
					{
						printf("First you need a key to lock the door!\n\n");
						return;
					}
				}
				else
				{
					printf("First you need put <item> into the door!!\n\n");
					return;
				}
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == false)
			{
				printf("The door was already close.\n\n");
				return;
			}
		}
	}
}

void Player::Equip(Vector<ClString> &str)
{
	DList<Entity*>::Node* node_player = list.first;
	while (node_player != nullptr)
	{
		if (node_player->data->name == str[1])
		{
			for (int i = 0; i < App->my_entities.size(); i++)
			{
				if (node_player->data->name == ((Item*)App->my_entities[45])->name && ((Item*)App->my_entities[45])->equiped == false)
				{
					if (((Item*)App->my_entities[44])->equiped == true)
					{
						if (((Item*)App->my_entities[59])->equiped == false)
						{
							((Item*)App->my_entities[45])->equiped = true;
							attack += ((Item*)App->my_entities[45])->attack;
							printf("You equiped-> %s\n\n", node_player->data->name.getstr());
							Stats();
							return;
						}
						else
						{
							printf("Frist you unequiped another ammo ->(ammo1)!!!\n");
							return;
						}
					}
					else
					{
						printf("You can not equip <Ammo> pack, first you need equip a gun!\n\n");
						return;
					}
				}
				else if (node_player->data->name == ((Item*)App->my_entities[59])->name && ((Item*)App->my_entities[59])->equiped == false)
				{
					if (((Item*)App->my_entities[44])->equiped == true)
					{
						if (((Item*)App->my_entities[45])->equiped == false)
						{
							((Item*)App->my_entities[59])->equiped = true;
							attack += ((Item*)App->my_entities[59])->attack;
							printf("You equiped-> %s\n\n", node_player->data->name.getstr());
							Stats();
							return;
						}
						else
						{
							printf("Frist you unequiped another ammo ->(ammo)!!!\n");
							return;
						}
					}
					else
					{
						printf("You can not equip <Ammo> pack, first you need equip a gun!\n\n");
						return;
					}
				}
				else if (node_player->data->name == ((Item*)App->my_entities[i])->name && ((Item*)App->my_entities[i])->equiped == false && ((Item*)App->my_entities[i])->canequip == true)
				{
					((Item*)App->my_entities[i])->equiped = true;
					attack += ((Item*)App->my_entities[i])->attack;
					hp += ((Item*)App->my_entities[i])->hp;
					printf("You equiped-> %s\n\n", node_player->data->name.getstr());
					Stats();
					return;
				}
				else if (node_player->data->name == ((Item*)App->my_entities[i])->name && ((Item*)App->my_entities[i])->canequip == false)
				{
					printf("You can't equip this item\n\n");
					return;
				}
			}
		}
		node_player = node_player->next;
	}
	printf("Wrong, You dont have this item or It is not an item.\n\n");
}

void Player::UnEquip(Vector<ClString> &str)
{
	DList<Entity*>::Node* node_player = list.first;
	for (; node_player != nullptr; node_player = node_player->next)
	{
		if (node_player->data->name == str[1])
		{
			if (node_player->data->name == ((Item*)App->my_entities[44])->name && ((Item*)App->my_entities[44])->equiped == true)
			{
				((Item*)App->my_entities[44])->equiped = false;
				((Item*)App->my_entities[45])->equiped = false;
				attack -= ((Item*)App->my_entities[44])->attack;
				attack -= ((Item*)App->my_entities[45])->attack;
				printf("You unequiped-> %s\n\n", node_player->data->name.getstr());
				Stats();
				return;
			}
			for (int i = 0; i < App->my_entities.size(); i++)
			{
				if (node_player->data->name == ((Item*)App->my_entities[i])->name && ((Item*)App->my_entities[i])->equiped == true && ((Item*)App->my_entities[i])->canequip == true)
				{
					((Item*)App->my_entities[i])->equiped = true;
					attack += ((Item*)App->my_entities[i])->attack;
					hp += ((Item*)App->my_entities[i])->hp;
					printf("You equiped-> %s\n\n", node_player->data->name.getstr());
					Stats();
					return;
				}
			}
		}
	}
	printf("Wrong, You dont have this item or It is not an item.\n\n");
}

void Player::Pick_item(Vector<ClString> &str)
{
	if (position->list.empty() == false)
	{
		DList<Entity*>::Node* node_room = position->list.first;
		for (int i = 0; i < 13; i++)
		{
			if (((Room*)App->my_entities[i]) == position)
			{
				while (node_room != nullptr)
				{
					if (node_room->data->name == str[1])
					{
						if (node_room->data->type == ITEM)
						{
							list.push_back(node_room->data);
							if (list.first->data == ((Item*)App->my_entities[38]))
							{
								printf("You picked-> %s\n\n", node_room->data->name.getstr());
								((Room*)App->my_entities[i])->list.erase(node_room);
								return;
							}
							else
							{
								printf("First you need a bag to pick items!\n\n");
								list.pop_back();
								return;
							}
						}
						else
						{
							printf("You can PICK this, this is a Object!\n\n");
							return;
						}
					}
					node_room = node_room->next;
				}
			}
		}
	}
	printf("In this room, there are no ITEMS with that name.\n\n");
	return;
}

void Player::Drop_item(Vector<ClString> &str)
{
	if (list.empty() == false)
	{
		DList<Entity*>::Node* node_player = list.first;
		for (int i = 0; i < 13; i++)
		{
			if (((Room*)App->my_entities[i]) == position)
			{
				while (node_player != nullptr)
				{
					if (node_player->data->name == str[1] && node_player->data->type == ITEM)
					{
						if (str[1] == ((Item*)App->my_entities[38])->name)
						{
							printf("I think it's better not take off my backpack, i will need.\n\n");
							return;
						}
						((Room*)App->my_entities[i])->list.push_back(node_player->data);
						printf("You Droped-> %s\n\n", node_player->data->name.getstr());
						list.erase(node_player);
						return;
					}
					node_player = node_player->next;
				}
			}
		}
	}
	printf("You don't have this item!\n\n");
	return;
}

void Player::Put_into(Vector<ClString> &str)
{
	DList<Entity*>::Node* node_player = list.first;
	DList<Entity*>::Node* node_room = position->list.first;
	while (node_player != nullptr)
	{
		if (node_player->data->type == ITEM && node_player->data->name == str[1])
		{
			while (node_room != nullptr)
			{
				if (node_room->data->type == OBJECT && node_room->data->name == str[3])
				{
					for (int i = 38; i < App->my_entities.size(); i++)
					{
						if (((Item*)App->my_entities[i])->name == str[3] &&
							((Item*)App->my_entities[i])->type == OBJECT)
						{
							if (((Item*)App->my_entities[i])->durability > 2)
							{
								if (str[1] == ((Item*)App->my_entities[38])->name)
								{
									printf("I think it's better not take off my backpack, i will need.\n\n");
									return;
								}
								printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
								((Item*)App->my_entities[i])->isinside = true;
								((Item*)App->my_entities[i])->list.push_back(node_player->data);
								list.erase(node_player);
								return;
							}
						}
					}
					if (node_room->data->name == ((Item*)App->my_entities[51])->name)
					{
						if (node_player->data->name == ((Item*)App->my_entities[41])->name)
						{
							printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
							((Item*)App->my_entities[51])->isinside = true;
							((Item*)App->my_entities[51])->list.push_back((Item*)node_player->data);
							list.erase(node_player);
							return;
						}
						else
						{
							printf("This item is not opens this door\n\n");
							return;
						}
					}
					/*else if (node_room->data->name == ((Item*)App->my_entities[52])->name)
					{
						if (node_player->data == ((Item*)App->my_entities[44]))
						{
							printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
							((Item*)App->my_entities[52])->isinside = true;
							((Item*)App->my_entities[52])->list.push_back(node_player->data);
							list.erase(node_player);
							return;
						}
						else
						{
							printf("This item is not opens this door\n\n");
							return;
						}
					}*/
					else if (node_room->data == ((Item*)App->my_entities[53]))
					{
						if (node_player->data == ((Item*)App->my_entities[42]))
						{
							printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
							((Item*)App->my_entities[53])->isinside = true;
							((Item*)App->my_entities[53])->list.push_back(node_player->data);
							list.erase(node_player);
							return;
						}
						else
						{
							printf("This item is not opens this door\n\n");
							return;
						}
					}
					else if (node_room->data == ((Item*)App->my_entities[50]))
					{
						if (node_player->data == ((Item*)App->my_entities[40]))
						{
							printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
							((Item*)App->my_entities[50])->isinside = true;
							((Item*)App->my_entities[50])->list.push_back(node_player->data);
							list.erase(node_player);
							return;
						}
						else
						{
							printf("This item is not opens this door\n\n");
							return;
						}
					}
					else if (node_room->data == ((Item*)App->my_entities[49]))
					{
						if (node_player->data == ((Item*)App->my_entities[43]))
						{
							printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
							((Item*)App->my_entities[49])->isinside = true;
							((Item*)App->my_entities[49])->list.push_back(node_player->data);
							list.erase(node_player);
							return;
						}
						else
						{
							printf("This item is not opens this door\n\n");
							return;
						}
					}
					else
					{
						printf("Here you can not put this item\n\n");
						return;
					}
				}
				else if (node_room->data->type != OBJECT && node_room->data->name == str[3])
				{
					printf("You can put this item into %s, You are crazy!!\n\n", node_room->data->name.getstr());
					return;
				}
				node_room = node_room->next;
			}
		}
		else if (node_player->data->type != ITEM && node_player->data->name == str[1])
		{
			printf("You can put %s into this Object, You are crazy!!\n\n", node_player->data->name.getstr());
			return;
		}
		node_player = node_player->next;
	}
	printf("You do not have this item\n\n");
	return;
}

void Player::Get_from(Vector<ClString> &str)
{
	DList<Entity*>::Node* node_player = list.first;
	DList<Entity*>::Node* node_room = position->list.first;

	while (node_room != nullptr)
	{
		if (node_room->data->type == OBJECT && node_room->data->name == str[3])
		{
			for (int i = 0; App->my_entities.size(); i++)
			{
				if (((Item*)App->my_entities[i])->name == str[3] &&
					((Item*)App->my_entities[i])->type == OBJECT)
				{
					DList<Entity*>::Node* node_item = ((Item*)App->my_entities[i])->list.first;
					while (node_item != nullptr)
					{
						if (node_item->data->name == str[1])
						{
							if (node_player->data == ((Item*)App->my_entities[38]))
							{
								if (((Item*)App->my_entities[40])->name == str[1] || ((Item*)App->my_entities[41])->name == str[1] ||
									((Item*)App->my_entities[42])->name == str[1] || ((Item*)App->my_entities[43])->name == str[1])
								{
									printf("Remember that if you remove the item from a door and close the door on the other side you'll be trapped.\n\n");
								}
								printf("You get %s from %s\n\n", node_item->data->name.getstr(), node_room->data->name.getstr());
								list.push_back(node_item->data);
								node_room->data->list.erase(node_item);
								if (node_room == nullptr)
								{
									((Item*)App->my_entities[i])->isinside = false;
								}
								return;
							}
						}
						node_item = node_item->next;
					}
					printf("Dosent exist this item!\n\n");
					return;
				}
			}
		}

		else if (node_room->data->type == ITEM && node_room->data->name == str[3])
		{
			printf("You can get this item from &s, You are crazy!!\n\n", node_room->data->name.getstr());
			return;
		}
		node_room = node_room->next;
	}
}

void Player::Stats()const
{
	printf("----------\n");
	printf("HP:     %i\n", hp);
	printf("ATTACK: %i\n", attack);
	printf("Money:  %i\n", coins);
	printf("----------\n");
}

void Player::Shoot_attack()
{
	if (((Item*)App->my_entities[44])->equiped == true)
	{
		if (((Item*)App->my_entities[45])->equiped == true)
		{
			if (((Item*)App->my_entities[45])->durability > 0)
			{
				printf("You shot the ground, I think it's better not spend foolishly ammunition.\n\n");
				((Item*)App->my_entities[45])->durability -= 1;
				printf("Your bullets number-> %i", ((Item*)App->my_entities[45])->durability);
				return;
			}
			else
			{
				printf("Oh my god, There are no bullets\n\n");
			}
		}
		else if (((Item*)App->my_entities[59])->equiped == true)
		{
			if (((Item*)App->my_entities[59])->durability > 0)
			{
				printf("You shot the ground, I think it's better not spend foolishly ammunition.\n\n");
				((Item*)App->my_entities[59])->durability -= 1;
				printf("Your bullets number-> %i", ((Item*)App->my_entities[59])->durability);
				return;
			}
			else
			{
				printf("Oh my god, There are no bullets\n\n");
			}
		}
		else
		{
			printf("First equip ammo!!!\n\n");
			return;
		}
	}
	else
	{
		printf("First equip a gun!!!\n\n");
		return;
	}
}

void Player::Attack(Vector<ClString> &str)
{
	if (((Item*)App->my_entities[44])->equiped == true)
	{
		if (((Item*)App->my_entities[45])->equiped == true)
		{
			if (((Item*)App->my_entities[45])->durability > 0)
			{
				if (str[1] == "padlock" && ((Item*)App->my_entities[52])->istatus == false)
				{
					((Item*)App->my_entities[45])->durability -= 1;
					printf("You broke the padlock, now you can open the door.\n\n");
					((Item*)App->my_entities[52])->istatus = true;
					return;
				}
				if (App->combat == true)
				{
					if (str[1] == App->alien->name)
					{
						((Item*)App->my_entities[45])->durability - 1;
						App->alien->hp -= attack;
						printf("You hit ALIEN, you did %i damage!\n\n", attack);
						isattack = true;
						return;
					}
					else if (str[1] == "seller")
					{
						printf("You can't attack a Seller, he is a inmortal person\n\n");
						return;
					}
				}
				else
				{
					printf("Who do you want to attack? if no one here...\n\n");
					return;
				}
			}
			else
			{
				printf("Oh my god, There are no bullets\n\n");
				return;
			}
		}
		else if (((Item*)App->my_entities[59])->equiped == true)
		{
			if (((Item*)App->my_entities[59])->durability > 0)
			{
				if (str[1] == "padlock" && ((Item*)App->my_entities[52])->istatus == false)
				{
					((Item*)App->my_entities[59])->durability -= 1;
					printf("You broke the padlock, now you can open the door.\n\n");
					((Item*)App->my_entities[52])->istatus = true;
					return;
				}
				if (App->combat == true)
				{
					if (str[1] == App->alien->name)
					{
						((Item*)App->my_entities[59])->durability - 1;
						App->alien->hp -= attack;
						printf("You hit ALIEN, you did %i damage!\n\n", attack);
						return;
					}
					else if (str[1] == "seller")
					{
						printf("You can't attack a Seller, he is a inmortal person\n\n");
						return;
					}
				}
				else
				{
					printf("Who do you want to attack? if no one here...\n\n");
					return;
				}
			}
			else
			{
				printf("Oh my god, There are no bullets\n\n");
				return;
			}
		}
		else
		{
			printf("First equip an ammo!!!\n\n");
			return;
		}
	}
	else
	{
		printf("First equip a gun!!!\n\n");
		return;
	}

}

void Player::Buy_list()
{
	if (App->seller->position == position)
	{
		DList<Entity*>::Node* node_Seller = App->seller->list.first;
		printf("Seller have these items:\n");
		while (node_Seller != nullptr)
		{
			for (int i = 0; i < App->my_entities.size(); i++)
			{
				if (node_Seller->data == ((Item*)App->my_entities[i]))
				{
					printf("- %s\nprice-> %i\n", node_Seller->data->name.getstr(), ((Item*)App->my_entities[i])->price);
					if (((Item*)App->my_entities[i])->hp > 0)
					{
						printf("hp->  +%i\n\n", ((Item*)App->my_entities[i])->hp);
					}
					if (((Item*)App->my_entities[i])->attack > 0)
					{
						printf("attack-> +%i\n\n", ((Item*)App->my_entities[i])->attack);
					}
					
				}
			}
			node_Seller = node_Seller->next;
		}
	}
	else
	{
		printf("There is no seller in this room!\n");
	}
	printf("\n");
}

void Player::Buy_from(Vector<ClString> &str)
{
	if (App->seller->position == position)
	{
		DList<Entity*>::Node* node_Seller = App->seller->list.first;
		while (node_Seller != nullptr)
		{
			if (str[1] == node_Seller->data->name)
			{
				for (int i = 0; i < App->my_entities.size(); i++)
				{
					if (((Item*)App->my_entities[i])->name == str[1] && ((Item*)App->my_entities[i])->equiped == false)
					{
						if (coins >= ((Item*)App->my_entities[i])->price)
						{
							if (list.first != nullptr)
							{
								if (list.first->data == ((Item*)App->my_entities[38]))
								{
									printf("You Buy a %s for %i\n", node_Seller->data->name.getstr(), ((Item*)App->my_entities[i])->price);
									coins -= ((Item*)App->my_entities[i])->price;
									Stats();
									list.push_back(node_Seller->data);
									App->seller->list.erase(node_Seller);
									return;
								}
							}
							else
							{
								printf("First you need a bag to pick items!\n\n");
								return;
							}
						}
						else
						{
							printf("You don't have enough money.\n\n");
							return;
						}
					}
					else if (((Item*)App->my_entities[i])->name == str[1] && ((Item*)App->my_entities[i])->equiped == true)
					{
						printf("First you need UnEquip the item!\n\n");
					}
				}
			}
			node_Seller = node_Seller->next;
		}
	}
}

void Player::Sell_to(Vector<ClString> &str)
{
	if (App->seller->position == position)
	{
		DList<Entity*>::Node* node_player = list.first;
		while (node_player != nullptr)
		{
			if (str[1] == node_player->data->name)
			{
				for (int i = 0; i < App->my_entities.size(); i++)
				{
					if (((Item*)App->my_entities[i])->name == str[1])
					{

						printf("You Sell a %s for %i\n", node_player->data->name.getstr(), ((Item*)App->my_entities[i])->price);
						coins += ((Item*)App->my_entities[i])->price;
						Stats();
						((Seller*)App->my_entities[58])->list.push_back(node_player->data);
						list.erase(node_player);
						return;
					}
				}
			}
			node_player = node_player->next;
		}
	}
	printf("You don't have this item!!!\n\n");
	return;
}

void Player::Special_attack(Vector<ClString> &str)
{
	if (str[1] == "granade")
	{
		if (App->special_attack == true)
		{
			App->special_attack = false;
			if (App->combat == true)
			{
				printf("You throw a granade to alien\n");
				App->alien->hp -= 150;
				printf("You inflicted 150 damage\n");
				return;
			}
			else
			{
				printf("You throw a granade, Oh my god, its dangerous!!!\n\n");
				return;
			}
		}
		else
		{
			App->want_special = true;
			return;
		}
	}
	else
	{
		printf("You can't throw this...\n\n");
		return;
	}
}

