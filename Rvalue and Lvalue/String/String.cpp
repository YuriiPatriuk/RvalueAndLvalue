#include "String.h"
#include <iostream>

String::String()
	:String(80)
{
}

String::String(const size_t size)
{
	setStringSize(size);
}

String::String(String&& other)
{
	cout << "~~~~~~~MOVING~~~~~~~" << endl;
	this->line = other.line;
	this->size = other.size;

	other.line = nullptr;
	other.size = 0;
}

void String::setLine(char* line)
{
	this->line = line;
}

void String::print()
{
	cout << "Line: " << line << endl;
	cout << "Size: " << size << endl;
}

void String::swap(String& one, String& two)
{
	String temp(move(one));
	one = move(two);
	two = move(temp);

}

void String::setStringSize(const size_t& size)
{
	this->size = size;
	line = new char[size] {};
}

String::String(const char* str)
{
	if (str == nullptr) {
		setStringSize(80);
		return;
	}
	this->size = strlen(str) + 1;
	setStringSize(size);
	strcpy_s(line, size, str);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		if (line != nullptr) {
			delete[] line;
		}
		line = new char[size = other.size];
		for (size_t i = 0; i < size; i++)
		{
			line[i] = other.line[i];
		}
	}
	return *this;
}

String& String::operator=(String&& other)
{
	cout << "~~~~~~MOVING~~~~~~" << endl;
	if (this != &other) {
		if (line != nullptr)
			delete[]line;
		
			this->line = other.line;
			this->size = other.size;
			other.line = nullptr;
			other.size = 0;
	
	}
	return*this;
}

String::String(const String& str)
{
	*this = str;
}

String::~String()
{
	if (line != nullptr) {
		delete[] line;
		line = nullptr;
	}
}
