#include <stdio.h>
#include "solvesquareequation.h"

int main()
{
	double A, B, C;
	printf("Enter coefficients of your square equation: ");
	scanf("%lf %lf %lf", &A, &B, &C);
	double x1, x2;
	int n = solveSquareEquation(A, B, C, &x1, &x2);
	if (n == 0)
		printf("no solutions\n");
	if (n == 1)
		printf("one solution: %lf\n",x1);
	if (n == 2)
		printf("two solutions: %lf %lf\n",x1, x2);
	if (n == 100)
		printf("infinite solutions\n");
	return 0;
}
