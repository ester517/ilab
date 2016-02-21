#include <iostream>
#include "stack.h"
int main()
{
	cstack a(10);
	a.push(7);
	double x;
	x = a.pop(); 
	printf("%f", x);
	return 0;
}

