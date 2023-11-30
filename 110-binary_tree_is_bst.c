#include "binary_trees.h"
#include <limits.h>
#include <stddef.h>

int is_bst_util(const binary_tree_t *tree, int min, int max);

/**
 * is_bst_util - Helper function to check if a binary tree is a valid BST
 *
 * @tree: Pointer to the root node of the tree
 * @min: The minimum value a node can have
 * @max: The maximum value a node can have
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */

int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (is_bst_util(tree->left, min, tree->n) &&
			is_bst_util(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_util(tree, INT_MIN, INT_MAX));
}
