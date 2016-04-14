#include "World.h"
#include "Item.h"
#include "Entity.h"
#include <stdio.h>
#include <stdlib.h>

Item::Item(const char* str1, const char* str2, Room* link, bool istatus) :
Entity(str1, str2), link(link), istatus(istatus)
{
	type = ITEM;
}

Item::~Item()
{

}


