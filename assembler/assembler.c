#include "assembler.h"
char OFNAME[256], IFNAME[256];
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
	printf("Name of iffile:\n");
	scanf("%s", IFNAME);
	printf("Name of offile:\n");
	scanf("%s", OFNAME);
	ifp = fopen(IFNAME, "r");
	ofp = fopen(OFNAME, "wb");
	char* cmd = calloc(7, sizeof(char));
	int c;
	char s;
	int f;
	int k = 0;
	for (k = 0; k < 5; k++)
		label[k] = -1;
	int *mas = (int *)calloc(128, sizeof(int));
	int n = 128;
	int i = 0;
	k = 0;
	char *cmd1 = calloc(7, sizeof(char));
	fscanf(ifp, "%s", cmd1);
	while (fscanf(ifp, "%s", cmd) != EOF)
	{
		if ((cmd[0] == ':')&&(label[cmd[1] - '0' - 1 ] == -1)&&(cmd1[0] != 'c'))
			label[cmd[1] - '0' - 1] = k;
		cmd1 = cmd;	
		k++;
	}
	fclose(ifp);
	#define DEF_CMD(name, num, arc) if (!strcmp(cmd, name))\
	{\
		check(mas, i, &n); \
		mas[i] = num;\
		i++;\
		if (arc == 1)\
		{\
			if ((num == cpush_x) || (num == cpop_x) || (num == cprint_x) || (num == cinc) || (num == cdec))\
			{\
				check(mas, i, &n); \
				fscanf(ifp, "%c", &s);\
				fscanf(ifp, "%c", &s);\
				if (s == 'a')\
				{\
					check(mas, i, &n); \
					mas[i] = 1;\
					i++; \
				}\
				if (s == 'b')\
				{\
					check(mas, i, &n); \
					mas[i] = 2;\
					i++; \
				}\
				if (s == 'c')\
				{\
					check(mas, i, &n); \
					mas[i] = 3;\
					i++; \
				}\
			} else \
			if ((num == cjmp) || (num == cje) || (num == cjne) || (num == ccal))\
			{\
				check(mas, i, &n);\
				fscanf(ifp, "%c", &s);\
				fscanf(ifp, "%s", cmd);\
				if (cmd[0] == '1')\
					mas[i] = 1;\
				if (cmd[0] == '2')\
					mas[i] = 2;\
				if (cmd[0] == '3')\
					mas[i] = 3;\
				if (cmd[0] == '4')\
					mas[i] = 4;\
				i++;\
			}\
			else \
			{\
				check(mas, i, &n); \
				fscanf(ifp, "%d", &c);\
				mas[i] = c;\
				i++;\
			}\
		} else \
		if (arc == 2)\
		{\
			if (num == ccmp)\
			{\
				check(mas, i, &n); \
				fscanf(ifp, "%c", &s);\
				fscanf(ifp, "%c", &s);\
				if (s == 'a')\
				{\
					check(mas, i, &n); \
					mas[i] = 1;\
					i++; \
				}\
				if (s == 'b')\
				{\
					check(mas, i, &n); \
					mas[i] = 2;\
					i++; \
				}\
				if (s == 'c')\
				{\
					check(mas, i, &n); \
					mas[i] = 3;\
					i++; \
				}\
				check(mas, i, &n); \
				fscanf(ifp, "%d", &c);\
				mas[i] = c;\
				i++;\
			} else \
			{\
				for (f = 0; f < 2; f++)\
				{\
					check(mas, i, &n); \
					fscanf(ifp, "%c", &s);\
					fscanf(ifp, "%c", &s);\
					if (s == 'a')\
					{\
						check(mas, i, &n); \
						mas[i] = 1;\
						i++; \
					}\
					if (s == 'b')\
					{\
						check(mas, i, &n); \
						mas[i] = 2;\
						i++; \
					}\
					if (s == 'c')\
					{\
						check(mas, i, &n); \
						mas[i] = 3;\
						i++; \
					}\
				}\
			}\
		}\
	} else \
		if (cmd[0] == ':') i = i;\
	else 
	ifp = fopen(IFNAME, "r");
	while (fscanf(ifp, "%s", cmd) != EOF)
	{	
		#include "cmdlist.h"
		printf("error");
	}
	#undef DEF_CMD
	fclose(ifp);
	for (k = 0; k < 5; k++)
		fwrite(&label[k], sizeof(int), 1, ofp);
	fwrite(&i, sizeof(int), 1, ofp);
	fwrite( mas, sizeof(int), i, ofp);
	fclose(ofp);
	free(mas);
	free(cmd1);
	return 0;
}
