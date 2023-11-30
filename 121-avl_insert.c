#include "binary_trees.h"
#include <stddef.h>

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);

/**
 * height - Measures height of binary tree
 *
 * @tree: Pointer to the root node
 *
 * Return: 0 iff tree is NULL,
 * else return height
 */

size_t height(const binary_tree_t *tree)
{
	size_t left_child = 0, right_child = 0;

	if (tree != NULL)
	{
		left_child = tree->left ? 1 +
			binary_tree_height(tree->left) : 1;
		right_child = tree->right ? 1 +
			binary_tree_height(tree->right) : 1;
		return ((left_child > right_child) ? left_child :
				right_child);
	}
	return (0);
}

/**
 * balance - Measures balance factor of a binary tree
 *
 * @tree: Pointer to root node
 *
 * Return: 0 if tree is NULL,
 * else return balance factor
 */

int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Inserts val into an AVL tree recursively
 *
 * @tree: Double pointer to root node
 * @parent: Parent node of the current node
 * @new: Double pointer to store new node
 * @value: Val to insert
 *
 * Return: Pointer to new root,
 * NULL on failure
 */

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int b_factor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));
	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left,
				*tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	} else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right,
				*tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	} else
		return (*tree);
	b_factor = balance(*tree);
	if (b_factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (b_factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (b_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	} else if (b_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts val into AVL tree
 *
 * @tree: Double pointer  root node
 * @value: Val to insert
 *
 * Return: Pointer to inserted node,
 * NULL on failure
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new_node, value);
	return (new_node);
}
