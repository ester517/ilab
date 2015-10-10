#include "sort.h"
clock_t bubblesort(int *a, int n) 
{
	clock_t t = NULL;
	t = clock();
	int i = 0, j = 0;
	for(i = n - 1 ; i >= 0; i--) 
	{
		for(j = 0 ; j < i ; j++)
		{
			if(a[j] > a[j + 1])
			{
				int sw = a[j];
				a[j] = a[j + 1];
				a[j + 1] = sw;
			}
		}
	}
	t = clock() - t;
	return t;
}

clock_t quickSort(int * a, int b, int e) 
{ 
	clock_t t = NULL;
	t = clock();
	int l = b, r = e; 		
	int p = a[(l + r) / 2 ];		
	do
	{
		while ( a[l] < p ) l++;
			while ( a[r] > p ) r--;
			if (l <= r) 
			{
				int tmp = a[l];
				a[l++] = a[r];
				a[r--] = tmp;
			}
	} while (l <= r); 
	if ( b < r ) quickSort(a, b, r);
	if ( e > l ) quickSort(a, l, e);
	t = clock() - t;
	return t;
}

