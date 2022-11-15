# 0x0E. Linear search in skip list
***
## This is a README.md for the repository
### In GitHub [0x0E-linear_skip]()
```
For Holberton School
Cohort 16.
```
## General

### search.h file

* Please define the following data structure in your search.h header file:
``` 
#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);
skiplist_t *linear_skip(skiplist_t *head, int value);

#endif /* _SEARCH_H_ */
```

![Alt text]()

## Extra resources around relational:

## More Info

## Files included

| File                 | Details                                    |
|--------------------- | ------------------------------------------ |
| []() |	       |
| []() |	       |
| []() |	       |
| []() |	       |
| []() |	       |
| []() |	       |
| []() |	       |
| []() |	       |
| []() |	       |
| []() |	       |


## Author
***
*Holberton School Student*

Juan Sebastian Posada  - [Github](https://github.com/Juansepo13) - [Twiter](https://twitter.com/@JuanSeb35904130)