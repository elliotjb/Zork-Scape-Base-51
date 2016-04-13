#ifndef _Player_
#define _Player_
#include "Entity.h"

using namespace std;

class Player : public Entity
{

public:
	Player(const char* name, const char* description);
	~Player();
	//char name[10];
	//char descrption[50];
	int position;

	int inventory;

};

#endif