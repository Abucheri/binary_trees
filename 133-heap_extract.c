#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

size_t _heap_size(const heap_t *root);
static void swap_nodes(heap_t *a, heap_t *b);
static void heapify_down(heap_t *root);

/**
 * _heap_size - Computes the size of the heap
 *
 * @root: Pointer to the root of the heap
 *
 * Return: Size of the heap
 */

size_t _heap_size(const heap_t *root)
{
	if (root == NULL)
		return (0);
	return (_heap_size(root->left) + _heap_size(root->right) + 1);
}

/**
 * swap_nodes - Swaps two nodes in a binary tree
 *
 * @a: First node
 * @b: Second node
 */

void swap_nodes(heap_t *a, heap_t *b)
{
	int temp;

	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * heapify_down - Heapifies the heap downwards
 *
 * @root: Pointer to the root of the heap
 */

void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;
	if (largest != root)
	{
		swap_nodes(root, largest);
		heapify_down(largest);
	}
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
	heap_t *last_node, *temp_root;

	if (root == NULL || *root == NULL)
		return (0);
	temp_root = *root;
	value = temp_root->n;
	last_node = temp_root;
	while (last_node->left != NULL || last_node->right != NULL)
	{
		if (last_node->right == NULL || last_node->left->n >
				last_node->right->n)
			last_node = last_node->left;
		else
			last_node = last_node->right;
	}
	if (last_node->parent != NULL)
	{
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
	} else
	{
		*root = NULL;
	}
	temp_root->n = last_node->n;
	free(last_node);
	heapify_down(temp_root);
	return (value);
}
