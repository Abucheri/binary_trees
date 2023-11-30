# 0x1D. C - Binary trees

0. New node
	- Write a function that creates a binary tree node
		- Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
		- Where `parent` is a pointer to the parent node of the node to create
		- And `value` is the value to put in the new node
		- When created, a node does not have any child
		- Your function must return a pointer to the new node, or `NULL` on failure
	```
	alex@/tmp/binary_trees$ cat 0-main.c 
	#include <stdlib.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;

	    root = binary_tree_node(NULL, 98);

	    root->left = binary_tree_node(root, 12);
	    root->left->left = binary_tree_node(root->left, 6);
	    root->left->right = binary_tree_node(root->left, 16);

	    root->right = binary_tree_node(root, 402);
	    root->right->left = binary_tree_node(root->right, 256);
	    root->right->right = binary_tree_node(root->right, 512);

	    binary_tree_print(root);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
	alex@/tmp/binary_trees$ ./0-node
	       .-------(098)-------.
	  .--(012)--.         .--(402)--.
	(006)     (016)     (256)     (512)
	alex@/tmp/binary_trees$
	```

1. Insert left
	- Write a function that inserts a node as the left-child of another node
		- Prototype: `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);`
		- Where `parent` is a pointer to the node to insert the left-child in
		- And `value` is the value to store in the new node
		- Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
		- If `parent` already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.
	```
	alex@/tmp/binary_trees$ cat 1-main.c 
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	
	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_print(root);
	    printf("\n");
	    binary_tree_insert_left(root->right, 128);
	    binary_tree_insert_left(root, 54);
	    binary_tree_print(root);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
	alex@/tmp/binary_trees$ ./1-left
	  .--(098)--.
	(012)     (402)
	
	       .--(098)-------.
	  .--(054)       .--(402)
	(012)          (128)                                            
	alex@/tmp/binary_trees$
	```

2. Insert right
	- Write a function that inserts a node as the right-child of another node
		- Prototype: `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);`
		- Where `parent` is a pointer to the node to insert the right-child in
		- And `value` is the value to store in the new node
		- Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
		- If `parent` already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.
	```
	alex@/tmp/binary_trees$ cat 2-main.c 
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	
	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_print(root);
	    printf("\n");
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    binary_tree_print(root);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 2-main.c 2-binary_tree_insert_right.c 0-binary_tree_node.c -o 2-right
	alex@/tmp/binary_trees$ ./2-right 
	  .--(098)--.
	(012)     (402)

	  .-------(098)--.
	(012)--.       (128)--.
	     (054)          (402)
	alex@/tmp/binary_trees$
	```

3. Delete
	- Write a function that deletes an entire binary tree
		- Prototype: `void binary_tree_delete(binary_tree_t *tree);`
		- Where `tree` is a pointer to the root node of the tree to delete
		- If `tree` is `NULL`, do nothing
	```
	alex@/tmp/binary_trees$ cat 3-main.c 
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	
	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    binary_tree_print(root);
	    binary_tree_delete(root);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del
	alex@/tmp/binary_trees$ valgrind ./3-del
	==13264== Memcheck, a memory error detector
	==13264== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
	==13264== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
	==13264== Command: ./3-del
	==13264== 
	  .-------(098)--.
	(012)--.       (128)--.
	     (054)          (402)
	==13264== 
	==13264== HEAP SUMMARY:
	==13264==     in use at exit: 0 bytes in 0 blocks
	==13264==   total heap usage: 9 allocs, 9 frees, 949 bytes allocated
	==13264== 
	==13264== All heap blocks were freed -- no leaks are possible
	==13264== 
	==13264== For counts of detected and suppressed errors, rerun with: -v
	==13264== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
	alex@/tmp/binary_trees$
	```

