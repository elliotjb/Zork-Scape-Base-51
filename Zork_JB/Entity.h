#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Vector.h"
#include "String_Class.h"


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
private:

	ClString name_string;
	ClString description_string;

public:

	Entity(const char* str1, const char* str2);
	Entity();
	virtual ~Entity();

	ClString name()const;
	ClString description()const;
	Type type;
	Vector <Entity*> my_entities;
	void Get_description()const; 
	void printf_name()const;

};


#endif 