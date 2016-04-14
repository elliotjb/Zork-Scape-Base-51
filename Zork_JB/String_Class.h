#ifndef _ClassString_H_
#define _ClassString_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

class ClString{

private:
	char* buffer = nullptr;
	uint memory;

public:
	ClString()
	{
		memory = 1;
		buffer = new char[memory];
		strcpy_s(buffer, memory, "");
	}
	ClString(const char* str){
		//Constructor que copiara al iniciar - "ClString hello("h"); ->(%s, hello) = h;"
		uint len = strlen(str);
		buffer = new char[len + 1];
		memory = len + 1;
		strcpy_s(buffer, memory, str);
	}
	//Contructor de copia
	ClString(const ClString& copy){
		memory = copy.memory;
		buffer = new char[memory];
		strcpy_s(buffer, memory, copy.buffer);
	}
	//Destructor
	~ClString(){
		delete[]buffer;
	}
	//Function to set 
	void set()
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
	//Funcion para devolver longitud
	uint length()const{
		return strlen(buffer);
	}
	void clear()
	{
		strcpy_s(buffer, memory, "");
	}
	//Funcion para imprimir string
	const char* getstr()const
	{
		return buffer;
	}
	//Devuelve la capacidad!
	uint capacity() const
	{
		return memory;
	}
	//Funcion para saber si hay algo en la cadena
	bool empty() const
	{
		return buffer[0] == 0;
	}
	//Funcion para comparar 2 clases si son iguales
	bool operator ==(const ClString& str) const
	{
		return strcmp(buffer, str.buffer) == 0;
	}
	//Function to compare 2 char
	bool operator ==(const char* str) const
	{
		return strcmp(buffer, str) == 0;
	}

	//Funcion para sumar 2 clases
	bool operator +=(const ClString& str) const
	{
		//deures!
	}
	//
	void operator =(const ClString& str)
	{
		if (memory < str.length() + 1)
		{
			delete[] buffer;
			memory = str.length() + 1;
			buffer = new char[memory];
		}
		strcpy_s(buffer, memory, str.buffer);
	}

	void operator =(const char *str)
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
	//+=
	void operator +=(const ClString& str)
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
	/*
	//
	bool operator +(const ClString& str)const{
		//deures!
	}
	//
	char* operator *=(const ClString& str)const{
		//deures!
	}
	//
	char* operator -(const ClString& str)const{
		//deures!
	}
	//
	char* operator -=(const ClString& str)const{
		//deures!
	}*/


};


















#endif