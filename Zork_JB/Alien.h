#ifndef _ALIEN_H_
#define _ALIEN_H_

#include "Criature.h"
#include "Room.h"
#include "Item.h"

class Alien:public Criature
{
public:
	Alien(const char* name, const char* description, int hp, int attack, int coins);
	~Alien();

	TYPE type;
	Room* position;
	Vector<Item*>inv;

	void Move(const int dir);
	void Attack();
	void Dead();
	void Update();

};

#endif

