#include "binary_trees.h"


/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *pivot;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	pivot = tree->left;
	new_root = pivot;
	tree->left = pivot->right;

	if (pivot->right != NULL)
		pivot->right->parent = tree;
	pivot->right = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;

	return (new_root);
}
