#include "player.h"

Player::Player(const char* str1, const char* str2) : Entity(str1, str2)
{
	type = PLAYER;
}

Player::~Player()
{

}

