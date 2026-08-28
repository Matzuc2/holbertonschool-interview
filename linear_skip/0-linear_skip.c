#include <stdio.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is found, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev;
	skiplist_t *node;

	if (!list)
		return (NULL);

	prev = list;

	/* Phase 1 : express lane — trouver la tranche contenant value */
	while (prev->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			prev->express->index, prev->express->n);

		if (prev->express->n >= value)
			break;

		prev = prev->express;
	}

	/*
	 * Ici prev est le dernier nœud express dont la valeur < value.
	 * prev->express est le premier nœud express dont la valeur >= value
	 * (ou NULL si on est en bout de liste).
	 * La valeur se trouve donc entre prev et prev->express.
	 */
	if (prev->express)
		printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, prev->express->index);
	else
	{
		/* Trouver le dernier index de la liste */
		node = prev;
		while (node->next)
			node = node->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, node->index);
	}

	/* Phase 2 : recherche linéaire dans la tranche [prev, prev->express] */
	node = prev;
	while (node)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			node->index, node->n);

		if (node->n == value)
			return (node);

		/* Stopper dès qu'on dépasse la borne supérieure */
		if (prev->express && node->index == prev->express->index)
			break;

		node = node->next;
	}

	return (NULL);
}