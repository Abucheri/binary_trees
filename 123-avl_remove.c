#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

void balanc(avl_t **tree);
int avl_successor(bst_t *node);
int remove_types(bst_t *root);
bst_t *bst_remove(bst_t *root, int value);

/**
 * balanc - Measures balance factor
 *
 * @tree: The AVL tree
 *
 * Return: Balanced factor
 */

void balanc(avl_t **tree)
{
	int balanc_val;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balanc(&(*tree)->left);
	balanc(&(*tree)->right);
	balanc_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (balanc_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balanc_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * avl_successor - Gets next successor
 *
 * @node: tree to traverse
 *
 * Return: Min val
 */

int avl_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	left = avl_successor(node->left);
	if (left == 0)
		return (node->n);
	return (left);
}

/**
 * remove_types - Function which removes nodes depending on their children
 *
 * @root: Node to remove
 *
 * Return: 0 children don't exist
 */

int remove_types(bst_t *root)
{
	int new_node = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	} else if ((!root->left && root->right) || (!root->right &&
				root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	new_node = avl_successor(root->right);
	root->n = new_node;
	return (new_node);
}

/**
 * bst_remove - Removes a node from a BST
 *
 * @root: Root node
 * @value: Node val to remove
 *
 * Return: Updated tree
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int nnode = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		nnode = remove_types(root);
		if (nnode != 0)
			bst_remove(root->right, nnode);
	} else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 *
 * @root: Pointer to the root node of the tree
 * @value: Value to be removed
 *
 * Return: Pointer to the new root node of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *nroot = (avl_t *) bst_remove((bst_t *) root, value);

	if (nroot == NULL)
		return (NULL);
	balanc(&nroot);
	return (nroot);
}
