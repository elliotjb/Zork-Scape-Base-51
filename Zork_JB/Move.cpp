#include "Move.h"
#include "player.h"
#include "Room.h"
#include "World.h"

World w;
Room r;
void Move::Move_position(){
	char mov[7];
	scanf_s("%s", &mov);
	
	if (w.num_room == 0){
		if ((r.direction[0]) == "n" || (r.direction2 + 0) == "north"){
			(w.rooms) + 1;
		}

		if ((r.direction[1]) == "w" || (r.direction2 + 1) == "west"){
			w.rooms + 0;
		}

		if ((r.direction[2]) == "s" || (r.direction2 + 2) == "south"){
			w.rooms + 0;
		}

		if ((r.direction[3]) == "e" || (r.direction2 + 3) == "east"){
			w.rooms + 0;
		}
	}
	/*if (w.num_room == 1){
		if ((r.direction + 0) == "n" || (r.direction2 + 0) == "north"){
			w.rooms + 1;
		}

		if ((r.direction + 1) == "w" || (r.direction2 + 1) == "west"){
			w.rooms + 2;
		}

		if ((r.direction + 2) == "s" || (r.direction2 + 2) == "south"){
			w.rooms + 7;
		}

		if ((r.direction + 3) == "e" || (r.direction2 + 3) == "east"){
			w.rooms - 1;
		}
	}
	*/
}

void Move::Look_position(){

	if (w.num_room == 0){
		printf("%s", (w.rooms + 0)->name);
		printf("%s", (w.rooms + 0)->description);
	}
	if (w.num_room == 1){
		printf("%s", (w.rooms + 1)->name);
		printf("%s", (w.rooms + 1)->description);
		system("pause");
	}
	if (w.num_room == 2){
		printf("%s", (w.rooms + 2)->name);
		printf("%s", (w.rooms + 2)->description);
	}
	if (w.num_room == 3){
		printf("%s", (w.rooms + 3)->name);
		printf("%s", (w.rooms + 3)->description);
	}
	if (w.num_room == 4){
		printf("%s", (w.rooms + 4)->name);
		printf("%s", (w.rooms + 4)->description);
	}
	if (w.num_room == 5){
		printf("%s", (w.rooms + 5)->name);
		printf("%s", (w.rooms + 5)->description);
	}
	if (w.num_room == 6){
		printf("%s", (w.rooms + 6)->name);
		printf("%s", (w.rooms + 6)->description);
	}
	if (w.num_room == 7){
		printf("%s", (w.rooms + 7)->name);
		printf("%s", (w.rooms + 7)->description);
	}
	if (w.num_room == 8){
		printf("%s", (w.rooms + 8)->name);
		printf("%s", (w.rooms + 8)->description);
	}
	if (w.num_room == 9){
		printf("%s", (w.rooms + 9)->name);
		printf("%s", (w.rooms + 9)->description);
	}
}