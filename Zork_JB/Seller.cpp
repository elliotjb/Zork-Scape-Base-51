#include "World.h"
#include "Alien.h"


Seller::Seller(const char* name, const char* des, int hp, int attack, int coins) : Criature(name, des, hp, attack, coins)
{
	type = NPC;
}

Seller::~Seller()
{

}

void Seller::Update()
{



}

