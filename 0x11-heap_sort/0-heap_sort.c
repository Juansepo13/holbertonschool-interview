#include "sort.h"

/**
 * heap_sort - sort an array of integers in ascending order
 * with sift-down heap sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int heapify = 0;
	size_t i, child_a, child_b;

	if (array == NULL || size < 2)
		return;
	while (heapify == 0)
	{
		for (i = size - 1; i > 0; i--)
		{
			child_a = (2 * i) + 1, child_b = (2 * i) + 2;
			if (child_a <= size - 1 && child_b >= size)
			{
				if (array[i] < array[child_a])
					swap(array, i, child_a, size);
			}
			else if (child_b <= size - 1 && child_a <= size - 1)
			{
				if (array[child_a] > array[i] || array[child_b] > array[i])
				{
					if (array[child_a] > array[child_b])
						swap(array, i, child_a, size);
					else
						swap(array, i, child_b, size);
				}
			}
		}
		for (i = size - 1; i > 0; i--)
		{
			child_a = (2 * i) + 1, child_b = (2 * i) + 2;
			if (child_a <= size - 1 && child_b >= size)
			{
				if (array[i] < array[child_a])
					break;
			}
			else if (child_b <= size - 1 && child_a <= size - 1)
			{
				if (array[child_a] > array[i] || array[child_b] > array[i])
					break;
			}
		}
		if (i == 0)
			heapify = 1;
	}
	shift_down(array, size, size);
}


/**
 * swap - swap two elements of an array
 * @array: array to swap
 * @i: index of the first element
 * @child: child to change
 *
 * Return: void
 */

void swap(int *array, size_t i, size_t child, size_t total_size)
{
	int tmp;

	tmp = array[i];
	array[i] = array[child];
	array[child] = tmp;
	print_array(array, total_size);
}

/**
 * shift_down - shift down an element of an array
 * @array: array to shift down
 * @size: size of the array
 *
 * Return: void
 */

void shift_down(int *array, size_t size, size_t total_size)
{
	size_t i, child_a, child_b, check = 0;

	for (i = 0; i < size - 1; i++)
	{
		child_a = (2 * i) + 1, child_b = (2 * i) + 2;
		if (child_a <= size - 1 && child_b >= size)
		{
			if (array[i] < array[child_a])
				swap(array, i, child_a, total_size);
		}
		else if (child_b <= size - 1 && child_a <= size - 1)
		{
			if (array[child_a] > array[i] || array[child_b] > array[i])
			{
				if (array[child_a] > array[child_b])
					swap(array, i, child_a, total_size);
				else
					swap(array, i, child_b, total_size);
			}
		}
	}
	for (i = 0; i < size - 1; i++)
	{
		child_a = (2 * i) + 1, child_b = (2 * i) + 2;
		if (child_a <= size - 1 && child_b >= size)
		{
			if (array[i] < array[child_a])
				break;
		}
		else if (child_b <= size - 1 && child_a <= size - 1)
		{
			if (array[child_a] > array[i] || array[child_b] > array[i])
				break;
		}
	}
	if (i != size - 1)
		shift_down(array, size, total_size);
	swap(array, 0, size - 1, total_size);
	check = check_array(array, total_size);
	if (check == 1 || size > 2)
		shift_down(array, size - 1, total_size);
}


/**
 * check_array - check if an array is sorted
 * @array: array to check
 * @size: size of the array
 *
 * Return: 0 if the array is sorted, 1 otherwise
 */

int check_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
			return (1);
	}
	return (0);
}
