#include "binary_trees.h"

/**
 * Height - Method to retrieve the height
 * of the binary tree
 * @node: actual node
 *
 * Return: The height of the binary tree
 */

static size_t Height(const binary_tree_t *node)
{
	size_t h_left;
	size_t h_right;

	h_left = node->left ? 1 + Height(node->left) : 0;
	h_right = node->right ? 1 + Height(node->right) : 0;
	return (h_left > h_right ? h_left : h_right);
}

/**
 * preorderTraversal - browse through the binary tree
 * using preorder traversal method.
 * @root: root node
 * @node: actual node
 * @height: height of tree
 * @layer: layer on the tree
 **/

void preorderTraversal(heap_t *root, heap_t **node,
		       size_t height, size_t layer)
{
	if (!root)
		return;
	if (height == layer)
		*node = root;
	layer++;
	if (root->left)
		preorderTraversal(root->left, node, height, layer);
	if (root->right)
		preorderTraversal(root->right, node, height, layer);
}

/**
 * sort - Heap sort method.
 *
 * @tmp: temporary node
 *
 * Return: pointer to the last node
 **/

heap_t *sort(heap_t *tmp)
{
	int n;

	while (tmp->left || tmp->right)
	{
		if (!tmp->right || tmp->left->n > tmp->right->n)
		{
			n = tmp->n;

			tmp->n = tmp->left->n;
			tmp->left->n = n;
			tmp = tmp->left;
		}
		else if (!tmp->left || tmp->left->n < tmp->right->n)
		{
			n = tmp->n;

			tmp->n = tmp->right->n;
			tmp->right->n = n;
			tmp = tmp->right;
		}
	}

	return (tmp);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 *
 * @root: double pointer to the root of the heap
 *
 * Return: The value of the extracted root node, otherwise 0
 * on failure.
 */

int heap_extract(heap_t **root)
{
	int value;
	heap_t *tmp, *node;

	if (!root || !*root)
		return (0);

	tmp = *root;
	value = tmp->n;

	if (!tmp->left && !tmp->right)
	{
		*root = NULL;
		free(tmp);
		return (value);
	}

	preorderTraversal(tmp, &node, Height(tmp), 0);

	tmp = sort(tmp);
	tmp->n = node->n;

	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;

	free(node);

	return (value);
}
