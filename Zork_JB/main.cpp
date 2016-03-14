#include <stdio.h>
#include <stdlib.h>
#include "Exits.h"
#include "player.h"
#include "Room.h"
#include "World.h"

#include <string.h>

int main(){
	World w;
	w.Create_World();

	printf("Hello to my Zork!\n\n");

	printf("%s", w.rooms[0].name);
	printf("%s", w.rooms[0].description);

	while (w.Exit_zork())
	{
		w.Set_Command();
	}
	printf("\nThanks for Playing!!! :D\n\n");

	system("pause");
	return 0;
}