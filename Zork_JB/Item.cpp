#include "World.h"
#include "Item.h"
#include "Entity.h"
#include <stdio.h>
#include <stdlib.h>

Item::Item(const char* str1, const char* str2) :Entity(str1, str2)
{
	type = ITEM;
}

Item::~Item()
{

}


