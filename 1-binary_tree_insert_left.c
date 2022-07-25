#include "binary_trees.h"

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node, *tmp;

    if (parent == NULL)
        return (NULL);
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);
    new_node->parent = parent;
    new_node->n = value;
    new_node->right = NULL;
    new_node->left = NULL;
    if (parent->left)
    {
        tmp = parent->left;
        parent->left = new_node;
        new_node->left = tmp;
        tmp->parent = new_node;
    }
    else
        parent->left = new_node;
    return (new_node);
}
