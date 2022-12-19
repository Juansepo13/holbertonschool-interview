#include "search_algos.h"

/**
 * print_array - prints an array
 * @array: array to print
 * @size: size of the array
 * Return: void
 */
void print_array(int *array, size_t size)
{
	if (size == 0)
	{
		printf("\n");
		return;
	}

	printf("%d", *array);
	if (size != 1)
		printf(", ");

	print_array(array + 1, size - 1);
}

/**
 * _advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * @index: index of the array
 * Return: index where value is located or -1
 */
int _advanced_binary(int *array, size_t size, int value, int index)
{
	size_t new_size = (size + 1) / 2;

	if (size == 0)
		return (-1);

	printf("Searching in array: ");
	print_array(array, size);

	if (size == 1)
		return (*array == value ? index : -1);

	if (size == 2 && (*array == value || *(array + 1) == value))
		return (*array == value ? index : index + 1);

	if (array[new_size - 1] >= value)
		return (_advanced_binary(array, size - (size / 2), value, index));

	return (_advanced_binary(
		array + new_size,
		size - new_size,
		value,
		index + new_size));
}
