#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandpa;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	parent = node->parent;
	grandpa = parent->parent;
	if (grandpa->left && grandpa->right)
	{
		if (grandpa->left == parent)
			return (grandpa->right);
		return (grandpa->left);
	}
	return (NULL);
}
