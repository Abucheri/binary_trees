#include "binary_trees.h"
#include <stddef.h>

size_t binary_tree_size(const binary_tree_t *tree);
int tree_is_complete(const binary_tree_t *tree, int index, int nnodes);
int binary_tree_is_complete(const binary_tree_t *tree);
int parent_c(const binary_tree_t *tree);

/**
 * binary_tree_size - Measures size of binary tree
 *
 * @tree: The root
 *
 * Return: Size of the tree,
 * else, 0 for NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - Checks if tree is complete
 *
 * @tree: Pointer to the root
 * @index: Index of node
 * @nnodes: No. of nodes
 *
 * Return: 1, for tree completion,
 * else, 0
 */

int tree_is_complete(const binary_tree_t *tree, int index, int nnodes)
{
	if (tree == NULL)
		return (1);
	if (index >= nnodes)
		return (0);
	return (tree_is_complete(tree->left, (2 * index) + 1, nnodes) &&
		tree_is_complete(tree->right, (2 * index) + 2, nnodes));
}

/**
 * binary_tree_is_complete - Calls the complete checker
 *
 * @tree: The root
 *
 * Return: 1 if complete,
 * else, 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nnodes;

	if (tree == NULL)
		return (0);
	nnodes = binary_tree_size(tree);
	return (tree_is_complete(tree, 0, nnodes));
}

/**
 * parent_c - Checks if parent has higher val than its child
 *
 * @tree: Pointer to the node
 *
 * Return: 1 parent val is higher,
 * else, 0
 */

int parent_c(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->n > tree->parent->n)
		return (0);
	return (parent_c(tree->left) && parent_c(tree->right));
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
	if (!binary_tree_is_complete(tree))
		return (0);
	return (parent_c(tree->left) && parent_c(tree->right));
}
