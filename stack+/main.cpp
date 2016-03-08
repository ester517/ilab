#include <iostream>
#include "stack.h"
int cstack::stackNumber = 0;
int main()
{
	cstack a(3);
	a.push(7);
	a.push(7);
	a.push(7);
	a.push(7);
	double x;
	x = a.pop(); 
	std::cout << x << std::endl;
	cstack b(6);
	b.push(3);
	x = b.pop();
	std::cout << x << std::endl;
	cstack c(7);
	return 0;
}

