#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct _stack 
{
	int count;
	int allocatedMemory;
	double *arr;
} stack;
void init(stack *s);
void end(stack *s);
bool push(stack *s, double x);
double pop(stack *s);
bool isEmpty(stack *s);
void dump(stack *s);
