#include "assembler.h"
void check( int *mas, int i, int *n)
{
	if (i == *n)
	{
		*n *= 2;
		mas = (int *)realloc(mas, *n * sizeof(int));
	}
	return;
}
int main()
{
	ifp = fopen(IFNAME, "rb");
	ofp = fopen(OFNAME, "wb");
	char* cmd;
	int c;
	int *mas = (int *)calloc(128, sizeof(int));
	int n = 128;
	int i = 0;
	#define DEF_CMD(name, num) if (!strcmp(cmd, name))\
	{\
		check(mas, i, &n); \
		mas[i] = num;\
		i++;\
		if (num == 1)\
		{\
			check(mas, i, &n); \
			fscanf(ifp, "%d", &c);\
			mas[i] = c;\
			i++; \
		}\
	} else
	
	while (fscanf(ifp, "%s", cmd) != EOF)
	{	
		#include "cmdlist.h"
		printf("error");
	}
	#undef DEF_CMD
	
	fclose(ifp);
	fwrite(&i, sizeof(int), 1, ofp);
	fwrite( mas, sizeof(int), i, ofp);
	fclose(ofp);
	free(mas);
	return 0;
}
