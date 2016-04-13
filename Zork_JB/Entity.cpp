#include "Entity.h"
#include "String_Class.h"


Entity::Entity(const char* str1, const char* str2) : name_string(str1), description_string(str2)
{
	type = ENTITY;
}

Entity::~Entity()
{

}

ClString Entity::name()const
{
	return name_string;
}

ClString Entity::description()const
{
	return description_string;
}
