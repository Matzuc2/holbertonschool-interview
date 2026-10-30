#include "sort.h"

/**
 * sift_down - Restore the max heap property below a node
 * @array: Array containing the heap
 * @root: Index of the node to sift down
 * @end: Index of the last element in the heap
 * @size: Total number of elements in the array
 */
static void sift_down(int *array, size_t root, size_t end, size_t size)
{
	size_t child;
	size_t largest;
	int temporary;

	if (root >= end)
		return;

	while (root <= (end - 1) / 2)
	{
		child = root * 2 + 1;
		largest = child;

		if (child < end && array[child] < array[child + 1])
			largest = child + 1;
		if (array[root] >= array[largest])
			return;

		temporary = array[root];
		array[root] = array[largest];
		array[largest] = temporary;
		print_array(array, size);
		root = largest;
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order using heap sort
 * @array: Array to sort
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t root;
	size_t end;
	int temporary;

	if (array == NULL || size < 2)
		return;

	for (root = (size - 2) / 2 + 1; root > 0; root--)
		sift_down(array, root - 1, size - 1, size);

	for (end = size - 1; end > 0; end--)
	{
		temporary = array[0];
		array[0] = array[end];
		array[end] = temporary;
		print_array(array, size);
		sift_down(array, 0, end - 1, size);
	}
}