#include "sort.h"

/**
 * merge_sort - sort an array using merge sort
 *
 * @array: array to sort
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i = 0;

	copy = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	Split(array, 0, size, copy);

	free(copy);
}

/**
 * Split - split an array
 *
 * @array: arr to sort
 * @copy: copy of the arr to sort
 * @start: starting index of the array
 * @end: ending index of the array
 */

void Split(int *array, int start, int end, int *copy)
{
	int mid = (start + end) / 2;
	int i = 0;

	if (end - start <= 1)
		return;

	Split(copy, start, mid, array);
	Split(copy, mid, end, array);
	printf("Merging...\n");
	printf("[left]: ");

	for (i = start; i < mid; i++)
	{
		printf("%d", copy[i]);
		if (i < mid - 1)
			printf(", ");
	}

	printf("\n[right]: ");

	for (i = mid; i < end; i++)
	{
		printf("%d", copy[i]);
		if (i < end - 1)
			printf(", ");
	}

	Merge(array, start, mid, end, copy);

	printf("\n");
	printf("[Done]: ");

	for (i = start; i < end; i++)
	{
		printf("%d", array[i]);
		if (i < end - 1)
			printf(", ");
	}

	printf("\n");
}

/**
 * Merge - merge two array
 *
 * @array: array to sort
 * @copy: copy of the array to sort
 * @start: starting index
 * @end:  ending index
 * @middle: middle index
 */

void Merge(int *array, int start, int middle, int end, int *copy)
{
	int s = start;
	int mid = middle;
	int i = 0;

	for (i = start; i < end; i++)
	{

		if (s < middle && (mid >= end || copy[s] <= copy[mid]))
		{
			array[i] = copy[s];
			s = s + 1;
		}
		else
		{
			array[i] = copy[mid];
			mid = mid + 1;
		}
	}
}
