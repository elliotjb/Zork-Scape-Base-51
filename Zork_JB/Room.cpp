#include "Room.h"
#include "World.h"

Room::Room(const char* str1, const char* str2, bool discover) :Entity(str1, str2), discover(discover)
{
	type = ROOM;
}

Room::~Room()
{

}

void Room::Look()const
{
	printf("\n%s\n%s", name.getstr(), description.getstr());
}