#include <iostream>
#include <algorithm>
#include "MyVector.h"
int main() {
	int arr[] = { 1, 2 ,3 , 4, 5 };
	MyVector vector(5);
	std::cin >> vector;
	std::cout << "before resize: \n";
	std::cout << vector;
	/*for (int i = 0; i < 5; i++) {
		std::cout << vector[i] << " ";
	}*/
	vector.resize(10);
	std::cout << "after resize: \n";
	for (int j = 0; j < 10; j++) {
		std::cout << vector[j] << " ";
	}

}
