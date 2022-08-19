#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* STRUCTS AND DEFINITIONS */

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

/* Binary Tree */
typedef struct binary_tree_s binary_tree_t;

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;

/* FUNCTION PROTOTYPES */

/* given function to print binary tree */
void binary_tree_print(const binary_tree_t *);

/* function that creates a binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* function that inserts a value into a Max Binary Heap */
heap_t *heap_insert(heap_t **root, int value);
/* subfunction to determine the height of the tree */
size_t binary_tree_height(heap_t *root);
/* subfunction to find location to insert at to maintain completeness */
heap_t *find_location(heap_t *root, size_t level);
/* subfunction to swap newly inserted node with parent for max heap order */
heap_t *swap_child(heap_t **root, heap_t *new);

#endif /* BINARY_TREES_H */
