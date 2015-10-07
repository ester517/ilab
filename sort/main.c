#include <stdio.h>
#include "sort.h"
#include <time.h>
#define N 1000

int main()
{
    int n, i;
    int a[N];
    time_t time1 = NULL;
    time (&time1);
    scanf("%d", &n);
    for(i = 0 ; i < n; i++) 
        scanf("%d", &a[i]);
    bubblesort(a, n);
    for(i = 0 ; i < n; i++) 
        printf("%d ", a[i]);
    time_t time2 = NULL;
    time (&time2);
    printf ("Working time: %ld\n", time2 - time1);    
	time (&time1);
    scanf("%d", &n);
    for(i = 0 ; i < n; i++) 
        scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    for(i = 0 ; i < n; i++) 
        printf("%d ", a[i]);
    time (&time2);
    printf ("Working time: %ld\n", time2 - time1);        
    return 0;
}
