#include "slide_line.h"
#include <stddef.h>

/**
 * compact_left - shift all non-zero values to the left, zeros to the right
 */
static void compact_left(int *line, size_t size)
{
	size_t i, pos;

	pos = 0;
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[pos] = line[i];
			if (pos != i)
				line[i] = 0;
			pos++;
		}
	}
}

/**
 * compact_right - shift all non-zero values to the right, zeros to the left
 */
static void compact_right(int *line, size_t size)
{
	size_t i, pos;

	pos = size - 1;
	for (i = size; i-- > 0;)
	{
		if (line[i] != 0)
		{
			line[pos] = line[i];
			if (pos != i)
				line[i] = 0;
			if (pos > 0)
				pos--;
		}
	}
}

/**
 * slide_left - compact left, merge equal adjacent pairs, compact again
 */
static void slide_left(int *line, size_t size)
{
	size_t i;

	compact_left(line, size);

	/* merge adjacent equal pairs, left to right */
	i = 0;
	while (i + 1 < size)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
			i += 2; /* skip both cells: current (merged) and consumed */
		}
		else
		{
			i++;
		}
	}

	compact_left(line, size);
}

/**
 * slide_right - compact right, merge equal adjacent pairs, compact again
 */
static void slide_right(int *line, size_t size)
{
	size_t i;

	compact_right(line, size);

	/* merge adjacent equal pairs, right to left */
	i = size - 1;
	while (i > 0)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
			if (i >= 2)
				i -= 2;
			else
				break; /* i would underflow */
		}
		else
		{
			i--;
		}
	}

	compact_right(line, size);
}

/**
 * slide_line - slides and merges an array in the given direction
 * @line: pointer to the array of integers
 * @size: number of elements in the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}
	if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}
	return (0);
}
