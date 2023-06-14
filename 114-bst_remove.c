#include "binary_trees.h"


/**
 * bst_remove - Removes a node from a Binary Search Tree
 *
 * @root: Pointer to the root node of the tree
 * @value: The value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{

	bst_t *right_child;
	bst_t *left_child;
	bst_t *successor;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else {
		if (root->left == NULL) 
		{
			right_child = root->right;
			free(root);
			return (right_child);
		} 
		else if (root->right == NULL) 
		{
			left_child = root->left;
			free(root);
			return (left_child);
		}

		successor = root->right;
		while (successor->left != NULL)
			successor = successor->left;

		root->n = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}

	return (root);
}
