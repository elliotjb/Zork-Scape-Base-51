#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "My_list.h"
#include "String_Class.h"


enum TYPE{ ROOM, EXIT, PLAYER, ITEM, OBJECT, NPC };


class Entity
{
public:

	ClString name;
	ClString description;
	TYPE type;
	DList<Entity*> list;

public:


	Entity();
	Entity(const char* str1, const char* str2);
	~Entity();

};


#endif 