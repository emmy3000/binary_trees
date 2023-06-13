#include "binary_trees.h"


int binary_tree_is_ancestor(const binary_tree_t *ancestor,
		const binary_tree_t *node);


/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor = NULL;
	const binary_tree_t *node1 = first;
	const binary_tree_t *node2 = second;

	if (first == NULL || second == NULL)
		return (NULL);

	while (node1 != node2)
	{
		node1 = (node1 == NULL) ? second : node1->parent;
		node2 = (node2 == NULL) ? first : node2->parent;
	}

	ancestor = node1;

	return ((binary_tree_t *)ancestor);
}


/**
 * binary_tree_is_ancestor - Checks if a node is an ancestor of another node.
 *
 * @ancestor: Pointer to the potential ancestor node.
 * @node: Pointer to the node to check if it is a descendant.
 *
 * Return: 1 if @ancestor is an ancestor of @node, 0 otherwise.
 */
int binary_tree_is_ancestor(const binary_tree_t *ancestor,
		const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (ancestor == node)
		return (1);

	return (binary_tree_is_ancestor(ancestor, node->left) ||
			binary_tree_is_ancestor(ancestor, node->right));
}
