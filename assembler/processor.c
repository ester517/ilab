#include <stdio.h>
#include "stack.h"
#include "assembler.h"
char OFNAME[256];
int main()
{ 
	int i;
	printf("Name of file.bin:\n");
	scanf("%s", OFNAME);
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
		if (mas[j] == cpush)
		{
			j++;
			push(&s, mas[j]); 
		} else
		if (mas[j] == cpop)
			c = pop(&s);
		else
		if (mas[j] == cadd)
			add(&s);
		else
		if (mas[j] == csub)
			sub(&s); 
		else
		if (mas[j] == cmul)
			mul(&s); 
		else
		if (mas[j] == cdiv)
			diiv(&s); 
		else
		if (mas[j] == cprint)
			print(&s); 
		else
		if (mas[j] == cend)
			end(&s); 
	j++;
	}	
	return 0;
}
