#ifndef _Room_
#define _Room_
#include <string>
#define _CRT_SECURE_NO_WARNINGS
class Room{
public:
	char name[50];
	char description[250];
	char *direction[4]; // 0-North  1-West  2-South  3-East
	char direction2[4]; // 0-North  1-West  2-South  3-East
	char door[4]; //  0-Door North  1-Door West  2-Dorr South  3-Door East
	char door2[4]; //  0-Door North  1-Door West  2-Dorr South  3-Door East
	char Interact_door[2]; //  0-Open  1-Close

	void Select_Direction();
	void Select_Direction2();
	void Select_Door();
	void Select_Door2();
	void Move_Door();
	
};




#endif 