#include "sort.h"
/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array[]
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (array == NULL)
		return;

	for (i = size / 2; i > 0; i--)
		aux_function(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0], array[0] = array[i],  array[i] = temp;
		print_array(array, size);
		aux_function(array, i, 0, size);
	}
}

/**
 * aux_function - aux_function recursive function to heap sort
 * @array: the array to sort
 * @n: variable size
 * @i: head
 * @size: size of array
 */
void aux_function(int *array, int n, int i, int size)
{
	int l, left, right, temp;

	left = (2 * i) + 1;
	right = (2 * i) + 2;
	l = i;
	left < n && array[left] > array[l] ? l = left : 0;
	right < n && array[right] > array[l] ? l = right : 0;
	if (l != i)
	{
		temp = array[i], array[i] = array[l], array[l] = temp;
		print_array(array, size);
		aux_function(array, n, l, size);
	}
}
