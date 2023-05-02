#include "regex.h"
/**
 * regex_match - checks regex pattern in string
 * @str: string to be checked
 * @pattern: pattern to check
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	int check_dot = 0, check_star = 0;

	if (!str || !pattern)
		return (0);

	check_dot = *str && (*str == *pattern || *pattern == '.');
	check_star = *(pattern + 1) == '*';

	if (!*str && !check_star)
		return (*pattern ? 0 : 1);

	if (check_dot && check_star)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (check_dot && !check_star)
		return (regex_match(str + 1, pattern + 1));
	else if (check_star)
		return (regex_match(str, pattern + 2));

	return (0);
}
