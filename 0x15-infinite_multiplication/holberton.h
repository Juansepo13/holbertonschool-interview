#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#define ERROR ("Error")
#define EXIT_ERROR()  \
do {                 \
	print(ERROR); \
	exit(98);     \
} while (0)

int _putchar(char c);

#endif /* HOLBERTON_H */
