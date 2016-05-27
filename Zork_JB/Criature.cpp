#include "Criature.h"

Criature::Criature()
{

}
Criature::Criature(const char* name, const char* des, int hp, int attack, int coins) :
Entity(name, des), hp(hp), attack(attack), coins(coins)
{
	type = NPC;
}

Criature::~Criature()
{

}