#include "Entity.h"
#include "String_Class.h"


Entity::Entity(const char* str1, const char* str2) : 
name(str1), description(str2)
{
	type = ENTITY;
}

Entity::Entity()
{

}

Entity::~Entity()
{

}

/*ClString Entity::name()const
{
	return name_string;
}

ClString Entity::description()const
{
	return description_string;
}*/
