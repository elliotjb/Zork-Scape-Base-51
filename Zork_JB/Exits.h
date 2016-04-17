#ifndef __Exits_H_
#define __Exits_H_
#include <string.h>
#include "Entity.h"

using namespace std;

class Exits : public Entity
{
public:
	Exits(const char* str1, const char* str2, int discover);
	~Exits();
	//char description[150];
	int discover;

};

#endif 