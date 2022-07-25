#include "binary_trees.h"
/**
 * @brief 
 * 
 * @param parent 
 * @param value 
 * @return binary_tree_t* 
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
    if (parent->right)
    {
        tmp = parent->right;
        parent->right = new_node;
        new_node->right = tmp;
        tmp->parent = new_node;
    }
    else
        parent->right = new_node;
    return (new_node);
}
