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
	//Contructor de copia
	ClString(const ClString& copy);
	~ClString();

	//Function to set 
	void set(char* command);

	//Funcion para devolver longitud
	uint length()const;

	void clear();

	//Funcion para imprimir string
	const char* getstr()const;

	//Devuelve la capacidad!
	uint capacity() const;

	//Funcion para saber si hay algo en la cadena
	bool empty() const;

	//Funcion para comparar 2 clases si son iguales
	bool operator ==(const ClString& str) const;

	//Function to compare 2 char
	bool operator ==(const char* str) const;

	//Funcion para sumar 2 clases
	bool operator +=(const ClString& str) const;

	void operator =(const ClString& str);

	void operator =(const char *str);
	//+=
	void operator +=(const ClString& str);

	Vector<ClString> tokenize(const char*);

};


#endif