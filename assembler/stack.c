#include "stack.h"
#define no -666
void init (stack *s)
{
	s -> count = 0;
	s -> allocatedMemory = 0;
	s -> arr = NULL;
}
void end (stack *s)
{
	free(s -> arr);
	s -> allocatedMemory = 0;
}
bool push (stack *s, int y)
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
	if (s -> allocatedMemory < 0) return false;
	s -> arr[s -> count] = y;
	s -> count ++;
	return true;
}
double pop (stack *s) 
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
void print (stack *s)
{
	int i;
	int n  = s -> count;
	if (n == 0) 
	{
		printf("stack is empty\n");
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
bool add (stack *s)
{
	double a,b;
	a = pop(s);
	b = pop(s);
	a = a + b;
	push(s, a);
	return true;
}
bool sub (stack *s)
{
	double a,b;
	a = pop(s);
	b = pop(s);
	a = b - a;
	push(s, a);
	return true;
}
bool mul (stack *s)
{
	double a,b;
	a = pop(s);
	b = pop(s);
	a = a * b;
	push(s, a);
	return true;
}
bool diiv (stack *s)
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
void push_x (stack *s, int a, int* mas)
{
	push(s, mas[a]); 
}
void pop_x (stack *s, int a, int* mas)
{
	mas[a] = pop(s); 
}
void mov (int a, int b, int* mas)
{
	int c;
	c = mas[a];
	mas[a] = mas[b];
	mas[b] = c; 
}
void in (stack *s)
{
	int f;
	scanf("%d", &f);
	push(s, f);
}
void out (stack *s)
{
	int a;
	a = pop(s);
	printf("%d\n", a);
	push(s, a);
}
void add_x (int a, int b, int* mas)
{
	mas[a] = mas[a] + mas[b];
}
void sub_x (int a, int b, int* mas)
{
	mas[a] = mas[a] - mas[b];
}
void mul_x (int a, int b, int* mas)
{
	mas[a] = mas[a] * mas[b];
}
void div_x (int a, int b, int* mas)
{
	if (mas[b] != 0)
		mas[a] = mas[a] / mas[b];
	else printf("Error/n");
}
int cmp (int a, int b, int *mas)
{
	if (mas[a] == b)
		return 1;
	return 0;
}
void print_x (int a, int *mas)
{
	printf("%d\n", mas[a]);
}
int jmp (int a, int j)
{
	j = a;
	return j;
}
void inc (int a, int *mas)
{
	mas[a] = mas[a] + 1;
}
void dec (int a, int *mas)
{
	mas[a] = mas[a] - 1;
}
int je (int a, int j, int c)
{	if ( c == 1)
	j = a;
	return j;
}
int jne (int a, int j, int c)
{	if ( c == 0)
	j = a;
	return j;
}
int cal (int a, int j)
{	
	j = a;
	return j;
}
int ret (int a, int j)
{
	j = a;
	return j;
}
