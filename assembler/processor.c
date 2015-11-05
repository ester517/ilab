#include <stdio.h>
#include "stack.h"
#include "assembler.h"
int main()
{
	int i;
	ofp = fopen(OFNAME, "rb");
	fread(&i, sizeof(int), 1, ofp);
	int *mas = (int *)calloc(i, sizeof(int));
	fread(mas, sizeof(int), i, ofp);
	fclose(ofp);	
	
	int j = 0;
	double c;
	stack s;
	init(&s);
	while (j != i)
	{
		if (mas[j] == 1)
		{
			j++;
			push(&s, mas[j]);
			j++; 
		} else
		if (mas[j] == 2)
		{
			c = pop(&s);
			j++;
		} else
		if (mas[j] == 3)
		{
			add(&s);
			j++;
		} else
		if (mas[j] == 4)
		{
			sub(&s);
			j++; 
		} else
		if (mas[j] == 5)
		{
			mul(&s);
			j++; 
		} else
		if (mas[j] == 6)
		{
			diiv(&s);
			j++; 
		} else
		if (mas[j] == 7)
		{
			print(&s);
			j++; 
		} else
		if (mas[j] == 8)
		{
			end(&s);
			j++; 
		}
	}	
	return 0;
}
