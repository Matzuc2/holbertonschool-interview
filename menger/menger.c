#include <math.h>
#include <stdio.h>
#include "menger.h"

/**
 * is_hole - checks if position (x, y) falls in a hole at any sponge level
 * @x: column index
 * @y: row index
 *
 * Return: 1 if the cell is a hole, 0 otherwise
 */
static int is_hole(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);
		x /= 3;
		y /= 3;
	}
	return (0);
}

/**
 * menger - draws a 2D Menger Sponge of the given level
 * @level: level of the sponge (>= 0)
 */
void menger(int level)
{
	int size, x, y;

	if (level < 0)
		return;

	size = (int)pow(3, level);

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			if (is_hole(x, y))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
