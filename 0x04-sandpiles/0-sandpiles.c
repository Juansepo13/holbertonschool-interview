#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - sim sandpiles until grid1 is stable
 *
 * @grid1: 3x3 grid
 * @grid2: another 3x3 grid to be add with grid1
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int  i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}

	/* check that sandpile grid1 is stable */
	while (check_stable_sandpile(grid1))
	{
		print_grid(grid1);
		topple_sandpile(grid1);
	}
}


/**
 * check_stable_sandpile - checks if sandpiles are stable
 * @grid1: 3x3 to be checked
 * Return: 0 if stable, 1 otherwise
 */

int check_stable_sandpile(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (1);
		}
	}
	return (0);
}


/**
 * topple_sandpile - topples the sandpile that it receives
 * @grid1: sandpile to be toppled
 */

void topple_sandpile(int grid1[3][3])
{
	int i, j;
	int result_grid[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			result_grid[i][j] = grid1[i][j];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			/* if current cell is more than 3 grains, substract 4 */
			if (grid1[i][j] > 3)
				result_grid[i][j] -= 4;
			/* Check neighbor cells */
			if ((i - 1) >= 0 && (i - 1) < 3)
				if (grid1[i - 1][j] > 3)
					result_grid[i][j] += 1;
			if ((j - 1) >= 0 && (j - 1) < 3)
				if (grid1[i][j - 1] > 3)
					result_grid[i][j] += 1;
			if ((i + 1) >= 0 && (i + 1) < 3)
				if (grid1[i + 1][j] > 3)
					result_grid[i][j] += 1;
			if ((j + 1) >= 0 && (j + 1) < 3)
				if (grid1[i][j + 1] > 3)
					result_grid[i][j] += 1;
		}
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = result_grid[i][j];
}
