#include "Room.h"

Room::Room(const char* str1, const char* str2) :Entity(str1, str2)
{
	type = ROOM;
}

Room::~Room()
{

}