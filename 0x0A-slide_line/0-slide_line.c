#include "slide_line.h"
/**
* slide_line - slides and merges an array of integers
* @line: points to an array of integers
* @size: number of elements in the array
* @direction: direction to slide and merge the integers
* Return: 1 upon success, or 0 upon failure
*/
int slide_line(int *line, size_t size, int direction)
{
	size_t find = 0, rep = 0, start = 1, stop = size;
	int flag = -1;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		find = size - 1;
		rep = size - 1;
		start = -1;
		stop = -1;
	}

	while (find != stop)
	{
		if (*(line + find) != 0)
		{
			if (flag == *(line + find))
			{
				*(line + find) += flag;
				flag = -1;
			}
			else
			{
				flag = *(line + find);
				if ((direction == SLIDE_LEFT && find != 0)
					||
					((direction == SLIDE_RIGHT && find != (size - 1))))
					if (*(line + rep) != 0)
						rep += start;
			}
			*(line + rep) = *(line + find);
			if (rep != find)
				*(line + find) = 0;
		} find += start;
	}
	return (1);
}
