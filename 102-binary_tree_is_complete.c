#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: the node to check
 * Return: 1 if it is complete or 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	else if (tree->left && tree -> right)
		return (binary_tree_is_complete(tree->left)
			&& binary_tree_is_complete(tree->right));
	return (0);
}
