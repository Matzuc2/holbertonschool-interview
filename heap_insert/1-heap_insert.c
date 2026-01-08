#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "binary_trees.h"

/* Forward declarations */
static size_t tree_size(const heap_t *tree);
static heap_t *get_node_at_index(heap_t *root, size_t index);
static void heapify_up(heap_t *node);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	size_t size;

	if (!root)
		return (NULL);

	/* If heap is empty, create root */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = tree_size(*root);

	/* Find parent of the new node */
	parent = get_node_at_index(*root, (size - 1) / 2);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	/* Insert as left or right child */
	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* Restore heap property */
	heapify_up(new_node);

	return (new_node);
}

/**
 * tree_size - Counts nodes in a binary tree
 * @tree: Pointer to root node
 *
 * Return: Number of nodes
 */
static size_t tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_node_at_index - Gets node at array index (heap logic)
 * @root: Root of the heap
 * @index: Index of the node to find
 *
 * Return: Pointer to node at index
 */
static heap_t *get_node_at_index(heap_t *root, size_t index)
{
	size_t path = index + 1;
	heap_t *node = root;
	size_t mask = 1UL << (sizeof(size_t) * 8 - 1);

	/* Find highest bit */
	while (!(path & mask))
		mask >>= 1;
	mask >>= 1;

	while (mask && node)
	{
		if (path & mask)
			node = node->right;
		else
			node = node->left;
		mask >>= 1;
	}

	return (node);
}

/**
 * heapify_up - Restore max heap ordering
 * @node: Node to heapify upward
 */
static void heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
}
