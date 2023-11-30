#include "binary_trees.h"

bst_t *bst_insert_helper(bst_t *node, int value);

/**
 * bst_insert_helper - inserts nodes into BST
 *
 * @node: Pointer to parent node
 * @value: Value to insert into new node
 *
 * Return: Pointer to new node,  NULL on failure
 */

bst_t *bst_insert_helper(bst_t *node, int value)
{
	bst_t *new_node;

	if (value > node->n)
	{
		if (node->right)
			return (bst_insert_helper(node->right, value));
		new_node = binary_tree_node(node, value);
		node->right = new_node;
		return (new_node);
	} else if (value < node->n)
	{
		if (node->left)
			return (bst_insert_helper(node->left, value));
		new_node = binary_tree_node(node, value);
		node->left = new_node;
		return (new_node);
	}
	return (NULL);
}

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
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	return (bst_insert_helper(*tree, value));
}
