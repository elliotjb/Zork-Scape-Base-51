#include "World.h"
#include "Item.h"
#include "Entity.h"
#include <stdio.h>
#include <stdlib.h>

Item::Item(const char* str1, const char* str2, Room* link, bool istatus, bool object, bool equiped, int hp, int attack, int durability) :
Entity(str1, str2), link(link), istatus(istatus), object(object), equiped(equiped), hp(hp), attack(attack), durability(durability)
{

}

Item::~Item()
{

}


