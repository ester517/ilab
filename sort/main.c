#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main()
{
    int n, i;
    int a[N], b[N];
	clock_t time;
    scanf("%d", &n);
    for(i = 0 ; i < n; i++)
    {
		a[i] = rand();
		b[i] = a[i];
	}
   time = bubblesort(a, n);
    
    for(i = 0 ; i < n; i++) 
        printf("%d", a[i]);
    printf ("Working time: %ld\n", time);    
    
    time = quickSort(b, 0, n - 1);
    for(i = 0 ; i < n; i++) 
        printf("%d", b[i]);
    printf ("Working time: %ld\n", time);        
    return 0;
}
