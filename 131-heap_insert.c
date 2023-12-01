#include "binary_trees.h"
#include <stddef.h>

int tree_height(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
void swap_nodes(heap_t **arg_node, heap_t **arg_child);

/**
 * tree_height - Measures height of tree
 *
 * @tree: The root
 *
 * Return: The tree height
 */

int tree_height(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree == NULL)
		return (-1);
	left = tree_height(tree->left);
	right = tree_height(tree->right);
	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * binary_tree_is_perfect - Checks for perfect binary tree
 *
 * @tree: The root
 *
 * Return: 1 if perfect,
 * else, 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree && tree_height(tree->left) == tree_height(tree->right))
	{
		if (tree_height(tree->left) == -1)
			return (1);
		if ((tree->left && !((tree->left)->left) &&
			!((tree->left)->right)) && (tree->right &&
			!((tree->right)->left) && !((tree->right)->right)))
			return (1);
		if (tree && tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
					binary_tree_is_perfect(tree->right));
	}
	return (0);
}

/**
 * swap_nodes - Swaps nodes only if child is greater that the parent
 *
 * @arg_node: Parent node
 * @arg_child: Child node
 *
 * Return: Nothing
 */

void swap_nodes(heap_t **arg_node, heap_t **arg_child)
{
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *arg_node, child = *arg_child;
	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;
		node_left = child->left, node_right = child->right;
		if (left_right == 0)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		} else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *arg_node = child;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Pointer to the root of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (binary_tree_is_perfect(*root) ||
			!binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new_node = heap_insert(&((*root)->left), value);
			swap_nodes(root, &((*root)->left));
			return (new_node);
		}
		new_node = (*root)->left = binary_tree_node(*root, value);
		swap_nodes(root, &((*root)->left));
		return (new_node);
	}
	if ((*root)->right)
	{
		new_node = heap_insert(&((*root)->right), value);
		swap_nodes(root, (&(*root)->right));
		return (new_node);
	}
	new_node = (*root)->right = binary_tree_node(*root, value);
	swap_nodes(root, &((*root)->right));
	return (new_node);
}
