#include "Array.h"
#include <iostream>
using std::cout;
using std::endl;

Array::Array(size_t size, int filler)
{
	array = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = filler;
	}
	this->size = size;
}

Array::Array(size_t size)
	:Array(size, 0)
{
}

Array::Array(const Array& other)
{
	*this = other;
}

Array::Array(Array&& other) //MOVE CTOR
{
	cout << "~~~~~~~MOVING~~~~~~~" << endl;
	this->array = other.array;
	this->size = other.size;

	other.array = nullptr;
	other.size = 0;
}

Array& Array::operator=(const Array& other)
{
	if (this != &other)
	{
		if (array != nullptr) {
			delete[] array;
		}
		array = new int[size = other.size];
		for (size_t i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}
	return *this;
}

Array& Array::operator=(Array&& other)
{
	if (this != &other) {
		if (array != nullptr)
			delete[]array;
		this->array = other.array;
		this->size = other.size;
		other.array = nullptr;
		other.size = 0;
	}
	return* this;
}

Array::~Array()
{
	if (array != nullptr) {
		delete[] array;
		array = nullptr;
	}
}

Array Array::operator+(const Array& other) const
{
	Array result(this->size + other.size);
	for (size_t i = 0; i < this->size; i++)
	{
		result.array[i] = array[i];
	}
	for (size_t i = 0; i < other.size; i++)
	{
		result.array[i + size] = other.array[i];
	}
	return result;
}

Array& Array::operator++()
{
	for (size_t i = 0; i < size; i++)
	{
		array[i]++;
	}
	return *this; //повернення самого себе
}

Array Array::operator++(int)
{
	Array old = *this; // copy THIS in OLD
	++* this; // виклик префіксної форми
	return old;
}

Array::operator int() const
{
	int suma = 0;
	for (size_t i = 0; i < size; i++)
	{
		suma += this->array[i];
	}
	return suma;
}

int& Array::operator[](int index)
{
	static int garbage;//0
	if (isValidIndex(index))
	{
		return array[index];
	}
	std::cerr << ">>>>>>>>>>>>>>>>>>>>>Error: index is not valid!" << std::endl;
	return garbage;
}

bool Array::operator==(const Array& other)
{
	if (size == other.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (other.array[i] != array[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

Array Array::operator()(const size_t index, size_t howMany)
{
	if (index > size - 1)
		return Array();
	size_t k = 0;
	Array result(howMany);// 0000000000000000
	for (size_t i = index; k < howMany && i < size; i++)
	{
		result.array[k] = array[i];
		k++;
	}
	return result;
}

void Array::print() const
{
	cout << "Array: " << (size == 0 ? "empty" : "");
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\nSize: " << size << endl;
	cout << endl;

}