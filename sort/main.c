#include <stdio.h>
#include "sort.h"
#define N 1000

int main()
{
    int n, i;
    int a[N];
    scanf("%d", &n);
    for(i = 0 ; i < n; i++) 
        scanf("%d", &a[i]);
    bubblesort(a, n);
    for(i = 0 ; i < n; i++) 
        printf("%d ", a[i]);
    scanf("%d", &n);
    for(i = 0 ; i < n; i++) 
        scanf("%d", &a[i]);
    quickSort(a, n);
    for(i = 0 ; i < n; i++) 
        printf("%d ", a[i]);
    return 0;
}