4. Is leaf
	- Write a function that checks if a node is a leaf
		- Prototype: `int binary_tree_is_leaf(const binary_tree_t *node);`
		- Where `node` is a pointer to the node to check
		- Your function must return `1` if `node` is a leaf, otherwise `0`
		- If `node` is `NULL`, return `0`
	```
	alex@/tmp/binary_trees$ cat 4-main.c 
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	    int ret;
	
	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    binary_tree_print(root);

	    ret = binary_tree_is_leaf(root);
	    printf("Is %d a leaf: %d\n", root->n, ret);
	    ret = binary_tree_is_leaf(root->right);
	    printf("Is %d a leaf: %d\n", root->right->n, ret);
	    ret = binary_tree_is_leaf(root->right->right);
	    printf("Is %d a leaf: %d\n", root->right->right->n, ret);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 4-binary_tree_is_leaf.c 4-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 4-leaf
	alex@/tmp/binary_trees$ ./4-leaf 
	  .-------(098)--.
	(012)--.       (128)--.
	     (054)          (402)
	Is 98 a leaf: 0
	Is 128 a leaf: 0
	Is 402 a leaf: 1
	alex@/tmp/binary_trees$
	```

5. Is root
	- Write a function that checks if a given node is a root
		- Prototype: `int binary_tree_is_root(const binary_tree_t *node);`
		- Where `node` is a pointer to the node to check
		- Your function must return `1` if `node` is a root, otherwise `0`
		- If `node` is `NULL`, return `0`
	```
	alex@/tmp/binary_trees$ cat 5-main.c 
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	    int ret;

	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    binary_tree_print(root);

	    ret = binary_tree_is_root(root);
	    printf("Is %d a root: %d\n", root->n, ret);
	    ret = binary_tree_is_root(root->right);
	    printf("Is %d a root: %d\n", root->right->n, ret);
	    ret = binary_tree_is_root(root->right->right);
	    printf("Is %d a root: %d\n", root->right->right->n, ret);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 5-binary_tree_is_root.c 5-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 5-root
	alex@/tmp/binary_trees$ ./5-root 
	  .-------(098)--.
	(012)--.       (128)--.
	     (054)          (402)
	Is 98 a root: 1
	Is 128 a root: 0
	Is 402 a root: 0
	alex@/tmp/binary_trees$
	```

6. Pre-order traversal
	- Write a function that goes through a binary tree using pre-order traversal
		- Prototype: `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));`
		- Where `tree` is a pointer to the root node of the tree to traverse
		- And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
		- If `tree` or `func` is `NULL`, do nothing
	```
	alex@/tmp/binary_trees$ cat 6-main.c
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * print_num - Prints a number
	 *
	 * @n: Number to be printed
	 */
	void print_num(int n)
	{
	    printf("%d\n", n);
	}
	
	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	
	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    root->left->left = binary_tree_node(root->left, 6);
	    root->left->right = binary_tree_node(root->left, 56);
	    root->right->left = binary_tree_node(root->right, 256);
	    root->right->right = binary_tree_node(root->right, 512);

	    binary_tree_print(root);
	    binary_tree_preorder(root, &print_num);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre
	alex@/tmp/binary_trees$ ./6-pre
	       .-------(098)-------.
	  .--(012)--.         .--(402)--.
	(006)     (056)     (256)     (512)
	98
	12
	6
	56
	402
	256
	512
	alex@/tmp/binary_trees$
	```

7. In-order traversal
	- Write a function that goes through a binary tree using in-order traversal
		- Prototype: `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));`
		- Where `tree` is a pointer to the root node of the tree to traverse
		- And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
		- If `tree` or `func` is `NULL`, do nothing
	```
	alex@/tmp/binary_trees$ cat 7-main.c
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * print_num - Prints a number
	 *
	 * @n: Number to be printed
	 */
	void print_num(int n)
	{
	    printf("%d\n", n);
	}
	
	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;

	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    root->left->left = binary_tree_node(root->left, 6);
	    root->left->right = binary_tree_node(root->left, 56);
	    root->right->left = binary_tree_node(root->right, 256);
	    root->right->right = binary_tree_node(root->right, 512);

	    binary_tree_print(root);
	    binary_tree_inorder(root, &print_num);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 7-main.c 7-binary_tree_inorder.c 0-binary_tree_node.c -o 7-in
	alex@/tmp/binary_trees$ ./7-in
	       .-------(098)-------.
	  .--(012)--.         .--(402)--.
	(006)     (056)     (256)     (512)
	6
	12
	56
	98
	256
	402
	512
	alex@/tmp/binary_trees$
	```

