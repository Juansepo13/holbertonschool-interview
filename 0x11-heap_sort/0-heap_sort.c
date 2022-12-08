#include "sort.h"

/**
 * get_parent_index - gets the index of the parent of a node
 *
 * @child_index: the index of the child
 *
 * Return: the index of the parent
 */
size_t get_parent_index(size_t child_index)
{
	return ((child_index - 1) / 2);
}

/**
 * swap - swaps two elements in an array
 *
 * @prmArray: the array to be sorted
 * @prmSize: the size of the array
 * @prmIndex1: the index of the first element
 * @prmIndex2: the index of the second element
 */
void swap(int *prmArray, size_t prmSize, size_t prmIndex1, size_t prmIndex2)
{
	int temp = prmArray[prmIndex1];

	prmArray[prmIndex1] = prmArray[prmIndex2];
	prmArray[prmIndex2] = temp;
	print_array(prmArray, prmSize);
}

/**
 * sift_down - fixes a heap
 *
 * @prmArray: the heap to fix
 * @prmRoot: the root of the heap
 * @prmEnd: the last index of the heap
 * @prmSize: size of the array
 *
 * Return: void
 */
void sift_down(int *prmArray, size_t prmRoot, size_t prmEnd, size_t prmSize)
{
	size_t left_child, right_child, current, root;

	root = prmRoot;

	while ((left_child = (2 * root) + 1) <= prmEnd)
	{
		current = root;
		right_child = left_child + 1;

		/**
		 * if the left child is greater than the current node,
		 *  then the current node is the left child
		 */
		if (prmArray[current] < prmArray[left_child])
			current = left_child;

		/**
		 * if the right child is greater than the current node,
		 * then the current node is the right child
		 */
		if (right_child <= prmEnd && prmArray[current] < prmArray[right_child])
			current = right_child;

		if (current == root)
			return;

		/** Swap the values */
		swap(prmArray, prmSize, root, current);
		root = current;
	}
}

/**
 * make_heap - makes a heap from an unsorted array
 *
 * @array: array to turn into a heap
 * @size: size of the array
 *
 * Return: void
 */
void make_heap(int *array, size_t size)
{
	size_t parent;

	for (parent = get_parent_index(size - 1); 1; parent--)
	{
		sift_down(array, parent, size - 1, size);

		if (parent == 0)
			break;
	}
}

/**
 * heap_sort - Sorts an array using the heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (array == NULL || size < 2)
		return;

	make_heap(array, size);
	end = size - 1;

	while (end > 0)
	{
		swap(array, size, end, 0);
		end--;
		sift_down(array, 0, end, size);
	}
}
