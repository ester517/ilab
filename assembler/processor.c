#include <stdio.h>
#include "stack.h"
#include "assembler.h"
char OFNAME[256];
int main()
{ 
	int i;
	int t;
	printf("Name of file.bin:\n");
	scanf("%s", OFNAME);
	ofp = fopen(OFNAME, "rb");
	for (t = 0; t < 5; t++)
		fread(&label[t], sizeof(int), 1, ofp);
	fread(&i, sizeof(int), 1, ofp);
	int *mas = (int *)calloc(i, sizeof(int));
	fread(mas, sizeof(int), i, ofp);
	fclose(ofp);	
	int cmp_ans = 0;
	int rec[3];
	int j = 0;
	double c;
	int r;
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
		if (mas[j] == cpush_x)
		{
			j++;
			push_x(&s ,mas[j], rec);
		}
		else
		if (mas[j] == cpop_x)
		{
			j++;
			pop_x(&s ,mas[j], rec);
		}
		else
		if (mas[j] == cmov)
		{
			j++;
			mov(mas[j], mas[j + 1], rec);
			j++;
		}
		else
		if (mas[j] == cin)
		{
			in(&s);
		}
		else
		if (mas[j] == cout)
		{
			out(&s);
		}
		else
		if (mas[j] == cadd_x)
		{
			j++;
			add_x(mas[j], mas[j + 1], rec);
			j++;
		}
		else
		if (mas[j] == csub_x)
		{
			j++;
			sub_x(mas[j], mas[j + 1], rec);
			j++;
		}
		else
		if (mas[j] == cmul_x)
		{
			j++;
			mul_x(mas[j], mas[j + 1], rec);
			j++;
		}
		else
		if (mas[j] == cdiv_x)
		{
			j++;
			div_x(mas[j], mas[j + 1], rec);
			j++;
		}
		else
		if (mas[j] == ccmp)
		{
			j++;
			cmp_ans = cmp(mas[j], mas[j + 1], rec);
			j++;
		}
		else 
		if (mas[j] == cprint_x)
		{
			j++;
			print_x(mas[j], rec);
		}
		else
		if (mas[j] == cinc)
		{
			j++;
			inc(mas[j], rec);
		}
		else
		if (mas[j] == cdec)
		{
			j++;
			dec(mas[j], rec);
		}
		else
		if (mas[j] == cjmp)
		{
			j = jmp(label[mas[j]], j);
			j++;
		}
		else
		if (mas[j] == cje)
		{	
			r = j;
			j++;
			j = je(label[mas[j] - 1], j, cmp_ans);
			j--;
			if (r == j) j++;
		}
		else
		if (mas[j] == cjne)
		{
			r = j;
			j++;
			j = jne(label[mas[j] - 1], j, cmp_ans);
			j--;
			if (r == j) j++;
		} 
		else
		if (mas[j] == ccal)
		{
			r = j;
			j++;
			j = cal(label[mas[j] - 1], j);
		}
		else
		if (mas[j] == cret)
		{
			j = ret(r, j);
		j++;
		}
		else
		if (mas[j] == cend)
		{
			end(&s);
			j = i - 1;
		}
	j++;
	}	
	return 0;
}
