#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"
/**
 * is_palindrome - checks whether or not a given integer is a palindrome.
 * @n: is the number to be checked
 * Return: 0 or 1 if is palindrome or not
 */
int is_palindrome(unsigned long n)
{
	unsigned long r, sum = 0, temp;

	temp = n;
	while (n > 0)
	{
		r = n % 10;
		sum = (sum * 10) + r;
		n = n / 10;
	}
	if (temp == sum)
		return (1);
	return (0);
}
