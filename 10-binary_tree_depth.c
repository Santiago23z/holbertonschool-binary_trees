#include "binary_trees.h"
/**
 * @brief 
 * 
 * @param tree 
 * @return size_t 
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t count = 0;
    if (tree == NULL)
    {
        return 0;
    }
    while (tree->parent)
    {
        count++;
        tree = tree->parent;
    }
    return count;
}
