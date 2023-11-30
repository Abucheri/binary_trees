#include "binary_trees.h"
#include <stddef.h>

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t a, b;

	if (array == NULL)
		return (NULL);
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b]== array[a])
				break;
		}
		if (b == a)
		{
			if (bst_insert(&tree, array[a]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
