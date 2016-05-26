#include "player.h"

Criature::Criature()
{

}
Criature::Criature(const char* name, const char* des, TYPE type, int hp, int attack, int coins) : 
Entity(name, des, type), hp(hp), attack(attack), coins(coins)
{
	type = NPC;
}

Criature::~Criature()
{

}


Player::Player()
{

}
Player::Player(const char* name, const char* des, TYPE type,  int hp, int attack, int coins) : Criature(name, des, type, hp, attack, coins)
{
	type = PLAYER;
}

Player::~Player()
{

}