8. Post-order traversal
	- Write a function that goes through a binary tree using post-order traversal
		- Prototype: `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));`
		- Where `tree` is a pointer to the root node of the tree to traverse
		- And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
		- If `tree` or `func` is `NULL`, do nothing
	```
	alex@/tmp/binary_trees$ cat 8-main.c
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * print_num - Prints a number
	 *
	 * @n: Number to be printed
	 */
	void print_num(int n)
	{
	    printf("%d\n", n);
	}

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;

	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    root->left->left = binary_tree_node(root->left, 6);
	    root->left->right = binary_tree_node(root->left, 56);
	    root->right->left = binary_tree_node(root->right, 256);
	    root->right->right = binary_tree_node(root->right, 512);

	    binary_tree_print(root);
	    binary_tree_postorder(root, &print_num);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 8-main.c 8-binary_tree_postorder.c 0-binary_tree_node.c -o 8-post
	alex@/tmp/binary_trees$ ./8-post
	       .-------(098)-------.
	  .--(012)--.         .--(402)--.
	(006)     (056)     (256)     (512)
	6
	56
	12
	256
	512
	402
	98
	alex@/tmp/binary_trees$
	```

9. Height
	- Write a function that measures the height of a binary tree
		- Prototype: `size_t binary_tree_height(const binary_tree_t *tree);`
		- Where `tree` is a pointer to the root node of the tree to measure the height.
		- If `tree` is `NULL`, your function must return `0`
	```
	alex@/tmp/binary_trees$ cat 9-main.c 
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	    size_t height;

	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    binary_tree_print(root);

	    height = binary_tree_height(root);
	    printf("Height from %d: %lu\n", root->n, height);
	    height = binary_tree_height(root->right);
	    printf("Height from %d: %lu\n", root->right->n, height);
	    height = binary_tree_height(root->left->right);
	    printf("Height from %d: %lu\n", root->left->right->n, height);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 9-binary_tree_height.c 9-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 9-height
	alex@/tmp/binary_trees$ ./9-height 
	  .-------(098)--.
	(012)--.       (128)--.
	     (054)          (402)
	Height from 98: 2
	Height from 128: 1
	Height from 54: 0
	alex@/tmp/binary_trees$
	```

10. Depth
	- Write a function that measures the depth of a node in a binary tree
		- Prototype: `size_t binary_tree_depth(const binary_tree_t *tree);`
		- Where `tree` is a pointer to the node to measure the depth
		- If `tree` is `NULL`, your function must return `0`
	```
	alex@/tmp/binary_trees$ cat 10-main.c 
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	    size_t depth;
	
	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    binary_tree_print(root);

	    depth = binary_tree_depth(root);
	    printf("Depth of %d: %lu\n", root->n, depth);
	    depth = binary_tree_depth(root->right);
	    printf("Depth of %d: %lu\n", root->right->n, depth);
	    depth = binary_tree_depth(root->left->right);
	    printf("Depth of %d: %lu\n", root->left->right->n, depth);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 10-binary_tree_depth.c 10-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 10-depth
	alex@/tmp/binary_trees$ ./10-depth 
	  .-------(098)--.
	(012)--.       (128)--.
	     (054)          (402)
	Depth of 98: 0
	Depth of 128: 1
	Depth of 54: 2
	alex@/tmp/binary_trees$
	```

