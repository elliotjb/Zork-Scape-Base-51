#include "World.h"
#include "player.h"

Alien::Alien(const char* name, const char* des, int hp, int attack, int coins) : Criature(name, des, hp, attack, coins)
{
	type = NPC;
}

Alien::~Alien()
{

}

void Alien::Update()
{
	printf("HI");
}


void Alien::Move(const Vector<ClString> &str)
{
	if (App->combat == false)
	{

	}
}

void Alien::Dead()
{

}