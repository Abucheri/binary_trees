#include "binary_trees.h"
#include <stddef.h>

size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int tree_is_perfect(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * binary_tree_height - Measures height of a binary tree
 *
 * @tree: Tree to traverse
 *
 * Return: Height output
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_child = 0;
	size_t right_child = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
		return (tree->parent != NULL);
	if (tree)
	{
		left_child = tree->left ? 1 +
			binary_tree_height(tree->left) : 0;
		right_child = tree->right ? 1 +
			binary_tree_height(tree->right) : 0;
	}
	return ((left_child > right_child) ?
			left_child : right_child);
}

/**
 * binary_tree_balance - Measures the balance factor
 *
 * @tree: Tree to traverse
 *
 * Return: The factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, all = 0;

	if (tree)
	{
		left = ((int)binary_tree_height(tree->left));
		right = ((int)binary_tree_height(tree->right));
		all = left - right;
	}
	return (all);
}

/**
 * tree_is_perfect - Checks if tree is perfect
 *
 * @tree: The binary tree
 *
 * Return: 0 if is not perfect
 */

int tree_is_perfect(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree->left && tree->right)
	{
		left = 1 + tree_is_perfect(tree->left);
		right = 1 + tree_is_perfect(tree->right);
		if (right == left && right != 0 && left != 0)
			return (right);
		return (0);
	} else if (!tree->left && !tree->right)
		return (1);
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a tree is perfect
 *
 * @tree: Tree to check
 *
 * Return: 1 if perfect
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int final_output = 0;

	if (tree == NULL)
		return (0);
	final_output = tree_is_perfect(tree);
	if (final_output != 0)
		return (1);
	return (0);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int value;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);
	if (binary_tree_is_perfect(tree))
		return (1);
	value = binary_tree_balance(tree);
	if (value == 0)
	{
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_heap(tree->right));
	}
	if (value == 1)
	{
		return (binary_tree_is_heap(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}
	return (0);
}
