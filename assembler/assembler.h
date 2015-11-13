#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *ifp, *ifp1, *ofp; 
void check( int *mas, int i, int *n);
enum cmd 
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
	cinc = 12,
	cjmp = 13,
	cine = 14,
	cje = 15
};
