#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, or NULL if not found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor = NULL;

	if (!first || !second)
		return (NULL);
	while (first)
	{
		const binary_tree_t *temp = second;

		while (temp)
		{
			if (temp == first)
				return ((binary_tree_t *)first);
			temp = temp->parent;
		}
		first = first->parent;
	}
	return ((binary_tree_t *)ancestor);
}
