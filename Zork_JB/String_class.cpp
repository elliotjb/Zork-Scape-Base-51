#include "String_Class.h"
#include <string.h>
#include "Vector.h"
#include <stdio.h>


ClString::ClString()
{

	memory = 1;
	buffer = new char[memory];
	strcpy_s(buffer, memory, "");

}

ClString::ClString(const char* str)
{
	uint len = strlen(str);
	buffer = new char[len + 1];
	memory = len + 1;
	strcpy_s(buffer, memory, str);
}

ClString::ClString(const ClString& copy)
{
	memory = copy.memory;
	buffer = new char[memory];
	strcpy_s(buffer, memory, copy.buffer);
}

ClString::~ClString()
{
	delete[]buffer;
}

void ClString::set(char* command)
{
	char str[20];
	gets_s(str, 20);
	int lent = strlen(str) + 1;
	if (memory < lent){
		delete[]buffer;
		memory = lent;
		buffer = new char[memory];
	}
	strcpy_s(buffer, memory, str);
}

uint ClString::length()const
{
	return strlen(buffer);
}

void ClString::clear()
{
	strcpy_s(buffer, memory, "");
}

const char* ClString::getstr()const
{
	return buffer;
}

uint ClString::capacity() const
{
	return memory;
}

bool ClString::empty()const 
{
	return buffer[0] == 0;
}

bool ClString::operator ==(const ClString& str) const
{
	return strcmp(buffer, str.buffer) == 0;
}

bool ClString::operator ==(const char* str) const
{
	return strcmp(buffer, str) == 0;
}


void ClString::operator =(const ClString& str)
{
	if (memory < str.length() + 1)
	{
		delete[] buffer;
		memory = str.length() + 1;
		buffer = new char[memory];
	}
	strcpy_s(buffer, memory, str.buffer);
}

void ClString::operator =(const char *str)
{
	unsigned int len = strlen(str);
	if (memory < len + 1);
	{
		delete[] buffer;
		memory = len + 1;
		buffer = new char[memory];
	}
	strcpy_s(buffer, memory, str);
}

void ClString::operator +=(const ClString& str)
{
	char *temp = nullptr;

	if (memory < str.length() + length() + 1)
	{
		memory = str.length() + length() + 1;
		temp = new char[memory];
		strcpy_s(temp, memory, buffer);
		delete[]buffer;
		strcat_s(temp, memory, str.buffer);
		buffer = temp;
	}
	else
	{
		strcat_s(buffer, memory, str.buffer);
	}
}

Vector<ClString> ClString::tokenize(const char* comand)
{
	Vector<ClString> v;
	int size = strlen(comand) + 1;
	char* dup = new char[size];
	char* re;
	strcpy_s(dup, size, comand);
	char* token = strtok_s(dup, " ", &re);
	while (token != NULL){
		v.push_back(token);
		token = strtok_s(NULL, " ", &re);
	}
	delete[]dup;
	return v;
}
