#include "stack.h"
int main()
{ 
	int i;
	double t1  = 0, t2 = 0;
	stack s = {};
	init(&s);
	for (i = 0; i < 10; i++)
	{
		push( &s, (double)i);
	}
	dump(&s);
	if (isEmpty(&s)) printf("YES\n");
	push(&s, 7.7);
	push(&s, 6.6);
	t1 = pop(&s);
	t2 = pop(&s);
	push(&s, t1 + t2);
	dump(&s);
	end(&s);
	return 0;
}
