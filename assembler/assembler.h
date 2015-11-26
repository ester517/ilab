#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *ifp, *ifp1, *ofp; 
void check( int *mas, int i, int *n);
int label[5];
enum comd 
{
	cpush = 1,
	cpop = 2, 
	cadd = 3,
	csub = 4,
	cmul = 5,
	cdiv = 6,
	cprint = 7,
	cend = 8,
	cmov = 9,
	cpush_x = 10,
	cpop_x = 11,
	cin = 12,
	cjmp = 13,
	cjne = 14,
	cje = 15,
	cadd_x = 16,
	csub_x = 17,
	cmul_x = 18,
	cdiv_x = 19,
	ccmp = 20,
	cout = 21,
	ccal = 22,
	cret = 23,
	cprint_x = 24,
	cinc = 25,
	cdec = 26
};
