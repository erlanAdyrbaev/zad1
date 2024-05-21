#pragma once
#include <fstream>
class MyVector
{
private:
	int *arr = nullptr;
	int size;
	int buf;
public:
	MyVector();
	MyVector(const int& size);
	MyVector(const int& size, const int& num);
	MyVector(MyVector& arr);
	~MyVector();
	const int  getSize();
	int& operator [](const int& i);
	void resize(const int& newSize);
	bool operator > (const MyVector& otherVector) const;
	bool operator >= (const MyVector& otherVector) const;
	bool operator <= (const MyVector& otherVector) const;
	bool operator < (const MyVector& otherVector) const;
	bool operator == (const MyVector& otherVector) const;
	bool operator != (const MyVector& otherVector) const;
	MyVector operator + (const MyVector& otherVector) const;
	void operator = (const MyVector& otherVector);
};
std::istream& operator >> (std::istream& in, MyVector& vector);
std::ostream& operator << (std::ostream& out, MyVector& vector);

