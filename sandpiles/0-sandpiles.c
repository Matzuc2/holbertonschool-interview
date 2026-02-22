#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
 * is_stable - Check if a sandpile is stable
 * @grid: 3x3 grid
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - Perform one round of toppling
 * @grid: 3x3 grid
 */
static void topple(int grid[3][3])
{
	int i, j;
	int temp[3][3] = {{0}};

	/* Mark cells that need to topple */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				temp[i][j] = 1;
		}
	}

	/* Subtract 4 from cells that topple */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (temp[i][j])
				grid[i][j] -= 4;
		}
	}

	/* Add 1 to neighbors of cells that toppled */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (temp[i][j])
			{
				/* Add to top neighbor */
				if (i > 0)
					grid[i - 1][j] += 1;
				/* Add to bottom neighbor */
				if (i < 2)
					grid[i + 1][j] += 1;
				/* Add to left neighbor */
				if (j > 0)
					grid[i][j - 1] += 1;
				/* Add to right neighbor */
				if (j < 2)
					grid[i][j + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Stabilize grid1 */
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
