#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: a pointer to the parent node for the node to create
 * @value: the value for the new node
 *
 * Return: pointer to the newly created node, or NULL if failed
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	/* Allocate memory for new node and check if NULL */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	/* Assign value and parent with given values */
	new_node->n = value;
	new_node->parent = parent;
	/* Set left and right children to NULL */
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
