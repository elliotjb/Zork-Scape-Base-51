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
	char key = 'a';
	char input[100];
	int num = 0;
	App->player->Look();

	int now = GetTickCount();
	int now_g = GetTickCount();
	while (App->stop == false)
	{
		while (App->Exit_zork())
		{
			int actualtime = GetTickCount();
			int coldown_g = GetTickCount();
			if (App->player->position == App->alien->position && App->combat == false)
			{
				printf("MODE COMBAT ACTIVATED!!\n\n");
				App->canmove = false;
				App->combat = true;
			}
			if (App->alien_dead == false)
			{
				if (actualtime >= now + 3000 && ((Room*)App->my_entities[4])->discover == false)
				{
					now = actualtime;
					App->alien->Update();
				}
			}

			if (App->special_attack == false)
			{
				if (coldown_g >= now_g + 20000)
				{
					now_g = coldown_g;
					App->special_attack = true;
				}
				if (App->want_special == true)
				{
					App->want_special = false;
					printf("Attack-> throw granade, is coldown!\n\n");
				}
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
				key = _getch();
				input[num++] = key;
				printf("%c", key);
				if (key == '\b')
				{
					if (num > 1)
					{
						num--;
						num--;
					}
					else if (num == 1)
					{
						num--;
					}

				}
				if (key == '\r')	//enter
				{
					input[--num] = '\0';
					App->Set_Command(input);
					input[0] = '\0';
					num = 0;
				}
			}
		}
	}


	printf("\nThanks for Playing!!!\n\n");
	system("pause");
	return 0;
}