#pragma once
#include<iostream>
using namespace std;
class String
{
public:
	String();
	String(const size_t size);
	String(const String& str);//copy
	String(String&& other);//MOVE CTOR
	void setLine(char* line);
	void print();
	static void swap(String&&one, String&& two);

	String(const char* str);
	~String();
	String& operator=(const String& other);
	String& operator=(String&& other);

	void setStringSize(const size_t& size);
	const char* getStr() const {
		cout << line << endl;
	};
private:
	char* line=nullptr;
	size_t size = 0;

};


