#include "binary_trees.h"
#include <limits.h>

int is_avl(const binary_tree_t *tree, int min, int max, size_t *height);

/**
 * is_avl - Helper function to check if a tree is a valid AVL tree
 *
 * @tree: Pointer to the root node of the tree
 * @min: Minimum allowed value for the node (inclusive)
 * @max: Maximum allowed value for the node (inclusive)
 * @height: Pointer to store the height of the tree
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */

int is_avl(const binary_tree_t *tree, int min, int max, size_t *height)
{
	size_t left_height, right_height;

	if (!tree)
	{
		*height = 0;
		return (1);
	}
	if (tree->n <= min || tree->n >= max)
		return (0);
	if (!is_avl(tree->left, min, tree->n, &left_height) ||
			!is_avl(tree->right, tree->n, max, &right_height))
		return (0);
	*height = 1 + (left_height > right_height ? left_height :
			right_height);
	return ((left_height > right_height + 1 || right_height >
				left_height + 1) ? 0 : 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t height;

	if (!tree)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX, &height));
}
