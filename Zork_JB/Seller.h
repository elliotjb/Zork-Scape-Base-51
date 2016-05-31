#ifndef _SELLER_H_
#define _SELLER_H_

#include "Criature.h"
#include "Room.h"
#include "Item.h"

class Seller :public Criature
{
public:
	Seller(const char* name, const char* description, int hp, int attack, int coins);
	~Seller();

	TYPE type;
	Room* position;
	Vector<Item*>inv;

	void Update();
};

#endif

