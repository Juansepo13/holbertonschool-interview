#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>


void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void Merge(int *array, int start, int middle, int end, int *copy);
void Split(int *array, int start, int end, int *copy);

#endif