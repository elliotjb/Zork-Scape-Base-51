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
		printf("Where you want to go? [go north, go west, go south, go east]\n> ");
	}
	if (strcmp("look", comand) == 0){
		printf("Where you want to look? [go north, go west, go south, go east]\n> ");
	}

}