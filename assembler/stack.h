#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct _stack 
{
	int count;
	int allocatedMemory;
	double *arr;
} stack;
void init (stack *s);
void end (stack *s);
bool push (stack *s, int y);
double pop (stack *s);
bool isEmpty (stack *s);
void print (stack *s);
bool add (stack *s);
bool sub (stack *s);
bool mul (stack *s);
bool diiv (stack *s);
void push_x (stack *s, int a, int* mas);
void pop_x (stack *s, int a, int* mas);
void mov (int a, int b, int* mas);
void in (stack *s);
void add_x (int a, int b, int* mas);
void sub_x (int a, int b, int* mas);
void mul_x (int a, int b, int* mas);
void div_x (int a, int b, int* mas);
void out (stack *s);
int cmp (int a, int b, int *mas);
void print_x (int a, int *mas);
int jmp (int a, int j);
void dec (int a, int *mas);
void inc (int a, int *mas);
int je (int a, int j, int c);
int jne (int a, int j, int c);
