#ifndef _ROOM_H_
#define _ROOM_H_
#include <string>
#include "Entity.h"



using namespace std;


class Room : public Entity
{

public:

	Room(const char* names_string, const char* description_string);
	virtual ~Room();

	//char name[50];
	//char description[250];
	char Interact_door[2]; //  0-Open  1-Close

	
};




#endif 