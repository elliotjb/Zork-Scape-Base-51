#include "Move.h"
#include "player.h"
#include "Room.h"
#include "Exits.h"
#include "World.h"

World w;
Room r;
Exits e;



void Move::Move_position_North(){

	if (w.player[0].position = 0)
	{
		w.player[0].position = 1;
		printf("\n%s\n", (w.rooms[1].name));
		printf("%s\n", (w.rooms[1].description));
		return;
	}
	if (w.player[0].position = 1)
	{
		w.player[0].position = 2;
		printf("\n%s\n", (w.rooms[2].name));
		printf("%s\n", (w.rooms[2].description));
		return;
	}	
	if (w.player[0].position = 2)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 3)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 4)
	{
		w.player[0].position = 5;
		printf("\n%s\n", (w.rooms[5].name));
		printf("%s\n", (w.rooms[5].description));
		return;
	}
	if (w.player[0].position = 5)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 6)
	{
		w.player[0].position = 3;
		printf("\n%s\n", (w.rooms[3].name));
		printf("%s\n", (w.rooms[3].description));
		return;
	}
	if (w.player[0].position = 7)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 8)
	{
		w.player[0].position = 11;
		printf("\n%s\n", (w.rooms[11].name));
		printf("%s\n", (w.rooms[11].description));
		return;
	}
	if (w.player[0].position = 9)
	{
		w.player[0].position = 8;
		printf("\n%s\n", (w.rooms[8].name));
		printf("%s\n", (w.rooms[8].description));
		return;
	}
	if (w.player[0].position = 10)
	{
		printf("This is Exit!\n");
		return;
	}
	if (w.player[0].position = 11)
	{
		w.player[0].position = 8;
		printf("\n%s\n", (w.rooms[8].name));
		printf("%s\n", (w.rooms[8].description));
		return;
	}
	if (w.player[0].position = 12)
	{
		printf("There is a wall!.\n");
		return;
	}



}
void Move::Move_position_West(){

	if (w.player[0].position = 0)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 1)
	{
		w.player[0].position = 3;
		printf("\n%s\n", (w.rooms[3].name));
		printf("%s\n", (w.rooms[3].description));
		return;
	}
	if (w.player[0].position = 2)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 3)
	{
		w.player[0].position = 4;
		printf("\n%s\n", (w.rooms[4].name));
		printf("%s\n", (w.rooms[4].description));
		return;
	}
	if (w.player[0].position = 4)
	{
		printf("There is a wall.\n");
		return;
	}
	if (w.player[0].position = 5)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 6)
	{
		w.player[0].position = 7;
		printf("\n%s\n", (w.rooms[7].name));
		printf("%s\n", (w.rooms[7].description));
		return;
	}
	if (w.player[0].position = 7)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 8)
	{
		w.player[0].position = 1;
		printf("\n%s\n", (w.rooms[1].name));
		printf("%s\n", (w.rooms[1].description));
		return;
	}
	if (w.player[0].position = 9)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 10)
	{
		w.player[0].position = 9;
		printf("\n%s\n", (w.rooms[9].name));
		printf("%s\n", (w.rooms[9].description));
		return;
	}
	if (w.player[0].position = 11)
	{
		w.player[0].position = 12;
		printf("\n%s\n", (w.rooms[12].name));
		printf("%s\n", (w.rooms[12].description));
		return;
	}
	if (w.player[0].position = 12)
	{
		printf("There is a wall!.\n");
		return;
	}

}
void Move::Move_position_South(){

	if (w.player[0].position = 0)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 1)
	{
		w.player[0].position = 0;
		printf("\n%s\n", (w.rooms[0].name));
		printf("%s\n", (w.rooms[0].description));
		return;
	}
	if (w.player[0].position = 2)
	{
		w.player[0].position = 1;
		printf("\n%s\n", (w.rooms[1].name));
		printf("%s\n", (w.rooms[1].description));
		return;
	}
	if (w.player[0].position = 3)
	{
		w.player[0].position = 6;
		printf("\n%s\n", (w.rooms[6].name));
		printf("%s\n", (w.rooms[6].description));
		return;
	}
	if (w.player[0].position = 4)
	{
		printf("There is a wall.\n");
		return;
	}
	if (w.player[0].position = 5)
	{
		w.player[0].position = 4;
		printf("\n%s\n", (w.rooms[4].name));
		printf("%s\n", (w.rooms[4].description));
		return;
	}
	if (w.player[0].position = 6)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 7)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 8)
	{
		w.player[0].position = 9;
		printf("\n%s\n", (w.rooms[9].name));
		printf("%s\n", (w.rooms[9].description));
		return;
	}
	if (w.player[0].position = 9)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 10)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 11)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 12)
	{
		printf("There is a wall!.\n");
		return;
	}
}
void Move::Move_position_East(){

	if (w.player[0].position = 0)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 1)
	{
		w.player[0].position = 8;
		printf("\n%s\n", (w.rooms[8].name));
		printf("%s\n", (w.rooms[8].description));
		return;
	}
	if (w.player[0].position = 2)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 3)
	{
		w.player[0].position = 1;
		printf("\n%s\n", (w.rooms[1].name));
		printf("%s\n", (w.rooms[1].description));
		return;
	}
	if (w.player[0].position = 4)
	{
		w.player[0].position = 3;
		printf("\n%s\n", (w.rooms[3].name));
		printf("%s\n", (w.rooms[3].description));
		return;
	}
	if (w.player[0].position = 5)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 6)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 7)
	{
		w.player[0].position = 6;
		printf("\n%s\n", (w.rooms[6].name));
		printf("%s\n", (w.rooms[6].description));
		return;
	}
	if (w.player[0].position = 8)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 9)
	{
		w.player[0].position = 10;
		printf("\n%s\n", (w.rooms[10].name));
		printf("%s\n", (w.rooms[10].description));
		return;
	}
	if (w.player[0].position = 10)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 11)
	{
		printf("There is a wall!.\n");
		return;
	}
	if (w.player[0].position = 12)
	{
		w.player[0].position = 11;
		printf("\n%s\n", (w.rooms[11].name));
		printf("%s\n", (w.rooms[11].description));
		return;
	}
}

void Move::Look_position(){

	if (w.num_room == 0){
		printf("%s", (w.rooms[0].name));
		printf("%s", (w.rooms[0].description));
	}
	if (w.num_room == 1){
		printf("%s", (w.rooms[1].name));
		printf("%s", (w.rooms[1].description));
		system("pause");
	}
	if (w.num_room == 2){
		printf("%s", (w.rooms[2].name));
		printf("%s", (w.rooms[2].description));
	}
	if (w.num_room == 3){
		printf("%s", (w.rooms[3].name));
		printf("%s", (w.rooms[3].description));
	}
	if (w.num_room == 4){
		printf("%s", (w.rooms[4].name));
		printf("%s", (w.rooms[4].description));
	}
	if (w.num_room == 5){
		printf("%s", (w.rooms[5].name));
		printf("%s", (w.rooms[5].description));
	}
	if (w.num_room == 6){
		printf("%s", (w.rooms[6].name));
		printf("%s", (w.rooms[6].description));
	}
	if (w.num_room == 7){
		printf("%s", (w.rooms[7].name));
		printf("%s", (w.rooms[7].description));
	}
	if (w.num_room == 8){
		printf("%s", (w.rooms[8].name));
		printf("%s", (w.rooms[8].description));
	}
	if (w.num_room == 9){
		printf("%s", (w.rooms[9].name));
		printf("%s", (w.rooms[9].description));
	}
}