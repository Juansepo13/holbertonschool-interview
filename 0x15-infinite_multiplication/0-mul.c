#include "holberton.h"

/**
 * is_number - Verify that a string is numeric
 * @string: A string
 * Return: 1 if valid, 0 if invalid
 */
int is_number(char *string)
{
	if (string == NULL)
		return (0);

	if (*string == '\0')
		return (1);

	if ((*string < '0' || *string > '9') && *string != '-')
		return (0);

	return (is_number(string + 1));
}

/**
 * print - Prints a string
 * @string: A string
 */
void print(char *string)
{
	if (string == NULL)
		return;

	if (*string == '\0')
	{
		_putchar('\n');
		return;
	}

	_putchar(*string);
	print(string + 1);
}

/**
 * _strlen - Calculates the length of a string
 * @string: A string
 * Return: The number of bytes in the string excluding the null byte
 */
size_t _strlen(char *string)
{
	if (string == NULL || *string == '\0')
		return (0);

	return (1 + _strlen(string + 1));
}

/**
 * main - multiplies two positive numbers
 * @argc: count of argv
 * @argv: array of strings with the numbers
 * Return: success
 **/
int main(int argc, char **argv)
{
	char *num1 = NULL, *num2 = NULL;
	char *result = NULL;
	char digit_a = '\0', digit_b = '\0', sum = '\0';
	size_t result_length = 0, a_length = 0, b_length, k = 0;
	int i = 0, j = 0;

	if (argc != 3)
		EXIT_ERROR();
	num1 = argv[1];
	num2 = argv[2];
	if (!num1 || !is_number(num1) || !num2 || !is_number(num2))
		EXIT_ERROR();
	a_length = _strlen(num1);
	b_length = _strlen(num2);
	result_length = a_length + b_length;
	result = malloc(result_length);
	if (result == NULL)
		EXIT_ERROR();
	while ((size_t)i < result_length)
		result[i++] = 0;
	for (i = a_length - 1; i >= 0; i--)
	{	digit_a = num1[i] - '0';
		for (j = b_length - 1; j >= 0; j--)
		{	digit_b = num2[j] - '0';
			k = result_length - 1 - (b_length - j - 1) - (a_length - i - 1);
			result[k] += digit_a * digit_b;
			for (sum = result[k]; sum > 9; sum = result[k])
			{
				result[k--] = sum % 10;
				result[k] += sum / 10;
			}
		}
	}
	for (i = k; (size_t)i < result_length; i++)
		result[i] += '0';
	while (result[k] == '0' && k < result_length - 1)
		k++;
	print(result + k);
	free(result);
	return (EXIT_SUCCESS);
}