#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 *
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);
	bst_t *parent = NULL;
	bst_t *current = *tree;
	bst_t *new_node;

	while (current)
	{
		parent = current;
		if (value == current->n)
			return (NULL);
		current = (value < current->n) ? current->left :
			current->right;
	}
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);
	if (!parent)
		*tree = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;
	return (new_node);
}
