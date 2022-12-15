#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main () {
    int a[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int n = sizeof a / sizeof a[0];
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    heap_sort(a, n);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
