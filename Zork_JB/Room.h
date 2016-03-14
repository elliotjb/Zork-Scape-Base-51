#ifndef _Room_
#define _Room_
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Room{
public:
	char name[50];
	char description[250];
//	char Interact_door[2]; //  0-Open  1-Close

	void Move_Door();
	
};




#endif 