11. Size
	- Write a function that measures the size of a binary tree
		- Prototype: `size_t binary_tree_size(const binary_tree_t *tree);`
		- Where `tree` is a pointer to the root node of the tree to measure the size
		- If `tree` is `NULL`, the function must return `0`
	```
	alex@/tmp/binary_trees$ cat 11-main.c 
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	    size_t size;

	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    binary_tree_print(root);

	    size = binary_tree_size(root);
	    printf("Size of %d: %lu\n", root->n, size);
	    size = binary_tree_size(root->right);
	    printf("Size of %d: %lu\n", root->right->n, size);
	    size = binary_tree_size(root->left->right);
	    printf("Size of %d: %lu\n", root->left->right->n, size);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 11-binary_tree_size.c 11-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 11-size
	alex@/tmp/binary_trees$ ./11-size 
	  .-------(098)--.
	(012)--.       (128)--.
	     (054)          (402)
	Size of 98: 5
	Size of 128: 2
	Size of 54: 1
	alex@/tmp/binary_trees$
	```

12. Leaves
	- Write a function that counts the leaves in a binary tree
		- Prototype: `size_t binary_tree_leaves(const binary_tree_t *tree);`
		- Where `tree` is a pointer to the root node of the tree to count the number of leaves
		- If `tree` is `NULL`, the function must return `0`
		- A `NULL` pointer is not a `leaf`
	```
	alex@/tmp/binary_trees$ cat 12-main.c 
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	    size_t leaves;

	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    binary_tree_print(root);

	    leaves = binary_tree_leaves(root);
	    printf("Leaves in %d: %lu\n", root->n, leaves);
	    leaves = binary_tree_leaves(root->right);
	    printf("Leaves in %d: %lu\n", root->right->n, leaves);
	    leaves = binary_tree_leaves(root->left->right);
	    printf("Leaves in %d: %lu\n", root->left->right->n, leaves);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 12-binary_tree_leaves.c 12-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 12-leaves
	alex@/tmp/binary_trees$ ./12-leaves 
	  .-------(098)--.
	(012)--.       (128)--.
	     (054)          (402)
	Leaves in 98: 2
	Leaves in 128: 1
	Leaves in 54: 1
	alex@/tmp/binary_trees$
	```

13. Nodes
	- Write a function that counts the nodes with at least 1 child in a binary tree
		- Prototype: `size_t binary_tree_nodes(const binary_tree_t *tree);`
		- Where `tree` is a pointer to the root node of the tree to count the number of nodes
		- If `tree` is `NULL`, the function must return `0`
		- A `NULL` pointer is not a node
	```
	alex@/tmp/binary_trees$ cat 13-main.c
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	    size_t nodes;

	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    binary_tree_print(root);

	    nodes = binary_tree_nodes(root);
	    printf("Nodes in %d: %lu\n", root->n, nodes);
	    nodes = binary_tree_nodes(root->right);
	    printf("Nodes in %d: %lu\n", root->right->n, nodes);
	    nodes = binary_tree_nodes(root->left->right);
	    printf("Nodes in %d: %lu\n", root->left->right->n, nodes);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 13-binary_tree_nodes.c 13-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 13-nodes
	alex@/tmp/binary_trees$ ./13-nodes
	  .-------(098)--.
	(012)--.       (128)--.
	     (054)          (402)
	Nodes in 98: 3
	Nodes in 128: 1
	Nodes in 54: 0
	alex@/tmp/binary_trees$
	```

