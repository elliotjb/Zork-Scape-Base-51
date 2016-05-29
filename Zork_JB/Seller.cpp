#include "World.h"
#include "Alien.h"


Alien::Alien(const char* name, const char* des, int hp, int attack, int coins) : Criature(name, des, hp, attack, coins)
{
	type = NPC;
}

Alien::~Alien()
{

}

void Alien::Update()
{



}

