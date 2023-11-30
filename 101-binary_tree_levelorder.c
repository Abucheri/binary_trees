#include "binary_trees.h"
#include <stddef.h>

size_t binary_tree_height(const binary_tree_t *tree);
void _print_level(const binary_tree_t *tree, void (*f)(int), size_t lvl);

/**
 * binary_tree_height - Measure the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, function must return 0.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t r_side, l_side;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	l_side = binary_tree_height(tree->left);
	r_side = binary_tree_height(tree->right);
	if (l_side > r_side)
		return (l_side + 1);
	return (r_side + 1);
}

/**
 * _print_level - Print a level of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 * @lvl: The level of the binary tree to print.
 *
 * Return: Nothing
 */

void _print_level(const binary_tree_t *tree, void (*func)(int), size_t lvl)
{
	if (tree == NULL)
		return;
	if (lvl == 0)
		func(tree->n);
	lvl -= 1;
	_print_level(tree->left, func, lvl);
	_print_level(tree->right, func, lvl);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using
 * level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t lvl = 0, tr_size = 0;

	if (tree == NULL || func == NULL)
		return;
	tr_size = binary_tree_height(tree);
	for (; lvl <= tr_size; ++lvl)
		_print_level(tree, func, lvl);
}
