#ifndef SEACH_ALGOS_H_
#define SEACH_ALGOS_H_

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, size_t size);
int _advanced_binary(int *array, size_t size, int value, int index);

#define advanced_binary(A, S, V) _advanced_binary(A, S, V, 0)

#endif /* SEACH_ALGOS_H_ */
