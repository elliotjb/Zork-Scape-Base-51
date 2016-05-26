#include "Exits.h"

Exits::Exits(const char* str1, const char* str2, TYPE type, bool discover, Room* origin, Room* destination, int direction) :
Entity(str1, str2, type), origin(origin), destination(destination), direction(direction)
{
	type = EXIT;
}

Exits::~Exits()
{

}


