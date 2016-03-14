#include <stdio.h>
#include <stdlib.h>
#include "Exits.h"
#include "Room.h"
#include "World.h"
#include "Move.h"
#include <string.h>

void Move::Set_Command(){
	char comand[10];
	printf("> ");
	gets_s(comand);

	//Command - Help
	if (strcmp("help", comand) == 0){
		printf("Your commands:\n");
		printf("-[go north] or [go n]\n-[go west] or [go w]\n-[go south] or [go s]\n-[go east] or [go e]\n");
		printf("-[look (the same way as above)]\n");
		printf("-[open door]\n-[close door]\n");
		printf("-[quit]\n-[help]\n");
	}

	if (strcmp("go north", comand) == 0){
		Move_position_North();
	}
	if (strcmp("go west", comand) == 0){
		Move_position_West();
	}
	if (strcmp("go south", comand) == 0){
		Move_position_South();
	}
	if (strcmp("go east", comand) == 0){
		Move_position_East();
	}
	if (strcmp("go n", comand) == 0){
		Move_position_North();
	}
	if (strcmp("go w", comand) == 0){
		Move_position_West();
	}
	if (strcmp("go s", comand) == 0){
		Move_position_South();
	}
	if (strcmp("go e", comand) == 0){
		Move_position_East();
	}

	if (strcmp("go", comand) == 0){
		printf("Where you want to go? [go north, go west, go south, go east]\n");
	}
	if (strcmp("look", comand) == 0){
		Look_position();
		printf("If you want to specify where to look like this-> [ look north/n, look west/w, look south/s, look east/e ]\n");
	}
	if (strcmp("look north", comand) == 0){
		Look_Specify_position_North();
	}
	if (strcmp("look west", comand) == 0){
		Look_Specify_position_West();
	}
	if (strcmp("look south", comand) == 0){
		Look_Specify_position_South();
	}
	if (strcmp("look east", comand) == 0){
		Look_Specify_position_East();
	}
	if (strcmp("look n", comand) == 0){
		Look_Specify_position_North();
	}
	if (strcmp("look w", comand) == 0){
		Look_Specify_position_West();
	}
	if (strcmp("look s", comand) == 0){
		Look_Specify_position_South();
	}
	if (strcmp("look e", comand) == 0){
		Look_Specify_position_East();
	}


}