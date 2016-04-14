#ifndef _ARRAY_H_
#define _ARRAY_H_
//#include <vector>
#include<stdio.h>
#include<assert.h>
#include<vector>
#include "String_Class.h"


template<class TYPE>
class Vector
{

private:
	TYPE* buffer;
	unsigned int capacity= 13;
	unsigned int elements = 0;

public:
	//Constructor
	Vector(){
		printf("Me cre!\n");
		buffer = new TYPE[capacity];
	}
	//Construcor copy
	Vector(const Vector& copy){
		capacity = copy.capacity;
		elements = copy.elements; 
		buffer = new TYPE[capacity];
		for (unsigned int i = 0; i < elements; i++){
			buffer[i] = copy.buffer[i];
		}
	}
	//Destructor
	~Vector(){ 
		printf("Me destruyo!\n");
		delete[]buffer;
		getchar();
	}

	uint num_ele()const
	{
		return elements;
	}

	TYPE& operator[](unsigned int num)
	{
		assert(num >= 0 && num < elements);
		return buffer[num];
	}

	void push_back(const TYPE& elements)
	{
	
		if (this->elements >= capacity)
		{
			TYPE* temp;
			capacity *= 2;
			temp = new TYPE[capacity];

			for (int i = 0; i < this->elements; i++)
			{
				temp[i] = buffer[i];
			}
			delete[]buffer;
			buffer = temp;
		}

		buffer[this->elements++] = elements;
	}


	void push_front(const TYPE& elements)
	{
		if (elements >= capacity)
		{
			TYPE* temp;
			capacity *= 2;
			temp = new TYPE[capacity];
			temp[0] = elements;
			this->elements++;
			for (int i = 0; i < this->elements; i++)
			{
				temp[i + 1] = buffer[i];
			}
			delete[]buffer;
			buffer = temp;
		}

		for (int i = elements; i >= 0; i++)
		{
			buffer[i] = buffer[i - 1];
		}
			//buffer[0] = elements;
	}
	//Pop_back  -> elimina el ultim element
	


};

//Vector<int> v;
//v.push_back(2);
//v.push_back(4);
//Memoria-> [2, 4, ...] amb push_back fica a la ultima posicio de la memoria del vector el
//numero que em posat despres del push, si no hi ha res afegeix un nou espai

#endif


