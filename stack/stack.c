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
void dump(stack *s)
{
	int i;
	int n  = s -> count;
	if ( n == 0) 
	{
		printf("stack is empty");
		return;
	}
	for (i = 0; i < n; i++)
	{
		printf("%lf\n", pop(s));
	}
	return;
}
