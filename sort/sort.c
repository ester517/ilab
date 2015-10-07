#include <stdio.h>
#define N 1000

void bubblesort(int *a, int n) 
{
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
}

void quickSort(int * a, int b, int e) 
{ 
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
}

