#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measure the height
 *
 * Return: The height of the tree starting at @node
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_child = 0, right_child = 0;

	if (tree)
	{
		left_child = tree->left ?
			1 + binary_tree_height(tree->left) : 0;
		right_child = tree->right ?
			1 + binary_tree_height(tree->right) : 0;
		return ((left_child > right_child) ? left_child : right_child);
	}
	return (0);
}
