#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "My_list.h"
#include "String_Class.h"


enum TYPE{ ROOM, EXIT, PLAYER, ITEM, NPC };


class Entity
{
public:

	ClString name;
	ClString description;
	TYPE type;
	DList<Entity*> list;

public:

	Entity(const char* str1, const char* str2, TYPE type);
	Entity();
	~Entity();

};


#endif 