#include "sort.h"

void swap(int *array, size_t a, size_t b);
void sift_down(int array[], int root, int bottom, size_t size);

/**
 * heap_sort - function that implements a heap sort algorithm
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size / 2); i >= 0; i--)
	{
		sift_down(array, i, size - 1, size);
	}

	for (i = size - 1; i >= 1; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}

/**
 * swap - Function to swap elements
 * @array: array to swap
 * @a: swap element 1
 * @b: swap element 2
 */
void swap(int *array, size_t a, size_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

/**
 * sift_down - order according binary distribution
 * @array: pointer to array
 * @root: actual size
 * @bottom: actual position
 * @size: total size
 */
void sift_down(int array[], int root, int bottom, size_t size)
{
	int maxChild = root * 2 + 1, otherChild;

	if (maxChild < bottom)
	{
		otherChild = maxChild + 1;
		if (array[otherChild] > array[maxChild])
			maxChild = otherChild;
		else
			maxChild = maxChild;
	}
	else
	{
		if (maxChild > bottom)
			return;
	}

	if (array[root] >= array[maxChild])
		return;

	swap(array, root, maxChild);
	print_array(array, size);
	sift_down(array, maxChild, bottom, size);
}
