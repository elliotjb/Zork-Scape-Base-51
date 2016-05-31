#ifndef _ClassString_H_
#define _ClassString_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"


typedef unsigned int uint;


class ClString{

private:

	char *buffer = nullptr;
	uint memory;

public:
	ClString();
	ClString(const char* str);
	ClString(const ClString& copy);
	~ClString();

	uint length()const;

	void clear();

	const char* getstr()const;

	uint capacity() const;

	bool empty() const;

	bool operator ==(const ClString& str) const;

	bool operator ==(const char* str) const;

	bool operator +=(const ClString& str) const;

	void operator =(const ClString& str);

	void operator =(const char *str);
	//+=
	void operator +=(const ClString& str);

	Vector<ClString> tokenize(const char*);

};


#endif