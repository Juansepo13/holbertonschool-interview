# 0x0D. Array to AVL
***
## This is a README.md for the repository
### In GitHub [0x0D-sorted_array_to_avl]()
```
For Holberton School
Cohort 16.
```
## General
* Basic Binary Tree
```
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

typedef struct binary_tree_s binary_tree_t;
```
* AVL Tree
```
typedef struct binary_tree_s avl_t;
```
![Alt text](https://media.geeksforgeeks.org/wp-content/uploads/AVL-Insertion1-1.jpg)


| File                 | Details                                    |
|--------------------- | ------------------------------------------ |
| [0-main.c]() | Main	       |
| [0-sorted_array_to_avl.c]() | function that builds an AVL tree from an array       |
| [binary_trees.h]() | Prototipes	       |


## Author
***
*Holberton School Student*

Juan Sebastian Posada  - [Github](https://github.com/Juansepo13) - [Twiter](https://twitter.com/@JuanSeb35904130)