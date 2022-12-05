#include "sort.h"

void heapify(int *array, size_t size, long int i, long int s);

/**
 * heap_sort - Function that sorts an array of integers in ascending order
 * using the "sift-down" Heap sort algorithm.
 * @array: Array to be sorted
 * @size: Size of Array
 */
void heap_sort(int *array, size_t size)
{
	long int i, aux;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		aux = array[0];
		array[0] = array[i];
		array[i] = aux;
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}

/**
 * heapify - order the tree - max heap
 * @array: Array to be sorted
 * @size: Size of Array
 * @i: index to start ordering the heap
 * @s: new size for ordering the heap
 */
void heapify(int *array, size_t size, long int i, long int s)
{
	long int j, max = i, aux;

	for (j = 1; j < 3 && s > (2 * i) + j; j++)
		if (array[i] < array[(2 * i) + j] && array[max] < array[(2 * i) + j])
			max = (2 * i) + j;

	if (max != i)
	{
		aux = array[i];
		array[i] = array[max];
		array[max] = aux;
		print_array(array, size);
		heapify(array, size, max, s);
	}
}
