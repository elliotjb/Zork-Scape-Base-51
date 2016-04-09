#ifndef _ClassString_H_
#define _ClassString_H_

#include <string.h>
#include <stdio.h>

class ClString{

private:
	char* buffer = nullptr;
	unsigned int memory;

public:
	ClString(const char* str){
		//Constructor que copiara al iniciar - "ClString hello("h"); ->(%s, hello) = h;"
		memory = strlen(str);
		buffer = new char[memory + 1];
		strcpy_s(buffer, memory, str);
	}
	//Contructor de copia
	ClString(const ClString& copy){
		memory = strlen(copy.buffer);
		buffer = new char[memory + 1];
		strcpy_s(buffer, memory, copy.buffer);
	}
	//Destructor
	~ClString(){
		delete[]buffer;
	}
	//Funcion para devolver longitud
	unsigned int lenght()const{
		return strlen(buffer);
	}
	//Funcion para imprimir string
	const char* getstr()const{
		return buffer;
	}
	//Funcion para saber si hay algo en la cadena
	bool empty()const{
		return strlen(buffer) == 0;
	}
	//Funcion para comparar 2 clases si son iguales
	bool operator ==(const ClString& str)const{
		return strcmp(buffer, str.buffer) == 0;
	}
	//Funcion para sumar 2 clases
	bool operator +=(const ClString& str)const{
		//deures!
	}
	//
	void operator =(const ClString& str){

		if (SameLenght(str)){
			strcpy_s(buffer, memory, str.buffer);
		}

		else if (IsSmaller(str)){
			int len = str.memory;
			strcpy_s(buffer, len, str.buffer);
			buffer[len] = 0;
		}

		if (str.lenght() + 1 > memory){
			memory = str.lenght() + 1;
			delete[]buffer;
			buffer = new char[memory];
		}
		strcpy_s(buffer, memory, str.buffer);
		//deures!
	}

	//+=
	void operator +=(const ClString& str){
		//if ()

	}
	//COmprueba que tengan la misma capacidad
	bool SameLenght(const ClString& str){
		return memory == str.memory;
	}
	//Comprueba que sea mas pequeño que la capacidad que hay
	bool IsSmaller(const ClString& str){
		return memory > str.memory;
	}

	//Devuelve la capacidad!
	int GetCapacity(){
		return memory;
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