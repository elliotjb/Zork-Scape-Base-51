#include <stdio.h>
#include <stdlib.h>
#include "Exits.h"
#include "player.h"
#include "Room.h"
#include "Vector.h"
#include "World.h"
#include "Entity.h"
#include "String_Class.h"

#include <string.h>

int main(){
	World world;
	world.Create_World();

	printf("WELCOME TO MY ZORK!!\n\n");
	printf("Your name is Ros. A few days ago you desided to enter at the Area 51, but you were captured by soldiers when you were in and they took away your camera.\nYour mission is to leave the building with your camera.");
	printf("\nTo do this you'll have to get items to open doors, and overcome obstacles.\n\n");

	world.Look();

	while (world.Exit_zork())
	{
		world.Set_Command();
	}

	printf("\nThanks for Playing!!!\n\n");
	printf("Your score is: %i\n", world.acon_moviment);
	if (world.acon_moviment < 44)
	{
		printf("Next time you try sure you will get it!\n\n");
	}
	if (world.acon_moviment == 44)
	{
		printf("OH!!!  You have the perfect score!!! Nicee :D!!\n\nBye professional player!!\n\n");
	}
	else if (world.acon_moviment > 44 && world.acon_moviment <= 70)
	{
		printf("Nice, you are really good!!\n\n");
	}
	else if (world.acon_moviment > 70)
	{
		printf("Its ok! Not everyone is good at playing!\n\n");
	}

	system("pause");
	return 0;
}