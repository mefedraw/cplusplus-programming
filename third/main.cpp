#include <iostream>
#include "Triangle.h"
#include "Array.h"


int main() { 
	Triangle x({1, 2}, {3, 5}, {6, 8});
	Triangle y = Triangle({4, 2}, {7, 4}, {0, 0});

	std::cout << (x == y);

}