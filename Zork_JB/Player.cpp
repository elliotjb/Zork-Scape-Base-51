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
	bool oneprint = false;
	for (int i = 0; i < App->my_entities.size(); i++)
	{
		if (((Item*)App->my_entities[i])->link == position && ((Item*)App->my_entities[i])->istatus == false &&
			((Item*)App->my_entities[i])->object == false && ((Item*)App->my_entities[i])->isinside == false &&
			oneprint == false)
		{
			oneprint = true;
			printf("\nItems in this room:\n\n");
		}
	}
	for (int i = 0; i < App->my_entities.size(); i++)
	{
		if (((Item*)App->my_entities[i])->link == position && ((Item*)App->my_entities[i])->istatus == false &&
			((Item*)App->my_entities[i])->object == false && ((Item*)App->my_entities[i])->isinside == false)
		{
			printf("- %s\n", ((Item*)App->my_entities[i])->name.getstr());
		}
	}
	oneprint = false;
	for (int i = 0; i < App->my_entities.size(); i++)
	{
		if (((Item*)App->my_entities[i])->link == position && ((Item*)App->my_entities[i])->object == true &&
			oneprint == false)
		{
			oneprint = true;
			printf("\nObjects in this room:\n\n");
		}
	}
	for (int i = 0; i < App->my_entities.size(); i++)
	{
		if (((Item*)App->my_entities[i])->link == position && ((Item*)App->my_entities[i])->object == true)
		{
			printf("- %s\n", ((Item*)App->my_entities[i])->name.getstr());
		}
	}
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
	for (int i = 0; i < App->my_entities.size(); i++)
	{
		if (((Item*)App->my_entities[i])->istatus == true && ((Item*)App->my_entities[i])->isinside == false ||
			((Item*)App->my_entities[i])->istatus == false && ((Item*)App->my_entities[i])->isinside == false ||
			((Item*)App->my_entities[i])->equiped == true && ((Item*)App->my_entities[i])->name == str[1])
		{
			printf("%s\n", ((Item*)App->my_entities[i])->name.getstr());
			printf("%s\n", ((Item*)App->my_entities[i])->description.getstr());
		}
		if (((Item*)App->my_entities[i])->object == true)
		{
			printf("Inside there: \n");
			for (int i = 0; i < App->my_entities.size(); i++)
			{
				if (((Item*)App->my_entities[i])->link == position && ((Item*)App->my_entities[i])->isinside == true)
				{
					printf("%s\n", ((Item*)App->my_entities[i])->name.getstr());
				}
			}
			printf("\n");
			return;
		}
	}
}

void Player::Open()
{
	for (int i = 0; i < NUM_DOORS; i++)
	{
		if (position == ((Door*)App->door[0])->door_origin || position == ((Door*)App->door[1])->door_origin)
		{
			if (((Door*)App->door[i])->isOP == false && ((Item*)App->my_entities[3])->link == ((Item*)App->my_entities[13])->link)
			{
				((Door*)App->door[i])->isOP = true;
				printf("The door has just been opened.\n");
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == true)
			{
				printf("The door was already open.\n\n");
			}
		}
		if (position == ((Door*)App->door[2])->door_origin || position == ((Door*)App->door[3])->door_origin)
		{
			if (((Door*)App->door[i])->isOP == false && ((Item*)App->my_entities[6])->link == ((Item*)App->my_entities[14])->link)
			{
				((Door*)App->door[i])->isOP = true;
				printf("The door has just been opened.\n");
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == true)
			{
				printf("The door was already open.\n\n");
			}
		}
		if (position == ((Door*)App->door[4])->door_origin || position == ((Door*)App->door[5])->door_origin)
		{
			if (((Door*)App->door[i])->isOP == false && ((Item*)App->my_entities[4])->link == ((Item*)App->my_entities[15])->link)
			{
				((Door*)App->door[i])->isOP = true;
				printf("The door has just been opened.\n");
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == true)
			{
				printf("The door was already open.\n\n");
			}
		}
		if (position == ((Door*)App->door[6])->door_origin || position == ((Door*)App->door[7])->door_origin)
		{
			if (((Door*)App->door[i])->isOP == false && ((Item*)App->my_entities[5])->link == ((Item*)App->my_entities[11])->link)
			{
				((Door*)App->door[i])->isOP = true;
				printf("The door has just been opened.\n");
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == true)
			{
				printf("The door was already open.\n\n");
			}
		}
		if (position == ((Door*)App->door[8])->door_origin || position == ((Door*)App->door[9])->door_origin)
		{
			if (((Door*)App->door[i])->isOP == false && ((Item*)App->my_entities[2])->link == ((Item*)App->my_entities[12])->link)
			{
				((Door*)App->door[i])->isOP = true;
				printf("The door has just been opened.\n");
			}
			else if (position == ((Door*)App->door[i])->door_origin && ((Door*)App->door[i])->isOP == true)
			{
				printf("The door was already open.\n\n");
			}
		}
	}
}

void Player::Close()
{

}


void Player::Pick_item(Vector<ClString> &str)
{
	DList<Entity*>::Node* node_room = position->list.first;
	for (int i = 0; i < 13; i++)
	{
		while (node_room != nullptr)
		{
			printf("1\n");
			if (node_room->data->name == str[1] && node_room->data->type == ITEM)
			{
				printf("2\n");
				list.push_back(node_room->data);
				if (App->player->list.first->data == ((Item*)App->my_entities[38]))
				{
					printf("3\n");
					printf("You picked-> %s\n\n", node_room->data->name.getstr());
					/*if (node_room->next != nullptr)
					{
						printf("4\n");
						node_room = node_room->next;
						
					}*/
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
			node_room = node_room->next;
		}
	}
	printf("In this room, there are no ITEMS with that name.\n\n");
	return;
}
void Player::Drop_item(Vector<ClString> &str)
{
	DList<Entity*>::Node* node_player = list.first;
	for (int i = 0; i < 13; i++)
	{
		while (node_player != nullptr)
		{
			printf("1\n");
			if (node_player->data->name == str[1] && node_player->data->type == ITEM)
			{
				printf("2\n");
				((Room*)App->my_entities[i])->list.push_back(node_player->data);
				if (App->player->list.first->data == ((Item*)App->my_entities[38]))
				{
					printf("3\n");
					printf("You Droped-> %s\n\n", node_player->data->name.getstr());
					/*if (node_room->next != nullptr)
					{
					printf("4\n");
					node_room = node_room->next;

					}*/
					list.erase(node_player);
					return;
				}
				else
				{
					printf("First you need a bag to pick items!\n\n");
					((Room*)App->my_entities[i])->list.pop_back();
					return;
				}
			}
			node_player = node_player->next;
		}
	}
	printf("In this room, there are no ITEMS with that name.\n\n");
	return;
}
