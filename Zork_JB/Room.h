#ifndef _ROOM_H_
#define _ROOM_H_

#include "Entity.h"



using namespace std;


class Room : public Entity
{

public:

	Room(const char* names_string, const char* description_string, bool discover);
	~Room();

	bool discover;
	void Look()const;
	//char name[50];
	//char description[250];

	
};




#endif 