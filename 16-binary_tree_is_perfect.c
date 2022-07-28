#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL)
		return (0);
	depth = binary_tree_height(tree);
	return (check_leaves(tree, depth, 0));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: the height of a binary tree or 0 if tree is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * check_leaves - Verify if all leaves are in the same level
 * @tree: pointer to the root node of the tree to check
 * @depth: level where the leaves should be are
 * @level: level of the node
 * Return: 1 if the leaves are in the same level,
 * 0 if not
 */
int check_leaves(const binary_tree_t *tree, int depth, int level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (check_leaves(tree->left, depth, level + 1) &&
			check_leaves(tree->right, depth, level + 1));
}
