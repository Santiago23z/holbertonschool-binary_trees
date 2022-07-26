#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    binary_tree_t *mom, *father;

    if (!first || !second)
        return (NULL);
    if (first == second)
        return ((binary_tree_t *)first);

    mom = first->parent, father = second->parent;
    if (first == father || !mom || (!mom->parent && father))
        return (binary_trees_ancestor(first, father));
    else if (mom == second || !father || (!father->parent && mom))
        return (binary_trees_ancestor(mom, second));
    return (binary_trees_ancestor(mom, father));
}
