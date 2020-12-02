#pragma once
class Array
{
public:
	Array(size_t size, int filler);
	Array(size_t size);
	Array() = default;
	Array(const Array& other);//COPY CTOR
	Array(Array && other);//MOVE CTOR
	~Array();

	Array& operator = (const Array& other); //assign with copy
	Array& operator = (Array&& other); //assign with moving 

	Array operator + (const Array& other)const;
	Array& operator++();
	Array operator++(int);

	explicit operator int() const;
	int& operator [] (int index);
	bool operator == (const Array& other);//binary
	Array operator()(const size_t index, size_t howMany);

	void print() const;
private:
	bool isValidIndex(size_t index) const;
	size_t size = 0;
	int* array = nullptr;
};
inline  bool Array::isValidIndex(size_t index) const
{
	return index < size ? true : false;
}

