#ifndef _SORT_H_
#define _SORT_H_


#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *array, size_t i, size_t child, size_t total_size);
int heapify_down(int *array, size_t size);
void shift_down(int *array, size_t size, size_t total_size);
int check_array(int *array, size_t total_size);



#endif
