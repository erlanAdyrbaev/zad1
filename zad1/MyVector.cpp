#include "MyVector.h"
#include <exception>
#include <iostream>
MyVector::MyVector() {
	arr = new int[5];
	size = 3;
	buf = 2;
}
MyVector::MyVector(const int& size) {
	buf = 2;
	this->size = size;
	arr = new int[this->size + buf];

	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}
MyVector::MyVector(const int& size,const int& num) {
	if (size < 0) {
		throw std::exception("negative size ");
	}
	else { 
		this->size = size;
		buf = 2;
	arr = new int[size + buf];
	
	} 
	for (int i = 0; i < size; i++) {
		arr[i] = num;
	}
}
MyVector::MyVector(MyVector& arrOld) {
	this->size = arrOld.size;
	this->buf = arrOld.buf;

	int* arr = new int[arrOld.size];
	for (int i = 0; i < arrOld.size; i++) {
		arr[i] = arrOld[i];
	}
	
}
MyVector::~MyVector() {
	delete[] arr;
	arr = nullptr;
}
	int& MyVector::operator [](const int& i) {
		{
			if (i > size || i < 0) {
				throw std::exception("the index > size  array or < 0");
			}
			else return arr[i];
		}
	}
	const int MyVector::getSize() {
		return this->size;
	}
	void MyVector::resize(const int& newSize) {
		if(newSize > 0){ 
			int* ptrbuf = arr;
			arr = new int[newSize + buf];
			for (int i = 0; i < newSize; i++) {
				if (i < size) {
					arr[i] = ptrbuf[i];
				}
				else arr[i] = 0;
			}
			size = newSize;
			delete[] ptrbuf;
			ptrbuf = nullptr;
		}
		else {
			throw std::exception("newSize negative or null");
		}
	}
	bool MyVector::operator >= (const MyVector& otherVector) const {
		for (int i = 0; i < size && i < otherVector.size; i++) {
			if (arr[i] > otherVector.arr[i]) {
				return true;
			}
			if (arr[i] < otherVector.arr[i]) {
				return false;
			}
		}
		if (size >= otherVector.size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool MyVector::operator > (const MyVector& otherVector) const {
		for (int i = 0; i < size && i < otherVector.size; i++) {
			if (arr[i] > otherVector.arr[i]) {
				return true;
			}
			if (arr[i] < otherVector.arr[i]) {
				return false;
			}
		}
		if (size > otherVector.size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool MyVector::operator <= (const MyVector& otherVector) const {
		for (int i = 0; i < size && i < otherVector.size; i++) {
			if (arr[i] < otherVector.arr[i]) {
				return true;
			}
			if (arr[i] > otherVector.arr[i]) {
				return false;
			}
		}
		if (size <= otherVector.size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool MyVector::operator < (const MyVector& otherVector) const {
		for (int i = 0; i < size && i < otherVector.size; i++) {
			if (arr[i] < otherVector.arr[i]) {
				return true;
			}
			if (arr[i] > otherVector.arr[i]) {
				return false;
			}
		}
		if (size < otherVector.size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool MyVector::operator == (const MyVector& otherVector) const {
		if (this == &otherVector) {
			return true;
		}
		if (size == otherVector.size) {
			for (int i = 0; i < size; i++) {
				if (arr[i] != otherVector.arr[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			throw std::exception("this vector size and otherVector size different");
		}
	}
	bool MyVector::operator != (const MyVector& otherVector) const {
		if (this == &otherVector) {
			return false;
		}
		if (size == otherVector.size) {
			for (int i = 0; i < size; i++) {
				if (arr[i] != otherVector.arr[i]) {
					return true;
				}
			}
			return false;
		}
		else {
			throw std::exception("this vector size and otherVector size different");
		}
	}
	MyVector MyVector::operator + (const MyVector& otherVector) const {
		MyVector result(size + otherVector.size);
		for (int i = 0; i < size; i++) {
			result.arr[i] = arr[i];
		}
		for (int j = 0; j < otherVector.size; j++) {
			result.arr[size + j] = otherVector.arr[j];
		}
		return result;
	}
	std::istream& operator >> (std::istream& in, MyVector& vector) {
		for (int i = 0; i < vector.getSize(); i++) {
			int value;
			//std::cout << "Entry vector[" << i << "]" << std::endl;
			in >> value;
			vector[i] = value;
		}
		return in;
	}
	std::ostream& operator << (std::ostream& out, MyVector& vector) {
		out << "MyVector: " << std::endl;
		for (int i = 0; i < vector.getSize(); i++) {
			out << "MyVector[" << i << "] : " << vector[i] << std::endl;
			}
		return out;
	}
	void MyVector::operator = (const MyVector& otherVector) {
		if (arr != nullptr) {
			delete[] arr;
		}
		size = otherVector.size;
		arr = new int[size + buf];
		for (int i = 0; i < size; i++) {
			arr[i] = otherVector.arr[i];
		}
	}