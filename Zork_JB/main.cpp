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
	printf("You'll have to get reach the exit without dying.\nFor this you will have to open and close doors and be careful not to get caught.\n\n");

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