#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Vector.h"
#include "String_Class.h"

#define NUM_ITEMS 18
#define NUM_ROOMS 13

using namespace std;


class Entity
{
public:

	ClString name;
	ClString description;

public:

	Entity(const char* str1, const char* str2);
	Entity();
	~Entity();

};


#endif 