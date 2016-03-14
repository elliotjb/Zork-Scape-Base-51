#include <stdio.h>
#include <stdlib.h>
#include "Exits.h"
#include "Room.h"
#include "World.h"
#include "Move.h"
#include <string.h>

int main(){
	World w;
	Room r;
	Move m;
	w.Create_World();
	printf("Hello to my Zork!\n\n");
	int exit = 0;
	char *dir;
	char *oc_door;
	printf("%s", w.rooms[0].name);
	printf("%s", w.rooms[0].description);

	while (exit==0)
	{
		m.Set_Command();
		if (w.player[0].position == 10){
			exit = 1;
		}
	}

	system("pause");
	return 0;
}