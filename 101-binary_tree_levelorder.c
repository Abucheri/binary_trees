#include "binary_trees.h"
#include <stdlib.h>

size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/* Recursively calculate size */
	return (1 + binary_tree_size(tree->left) +
			binary_tree_size(tree->right));
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
	if (!tree || !func)
		return;
	/* Use a queue to perform level-order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) *
			binary_tree_size(tree));
	size_t front = 0, rear = 0;

	if (!queue)
		return;
	/* Enqueue the root node */
	queue[rear++] = (binary_tree_t *)tree;
	/* Perform level-order traversal */
	while (front < rear)
	{
		/* Dequeue a node and apply the function */
		binary_tree_t *current = queue[front++];

		func(current->n);
		/* Enqueue left child if exists */
		if (current->left)
			queue[rear++] = current->left;
		/* Enqueue right child if exists */
		if (current->right)
			queue[rear++] = current->right;
	}
	/* Free the queue */
	free(queue);
}
