#include "binary_trees.h"
#include <stddef.h>

avl_t *sorted_array_to_avl_helper(avl_t *parent, int *array, int start,
		int end);

/**
 * sorted_array_to_avl_helper - Recursive helper function to build AVL tree
 *
 * @array: Pointer to the first element of the array
 * @start: Starting index of the current subarray
 * @end: Ending index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the created AVL tree,
 * or NULL on failure
 */

avl_t *sorted_array_to_avl_helper(avl_t *parent, int *array, int start,
		int end)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (start <= end)
	{
		mid = (start + end) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = sorted_array_to_avl_helper(root, array, start,
				mid - 1);
		root->right = sorted_array_to_avl_helper(root, array,
				mid + 1, end);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree,
 * NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (sorted_array_to_avl_helper(NULL, array, 0,
				((int)(size)) - 1));
}