14. Balance factor
	- Write a function that measures the balance factor of a binary tree
		- Prototype: `int binary_tree_balance(const binary_tree_t *tree);`
		- Where `tree` is a pointer to the root node of the tree to measure the balance factor
		- If `tree` is `NULL`, return `0`
	```
	alex@/tmp/binary_trees$ cat 14-main.c 
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	    int balance;

	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    binary_tree_insert_left(root, 45);
	    binary_tree_insert_right(root->left, 50);
	    binary_tree_insert_left(root->left->left, 10);
	    binary_tree_insert_left(root->left->left->left, 8);
	    binary_tree_print(root);

	    balance = binary_tree_balance(root);
	    printf("Balance of %d: %+d\n", root->n, balance);
	    balance = binary_tree_balance(root->right);
	    printf("Balance of %d: %+d\n", root->right->n, balance);
	    balance = binary_tree_balance(root->left->left->right);
	    printf("Balance of %d: %+d\n", root->left->left->right->n, balance);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 14-binary_tree_balance.c 14-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c 1-binary_tree_insert_left.c -o 14-balance
	alex@/tmp/binary_trees$ ./14-balance
	                      .-------(098)--.
	            .-------(045)--.       (128)--.
	       .--(012)--.       (050)          (402)
	  .--(010)     (054)
	(008)
	Balance of 98: +2
	Balance of 128: -1
	Balance of 54: +0
	alex@/tmp/binary_trees$
	```

15. Is full
	- Write a function that checks if a binary tree is full
		- Prototype: `int binary_tree_is_full(const binary_tree_t *tree);`
		- Where `tree` is a pointer to the root node of the tree to check
		- If `tree` is `NULL`, your function must return `0`
	```
	alex@/tmp/binary_trees$ cat 15-main.c
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	    int full;

	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    root->left->left = binary_tree_node(root->left, 10);
	    binary_tree_print(root);

	    full = binary_tree_is_full(root);
	    printf("Is %d full: %d\n", root->n, full);
	    full = binary_tree_is_full(root->left);
	    printf("Is %d full: %d\n", root->left->n, full);
	    full = binary_tree_is_full(root->right);
	    printf("Is %d full: %d\n", root->right->n, full);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 15-binary_tree_is_full.c 15-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 15-full
	alex@/tmp/binary_trees$ ./15-full
	       .-------(098)--.
	  .--(012)--.       (128)--.
	(010)     (054)          (402)
	Is 98 full: 0
	Is 12 full: 1
	Is 128 full: 0
	alex@/tmp/binary_trees$
	```

16. Is perfect
	- Write a function that checks if a binary tree is perfect
		- Prototype: `int binary_tree_is_perfect(const binary_tree_t *tree);`
		- Where `tree` is a pointer to the root node of the tree to check
		- If `tree` is `NULL`, your function must return `0`
	```
	alex@/tmp/binary_trees$ cat 16-main.c
	#include <stdlib.h>
	#include <stdio.h>
	#include "binary_trees.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0 (Success)
	 */
	int main(void)
	{
	    binary_tree_t *root;
	    int perfect;

	    root = binary_tree_node(NULL, 98);
	    root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 402);
	    binary_tree_insert_right(root->left, 54);
	    binary_tree_insert_right(root, 128);
	    root->left->left = binary_tree_node(root->left, 10);
	    root->right->left = binary_tree_node(root->right, 10);

	    binary_tree_print(root);
	    perfect = binary_tree_is_perfect(root);
	    printf("Perfect: %d\n\n", perfect);

	    root->right->right->left = binary_tree_node(root->right->right, 10);
	    binary_tree_print(root);
	    perfect = binary_tree_is_perfect(root);
	    printf("Perfect: %d\n\n", perfect);

	    root->right->right->right = binary_tree_node(root->right->right, 10);
	    binary_tree_print(root);
	    perfect = binary_tree_is_perfect(root);
	    printf("Perfect: %d\n", perfect);
	    return (0);
	}
	alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 16-binary_tree_is_perfect.c 16-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 16-perfect
	alex@/tmp/binary_trees$ ./16-perfect 
	       .-------(098)-------.
	  .--(012)--.         .--(128)--.
	(010)     (054)     (010)     (402)
	Perfect: 1
	
	       .-------(098)-------.
	  .--(012)--.         .--(128)-------.
	(010)     (054)     (010)       .--(402)
                              (010)
	Perfect: 0
	
	       .-------(098)-------.
	  .--(012)--.         .--(128)-------.
	(010)     (054)     (010)       .--(402)--.
                              (010)     (010)
	Perfect: 0
	alex@/tmp/binary_trees$
	```

