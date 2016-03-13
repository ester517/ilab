#include <iostream>
#include "vector.h"
int main()
{
	Cvector<int> a(3), b(3), c(3);
	a[0] = 3;
	a[1] = 3;
	a[2] = 3;
	int k = a[0];
	std::cout << k << std::endl;
	b[0] = 2;
	b[1] = 2;
	b[2] = 2;
	c = a + b;
	std::cout << c[0] << " " << c[1] << " " << c[2] << std::endl;
	a = a * 3;
	std::cout << a[0] << " " << a[1] << " " << a[2] << std::endl;
	int f;
	f = a & b;
	std::cout << f << std::endl;
	double t = a ^ b;
	std::cout << t << std::endl;
	return 0;
}

