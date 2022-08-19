#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * Max Binary Heap must be complete tree with max as root node
 * @root: a double pointer to the root node of the Heap
 * @value: the value to store in the inserted node
 *
 * Return: pointer to the newly inserted node, or NULL if failed
 */

heap_t *heap_insert(heap_t **root, int value)
{
	size_t level = 0, height = 0;
	heap_t *location = NULL, *new = NULL;

	if (root == NULL)
		return (NULL);
	/* if given pointer to empty max binary heap, */
	/*   create new node and set root pointer to new node */
	if (*root == NULL)
	{
		new = binary_tree_node(*root, value);
		*root = new;
		return (new);
	}
	/* Determine height of max heap to move through level-by-level */
	height = binary_tree_height(*root);
	/* Move through heap using level-order travesal */
	for (level = 0; level < height; level++)
	{
		/* Use find_location to find next opening in complete tree */
		location = find_location(*root, level);
		/* if the location is not NULL, break and */
		/*   location will be used as node to insert off of */
		if (location != NULL)
			break;
	}
	/* Create and insert node with location as parent */
	new = binary_tree_node(location, value);
	/* if location had no left child, set left to new node */
	if (!location->left)
		location->left = new;
	/* Otherwise, set new node as location's right child */
	else
		location->right = new;
	/* Keep swapping nodes until max binary heap is achieved */
	while (new->parent && new->n > new->parent->n)
	{
		new = swap_child(root, new);
	}
	/* return newly inserted node */
	return (new);
}

/**
 * binary_tree_height - finds the height of completed binary tree
 * since the tree is completed, talled on left side
 * @root: pointer to the root node of the tree
 *
 * Return: returns the height of the overall tree
 */
size_t binary_tree_height(heap_t *root)
{
	if (root == NULL)
		return (0);
	/* Recursively call function, adding 1 for each layer found */
	/* Using left child, since heap is a complete tree */
	return (1 + binary_tree_height(root->left));
}

/**
 * find_location - finds first location that does not have a right child
 * the location may be a leaf or only have left child
 * since level-order traversal, will find location to add for complete tree
 * @root: pointer to the root node of the tree
 * @level: keeps track of the current level in the tree
 *
 * Return: location to insert new node off of, or NULL if has two children
 */
heap_t *find_location(heap_t *root, size_t level)
{
	heap_t *location = NULL;

	/* return NULL if no root pointer */
	if (root == NULL)
		return (NULL);
	/* if first level and no right child, return root node to insert from */
	/* check for right child because initially given a complete tree - */
	/*   doesn't matter if left child, it's first spot with missing child */
	if (level == 0 && root->right == NULL)
		return (root);
	/* if first level with both children, return NULL to continue */
	else if (level == 0)
		return (NULL);
	/* recursively call function for next level with left child as root */
	location = find_location(root->left, level - 1);
	/* if recursive call found valid location, return that location */
	if (location != NULL)
		return (location);
	/* recursively call function for next level with right child as root */
	location = find_location(root->right, level - 1);
	/* return valid location or NULL to continue */
	return (location);
}

/**
 * swap_child - swaps the new node with its parent
 * @root: double pointer to the root node of the max binary heap
 * @new: recently inserted node to swap
 *
 * Return: pointer to new node after switch
 */
heap_t *swap_child(heap_t **root, heap_t *new)
{
	int left = 0;
	heap_t *temp = new->parent, *temp_r = temp->right, *temp_l = temp->left;

	if (new->parent->left == new)
		left = 1;
	new->parent->right = new->right;
	if (new->right)
		new->right->parent = new->parent;
	new->parent->left = new->left;
	if (new->left)
		new->left->parent = new->parent;
	if (left)
	{
		new->right = temp_r;
		if (temp_r)
			temp_r->parent = new;
	}
	else
	{
		new->left = temp_l;
		if (temp_l)
			temp_l->parent = new;
	}
	new->parent = temp->parent;
	if (temp->parent)
	{
		if (temp->parent->left == temp)
			temp->parent->left = new;
		else
			temp->parent->right = new;
	}
	else
		*root = new;
	if (left)
		new->left = temp;
	else
		new->right = temp;
	temp->parent = new;
	return (new);
}
