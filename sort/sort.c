#include <stdio.h>
#define N 1000

void bubblesort(int *a, int n) 
{
	int i, j;
	for(i = n - 1 ; i >= 0; i--) 
		for(j = 0 ; j < i ; j++)
			if(a[j] > a[j + 1])
			{
				int sw = a[j];
				a[j] = a[i];
				a[i] = sw;
			}
}

void quickSort(int * a, int n) 
{
	int i = 0, j = n - 1; 		
	int p, sw;
	p = a[(i + j) / 2 ];		
	do 
	{
		while ( a[i] < p ) i++;
			while ( a[j] > p ) j--;
			if (i <= j) 
			{
				sw = a[i]; a[i] = a[j]; a[j] = sw;
				i++; j--;
			}
	} while ( i<=j );
	if ( j > 0 ) quickSort(a, j);
	if ( n > i ) quickSort((a + i), n - i);
}

