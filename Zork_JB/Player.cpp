#include "player.h"

Criature::Criature()
{

}
Criature::Criature(const char* name, const char* des, int hp, int attack, int coins) : Entity(name, des), hp(hp), attack(attack), coins(coins)
{
	/*hp = 0;
	attack = 0;
	coins = 0;*/
}

Criature::~Criature()
{

}


Player::Player()
{

}
Player::Player(const char* name, const char* des, int hp, int attack, int coins) : Criature(name, des, hp, attack, coins)
{
	/*hp = 0;
	attack = 0;
	coins = 0;*/
}

Player::~Player()
{

}

