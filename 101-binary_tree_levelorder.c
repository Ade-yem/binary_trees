#include "binary_trees.h"

/**
 * height - height of the node
 * @node: node to get the height of
 * Return: heigt of the node
 */

int height(const binary_tree_t *node)
{
	int lheight, rheight;

	if (node == NULL)
		return (0);
	/* compute the height of each subtree */
	lheight = height(node->left);
	rheight = height(node->right);

	/* use the larger one */
	if (lheight > rheight)
		return (lheight + 1);
	else
		return (rheight + 1);
}

/**
 * printCurrentLevel - Print nodes at a current level
 * @root: node which is to be printed
 * @level: current level
 * @func: functiom that prints the node
 */

void printCurrentLevel(const binary_tree_t *root, int level, void (*func)(int))
{
	if (root == NULL)
		return;
	if (level == 1)
		func(root->n);
	else if (level > 1)
	{
		printCurrentLevel(root->left, level - 1, func);
		printCurrentLevel(root->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree by level-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h = height(tree), i;

	for (i = 1; i <= h; i++)
		printCurrentLevel(tree, i, func);
}
