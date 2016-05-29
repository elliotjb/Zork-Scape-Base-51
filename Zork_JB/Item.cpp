#include "World.h"
#include "Item.h"
#include "Entity.h"
#include <stdio.h>
#include <stdlib.h>

Item::Item(const char* str1, const char* str2, Room* link, bool istatus, bool object, bool equiped, bool isinside, int hp, int attack, int durability, int price) :
Entity(str1, str2), link(link), istatus(istatus), object(object), equiped(equiped), isinside(isinside), hp(hp), attack(attack), durability(durability), price(price)
{
	type = ITEM;
}

Item::~Item()
{

}


