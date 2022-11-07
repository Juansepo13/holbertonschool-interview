#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (!array)
		return (NULL);

	return (create_tree(tree, array, 0, size - 1));
}

/**
 * create_tree - creates an AVL tree
 * @tree: pointer to the tree
 * @array: pointer to the first element of the array to be converted
 * @start: start index of array
 * @end: end index of array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 **/
avl_t *create_tree(avl_t *tree, int *array, int start, int end)
{
	size_t mid = (start + end) / 2;
	avl_t *node;

	if (start > end)
		return (NULL);

	node = node_maker(array[mid]);
	if (!node)
		return (NULL);

	node->parent = tree;
	node->left = create_tree(node, array, start, mid - 1);
	node->right = create_tree(node, array, mid + 1, end);

	return (node);
}

/**
 * node_maker - creates a node to an AVL tree
 * @n: data contained in node
 *
 * Return: node or NULL on failure
 **/
avl_t *node_maker(int n)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = n;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (!array)
		return (NULL);

	return (create_tree(tree, array, 0, size - 1));
}

/**
 * create_tree - creates an AVL tree
 * @tree: pointer to the tree
 * @array: pointer to the first element of the array to be converted
 * @start: start index of array
 * @end: end index of array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 **/
avl_t *create_tree(avl_t *tree, int *array, int start, int end)
{
	size_t mid = (start + end) / 2;
	avl_t *node;

	if (start > end)
		return (NULL);

	node = node_maker(array[mid]);
	if (!node)
		return (NULL);

	node->parent = tree;
	node->left = create_tree(node, array, start, mid - 1);
	node->right = create_tree(node, array, mid + 1, end);

	return (node);
}

/**
 * node_maker - creates a node to an AVL tree
 * @n: data contained in node
 *
 * Return: node or NULL on failure
 **/
avl_t *node_maker(int n)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = n;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
