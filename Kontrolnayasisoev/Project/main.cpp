#include <iostream>
#include "Vector3d.h"

int main()
{
	Vector3d a = Vector3d(23, 4, 23);
	Vector3d b = a * 3;
	Vector3d c = a + b;
	std::cout << a << std::endl << b << std::endl << c;
	return 0;
}