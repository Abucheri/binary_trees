#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 *
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (tree);
	new_root = tree->left;
	tmp = new_root->right;
	new_root->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = new_root;
	new_root->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = new_root;
		else
			tmp->right = new_root;
	}
	return (new_root);
}
