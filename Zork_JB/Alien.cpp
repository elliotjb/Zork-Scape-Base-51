#include "World.h"
#include "Alien.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


Alien::Alien(const char* name, const char* des, int hp, int attack, int coins) : Criature(name, des, hp, attack, coins)
{
	type = NPC;
}

Alien::~Alien()
{

}

void Alien::Update()
{
	srand(time(NULL));
	int dir;
	if (hp <= 0)
	{
		Dead();
	}

	if (App->canmove == true)
	{
		//0 -> NORTH ->up
		//1 -> WEST  ->left
		//2 -> SOUTH ->down
		//3 -> EAST  ->right
		dir = rand() % 4;
		Move(dir);
	}
	if (App->combat == true)
	{
		Attack();
	}

	if (App->alien_dead == false)
	{
		if (App->respawn == true)
		{
			App->respawn = false;
			App->canmove = true;
			position = ((Room*)App->my_entities[4]);
		}
	}



	/*Implemented MOVE*/
}


void Alien::Move(const int dir)
{
	if (App->combat == false)
	{
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
								printf("-> %s\n", position->name.getstr());
								return;
							}
							else if (((Door*)App->door[j])->isOP == false)
							{
								return;
							}
						}
					}
					position = ((Exits*)App->my_entities[i])->destination;
					if (App->player->position == position)
					{
						printf("WTF!!, Another fucking alien here, I have to shoot fast!\n\n");
						printf("-> %s\n", position->name.getstr());
						return;
					}
					printf("-> %s\n", position->name.getstr());
					return;
				}
			}
		}
	}
}

void Alien::Dead()
{
	App->respawn = true;
	App->alien_dead = true;
	hp = 300;
	App->combat = false;
	App->player->coins += coins;
	position = ((Room*)App->my_entities[57]);
	printf("You kill the Predator\n");
	printf("You earn 250 coins!\n");
	return;
}

void Alien::Attack()
{
	if (App->combat == true)
	{
		printf("%i\n", hp);
		App->player->hp -= attack;
		printf("ALIEN hit you, he has made 5 damage!\n\n");
		return;
	}
	else
	{
		return;
	}
}
