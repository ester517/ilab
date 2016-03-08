#include "stack.h"
#include <iostream>
#include <cassert>
cstack::cstack(int size)
{
	if (stackNumber > 1)
	{
		std::cout << "error only 2 stack\n"<< std::endl;
		exit(EXIT_FAILURE);
	}
	arr = new double [size];
	allocatedMemory = size;
	stackNumber++;
	count = 0;
}
cstack::cstack()
{
	
	if (stackNumber > 1)
	{
		std::cout << "error only 2 stack\n"<< std::endl;
		exit(EXIT_FAILURE);
	}
	arr = new double [size0];
	allocatedMemory = size0;
	count = 0;
	stackNumber++;
}
cstack::~cstack()
{
	delete [] arr;
	stackNumber--;
}
bool cstack::push(double x)
{
	if (count == allocatedMemory)
	{	
		allocatedMemory *= 2;
		arr = (double *)realloc(arr, allocatedMemory*sizeof(double));
		assert(arr != NULL);
	}
	
	if (allocatedMemory < 0) 
	return false;
	arr[count] = x;
	count++;
	return true;
}
bool  cstack::is_Empty()
{
	if (count == 0)
		return true;
	return false;
}

double  cstack::pop()
{
	if (is_Empty() == 1) return no;
	count --;
	double t = arr[count];
	return t;
}

