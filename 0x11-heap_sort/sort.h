#ifndef _H_HEAP
#define _H_HEAP

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void aux_function(int *array, int n, int i, int size);
void print_array(const int *array, size_t size);

#endif /* _H_HEAP */
