#include <stdlib.h>
#include "binary_trees.h"
/**
* heap_insert - Inserts a value into a Max Binary Heap.
* @root: Double pointer to the root node of the Heap.
* @value: Value to store in the node to be inserted.
* Return: Pointer to the inserted node, or NULL on failure.
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = NULL;
	int change;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	else
	{
		new = insert_last(*root, value);
		if (!new)
			return (NULL);
	}
	while (new->parent && new->parent->n < new->n)
	{
		change = new->n;
		new->n = new->parent->n;
		new->parent->n = change;
		new = new->parent;
	}
	return (new);
}

/**
* push - Pushes a value into the queue.
* @last: Last element of queue.
* @node: Node to insert.
* Return: Node inserted or NULL if failed.
*/

queue *push(queue *last, heap_t *node)
{
	queue *new = malloc(sizeof(queue));

	if (!new)
		return (NULL);

	new->node = node;
	new->next = NULL;

	if (last)
		last->next =  new;
	return (new);

}

/**
* insert_last - Inserts in the last free position of a heap.
* @root: Root of the heap.
* @value: Value of new node.
* Return: Pointer to new node inserted or NULL on failure.
*/

heap_t *insert_last(heap_t *root, int value)
{
	queue *q, *last, *temp;
	heap_t *new = NULL;

	q = push(NULL, root);
	if (!q)
		return (NULL);
	last = q;
	while (q)
	{
		if (new)
		{
			temp = q;
			q = q->next;
			free(temp);
		}
		else if (q->node->left && q->node->right)
		{
			last = push(last, q->node->left);
			if (!last)
				return (NULL);
			last = push(last, q->node->right);
			if (!last)
				return (NULL);
			temp = q;
			q = q->next;
			free(temp);
		}
		else if (!q->node->left)
		{
			new = binary_tree_node(q->node, value);
			q->node->left = new;
		}
		else
		{
			new = binary_tree_node(q->node, value);
			q->node->right = new;
		}
	}
	return (new);
}
