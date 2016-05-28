#include "World.h"
#include "player.h"

Player::Player(const char* name, const char* des, int hp, int attack, int coins) : Criature(name, des, hp, attack, coins)
{
	type = PLAYER;
}

Player::~Player()
{

}



void Player::Move(const Vector<ClString> &str)
{
	bool direct = true;
	int i = 0;
	int dir = -1;
	while (direct)
	{
		if (str[i] == "n")
		{
			direct = false; dir = 0;
		}
		else if (str[i] == "w")
		{
			direct = false; dir = 1;
		}
		else if (str[i] == "s")
		{
			direct = false; dir = 2;
		}
		else if (str[i] == "e")
		{
			direct = false; dir = 3;
		}
		i++;
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
							Look();
							return;
						}
						if (((Door*)App->door[j])->isOP == false)
						{
							printf("Frist You need open the door!\n");
							return;
						}
					}
				}
				position = ((Exits*)App->my_entities[i])->destination;
				Look();
				return;
			}
		}
	}
}

void Player::Look() const
{
	App->my_entities[0]->list.first->data;
	printf("HOLA");
	printf("%s \n%s \n", position->name.getstr(), position->description.getstr());
	bool oneprint_item = false;
	bool oneprint_obj = false;

	const DList<Entity*>::Node* node_room = position->list.first;
	while (node_room != nullptr)
	{
		if (node_room->data->type == ITEM)
		{
			oneprint_item = true;
		}
		if (node_room->data->type == OBJECT)
		{
			oneprint_obj = true;
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
	while (new_node_room != nullptr)
	{
		if (new_node_room->data->type == OBJECT)
		{
			printf("- %s\n", new_node_room->data->name.getstr());
		}
		new_node_room = new_node_room->next;
	}
	printf("\n");
}

void Player::Look_inventory() const
{
	DList<Entity*>::Node* node_player = App->player->list.first;
	printf("You have these items:\n");
	if (App->player->list.first->data == ((Item*)App->my_entities[38]))
	{
		while (node_player != nullptr)
		{
			printf("- %s\n", node_player->data->name.getstr());
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
						DList<Entity*>::Node* node_item = ((Item*)App->my_entities[i])->list.first;
						if (((Item*)App->my_entities[i])->list.empty() == false)
						{
							printf("%s\n", node_item->data->name.getstr());
							printf("%s\n", node_item->data->description.getstr());
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
				printf("%s\n", node_player->data->name.getstr());
				printf("%s\n", node_player->data->description.getstr());
				return;
			}
			node_player = node_player->next;
		}
	}

}

void Player::Open()
{
	for (int i = 0; i < NUM_DOORS; i++)
	{
		if (position == ((Door*)App->door[0])->door_origin || position == ((Door*)App->door[1])->door_origin)
		{
			DList<Entity*>::Node* node_item = ((Item*)App->my_entities[51])->list.first;
			if (((Door*)App->door[i])->isOP == false)
			{
				if (node_item->data == ((Item*)App->my_entities[41]))
				{
					((Door*)App->door[i])->isOP = true;
					printf("The door has just been opened.\n\n");
					return;
				}
				else
				{
					printf("First you need a key to Unlock the door!\n\n");
					return;
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
			DList<Entity*>::Node* node_item = ((Item*)App->my_entities[52])->list.first;
			if (((Door*)App->door[i])->isOP == false)
			{
				if (node_item->data == ((Item*)App->my_entities[44]))
				{
					((Door*)App->door[i])->isOP = true;
					printf("The door has just been opened.\n\n");
					return;
				}
				else
				{
					printf("First you need a key to Unlock the door!\n\n");
					return;
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
			if (((Door*)App->door[i])->isOP == false)
			{
				if (node_item->data == ((Item*)App->my_entities[42]))
				{
					((Door*)App->door[i])->isOP = true;
					printf("The door has just been opened.\n\n");
					return;
				}
				else
				{
					printf("First you need a key to Unlock the door!\n\n");
					return;
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
			if (((Door*)App->door[i])->isOP == false)
			{
				if (node_item->data == ((Item*)App->my_entities[43]))
				{
					((Door*)App->door[i])->isOP = true;
					printf("The door has just been opened.\n\n");
					return;
				}
				else
				{
					printf("First you need a key to Unlock the door!\n\n");
					return;
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
			if (((Door*)App->door[i])->isOP == false)
			{
				if (node_item->data == ((Item*)App->my_entities[40]))
				{
					((Door*)App->door[i])->isOP = true;
					printf("The door has just been opened.\n\n");
					return;
				}
				else
				{
					printf("First you need a key to Unlock the door!\n\n");
					return;
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
			if (((Door*)App->door[i])->isOP == true)
			{
				if (node_item->data == ((Item*)App->my_entities[41]))
				{
					((Door*)App->door[i])->isOP = false;
					printf("The door has just been Closed.\n\n");
					return;
				}
				else
				{
					printf("First you need a key to lock the door!\n\n");
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
			DList<Entity*>::Node* node_item = ((Item*)App->my_entities[52])->list.first;
			if (((Door*)App->door[i])->isOP == true)
			{
				if (node_item->data == ((Item*)App->my_entities[44]))
				{
					((Door*)App->door[i])->isOP = false;
					printf("The door has just been Closed.\n\n");
					return;
				}
				else
				{
					printf("First you need a key to lock the door!\n\n");
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
			if (((Door*)App->door[i])->isOP == true)
			{
				if (node_item->data == ((Item*)App->my_entities[42]))
				{
					((Door*)App->door[i])->isOP = false;
					printf("The door has just been Closed.\n\n");
					return;
				}
				else
				{
					printf("First you need a key to lock the door!\n\n");
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
			if (((Door*)App->door[i])->isOP == true)
			{
				if (node_item->data == ((Item*)App->my_entities[43]))
				{
					((Door*)App->door[i])->isOP = false;
					printf("The door has just been Closed.\n\n");
					return;
				}
				else
				{
					printf("First you need a key to lock the door!\n\n");
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
			if (((Door*)App->door[i])->isOP == true)
			{
				if (node_item->data == ((Item*)App->my_entities[40]))
				{
					((Door*)App->door[i])->isOP = false;
					printf("The door has just been Closed.\n\n");
					return;
				}
				else
				{
					printf("First you need a key to lock the door!\n\n");
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
	for (; node_player != nullptr; node_player = node_player->next)
	{
		if (node_player->data->name == str[1])
		{
			if (node_player->data->name == ((Item*)App->my_entities[44])->name && ((Item*)App->my_entities[44])->equiped == false)
			{
				((Item*)App->my_entities[44])->equiped == true;
				attack += ((Item*)App->my_entities[44])->attack;
				printf("You equiped-> %s\n\n", node_player->data->name.getstr());
				return;
			}
			else if (node_player->data->name == ((Item*)App->my_entities[47])->name && ((Item*)App->my_entities[47])->equiped == false)
			{
				((Item*)App->my_entities[47])->equiped == true;
				hp += ((Item*)App->my_entities[47])->hp;
				printf("You equiped-> %s\n\n", node_player->data->name.getstr());
				return;
			}
			else if (node_player->data->name == ((Item*)App->my_entities[45])->name && ((Item*)App->my_entities[45])->equiped == false)
			{
				if (((Item*)App->my_entities[44])->equiped == true)
				{
					((Item*)App->my_entities[45])->equiped == true;
					attack += ((Item*)App->my_entities[45])->attack;
					printf("You equiped-> %s\n\n", node_player->data->name.getstr());
					return;
				}
				else
				{
					printf("You can not equip <Ammo> pack, first you need equip a gun!\n\n");
					return;
				}
			}
			else
			{
				printf("You can't Equip this item!\n\n");
				return;
			}
		}
	}
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
				((Item*)App->my_entities[44])->equiped == false;
				((Item*)App->my_entities[45])->equiped == false;
				attack -= ((Item*)App->my_entities[44])->attack;
				attack -= ((Item*)App->my_entities[45])->attack;
				printf("You unequiped-> %s\n\n", node_player->data->name.getstr());
				return;
			}
			else if (node_player->data->name == ((Item*)App->my_entities[47])->name && ((Item*)App->my_entities[47])->equiped == true)
			{
				((Item*)App->my_entities[47])->equiped == false;
				hp -= ((Item*)App->my_entities[47])->hp;
				printf("You unequiped-> %s\n\n", node_player->data->name.getstr());
				return;
			}
			else if (node_player->data->name == ((Item*)App->my_entities[45])->name && ((Item*)App->my_entities[45])->equiped == true)
			{
				if (((Item*)App->my_entities[44])->equiped == true)
				{
					((Item*)App->my_entities[45])->equiped == false;
					attack -= ((Item*)App->my_entities[45])->attack;
					printf("You unequiped-> %s\n\n", node_player->data->name.getstr());
					return;
				}
			}
			else
			{
				printf("You can't UnEquip this item!\n\n");
				return;
			}
		}
		else
		{
			printf("You don't have this item or dosen't exist\n\n");
			return;
		}
	}
}

void Player::Pick_item(Vector<ClString> &str)
{
	if (position->list.empty() == false)
	{
		DList<Entity*>::Node* node_room = position->list.first;
		for (int i = 0; i < 13; i++)
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
	printf("In this room, there are no ITEMS with that name.\n\n");
	return;
}

void Player::Drop_item(Vector<ClString> &str)
{
	if (list.empty())
	{
		DList<Entity*>::Node* node_player = list.first;
		for (int i = 0; i < 13; i++)
		{
			while (node_player != nullptr)
			{
				if (node_player->data->name == str[1] && node_player->data->type == ITEM)
				{
					((Room*)App->my_entities[i])->list.push_back(node_player->data);
					printf("You Droped-> %s\n\n", node_player->data->name.getstr());
					list.erase(node_player);
					return;
				}
				node_player = node_player->next;
			}
		}
	}
	printf("You don'y have this item!\n\n");
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
					for (int i = 0; App->my_entities.size(); i++)
					{
						if (((Item*)App->my_entities[i])->name == str[3] &&
							((Item*)App->my_entities[i])->type == OBJECT)
						{
							if (((Item*)App->my_entities[i])->durability > 2)
							{
								DList<Entity*>::Node* node_item = ((Item*)App->my_entities[i])->list.first;
								printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
								node_item->data->list.push_back(node_player->data);
								list.erase(node_player);
								return;
							}
						}
					}
					if (node_room->data == ((Item*)App->my_entities[13]))
					{
						if (node_player->data == ((Item*)App->my_entities[3]))
						{
							DList<Entity*>::Node* node_item = ((Item*)App->my_entities[13])->list.first;
							printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
							node_item->data->list.push_back(node_player->data);
							list.erase(node_player);
							return;
						}
						else
						{
							printf("This item is not opens this door\n\n");
							return;
						}
					}
					else if (node_room->data == ((Item*)App->my_entities[14]))
					{
						if (node_player->data == ((Item*)App->my_entities[6]))
						{
							DList<Entity*>::Node* node_item = ((Item*)App->my_entities[14])->list.first;
							printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
							node_item->data->list.push_back(node_player->data);
							list.erase(node_player);
							return;
						}
						else
						{
							printf("This item is not opens this door\n\n");
							return;
						}
					}
					else if (node_room->data == ((Item*)App->my_entities[15]))
					{
						if (node_player->data == ((Item*)App->my_entities[4]))
						{
							DList<Entity*>::Node* node_item = ((Item*)App->my_entities[15])->list.first;
							printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
							node_item->data->list.push_back(node_player->data);
							list.erase(node_player);
							return;
						}
						else
						{
							printf("This item is not opens this door\n\n");
							return;
						}
					}
					else if (node_room->data == ((Item*)App->my_entities[12]))
					{
						if (node_player->data == ((Item*)App->my_entities[2]))
						{
							DList<Entity*>::Node* node_item = ((Item*)App->my_entities[12])->list.first;
							printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
							node_item->data->list.push_back(node_player->data);
							list.erase(node_player);
							return;
						}
						else
						{
							printf("This item is not opens this door\n\n");
							return;
						}
					}
					else if (node_room->data == ((Item*)App->my_entities[11]))
					{
						if (node_player->data == ((Item*)App->my_entities[5]))
						{
							DList<Entity*>::Node* node_item = ((Item*)App->my_entities[11])->list.first;
							printf("You Put %s Into %s\n\n", node_player->data->name.getstr(), node_room->data->name.getstr());
							node_item->data->list.push_back(node_player->data);
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
	if (node_player->data == ((Item*)App->my_entities[38]))
	{
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
								list.push_back(node_item->data);
								node_item->data->list.erase(node_item);
								printf("You get %s from %s\n\n", node_item->data->name.getstr(), node_room->data->name.getstr());
								return;
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
	else
	{
		printf("First you need a bag to Get items!\n\n");
		return;
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

