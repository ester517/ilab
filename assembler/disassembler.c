#include "assembler.h"
char OFNAME[256], IFNAME[256];
int main()
{	
	printf("Name of iffile:\n");
	scanf("%s", OFNAME);
	printf("Name of offile:\n");
	scanf("%s", IFNAME);
	int i;
	int f;
	int t;
	ofp = fopen(OFNAME, "rb");
	for (t = 0; t < 5; t++)
		fread(&label[t], sizeof(int), 1, ofp);
	fread(&i, sizeof(int), 1, ofp);
	int *mas = (int *)calloc(i, sizeof(int));
	fread(mas, sizeof(int), i, ofp);
	fclose(ofp);	
	ifp1 = fopen(IFNAME, "w");
	fprintf(ifp1, "%d\n", i);
	int j = 0;
	int c;
	int k = 0;
	int sv = 0;
	#define DEF_CMD(name, num, arc)\
	if (mas[j] == num)\
		{\
			fprintf(ifp1, "%s\n", name);\
			j++;\
		if (arc == 1)\
		{\
			if ((num == cpush_x)||(num == cpop_x)||(num == cprint_x)||(num == cinc)||(num == cdec))\
				{\
					c = mas[j];\
					if (c == 1) fprintf(ifp1, "a\n");\
					if (c == 2) fprintf(ifp1, "b\n");\
					if (c == 3) fprintf(ifp1, "c\n");\
					j++;\
				} else \
				if ((num  == cjmp) || (num == cje) || (num == cjne) || (num == ccal) || (num == cret))\
				{\
					c = mas[j];\
					fprintf(ifp1, "%d\n", c);\
					j++; \
				}\
				else \
			{\
				c = mas[j];\
				fprintf(ifp1, "%d\n", c);\
				j++; \
			}\
		}else \
		{\
		if (arc == 2)\
		{\
			if (num == ccmp)\
			{\
				c = mas[j];\
				if (c == 1) fprintf(ifp1, "a\n");\
				if (c == 2) fprintf(ifp1, "b\n");\
				if (c == 3) fprintf(ifp1, "c\n");\
				j++;\
				c = mas[j];\
				fprintf(ifp1, "%d\n", c);\
				j++; \
			} else {\
			for (f = 0; f < 2; f++)\
			{\
				c = mas[j];\
				if (c == 1) fprintf(ifp1, "a\n");\
				if (c == 2) fprintf(ifp1, "b\n");\
				if (c == 3) fprintf(ifp1, "c\n");\
				j++;\
			}\
		}\
		}\
		}\
		k = 0;\
	} else
	while (j != i)
	{
		if ((j == label[0] - sv)&&(k == 0))
		{ 						
			fprintf(ifp1, ":1\n");
			k++;
			sv++;
		}
		else 
		if ((j == label[1] - sv)&&(k == 0))
		{
			fprintf(ifp1, ":2\n");
			k++;
			sv++;
		}
		else 
		if ((j == label[2] - sv)&&(k == 0))
		{										
			fprintf(ifp1, ":3\n");
			k++;
			sv++;
		}
		else 
		if ((j == label[3] - sv)&&(k == 0))
		{	
			fprintf(ifp1, ":4\n");
			k++;
			sv++;
		}
		else 
		if ((j == label[4] - sv)&&(k == 0))
		{	
			fprintf(ifp1, ":5\n");
			k++;
			sv++;
		}
		else 
			#include "cmdlist.h"
			printf("error ");
	}
	#undef DEF_CMD
	fclose(ifp1);
	free(mas);
	return 0;
}
