#include <stdio.h>
#include <stdlib.h>
#include "Exits.h"
#include "player.h"
#include "Room.h"
#include "Vector.h"
#include "World.h"
#include "Entity.h"
#include "String_Class.h"
#include <conio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

World* App = nullptr;

int main()
{
	App = new World;
	App->Create_World();

	printf("WELCOME TO MY ZORK!!\n\n");
	printf("Your name is Ros. A few days ago you desided to enter at the Area 51, but you were captured by soldiers when you were in and they took away your camera.\nYour mission is to leave the building with your camera.");
	printf("\nTo do this you'll have to get items to open doors, and overcome obstacles.\n\n");

	App->player->Look();

	int now = GetTickCount();
	while (App->stop == false)
	{
		while (App->Exit_zork())
		{
			int actualtime = GetTickCount();
			if (App->player->position == App->alien->position)
			{
				App->canmove = false;
				App->combat = true;
			}
			if (App->alien_dead == false)
			{
				if (actualtime >= now + 2000 && ((Room*)App->my_entities[4])->discover == false)
				{
					now = actualtime;
					App->alien->Update();
				}
			}
			if (App->player->hp <= 0)
			{

				//break;
			}
			if (App->alien_dead == true)
			{
				if (actualtime >= now + 20000)
				{
					now = actualtime;
					App->alien_dead = false;
				}
			}


			if (_kbhit())
			{
				App->Set_Command();
			}
		}
	}


	printf("\nThanks for Playing!!!\n\n");
	system("pause");
	return 0;
}