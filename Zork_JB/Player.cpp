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
	if (((Item*)App->my_entities[38])->istatus == true)
	{
		printf("You have these items:\n");
		for (int i = 0; i < App->my_entities.size(); i++)
		{
			if (App->my_entities[i]->type == ITEM)
			{
				if (((Item*)App->my_entities[i])->istatus == true && ((Item*)App->my_entities[i])->equiped == false && 
					((Item*)App->my_entities[i])->object == false)
				{
					printf("- %s\n", ((Item*)App->my_entities[i])->name.getstr());
				}
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
	}
}

void Player::Close()
{

}


void Player::Pick_item(Vector<ClString> &str)
{
	for (int i = 0; i < App->my_entities.size(); i++)
	{
		if (((Item*)App->my_entities[i])->link == position && ((Item*)App->my_entities[i])->istatus == false &&
			((Item*)App->my_entities[i])->name == str[1] && ((Item*)App->my_entities[i])->object == false &&
			((Item*)App->my_entities[i])->isinside == false)
		{
			((Item*)App->my_entities[i])->istatus = true;
			if (((Item*)App->my_entities[38])->istatus == true)
			{
				printf("You picked-> %s\n\n", ((Item*)App->my_entities[i])->name.getstr());
				return;
			}
			else if (((Item*)App->my_entities[38])->istatus == false)
			{
				((Item*)App->my_entities[i])->istatus = false;
				printf("First you need a bag to pick items!\n\n");
				return;
			}
		}
	}
	printf("In this room, there are no ITEMS with that name.\n\n");
	return;
}
void Player::Drop_item(Vector<ClString> &str)
{
	for (int i = 0; i < App->my_entities.size(); i++)
	{
		if (((Item*)App->my_entities[i])->istatus == true && ((Item*)App->my_entities[i])->name == str[1] && 
			((Item*)App->my_entities[i])->object == false && ((Item*)App->my_entities[i])->equiped == false)
		{
			((Item*)App->my_entities[i])->istatus = false;
			((Item*)App->my_entities[i])->link = position;
			printf("You Droped-> %s\n\n", ((Item*)App->my_entities[i])->name.getstr());
			return;
		}
		else if (((Item*)App->my_entities[i])->equiped == true)
		{
			printf("You can't drop an equiped item!\n\n");
			return;
		}
	}
	printf("You dont have any object with this name\n\n");
	return;
}
