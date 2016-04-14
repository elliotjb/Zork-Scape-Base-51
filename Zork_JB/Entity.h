#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Vector.h"
#include "String_Class.h"
#define NUM_ITEMS 15

using namespace std;

enum Type
{
	PLAYER,
	ROOM,
	ITEM,
	EXIT,
	ENTITY
};

class Entity
{
public:

	ClString name;
	ClString description;

public:

	Entity(const char* str1, const char* str2);
	Entity();
	virtual ~Entity();

	/*ClString name()const;
	ClString description()const;*/
	Type type;
	Vector <Entity*> my_entities;
	void Get_description()const; 
	void printf_name()const;

};


#endif 