#include <stdlib.h>
#include "binary_trees.h"
 
/**
 * create_node - Creates a new binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
static binary_tree_t *create_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;
 
	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
 
/**
 * build_avl - Recursively builds an AVL tree from a sorted array
 * @parent: Pointer to the parent node
 * @array: Sorted array of integers
 * @start: Start index of the current subarray
 * @end: End index of the current subarray (inclusive)
 *
 * Return: Pointer to the root of the subtree, or NULL on failure
 */
static avl_t *build_avl(avl_t *parent, int *array, int start, int end)
{
	avl_t *node;
	int mid;
 
	if (start > end)
		return (NULL);
 
	mid = (start + end) / 2;
	node = create_node(parent, array[mid]);
	if (!node)
		return (NULL);
 
	node->left  = build_avl(node, array, start, mid - 1);
	node->right = build_avl(node, array, mid + 1, end);
	return (node);
}
 
/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
 
	return (build_avl(NULL, array, 0, (int)size - 1));
}