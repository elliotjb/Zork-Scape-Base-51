#ifndef _ARRAY_H_
#define _ARRAY_H_

#include<stdio.h>
#include<assert.h>
#include<vector>

typedef unsigned int uint;

template<class TYPE>
class Vector
{

private:
	TYPE* buffer = nullptr;
	unsigned int capacity = 18;
	unsigned int elements = 0;

public:
	//Constructor
	Vector(){
		buffer = new TYPE[capacity];
	}
	//Construcor copy
	Vector(const Vector& copy){
		capacity = copy.elements;
		buffer = new TYPE[capacity];
		if (copy.elements > 0)
		{
			elements = copy.elements;
			for (int i = 0; i < elements; i++)
			{
				buffer[i] = copy.buffer[i];
			}
		}
	}

	//Destructor
	~Vector(){ 
		delete[] buffer;
	}

	uint size()const
	{
		return elements;
	}

	TYPE& operator[](unsigned int num)
	{
		assert(num < elements);
		return buffer[num];
	}
	TYPE& operator[](unsigned int num)const
	{
		assert(num < elements);
		return buffer[num];
	}

	void push_back(const TYPE& elements)
	{
	
		if (this->elements >= capacity)
		{
			TYPE* temp = nullptr;
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
	}
	


};
#endif


