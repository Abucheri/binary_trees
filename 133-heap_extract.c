#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

void recursive_extract(heap_t *tree);
heap_t *max_heap(heap_t *tree);

/**
 * recursive_extract - Recursively extracts the maximum node
 *
 * @tree: Pointer to the root
 */

void recursive_extract(heap_t *tree)
{
	heap_t *left_max, *right_max = NULL;

	if (!tree->left)
		return;
	left_max = max_heap((tree)->left);
	if (tree->right)
		right_max = max_heap(tree->right);
	if (right_max && right_max->n > left_max->n)
		left_max = right_max;
	tree->n = left_max->n;
	if (!left_max->left)
	{
		if (left_max->parent && left_max->parent->left == left_max)
			left_max->parent->left = NULL;
		if (left_max->parent && left_max->parent->right == left_max)
			left_max->parent->right = NULL;
		free(left_max);
	} else
	{
		recursive_extract(left_max);
	}
}

/**
 * max_heap - Finds the max node
 *
 * @tree: Pointer to the root
 *
 * Return: Node with max val
 */

heap_t *max_heap(heap_t *tree)
{
	heap_t *current, *left_max, *right_max;

	if (!tree->left)
		return (tree);
	left_max = max_heap(tree->left);
	if (left_max->n > tree->n)
		current = left_max;
	else
		current = tree;
	if (tree->right)
	{
		right_max = max_heap(tree->right);
		if (right_max->n > current->n)
			current = right_max;
	}
	return (current);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 *
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node
 */

int heap_extract(heap_t **root)
{
	int value;

	if (!*root)
		return (0);
	value = (*root)->n;
	if (!(*root)->left)
	{
		/* value = (*root)->n; */
		free(*root);
		*root = NULL;
		return (value);
	}
	recursive_extract(*root);
	return (value);
}
