#include "sort.h"

/**
 * recurisve_heap - helper function to perform recursive heap sort
 * @array: int array to sort
 * @size: size of array
 * @root: parent node
 * @n: total size of array to be printed
*/
void recurisve_heap(int *array, size_t size, size_t root, size_t n)
{
	int temp;
	size_t largest = root, left = 2 * root + 1, right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;

		print_array(array, n);

		recurisve_heap(array, size, largest, n);
	}
}
/**
 * heap_sort - function that sorts an array of integers in
 * ascending order using the Heap sort algorithm
 * @array: int array to sort
 * @size: size of array
*/
void heap_sort(int *array, size_t size)
{
	int i, temp;

	for (i = size / 2 - 1; i >= 0; i--)
		recurisve_heap(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		if (i != 0)
			print_array(array, size);

		recurisve_heap(array, i, 0, size);
	}
}
