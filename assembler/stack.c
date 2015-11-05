#include "stack.h"
#define no -666
void init(stack *s)
{
	s -> count = 0;
	s -> allocatedMemory = 0;
	s -> arr = NULL;
}
void end(stack *s)
{
	free(s -> arr);
	s -> allocatedMemory = 0;
}
bool push(stack *s, double x)
{
	if (s -> allocatedMemory == 0)
	{
		s -> arr = realloc (s -> arr, 1 * sizeof (double));
		s -> allocatedMemory ++;
	}
	if (s -> allocatedMemory == s -> count)
	{
		s -> arr = realloc (s -> arr, 2 * s -> allocatedMemory * sizeof (double));
		s -> allocatedMemory *= 2;
	}
	if ( s -> allocatedMemory < 0) return false;
	s -> arr[s -> count] = x;
	s -> count ++;
	return true;
}
double pop(stack *s) 
{ 
	if (s -> count > 0)
	{
		s -> count --;	
		double res = s -> arr[s -> count];
		return res;
	}	
	return no;
}
bool isEmpty(stack *s)
{
	if (s -> count == 0)
	return true;
	else return false;
}	
void print(stack *s)
{
	int i;
	int n  = s -> count;
	if ( n == 0) 
	{
		printf("stack is empty");
		return;
	}
	n--;
	while (n >= 0)
	{
	printf("%lg\n", s -> arr[n]);	
	n--;
	}
	return;
}
bool add(stack *s)
{
	double a,b;
	a = pop(s);
	b = pop(s);
	a = a + b;
	push(s, a);
	return true;
}
bool sub( stack *s)
{
	double a,b;
	a = pop(s);
	b = pop(s);
	a = b - a;
	push(s, a);
	return true;
}
bool mul( stack *s)
{
	double a,b;
	a = pop(s);
	b = pop(s);
	a = a * b;
	push(s, a);
	return true;
}
bool diiv( stack *s)
{
	double a, b, c;
	a = pop(s);
	b = pop(s);
	if ( a != 0)
	{ 
		c = b / a;
		push(s, c);
		return true;
	}
	return false;
}

