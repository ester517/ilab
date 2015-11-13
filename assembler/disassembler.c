#include "assembler.h"
char OFNAME[256], IFNAME[256];
int main()
{	
	printf("Name of iffile:\n");
	scanf("%s", OFNAME);
	printf("Name of offile:\n");
	scanf("%s", IFNAME);
	int i;
	ofp = fopen(OFNAME, "rb");
	fread(&i, sizeof(int), 1, ofp);
	int *mas = (int *)calloc(i, sizeof(int));
	fread(mas, sizeof(int), i, ofp);
	fclose(ofp);	
	ifp1 = fopen(IFNAME, "w");
	fprintf(ifp1, "%d\n", i);
	int j = 0;
	int cmd;
	int c;
	#define DEF_CMD(name, num)\
		if (mas[j] == num)\
		{\
			fprintf(ifp1, "%s\n", name);\
			cmd = num;\
			j++;\
		if (cmd == 1)\
		{\
			c = mas[j];\
			fprintf(ifp1, "%d\n", c);\
			j++; \
		}\
	} else
	while (j != i)
	{
		#include "cmdlist.h"
		printf("error");
	}
	#undef DEF_CMD
	fclose(ifp1);
	free(mas);
	return 0;
}

