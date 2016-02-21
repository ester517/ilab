#include "stack.h"
#include <iostream>
cstack::cstack(int size)
{
	arr = new double [size];
	allocatedMemory = size;
	count = 0;
}
cstack::cstack()
{
	arr = new double [size0];
	allocatedMemory = size0;
	count = 0;
}
cstack::~cstack()
{
	delete [] arr;
}
bool cstack::push(double x)
{
	if (count == allocatedMemory)
	{	
		allocatedMemory *= 2;
		arr = (double *)realloc(arr, allocatedMemory*sizeof(double));
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

